#include "Hooks.hpp"
#include "Font.hpp"

//Typedefs
typedef HRESULT(__stdcall* EndSceneFn)(IDirect3DDevice9* pDevice);
typedef long(__stdcall* ResetFn)(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pPresentationParameters);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef void(__stdcall* LockCursorFn)();
typedef void(__stdcall* OverrideViewFn)(CViewSetup* setup);
typedef bool(__stdcall* CreateMoveFn)(float frametime, CUserCmd* pCmd);
typedef void(__stdcall* FrameStageNotifyFn)(ClientFrameStage_t curStage);
typedef void(__fastcall* DrawModelExecuteFn)(void* _this, int edx, IMatRenderContext* ctx, const DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4* pCustomBoneToWorld);

//Externals
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Defines
EndSceneFn oEndScene;
ResetFn oReset;
WNDPROC oWndProc;
LockCursorFn oLockCursor;
OverrideViewFn oOverrideView;
CreateMoveFn oCreateMove;
FrameStageNotifyFn oFrameStageNotify;
DrawModelExecuteFn oDrawModelExecute;

//Hooks

static bool menuOpen = false;
static void __stdcall hkLockCursor()
{
    if (menuOpen && interfaces.Engine->isIngame())
        return interfaces.Surface->unlockCursor();

    return oLockCursor();
}

static HRESULT __stdcall hkEndScene(IDirect3DDevice9* pDevice)
{
    static bool init = true;
    if (init)
    {
        init = false;
        Render.Init(pDevice);

        ImGui::CreateContext();
        ImGui_ImplWin32_Init(FindWindowA(NULL, "Counter-Strike: Global Offensive"));
        ImGui_ImplDX9_Init(pDevice);

        ImGuiIO& io = ImGui::GetIO();
        ImFont * f = io.Fonts->AddFontFromMemoryTTF(robotoFont, 16.f, 16.f);
    }

    if (menuOpen && interfaces.Engine->isIngame() && oLockCursor == nullptr)
        oLockCursor = HookFunction<LockCursorFn>(interfaces.Surface, 67, hkLockCursor);

    if (GetAsyncKeyState(VK_INSERT) & 1)
        menuOpen = !menuOpen;

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    drawList = ImGui::GetBackgroundDrawList();

    if (menuOpen)
        Gui::Render();

    Gui::Watermark();

    if (LocalPlayer && interfaces.Engine->isIngame())
    {
        ESP::Render();
    }

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return oEndScene(pDevice);
}

static long __stdcall hkReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	return oReset(device, pPresentationParameters);
}

static LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) // For ImGui window handle
{
    if (menuOpen)
    {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        return true;
    }

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


static void __stdcall hkOverrideView(CViewSetup* setup)
{
    if (!LocalPlayer || !interfaces.Engine->isIngame() || !LocalPlayer->isAlive())
        return oOverrideView(setup);

    if (LocalPlayer->getActiveWeapon()->isWeaponSniper() && !LocalPlayer->isScoped())
        setup->fov = 120;
    else if (!LocalPlayer->getActiveWeapon()->isWeaponSniper())
        setup->fov = 120;

    return oOverrideView(setup);
}

static bool __stdcall hkCreateMove(float frametime, CUserCmd* pCmd)
{
    LocalPlayer = interfaces.ClientEntityList->GetClientEntity(interfaces.Engine->getLocalPlayer());

    if (!LocalPlayer || !pCmd->command_number)
        return oCreateMove(frametime, pCmd);

    unsigned long* EBPPointer;
    __asm mov EBPPointer, ebp;
    bool& SendPacket = *reinterpret_cast<bool*>(*EBPPointer - 0x1C);

    if (features.Bunnyhop)
        Misc::Bunnyhop(pCmd);

    return false; // Send to server, but not update on client
}

static void __stdcall hkFrameStageNotify(ClientFrameStage_t curStage)
{
    static ConVar* cvPanoramaBlur;
    if (!cvPanoramaBlur)
        cvPanoramaBlur = interfaces.cvar->findVar("@panorama_disable_blur");

    if (features.NoPanoramaBlur && cvPanoramaBlur->getInt() == 0)
        cvPanoramaBlur->setValue(true);
    else if (!features.NoPanoramaBlur && cvPanoramaBlur->getInt() == 1)
        cvPanoramaBlur->setValue(false);

    if (!LocalPlayer || interfaces.Engine->isTakingScreenshot())
        return oFrameStageNotify(curStage);

    return oFrameStageNotify(curStage);
}

static void __fastcall hkDrawModelExecute(void* _this, int edx, IMatRenderContext* ctx, const DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4* pCustomBoneToWorld)
{
    if (interfaces.ModelRender->IsForcedMaterialOverride() && !strstr(pInfo.pModel->szName, "arms") && !strstr(pInfo.pModel->szName, "weapons/v_"))
        return oDrawModelExecute(_this, edx, ctx, state, pInfo, pCustomBoneToWorld);

    Chams::OnDrawModelExecute(ctx, state, pInfo, pCustomBoneToWorld, oDrawModelExecute);

    oDrawModelExecute(_this, edx, ctx, state, pInfo, pCustomBoneToWorld);
    interfaces.ModelRender->ForcedMaterialOverride(nullptr);
}

void Hooks::Setup()
{
    oWndProc = (WNDPROC)SetWindowLongPtr(FindWindowA(0, "Counter-Strike: Global Offensive"), GWL_WNDPROC, (LONG_PTR)WndProc);

	void* dxBase = reinterpret_cast<void*>(**reinterpret_cast<unsigned long****>(Memory::FindPattern(reinterpret_cast<unsigned long>(GetModuleHandleA("shaderapidx9.dll")), "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C") + 0x1));

	oEndScene = HookFunction<EndSceneFn>(dxBase, 42, hkEndScene);
	oReset = HookFunction<ResetFn>(dxBase, 16, hkReset);
    oCreateMove = HookFunction<CreateMoveFn>(interfaces.ClientMode, 24, hkCreateMove);
    oOverrideView = HookFunction<OverrideViewFn>(interfaces.ClientMode, 18, hkOverrideView);
    oFrameStageNotify = HookFunction<FrameStageNotifyFn>(interfaces.Client, 37, hkFrameStageNotify);
    oDrawModelExecute = HookFunction<DrawModelExecuteFn>(interfaces.ModelRender, 21, hkDrawModelExecute);
}
