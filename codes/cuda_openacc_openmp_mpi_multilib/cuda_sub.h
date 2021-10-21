#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifndef HX_DLL
	#ifdef _WIN32
	#	if defined( BUILD_DLL )
	#		define HX_DLL __declspec(dllexport)
	#	elif defined( USE_DLL )
	#		define HX_DLL __declspec(dllimport)
	#	else
	#		define HX_DLL
	#	endif
	#else
	#	define HX_DLL
	#endif
#endif

HX_DLL void GetCudaDeviceCount( int &num_gpus );

#ifdef __cplusplus
}
#endif
