#pragma once

#include "../../Hooks.hpp"
#include "../../VirtualFunction.hpp"

#ifndef PAD
#define PAD(size) \
private: \
    std::byte _pad_##size[size]; \
public:
#endif

struct SurfaceData {
    PAD(80)
    float maxspeedfactor;
    float jumpfactor;
    float penetrationmodifier;
    float damagemodifier;
    short material;
    bool climbable;
};

class PhysicsSurfaceProps {
public:
    VF(SurfaceData*, getSurfaceData, 5, (int index), (this, index));
};