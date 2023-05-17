#include "pch.h"
#include "KMCLR.h"

#ifdef _M_X64
#pragma comment(lib,"./Library/x64/msdk/msdk.lib")
#else
#pragma comment(lib,"./Library/x32/msdk/msdk.lib")
#endif

String^ KMCLR::KMSoft::Ver()
{
	return "1.0";
}

int KMCLR::KMSoft::Open()
{
	handle = M_Open(1);
	return handle == INVALID_HANDLE_VALUE ? 0 : 1;
}

int KMCLR::KMSoft::Open_VidPid(int vid, int pid)
{
	handle = M_Open_VidPid(vid, pid);
	return handle == INVALID_HANDLE_VALUE ? 0 : 1;
}

int KMCLR::KMSoft::Close()
{
	long ret = -1;
	if (handle != INVALID_HANDLE_VALUE)
	{
		ret = M_Close(handle);
		handle = INVALID_HANDLE_VALUE;
	}

	return ret == 0 ? 1 : ret;
}

int KMCLR::KMSoft::GetAbsCfg()
{
	return M_GetAbsCfg(handle);
}

int KMCLR::KMSoft::SetAbsCfg(int e1d0)
{
	return M_SetAbsCfg(handle, e1d0);
}

HANDLE KMCLR::KMSoft::ScanAndOpen()
{
	return M_ScanAndOpen();
}

int KMCLR::KMSoft::MoveR(int x, int y)
{
	return M_MoveR(handle, x, y);
}

int KMCLR::KMSoft::MoveR2(int x, int y)
{
	return M_MoveR2(handle, x, y);
}

int KMCLR::KMSoft::MoveTo(int x, int y)
{
	return M_MoveTo(handle, x, y);
}

int KMCLR::KMSoft::MoveTo2(int x, int y)
{
	return M_MoveTo2(handle, x, y);
}

int KMCLR::KMSoft::MoveTo3(int x, int y)
{
	return M_MoveTo3(handle, x, y);
}

int KMCLR::KMSoft::MoveTo3_D(int x, int y)
{
	return M_MoveTo3_D(handle, x, y);
}

Tuple<long, long, int>^ KMCLR::KMSoft::GetCurrMousePos()
{
	int x, y;
	auto ret = M_GetCurrMousePos(handle, &x, &y);
	return gcnew Tuple<long, long, int>(x, y, ret);
}

Tuple<long, long, int>^ KMCLR::KMSoft::GetCurrMousePos2()
{
	int x, y;
	auto ret = M_GetCurrMousePos2(&x, &y);
	return gcnew Tuple<long, long, int>(x, y, ret);
}

int KMCLR::KMSoft::GetCurrMousePosX()
{
	return M_GetCurrMousePosX(handle);
}

int KMCLR::KMSoft::GetCurrMousePosY()
{
	return M_GetCurrMousePosY(handle);
}

int KMCLR::KMSoft::SetParam(int ParamType, int Param1, int Param2)
{
	return M_SetParam(handle, ParamType, Param1, Param2);
}

int KMCLR::KMSoft::InitParam()
{
	return M_InitParam(handle);
}

int KMCLR::KMSoft::KeyPress(int keyCode, int Nbr)
{
	return M_KeyPress(handle, keyCode, Nbr);
}


int KMCLR::KMSoft::KeyPress2(int keyCode, int Nbr)
{
	return M_KeyPress2(handle, keyCode, Nbr);
}

int KMCLR::KMSoft::KeyDown(int keyCode)
{
	return M_KeyDown(handle, keyCode);
}

int KMCLR::KMSoft::KeyDown2(int keyCode)
{
	return M_KeyDown(handle, keyCode);
}

int KMCLR::KMSoft::KeyUp(int keyCode)
{
	return M_KeyUp(handle, keyCode);
}

int KMCLR::KMSoft::KeyUp2(int keyCode)
{
	return M_KeyUp(handle, keyCode);
}

int KMCLR::KMSoft::KeyState(int keyCode)
{
	return M_KeyState(handle, keyCode);
}

int KMCLR::KMSoft::KeyState2(int keyCode)
{
	return M_KeyState(handle, keyCode);
}

int KMCLR::KMSoft::ReleaseAllKey()
{
	return M_ReleaseAllKey(handle);
}

int KMCLR::KMSoft::NumLockLedState()
{
	return M_NumLockLedState(handle);
}

int KMCLR::KMSoft::CapsLockLedState()
{
	return M_CapsLockLedState(handle);
}

int KMCLR::KMSoft::ScrollLockLedState()
{
	return M_ScrollLockLedState(handle);
}

int KMCLR::KMSoft::KeyInputString(String^ InputStr, int InputLen)
{
	return M_KeyInputString(handle, Util::StringToChar(InputStr), InputLen);
}

int KMCLR::KMSoft::KeyInputStringGBK(String^ InputStr, int InputLen)
{
	return M_KeyInputStringGBK(handle, Util::StringToChar(InputStr), InputLen);
}

int KMCLR::KMSoft::KeyInputStringUnicode(String^ InputStr, int InputLen)
{
	return M_KeyInputStringUnicode(handle, Util::StringToChar(InputStr), InputLen);
}

int KMCLR::KMSoft::LeftClick(int Nbr)
{
	return M_LeftClick(handle, Nbr);
}

int KMCLR::KMSoft::LeftDoubleClick(int Nbr)
{
	return M_LeftDoubleClick(handle, Nbr);
}

int KMCLR::KMSoft::LeftDown()
{
	return M_LeftDown(handle);
}

int KMCLR::KMSoft::LeftUp()
{
	return M_LeftUp(handle);
}

int KMCLR::KMSoft::RightClick(int Nbr)
{
	return M_RightClick(handle, Nbr);
}

int KMCLR::KMSoft::RightDown()
{
	return M_RightDown(handle);
}

int KMCLR::KMSoft::RightUp()
{
	return M_RightUp(handle);
}

int KMCLR::KMSoft::MiddleClick(int Nbr)
{
	return M_MiddleClick(handle, Nbr);
}

int KMCLR::KMSoft::MiddleDown()
{
	return M_MiddleDown(handle);
}

int KMCLR::KMSoft::MiddleUp()
{
	return M_MiddleUp(handle);
}

int KMCLR::KMSoft::ReleaseAllMouse()
{
	return M_ReleaseAllMouse(handle);
}

int KMCLR::KMSoft::MouseKeyState(int Nbr)
{
	return M_MouseKeyState(handle, Nbr);
}

int KMCLR::KMSoft::MouseWheel(int Nbr)
{
	return M_MouseWheel(handle, Nbr);
}

int KMCLR::KMSoft::ResetMousePos()
{
	return M_ResetMousePos(handle);
}

int KMCLR::KMSoft::ResolutionUsed(int x, int y)
{
	return M_ResolutionUsed(handle, x, y);
}

int KMCLR::KMSoft::Delay(int time)
{
	return M_Delay(time);
}

int KMCLR::KMSoft::DelayRandom(int Min_time, int Max_time)
{
	return M_DelayRandom(Min_time, Max_time);
}

int KMCLR::KMSoft::RandDomNbr(int Min_V, int Max_V)
{
	return M_RandDomNbr(Min_V, Max_V);
}


KMCLR::KMSoft::~KMSoft()
{
	Close();
}


