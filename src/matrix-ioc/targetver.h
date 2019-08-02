#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>


#ifdef EXPMODULE
#define EXPORT_SYMBOL __declspec(dllexport)
#else
#define EXPORT_SYMBOL __declspec(dllimport)
#endif