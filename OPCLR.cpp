#include "pch.h"
#include "OPCLR.h"

#ifdef _M_X64
#pragma comment(lib,"./Library/x64/op/op.lib")
#pragma comment(lib,"./Library/x64/op/BlackBone.lib")
#else
#pragma comment(lib,"./Library/x32/op/op.lib")
#pragma comment(lib,"./Library/x32/op/BlackBone.lib")
#endif

namespace OPCLR {

	static libop op;

	String^ OPSoft::Ver()
	{
		auto a = op.Ver();
		return gcnew String(a.c_str());
	}

	int OPSoft::SetPath(String^ path)
	{
		auto str = Util::StringToWchar(path);

		long ret;
		op.SetPath(str, &ret);
		return ret;
	}

	String^ OPSoft::GetPath()
	{
		wstring str;
		op.GetPath(str);
		return Util::WStringToString(str);
	}

	String^ OPSoft::GetBasePath()
	{
		wstring str;
		op.GetBasePath(str);
		return Util::WStringToString(str);
	}

	int OPSoft::GetID()
	{
		long ret;
		op.GetID(&ret);
		return ret;
	}

	int OPSoft::GetLastError()
	{
		long ret;
		op.GetLastError(&ret);
		return ret;
	}

	//设置是否弹出错误信息,默认是打开 0:关闭，1:显示为信息框，2:保存到文件,3:输出到标准输出
	int OPSoft::SetShowErrorMsg(long show_type)
	{
		long ret;
		op.SetShowErrorMsg(show_type, &ret);
		return ret;
	}

	//sleep
	int OPSoft::Sleep(long millseconds)
	{
		long ret;
		op.Sleep(millseconds, &ret);
		return ret;
	}
	//Process
	//inject dll
	int OPSoft::InjectDll(String^ process_name, String^ dll_name) {
		long ret;
		op.InjectDll(Util::StringToWchar(process_name), Util::StringToWchar(dll_name), &ret);
		return ret;
	}
	//设置是否开启或者关闭插件内部的图片缓存机制
	int OPSoft::EnablePicCache(long enable) {
		long ret;
		op.EnablePicCache(enable, &ret);
		return ret;
	}
	//取上次操作的图色区域，保存为file(24位位图)
	int OPSoft::CapturePre(String^ file_name) {
		long ret;
		op.CapturePre(Util::StringToWchar(file_name), &ret);
		return ret;
	}

	//---------------------algorithm-------------------------------
	//A星算法
	String^ OPSoft::AStarFindPath(long mapWidth, long mapHeight, String^ disable_points, long beginX, long beginY, long endX, long endY) {
		wstring ret;
		op.AStarFindPath(mapWidth, mapHeight, Util::StringToWchar(disable_points), beginX, beginY, endX, endY, ret);
		return Util::WStringToString(ret);
	}

	String^ OPSoft::FindNearestPos(String^ all_pos, long type, long x, long y) {
		wstring ret;
		op.FindNearestPos(Util::StringToWchar(all_pos), type, x, y, ret);
		return Util::WStringToString(ret);
	}

