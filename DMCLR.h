#pragma once
#include ".\Library\x32\dm\dm.tlh"
#include "Util.h"
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
		int SetPath(String^ path);
		String^ Ocr(long x1, long y1, long x2, long y2, String^ color, double sim);
		Tuple<long, long, int>^ FindStr(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		int GetResultCount(String^ str);
		Tuple<long, long, int>^ GetResultPos(String^ str, long index);
		int StrStr(String^ s, String^ str);
		int SendCommand(String^ cmd);
		long UseDict(long index);
		String^ GetBasePath();
		long SetDictPwd(String^ pwd);
		String^ OcrInFile(long x1, long y1, long x2, long y2, String^ pic_name, String^ color, double sim);
		long Capture(long x1, long y1, long x2, long y2, String^ file);
		long KeyPress(long vk);
		long KeyDown(long vk);
		long KeyUp(long vk);
		long LeftClick();
		long RightClick();
		long MiddleClick();
		long LeftDoubleClick();
		long LeftDown();
		long LeftUp();
		long RightDown();
		long RightUp();
		long MoveTo(long x, long y);
		long MoveR(long rx, long ry);
		String^ GetColor(long x, long y);
		String^ GetColorBGR(long x, long y);
		String^ RGB2BGR(String^ rgb_color);
		String^ BGR2RGB(String^ bgr_color);
		long UnBindWindow();
		long CmpColor(long x, long y, String^ color, double sim);
		long ClientToScreen(long hwnd);
		long ScreenToClient(long hwnd);
		long ShowScrMsg(long x1, long y1, long x2, long y2, String^ msg, String^ color);
		long SetMinRowGap(long row_gap);
		long SetMinColGap(long col_gap);
		long FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir);
		String^ FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir);
		long SetWordLineHeight(long line_height);
		long SetWordGap(long word_gap);
		long SetRowGapNoDict(long row_gap);
		long SetColGapNoDict(long col_gap);
		long SetWordLineHeightNoDict(long line_height);
		long SetWordGapNoDict(long word_gap);
		long GetWordResultCount(String^ str);
		long GetWordResultPos(String^ str, long index);
		String^ GetWordResultStr(String^ str, long index);
		String^ GetWords(long x1, long y1, long x2, long y2, String^ color, double sim);
		String^ GetWordsNoDict(long x1, long y1, long x2, long y2, String^ color);
		long SetShowErrorMsg(long show);
		long GetClientSize(long hwnd);
		long MoveWindow(long hwnd, long x, long y);
		String^ GetColorHSV(long x, long y);
		String^ GetAveRGB(long x1, long y1, long x2, long y2);
		String^ GetAveHSV(long x1, long y1, long x2, long y2);
		long GetForegroundWindow();
		long GetForegroundFocus();
		long GetMousePointWindow();
		long GetPointWindow(long x, long y);
		String^ EnumWindow(long parent, String^ title, String^ class_name, long filter);
		long GetWindowState(long hwnd, long flag);
		long GetWindow(long hwnd, long flag);
		long GetSpecialWindow(long flag);
		long SetWindowText(long hwnd, String^ text);
		long SetWindowSize(long hwnd, long width, long height);
		long GetWindowRect(long hwnd);
		String^ GetWindowTitle(long hwnd);
		String^ GetWindowClass(long hwnd);
		long SetWindowState(long hwnd, long flag);
		long CreateFoobarRect(long hwnd, long x, long y, long w, long h);
		long CreateFoobarRoundRect(long hwnd, long x, long y, long w, long h, long rw, long rh);
		long CreateFoobarEllipse(long hwnd, long x, long y, long w, long h);
		long CreateFoobarCustom(long hwnd, long x, long y, String^ pic, String^ trans_color, double sim);
		long FoobarFillRect(long hwnd, long x1, long y1, long x2, long y2, String^ color);
		long FoobarDrawText(long hwnd, long x, long y, long w, long h, String^ text, String^ color, long align);
		long FoobarDrawPic(long hwnd, long x, long y, String^ pic, String^ trans_color);
		long FoobarUpdate(long hwnd);
		long FoobarLock(long hwnd);
		long FoobarUnlock(long hwnd);
		long FoobarSetFont(long hwnd, String^ font_name, long size, long flag);
		long FoobarTextRect(long hwnd, long x, long y, long w, long h);
		long FoobarPrintText(long hwnd, String^ text, String^ color);
		long FoobarClearText(long hwnd);
		long FoobarTextLineGap(long hwnd, long gap);
		long Play(String^ file);
		long FaqCapture(long x1, long y1, long x2, long y2, long quality, long delay, long time);
		long FaqRelease(long handle);
		String^ FaqSend(String^ server, long handle, long request_type, long time_out);
		long Beep(long fre, long delay);
		long FoobarClose(long hwnd);
		long MoveDD(long dx, long dy);
		long FaqGetSize(long handle);
		long LoadPic(String^ pic_name);
		long FreePic(String^ pic_name);
		long GetScreenData(long x1, long y1, long x2, long y2);
		long FreeScreenData(long handle);
		long WheelUp();
		long WheelDown();
		long SetMouseDelay(String^ type, long delay);
		long SetKeypadDelay(String^ type, long delay);
		String^ GetEnv(long index, String^ name);
		long SetEnv(long index, String^ name, String^ value);
		long SendString(long hwnd, String^ str);
		long DelEnv(long index, String^ name);
		String^ GetPath();
		long SetDict(long index, String^ dict_name);
		long FindPic(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir);
		String^ FindPicEx(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir);
		long SetClientSize(long hwnd, long width, long height);
		long ReadInt(long hwnd, String^ addr, long type);
		float ReadFloat(long hwnd, String^ addr);
		double ReadDouble(long hwnd, String^ addr);
		String^ FindInt(long hwnd, String^ addr_range, long int_value_min, long int_value_max, long type);
		String^ FindFloat(long hwnd, String^ addr_range, float float_value_min, float float_value_max);
		String^ FindDouble(long hwnd, String^ addr_range, double double_value_min, double double_value_max);
		String^ FindString(long hwnd, String^ addr_range, String^ string_value, long type);
		long GetModuleBaseAddr(long hwnd, String^ module_name);
		String^ MoveToEx(long x, long y, long w, long h);
		String^ MatchPicName(String^ pic_name);
		long AddDict(long index, String^ dict_info);
		long EnterCri();
		long LeaveCri();
		long WriteInt(long hwnd, String^ addr, long type, long v);
		long WriteFloat(long hwnd, String^ addr, float v);
		long WriteDouble(long hwnd, String^ addr, double v);
		long WriteString(long hwnd, String^ addr, long type, String^ v);
		long AsmAdd(String^ asm_ins);
		long AsmClear();
		long AsmCall(long hwnd, long mode);
		long FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir);
		String^ FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir);
		String^ Assemble(long base_addr, long is_64bit);
		String^ DisAssemble(String^ asm_code, long base_addr, long is_64bit);
		long SetWindowTransparent(long hwnd, long v);
		String^ ReadData(long hwnd, String^ addr, long len);
		long WriteData(long hwnd, String^ addr, String^ data);
		String^ FindData(long hwnd, String^ addr_range, String^ data);
		long SetPicPwd(String^ pwd);
		long Log(String^ info);
		String^ FindStrE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		String^ FindColorE(long x1, long y1, long x2, long y2, String^ color, double sim, long dir);
		String^ FindPicE(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir);
		String^ FindMultiColorE(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir);
		long SetExactOcr(long exact_ocr);
		String^ ReadString(long hwnd, String^ addr, long type, long len);
		long FoobarTextPrintDir(long hwnd, long dir);
		String^ OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim);
		long SetDisplayInput(String^ mode);
		long GetTime();
		long GetScreenWidth();
		long GetScreenHeight();
		long BindWindowEx(long hwnd, String^ display, String^ mouse, String^ keypad, String^ public_desc, long mode);
		String^ GetDiskSerial(long index);
		String^ Md5(String^ str);
		String^ GetMac();
		long ActiveInputMethod(long hwnd, String^ id);
		long CheckInputMethod(long hwnd, String^ id);
		long FindInputMethod(String^ id);
		long GetCursorPos();
		long BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode);
		long FindWindow(String^ class_name, String^ title_name);
		long GetScreenDepth();
		long SetScreen(long width, long height, long depth);
		long ExitOs(long type);
		String^ GetDir(long type);
		long GetOsType();
		long FindWindowEx(long parent, String^ class_name, String^ title_name);
		long SetExportDict(long index, String^ dict_name);
		String^ GetCursorShape();
		long DownCpu(long type, long rate);
		String^ GetCursorSpot();
		long SendString2(long hwnd, String^ str);
		long FaqPost(String^ server, long handle, long request_type, long time_out);
		String^ FaqFetch();
		String^ FetchWord(long x1, long y1, long x2, long y2, String^ color, String^ word);
		long CaptureJpg(long x1, long y1, long x2, long y2, String^ file, long quality);
		long FindStrWithFont(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag);
		String^ FindStrWithFontE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag);
		String^ FindStrWithFontEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim, String^ font_name, long font_size, long flag);
		String^ GetDictInfo(String^ str, String^ font_name, long font_size, long flag);
		long SaveDict(long index, String^ file);
		long GetWindowProcessId(long hwnd);
		String^ GetWindowProcessPath(long hwnd);
		long LockInput(long lock);
		String^ GetPicSize(String^ pic_name);
		long GetID();
		long CapturePng(long x1, long y1, long x2, long y2, String^ file);
		long CaptureGif(long x1, long y1, long x2, long y2, String^ file, long delay, long time);
		long ImageToBmp(String^ pic_name, String^ bmp_name);
		long FindStrFast(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		String^ FindStrFastEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		String^ FindStrFastE(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		long EnableDisplayDebug(long enable_debug);
		long CapturePre(String^ file);
		long RegEx(String^ code, String^ Ver, String^ ip);
		String^ GetMachineCode();
		long SetClipboard(String^ data);
		String^ GetClipboard();
		long GetNowDict();
		long Is64Bit();
		long GetColorNum(long x1, long y1, long x2, long y2, String^ color, double sim);
		String^ EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter);
		long GetDictCount(long index);
		long GetLastError();
		String^ GetNetTime();
		long EnableGetColorByCapture(long en);
		long CheckUAC();
		long SetUAC(long uac);
		long DisableFontSmooth();
		long CheckFontSmooth();
		long SetDisplayAcceler(long level);
		long FindWindowByProcess(String^ process_name, String^ class_name, String^ title_name);
		long FindWindowByProcessId(long process_id, String^ class_name, String^ title_name);
		String^ ReadIni(String^ section, String^ key, String^ file);
		long WriteIni(String^ section, String^ key, String^ v, String^ file);
		long RunApp(String^ path, long mode);
		long delay(long mis);
		long FindWindowSuper(String^ spec1, long flag1, long type1, String^ spec2, long flag2, long type2);
		String^ ExcludePos(String^ all_pos, long type, long x1, long y1, long x2, long y2);
		String^ FindNearestPos(String^ all_pos, long type, long x, long y);
		String^ SortPosDistance(String^ all_pos, long type, long x, long y);
		long FindPicMem(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir);
		String^ FindPicMemEx(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir);
		String^ FindPicMemE(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, double sim, long dir);
		String^ AppendPicAddr(String^ pic_info, long addr, long size);
		long WriteFile(String^ file, String^ content);
		long Stop(long id);
		long SetDictMem(long index, long addr, long size);
		String^ GetNetTimeSafe();
		long ForceUnBindWindow(long hwnd);
		String^ ReadIniPwd(String^ section, String^ key, String^ file, String^ pwd);
		long WriteIniPwd(String^ section, String^ key, String^ v, String^ file, String^ pwd);
		long DecodeFile(String^ file, String^ pwd);
		long KeyDownChar(String^ key_str);
		long KeyUpChar(String^ key_str);
		long KeyPressChar(String^ key_str);
		long KeyPressStr(String^ key_str, long delay);
		long EnableKeypadPatch(long en);
		long EnableKeypadSync(long en, long time_out);
		long EnableMouseSync(long en, long time_out);
		long DmGuard(long en, String^ type);
		long FaqCaptureFromFile(long x1, long y1, long x2, long y2, String^ file, long quality);
		String^ FindIntEx(long hwnd, String^ addr_range, long int_value_min, long int_value_max, long type, long step, long multi_thread, long mode);
		String^ FindFloatEx(long hwnd, String^ addr_range, float float_value_min, float float_value_max, long step, long multi_thread, long mode);
		String^ FindDoubleEx(long hwnd, String^ addr_range, double double_value_min, double double_value_max, long step, long multi_thread, long mode);
		String^ FindStringEx(long hwnd, String^ addr_range, String^ string_value, long type, long step, long multi_thread, long mode);
		String^ FindDataEx(long hwnd, String^ addr_range, String^ data, long step, long multi_thread, long mode);
		long EnableRealMouse(long en, long mousedelay, long mousestep);
		long EnableRealKeypad(long en);
		long SendStringIme(String^ str);
		long FoobarDrawLine(long hwnd, long x1, long y1, long x2, long y2, String^ color, long style, long width);
		String^ FindStrEx(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		long IsBind(long hwnd);
		long SetDisplayDelay(long t);
		long GetDmCount();
		long DisableScreenSave();
		long DisablePowerSave();
		long SetMemoryHwndAsProcessId(long en);
		long FindShape(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir);
		String^ FindShapeE(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir);
		String^ FindShapeEx(long x1, long y1, long x2, long y2, String^ offset_color, double sim, long dir);
		String^ FindStrS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		String^ FindStrExS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		String^ FindStrFastS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		String^ FindStrFastExS(long x1, long y1, long x2, long y2, String^ str, String^ color, double sim);
		String^ FindPicS(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir);
		String^ FindPicExS(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, double sim, long dir);
		long ClearDict(long index);
		String^ GetMachineCodeNoMac();
		long GetClientRect(long hwnd);
		long EnableFakeActive(long en);
		long GetScreenDataBmp(long x1, long y1, long x2, long y2);
		long EncodeFile(String^ file, String^ pwd);
		String^ GetCursorShapeEx(long type);
		long FaqCancel();
		String^ IntToData(long int_value, long type);
		String^ FloatToData(float float_value);
		String^ DoubleToData(double double_value);
		String^ StringToData(String^ string_value, long type);
		long SetMemoryFindResultToFile(String^ file);
		long EnableBind(long en);
		long SetSimMode(long mode);
		long LockMouseRect(long x1, long y1, long x2, long y2);
		long SendPaste(long hwnd);
		long IsDisplayDead(long x1, long y1, long x2, long y2, long t);
		long GetKeyState(long vk);
		long CopyFile(String^ src_file, String^ dst_file, long over);
		long IsFileExist(String^ file);
		long DeleteFile(String^ file);
		long MoveFile(String^ src_file, String^ dst_file);
		long CreateFolder(String^ folder_name);
		long DeleteFolder(String^ folder_name);
		long GetFileLength(String^ file);
		String^ ReadFile(String^ file);
		long WaitKey(long key_code, long time_out);
		long DeleteIni(String^ section, String^ key, String^ file);
		long DeleteIniPwd(String^ section, String^ key, String^ file, String^ pwd);
		long EnableSpeedDx(long en);
		long EnableIme(long en);
		long Reg(String^ code, String^ Ver);
		String^ SelectFile();
		String^ SelectDirectory();
		long LockDisplay(long lock);
		long FoobarSetSave(long hwnd, String^ file, long en, String^ header);
		String^ EnumWindowSuper(String^ spec1, long flag1, long type1, String^ spec2, long flag2, long type2, long sort);
		long DownloadFile(String^ url, String^ save_file, long timeout);
		long EnableKeypadMsg(long en);
		long EnableMouseMsg(long en);
		long RegNoMac(String^ code, String^ Ver);
		long RegExNoMac(String^ code, String^ Ver, String^ ip);
		long SetEnumWindowDelay(long delay);
		long FindMulColor(long x1, long y1, long x2, long y2, String^ color, double sim);
		String^ GetDict(long index, long font_index);
		long GetBindWindow();
		long FoobarStartGif(long hwnd, long x, long y, String^ pic_name, long repeat_limit, long delay);
		long FoobarStopGif(long hwnd, long x, long y, String^ pic_name);
		long FreeProcessMemory(long hwnd);
		String^ ReadFileData(String^ file, long start_pos, long end_pos);
		long VirtualAllocEx(long hwnd, long addr, long size, long type);
		long VirtualFreeEx(long hwnd, long addr);
		String^ GetCommandLine(long hwnd);
		long TerminateProcess(long pid);
		String^ GetNetTimeByIp(String^ ip);
		String^ EnumProcess(String^ name);
		String^ GetProcessInfo(long pid);
		long ReadIntAddr(long hwnd, long addr, long type);
		String^ ReadDataAddr(long hwnd, long addr, long len);
		double ReadDoubleAddr(long hwnd, long addr);
		float ReadFloatAddr(long hwnd, long addr);
		String^ ReadStringAddr(long hwnd, long addr, long type, long len);
		long WriteDataAddr(long hwnd, long addr, String^ data);
		long WriteDoubleAddr(long hwnd, long addr, double v);
		long WriteFloatAddr(long hwnd, long addr, float v);
		long WriteIntAddr(long hwnd, long addr, long type, long v);
		long WriteStringAddr(long hwnd, long addr, long type, String^ v);
		long Delays(long min_s, long max_s);
		long FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long width, long height);
		String^ FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long width, long height);
		long OpenProcess(long pid);
		String^ EnumIniSection(String^ file);
		String^ EnumIniSectionPwd(String^ file, String^ pwd);
		String^ EnumIniKey(String^ section, String^ file);
		String^ EnumIniKeyPwd(String^ section, String^ file, String^ pwd);
		long SwitchBindWindow(long hwnd);
		long InitCri();
		long SendStringIme2(long hwnd, String^ str, long mode);
		String^ EnumWindowByProcessId(long pid, String^ title, String^ class_name, long filter);
		String^ GetDisplayInfo();
		long EnableFontSmooth();
		String^ OcrExOne(long x1, long y1, long x2, long y2, String^ color, double sim);
		long SetAero(long en);
		long FoobarSetTrans(long hwnd, long trans, String^ color, double sim);
		long EnablePicCache(long en);
		long FaqIsPosted();
		long LoadPicByte(long addr, long size, String^ name);
		long MiddleDown();
		long MiddleUp();
		long FaqCaptureString(String^ str);
		long VirtualProtectEx(long hwnd, long addr, long size, long type, long old_protect);
		long SetMouseSpeed(long speed);
		long GetMouseSpeed();
		long EnableMouseAccuracy(long en);
		long SetExcludeRegion(long type, String^ info);
		long EnableShareDict(long en);
		long DisableCloseDisplayAndSleep();
		long Int64ToInt32(long v);
		long GetLocale();
		long SetLocale();
		long ReadDataToBin(long hwnd, String^ addr, long len);
		long WriteDataFromBin(long hwnd, String^ addr, long data, long len);
		long ReadDataAddrToBin(long hwnd, long addr, long len);
		long WriteDataAddrFromBin(long hwnd, long addr, long data, long len);
		long SetParam64ToPointer();
		long GetDPI();
		long SetDisplayRefreshDelay(long t);
		long IsFolderExist(String^ folder);
		long GetCpuType();
		long ReleaseRef();
		long SetExitThread(long en);
		long GetFps();
		String^ VirtualQueryEx(long hwnd, long addr, long pmbi);
		long AsmCallEx(long hwnd, long mode, String^ base_addr);
		long GetRemoteApiAddress(long hwnd, long base_addr, String^ fun_name);
		String^ ExecuteCmd(String^ cmd, String^ current_dir, long time_out);
		long SpeedNormalGraphic(long en);
		long UnLoadDriver();
		long GetOsBuildNumber();
		long HackSpeed(double rate);
		String^ GetRealPath(String^ path);
		long ShowTaskBarIcon(long hwnd, long is_show);
		long AsmSetTimeout(long time_out, long param);
		String^ DmGuardParams(String^ cmd, String^ sub_cmd, String^ param);
		long GetModuleSize(long hwnd, String^ module_name);
		long IsSurrpotVt();
		String^ GetDiskModel(long index);
		String^ GetDiskReversion(long index);
		long EnableFindPicMultithread(long en);
		long GetCpuUsage();
		long GetMemoryUsage();
		String^ Hex32(long v);
		String^ Hex64(long v);
		long GetWindowThreadId(long hwnd);
		long DmGuardExtract(String^ type, String^ path);
		long DmGuardLoadCustom(String^ type, String^ path);
		long SetShowAsmErrorMsg(long show);
		String^ GetSystemInfo(String^ type, long method);
		long SetFindPicMultithreadCount(long count);
		long FindPicSim(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir);
		String^ FindPicSimEx(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir);
		long FindPicSimMem(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir);
		String^ FindPicSimMemEx(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir);
		String^ FindPicSimE(long x1, long y1, long x2, long y2, String^ pic_name, String^ delta_color, long sim, long dir);
		String^ FindPicSimMemE(long x1, long y1, long x2, long y2, String^ pic_info, String^ delta_color, long sim, long dir);
		long SetInputDm(long input_dm, long rx, long ry);
		long SetFindPicMultithreadLimit(long limit);
		DMSoft();
		~DMSoft();
	};
}
