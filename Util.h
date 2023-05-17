#pragma once
#include <string>
#include<vector>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <comutil.h>

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

	static const std::string ToCPPString(String^ value)
	{
		std::string str = marshal_as<std::string>(value->ToString());
		return str;
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
