#pragma once

#ifndef _WIN64
#define _WIN64
#endif

#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0500	// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_DCOM
#define _WIN32_DCOM
#endif

#ifndef __cplusplus
#define __cplusplus
#endif

#define _CRT_RAND_S

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

#include <winsock2.h>
#include <shellapi.h>
#include <psapi.h>
#include <windows.h>
#include <tchar.h>
#include <shlwapi.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <process.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <basetsd.h>
#include <map>
#include <vector>
#include <set>

#include <list>
#include <tlhelp32.h> 
#include "ThreadSafe.h"


#define JMP 0xE9
#define CALL 0xE8
#define NOP 0x90

#define DllExport __declspec(dllexport)

using namespace std;

//Additional Headers

#include "HookManager.h"
