#pragma once

using namespace System;

namespace DMCLR {
	public ref class DMSoft
	{
	private:
		Idmsoft* dm;
		
	public:
		String^ Ver();
		int MoveTo(int x,int y);
		int MoveR(int x, int y);
		DMSoft();
		~DMSoft();
	};
}