	//--------------------windows api------------------------------
	//根据指定条件,枚举系统中符合条件的窗口
	String^ OPSoft::EnumWindow(long parent, String^ title, String^ class_name, long filter) {
		wstring ret;
		op.EnumWindow(parent, Util::StringToWchar(title), Util::StringToWchar(class_name), filter, ret);
		return Util::WStringToString(ret);
	}
	//根据指定进程以及其它条件,枚举系统中符合条件的窗口
	String^ OPSoft::EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter) {
		wstring ret;
		op.EnumWindowByProcess(Util::StringToWchar(process_name), Util::StringToWchar(title), Util::StringToWchar(class_name), filter, ret);
		return Util::WStringToString(ret);
	}

	//根据指定进程名,枚举系统中符合条件的进程PID
	String^ OPSoft::EnumProcess(String^ name) {
		wstring ret;
		op.EnumProcess(Util::StringToWchar(name), ret);
		return Util::WStringToString(ret);
	}
	//把窗口坐标转换为屏幕坐标
	System::Tuple<long, long, int>^ OPSoft::ClientToScreen(long ClientToScreen) {
		long ret;
		long x;
		long y;
		op.ClientToScreen(ClientToScreen, &x, &y, &ret);
		return gcnew System::Tuple<long, long, int>(x, y, ret);
	}
	//查找符合类名或者标题名的顶层可见窗口
	int OPSoft::FindWindow(String^ class_name, String^ title)
	{
		long ret;
		op.FindWindow(Util::StringToWchar(class_name), Util::StringToWchar(title), &ret);
		return ret;
	}
	//根据指定的进程名字，来查找可见窗口
	int OPSoft::FindWindowByProcess(String^ process_name, String^ class_name, String^ title) {
		long ret;
		op.FindWindowByProcess(Util::StringToWchar(process_name), Util::StringToWchar(class_name), Util::StringToWchar(title), &ret);
		return ret;
	}

	//根据指定的进程Id，来查找可见窗口
	int OPSoft::FindWindowByProcessId(long process_id, String^ class_name, String^ title) {
		long ret;
		op.FindWindowByProcessId(process_id, Util::StringToWchar(class_name), Util::StringToWchar(title), &ret);
		return ret;
	}
	//查找符合类名或者标题名的顶层可见窗口,如果指定了parent,则在parent的第一层子窗口中查找
	int OPSoft::FindWindowEx(long parent, String^ class_name, String^ title)
	{
		long ret;
		op.FindWindowEx(parent, Util::StringToWchar(class_name), Util::StringToWchar(title), &ret);
		return ret;
	}
	//获取窗口客户区域在屏幕上的位置
	System::Tuple<long, long, long, long, int>^ OPSoft::GetClientRect(long hwnd) {
		long ret;
		long x1;
		long y1;
		long x2;
		long y2;
		op.GetClientRect(hwnd, &x1, &y1, &x2, &y2, &ret);
		return gcnew System::Tuple<long, long, long, long, int>(x1, y1, x2, y2, ret);
	}
	//获取窗口客户区域的宽度和高度
	System::Tuple<long, long, int>^ OPSoft::GetClientSize(long hwnd) {
		long ret;
		long w;
		long h;
		op.GetClientSize(hwnd, &w, &h, &ret);
		return gcnew System::Tuple<long, long, int>(w, h, ret);
	}
	//获取顶层活动窗口中具有输入焦点的窗口句柄
	int OPSoft::GetForegroundFocus() {
		long ret;
		op.GetForegroundFocus(&ret);
		return ret;
	}
	//获取顶层活动窗口,可以获取到按键自带插件无法获取到的句柄
	int OPSoft::GetForegroundWindow() {
		long ret;
		op.GetForegroundWindow(&ret);
		return ret;
	}
	//获取鼠标指向的可见窗口句柄
	int OPSoft::GetMousePointWindow() {
		long ret;
		op.GetMousePointWindow(&ret);
		return ret;
	}
	//获取给定坐标的可见窗口句柄
	int OPSoft::GetPointWindow(long x, long y) {
		long ret;
		op.GetPointWindow(x, y, &ret);
		return ret;
	}
	//根据指定的pid获取进程详细信息
	String^ OPSoft::GetProcessInfo(long pid) {
		wstring ret;
		op.GetProcessInfo(pid, ret);
		return Util::WStringToString(ret);
	}
	//获取特殊窗口
	int OPSoft::GetSpecialWindow(long flag) {
		long ret;
		op.GetSpecialWindow(flag, &ret);
		return ret;
	}
	//获取给定窗口相关的窗口句柄
	int OPSoft::GetWindow(long hwnd, long flag) {
		long ret;
		op.GetWindow(hwnd, flag, &ret);
		return ret;
	}
	//获取窗口的类名
	String^ OPSoft::GetWindowClass(long hwnd) {
		wstring ret;
		op.GetWindowClass(hwnd, ret);
		return Util::WStringToString(ret);
	}
	//获取指定窗口所在的进程ID
	int OPSoft::GetWindowProcessId(long hwnd) {
		long ret;
		op.GetWindowProcessId(hwnd, &ret);
		return ret;
	}
	//获取指定窗口所在的进程的exe文件全路径
	String^ OPSoft::GetWindowProcessPath(long hwnd) {
		wstring ret;
		op.GetWindowProcessPath(hwnd, ret);
		return Util::WStringToString(ret);
	}
	//获取窗口在屏幕上的位置
	System::Tuple<long, long, long, long, int>^ OPSoft::GetWindowRect(long hwnd) {
		long ret;
		long x1;
		long y1;
		long x2;
		long y2;
		op.GetWindowRect(hwnd, &x1, &y1, &x2, &y2, &ret);
		return gcnew System::Tuple<long, long, long, long, int>(x1, y1, x2, y2, ret);
	}
	//获取指定窗口的一些属性
	int OPSoft::GetWindowState(long hwnd, long flag) {
		long ret;
		op.GetWindowState(hwnd, flag, &ret);
		return ret;
	}
	//获取窗口的标题
	String^ OPSoft::GetWindowTitle(long hwnd) {
		wstring ret;
		op.GetWindowTitle(hwnd, ret);
		return Util::WStringToString(ret);
	}
	//移动指定窗口到指定位置
	int OPSoft::MoveWindow(long hwnd, long x, long y) {
		long ret;
		op.MoveWindow(hwnd, x, y, &ret);
		return ret;
	}
	//把屏幕坐标转换为窗口坐标
	System::Tuple<long, long, int>^ OPSoft::ScreenToClient(long hwnd) {

		long ret;
		long x;
		long y;
		op.ScreenToClient(hwnd, &x, &y, &ret);
		return gcnew System::Tuple<long, long, int>(x, y, ret);
	}

	//向指定窗口发送粘贴命令
	int OPSoft::SendPaste(long hwnd) {
		long ret;
		op.SendPaste(hwnd, &ret);
		return ret;
	}
	//设置窗口客户区域的宽度和高度
	int OPSoft::SetClientSize(long hwnd, long width, long hight) {
		long ret;
		op.SetClientSize(hwnd, width, hight, &ret);
		return ret;
	}
	//设置窗口的状态
	int OPSoft::SetWindowState(long hwnd, long flag) {
		long ret;
		op.SetWindowState(hwnd, flag, &ret);
		return ret;
	}
	//设置窗口的大小
	int OPSoft::SetWindowSize(long hwnd, long width, long height) {
		long ret;
		op.SetWindowSize(hwnd, width, height, &ret);
		return ret;
	}
	//设置窗口的标题
	int OPSoft::SetWindowText(long hwnd, String^ title) {
		long ret;
		op.SetWindowText(hwnd, Util::StringToWchar(title), &ret);
		return ret;
	}
	//设置窗口的透明度
	int OPSoft::SetWindowTransparent(long hwnd, long trans) {
		long ret;
		op.SetWindowTransparent(hwnd, trans, &ret);
		return ret;
	}
	//向指定窗口发送文本数据
	int OPSoft::SendString(long hwnd, String^ str) {
		long ret;
		op.SendString(hwnd, Util::StringToWchar(str), &ret);
		return ret;
	}
	//向指定窗口发送文本数据-输入法
	int OPSoft::SendStringIme(long hwnd, String^ str) {
		long ret;
		op.SendStringIme(hwnd, Util::StringToWchar(str), &ret);
		return ret;
	}
	//运行可执行文件,可指定模式
	int OPSoft::RunApp(String^ cmdline, long mode) {
		long ret;
		op.RunApp(Util::StringToWchar(cmdline), mode, &ret);
		return ret;
	}
	//运行可执行文件，可指定显示模式
	int OPSoft::WinExec(String^ cmdline, long cmdshow) {
		long ret;
		op.WinExec(Util::StringToWchar(cmdline), cmdshow, &ret);
		return ret;
	}

	//运行命令行并返回结果
	String^ OPSoft::GetCmdStr(String^ cmd, long millseconds) {
		wstring ret;
		op.GetCmdStr(Util::StringToWchar(cmd), millseconds, ret);
		return Util::WStringToString(ret);
	}

	//--------------------Background -----------------------
	//bind window and beign capture screen
	int OPSoft::BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode)
	{
		long ret;
		op.BindWindow(hwnd, Util::StringToWchar(display), Util::StringToWchar(mouse), Util::StringToWchar(keypad), mode, &ret);
		return ret;
	}
	//
	int OPSoft::UnBindWindow()
	{
		long ret;
		op.UnBindWindow(&ret);
		return ret;
	}
	//--------------------mouse & keyboard------------------
	//获取鼠标位置.
	String^ OPSoft::GetCursorPos() {
		long x;
		long y;
		long ret;
		op.GetCursorPos(&x, &y, &ret);
		auto str = std::to_string(x) + "-" + std::to_string(y);

		return Util::ToNetString(str);
	}

	//鼠标相对于上次的位置移动rx,ry.
	int OPSoft::MoveR(long x, long y) {
		long ret;
		op.MoveR(x, y, &ret);
		return ret;
	}
	//把鼠标移动到目的点(x,y)
	int OPSoft::MoveTo(long x, long y)
	{
		long ret;
		op.MoveTo(x, y, &ret);
		return ret;
	};
	//把鼠标移动到目的范围内的任意一点
	int OPSoft::MoveToEx(long x, long y, long w, long h)
	{

		long ret;
		op.MoveToEx(x, y, w, h, &ret);
		return ret;
	}

	//按下鼠标左键
	int OPSoft::LeftClick()
	{
		long ret;
		op.LeftClick(&ret);
		return ret;
	}

	//双击鼠标左键
	int OPSoft::LeftDoubleClick()
	{
		long ret;
		op.LeftDoubleClick(&ret);
		return ret;
	}
	//按住鼠标左键
	int OPSoft::LeftDown()
	{
		long ret;
		op.LeftDown(&ret);
		return ret;
	}
	//弹起鼠标左键
	int OPSoft::LeftUp()
	{
		long ret;
		op.LeftUp(&ret);
		return ret;
	}
	//按下鼠标中键
	int OPSoft::MiddleClick()
	{
		long ret;
		op.MiddleClick(&ret);
		return ret;
	}
	//按住鼠标中键
	int OPSoft::MiddleDown()
	{
		long ret;
		op.MiddleDown(&ret);
		return ret;
	}
	//弹起鼠标中键
	int OPSoft::MiddleUp()
	{
		long ret;
		op.MiddleUp(&ret);
		return ret;
	}
	//按下鼠标右键
	int OPSoft::RightClick()
	{
		long ret;
		op.RightClick(&ret);
		return ret;
	}
	//按住鼠标右键
	int OPSoft::RightDown()
	{
		long ret;
		op.RightDown(&ret);
		return ret;
	}
	//弹起鼠标右键
	int OPSoft::RightUp()
	{
		long ret;
		op.RightUp(&ret);
		return ret;
	}
	//滚轮向下滚
	int OPSoft::WheelDown()
	{
		long ret;
		op.WheelDown(&ret);
		return ret;
	}
	//滚轮向上滚
	int OPSoft::WheelUp()
	{
		long ret;
		op.WheelUp(&ret);
		return ret;
	}
	//获取指定的按键状态.(前台信息,不是后台)
	int OPSoft::GetKeyState(long vk_code)
	{
		long ret;
		op.GetKeyState(vk_code, &ret);
		return ret;
	}
	//按住指定的虚拟键码
	int OPSoft::KeyDown(long vk_code)
	{
		long ret;
		op.KeyDown(vk_code, &ret);
		return ret;
	}
	//按住指定的虚拟键码
	int OPSoft::KeyDownChar(String^ vk_code)
	{
		long ret;
		op.KeyDownChar(Util::StringToWchar(vk_code), &ret);
		return ret;
	}
	//弹起来虚拟键vk_code
	int OPSoft::KeyUp(long vk_code)
	{
		long ret;
		op.KeyUp(vk_code, &ret);
		return ret;
	}
	//弹起来虚拟键vk_code
	int OPSoft::KeyUpChar(String^ vk_code)
	{
		long ret;
		op.KeyUpChar(Util::StringToWchar(vk_code), &ret);
		return ret;
	}
	//等待指定的按键按下 (前台,不是后台)
	int OPSoft::WaitKey(long vk_code, long time_out)
	{
		long ret;
		op.WaitKey(vk_code, time_out, &ret);
		return ret;
	}
	//发送字符串
	//long SendString(long HWND)
	//弹起来虚拟键vk_code
	int OPSoft::KeyPress(long vk_code)
	{
		long ret;
		op.KeyPress(vk_code, &ret);
		return ret;
	}
	int OPSoft::KeyPressChar(String^ vk_code)
	{
		long ret;
		op.KeyPressChar(Util::StringToWchar(vk_code), &ret);
		return ret;
	}

	//--------------------image and color-----------------------
	//抓取指定区域(x1, y1, x2, y2)的图像, 保存为file
	int OPSoft::Capture(long x1, long y1, long x2, long y2, String^ file_name) {
		long ret;
		op.Capture(x1, y1, x2, y2, Util::StringToWchar(file_name), &ret);
		return ret;
	}

	//比较指定坐标点(x,y)的颜色
	int OPSoft::CmpColor(long x, long y, String^ color, double sim) {
		long ret;
		op.CmpColor(x, y, Util::StringToWchar(color), sim, &ret);
		return ret;
	}

	//查找指定区域内的颜色
	Tuple<long, long, int>^ OPSoft::FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) {
		long ret;
		long x;
		long y;
		op.FindColor(x1, y1, x2, y2, Util::StringToWchar(color), sim, dir, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);

	}
	//查找指定区域内的所有颜色
	String^ OPSoft::FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) {
		wstring ret;
		op.FindColorEx(x1, y1, x2, y2, Util::StringToWchar(color), sim, dir, ret);
		return Util::WStringToString(ret);
	}
	//根据指定的多点查找颜色坐标
	Tuple<long, long, int>^ OPSoft::FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) {
		long ret;
		long x;
		long y;
		op.FindMultiColor(x1, y1, x2, y2, Util::StringToWchar(first_color), Util::StringToWchar(offset_color), sim, dir, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}
	//根据指定的多点查找所有颜色坐标
	String^ OPSoft::FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) {
		wstring ret;
		op.FindMultiColorEx(x1, y1, x2, y2, Util::StringToWchar(first_color), Util::StringToWchar(offset_color), sim, dir, ret);
		return Util::WStringToString(ret);
	}
	//查找指定区域内的图片
	Tuple<long, long, int>^ OPSoft::FindPic(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) {
		long ret;
		long x;
		long y;
		op.FindPic(x1, y1, x2, y2, Util::StringToWchar(files), Util::StringToWchar(delta_color), sim, dir, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}
	//查找多个图片
	String^ OPSoft::FindPicEx(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) {
		wstring ret;
		op.FindPicEx(x1, y1, x2, y2, Util::StringToWchar(files), Util::StringToWchar(delta_color), sim, dir, ret);
		return Util::WStringToString(ret);
	}
	//
	//这个函数可以查找多个图片, 并且返回所有找到的图像的坐标.此函数同FindPicEx.只是返回值不同.(file1,x,y|file2,x,y|...)
	String^ OPSoft::FindPicExS(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) {
		wstring ret;
		op.FindPicExS(x1, y1, x2, y2, Util::StringToWchar(files), Util::StringToWchar(delta_color), sim, dir, ret);
		return Util::WStringToString(ret);
	}
	//查找指定区域内的颜色块,颜色格式"RRGGBB-DRDGDB",注意,和按键的颜色格式相反
	Tuple<long, long, int>^ OPSoft::FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width) {
		long ret;
		long x;
		long y;
		op.FindColorBlock(x1, y1, x2, y2, Util::StringToWchar(color), sim, count, height, width, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}

	//查找指定区域内的所有颜色块, 颜色格式"RRGGBB-DRDGDB", 注意, 和按键的颜色格式相反
	String^ OPSoft::FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width) {
		wstring ret;
		op.FindColorBlockEx(x1, y1, x2, y2, Util::StringToWchar(color), sim, count, height, width, ret);
		return Util::WStringToString(ret);
	}

	//获取(x,y)的颜色
	String^ OPSoft::GetColor(long x, long y) {
		wstring ret;
		op.GetColor(x, y, ret);
		return Util::WStringToString(ret);
	}
	//
	//设置图像输入方式，默认窗口截图
	int OPSoft::SetDisplayInput(String^ mode) {
		long ret;
		op.SetDisplayInput(Util::StringToWchar(mode), &ret);
		return ret;
	}

	int OPSoft::LoadPic(String^ file_name)
	{
		long ret;
		op.LoadPic(Util::StringToWchar(file_name), &ret);
		return ret;
	}

	int OPSoft::FreePic(String^ file_name) {
		long ret;
		op.FreePic(Util::StringToWchar(file_name), &ret);
		return ret;
	}


	Tuple<long, long>^ OPSoft::GetScreenFrameInfo()
	{
		long frame_id;
		long time;
		op.GetScreenFrameInfo(&frame_id, &time);
		return gcnew Tuple<long, long>(frame_id, time);
	}

	//
	String^ OPSoft::MatchPicName(String^ pic_name) {
		wstring ret;
		op.MatchPicName(Util::StringToWchar(pic_name), ret);
		return Util::WStringToString(ret);
	}
	//----------------------ocr-------------------------
	//设置字库文件
	int OPSoft::SetDict(long idx, String^ file_name)
	{
		long ret;
		op.SetDict(idx, Util::StringToWchar(file_name), &ret);
		return ret;
	}
	//设置内存字库文件
	int OPSoft::SetMemDict(long idx, String^ data, long size) {
		long ret;
		op.SetMemDict(idx, Util::StringToWchar(data), size, &ret);
		return ret;
	}
	//使用哪个字库文件进行识别
	int OPSoft::UseDict(long idx) {
		long ret;
		op.UseDict(idx, &ret);
		return ret;
	}
	//识别屏幕范围(x1,y1,x2,y2)内符合color_format的字符串,并且相似度为sim,sim取值范围(0.1-1.0),
	String^ OPSoft::Ocr(long x1, long y1, long x2, long y2, String^ color, double sim) {
		wstring ret;
		op.Ocr(x1, y1, x2, y2, Util::StringToWchar(color), sim, ret);
		return Util::WStringToString(ret);
	}

	//回识别到的字符串，以及每个字符的坐标.
	String^ OPSoft::OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim) {
		wstring ret;
		op.OcrEx(x1, y1, x2, y2, Util::StringToWchar(color), sim, ret);
		return Util::WStringToString(ret);
	}
	//在屏幕范围(x1,y1,x2,y2)内,查找string(可以是任意个字符串的组合),并返回符合color_format的坐标位置
	Tuple<long, long, int>^ OPSoft::FindStr(long x1, long y1, long x2, long y2, String^ strs, String^ color, double simxy) {
		long ret;
		long x;
		long y;
		op.FindStr(x1, y1, x2, y2, Util::StringToWchar(strs), Util::StringToWchar(color), simxy, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}
	//返回符合color_format的所有坐标位置
	String^ OPSoft::FindStrEx(long x1, long y1, long x2, long y2, String^ strs, String^ color, double sim) {

		wstring ret;
		op.FindStrEx(x1, y1, x2, y2, Util::StringToWchar(strs), Util::StringToWchar(color), sim, ret);
		return Util::WStringToString(ret);
	}
	//识别屏幕范围(x1,y1,x2,y2)内的字符串,自动二值化，而无需指定颜色
	String^ OPSoft::OcrAuto(long x1, long y1, long x2, long y2, double sim) {
		wstring ret;
		op.OcrAuto(x1, y1, x2, y2, sim, ret);
		return Util::WStringToString(ret);
	}
	//从文件中识别图片
	String^ OPSoft::OcrFromFile(String^ file_name, String^ color_format, double sim) {
		wstring ret;
		op.OcrFromFile(Util::StringToWchar(file_name), Util::StringToWchar(color_format), sim, ret);
		return Util::WStringToString(ret);
	}
	//从文件中识别图片,无需指定颜色
	String^ OPSoft::OcrAutoFromFile(String^ file_name, double sim) {
		wstring ret;
		op.OcrAutoFromFile(Util::StringToWchar(file_name), sim, ret);
		return Util::WStringToString(ret);
	}

	//查找频幕中的直线
	String^ OPSoft::FindLine(long x1, long y1, long x2, long y2, String^ color, double sim) {
		wstring ret;
		op.FindLine(x1, y1, x2, y2, Util::StringToWchar(color), sim, ret);
		return Util::WStringToString(ret);
	}

	//向某进程写入数据
	int OPSoft::WriteData(long hwnd, String^ address, String^ data, long size) {
		long ret;
		op.WriteData(hwnd, Util::StringToWchar(address), Util::StringToWchar(data), size, &ret);
		return ret;
	}

	//读取数据
	String^ OPSoft::ReadData(long hwnd, String^ address, long size) {
		wstring ret;
		op.ReadData(hwnd, Util::StringToWchar(address), size, ret);
		return Util::WStringToString(ret);
	}

	OPSoft::~OPSoft()
	{

	}
}
