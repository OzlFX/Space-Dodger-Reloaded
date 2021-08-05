#pragma once

#include "Application.h"

#ifdef _WINDOWS

int main()
{
	auto Application = KE::CreateApplication();
	Application->Run();
}

#endif // _Windows
