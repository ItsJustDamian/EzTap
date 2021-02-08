#pragma once
#include "../../VirtualFunction.hpp"
#include "IAppSystem.hpp"
#include "IMaterial.hpp"

typedef unsigned short MaterialHandle_t;

class KeyValues;

class IMaterial;
class IMaterialSystem : public IAppSystem
{
public:
	VF(IMaterial*, CreateMaterial, 83, (const char* pMaterialName, KeyValues* pVMTKeyValues), (this, pMaterialName, pVMTKeyValues));
	VF(IMaterial*, FindMaterial, 84, (char const* pMaterialName, const char* pMaterialGroupORSMTH), (this, pMaterialName, pMaterialGroupORSMTH, true, NULL));
	VF(MaterialHandle_t, FirstMaterial, 86, (), (this));
	VF(MaterialHandle_t, NextMaterial, 87, (MaterialHandle_t h), (this, h));
	VF(MaterialHandle_t, InvalidMaterial, 88, (), (this));
	VF(IMaterial*, GetMaterial, 89, (MaterialHandle_t h), (this, h));
};