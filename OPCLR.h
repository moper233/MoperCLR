#pragma once
#include <string>
#include<vector>

#include ".\Library\Include\libop.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

#undef FindWindow
#undef FindWindowEx
#undef SetWindowText
using namespace std;
using namespace System;
using namespace msclr::interop;
using namespace System::Runtime::InteropServices;

namespace OPCLR {
	public ref class OPSoft
	{

	public:
		String^ Ver();
		int SetPath(String^ path);
		String^ GetPath();
		String^ GetBasePath();
		int GetID();
		//获取最后一次错误
		int GetLastError();

		//设置是否弹出错误信息,默认是打开 0:关闭，1:显示为信息框，2:保存到文件,3:输出到标准输出
		int SetShowErrorMsg(long show_type);

		//sleep
		int Sleep(long millseconds);
		//Process
		//inject dll
		int InjectDll(String^ process_name, String^ dll_name);
		//设置是否开启或者关闭插件内部的图片缓存机制
		int EnablePicCache(long enable);
		//取上次操作的图色区域，保存为file(24位位图)
		int CapturePre(String^ file_name);
		//---------------------algorithm-------------------------------
		//A星算法
		String^ AStarFindPath(long mapWidth, long mapHeight, String^ disable_points, long beginX, long beginY, long endX, long endY);
		//
		String^ FindNearestPos(String^ all_pos, long type, long x, long y);
		//--------------------windows api------------------------------
		//根据指定条件,枚举系统中符合条件的窗口
		String^ EnumWindow(long parent, String^ title, String^ class_name, long filter);
		//根据指定进程以及其它条件,枚举系统中符合条件的窗口
		String^ EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter);
		//根据指定进程名,枚举系统中符合条件的进程PID
		String^ EnumProcess(String^ name);
		//把窗口坐标转换为屏幕坐标
		System::Tuple<long, long, int>^ ClientToScreen(long ClientToScreen);
		//查找符合类名或者标题名的顶层可见窗口
		int FindWindow(String^ class_name, String^ title);
		//根据指定的进程名字，来查找可见窗口
		int FindWindowByProcess(String^ process_name, String^ class_name, String^ title);
		//根据指定的进程Id，来查找可见窗口
		int FindWindowByProcessId(long process_id, String^ class_name, String^ title);
		//查找符合类名或者标题名的顶层可见窗口,如果指定了parent,则在parent的第一层子窗口中查找
		int FindWindowEx(long parent, String^ class_name, String^ title);
		//获取窗口客户区域在屏幕上的位置
		System::Tuple<long, long, long, long, int>^ GetClientRect(long hwnd);
		//获取窗口客户区域的宽度和高度
		System::Tuple<long, long, int>^ GetClientSize(long hwnd);
		//获取顶层活动窗口中具有输入焦点的窗口句柄
		int GetForegroundFocus();
		//获取顶层活动窗口,可以获取到按键自带插件无法获取到的句柄
		int GetForegroundWindow();
		//获取鼠标指向的可见窗口句柄
		int GetMousePointWindow();
		//获取给定坐标的可见窗口句柄
		int GetPointWindow(long x, long y);
		//根据指定的pid获取进程详细信息
		String^ GetProcessInfo(long pid);
		//获取特殊窗口
		int GetSpecialWindow(long flag);
		//获取给定窗口相关的窗口句柄
		int GetWindow(long hwnd, long flag);
		//获取窗口的类名
		String^ GetWindowClass(long hwnd);
		//获取指定窗口所在的进程ID
		int GetWindowProcessId(long hwnd);
		//获取指定窗口所在的进程的exe文件全路径
		String^ GetWindowProcessPath(long hwnd);
		//获取窗口在屏幕上的位置
		System::Tuple<long, long, long, long, int>^ GetWindowRect(long hwnd);
		//获取指定窗口的一些属性
		int GetWindowState(long hwnd, long flag);
		//获取窗口的标题
		String^ GetWindowTitle(long hwnd);
		//移动指定窗口到指定位置
		int MoveWindow(long hwnd, long x, long y);
		//把屏幕坐标转换为窗口坐标
		System::Tuple<long, long, int>^ ScreenToClient(long hwnd);
		//向指定窗口发送粘贴命令
		int SendPaste(long hwnd);
		//设置窗口客户区域的宽度和高度
		int SetClientSize(long hwnd, long width, long hight);
		//设置窗口的状态
		int SetWindowState(long hwnd, long flag);
		//设置窗口的大小
		int SetWindowSize(long hwnd, long width, long height);
		//设置窗口的标题
		int SetWindowText(long hwnd, String^ title);
		//设置窗口的透明度
		int SetWindowTransparent(long hwnd, long trans);
		//向指定窗口发送文本数据
		int SendString(long hwnd, String^ str);
		//向指定窗口发送文本数据-输入法
		int SendStringIme(long hwnd, String^ str);
		//运行可执行文件,可指定模式
		int RunApp(String^ cmdline, long mode);
		//运行可执行文件，可指定显示模式
		int WinExec(String^ cmdline, long cmdshow);

		//运行命令行并返回结果
		String^ GetCmdStr(String^ cmd, long millseconds);

