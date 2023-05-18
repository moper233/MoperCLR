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

String^ DMCLR::DMSoft::Ver()
{
	auto ver = (WCHAR*)dm->Ver();
	return Util::Util::BSTRToString(ver);
}

int DMCLR::DMSoft::SetPath(String^ path)
{
	return dm->SetPath(Util::Util::StringToWchar(path));
}

String^ DMCLR::DMSoft::Ocr(long x1, long y1, long x2, long y2, String^ color, double sim)
{
	auto ret = dm->Ocr(x1, y1, x2, y2, Util::Util::StringToWchar(color), sim);
	return Util::Util::BSTRToString(ret);
}

Tuple<long, long, int>^ DMCLR::DMSoft::FindStr(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	long ret;
	VARIANT x;
	VARIANT y;

	ret = dm->FindStr(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}

int DMCLR::DMSoft::GetResultCount(String^ str)
{
	return dm->GetResultCount(Util::StringToWchar(str));
}

Tuple<long, long, int>^ DMCLR::DMSoft::GetResultPos(String^ str, long index)
{
	long ret;
	VARIANT x;
	VARIANT y;

	ret = dm->GetResultPos(Util::StringToWchar(str), index, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}

int DMCLR::DMSoft::StrStr(String^ s, String^ str)
{
	return dm->StrStr(Util::StringToWchar(s), Util::StringToWchar(str));
}

int DMCLR::DMSoft::SendCommand(String^ cmd)
{
	return dm->SendCommand(Util::StringToWchar(cmd));
}

long DMCLR::DMSoft::UseDict(long index) { return dm->UseDict(index); }
String^ DMCLR::DMSoft::GetBasePath()
{
	auto ret = dm->GetBasePath();
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::SetDictPwd(String^ pwd) { return dm->SetDictPwd(Util::StringToWchar(pwd)); }
String^ DMCLR::DMSoft::OcrInFile(long x1, long y1, long x2, long y2, String^ pic_name, String^ color, double sim)
{ 
	auto ret = dm->OcrInFile(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(color), sim);
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::Capture(long x1, long y1, long x2, long y2, String^ file) 
{
	return dm->Capture(x1, y1, x2, y2, Util::StringToWchar(file));
}
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
String^ DMCLR::DMSoft::GetColor(long x, long y)
{
	auto ret = dm->GetColor(x, y);
	return Util::BSTRToString(ret);
}

String^ DMCLR::DMSoft::GetColorBGR(long x, long y)
{
	auto ret = dm->GetColorBGR(x, y);
	return Util::BSTRToString(ret);
}

String^ DMCLR::DMSoft::RGB2BGR(String^ rgb_color)
{
	auto ret = dm->RGB2BGR(Util::StringToWchar(rgb_color));
	return Util::BSTRToString(ret);
}
String^ DMCLR::DMSoft::BGR2RGB(String^ bgr_color)
{
	auto ret = dm->BGR2RGB(Util::StringToWchar(bgr_color));
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::UnBindWindow() { return dm->UnBindWindow(); }
long DMCLR::DMSoft::CmpColor(long x, long y, String^ color, double sim)
{
	return dm->CmpColor(x, y, Util::StringToWchar(color), sim);
}

Tuple<long, long, int>^ DMCLR::DMSoft::ClientToScreen(long hwnd)
{
	long ret;
	VARIANT x;
	VARIANT y;
	ret = dm->ClientToScreen(hwnd, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}

Tuple<long, long, int>^ DMCLR::DMSoft::ScreenToClient(long hwnd)
{
	long ret;
	VARIANT x;
	VARIANT y;
	ret = dm->ScreenToClient(hwnd, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
long DMCLR::DMSoft::ShowScrMsg(long x1, long y1, long x2, long y2, String^ msg, String^ color)
{
	return dm->ShowScrMsg(x1, y1, x2, y2, Util::StringToWchar(msg), Util::StringToWchar(color));
}
long DMCLR::DMSoft::SetMinRowGap(long row_gap)
{
	return dm->SetMinRowGap(row_gap);
}
long DMCLR::DMSoft::SetMinColGap(long col_gap)
{
	return dm->SetMinColGap(col_gap);
}

Tuple<long, long, int>^ DMCLR::DMSoft::FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir)
{
	long ret;
	VARIANT x;
	VARIANT y;
	ret = dm->FindColor(x1, y1, x2, y2, Util::StringToWchar(color), sim, dir, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir)
{
	auto ret = dm->FindColorEx(x1, y1, x2, y2, Util::StringToWchar(color), sim, dir);
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::SetWordLineHeight(long line_height)
{
	return dm->SetWordLineHeight(line_height);
}
long DMCLR::DMSoft::SetWordGap(long word_gap)
{
	return dm->SetWordGap(word_gap);
}
long DMCLR::DMSoft::SetRowGapNoDict(long row_gap) { return dm->SetRowGapNoDict(row_gap); }
long DMCLR::DMSoft::SetColGapNoDict(long col_gap) { return dm->SetColGapNoDict(col_gap); }
long DMCLR::DMSoft::SetWordLineHeightNoDict(long line_height) { return dm->SetWordLineHeightNoDict(line_height); }
long DMCLR::DMSoft::SetWordGapNoDict(long word_gap) { return dm->SetWordGapNoDict(word_gap); }
long DMCLR::DMSoft::GetWordResultCount(String^ str) { return dm->GetWordResultCount(Util::StringToWchar(str)); }
Tuple<long, long, int>^ DMCLR::DMSoft::GetWordResultPos(String^ str, long index)
{
	VARIANT x, y;
	auto ret = dm->GetWordResultPos(Util::StringToWchar(str), index, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::GetWordResultStr(String^ str, long index)
{
	auto ret = dm->GetWordResultStr(Util::StringToWchar(str), index);
	return Util::BSTRToString(ret);
}
String^ DMCLR::DMSoft::GetWords(long x1, long y1, long x2, long y2, String^ color, double sim)
{
	return Util::BSTRToString(dm->GetWords(x1, y1, x2, y2, Util::StringToWchar(color), sim));
}
String^ DMCLR::DMSoft::GetWordsNoDict(long x1, long y1, long x2, long y2, String^ color)
{
	return Util::BSTRToString(dm->GetWordsNoDict(x1, y1, x2, y2, Util::StringToWchar(color)));
}
long DMCLR::DMSoft::SetShowErrorMsg(long show) { return dm->SetShowErrorMsg(show); }
Tuple<long, long, int>^ DMCLR::DMSoft::GetClientSize(long hwnd)
{
	VARIANT x, y;
	auto ret = dm->GetClientSize(hwnd, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
long DMCLR::DMSoft::MoveWindow(long hwnd, long x, long y) { return dm->MoveWindow(hwnd, x, y); }
String^ DMCLR::DMSoft::GetColorHSV(long x, long y) { return Util::BSTRToString(dm->GetColorHSV(x, y)); }
String^ DMCLR::DMSoft::GetAveRGB(long x1, long y1, long x2, long y2) { return Util::BSTRToString(dm->GetAveRGB(x1, y1, x2, y2)); }
String^ DMCLR::DMSoft::GetAveHSV(long x1, long y1, long x2, long y2) { return Util::BSTRToString(dm->GetAveHSV(x1, y1, x2, y2)); }
long DMCLR::DMSoft::GetForegroundWindow() { return dm->GetForegroundWindow(); }
long DMCLR::DMSoft::GetForegroundFocus() { return dm->GetForegroundFocus(); }
long DMCLR::DMSoft::GetMousePointWindow() { return dm->GetMousePointWindow(); }
long DMCLR::DMSoft::GetPointWindow(long x, long y) { return dm->GetPointWindow(x, y); }
String^ DMCLR::DMSoft::EnumWindow(long parent, String^ title, String^ class_name, long filter)
{
	return Util::BSTRToString(dm->EnumWindow(parent, Util::StringToWchar(title), Util::StringToWchar(class_name), filter));
}
long DMCLR::DMSoft::GetWindowState(long hwnd, long flag) { return dm->GetWindowState(hwnd, flag); }
long DMCLR::DMSoft::GetWindow(long hwnd, long flag) { return dm->GetWindow(hwnd, flag); }
long DMCLR::DMSoft::GetSpecialWindow(long flag) { return dm->GetSpecialWindow(flag); }
long DMCLR::DMSoft::SetWindowText(long hwnd, String^ text) { return dm->SetWindowTextW(hwnd, Util::StringToWchar(text)); }
long DMCLR::DMSoft::SetWindowSize(long hwnd, long width, long height) { return dm->SetWindowSize(hwnd, width, height); }
Tuple<long, long, long, long, int>^ DMCLR::DMSoft::GetWindowRect(long hwnd)
{
	VARIANT x1, y1, x2, y2;
	auto ret = dm->GetWindowRect(hwnd, &x1, &y1, &x2, &y2);
	return gcnew Tuple<long, long, long, long, int>(x1.lVal, y1.lVal, x2.lVal, y2.lVal, ret);
}
String^ DMCLR::DMSoft::GetWindowTitle(long hwnd) { return Util::BSTRToString(dm->GetWindowTitle(hwnd)); }
String^ DMCLR::DMSoft::GetWindowClass(long hwnd) { return Util::BSTRToString(dm->GetWindowClass(hwnd)); }
long DMCLR::DMSoft::SetWindowState(long hwnd, long flag) { return dm->SetWindowState(hwnd, flag); }

long DMCLR::DMSoft::CreateFoobarRect(long hwnd, long x, long y, long w, long h)
{
	return dm->CreateFoobarRect(hwnd, x, y, w, h);
}

long DMCLR::DMSoft::CreateFoobarRoundRect(long hwnd, long x, long y, long w, long h, long rw, long rh)
{
	return dm->CreateFoobarRoundRect(hwnd, x, y, w, h, rw, rh);
}
long DMCLR::DMSoft::CreateFoobarEllipse(long hwnd, long x, long y, long w, long h)
{
	return dm->CreateFoobarEllipse(hwnd, x, y, w, h);
}
long DMCLR::DMSoft::CreateFoobarCustom(long hwnd, long x, long y, String^ pic, String^ trans_color, double sim)
{
	return dm->CreateFoobarCustom(hwnd, x, y, Util::StringToWchar(pic), Util::StringToWchar(trans_color), sim);
}
long DMCLR::DMSoft::FoobarFillRect(long hwnd, long x1, long y1, long x2, long y2, String^ color)
{
	return dm->FoobarFillRect(hwnd, x1, y1, x2, y2, Util::StringToWchar(color));
}

long DMCLR::DMSoft::FoobarDrawText(long hwnd, long x, long y, long w, long h, String^ text, String^ color, long align)
{
	return dm->FoobarDrawText(hwnd, x, y, w, h, Util::StringToWchar(text), Util::StringToWchar(color), align);
}
long DMCLR::DMSoft::FoobarDrawPic(long hwnd, long x, long y, String^ pic, String^ trans_color)
{
	return dm->FoobarDrawPic(hwnd, x, y, Util::StringToWchar(pic), Util::StringToWchar(trans_color));
}

long DMCLR::DMSoft::FoobarUpdate(long hwnd) { return dm->FoobarUpdate(hwnd); }
long DMCLR::DMSoft::FoobarLock(long hwnd) { return dm->FoobarLock(hwnd); }
long DMCLR::DMSoft::FoobarUnlock(long hwnd) { return dm->FoobarUnlock(hwnd); }
long DMCLR::DMSoft::FoobarSetFont(long hwnd, String^ font_name, long size, long flag)
{
	return dm->FoobarSetFont(hwnd, Util::StringToWchar(font_name), size, flag);
}
long DMCLR::DMSoft::FoobarTextRect(long hwnd, long x, long y, long w, long h) { return dm->FoobarTextRect(hwnd, x, y, w, h); }
long DMCLR::DMSoft::FoobarPrintText(long hwnd, String^ text, String^ color) { return dm->FoobarPrintText(hwnd, Util::StringToWchar(text), Util::StringToWchar(color)); }
long DMCLR::DMSoft::FoobarClearText(long hwnd) { return dm->FoobarClearText(hwnd); }
long DMCLR::DMSoft::FoobarTextLineGap(long hwnd, long gap) { return dm->FoobarTextLineGap(hwnd, gap); }
long DMCLR::DMSoft::Play(String^ file) { return dm->Play(Util::StringToWchar(file)); }
long DMCLR::DMSoft::FaqCapture(long x1, long y1, long x2, long y2, long quality, long delay, long time) { return dm->FaqCapture(x1, y1, x2, y2, quality, delay, time); }
long DMCLR::DMSoft::FaqRelease(long handle) { return dm->FaqRelease(handle); }
String^ DMCLR::DMSoft::FaqSend(String^ server, long handle, long request_type, long time_out) { return Util::BSTRToString(dm->FaqSend(Util::StringToWchar(server), handle, request_type, time_out)); }
long DMCLR::DMSoft::Beep(long fre, long delay) { return dm->Beep(fre, delay); }
long DMCLR::DMSoft::FoobarClose(long hwnd) { return dm->FoobarClose(hwnd); }
long DMCLR::DMSoft::MoveDD(long dx, long dy) { return dm->MoveDD(dx, dy); }
long DMCLR::DMSoft::FaqGetSize(long handle) { return dm->FaqGetSize(handle); }
long DMCLR::DMSoft::LoadPic(String^ pic_name) { return dm->LoadPic(Util::StringToWchar(pic_name)); }
long DMCLR::DMSoft::FreePic(String^ pic_name) { return dm->FreePic(Util::StringToWchar(pic_name)); }
long DMCLR::DMSoft::GetScreenData(long x1, long y1, long x2, long y2) { return dm->GetScreenData(x1, y1, x2, y2); }
long DMCLR::DMSoft::FreeScreenData(long handle) { return dm->FreeScreenData(handle); }
long DMCLR::DMSoft::WheelUp() { return dm->WheelUp(); }
long DMCLR::DMSoft::WheelDown() { return dm->WheelDown(); }
long DMCLR::DMSoft::SetMouseDelay(String^ type, long delay) { return dm->SetMouseDelay(Util::StringToWchar(type), delay); }
long DMCLR::DMSoft::SetKeypadDelay(String^ type, long delay) { return dm->SetKeypadDelay(Util::StringToWchar(type), delay); }
String^ DMCLR::DMSoft::GetEnv(long index, String^ name) { return Util::BSTRToString(dm->GetEnv(index, Util::StringToWchar(name))); }
long DMCLR::DMSoft::SetEnv(long index, String^ name, String^ value) { return dm->SetEnv(index, Util::StringToWchar(name), Util::StringToWchar(value)); }
long DMCLR::DMSoft::SendString(long hwnd, String^ str) { return dm->SendString(hwnd, Util::StringToWchar(str)); }
long DMCLR::DMSoft::DelEnv(long index, String^ name) { return dm->DelEnv(index, Util::StringToWchar(name)); }
String^ DMCLR::DMSoft::GetPath() { return Util::BSTRToString(dm->GetPath()); }
long DMCLR::DMSoft::SetDict(long index, String^ dict_name) { return dm->SetDict(index, Util::StringToWchar(dict_name)); }
Tuple<long, long, int>^ DMCLR::DMSoft::FindPic(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir)
{
	long ret;
	VARIANT x;
	VARIANT y;
	ret = dm->FindPic(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindPicEx(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir)
{
	auto ret = dm->FindPicEx(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir);
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::SetClientSize(long hwnd, long width, long height) { return dm->SetClientSize(hwnd, width, height); }
long long DMCLR::DMSoft::ReadInt(long hwnd, String^ addr, long type) { return dm->ReadInt(hwnd, Util::StringToWchar(addr), type); }
float DMCLR::DMSoft::ReadFloat(long hwnd, String^ addr) { return dm->ReadFloat(hwnd, Util::StringToWchar(addr)); }
double DMCLR::DMSoft::ReadDouble(long hwnd, String^ addr) { return dm->ReadDouble(hwnd, Util::StringToWchar(addr)); }
String^ DMCLR::DMSoft::FindInt(long hwnd, String^ addr_range, long int_value_min, long int_value_max, long type) { return Util::BSTRToString(dm->FindInt(hwnd, Util::StringToWchar(addr_range), int_value_min, int_value_max, type)); }
String^ DMCLR::DMSoft::FindFloat(long hwnd, String^ addr_range, float float_value_min, float float_value_max) { return Util::BSTRToString(dm->FindFloat(hwnd, Util::StringToWchar(addr_range), float_value_min, float_value_max)); }
String^ DMCLR::DMSoft::FindDouble(long hwnd, String^ addr_range, double double_value_min, double double_value_max) { return Util::BSTRToString(dm->FindDouble(hwnd, Util::StringToWchar(addr_range), double_value_min, double_value_max)); }
String^ DMCLR::DMSoft::FindString(long hwnd, String^ addr_range, String^ string_value, long type) { return Util::BSTRToString(dm->FindString(hwnd, Util::StringToWchar(addr_range), Util::StringToWchar(string_value), type)); }
long long DMCLR::DMSoft::GetModuleBaseAddr(long hwnd, String^ module_name) { return dm->GetModuleBaseAddr(hwnd, Util::StringToWchar(module_name)); }
String^ DMCLR::DMSoft::MoveToEx(long x, long y, long w, long h) { return Util::BSTRToString(dm->MoveToEx(x, y, w, h)); }
String^ DMCLR::DMSoft::MatchPicName(String^ pic_name) { return Util::BSTRToString(dm->MatchPicName(Util::StringToWchar(pic_name))); }
long DMCLR::DMSoft::AddDict(long index, String^ dict_info) { return dm->AddDict(index, Util::StringToWchar(dict_info)); }
long DMCLR::DMSoft::EnterCri() { return dm->EnterCri(); }
long DMCLR::DMSoft::LeaveCri() { return dm->LeaveCri(); }
long DMCLR::DMSoft::WriteInt(long hwnd, String^ addr, long type, long v) { return dm->WriteInt(hwnd, Util::StringToWchar(addr), type, v); }
long DMCLR::DMSoft::WriteFloat(long hwnd, String^ addr, float v) { return dm->WriteFloat(hwnd, Util::StringToWchar(addr), v); }
long DMCLR::DMSoft::WriteDouble(long hwnd, String^ addr, double v) { return dm->WriteDouble(hwnd, Util::StringToWchar(addr), v); }
long DMCLR::DMSoft::WriteString(long hwnd, String^ addr, long type, String^ v) { return dm->WriteString(hwnd, Util::StringToWchar(addr), type, Util::StringToWchar(v)); }
long DMCLR::DMSoft::AsmAdd(String^ asm_ins) { return dm->AsmAdd(Util::StringToWchar(asm_ins)); }
long DMCLR::DMSoft::AsmClear() { return dm->AsmClear(); }
long long DMCLR::DMSoft::AsmCall(long hwnd, long mode) { return dm->AsmCall(hwnd, mode); }
Tuple<long, long, int>^ DMCLR::DMSoft::FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir)
{
	VARIANT x, y;
	auto ret = dm->FindMultiColor(x1, y1, x2, y2, Util::StringToWchar(first_color), Util::StringToWchar(offset_color), sim, dir, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir)
{
	auto ret = dm->FindMultiColorEx(x1, y1, x2, y2, Util::StringToWchar(first_color), Util::StringToWchar(offset_color), sim, dir);
	return Util::BSTRToString(ret);
}
String^ DMCLR::DMSoft::Assemble(long base_addr, long is_64bit) { return Util::BSTRToString(dm->Assemble(base_addr, is_64bit)); }
String^ DMCLR::DMSoft::DisAssemble(String^ asm_code, long base_addr, long is_64bit) { return Util::BSTRToString(dm->DisAssemble(Util::StringToWchar(asm_code), base_addr, is_64bit)); }
long DMCLR::DMSoft::SetWindowTransparent(long hwnd, long v) { return dm->SetWindowTransparent(hwnd, v); }
String^ DMCLR::DMSoft::ReadData(long hwnd, String^ addr, long len) { return Util::BSTRToString(dm->ReadData(hwnd, Util::StringToWchar(addr), len)); }
long DMCLR::DMSoft::WriteData(long hwnd, String^ addr, String^ data) { return dm->WriteData(hwnd, Util::StringToWchar(addr), Util::StringToWchar(data)); }
String^ DMCLR::DMSoft::FindData(long hwnd, String^ addr_range, String^ data) { return Util::BSTRToString(dm->FindData(hwnd, Util::StringToWchar(addr_range), Util::StringToWchar(data))); }
long DMCLR::DMSoft::SetPicPwd(String^ pwd) { return dm->SetPicPwd(Util::StringToWchar(pwd)); }
long DMCLR::DMSoft::Log(String^ info) { return dm->Log(Util::StringToWchar(info)); }
String^ DMCLR::DMSoft::FindStrE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	auto ret = dm->FindStrE(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim);
	return Util::BSTRToString(ret);
}
String^ DMCLR::DMSoft::FindColorE(long x1, long y1, long x2, long y2, String^ color, double sim, long dir)
{
	auto ret = dm->FindColorE(x1, y1, x2, y2, Util::StringToWchar(color), sim, dir);
	return Util::BSTRToString(ret);
}
String^ DMCLR::DMSoft::FindPicE(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir)
{
	auto ret = dm->FindPicE(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir);
	return Util::BSTRToString(ret);
}
String^ DMCLR::DMSoft::FindMultiColorE(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir)
{
	auto ret = dm->FindMultiColorE(x1, y1, x2, y2, Util::StringToWchar(first_color), Util::StringToWchar(offset_color), sim, dir);
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::SetExactOcr(long exact_ocr)
{
	return dm->SetExactOcr(exact_ocr);
}
String^ DMCLR::DMSoft::ReadString(long hwnd, String^ addr, long type, long len)
{
	auto ret = dm->ReadString(hwnd, Util::StringToWchar(addr), type, len);
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::FoobarTextPrintDir(long hwnd, long dir)
{
	return dm->FoobarTextPrintDir(hwnd, dir);
}
String^ DMCLR::DMSoft::OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim)
{
	auto ret = dm->OcrEx(x1, y1, x2, y2, Util::StringToWchar(color), sim);
	return Util::BSTRToString(ret);
}
long DMCLR::DMSoft::SetDisplayInput(String^ mode)
{
	return dm->SetDisplayInput(Util::StringToWchar(mode));
}
long DMCLR::DMSoft::GetTime()
{
	return dm->GetTime();
}
long DMCLR::DMSoft::GetScreenWidth() { return dm->GetScreenWidth(); }
long DMCLR::DMSoft::GetScreenHeight() { return dm->GetScreenHeight(); }
long DMCLR::DMSoft::BindWindowEx(long hwnd, String^ display, String^ mouse, String^ keypad, String^ public_desc, long mode)
{
	return dm->BindWindowEx(hwnd, Util::StringToWchar(display), Util::StringToWchar(mouse), Util::StringToWchar(keypad), Util::StringToWchar(public_desc), mode);
}
String^ DMCLR::DMSoft::GetDiskSerial(long index)
{
	auto ret = dm->GetDiskSerial(index);
	return Util::BSTRToString(ret);
}
String^ DMCLR::DMSoft::Md5(String^ str)
{
	return Util::BSTRToString(dm->Md5(Util::StringToWchar(str)));
}
String^ DMCLR::DMSoft::GetMac() { return Util::BSTRToString(dm->GetMac()); }
long DMCLR::DMSoft::ActiveInputMethod(long hwnd, String^ id) { return dm->ActiveInputMethod(hwnd, Util::StringToWchar(id)); }
long DMCLR::DMSoft::CheckInputMethod(long hwnd, String^ id) { return dm->CheckInputMethod(hwnd, Util::StringToWchar(id)); }
long DMCLR::DMSoft::FindInputMethod(String^ id) { return dm->FindInputMethod(Util::StringToWchar(id)); }
Tuple<long, long, int>^ DMCLR::DMSoft::GetCursorPos()
{
	VARIANT x, y;
	auto ret = dm->GetCursorPos(&x, &y);
	return gcnew Tuple<long, long, int>(x.intVal, y.intVal, ret);
}
long DMCLR::DMSoft::BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode)
{
	return dm->BindWindow(hwnd, Util::StringToWchar(display), Util::StringToWchar(mouse), Util::StringToWchar(keypad), mode);
}
long DMCLR::DMSoft::FindWindow(String^ class_name, String^ title_name)
{
	return dm->FindWindowW(Util::StringToWchar(class_name), Util::StringToWchar(title_name));
}
long DMCLR::DMSoft::GetScreenDepth() { return dm->GetScreenDepth(); }
long DMCLR::DMSoft::SetScreen(long width, long height, long depth) { return dm->SetScreen(width, height, depth); }
long DMCLR::DMSoft::ExitOs(long type) { return dm->ExitOs(type); }
String^ DMCLR::DMSoft::GetDir(long type) { return Util::BSTRToString(dm->GetDir(type)); }
long DMCLR::DMSoft::GetOsType() { return dm->GetOsType(); }
long DMCLR::DMSoft::FindWindowEx(long parent, String^ class_name, String^ title_name)
{
	return dm->FindWindowExW(parent, Util::StringToWchar(class_name), Util::StringToWchar(title_name));
}
long DMCLR::DMSoft::SetExportDict(long index, String^ dict_name) { return dm->SetExportDict(index, Util::StringToWchar(dict_name)); }
String^ DMCLR::DMSoft::GetCursorShape() { return Util::BSTRToString(dm->GetCursorShape()); }
long DMCLR::DMSoft::DownCpu(long type, long rate) { return dm->DownCpu(type, rate); }
String^ DMCLR::DMSoft::GetCursorSpot() { return Util::BSTRToString(dm->GetCursorSpot()); }
long DMCLR::DMSoft::SendString2(long hwnd, String^ str) { return dm->SendString2(hwnd, Util::StringToWchar(str)); }
long DMCLR::DMSoft::FaqPost(String^ server, long handle, long request_type, long time_out) { return dm->FaqPost(Util::StringToWchar(server), handle, request_type, time_out); }
String^ DMCLR::DMSoft::FaqFetch() { return Util::BSTRToString(dm->FaqFetch()); }
String^ DMCLR::DMSoft::FetchWord(long x1, long y1, long x2, long y2, String^ color, String^ word) { return Util::BSTRToString(dm->FetchWord(x1, y1, x2, y2, Util::StringToWchar(color), Util::StringToWchar(word))); }
long DMCLR::DMSoft::CaptureJpg(long x1, long y1, long x2, long y2, String^ file, long quality) { return dm->CaptureJpg(x1, y1, x2, y2, Util::StringToWchar(file), quality); }
Tuple<long, long, int>^ DMCLR::DMSoft::FindStrWithFont(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag)
{

	VARIANT x, y;
	auto ret = dm->FindStrWithFont(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim, Util::StringToWchar(font_name), font_size, flag, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindStrWithFontE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag) { return Util::BSTRToString(dm->FindStrWithFontE(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim, Util::StringToWchar(font_name), font_size, flag)); }
String^ DMCLR::DMSoft::FindStrWithFontEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag) { return Util::BSTRToString(dm->FindStrWithFontEx(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim, Util::StringToWchar(font_name), font_size, flag)); }
String^ DMCLR::DMSoft::GetDictInfo(String^ str, String^ font_name, long font_size, long flag) { return Util::BSTRToString(dm->GetDictInfo(Util::StringToWchar(str), Util::StringToWchar(font_name), font_size, flag)); }
long DMCLR::DMSoft::SaveDict(long index, String^ file)
{
	return dm->SaveDict(index, Util::StringToWchar(file));
}
long DMCLR::DMSoft::GetWindowProcessId(long hwnd) { return dm->GetWindowProcessId(hwnd); }
String^ DMCLR::DMSoft::GetWindowProcessPath(long hwnd) { return Util::BSTRToString(dm->GetWindowProcessPath(hwnd)); }
long DMCLR::DMSoft::LockInput(long lock) { return dm->LockInput(lock); }
String^ DMCLR::DMSoft::GetPicSize(String^ pic_name) { return Util::BSTRToString(dm->GetPicSize(Util::StringToWchar(pic_name))); }
long DMCLR::DMSoft::GetID() { return dm->GetID(); }
long DMCLR::DMSoft::CapturePng(long x1, long y1, long x2, long y2, String^ file) { return dm->CapturePng(x1, y1, x2, y2, Util::StringToWchar(file)); }
long DMCLR::DMSoft::CaptureGif(long x1, long y1, long x2, long y2, String^ file, long delay, long time) { return dm->CaptureGif(x1, y1, x2, y2, Util::StringToWchar(file), delay, time); }
long DMCLR::DMSoft::ImageToBmp(String^ pic_name, String^ bmp_name) { return dm->ImageToBmp(Util::StringToWchar(pic_name), Util::StringToWchar(bmp_name)); }
Tuple<long, long, int>^ DMCLR::DMSoft::FindStrFast(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{ 
	VARIANT x, y;
	auto ret = dm->FindStrFast(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindStrFastEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	return Util::BSTRToString(dm->FindStrFastEx(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim));
}
String^ DMCLR::DMSoft::FindStrFastE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	return Util::BSTRToString(dm->FindStrFastE(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim));
}
long DMCLR::DMSoft::EnableDisplayDebug(long enable_debug)
{
	return dm->EnableDisplayDebug(enable_debug);
}
long DMCLR::DMSoft::CapturePre(String^ file)
{
	return dm->CapturePre(Util::StringToWchar(file));
}
long DMCLR::DMSoft::RegEx(String^ code, String^ Ver, String^ ip)
{
	return dm->RegEx(Util::StringToWchar(code), Util::StringToWchar(Ver), Util::StringToWchar(ip));
}
String^ DMCLR::DMSoft::GetMachineCode()
{
	return Util::BSTRToString(dm->GetMachineCode());
}
long DMCLR::DMSoft::SetClipboard(String^ data)
{
	return dm->SetClipboard(Util::StringToWchar(data));
}
String^ DMCLR::DMSoft::GetClipboard()
{
	return Util::BSTRToString(dm->GetClipboard());
}
long DMCLR::DMSoft::GetNowDict()
{
	return dm->GetNowDict();
}
long DMCLR::DMSoft::Is64Bit()
{
	return dm->Is64Bit();
}
long DMCLR::DMSoft::GetColorNum(long x1, long y1, long x2, long y2, String^ color, double sim)
{
	return dm->GetColorNum(x1, y1, x2, y2, Util::StringToWchar(color), sim);
}
String^ DMCLR::DMSoft::EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter)
{
	return Util::BSTRToString(dm->EnumWindowByProcess(Util::StringToWchar(process_name), Util::StringToWchar(title), Util::StringToWchar(class_name), filter));
}
long DMCLR::DMSoft::GetDictCount(long index) { return dm->GetDictCount(index); }
long DMCLR::DMSoft::GetLastError()
{
	return dm->GetLastError();
}
String^ DMCLR::DMSoft::GetNetTime()
{
	return Util::BSTRToString(dm->GetNetTime());
}
long DMCLR::DMSoft::EnableGetColorByCapture(long en) { return dm->EnableGetColorByCapture(en); }
long DMCLR::DMSoft::CheckUAC()
{
	return dm->CheckUAC();
}
long DMCLR::DMSoft::SetUAC(long uac) { return dm->SetUAC(uac); }
long DMCLR::DMSoft::DisableFontSmooth()
{
	return dm->DisableFontSmooth();
}
long DMCLR::DMSoft::CheckFontSmooth()
{
	return dm->CheckFontSmooth();
}
long DMCLR::DMSoft::SetDisplayAcceler(long level) { return dm->SetDisplayAcceler(level); }
long DMCLR::DMSoft::FindWindowByProcess(String^ process_name, String^ class_name, String^ title_name)
{
	return dm->FindWindowByProcess(Util::StringToWchar(process_name), Util::StringToWchar(class_name), Util::StringToWchar(title_name));
}
long DMCLR::DMSoft::FindWindowByProcessId(long process_id, String^ class_name, String^ title_name)
{
	return dm->FindWindowByProcessId(process_id, Util::StringToWchar(class_name), Util::StringToWchar(title_name));
}
String^ DMCLR::DMSoft::ReadIni(String^ section, String^ key, String^ file)
{
	return Util::BSTRToString(dm->ReadIni(Util::StringToWchar(section), Util::StringToWchar(key), Util::StringToWchar(file)));
}
long DMCLR::DMSoft::WriteIni(String^ section, String^ key, String^ v, String^ file) { return dm->WriteIni(Util::StringToWchar(section), Util::StringToWchar(key), Util::StringToWchar(v), Util::StringToWchar(file)); }
long DMCLR::DMSoft::RunApp(String^ path, long mode) { return dm->RunApp(Util::StringToWchar(path), mode); }
long DMCLR::DMSoft::delay(long mis) { return dm->delay(mis); }
long DMCLR::DMSoft::FindWindowSuper(String^ spec1, long flag1, long type1, String^ spec2, long flag2, long type2)
{
	return dm->FindWindowSuper(Util::StringToWchar(spec1), flag1, type1, Util::StringToWchar(spec2), flag2, type2);
}
String^ DMCLR::DMSoft::ExcludePos(String^ all_pos, long type, long x1, long y1, long x2, long y2) { return Util::BSTRToString(dm->ExcludePos(Util::StringToWchar(all_pos), type, x1, y1, x2, y2)); }
String^ DMCLR::DMSoft::FindNearestPos(String^ all_pos, long type, long x, long y) { return Util::BSTRToString(dm->FindNearestPos(Util::StringToWchar(all_pos), type, x, y)); }
String^ DMCLR::DMSoft::SortPosDistance(String^ all_pos, long type, long x, long y) { return Util::BSTRToString(dm->SortPosDistance(Util::StringToWchar(all_pos), type, x, y)); }
Tuple<long, long, int>^ DMCLR::DMSoft::FindPicMem(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir)
{
	VARIANT x, y;
	auto ret = dm->FindPicMem(x1, y1, x2, y2, Util::StringToWchar(pic_info), Util::StringToWchar(delta_color), sim, dir, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindPicMemEx(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir)
{
	return Util::BSTRToString(dm->FindPicMemEx(x1, y1, x2, y2, Util::StringToWchar(pic_info), Util::StringToWchar(delta_color), sim, dir));
}

String^ DMCLR::DMSoft::FindPicMemE(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir)
{
	return Util::BSTRToString(dm->FindPicMemE(x1, y1, x2, y2, Util::StringToWchar(pic_info), Util::StringToWchar(delta_color), sim, dir));
}
String^ DMCLR::DMSoft::AppendPicAddr(String^ pic_info, long addr, long size) { return Util::BSTRToString(dm->AppendPicAddr(Util::StringToWchar(pic_info), addr, size)); }
long DMCLR::DMSoft::WriteFile(String^ file, String^ content) { return dm->WriteFile(Util::StringToWchar(file), Util::StringToWchar(content)); }
long DMCLR::DMSoft::Stop(long id) { return dm->Stop(id); }
long DMCLR::DMSoft::SetDictMem(long index, long addr, long size) { return dm->SetDictMem(index, addr, size); }
String^ DMCLR::DMSoft::GetNetTimeSafe() { return Util::BSTRToString(dm->GetNetTimeSafe()); }
long DMCLR::DMSoft::ForceUnBindWindow(long hwnd)
{
	return dm->ForceUnBindWindow(hwnd);
}
String^ DMCLR::DMSoft::ReadIniPwd(String^ section, String^ key, String^ file, String^ pwd) { return Util::BSTRToString(dm->ReadIniPwd(Util::StringToWchar(section), Util::StringToWchar(key), Util::StringToWchar(file), Util::StringToWchar(pwd))); }
long DMCLR::DMSoft::WriteIniPwd(String^ section, String^ key, String^ v, String^ file, String^ pwd) { return dm->WriteIniPwd(Util::StringToWchar(section), Util::StringToWchar(key), Util::StringToWchar(v), Util::StringToWchar(file), Util::StringToWchar(pwd)); }
long DMCLR::DMSoft::DecodeFile(String^ file, String^ pwd) { return dm->DecodeFile(Util::StringToWchar(file), Util::StringToWchar(pwd)); }
long DMCLR::DMSoft::KeyDownChar(String^ key_str)
{
	return dm->KeyDownChar(Util::StringToWchar(key_str));
}
long DMCLR::DMSoft::KeyUpChar(String^ key_str)
{
	return dm->KeyUpChar(Util::StringToWchar(key_str));
}
long DMCLR::DMSoft::KeyPressChar(String^ key_str)
{
	return dm->KeyPressChar(Util::StringToWchar(key_str));
}
long DMCLR::DMSoft::KeyPressStr(String^ key_str, long delay)
{
	return dm->KeyPressStr(Util::StringToWchar(key_str), delay);
}
long DMCLR::DMSoft::EnableKeypadPatch(long en) { return dm->EnableKeypadPatch(en); }
long DMCLR::DMSoft::EnableKeypadSync(long en, long time_out) { return dm->EnableKeypadSync(en, time_out); }
long DMCLR::DMSoft::EnableMouseSync(long en, long time_out) { return dm->EnableMouseSync(en, time_out); }
long DMCLR::DMSoft::DmGuard(long en, String^ type)
{
	return dm->DmGuard(en, Util::StringToWchar(type));
}
long DMCLR::DMSoft::FaqCaptureFromFile(long x1, long y1, long x2, long y2, String^ file, long quality)
{
	return dm->FaqCaptureFromFile(x1, y1, x2, y2, Util::StringToWchar(file), quality);
}
String^ DMCLR::DMSoft::FindIntEx(long hwnd, String^ addr_range, long int_value_min, long int_value_max, long type, long step, long multi_thread, long mode)
{
	return Util::BSTRToString(dm->FindIntEx(hwnd, Util::StringToWchar(addr_range), int_value_min, int_value_max, type, step, multi_thread, mode));
}
String^ DMCLR::DMSoft::FindFloatEx(long hwnd, String^ addr_range, float float_value_min, float float_value_max, long step, long multi_thread, long mode)
{
	return Util::BSTRToString(dm->FindFloatEx(hwnd, Util::StringToWchar(addr_range), float_value_min, float_value_max, step, multi_thread, mode));
}
String^ DMCLR::DMSoft::FindDoubleEx(long hwnd, String^ addr_range, double double_value_min, double double_value_max, long step, long multi_thread, long mode)
{
	return Util::BSTRToString(dm->FindDoubleEx(hwnd, Util::StringToWchar(addr_range), double_value_min, double_value_max, step, multi_thread, mode));
}
String^ DMCLR::DMSoft::FindStringEx(long hwnd, String^ addr_range, String^ string_value, long type, long step, long multi_thread, long mode)
{
	return Util::BSTRToString(dm->FindStringEx(hwnd, Util::StringToWchar(addr_range), Util::StringToWchar(string_value), type, step, multi_thread, mode));
}
String^ DMCLR::DMSoft::FindDataEx(long hwnd, String^ addr_range, String^ data, long step, long multi_thread, long mode)
{
	return Util::BSTRToString(dm->FindDataEx(hwnd, Util::StringToWchar(addr_range), Util::StringToWchar(data), step, multi_thread, mode));
}
long DMCLR::DMSoft::EnableRealMouse(long en, long mousedelay, long mousestep)
{
	return dm->EnableRealMouse(en, mousedelay, mousestep);
}
long DMCLR::DMSoft::EnableRealKeypad(long en) { return dm->EnableRealKeypad(en); }
long DMCLR::DMSoft::SendStringIme(String^ str) { return dm->SendStringIme(Util::StringToWchar(str)); }
long DMCLR::DMSoft::FoobarDrawLine(long hwnd, long x1, long y1, long x2, long y2, String^ color, long style, long width)
{
	return dm->FoobarDrawLine(hwnd, x1, y1, x2, y2, Util::StringToWchar(color), style, width);
}
String^ DMCLR::DMSoft::FindStrEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	return Util::BSTRToString(dm->FindStrEx(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim));
}
long DMCLR::DMSoft::IsBind(long hwnd)
{
	return dm->IsBind(hwnd);
}
long DMCLR::DMSoft::SetDisplayDelay(long t) { return dm->SetDisplayDelay(t); }
long DMCLR::DMSoft::GetDmCount()
{
	return dm->GetDmCount();
}
long DMCLR::DMSoft::DisableScreenSave() { return dm->DisableScreenSave(); }
long DMCLR::DMSoft::DisablePowerSave() { return dm->DisablePowerSave(); }
long DMCLR::DMSoft::SetMemoryHwndAsProcessId(long en) { return dm->SetMemoryHwndAsProcessId(en); }
Tuple<long, long, int>^ DMCLR::DMSoft::FindShape(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir)
{
	VARIANT x, y;
	auto ret = dm->FindShape(x1, y1, x2, y2, Util::StringToWchar(offset_color), sim, dir, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindShapeE(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir)
{
	return Util::BSTRToString(dm->FindShapeE(x1, y1, x2, y2, Util::StringToWchar(offset_color), sim, dir));
}
String^ DMCLR::DMSoft::FindShapeEx(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir)
{
	return Util::BSTRToString(dm->FindShapeEx(x1, y1, x2, y2, Util::StringToWchar(offset_color), sim, dir));
}

Tuple<long, long, String^>^ DMCLR::DMSoft::FindStrS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	VARIANT x, y;
	auto ret = Util::BSTRToString(dm->FindStrS(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim, &x, &y));
	return gcnew Tuple<long, long, String^>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindStrExS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	return Util::BSTRToString(dm->FindStrExS(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim));
}
Tuple<long, long, String^>^ DMCLR::DMSoft::FindStrFastS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	VARIANT x, y;
	auto ret = Util::BSTRToString(dm->FindStrFastS(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim, &x, &y));
	return gcnew Tuple<long, long, String^>(x.lVal, y.lVal, ret);
}

String^ DMCLR::DMSoft::FindStrFastExS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim)
{
	return Util::BSTRToString(dm->FindStrFastExS(x1, y1, x2, y2, Util::StringToWchar(str), Util::StringToWchar(color), sim));
}
Tuple<long, long, String^>^ DMCLR::DMSoft::FindPicS(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir)
{
	VARIANT x, y;
	auto ret = Util::BSTRToString(dm->FindPicS(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir, &x, &y));
	return gcnew Tuple<long, long, String^>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindPicExS(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir)
{
	return Util::BSTRToString(dm->FindPicExS(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir));
}
long DMCLR::DMSoft::ClearDict(long index)
{
	return dm->ClearDict(index);
}
String^ DMCLR::DMSoft::GetMachineCodeNoMac() { return Util::BSTRToString(dm->GetMachineCodeNoMac()); }
Tuple<long, long, long, long, int>^ DMCLR::DMSoft::GetClientRect(long hwnd)
{

	VARIANT x1, y1, x2, y2;
	auto ret = dm->GetClientRect(hwnd, &x1, &y1, &x2, &y2);
	return gcnew Tuple<long, long, long, long, int>(x1.lVal, y1.lVal, x2.lVal, y2.lVal, ret);
}
long DMCLR::DMSoft::EnableFakeActive(long en) { return dm->EnableFakeActive(en); }
long DMCLR::DMSoft::GetScreenDataBmp(long x1, long y1, long x2, long y2) 
{ 
	//return dm->GetScreenDataBmp(x1, y1, x2, y2); 
	return 0;
}
long DMCLR::DMSoft::EncodeFile(String^ file, String^ pwd) { return dm->EncodeFile(Util::StringToWchar(file), Util::StringToWchar(pwd)); }
String^ DMCLR::DMSoft::GetCursorShapeEx(long type) { return Util::BSTRToString(dm->GetCursorShapeEx(type)); }
long DMCLR::DMSoft::FaqCancel() { return dm->FaqCancel(); }
String^ DMCLR::DMSoft::IntToData(long int_value, long type) { return Util::BSTRToString(dm->IntToData(int_value, type)); }
String^ DMCLR::DMSoft::FloatToData(float float_value) { return Util::BSTRToString(dm->FloatToData(float_value)); }
String^ DMCLR::DMSoft::DoubleToData(double double_value) { return Util::BSTRToString(dm->DoubleToData(double_value)); }
String^ DMCLR::DMSoft::StringToData(String^ string_value, long type) { return Util::BSTRToString(dm->StringToData(Util::StringToWchar(string_value), type)); }
long DMCLR::DMSoft::SetMemoryFindResultToFile(String^ file) { return dm->SetMemoryFindResultToFile(Util::StringToWchar(file)); }
long DMCLR::DMSoft::EnableBind(long en) { return dm->EnableBind(en); }
long DMCLR::DMSoft::SetSimMode(long mode) { return dm->SetSimMode(mode); }
long DMCLR::DMSoft::LockMouseRect(long x1, long y1, long x2, long y2) { return dm->LockMouseRect(x1, y1, x2, y2); }
long DMCLR::DMSoft::SendPaste(long hwnd) { return dm->SendPaste(hwnd); }
long DMCLR::DMSoft::IsDisplayDead(long x1, long y1, long x2, long y2, long t) { return dm->IsDisplayDead(x1, y1, x2, y2, t); }
long DMCLR::DMSoft::GetKeyState(long vk) { return dm->GetKeyState(vk); }
long DMCLR::DMSoft::CopyFile(String^ src_file, String^ dst_file, long over) { return dm->CopyFile(Util::StringToWchar(src_file), Util::StringToWchar(dst_file), over); }
long DMCLR::DMSoft::IsFileExist(String^ file) { return dm->IsFileExist(Util::StringToWchar(file)); }
long DMCLR::DMSoft::DeleteFile(String^ file) { return dm->DeleteFile(Util::StringToWchar(file)); }
long DMCLR::DMSoft::MoveFile(String^ src_file, String^ dst_file) { return dm->MoveFile(Util::StringToWchar(src_file), Util::StringToWchar(dst_file)); }
long DMCLR::DMSoft::CreateFolder(String^ folder_name) { return dm->CreateFolder(Util::StringToWchar(folder_name)); }
long DMCLR::DMSoft::DeleteFolder(String^ folder_name) { return dm->DeleteFolder(Util::StringToWchar(folder_name)); }
long DMCLR::DMSoft::GetFileLength(String^ file) { return dm->GetFileLength(Util::StringToWchar(file)); }
String^ DMCLR::DMSoft::ReadFile(String^ file) { return Util::BSTRToString(dm->ReadFile(Util::StringToWchar(file))); }
long DMCLR::DMSoft::WaitKey(long key_code, long time_out)
{
	return dm->WaitKey(key_code, time_out);
}
long DMCLR::DMSoft::DeleteIni(String^ section, String^ key, String^ file) { return dm->DeleteIni(Util::StringToWchar(section), Util::StringToWchar(key), Util::StringToWchar(file)); }
long DMCLR::DMSoft::DeleteIniPwd(String^ section, String^ key, String^ file, String^ pwd) { return dm->DeleteIniPwd(Util::StringToWchar(section), Util::StringToWchar(key), Util::StringToWchar(file), Util::StringToWchar(pwd)); }
long DMCLR::DMSoft::EnableSpeedDx(long en) { return dm->EnableSpeedDx(en); }
long DMCLR::DMSoft::EnableIme(long en) { return dm->EnableIme(en); }

long DMCLR::DMSoft::Reg(String^ code, String^ Ver)
{
	return dm->Reg(Util::StringToWchar(code), Util::StringToWchar(Ver));
}
String^ DMCLR::DMSoft::SelectFile() { return Util::BSTRToString(dm->SelectFile()); }
String^ DMCLR::DMSoft::SelectDirectory() { return Util::BSTRToString(dm->SelectDirectory()); }
long DMCLR::DMSoft::LockDisplay(long lock) { return dm->LockDisplay(lock); }
long DMCLR::DMSoft::FoobarSetSave(long hwnd, String^ file, long en, String^ header) { return dm->FoobarSetSave(hwnd, Util::StringToWchar(file), en, Util::StringToWchar(header)); }
String^ DMCLR::DMSoft::EnumWindowSuper(String^ spec1, long flag1, long type1, String^ spec2, long flag2, long type2, long sort) { return Util::BSTRToString(dm->EnumWindowSuper(Util::StringToWchar(spec1), flag1, type1, Util::StringToWchar(spec2), flag2, type2, sort)); }
long DMCLR::DMSoft::DownloadFile(String^ url, String^ save_file, long timeout) { return dm->DownloadFile(Util::StringToWchar(url), Util::StringToWchar(save_file), timeout); }
long DMCLR::DMSoft::EnableKeypadMsg(long en) { return dm->EnableKeypadMsg(en); }
long DMCLR::DMSoft::EnableMouseMsg(long en) { return dm->EnableMouseMsg(en); }
long DMCLR::DMSoft::RegNoMac(String^ code, String^ Ver)
{
	return dm->RegNoMac(Util::StringToWchar(code), Util::StringToWchar(Ver));
}
long DMCLR::DMSoft::RegExNoMac(String^ code, String^ Ver, String^ ip)
{
	return dm->RegExNoMac(Util::StringToWchar(code), Util::StringToWchar(Ver), Util::StringToWchar(ip));
}
long DMCLR::DMSoft::SetEnumWindowDelay(long delay) { return dm->SetEnumWindowDelay(delay); }
long DMCLR::DMSoft::FindMulColor(long x1, long y1, long x2, long y2, String^ color, double sim) { return dm->FindMulColor(x1, y1, x2, y2, Util::StringToWchar(color), sim); }
String^ DMCLR::DMSoft::GetDict(long index, long font_index) { return Util::BSTRToString(dm->GetDict(index, font_index)); }
long DMCLR::DMSoft::GetBindWindow() { return dm->GetBindWindow(); }
long DMCLR::DMSoft::FoobarStartGif(long hwnd, long x, long y, String^ pic_name, long repeat_limit, long delay) { return dm->FoobarStartGif(hwnd, x, y, Util::StringToWchar(pic_name), repeat_limit, delay); }
long DMCLR::DMSoft::FoobarStopGif(long hwnd, long x, long y, String^ pic_name) { return dm->FoobarStopGif(hwnd, x, y, Util::StringToWchar(pic_name)); }
long DMCLR::DMSoft::FreeProcessMemory(long hwnd) { return dm->FreeProcessMemory(hwnd); }
String^ DMCLR::DMSoft::ReadFileData(String^ file, long start_pos, long end_pos) { return Util::BSTRToString(dm->ReadFileData(Util::StringToWchar(file), start_pos, end_pos)); }
long long DMCLR::DMSoft::VirtualAllocEx(long hwnd, long addr, long size, long type) { return dm->VirtualAllocEx(hwnd, addr, size, type); }
long DMCLR::DMSoft::VirtualFreeEx(long hwnd, long addr) { return dm->VirtualFreeEx(hwnd, addr); }
String^ DMCLR::DMSoft::GetCommandLine(long hwnd) { return Util::BSTRToString(dm->GetCommandLineW(hwnd)); }
long DMCLR::DMSoft::TerminateProcess(long pid) { return dm->TerminateProcess(pid); }
String^ DMCLR::DMSoft::GetNetTimeByIp(String^ ip) { return Util::BSTRToString(dm->GetNetTimeByIp(Util::StringToWchar(ip))); }
String^ DMCLR::DMSoft::EnumProcess(String^ name) { return Util::BSTRToString(dm->EnumProcess(Util::StringToWchar(name))); }
String^ DMCLR::DMSoft::GetProcessInfo(long pid) { return Util::BSTRToString(dm->GetProcessInfo(pid)); }
long long DMCLR::DMSoft::ReadIntAddr(long hwnd, long addr, long type) { return dm->ReadIntAddr(hwnd, addr, type); }
String^ DMCLR::DMSoft::ReadDataAddr(long hwnd, long addr, long len) { return Util::BSTRToString(dm->ReadDataAddr(hwnd, addr, len)); }
double DMCLR::DMSoft::ReadDoubleAddr(long hwnd, long addr) { return dm->ReadDoubleAddr(hwnd, addr); }
float DMCLR::DMSoft::ReadFloatAddr(long hwnd, long addr) { return dm->ReadFloatAddr(hwnd, addr); }
String^ DMCLR::DMSoft::ReadStringAddr(long hwnd, long addr, long type, long len) { return Util::BSTRToString(dm->ReadStringAddr(hwnd, addr, type, len)); }
long DMCLR::DMSoft::WriteDataAddr(long hwnd, long addr, String^ data) { return dm->WriteDataAddr(hwnd, addr, Util::StringToWchar(data)); }
long DMCLR::DMSoft::WriteDoubleAddr(long hwnd, long addr, double v) { return dm->WriteDoubleAddr(hwnd, addr, v); }
long DMCLR::DMSoft::WriteFloatAddr(long hwnd, long addr, float v) { return dm->WriteFloatAddr(hwnd, addr, v); }
long DMCLR::DMSoft::WriteIntAddr(long hwnd, long addr, long type, long v) { return dm->WriteIntAddr(hwnd, addr, type, v); }
long DMCLR::DMSoft::WriteStringAddr(long hwnd, long addr, long type, String^ v) { return dm->WriteStringAddr(hwnd, addr, type, Util::StringToWchar(v)); }
long DMCLR::DMSoft::Delays(long min_s, long max_s) { return dm->Delays(min_s, max_s); }
Tuple<long, long, int>^ DMCLR::DMSoft::FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long width, long height)
{
	VARIANT x, y;
	auto ret = dm->FindColorBlock(x1, y1, x2, y2, Util::StringToWchar(color), sim, count, width, height, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long width, long height) { return Util::BSTRToString(dm->FindColorBlockEx(x1, y1, x2, y2, Util::StringToWchar(color), sim, count, width, height)); }
long DMCLR::DMSoft::OpenProcess(long pid) { return dm->OpenProcess(pid); }
String^ DMCLR::DMSoft::EnumIniSection(String^ file) { return Util::BSTRToString(dm->EnumIniSection(Util::StringToWchar(file))); }
String^ DMCLR::DMSoft::EnumIniSectionPwd(String^ file, String^ pwd) { return Util::BSTRToString(dm->EnumIniSectionPwd(Util::StringToWchar(file), Util::StringToWchar(pwd))); }
String^ DMCLR::DMSoft::EnumIniKey(String^ section, String^ file) { return Util::BSTRToString(dm->EnumIniKey(Util::StringToWchar(section), Util::StringToWchar(file))); }
String^ DMCLR::DMSoft::EnumIniKeyPwd(String^ section, String^ file, String^ pwd) { return Util::BSTRToString(dm->EnumIniKeyPwd(Util::StringToWchar(section), Util::StringToWchar(file), Util::StringToWchar(pwd))); }
long DMCLR::DMSoft::SwitchBindWindow(long hwnd) { return dm->SwitchBindWindow(hwnd); }
long DMCLR::DMSoft::InitCri() { return dm->InitCri(); }
long DMCLR::DMSoft::SendStringIme2(long hwnd, String^ str, long mode) { return dm->SendStringIme2(hwnd, Util::StringToWchar(str), mode); }
String^ DMCLR::DMSoft::EnumWindowByProcessId(long pid, String^ title, String^ class_name, long filter) { return Util::BSTRToString(dm->EnumWindowByProcessId(pid, Util::StringToWchar(title), Util::StringToWchar(class_name), filter)); }
String^ DMCLR::DMSoft::GetDisplayInfo() { return Util::BSTRToString(dm->GetDisplayInfo()); }
long DMCLR::DMSoft::EnableFontSmooth() { return dm->EnableFontSmooth(); }
String^ DMCLR::DMSoft::OcrExOne(long x1, long y1, long x2, long y2, String^ color, double sim) { return Util::BSTRToString(dm->OcrExOne(x1, y1, x2, y2, Util::StringToWchar(color), sim)); }
long DMCLR::DMSoft::SetAero(long en)
{
	return dm->SetAero(en);
}
long DMCLR::DMSoft::FoobarSetTrans(long hwnd, long trans, String^ color, double sim)
{
	return dm->FoobarSetTrans(hwnd, trans, Util::StringToWchar(color), sim);
}
long DMCLR::DMSoft::EnablePicCache(long en)
{
	return dm->EnablePicCache(en);
}
long DMCLR::DMSoft::FaqIsPosted() { return dm->FaqIsPosted(); }
long DMCLR::DMSoft::LoadPicByte(long addr, long size, String^ name)
{
	return dm->LoadPicByte(addr, size, Util::StringToWchar(name));
}
long DMCLR::DMSoft::MiddleDown()
{
	return dm->MiddleDown();
}
long DMCLR::DMSoft::MiddleUp()
{
	return dm->MiddleUp();
}
long DMCLR::DMSoft::FaqCaptureString(String^ str) { return dm->FaqCaptureString(Util::StringToWchar(str)); }
long DMCLR::DMSoft::VirtualProtectEx(long hwnd, long addr, long size, long type, long old_protect) { return dm->VirtualProtectEx(hwnd, addr, size, type, old_protect); }
long DMCLR::DMSoft::SetMouseSpeed(long speed)
{
	return dm->SetMouseSpeed(speed);
}
long DMCLR::DMSoft::GetMouseSpeed()
{
	return dm->GetMouseSpeed();
}
long DMCLR::DMSoft::EnableMouseAccuracy(long en) { return dm->EnableMouseAccuracy(en); }
long DMCLR::DMSoft::SetExcludeRegion(long type, String^ info) { return dm->SetExcludeRegion(type, Util::StringToWchar(info)); }
long DMCLR::DMSoft::EnableShareDict(long en) { return dm->EnableShareDict(en); }
long DMCLR::DMSoft::DisableCloseDisplayAndSleep() { return dm->DisableCloseDisplayAndSleep(); }
long DMCLR::DMSoft::Int64ToInt32(long v) { return dm->Int64ToInt32(v); }
long DMCLR::DMSoft::GetLocale() { return dm->GetLocale(); }
long DMCLR::DMSoft::SetLocale() { return dm->SetLocale(); }
long DMCLR::DMSoft::ReadDataToBin(long hwnd, String^ addr, long len) { return dm->ReadDataToBin(hwnd, Util::StringToWchar(addr), len); }
long DMCLR::DMSoft::WriteDataFromBin(long hwnd, String^ addr, long data, long len) { return dm->WriteDataFromBin(hwnd, Util::StringToWchar(addr), data, len); }
long DMCLR::DMSoft::ReadDataAddrToBin(long hwnd, long addr, long len) { return dm->ReadDataAddrToBin(hwnd, addr, len); }
long DMCLR::DMSoft::WriteDataAddrFromBin(long hwnd, long addr, long data, long len) { return dm->WriteDataAddrFromBin(hwnd, addr, data, len); }
long DMCLR::DMSoft::SetParam64ToPointer() { return dm->SetParam64ToPointer(); }
long DMCLR::DMSoft::GetDPI() { return dm->GetDPI(); }
long DMCLR::DMSoft::SetDisplayRefreshDelay(long t) { return dm->SetDisplayRefreshDelay(t); }
long DMCLR::DMSoft::IsFolderExist(String^ folder) { return dm->IsFolderExist(Util::StringToWchar(folder)); }
long DMCLR::DMSoft::GetCpuType() { return dm->GetCpuType(); }
long DMCLR::DMSoft::ReleaseRef() { return dm->ReleaseRef(); }
long DMCLR::DMSoft::SetExitThread(long en) { return dm->SetExitThread(en); }
long DMCLR::DMSoft::GetFps() { return dm->GetFps(); }
String^ DMCLR::DMSoft::VirtualQueryEx(long hwnd, long addr, long pmbi) { return Util::BSTRToString(dm->VirtualQueryEx(hwnd, addr, pmbi)); }
long long DMCLR::DMSoft::AsmCallEx(long hwnd, long mode, String^ base_addr) { return dm->AsmCallEx(hwnd, mode, Util::StringToWchar(base_addr)); }
long long DMCLR::DMSoft::GetRemoteApiAddress(long hwnd, long base_addr, String^ fun_name) { return dm->GetRemoteApiAddress(hwnd, base_addr, Util::StringToWchar(fun_name)); }
String^ DMCLR::DMSoft::ExecuteCmd(String^ cmd, String^ current_dir, long time_out) { return Util::BSTRToString(dm->ExecuteCmd(Util::StringToWchar(cmd), Util::StringToWchar(current_dir), time_out)); }
long DMCLR::DMSoft::SpeedNormalGraphic(long en) { return dm->SpeedNormalGraphic(en); }
long DMCLR::DMSoft::UnLoadDriver() { return dm->UnLoadDriver(); }
long DMCLR::DMSoft::GetOsBuildNumber() { return dm->GetOsBuildNumber(); }
long DMCLR::DMSoft::HackSpeed(double rate) { return dm->HackSpeed(rate); }
String^ DMCLR::DMSoft::GetRealPath(String^ path) { return Util::BSTRToString(dm->GetRealPath(Util::StringToWchar(path))); }
long DMCLR::DMSoft::ShowTaskBarIcon(long hwnd, long is_show) { return dm->ShowTaskBarIcon(hwnd, is_show); }
long DMCLR::DMSoft::AsmSetTimeout(long time_out, long param) { return dm->AsmSetTimeout(time_out, param); }
String^ DMCLR::DMSoft::DmGuardParams(String^ cmd, String^ sub_cmd, String^ param) { return Util::BSTRToString(dm->DmGuardParams(Util::StringToWchar(cmd), Util::StringToWchar(sub_cmd), Util::StringToWchar(param))); }
long DMCLR::DMSoft::GetModuleSize(long hwnd, String^ module_name) { return dm->GetModuleSize(hwnd, Util::StringToWchar(module_name)); }
long DMCLR::DMSoft::IsSurrpotVt() { return dm->IsSurrpotVt(); }
String^ DMCLR::DMSoft::GetDiskModel(long index) { return Util::BSTRToString(dm->GetDiskModel(index)); }
String^ DMCLR::DMSoft::GetDiskReversion(long index) { return Util::BSTRToString(dm->GetDiskReversion(index)); }
long DMCLR::DMSoft::EnableFindPicMultithread(long en)
{
	return dm->EnableFindPicMultithread(en);
}
long DMCLR::DMSoft::GetCpuUsage()
{
	return dm->GetCpuUsage();
}
long DMCLR::DMSoft::GetMemoryUsage()
{
	return dm->GetMemoryUsage();
}
String^ DMCLR::DMSoft::Hex32(long v)
{
	return Util::BSTRToString(dm->Hex32(v));
}
String^ DMCLR::DMSoft::Hex64(long v)
{
	return Util::BSTRToString(dm->Hex64(v));
}
long DMCLR::DMSoft::GetWindowThreadId(long hwnd)
{
	return dm->GetWindowThreadId(hwnd);
}
long DMCLR::DMSoft::DmGuardExtract(String^ type, String^ path)
{
	return dm->DmGuardExtract(Util::StringToWchar(type), Util::StringToWchar(path));
}
long DMCLR::DMSoft::DmGuardLoadCustom(String^ type, String^ path)
{
	return dm->DmGuardLoadCustom(Util::StringToWchar(type), Util::StringToWchar(path));
}
long DMCLR::DMSoft::SetShowAsmErrorMsg(long show)
{
	return dm->SetShowAsmErrorMsg(show);
}
String^ DMCLR::DMSoft::GetSystemInfo(String^ type, long method)
{
	return Util::BSTRToString(dm->GetSystemInfo(Util::StringToWchar(type), method));
}
long DMCLR::DMSoft::SetFindPicMultithreadCount(long count)
{
	return dm->SetFindPicMultithreadCount(count);
}
Tuple<long, long, int>^ DMCLR::DMSoft::FindPicSim(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir)
{
	VARIANT x, y;
	int ret = dm->FindPicSim(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindPicSimEx(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir)
{
	return Util::BSTRToString(dm->FindPicSimEx(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir));
}
Tuple<long, long, int>^ DMCLR::DMSoft::FindPicSimMem(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir)
{
	VARIANT x, y;
	int ret = dm->FindPicSimMem(x1, y1, x2, y2, Util::StringToWchar(pic_info), Util::StringToWchar(delta_color), sim, dir, &x, &y);
	return gcnew Tuple<long, long, int>(x.lVal, y.lVal, ret);
}
String^ DMCLR::DMSoft::FindPicSimMemEx(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir)
{
	return Util::BSTRToString(dm->FindPicSimMemEx(x1, y1, x2, y2, Util::StringToWchar(pic_info), Util::StringToWchar(delta_color), sim, dir));
}
String^ DMCLR::DMSoft::FindPicSimE(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir)
{
	return Util::BSTRToString(dm->FindPicSimE(x1, y1, x2, y2, Util::StringToWchar(pic_name), Util::StringToWchar(delta_color), sim, dir));
}
String^ DMCLR::DMSoft::FindPicSimMemE(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir)
{
	return Util::BSTRToString(dm->FindPicSimMemE(x1, y1, x2, y2, Util::StringToWchar(pic_info), Util::StringToWchar(delta_color), sim, dir));
}
long DMCLR::DMSoft::SetInputDm(long input_dm, long rx, long ry)
{
	return dm->SetInputDm(input_dm, rx, ry);
}
long DMCLR::DMSoft::SetFindPicMultithreadLimit(long limit)
{
	return dm->SetFindPicMultithreadLimit(limit);
}


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
