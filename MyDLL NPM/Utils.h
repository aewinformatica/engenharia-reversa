#pragma once
#include <windows.h>
#include <string>
#include <tchar.h>
#include <vector>
#include "time.h"
using namespace std;

//OPCODES
#define	JMP	  = 0xE9
#define	JE	  = 0x74
#define	JNE	  = 0x75
#define	JGE	  = 0x7D
#define	NOP	  = 0x90
#define	CALL  = 0xE8
#define	CALLD = 0xFF
#define	PUSH  = 0x68

bool WriteMemory(DWORD dwDestAddress, LPVOID pData, DWORD dwSize);
bool WriteMemoryDWORD(DWORD dwDestAddress, DWORD dwValue);
void SetHook(BYTE OpCode, DWORD dwBaseAddr, DWORD dwTargetAddr, int nNops);