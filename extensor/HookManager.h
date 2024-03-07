#pragma once
#include <basetsd.h>
#include <iostream>
#include <string>
#include <map>
#include <windows.h>

using namespace std;

class CHookManager : private CThreadSafe
{
	map<UINT64, bool> mData;
	bool TryWrite(UINT64 Address, int Count);
	void Write(UINT64 Address, int Count);
	bool ValidOrgBytes(UINT64 Address, LPBYTE OrgBytes, int Count);
public:
	CHookManager();
	~CHookManager();
	void WriteCall(UINT64 Address, PVOID Function, SIZE_T Nops = 0, LPBYTE OrgBytes = NULL);

};

extern CHookManager g_HookManager;