#include "stdafx.h"
#include "Emu/System.h"
#include "Emu/Cell/PPUModule.h"

#include "cellUserInfo.h"

#include "Utilities/StrUtil.h"

LOG_CHANNEL(cellUserInfo);

s32 cellUserInfoGetStat(u32 id, vm::ptr<CellUserInfoUserStat> stat)
{
	cellUserInfo.warning("cellUserInfoGetStat(id=%d, stat=*0x%x)", id, stat);

	if (id > CELL_SYSUTIL_USERID_MAX)
		return CELL_USERINFO_ERROR_NOUSER;

	if (id == CELL_SYSUTIL_USERID_CURRENT)
	{
		// TODO: Return current user/profile when that is implemented
		id = 1;
	}

	const std::string& path = vfs::get(fmt::format("/dev_hdd0/home/%08d/", id));
	if (!fs::is_dir(path))
		return CELL_USERINFO_ERROR_NOUSER;

	const fs::file f(path + "localusername");
	if (!f)
		return CELL_USERINFO_ERROR_INTERNAL;

	stat->id = id;
	strcpy_trunc(stat->name, f.to_string());
	return CELL_OK;
}

s32 cellUserInfoSelectUser_ListType()
{
	UNIMPLEMENTED_FUNC(cellUserInfo);
	return CELL_OK;
}

s32 cellUserInfoSelectUser_SetList()
{
	UNIMPLEMENTED_FUNC(cellUserInfo);
	return CELL_OK;
}

s32 cellUserInfoEnableOverlay()
{
	UNIMPLEMENTED_FUNC(cellUserInfo);
	return CELL_OK;
}

s32 cellUserInfoGetList(vm::ptr<u32> listNum, vm::ptr<CellUserInfoUserList> listBuf, vm::ptr<u32> currentUserId)
{
	cellUserInfo.warning("cellUserInfoGetList(listNum=*0x%x, listBuf=*0x%x, currentUserId=*0x%x)", listNum, listBuf, currentUserId);

	// If only listNum is NULL, an error will be returned
	if (listBuf && !listNum)
		return CELL_USERINFO_ERROR_PARAM;
	if (listNum)
		*listNum = 1;
	if (listBuf)
		listBuf->userId[0] = 1;

	if (currentUserId)
		*currentUserId = 1;
	
	return CELL_OK;
}

DECLARE(ppu_module_manager::cellUserInfo)("cellUserInfo", []()
{
	REG_FUNC(cellUserInfo, cellUserInfoGetStat);
	REG_FUNC(cellUserInfo, cellUserInfoSelectUser_ListType);
	REG_FUNC(cellUserInfo, cellUserInfoSelectUser_SetList);
	REG_FUNC(cellUserInfo, cellUserInfoEnableOverlay);
	REG_FUNC(cellUserInfo, cellUserInfoGetList);
});
