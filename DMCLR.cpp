#include "pch.h"
#include "DMCLR.h"

Idmsoft* GetDmObject()
{
	Idmsoft* m_dm = NULL;
	bool m_bInit = false;
	//直接加载dll创建对象，避免进行注册文件
	typedef HRESULT(_stdcall* pfnGCO)(REFCLSID, REFIID, void**);
	pfnGCO fnGCO = NULL;
	HINSTANCE hdllInst = LoadLibrary(L"dm.dll");
	fnGCO = (pfnGCO)GetProcAddress(hdllInst, "DllGetClassObject");
	if (fnGCO != 0)
	{
		IClassFactory* pcf = NULL;
		HRESULT hr = (fnGCO)(__uuidof(dmsoft), IID_IClassFactory, (void**)&pcf);
		if (SUCCEEDED(hr) && (pcf != NULL))
		{
			hr = pcf->CreateInstance(NULL, __uuidof(Idmsoft), (void**)&m_dm);
			if ((SUCCEEDED(hr) && (m_dm != NULL)) == FALSE)
				return NULL;

		}
		pcf->Release();
		m_bInit = true;
	}
	else
		m_bInit = false;
	return m_dm;

}

static const wchar_t* StringToWchar(String^ value)
{
	auto str = (wchar_t*)(void*)Marshal::StringToHGlobalUni(value);
	return str;
}
static String^ BSTRToString(_bstr_t value)
{
	return gcnew String((WCHAR*)value);
}

String^ DMCLR::DMSoft::Ver()
{
	auto ver = (WCHAR*)dm->Ver();
	return BSTRToString(ver);
}

int DMCLR::DMSoft::SetPath(String^ path)
{
	return dm->SetPath(StringToWchar(path));
}

String^ DMCLR::DMSoft::Ocr(long x1, long y1, long x2, long y2, String^ color, double sim)
{
	auto ret = dm->Ocr(x1, y1, x2, y2, StringToWchar(color), sim);
	return BSTRToString(ret);
}

