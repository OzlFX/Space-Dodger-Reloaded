/** Define dll import/export for windows **/
/** BUILD_DLL is only defined in engine **/
#pragma once

#ifdef _WINDOWS
	#ifdef BUILD_DLL
		#define KE_API __declspec(dllexport)
	#else
		#define KE_API __declspec(dllimport)
	#endif // BUILD_DLL
#else
	#error Only Windows is supported!
#endif // _WINDOWS
