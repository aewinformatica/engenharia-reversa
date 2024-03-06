#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "Winuser.h"
#include <process.h>
#include <windows.h>
#include <string.h>
#include <iostream>
#include "Splash.h"
#include "resource.h"

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#endif