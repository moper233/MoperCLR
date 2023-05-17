#pragma once
#include ".\Library\Include\msdk.h"
#include "Util.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace msclr::interop;
using namespace System::Runtime::InteropServices;

namespace KMCLR {
	public ref class KMSoft
	{
	private:
		HANDLE handle;

	public:
		String^ Ver();
		int Open();
		int Open_VidPid(int vid, int pid);
		int Close();
		int GetAbsCfg();
		int SetAbsCfg(int e1d0);
		HANDLE ScanAndOpen();

		
		int MoveR(int x, int y);
		int MoveR2(int x, int y);
		int MoveTo(int x, int y);
		int MoveTo2(int x, int y);
		int MoveTo3(int x, int y);
		int MoveTo3_D(int x, int y);
		Tuple<long, long, int>^ GetCurrMousePos();
		Tuple<long, long, int>^ GetCurrMousePos2();
		int GetCurrMousePosX();
		int GetCurrMousePosY();
		int InitParam();
		int SetParam(int ParamType, int Param1, int Param2);
		int KeyPress(int keyCode, int Nbr);
		int KeyPress2(int keyCode, int Nbr);
		int KeyDown(int keyCode);
		int KeyDown2(int keyCode);
		int KeyUp(int keyCode);
		int KeyUp2(int keyCode);
		int KeyState(int keyCode);
		int KeyState2(int keyCode);
		int ReleaseAllKey();
		int NumLockLedState();
		int CapsLockLedState();
		int ScrollLockLedState();
		int KeyInputString(String^ InputStr, int InputLen);
		int KeyInputStringGBK(String^ InputStr, int InputLen);
		int KeyInputStringUnicode(String^ InputStr, int InputLen);
		int LeftClick(int Nbr);
		int LeftDoubleClick(int Nbr);
		int LeftDown();
		int LeftUp();
		int RightClick(int Nbr);
		int RightDown();
		int RightUp();
		int MiddleClick(int Nbr);
		int MiddleDown();
		int MiddleUp();
		int ReleaseAllMouse();
		int MouseKeyState(int MouseKeyCode);
		int MouseWheel(int Nbr);
		int ResetMousePos();
		int ResolutionUsed(int x, int y);
		int Delay(int time);
		int DelayRandom(int Min_time, int Max_time);
		int RandDomNbr(int Min_V, int Max_V);
		~KMSoft();
	};
}

