#include "HTTPRequest.hpp"
#include "Hooks.hpp"
#include "Font.hpp"
#pragma comment(lib, "Ws2_32.lib")

// Some auth stuff

std::vector<char> authUrl = { 'h','t','t','p',':','/','/','e','z','t','a','p','.','o','n','l','i','n','e','/','a','u','t','h','.','p','h','p' };
std::vector<char> authUrlParam1 = { 'h', 'w', 'i', 'd' };
std::vector<char> authUrlParam2 = { 'c', 'h', 'e', 'c', 'k', 'T', 'y', 'p', 'e' };
std::vector<char> authUrlContentType = { 'C','o','n','t','e','n','t','-','T','y','p','e',':',' ','a','p','p','l','i','c','a','t','i','o','n','/','x','-','w','w','w','-','f','o','r','m','-','u','r','l','e','n','c','o','d','e','d' };

//Typedefs
typedef HRESULT(__stdcall* EndSceneFn)(IDirect3DDevice9*);
typedef long(__stdcall* ResetFn)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef void(__stdcall* LockCursorFn)();
typedef void(__stdcall* OverrideViewFn)(CViewSetup*);
typedef bool(__stdcall* CreateMoveFn)(float, CUserCmd*);
typedef void(__stdcall* FrameStageNotifyFn)(ClientFrameStage_t);
typedef void(__fastcall* DrawModelExecuteFn)(void*, int, IMatRenderContext*, const DrawModelState_t&, const ModelRenderInfo_t&, matrix3x4*);
typedef void(__fastcall* EmitSoundFn)(void*, void*, void*, int, int, const char*, unsigned int, const char*, float, float, int, int, int, const Vector*, const Vector*, Vector*, bool, float, int, void*&);
typedef bool(__fastcall* FireEventFn)(void*, void*, IGameEvent*);
typedef void(__stdcall* PaintTraverseFn)(unsigned int, bool, bool);

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
EmitSoundFn oEmitSound;
FireEventFn oFireEvent;

//Hooks

static void __stdcall hkLockCursor()
{
    (menuOpen && interfaces.Engine->isIngame()) ? interfaces.Surface->unlockCursor() : oLockCursor();
}

