#pragma once
#include <string>
#include<vector>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <comutil.h>
#include <locale>
#include <codecvt>

using namespace std;
using namespace System;
using namespace msclr::interop;
using namespace System::Runtime::InteropServices;

public class Util
{

public:
	static const wchar_t* StringToWchar(String^ value)
	{
		auto str = (wchar_t*)(void*)Marshal::StringToHGlobalUni(value);
		return str;
	}

	static char* StringToChar(String^ value)
	{
		auto str = (char*)(void*)Marshal::StringToHGlobalUni(value);
		return str;
	}

	static const std::string ToCPPString(String^ value)
	{
		std::string str = marshal_as<std::string>(value->ToString());
		return str;
	}

	static char* StringToChar(String^ value, const std::string& locale)
	{
		auto str = ToCPPString(value);
		typedef std::codecvt_byname<wchar_t, char, std::mbstate_t> F;
		static std::wstring_convert<F> strCnv(new F(locale));
		auto wstr_value = strCnv.from_bytes(str);


		_bstr_t t = wstr_value.c_str();
		char* pchar = (char*)t;
		string result = pchar;
		char* charTmp = new char;
		strcpy_s(charTmp, result.length() + 1, result.c_str());
		pchar = NULL;
		delete pchar;
		return charTmp;
	}

	static String^ ToNetString(std::string value)
	{
		String^ str = gcnew String(value.c_str());
		return str;
	}

	static String^ WStringToString(wstring value)
	{
		String^ str = gcnew String(value.c_str());
		return str;
	}

	static String^ BSTRToString(_bstr_t value)
	{
		return gcnew String((WCHAR*)value);
	}

};
