#include "pch.h"
#include "KMCLR.h"

#ifdef _M_X64
#pragma comment(lib,"./Library/x64/msdk/msdk.lib") //64λlib
#else
#pragma comment(lib,"./Library/x32/msdk/msdk.lib") //32λlib
#endif

int KMCLR::KMSoft::Open()
{
	handle = M_Open(1);
	return handle == NULL ? 0 : 1;
}

int KMCLR::KMSoft::Open_VidPid(int vid, int pid)
{
	handle = M_Open_VidPid(vid, pid);
	return handle == NULL ? 0 : 1;
}

int KMCLR::KMSoft::Close()
{
	auto ret = M_Close(handle);
	return ret == 0 ? 1 : ret;
}

int KMCLR::KMSoft::MoveR(int x, int y)
{
	return M_MoveR(handle, x, y);
}

int KMCLR::KMSoft::MoveTo(int x, int y)
{
	return M_MoveTo(handle, x, y);
}

KMCLR::KMSoft::~KMSoft()
{
	if (handle != NULL)handle = NULL;
}
