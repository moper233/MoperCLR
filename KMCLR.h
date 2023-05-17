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
		int MoveR(int x, int y);
		int MoveR2(int x,int y);
		int MoveTo(int x, int y);
		int MoveTo2(int x, int y);
		int MoveTo3(int x, int y);
		int MoveTo3_D(int x, int y);
		Tuple<long, long, int>^ GetCurrMousePos();
		Tuple<long, long, int>^ GetCurrMousePos2();
		~KMSoft();
	};
}

