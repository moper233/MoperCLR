#pragma once
#include ".\dm\dm.tlh"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

#undef FindWindow
#undef FindWindowEx
#undef SetWindowText

using namespace std;
using namespace System;
using namespace msclr::interop;
using namespace System::Runtime::InteropServices;

namespace DMCLR {
	public ref class DMSoft
	{
	private:
		Idmsoft* dm;

	public:
		String^ Ver();
		int MoveTo(int x, int y);
		int MoveR(int x, int y);
		int FindWindow(String^ class_name, String^ title_name);
		int BindWindow(int hwnd, String^ display, String^ mouse, String^ keypad, int mode);
		DMSoft();
		~DMSoft();
	};
}
