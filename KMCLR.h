#pragma once
#include ".\Library\Include\msdk.h"
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
		int Open();
		int Open_VidPid(int vid, int pid);
		int Close();
		int MoveR(int x, int y);
		int MoveTo(int x, int y);
		~KMSoft();
	};
}

