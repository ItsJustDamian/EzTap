#pragma once
#include "../../VirtualFunction.hpp"
#include "IMaterial.hpp"
#include "../Classes/Vector.hpp"

//struct model_t;
//
//struct ModelRenderInfo_t
//{
//    Vector origin;
//    Vector angles;
//    char   pad[0x4];
//    void* pRenderable;
//    const model_t* pModel;
//    const void* pModelToWorld;
//    const void* pLightingOffset;
//    const void* pLightingOrigin;
//    int flags;
//    int entity_index;
//    int skin;
//    int body;
//    int hitboxset;
//    uintptr_t instance;
//    ModelRenderInfo_t()
//    {
//        pModelToWorld = NULL;
//        pLightingOffset = NULL;
//        pLightingOrigin = NULL;
//    }
//};
//
//struct DrawModelState_t
//{
//    void* m_pStudioHdr;
//    void* m_pStudioHWData;
//    void* m_pRenderable;
//    const void* m_pModelToWorld;
//    uintptr_t        m_decals;
//    int                        m_drawFlags;
//    int                        m_lod;
//};
//
//class IVModelInfoClient
//{
//public:
//    VF(void*, GetModel, 1, (int Index), (this, Index));
//    VF(int, GetModelIndex, 2, (const char* Filename), (this, Filename));
//    VF(const char*, GetModelName, 3, (const void* Model), (this, Model));
//    VF(void*, GetStudioModel, 4, (const model_t* model), (this, model));
//    VF(void, GetModelMaterials, 18, (const model_t* model, int count, IMaterial** ppMaterial), (this, model, count, ppMaterial));
//};
//
//class IVModelRender
//{
//public:
//    virtual int DrawModel(int flags, void* pRenderable, uintptr_t instance, int entity_index,
//        const model_t* model, Vector const& origin, Vector const& angles, int skin, int body,
//        int hitboxset, const void* modelToWorld = NULL,
//        const void* pLightingOffset = NULL) = 0;
//
//    virtual void ForcedMaterialOverride(IMaterial* newMaterial, int nOverrideType = 0, int nOverrides = 0) = 0;
//    virtual bool IsForcedMaterialOverride(void) = 0;
//    virtual void SetViewTarget(const int* pStudioHdr, int nBodyIndex, const Vector& target) = 0;
//    virtual uintptr_t CreateInstance(void* pRenderable, void* pCache = NULL) = 0;
//    virtual void DestroyInstance(uintptr_t handle) = 0;
//};

struct Model_t {
    void* handle;
    char name[260];
    int	loadFlags;
    int	serverCount;
    int	type;
    int	flags;
    Vector mins, maxs;
};

struct ModelRenderInfo {
    Vector origin;
    Vector angles;
    char pad[4];
    void* renderable;
    const Model_t* model;
    const matrix3x4* modelToWorld;
    const matrix3x4* lightingOffset;
    const Vector* lightingOrigin;
    int flags;
    int entityIndex;
};

class IModelRender
{

};