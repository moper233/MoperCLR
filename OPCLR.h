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
		//��ȡ���һ�δ���
		int GetLastError();

		//�����Ƿ񵯳�������Ϣ,Ĭ���Ǵ� 0:�رգ�1:��ʾΪ��Ϣ��2:���浽�ļ�,3:�������׼���
		int SetShowErrorMsg(long show_type);

		//sleep
		int Sleep(long millseconds);
		//Process
		//inject dll
		int InjectDll(String^ process_name, String^ dll_name);
		//�����Ƿ������߹رղ���ڲ���ͼƬ�������
		int EnablePicCache(long enable);
		//ȡ�ϴβ�����ͼɫ���򣬱���Ϊfile(24λλͼ)
		int CapturePre(String^ file_name);
		//---------------------algorithm-------------------------------
		//A���㷨
		String^ AStarFindPath(long mapWidth, long mapHeight, String^ disable_points, long beginX, long beginY, long endX, long endY);
		//
		String^ FindNearestPos(String^ all_pos, long type, long x, long y);
		//--------------------windows api------------------------------
		//����ָ������,ö��ϵͳ�з��������Ĵ���
		String^ EnumWindow(long parent, String^ title, String^ class_name, long filter);
		//����ָ�������Լ���������,ö��ϵͳ�з��������Ĵ���
		String^ EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter);
		//����ָ��������,ö��ϵͳ�з��������Ľ���PID
		String^ EnumProcess(String^ name);
		//�Ѵ�������ת��Ϊ��Ļ����
		System::Tuple<long, long, int>^ ClientToScreen(long ClientToScreen);
		//���ҷ����������߱������Ķ���ɼ�����
		int FindWindow(String^ class_name, String^ title);
		//����ָ���Ľ������֣������ҿɼ�����
		int FindWindowByProcess(String^ process_name, String^ class_name, String^ title);
		//����ָ���Ľ���Id�������ҿɼ�����
		int FindWindowByProcessId(long process_id, String^ class_name, String^ title);
		//���ҷ����������߱������Ķ���ɼ�����,���ָ����parent,����parent�ĵ�һ���Ӵ����в���
		int FindWindowEx(long parent, String^ class_name, String^ title);
		//��ȡ���ڿͻ���������Ļ�ϵ�λ��
		System::Tuple<long, long, long, long, int>^ GetClientRect(long hwnd);
		//��ȡ���ڿͻ�����Ŀ�Ⱥ͸߶�
		System::Tuple<long, long, int>^ GetClientSize(long hwnd);
		//��ȡ���������о������뽹��Ĵ��ھ��
		int GetForegroundFocus();
		//��ȡ��������,���Ի�ȡ�������Դ�����޷���ȡ���ľ��
		int GetForegroundWindow();
		//��ȡ���ָ��Ŀɼ����ھ��
		int GetMousePointWindow();
		//��ȡ��������Ŀɼ����ھ��
		int GetPointWindow(long x, long y);
		//����ָ����pid��ȡ������ϸ��Ϣ
		String^ GetProcessInfo(long pid);
		//��ȡ���ⴰ��
		int GetSpecialWindow(long flag);
		//��ȡ����������صĴ��ھ��
		int GetWindow(long hwnd, long flag);
		//��ȡ���ڵ�����
		String^ GetWindowClass(long hwnd);
		//��ȡָ���������ڵĽ���ID
		int GetWindowProcessId(long hwnd);
		//��ȡָ���������ڵĽ��̵�exe�ļ�ȫ·��
		String^ GetWindowProcessPath(long hwnd);
		//��ȡ��������Ļ�ϵ�λ��
		System::Tuple<long, long, long, long, int>^ GetWindowRect(long hwnd);
		//��ȡָ�����ڵ�һЩ����
		int GetWindowState(long hwnd, long flag);
		//��ȡ���ڵı���
		String^ GetWindowTitle(long hwnd);
		//�ƶ�ָ�����ڵ�ָ��λ��
		int MoveWindow(long hwnd, long x, long y);
		//����Ļ����ת��Ϊ��������
		System::Tuple<long, long, int>^ ScreenToClient(long hwnd);
		//��ָ�����ڷ���ճ������
		int SendPaste(long hwnd);
		//���ô��ڿͻ�����Ŀ�Ⱥ͸߶�
		int SetClientSize(long hwnd, long width, long hight);
		//���ô��ڵ�״̬
		int SetWindowState(long hwnd, long flag);
		//���ô��ڵĴ�С
		int SetWindowSize(long hwnd, long width, long height);
		//���ô��ڵı���
		int SetWindowText(long hwnd, String^ title);
		//���ô��ڵ�͸����
		int SetWindowTransparent(long hwnd, long trans);
		//��ָ�����ڷ����ı�����
		int SendString(long hwnd, String^ str);
		//��ָ�����ڷ����ı�����-���뷨
		int SendStringIme(long hwnd, String^ str);
		//���п�ִ���ļ�,��ָ��ģʽ
		int RunApp(String^ cmdline, long mode);
		//���п�ִ���ļ�����ָ����ʾģʽ
		int WinExec(String^ cmdline, long cmdshow);

		//���������в����ؽ��
		String^ GetCmdStr(String^ cmd, long millseconds);

		//--------------------Background -----------------------
		//bind window and beign capture screen
		int BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode);
		//
		int UnBindWindow();
		//--------------------mouse & keyboard------------------
		//��ȡ���λ��.
		String^ GetCursorPos();
		//���������ϴε�λ���ƶ�rx,ry.
		int MoveR(long x, long y);
		//������ƶ���Ŀ�ĵ�(x,y)
		int MoveTo(long x, long y);
		//������ƶ���Ŀ�ķ�Χ�ڵ�����һ��
		int MoveToEx(long x, long y, long w, long h);
		//����������
		int LeftClick();
		//˫��������
		int LeftDoubleClick();
		//��ס������
		int LeftDown();
		//����������
		int LeftUp();
		//��������м�
		int MiddleClick();
		//��ס����м�
		int MiddleDown();
		//��������м�
		int MiddleUp();
		//��������Ҽ�
		int RightClick();
		//��ס����Ҽ�
		int RightDown();
		//��������Ҽ�
		int RightUp();
		//�������¹�
		int WheelDown();
		//�������Ϲ�
		int WheelUp();
		//��ȡָ���İ���״̬.(ǰ̨��Ϣ,���Ǻ�̨)
		int GetKeyState(long vk_code);
		//��סָ�����������
		int KeyDown(long vk_code);
		//��סָ�����������
		int KeyDownChar(String^ vk_code);
		//�����������vk_code
		int KeyUp(long vk_code);
		//�����������vk_code
		int KeyUpChar(String^ vk_code);
		//�ȴ�ָ���İ������� (ǰ̨,���Ǻ�̨)
		int WaitKey(long vk_code, long time_out);
		//�����ַ���
		//long SendString(long HWND)
		//�����������vk_code
		int KeyPress(long vk_code);
		int KeyPressChar(String^ vk_code);

		//--------------------image and color-----------------------
		//ץȡָ������(x1, y1, x2, y2)��ͼ��, ����Ϊfile
		int Capture(long x1, long y1, long x2, long y2, String^ file_name);
		//�Ƚ�ָ�������(x,y)����ɫ
		int CmpColor(long x, long y, String^ color, double sim);
		//����ָ�������ڵ���ɫ
		Tuple<long, long, int>^ FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir);
		//����ָ�������ڵ�������ɫ
		String^ FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir);
		//����ָ���Ķ�������ɫ����
		Tuple<long, long, int>^ FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir);
		//����ָ���Ķ�����������ɫ����
		String^ FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir);
		//����ָ�������ڵ�ͼƬ
		Tuple<long, long, int>^ FindPic(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir);
		//���Ҷ��ͼƬ
		String^ FindPicEx(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir);
		//
		//����������Բ��Ҷ��ͼƬ, ���ҷ��������ҵ���ͼ�������.�˺���ͬFindPicEx.ֻ�Ƿ���ֵ��ͬ.(file1,x,y|file2,x,y|...)
		String^ FindPicExS(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir);
		//����ָ�������ڵ���ɫ��,��ɫ��ʽ"RRGGBB-DRDGDB",ע��,�Ͱ�������ɫ��ʽ�෴
		Tuple<long, long, int>^ FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width);
		//����ָ�������ڵ�������ɫ��, ��ɫ��ʽ"RRGGBB-DRDGDB", ע��, �Ͱ�������ɫ��ʽ�෴
		String^ FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width);
		//��ȡ(x,y)����ɫ
		String^ GetColor(long x, long y);
		//
		//����ͼ�����뷽ʽ��Ĭ�ϴ��ڽ�ͼ
		int SetDisplayInput(String^ mode);

		int LoadPic(String^ file_name);

		int FreePic(String^ file_name);

		Tuple<long, long>^ GetScreenFrameInfo();
		//
		String^ MatchPicName(String^ pic_name);
		//----------------------ocr-------------------------
		//�����ֿ��ļ�
		int SetDict(long idx, String^ file_name);
		//�����ڴ��ֿ��ļ�
		int SetMemDict(long idx, String^ data, long size);
		//ʹ���ĸ��ֿ��ļ�����ʶ��
		int UseDict(long idx);
		//ʶ����Ļ��Χ(x1,y1,x2,y2)�ڷ���color_format���ַ���,�������ƶ�Ϊsim,simȡֵ��Χ(0.1-1.0),
		String^ Ocr(long x1, long y1, long x2, long y2, String^ color, double sim);
		//��ʶ�𵽵��ַ������Լ�ÿ���ַ�������.
		String^ OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim);
		//����Ļ��Χ(x1,y1,x2,y2)��,����string(������������ַ��������),�����ط���color_format������λ��
		Tuple<long, long, int>^ FindStr(long x1, long y1, long x2, long y2, String^ strs, String^ color, double simxy);
		//���ط���color_format����������λ��
		String^ FindStrEx(long x1, long y1, long x2, long y2, String^ strs, String^ color, double sim);
		//ʶ����Ļ��Χ(x1,y1,x2,y2)�ڵ��ַ���,�Զ���ֵ����������ָ����ɫ
		String^ OcrAuto(long x1, long y1, long x2, long y2, double sim);
		//���ļ���ʶ��ͼƬ
		String^ OcrFromFile(String^ file_name, String^ color_format, double sim);
		//���ļ���ʶ��ͼƬ,����ָ����ɫ
		String^ OcrAutoFromFile(String^ file_name, double sim);
		//����ƵĻ�е�ֱ��
		String^ FindLine(long x1, long y1, long x2, long y2, String^ color, double sim);

		//��ĳ����д������
		int WriteData(long hwnd, String^ address, String^ data, long size);
		//��ȡ����
		String^ ReadData(long hwnd, String^ address, long size);

		~OPSoft();
	};
}