Tuple<long, long, int>^ DMCLR::DMSoft::FindStr(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	long ret;
	VARIANT x;
	VARIANT y;

	ret = dm->FindStr(x1, y1, x2, y2, StringToWchar(str), StringToWchar(color), sim, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}

int DMCLR::DMSoft::GetResultCount(String^ str)
{
	return dm->GetResultCount(StringToWchar(str));
}

Tuple<long, long, int>^ DMCLR::DMSoft::GetResultPos(String^ str, long index)
{
	long ret;
	VARIANT x;
	VARIANT y;

	ret = dm->GetResultPos(StringToWchar(str), index, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}

int DMCLR::DMSoft::StrStr(String^ s, String^ str)
{
	return dm->StrStr(StringToWchar(s), StringToWchar(str));
}

int DMCLR::DMSoft::SendCommand(String^ cmd)
{
	return dm->SendCommand(StringToWchar(cmd));
}

long DMCLR::DMSoft::UseDict(long index) { return dm->UseDict(index); }
String^ DMCLR::DMSoft::GetBasePath() { return ""; }
long DMCLR::DMSoft::SetDictPwd(String^ pwd) { return dm->SetDictPwd(StringToWchar(pwd)); }
String^ DMCLR::DMSoft::OcrInFile(long x1, long y1, long x2, long y2, String^ pic_name, String^ color, double sim) { return ""; }
long DMCLR::DMSoft::Capture(long x1, long y1, long x2, long y2, String^ file) { return 0; }
long DMCLR::DMSoft::KeyPress(long vk) { return dm->KeyPress(vk); }
long DMCLR::DMSoft::KeyDown(long vk) { return dm->KeyDown(vk); }
long DMCLR::DMSoft::KeyUp(long vk) { return dm->KeyUp(vk); }
long DMCLR::DMSoft::LeftClick() { return dm->LeftClick(); }
long DMCLR::DMSoft::RightClick() { return dm->RightClick(); }
long DMCLR::DMSoft::MiddleClick() { return dm->MiddleClick(); }
long DMCLR::DMSoft::LeftDoubleClick() { return dm->LeftDoubleClick(); }
long DMCLR::DMSoft::LeftDown() { return dm->LeftDown(); }
long DMCLR::DMSoft::LeftUp() { return dm->LeftUp(); }
long DMCLR::DMSoft::RightDown() { return dm->RightDown(); }
long DMCLR::DMSoft::RightUp() { return dm->RightUp(); }
long DMCLR::DMSoft::MoveTo(long x, long y) { return dm->MoveTo(x, y); }
long DMCLR::DMSoft::MoveR(long rx, long ry) { return dm->MoveR(rx, rx); }
String^ DMCLR::DMSoft::GetColor(long x, long y) { return ""; }
String^ DMCLR::DMSoft::GetColorBGR(long x, long y) { return ""; }
String^ DMCLR::DMSoft::RGB2BGR(String^ rgb_color) { return ""; }
String^ DMCLR::DMSoft::BGR2RGB(String^ bgr_color) { return ""; }
long DMCLR::DMSoft::UnBindWindow() { return dm->UnBindWindow(); }
long DMCLR::DMSoft::CmpColor(long x, long y, String^ color, double sim) { return 0; }
long DMCLR::DMSoft::ClientToScreen(long hwnd) { return 0; }
long DMCLR::DMSoft::ScreenToClient(long hwnd) { return 0; }
long DMCLR::DMSoft::ShowScrMsg(long x1, long y1, long x2, long y2, String^ msg, String^ color) { return 0; }
long DMCLR::DMSoft::SetMinRowGap(long row_gap) { return 0; }
long DMCLR::DMSoft::SetMinColGap(long col_gap) { return 0; }
long DMCLR::DMSoft::FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) { return 0; }
String^ DMCLR::DMSoft::FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) { return ""; }
long DMCLR::DMSoft::SetWordLineHeight(long line_height) { return 0; }
long DMCLR::DMSoft::SetWordGap(long word_gap) { return 0; }
long DMCLR::DMSoft::SetRowGapNoDict(long row_gap) { return 0; }
long DMCLR::DMSoft::SetColGapNoDict(long col_gap) { return 0; }
long DMCLR::DMSoft::SetWordLineHeightNoDict(long line_height) { return 0; }
long DMCLR::DMSoft::SetWordGapNoDict(long word_gap) { return 0; }
long DMCLR::DMSoft::GetWordResultCount(String^ str) { return 0; }
long DMCLR::DMSoft::GetWordResultPos(String^ str, long index) { return 0; }
String^ DMCLR::DMSoft::GetWordResultStr(String^ str, long index) { return ""; }
String^ DMCLR::DMSoft::GetWords(long x1, long y1, long x2, long y2, String^ color, double sim) { return ""; }
String^ DMCLR::DMSoft::GetWordsNoDict(long x1, long y1, long x2, long y2, String^ color) { return ""; }
long DMCLR::DMSoft::SetShowErrorMsg(long show) { return dm->SetShowErrorMsg(show); }
long DMCLR::DMSoft::GetClientSize(long hwnd) { return 0; }
long DMCLR::DMSoft::MoveWindow(long hwnd, long x, long y) { return 0; }
String^ DMCLR::DMSoft::GetColorHSV(long x, long y) { return ""; }
String^ DMCLR::DMSoft::GetAveRGB(long x1, long y1, long x2, long y2) { return ""; }
String^ DMCLR::DMSoft::GetAveHSV(long x1, long y1, long x2, long y2) { return ""; }
long DMCLR::DMSoft::GetForegroundWindow() { return 0; }
long DMCLR::DMSoft::GetForegroundFocus() { return 0; }
long DMCLR::DMSoft::GetMousePointWindow() { return 0; }
long DMCLR::DMSoft::GetPointWindow(long x, long y) { return 0; }
String^ DMCLR::DMSoft::EnumWindow(long parent, String^ title, String^ class_name, long filter) { return ""; }
long DMCLR::DMSoft::GetWindowState(long hwnd, long flag) { return 0; }
long DMCLR::DMSoft::GetWindow(long hwnd, long flag) { return 0; }
long DMCLR::DMSoft::GetSpecialWindow(long flag) { return 0; }
long DMCLR::DMSoft::SetWindowText(long hwnd, String^ text) { return 0; }
long DMCLR::DMSoft::SetWindowSize(long hwnd, long width, long height) { return 0; }
long DMCLR::DMSoft::GetWindowRect(long hwnd) { return 0; }
String^ DMCLR::DMSoft::GetWindowTitle(long hwnd) { return ""; }
String^ DMCLR::DMSoft::GetWindowClass(long hwnd) { return ""; }
long DMCLR::DMSoft::SetWindowState(long hwnd, long flag) { return 0; }
long DMCLR::DMSoft::CreateFoobarRect(long hwnd, long x, long y, long w, long h) { return 0; }
long DMCLR::DMSoft::CreateFoobarRoundRect(long hwnd, long x, long y, long w, long h, long rw, long rh) { return 0; }
long DMCLR::DMSoft::CreateFoobarEllipse(long hwnd, long x, long y, long w, long h) { return 0; }
long DMCLR::DMSoft::CreateFoobarCustom(long hwnd, long x, long y, String^ pic, String^ trans_color, double sim) { return 0; }
long DMCLR::DMSoft::FoobarFillRect(long hwnd, long x1, long y1, long x2, long y2, String^ color) { return 0; }
long DMCLR::DMSoft::FoobarDrawText(long hwnd, long x, long y, long w, long h, String^ text, String^ color, long align) { return 0; }
long DMCLR::DMSoft::FoobarDrawPic(long hwnd, long x, long y, String^ pic, String^ trans_color) { return 0; }
long DMCLR::DMSoft::FoobarUpdate(long hwnd) { return 0; }
long DMCLR::DMSoft::FoobarLock(long hwnd) { return 0; }
long DMCLR::DMSoft::FoobarUnlock(long hwnd) { return 0; }
long DMCLR::DMSoft::FoobarSetFont(long hwnd, String^ font_name, long size, long flag) { return 0; }
long DMCLR::DMSoft::FoobarTextRect(long hwnd, long x, long y, long w, long h) { return 0; }
long DMCLR::DMSoft::FoobarPrintText(long hwnd, String^ text, String^ color) { return 0; }
long DMCLR::DMSoft::FoobarClearText(long hwnd) { return 0; }
long DMCLR::DMSoft::FoobarTextLineGap(long hwnd, long gap) { return 0; }
long DMCLR::DMSoft::Play(String^ file) { return 0; }
long DMCLR::DMSoft::FaqCapture(long x1, long y1, long x2, long y2, long quality, long delay, long time) { return 0; }
long DMCLR::DMSoft::FaqRelease(long handle) { return 0; }
String^ DMCLR::DMSoft::FaqSend(String^ server, long handle, long request_type, long time_out) { return ""; }
long DMCLR::DMSoft::Beep(long fre, long delay) { return 0; }
long DMCLR::DMSoft::FoobarClose(long hwnd) { return 0; }
long DMCLR::DMSoft::MoveDD(long dx, long dy) { return 0; }
long DMCLR::DMSoft::FaqGetSize(long handle) { return 0; }
long DMCLR::DMSoft::LoadPic(String^ pic_name) { return 0; }
long DMCLR::DMSoft::FreePic(String^ pic_name) { return 0; }
long DMCLR::DMSoft::GetScreenData(long x1, long y1, long x2, long y2) { return 0; }
long DMCLR::DMSoft::FreeScreenData(long handle) { return 0; }
long DMCLR::DMSoft::WheelUp() { return 0; }
long DMCLR::DMSoft::WheelDown() { return 0; }
long DMCLR::DMSoft::SetMouseDelay(String^ type, long delay) { return 0; }
long DMCLR::DMSoft::SetKeypadDelay(String^ type, long delay) { return 0; }
String^ DMCLR::DMSoft::GetEnv(long index, String^ name) { return ""; }
long DMCLR::DMSoft::SetEnv(long index, String^ name, String^ value) { return 0; }
long DMCLR::DMSoft::SendString(long hwnd, String^ str) { return 0; }
long DMCLR::DMSoft::DelEnv(long index, String^ name) { return 0; }
String^ DMCLR::DMSoft::GetPath() { return ""; }
long DMCLR::DMSoft::SetDict(long index, String^ dict_name) { return dm->SetDict(index, StringToWchar(dict_name)); }
long DMCLR::DMSoft::FindPic(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir) { return 0; }
String^ DMCLR::DMSoft::FindPicEx(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir) { return ""; }
long DMCLR::DMSoft::SetClientSize(long hwnd, long width, long height) { return 0; }
long DMCLR::DMSoft::ReadInt(long hwnd, String^ addr, long type) { return 0; }
float DMCLR::DMSoft::ReadFloat(long hwnd, String^ addr) { return 0; }
double DMCLR::DMSoft::ReadDouble(long hwnd, String^ addr) { return 0; }
String^ DMCLR::DMSoft::FindInt(long hwnd, String^ addr_range, long int_value_min, long int_value_max, long type) { return ""; }
String^ DMCLR::DMSoft::FindFloat(long hwnd, String^ addr_range, float float_value_min, float float_value_max) { return ""; }
String^ DMCLR::DMSoft::FindDouble(long hwnd, String^ addr_range, double double_value_min, double double_value_max) { return ""; }
String^ DMCLR::DMSoft::FindString(long hwnd, String^ addr_range, String^ string_value, long type) { return ""; }
long DMCLR::DMSoft::GetModuleBaseAddr(long hwnd, String^ module_name) { return 0; }
String^ DMCLR::DMSoft::MoveToEx(long x, long y, long w, long h) { return BSTRToString(dm->MoveToEx(x, y, w, h)); }
String^ DMCLR::DMSoft::MatchPicName(String^ pic_name) { return ""; }
long DMCLR::DMSoft::AddDict(long index, String^ dict_info) { return 0; }
long DMCLR::DMSoft::EnterCri() { return 0; }
long DMCLR::DMSoft::LeaveCri() { return 0; }
long DMCLR::DMSoft::WriteInt(long hwnd, String^ addr, long type, long v) { return 0; }
long DMCLR::DMSoft::WriteFloat(long hwnd, String^ addr, float v) { return 0; }
long DMCLR::DMSoft::WriteDouble(long hwnd, String^ addr, double v) { return 0; }
long DMCLR::DMSoft::WriteString(long hwnd, String^ addr, long type, String^ v) { return 0; }
long DMCLR::DMSoft::AsmAdd(String^ asm_ins) { return 0; }
long DMCLR::DMSoft::AsmClear() { return 0; }
long DMCLR::DMSoft::AsmCall(long hwnd, long mode) { return 0; }
long DMCLR::DMSoft::FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) { return 0; }
String^ DMCLR::DMSoft::FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::Assemble(long base_addr, long is_64bit) { return ""; }
String^ DMCLR::DMSoft::DisAssemble(String^ asm_code, long base_addr, long is_64bit) { return ""; }
long DMCLR::DMSoft::SetWindowTransparent(long hwnd, long v) { return 0; }
String^ DMCLR::DMSoft::ReadData(long hwnd, String^ addr, long len) { return ""; }
long DMCLR::DMSoft::WriteData(long hwnd, String^ addr, String^ data) { return 0; }
String^ DMCLR::DMSoft::FindData(long hwnd, String^ addr_range, String^ data) { return ""; }
long DMCLR::DMSoft::SetPicPwd(String^ pwd) { return 0; }
long DMCLR::DMSoft::Log(String^ info) { return 0; }
String^ DMCLR::DMSoft::FindStrE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
String^ DMCLR::DMSoft::FindColorE(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindPicE(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindMultiColorE(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) { return ""; }
long DMCLR::DMSoft::SetExactOcr(long exact_ocr) { return 0; }
String^ DMCLR::DMSoft::ReadString(long hwnd, String^ addr, long type, long len) { return ""; }
long DMCLR::DMSoft::FoobarTextPrintDir(long hwnd, long dir) { return 0; }
String^ DMCLR::DMSoft::OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim) { return ""; }
long DMCLR::DMSoft::SetDisplayInput(String^ mode) { return 0; }
long DMCLR::DMSoft::GetTime() { return 0; }
long DMCLR::DMSoft::GetScreenWidth() { return 0; }
long DMCLR::DMSoft::GetScreenHeight() { return 0; }
long DMCLR::DMSoft::BindWindowEx(long hwnd, String^ display, String^ mouse, String^ keypad, String^ public_desc, long mode)
{
	return dm->BindWindowEx(hwnd, StringToWchar(display), StringToWchar(mouse), StringToWchar(keypad), StringToWchar(public_desc), mode);
}
String^ DMCLR::DMSoft::GetDiskSerial(long index) { return ""; }
String^ DMCLR::DMSoft::Md5(String^ str) { return BSTRToString(dm->Md5(StringToWchar(str))); }
String^ DMCLR::DMSoft::GetMac() { return BSTRToString(dm->GetMac()); }
long DMCLR::DMSoft::ActiveInputMethod(long hwnd, String^ id) { return 0; }
long DMCLR::DMSoft::CheckInputMethod(long hwnd, String^ id) { return 0; }
long DMCLR::DMSoft::FindInputMethod(String^ id) { return 0; }
long DMCLR::DMSoft::GetCursorPos() { return 0; }
long DMCLR::DMSoft::BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode)
{
	return dm->BindWindow(hwnd, StringToWchar(display), StringToWchar(mouse), StringToWchar(keypad), mode);
}
long DMCLR::DMSoft::FindWindow(String^ class_name, String^ title_name) { return dm->FindWindowW(StringToWchar(class_name), StringToWchar(title_name)); }
long DMCLR::DMSoft::GetScreenDepth() { return 0; }
long DMCLR::DMSoft::SetScreen(long width, long height, long depth) { return 0; }
long DMCLR::DMSoft::ExitOs(long type) { return 0; }
String^ DMCLR::DMSoft::GetDir(long type) { return ""; }
long DMCLR::DMSoft::GetOsType() { return 0; }
long DMCLR::DMSoft::FindWindowEx(long parent, String^ class_name, String^ title_name)
{
	return dm->FindWindowExW(parent, StringToWchar(class_name), StringToWchar(title_name));
}
long DMCLR::DMSoft::SetExportDict(long index, String^ dict_name) { return 0; }
String^ DMCLR::DMSoft::GetCursorShape() { return ""; }
long DMCLR::DMSoft::DownCpu(long type, long rate) { return 0; }
String^ DMCLR::DMSoft::GetCursorSpot() { return ""; }
long DMCLR::DMSoft::SendString2(long hwnd, String^ str) { return 0; }
long DMCLR::DMSoft::FaqPost(String^ server, long handle, long request_type, long time_out) { return 0; }
String^ DMCLR::DMSoft::FaqFetch() { return ""; }
String^ DMCLR::DMSoft::FetchWord(long x1, long y1, long x2, long y2, String^ color, String^ word) { return ""; }
long DMCLR::DMSoft::CaptureJpg(long x1, long y1, long x2, long y2, String^ file, long quality) { return 0; }
long DMCLR::DMSoft::FindStrWithFont(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag) { return 0; }
String^ DMCLR::DMSoft::FindStrWithFontE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag) { return ""; }
String^ DMCLR::DMSoft::FindStrWithFontEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag) { return ""; }
String^ DMCLR::DMSoft::GetDictInfo(String^ str, String^ font_name, long font_size, long flag) { return ""; }
long DMCLR::DMSoft::SaveDict(long index, String^ file) { return 0; }
long DMCLR::DMSoft::GetWindowProcessId(long hwnd) { return 0; }
String^ DMCLR::DMSoft::GetWindowProcessPath(long hwnd) { return ""; }
long DMCLR::DMSoft::LockInput(long lock) { return 0; }
String^ DMCLR::DMSoft::GetPicSize(String^ pic_name) { return ""; }
long DMCLR::DMSoft::GetID() { return 0; }
long DMCLR::DMSoft::CapturePng(long x1, long y1, long x2, long y2, String^ file) { return 0; }
long DMCLR::DMSoft::CaptureGif(long x1, long y1, long x2, long y2, String^ file, long delay, long time) { return 0; }
long DMCLR::DMSoft::ImageToBmp(String^ pic_name, String^ bmp_name) { return 0; }
long DMCLR::DMSoft::FindStrFast(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return 0; }
String^ DMCLR::DMSoft::FindStrFastEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
String^ DMCLR::DMSoft::FindStrFastE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
long DMCLR::DMSoft::EnableDisplayDebug(long enable_debug) { return 0; }
long DMCLR::DMSoft::CapturePre(String^ file) { return 0; }
long DMCLR::DMSoft::RegEx(String^ code, String^ Ver, String^ ip) { return 0; }
String^ DMCLR::DMSoft::GetMachineCode() { return ""; }
long DMCLR::DMSoft::SetClipboard(String^ data) { return 0; }
String^ DMCLR::DMSoft::GetClipboard() { return ""; }
long DMCLR::DMSoft::GetNowDict() { return 0; }
long DMCLR::DMSoft::Is64Bit() { return 0; }
long DMCLR::DMSoft::GetColorNum(long x1, long y1, long x2, long y2, String^ color, double sim) { return 0; }
String^ DMCLR::DMSoft::EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter) { return ""; }
long DMCLR::DMSoft::GetDictCount(long index) { return 0; }
long DMCLR::DMSoft::GetLastError() { return 0; }
String^ DMCLR::DMSoft::GetNetTime() { return ""; }
long DMCLR::DMSoft::EnableGetColorByCapture(long en) { return 0; }
long DMCLR::DMSoft::CheckUAC() { return 0; }
long DMCLR::DMSoft::SetUAC(long uac) { return dm->SetUAC(uac); }
long DMCLR::DMSoft::DisableFontSmooth() { return 0; }
long DMCLR::DMSoft::CheckFontSmooth() { return 0; }
long DMCLR::DMSoft::SetDisplayAcceler(long level) { return 0; }
long DMCLR::DMSoft::FindWindowByProcess(String^ process_name, String^ class_name, String^ title_name) { return 0; }
long DMCLR::DMSoft::FindWindowByProcessId(long process_id, String^ class_name, String^ title_name) { return 0; }
String^ DMCLR::DMSoft::ReadIni(String^ section, String^ key, String^ file) { return ""; }
long DMCLR::DMSoft::WriteIni(String^ section, String^ key, String^ v, String^ file) { return 0; }
long DMCLR::DMSoft::RunApp(String^ path, long mode) { return 0; }
long DMCLR::DMSoft::delay(long mis) { return 0; }
long DMCLR::DMSoft::FindWindowSuper(String^ spec1, long flag1, long type1, String^ spec2, long flag2, long type2) { return 0; }
String^ DMCLR::DMSoft::ExcludePos(String^ all_pos, long type, long x1, long y1, long x2, long y2) { return ""; }
String^ DMCLR::DMSoft::FindNearestPos(String^ all_pos, long type, long x, long y) { return ""; }
String^ DMCLR::DMSoft::SortPosDistance(String^ all_pos, long type, long x, long y) { return ""; }
long DMCLR::DMSoft::FindPicMem(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir) { return 0; }
String^ DMCLR::DMSoft::FindPicMemEx(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindPicMemE(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::AppendPicAddr(String^ pic_info, long addr, long size) { return ""; }
long DMCLR::DMSoft::WriteFile(String^ file, String^ content) { return 0; }
long DMCLR::DMSoft::Stop(long id) { return 0; }
long DMCLR::DMSoft::SetDictMem(long index, long addr, long size) { return 0; }
String^ DMCLR::DMSoft::GetNetTimeSafe() { return ""; }
long DMCLR::DMSoft::ForceUnBindWindow(long hwnd) { return 0; }
String^ DMCLR::DMSoft::ReadIniPwd(String^ section, String^ key, String^ file, String^ pwd) { return ""; }
long DMCLR::DMSoft::WriteIniPwd(String^ section, String^ key, String^ v, String^ file, String^ pwd) { return 0; }
long DMCLR::DMSoft::DecodeFile(String^ file, String^ pwd) { return 0; }
long DMCLR::DMSoft::KeyDownChar(String^ key_str) { return 0; }
long DMCLR::DMSoft::KeyUpChar(String^ key_str) { return 0; }
long DMCLR::DMSoft::KeyPressChar(String^ key_str) { return 0; }
long DMCLR::DMSoft::KeyPressStr(String^ key_str, long delay) { return 0; }
long DMCLR::DMSoft::EnableKeypadPatch(long en) { return 0; }
long DMCLR::DMSoft::EnableKeypadSync(long en, long time_out) { return 0; }
long DMCLR::DMSoft::EnableMouseSync(long en, long time_out) { return 0; }
long DMCLR::DMSoft::DmGuard(long en, String^ type) { return dm->DmGuard(en, StringToWchar(type)); }
long DMCLR::DMSoft::FaqCaptureFromFile(long x1, long y1, long x2, long y2, String^ file, long quality) { return 0; }
String^ DMCLR::DMSoft::FindIntEx(long hwnd, String^ addr_range, long int_value_min, long int_value_max, long type, long step, long multi_thread, long mode) { return ""; }
String^ DMCLR::DMSoft::FindFloatEx(long hwnd, String^ addr_range, float float_value_min, float float_value_max, long step, long multi_thread, long mode) { return ""; }
String^ DMCLR::DMSoft::FindDoubleEx(long hwnd, String^ addr_range, double double_value_min, double double_value_max, long step, long multi_thread, long mode) { return ""; }
String^ DMCLR::DMSoft::FindStringEx(long hwnd, String^ addr_range, String^ string_value, long type, long step, long multi_thread, long mode) { return ""; }
String^ DMCLR::DMSoft::FindDataEx(long hwnd, String^ addr_range, String^ data, long step, long multi_thread, long mode) { return ""; }
long DMCLR::DMSoft::EnableRealMouse(long en, long mousedelay, long mousestep) { return 0; }
long DMCLR::DMSoft::EnableRealKeypad(long en) { return 0; }
long DMCLR::DMSoft::SendStringIme(String^ str) { return 0; }
long DMCLR::DMSoft::FoobarDrawLine(long hwnd, long x1, long y1, long x2, long y2, String^ color, long style, long width) { return 0; }
String^ DMCLR::DMSoft::FindStrEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
long DMCLR::DMSoft::IsBind(long hwnd) { return 0; }
long DMCLR::DMSoft::SetDisplayDelay(long t) { return 0; }
long DMCLR::DMSoft::GetDmCount() { return 0; }
long DMCLR::DMSoft::DisableScreenSave() { return 0; }
long DMCLR::DMSoft::DisablePowerSave() { return 0; }
long DMCLR::DMSoft::SetMemoryHwndAsProcessId(long en) { return 0; }
long DMCLR::DMSoft::FindShape(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir) { return 0; }
String^ DMCLR::DMSoft::FindShapeE(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindShapeEx(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindStrS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
String^ DMCLR::DMSoft::FindStrExS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
String^ DMCLR::DMSoft::FindStrFastS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
String^ DMCLR::DMSoft::FindStrFastExS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim) { return ""; }
String^ DMCLR::DMSoft::FindPicS(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindPicExS(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir) { return ""; }
long DMCLR::DMSoft::ClearDict(long index) { return 0; }
String^ DMCLR::DMSoft::GetMachineCodeNoMac() { return ""; }
long DMCLR::DMSoft::GetClientRect(long hwnd) { return 0; }
long DMCLR::DMSoft::EnableFakeActive(long en) { return 0; }
long DMCLR::DMSoft::GetScreenDataBmp(long x1, long y1, long x2, long y2) { return 0; }
long DMCLR::DMSoft::EncodeFile(String^ file, String^ pwd) { return 0; }
String^ DMCLR::DMSoft::GetCursorShapeEx(long type) { return ""; }
long DMCLR::DMSoft::FaqCancel() { return 0; }
String^ DMCLR::DMSoft::IntToData(long int_value, long type) { return ""; }
String^ DMCLR::DMSoft::FloatToData(float float_value) { return ""; }
String^ DMCLR::DMSoft::DoubleToData(double double_value) { return ""; }
String^ DMCLR::DMSoft::StringToData(String^ string_value, long type) { return ""; }
long DMCLR::DMSoft::SetMemoryFindResultToFile(String^ file) { return 0; }
long DMCLR::DMSoft::EnableBind(long en) { return 0; }
long DMCLR::DMSoft::SetSimMode(long mode) { return 0; }
long DMCLR::DMSoft::LockMouseRect(long x1, long y1, long x2, long y2) { return 0; }
long DMCLR::DMSoft::SendPaste(long hwnd) { return 0; }
long DMCLR::DMSoft::IsDisplayDead(long x1, long y1, long x2, long y2, long t) { return 0; }
long DMCLR::DMSoft::GetKeyState(long vk) { return 0; }
long DMCLR::DMSoft::CopyFile(String^ src_file, String^ dst_file, long over) { return 0; }
long DMCLR::DMSoft::IsFileExist(String^ file) { return 0; }
long DMCLR::DMSoft::DeleteFile(String^ file) { return 0; }
long DMCLR::DMSoft::MoveFile(String^ src_file, String^ dst_file) { return 0; }
long DMCLR::DMSoft::CreateFolder(String^ folder_name) { return 0; }
long DMCLR::DMSoft::DeleteFolder(String^ folder_name) { return 0; }
long DMCLR::DMSoft::GetFileLength(String^ file) { return 0; }
String^ DMCLR::DMSoft::ReadFile(String^ file) { return ""; }
long DMCLR::DMSoft::WaitKey(long key_code, long time_out) { return 0; }
long DMCLR::DMSoft::DeleteIni(String^ section, String^ key, String^ file) { return 0; }
long DMCLR::DMSoft::DeleteIniPwd(String^ section, String^ key, String^ file, String^ pwd) { return 0; }
long DMCLR::DMSoft::EnableSpeedDx(long en) { return 0; }
long DMCLR::DMSoft::EnableIme(long en) { return 0; }

long DMCLR::DMSoft::Reg(String^ code, String^ Ver)
{
	return dm->Reg(StringToWchar(code), StringToWchar(Ver));
}
String^ DMCLR::DMSoft::SelectFile() { return ""; }
String^ DMCLR::DMSoft::SelectDirectory() { return ""; }
long DMCLR::DMSoft::LockDisplay(long lock) { return 0; }
long DMCLR::DMSoft::FoobarSetSave(long hwnd, String^ file, long en, String^ header) { return 0; }
String^ DMCLR::DMSoft::EnumWindowSuper(String^ spec1, long flag1, long type1, String^ spec2, long flag2, long type2, long sort) { return ""; }
long DMCLR::DMSoft::DownloadFile(String^ url, String^ save_file, long timeout) { return 0; }
long DMCLR::DMSoft::EnableKeypadMsg(long en) { return 0; }
long DMCLR::DMSoft::EnableMouseMsg(long en) { return 0; }
long DMCLR::DMSoft::RegNoMac(String^ code, String^ Ver) { return 0; }
long DMCLR::DMSoft::RegExNoMac(String^ code, String^ Ver, String^ ip) { return 0; }
long DMCLR::DMSoft::SetEnumWindowDelay(long delay) { return 0; }
long DMCLR::DMSoft::FindMulColor(long x1, long y1, long x2, long y2, String^ color, double sim) { return 0; }
String^ DMCLR::DMSoft::GetDict(long index, long font_index) { return ""; }
long DMCLR::DMSoft::GetBindWindow() { return dm->GetBindWindow(); }
long DMCLR::DMSoft::FoobarStartGif(long hwnd, long x, long y, String^ pic_name, long repeat_limit, long delay) { return 0; }
long DMCLR::DMSoft::FoobarStopGif(long hwnd, long x, long y, String^ pic_name) { return 0; }
long DMCLR::DMSoft::FreeProcessMemory(long hwnd) { return 0; }
String^ DMCLR::DMSoft::ReadFileData(String^ file, long start_pos, long end_pos) { return ""; }
long DMCLR::DMSoft::VirtualAllocEx(long hwnd, long addr, long size, long type) { return 0; }
long DMCLR::DMSoft::VirtualFreeEx(long hwnd, long addr) { return 0; }
String^ DMCLR::DMSoft::GetCommandLine(long hwnd) { return ""; }
long DMCLR::DMSoft::TerminateProcess(long pid) { return 0; }
String^ DMCLR::DMSoft::GetNetTimeByIp(String^ ip) { return ""; }
String^ DMCLR::DMSoft::EnumProcess(String^ name) { return ""; }
String^ DMCLR::DMSoft::GetProcessInfo(long pid) { return ""; }
long DMCLR::DMSoft::ReadIntAddr(long hwnd, long addr, long type) { return 0; }
String^ DMCLR::DMSoft::ReadDataAddr(long hwnd, long addr, long len) { return ""; }
double DMCLR::DMSoft::ReadDoubleAddr(long hwnd, long addr) { return 0; }
float DMCLR::DMSoft::ReadFloatAddr(long hwnd, long addr) { return 0; }
String^ DMCLR::DMSoft::ReadStringAddr(long hwnd, long addr, long type, long len) { return ""; }
long DMCLR::DMSoft::WriteDataAddr(long hwnd, long addr, String^ data) { return 0; }
long DMCLR::DMSoft::WriteDoubleAddr(long hwnd, long addr, double v) { return 0; }
long DMCLR::DMSoft::WriteFloatAddr(long hwnd, long addr, float v) { return 0; }
long DMCLR::DMSoft::WriteIntAddr(long hwnd, long addr, long type, long v) { return 0; }
long DMCLR::DMSoft::WriteStringAddr(long hwnd, long addr, long type, String^ v) { return 0; }
long DMCLR::DMSoft::Delays(long min_s, long max_s) { return 0; }
long DMCLR::DMSoft::FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long width, long height) { return 0; }
String^ DMCLR::DMSoft::FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long width, long height) { return ""; }
long DMCLR::DMSoft::OpenProcess(long pid) { return 0; }
String^ DMCLR::DMSoft::EnumIniSection(String^ file) { return ""; }
String^ DMCLR::DMSoft::EnumIniSectionPwd(String^ file, String^ pwd) { return ""; }
String^ DMCLR::DMSoft::EnumIniKey(String^ section, String^ file) { return ""; }
String^ DMCLR::DMSoft::EnumIniKeyPwd(String^ section, String^ file, String^ pwd) { return ""; }
long DMCLR::DMSoft::SwitchBindWindow(long hwnd) { return 0; }
long DMCLR::DMSoft::InitCri() { return 0; }
long DMCLR::DMSoft::SendStringIme2(long hwnd, String^ str, long mode) { return 0; }
String^ DMCLR::DMSoft::EnumWindowByProcessId(long pid, String^ title, String^ class_name, long filter) { return ""; }
String^ DMCLR::DMSoft::GetDisplayInfo() { return ""; }
long DMCLR::DMSoft::EnableFontSmooth() { return 0; }
String^ DMCLR::DMSoft::OcrExOne(long x1, long y1, long x2, long y2, String^ color, double sim) { return ""; }
long DMCLR::DMSoft::SetAero(long en) { return 0; }
long DMCLR::DMSoft::FoobarSetTrans(long hwnd, long trans, String^ color, double sim) { return 0; }
long DMCLR::DMSoft::EnablePicCache(long en) { return 0; }
long DMCLR::DMSoft::FaqIsPosted() { return 0; }
long DMCLR::DMSoft::LoadPicByte(long addr, long size, String^ name) { return 0; }
long DMCLR::DMSoft::MiddleDown() { return 0; }
long DMCLR::DMSoft::MiddleUp() { return 0; }
long DMCLR::DMSoft::FaqCaptureString(String^ str) { return 0; }
long DMCLR::DMSoft::VirtualProtectEx(long hwnd, long addr, long size, long type, long old_protect) { return 0; }
long DMCLR::DMSoft::SetMouseSpeed(long speed) { return 0; }
long DMCLR::DMSoft::GetMouseSpeed() { return 0; }
long DMCLR::DMSoft::EnableMouseAccuracy(long en) { return 0; }
long DMCLR::DMSoft::SetExcludeRegion(long type, String^ info) { return 0; }
long DMCLR::DMSoft::EnableShareDict(long en) { return 0; }
long DMCLR::DMSoft::DisableCloseDisplayAndSleep() { return 0; }
long DMCLR::DMSoft::Int64ToInt32(long v) { return 0; }
long DMCLR::DMSoft::GetLocale() { return 0; }
long DMCLR::DMSoft::SetLocale() { return 0; }
long DMCLR::DMSoft::ReadDataToBin(long hwnd, String^ addr, long len) { return 0; }
long DMCLR::DMSoft::WriteDataFromBin(long hwnd, String^ addr, long data, long len) { return 0; }
long DMCLR::DMSoft::ReadDataAddrToBin(long hwnd, long addr, long len) { return 0; }
long DMCLR::DMSoft::WriteDataAddrFromBin(long hwnd, long addr, long data, long len) { return 0; }
long DMCLR::DMSoft::SetParam64ToPointer() { return 0; }
long DMCLR::DMSoft::GetDPI() { return 0; }
long DMCLR::DMSoft::SetDisplayRefreshDelay(long t) { return 0; }
long DMCLR::DMSoft::IsFolderExist(String^ folder) { return 0; }
long DMCLR::DMSoft::GetCpuType() { return 0; }
long DMCLR::DMSoft::ReleaseRef() { return 0; }
long DMCLR::DMSoft::SetExitThread(long en) { return 0; }
long DMCLR::DMSoft::GetFps() { return 0; }
String^ DMCLR::DMSoft::VirtualQueryEx(long hwnd, long addr, long pmbi) { return ""; }
long DMCLR::DMSoft::AsmCallEx(long hwnd, long mode, String^ base_addr) { return 0; }
long DMCLR::DMSoft::GetRemoteApiAddress(long hwnd, long base_addr, String^ fun_name) { return 0; }
String^ DMCLR::DMSoft::ExecuteCmd(String^ cmd, String^ current_dir, long time_out) { return ""; }
long DMCLR::DMSoft::SpeedNormalGraphic(long en) { return 0; }
long DMCLR::DMSoft::UnLoadDriver() { return 0; }
long DMCLR::DMSoft::GetOsBuildNumber() { return 0; }
long DMCLR::DMSoft::HackSpeed(double rate) { return 0; }
String^ DMCLR::DMSoft::GetRealPath(String^ path) { return ""; }
long DMCLR::DMSoft::ShowTaskBarIcon(long hwnd, long is_show) { return 0; }
long DMCLR::DMSoft::AsmSetTimeout(long time_out, long param) { return 0; }
String^ DMCLR::DMSoft::DmGuardParams(String^ cmd, String^ sub_cmd, String^ param) { return ""; }
long DMCLR::DMSoft::GetModuleSize(long hwnd, String^ module_name) { return 0; }
long DMCLR::DMSoft::IsSurrpotVt() { return 0; }
String^ DMCLR::DMSoft::GetDiskModel(long index) { return ""; }
String^ DMCLR::DMSoft::GetDiskReversion(long index) { return ""; }
long DMCLR::DMSoft::EnableFindPicMultithread(long en) { return 0; }
long DMCLR::DMSoft::GetCpuUsage() { return 0; }
long DMCLR::DMSoft::GetMemoryUsage() { return 0; }
String^ DMCLR::DMSoft::Hex32(long v) { return ""; }
String^ DMCLR::DMSoft::Hex64(long v) { return ""; }
long DMCLR::DMSoft::GetWindowThreadId(long hwnd) { return 0; }
long DMCLR::DMSoft::DmGuardExtract(String^ type, String^ path) { return 0; }
long DMCLR::DMSoft::DmGuardLoadCustom(String^ type, String^ path) { return 0; }
long DMCLR::DMSoft::SetShowAsmErrorMsg(long show) { return 0; }
String^ DMCLR::DMSoft::GetSystemInfo(String^ type, long method) { return ""; }
long DMCLR::DMSoft::SetFindPicMultithreadCount(long count) { return 0; }
long DMCLR::DMSoft::FindPicSim(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir) { return 0; }
String^ DMCLR::DMSoft::FindPicSimEx(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir) { return ""; }
long DMCLR::DMSoft::FindPicSimMem(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir) { return 0; }
String^ DMCLR::DMSoft::FindPicSimMemEx(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindPicSimE(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir) { return ""; }
String^ DMCLR::DMSoft::FindPicSimMemE(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir) { return ""; }
long DMCLR::DMSoft::SetInputDm(long input_dm, long rx, long ry) { return 0; }
long DMCLR::DMSoft::SetFindPicMultithreadLimit(long limit) { return 0; }


DMCLR::DMSoft::DMSoft()
{
	dm = GetDmObject();
}

DMCLR::DMSoft::~DMSoft()
{
	//释放dm
	if (dm != NULL)
	{
		dm->Release();
		dm = NULL;
	}
}
