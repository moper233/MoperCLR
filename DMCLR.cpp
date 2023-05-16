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

String^ DMCLR::DMSoft::Ver()
{
	auto ver = (WCHAR*)dm->Ver();
	return gcnew String(ver);
}

int DMCLR::DMSoft::MoveTo(int x, int y)
{
	return dm->MoveTo(x, y);
}

int DMCLR::DMSoft::MoveR(int x, int y)
{
	return dm->MoveR(x, y);
}

int DMCLR::DMSoft::FindWindow(String^ class_name, String^ title_name)
{
	return dm->FindWindowW(StringToWchar(class_name), StringToWchar(title_name));
}

int DMCLR::DMSoft::BindWindow(int hwnd, String^ display, String^ mouse, String^ keypad, int mode)
{
	return dm->BindWindow(hwnd, StringToWchar(display), StringToWchar(mouse), StringToWchar(mouse), mode);
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