		//--------------------Background -----------------------
		//bind window and beign capture screen
		int BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode);
		//
		int UnBindWindow();
		//--------------------mouse & keyboard------------------
		//获取鼠标位置.
		String^ GetCursorPos();
		//鼠标相对于上次的位置移动rx,ry.
		int MoveR(long x, long y);
		//把鼠标移动到目的点(x,y)
		int MoveTo(long x, long y);
		//把鼠标移动到目的范围内的任意一点
		int MoveToEx(long x, long y, long w, long h);
		//按下鼠标左键
		int LeftClick();
		//双击鼠标左键
		int LeftDoubleClick();
		//按住鼠标左键
		int LeftDown();
		//弹起鼠标左键
		int LeftUp();
		//按下鼠标中键
		int MiddleClick();
		//按住鼠标中键
		int MiddleDown();
		//弹起鼠标中键
		int MiddleUp();
		//按下鼠标右键
		int RightClick();
		//按住鼠标右键
		int RightDown();
		//弹起鼠标右键
		int RightUp();
		//滚轮向下滚
		int WheelDown();
		//滚轮向上滚
		int WheelUp();
		//获取指定的按键状态.(前台信息,不是后台)
		int GetKeyState(long vk_code);
		//按住指定的虚拟键码
		int KeyDown(long vk_code);
		//按住指定的虚拟键码
		int KeyDownChar(String^ vk_code);
		//弹起来虚拟键vk_code
		int KeyUp(long vk_code);
		//弹起来虚拟键vk_code
		int KeyUpChar(String^ vk_code);
		//等待指定的按键按下 (前台,不是后台)
		int WaitKey(long vk_code, long time_out);
		//发送字符串
		//long SendString(long HWND)
		//弹起来虚拟键vk_code
		int KeyPress(long vk_code);
		int KeyPressChar(String^ vk_code);

		//--------------------image and color-----------------------
		//抓取指定区域(x1, y1, x2, y2)的图像, 保存为file
		int Capture(long x1, long y1, long x2, long y2, String^ file_name);
		//比较指定坐标点(x,y)的颜色
		int CmpColor(long x, long y, String^ color, double sim);
		//查找指定区域内的颜色
		Tuple<long, long, int>^ FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir);
		//查找指定区域内的所有颜色
		String^ FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir);
		//根据指定的多点查找颜色坐标
		Tuple<long, long, int>^ FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir);
		//根据指定的多点查找所有颜色坐标
		String^ FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir);
		//查找指定区域内的图片
		Tuple<long, long, int>^ FindPic(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir);
		//查找多个图片
		String^ FindPicEx(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir);
		//
		//这个函数可以查找多个图片, 并且返回所有找到的图像的坐标.此函数同FindPicEx.只是返回值不同.(file1,x,y|file2,x,y|...)
		String^ FindPicExS(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir);
		//查找指定区域内的颜色块,颜色格式"RRGGBB-DRDGDB",注意,和按键的颜色格式相反
		Tuple<long, long, int>^ FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width);
		//查找指定区域内的所有颜色块, 颜色格式"RRGGBB-DRDGDB", 注意, 和按键的颜色格式相反
		String^ FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width);
		//获取(x,y)的颜色
		String^ GetColor(long x, long y);
		//
		//设置图像输入方式，默认窗口截图
		int SetDisplayInput(String^ mode);

		int LoadPic(String^ file_name);

		int FreePic(String^ file_name);

		Tuple<long, long>^ GetScreenFrameInfo();
		//
		String^ MatchPicName(String^ pic_name);
		//----------------------ocr-------------------------
		//设置字库文件
		int SetDict(long idx, String^ file_name);
		//设置内存字库文件
		int SetMemDict(long idx, String^ data, long size);
		//使用哪个字库文件进行识别
		int UseDict(long idx);
		//识别屏幕范围(x1,y1,x2,y2)内符合color_format的字符串,并且相似度为sim,sim取值范围(0.1-1.0),
		String^ Ocr(long x1, long y1, long x2, long y2, String^ color, double sim);
		//回识别到的字符串，以及每个字符的坐标.
		String^ OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim);
		//在屏幕范围(x1,y1,x2,y2)内,查找string(可以是任意个字符串的组合),并返回符合color_format的坐标位置
		Tuple<long, long, int>^ FindStr(long x1, long y1, long x2, long y2, String^ strs, String^ color, double simxy);
		//返回符合color_format的所有坐标位置
		String^ FindStrEx(long x1, long y1, long x2, long y2, String^ strs, String^ color, double sim);
		//识别屏幕范围(x1,y1,x2,y2)内的字符串,自动二值化，而无需指定颜色
		String^ OcrAuto(long x1, long y1, long x2, long y2, double sim);
		//从文件中识别图片
		String^ OcrFromFile(String^ file_name, String^ color_format, double sim);
		//从文件中识别图片,无需指定颜色
		String^ OcrAutoFromFile(String^ file_name, double sim);
		//查找频幕中的直线
		String^ FindLine(long x1, long y1, long x2, long y2, String^ color, double sim);

		//向某进程写入数据
		int WriteData(long hwnd, String^ address, String^ data, long size);
		//读取数据
		String^ ReadData(long hwnd, String^ address, long size);

		~OPSoft();
	};
}
