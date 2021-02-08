#pragma once
#include "../Hooks.hpp"
#include "../Interfaces.hpp"
#include "../valve_sdk/Classes/Color.hpp"

class IMatRenderContext;
struct DrawModelState_t;
struct ModelRenderInfo_t;

typedef void(__fastcall* DrawModelExecuteFn)(void* _this, int edx, IMatRenderContext* ctx, const DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4* pCustomBoneToWorld);

namespace Chams
{
	void Initialize();
	void OverrideMaterial(bool ignoreZ, bool flat, bool wireframe, bool glass, const Color& rgba);
	void OnDrawModelExecute(IMatRenderContext* ctx, const DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4* pCustomBoneToWorld, DrawModelExecuteFn oFunc);
}