#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/ARMv7/ARMv7Module.h"

#include "sceTouch.h"

LOG_CHANNEL(sceTouch);

s32 sceTouchGetPanelInfo(u32 port, vm::ptr<SceTouchPanelInfo> pPanelInfo)
{
	throw EXCEPTION("");
}

s32 sceTouchRead(u32 port, vm::ptr<SceTouchData> pData, u32 nBufs)
{
	throw EXCEPTION("");
}

s32 sceTouchPeek(u32 port, vm::ptr<SceTouchData> pData, u32 nBufs)
{
	throw EXCEPTION("");
}

s32 sceTouchSetSamplingState(u32 port, u32 state)
{
	throw EXCEPTION("");
}

s32 sceTouchGetSamplingState(u32 port, vm::ptr<u32> pState)
{
	throw EXCEPTION("");
}


#define REG_FUNC(nid, name) REG_FNID(SceTouch, nid, name)

DECLARE(arm_module_manager::SceTouch)("SceTouch", []()
{
	REG_FUNC(0x169A1D58, sceTouchRead);
	REG_FUNC(0xFF082DF0, sceTouchPeek);
	REG_FUNC(0x1B9C5D14, sceTouchSetSamplingState);
	REG_FUNC(0x26531526, sceTouchGetSamplingState);
	REG_FUNC(0x10A2CA25, sceTouchGetPanelInfo);
});
