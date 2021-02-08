#pragma once

#include <cstddef>
#include <string_view>
#include <string>

#include "IMaterial.hpp"
#include "../../VirtualFunction.hpp"

enum class OverrideType {
    Normal = 0,
    BuildShadows,
    DepthWrite,
    CustomMaterial, // weapon skins
    SsaoDepthWrite
};

class IStudioRender {
    std::byte pad_0[0x250];
    IMaterial* materialOverride;
    std::byte pad_1[0xC];
    OverrideType overrideType;
public:
    VF(void, forcedMaterialOverride, 33, (IMaterial* material, OverrideType type = OverrideType::Normal, int index = -1), (this, material, type, index));

    bool isForcedMaterialOverride() noexcept
    {
        if (!materialOverride)
            return overrideType == OverrideType::DepthWrite || overrideType == OverrideType::SsaoDepthWrite; // see CStudioRenderContext::IsForcedMaterialOverride
        return std::string_view{ materialOverride->GetName() }._Starts_with("dev/glow");
    }
};