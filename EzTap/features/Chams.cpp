#include "Chams.hpp"

IMaterial* materialRegular = nullptr;
IMaterial* materialFlat = nullptr;

void Chams::Initialize()
{
	materialRegular = interfaces.MaterialSystem->FindMaterial("debug/debugambientcube", nullptr);
	materialFlat = interfaces.MaterialSystem->FindMaterial("debug/debugdrawflat", nullptr);
}

void Chams::OverrideMaterial(bool ignoreZ, bool flat, bool wireframe, bool glass, const Color& rgba)
{
	IMaterial* material = nullptr;

	if (flat) {
		material = materialFlat;
	}
	else {
		material = materialRegular;
	}

	material->SetMaterialVarFlag(MATERIAL_VAR_IGNOREZ, ignoreZ);


	if (glass) {
		material = materialFlat;
		material->AlphaModulate(0.45f);
	}
	else {
		material->AlphaModulate(
			rgba.a() / 255.0f);
	}

	material->SetMaterialVarFlag(MATERIAL_VAR_WIREFRAME, wireframe);
	material->ColorModulate(
		rgba.r() / 255.0f,
		rgba.g() / 255.0f,
		rgba.b() / 255.0f);

	interfaces.ModelRender->ForcedMaterialOverride(material);
}

void Chams::OnDrawModelExecute(IMatRenderContext* ctx, const DrawModelState_t& state, const ModelRenderInfo_t& pInfo, matrix3x4* pCustomBoneToWorld, DrawModelExecuteFn oFunc)
{
	static bool init = true;
	if (init)
	{
		Chams::Initialize();
		init = false;
	}

	const auto mdl = pInfo.pModel;

	bool is_arm = strstr(mdl->szName, "arms") != nullptr;
	bool is_player = strstr(mdl->szName, "models/player") != nullptr;
	bool is_sleeve = strstr(mdl->szName, "sleeve") != nullptr;
	//bool is_weapon = strstr(mdl->szName, "weapons/v_")  != nullptr;

	if (is_player && true) {
		// 
		// Draw player Chams.
		// 
		C_BaseEntity * ent = interfaces.ClientEntityList->GetClientEntity(pInfo.entity_index);

		if (ent && LocalPlayer && ent->isAlive()) {
			const auto enemy = ent->team() != LocalPlayer->team();
			if (!enemy && true)
				return;

			const auto clr_front = enemy ? Color(204, 27, 207) : Color(204, 27, 207);
			const auto clr_back = enemy ? Color(204, 27, 207) : Color(204, 27, 207);

			/*OverrideMaterial(
				false,
				true,
				false,
				false,
				clr_front);*/
			if (features.Chams)
			{
				OverrideMaterial(
					true,
					true,
					false,
					false,
					clr_back);
				//fnDME(g_MdlRender, 0, ctx, state, info, matrix);
				oFunc(interfaces.ModelRender, 0, ctx, state, pInfo, pCustomBoneToWorld);
				OverrideMaterial(
					false,
					true,
					false,
					false,
					clr_front);
			}
		}
	}
	else if (is_sleeve && true) {
		auto material = interfaces.MaterialSystem->FindMaterial(mdl->szName, TEXTURE_GROUP_MODEL);
		if (!material)
			return;
		// 
		// Remove sleeves when drawing Chams.
		// 
		material->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
		interfaces.ModelRender->ForcedMaterialOverride(material);
	}
	else if (is_arm) {
		auto material = interfaces.MaterialSystem->FindMaterial(mdl->szName, TEXTURE_GROUP_MODEL);
		if (!material)
			return;
		
		if (features.NoHands) {
			material->SetMaterialVarFlag(MATERIAL_VAR_NO_DRAW, true);
			interfaces.ModelRender->ForcedMaterialOverride(material);
		}
	}
}
