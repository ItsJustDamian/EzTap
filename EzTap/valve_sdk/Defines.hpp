#pragma once
#include "Classes/Vector.hpp"
enum class ClientFrameStage_t : int
{
	FRAME_UNDEFINED = -1,
	FRAME_START,
	FRAME_NET_UPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_START,
	FRAME_NET_UPDATE_POSTDATAUPDATE_END,
	FRAME_NET_UPDATE_END,
	FRAME_RENDER_START,
	FRAME_RENDER_END
};

struct model_t
{
    void* fnHandle;               //0x0000 
    char    szName[260];            //0x0004 
    __int32 nLoadFlags;             //0x0108 
    __int32 nServerCount;           //0x010C 
    __int32 type;                   //0x0110 
    __int32 flags;                  //0x0114 
    Vector  vecMins;                //0x0118 
    Vector  vecMaxs;                //0x0124 
    float   radius;                 //0x0130 
    char    pad[0x1C];              //0x0134
};