static HRESULT __stdcall hkEndScene(IDirect3DDevice9* pDevice)
{
    static bool init = true;
    if (init)
    {
        init = false;
        Render.Init(pDevice);

        ImGui::CreateContext();
        ImGui_ImplWin32_Init(FindWindowA("Valve001", NULL));
        ImGui_ImplDX9_Init(pDevice);

        ImGuiIO& io = ImGui::GetIO();
        ImFont * f = io.Fonts->AddFontFromMemoryTTF(robotoFont, 16.f, 16.f);
        IconFont = io.Fonts->AddFontFromMemoryTTF(badcache::fileBytes, 46.f, 46.f);
    }

    if(menuOpen && interfaces.Engine->isIngame() && !oLockCursor)
        oLockCursor = HookFunction<LockCursorFn>(interfaces.Surface, 67, hkLockCursor);

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    drawList = ImGui::GetBackgroundDrawList();

    if (!MELikEYCheeSE)
    {
        LoginGui::Render();
    }else {

    if (menuOpen)
        Gui::Render();

    }

    Gui::Watermark();

    if (LocalPlayer && interfaces.Engine->isIngame())
    {
        ESP::Render();
    }

    DXHooks->ExecuteAllCallbacks();

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
    if (uMsg == WM_KEYUP && wParam == VK_INSERT && MELikEYCheeSE)
        menuOpen ^= true;

    if (menuOpen || !MELikEYCheeSE)
    {
        ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
        return true;
    }

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

static void __stdcall hkOverrideView(CViewSetup* setup)
{
    if (!interfaces.Engine->isIngame() || !LocalPlayer || !LocalPlayer->isValid())
        return oOverrideView(setup);

    if (LocalPlayer->getActiveWeapon()->isWeaponSniper() && !LocalPlayer->isScoped())
        setup->fov = features.FOV;
    else if (!LocalPlayer->getActiveWeapon()->isWeaponSniper())
        setup->fov = features.FOV;

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

    if (features.Aimbot)
        Aimbot::CreateMove(pCmd);

    if (features.RankReveal)
        Misc::RankReveal();

    if (features.Legit_Triggerbot)
        LegitBot::Triggerbot(pCmd);

    FakeLag::CreateMove(pCmd, SendPacket);

    if (features.ClanTag)
    {
        static int tickCount = 0;
        if (tickCount < 3) tickCount++;
        else {
            tickCount = 0; Misc::ClanTag();
        }
    }

    /*if (features.AntiAim)
        RageBot::AntiAim(pCmd, SendPacket);*/

    //CMHooks->ExecuteAllCallbacks();

    LUAHooksExecWithArgs(CMHooks, (ExportedUserCmd(pCmd)));

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

    if (!interfaces.Engine->isIngame() || !LocalPlayer || !LocalPlayer->isValid() || interfaces.Engine->isTakingScreenshot())
        if (oFrameStageNotify)
            return oFrameStageNotify(curStage);
        else
            return;

    Misc::ForceCrosshair();
    Misc::NoFlash(features.NoFlash);

    if (features.Legit_RadarHack)
    {
        static int tickCount = 0;
        if (tickCount < 20) tickCount++;
        else {
            tickCount = 0; LegitBot::RadarHack();
        }
    }

    FSNHooks->ExecuteAllCallbacks();

    if (oFrameStageNotify)
        return oFrameStageNotify(curStage);
    else
        return;
}

static void __fastcall hkDrawModelExecute(void* _this, int edx, IMatRenderContext* ctx, const DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4* pCustomBoneToWorld)
{
    if(!interfaces.Engine->isIngame() || !LocalPlayer || !LocalPlayer->isValid())
        return oDrawModelExecute(_this, edx, ctx, state, pInfo, pCustomBoneToWorld);

    if (interfaces.ModelRender->IsForcedMaterialOverride() && !strstr(pInfo.pModel->szName, "arms") && !strstr(pInfo.pModel->szName, "weapons/v_"))
        return oDrawModelExecute(_this, edx, ctx, state, pInfo, pCustomBoneToWorld);

    Chams::OnDrawModelExecute(ctx, state, pInfo, pCustomBoneToWorld, oDrawModelExecute);

    oDrawModelExecute(_this, edx, ctx, state, pInfo, pCustomBoneToWorld);
    interfaces.ModelRender->ForcedMaterialOverride(nullptr);
}

static void __fastcall hkEmitSound(void* ecx, void* edx, void* filter, int iEntIndex, int iChannel, const char* pSoundEntry, unsigned int nSoundEntryHash, const char* pSample, float flVolume, float flAttenuation, int nSeed, int iFlags, int iPitch, const Vector* pOrigin, const Vector* pDirection, Vector* pUtlVecOrigins, bool bUpdatePositions, float soundtime, int speakerentity, void*& params)
{
    if (features.AutoAccept)
    {
        if (!strcmp(pSoundEntry, "UIPanorama.popup_accept_match_beep"))
            Utils::SetPlayerReady();
    }

    ExportedVector orgin, direction;

    if (interfaces.Engine->isIngame() && LocalPlayer->isValid())
    {
        orgin.SetX(pOrigin->x);
        orgin.SetY(pOrigin->y);
        orgin.SetZ(pOrigin->z);

        direction.SetX(pDirection->x);
        direction.SetY(pDirection->y);
        direction.SetZ(pDirection->z);
    }

    LUAHooksExecWithArgs(SNDHooks, (pSoundEntry, pSample, flVolume, flAttenuation, iFlags, soundtime));

    return oEmitSound(ecx, edx, filter, iEntIndex, iChannel, pSoundEntry, nSoundEntryHash, pSample, flVolume, flAttenuation, nSeed, iFlags, iPitch, pOrigin, pDirection, pUtlVecOrigins, bUpdatePositions, soundtime, speakerentity, params);
}

#define CheckHook(oFunc, name) \
    if (!oFunc) \
        console.Error("Failed to hook %s!\n", name); \
    else \
        console.Info("%s hooked successfully, Old Function 0x%X\n", name, oFunc);

void* dxBase = nullptr;
void Hooks::Setup()
{
    WhyNut();

    oWndProc = (WNDPROC)SetWindowLongPtr(FindWindowA("Valve001", NULL), GWL_WNDPROC, (LONG_PTR)WndProc);
    dxBase = reinterpret_cast<void*>(**reinterpret_cast<unsigned long****>(Memory::FindPattern(reinterpret_cast<unsigned long>(GetModuleHandleA("shaderapidx9.dll")), "A1 ?? ?? ?? ?? 50 8B 08 FF 51 0C") + 0x1));

    oEndScene = HookFunction<EndSceneFn>(dxBase, 42, hkEndScene);   
    oReset = HookFunction<ResetFn>(dxBase, 16, hkReset);
    oOverrideView = HookFunction<OverrideViewFn>(interfaces.ClientMode, 18, hkOverrideView);
    oFrameStageNotify = HookFunction<FrameStageNotifyFn>(interfaces.Client, 37, hkFrameStageNotify);
    oDrawModelExecute = HookFunction<DrawModelExecuteFn>(interfaces.ModelRender, 21, hkDrawModelExecute);
    oEmitSound = HookFunction<EmitSoundFn>(interfaces.EngineSound, 5, hkEmitSound);
    oCreateMove = HookFunction<CreateMoveFn>(interfaces.ClientMode, 24, hkCreateMove);
    //oLockCursor = HookFunction<LockCursorFn>(interfaces.Surface, 67, hkLockCursor);

    CheckHook(oEndScene,"EndScene");
    CheckHook(oReset,"Reset");
    CheckHook(oCreateMove,"CreateMove");
    CheckHook(oOverrideView,"OverrideView");
    CheckHook(oFrameStageNotify,"FrameStageNotify");
    CheckHook(oDrawModelExecute,"DrawModelExecute");
    CheckHook(oEmitSound,"EmitSound");
}

void Hooks::Restore()
{
    (WNDPROC)SetWindowLongPtr(FindWindowA(0, "Counter-Strike: Global Offensive"), GWL_WNDPROC, (LONG_PTR)oWndProc);

    /*HookFunction<EndSceneFn>(dxBase, 42, oEndScene);
    HookFunction<EndSceneFn>(dxBase, 16, oReset);
    HookFunction<CreateMoveFn>(interfaces.ClientMode, 24, oCreateMove);
    HookFunction<OverrideViewFn>(interfaces.ClientMode, 18, oOverrideView);
    HookFunction<FrameStageNotifyFn>(interfaces.Client, 37, oFrameStageNotify);
    HookFunction<DrawModelExecuteFn>(interfaces.ModelRender, 21, oDrawModelExecute);
    HookFunction<EmitSoundFn>(interfaces.EngineSound, 5, oEmitSound);*/

    MH_DisableHook(MH_ALL_HOOKS);
    MH_RemoveHook(oEndScene);
    MH_RemoveHook(oReset);
    MH_RemoveHook(oCreateMove);
    MH_RemoveHook(oOverrideView);
    MH_RemoveHook(oFrameStageNotify);
    MH_RemoveHook(oDrawModelExecute);
    MH_RemoveHook(oEmitSound);

    if (oLockCursor)
        MH_RemoveHook(oLockCursor);
}

void Hooks::WhyNut()
{
    try
    {
        HW_PROFILE_INFO hwProfileInfo;
        if (!GetCurrentHwProfile(&hwProfileInfo))
            exit(-1);

        const char* url = StringSolver::SolveCharArray(authUrl);

    	http::Request request(url);
        Sleep(100);
    	std::map<std::string, std::string> parameters = { {StringSolver::SolveCharArray(authUrlParam1), hwProfileInfo.szHwProfileGuid} };
        Sleep(100);
        parameters.insert({ StringSolver::SolveCharArray(authUrlParam2), std::to_string(1).c_str() });
        Sleep(100);
        
        const http::Response response = request.send("POST", parameters, {
            StringSolver::SolveCharArray(authUrlContentType)
    		});

    	std::string respStr = std::string(response.body.begin(), response.body.end()).c_str();

        if (std::stol(respStr) != 696900666)
        {
            console.Debug(hwProfileInfo.szHwProfileGuid);
            Sleep(500);
            exit(-1);
        }
        else result1 = std::stol(respStr);
    }
    catch (const std::exception& e)
    {
    	//console.Error("Request failed, error: %s\n", e.what());
        exit(-1);
    }
}
