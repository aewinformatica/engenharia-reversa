#include "Utils.h"

bool WriteMemory(DWORD dwDestAddress, LPVOID pData, DWORD dwSize)
{
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, GetCurrentProcessId());
	if(hProcess)
	{
		DWORD dwOldProtect = 0;
		if(VirtualProtect((LPVOID)dwDestAddress, dwSize, PAGE_WRITECOPY, &dwOldProtect))
		{
			DWORD dwWritten = 0;
			WriteProcessMemory(hProcess, (LPVOID)dwDestAddress, pData, dwSize, &dwWritten);
			VirtualProtect((LPVOID)dwDestAddress, dwSize, dwOldProtect, &dwOldProtect);
		}
		CloseHandle(hProcess);
		return true;
	}else
	{
		MessageBox(NULL, _T("Cannot get process handle!"), _T("CacheD Extension"), MB_OK);
	}
	return false;
}

bool WriteMemoryDWORD(DWORD dwDestAddress, DWORD dwValue)
{
	return WriteMemory(dwDestAddress, &dwValue, sizeof(DWORD));
}

void SetHook(BYTE OpCode, DWORD dwBaseAddr, DWORD dwTargetAddr, int nNops)
{
	HANDLE Server = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, false, GetCurrentProcessId());
	if(Server)
	{
		DWORD dwOldProtect = NULL;
		SIZE_T BytesWritten = NULL;
		int nTempSize = 5+nNops;
		BYTE *buffer = new BYTE[nTempSize];
		if(nNops==0)
		{
			ZeroMemory(buffer,5);
			buffer[0]=OpCode;
			dwTargetAddr-=dwBaseAddr+5;
			memcpy(buffer+1,&dwTargetAddr,4);
		}else
		{
			ZeroMemory(buffer, nTempSize);
			buffer[0]=OpCode;
			dwTargetAddr-=dwBaseAddr+5;
			memcpy(buffer+1,&dwTargetAddr,4);
			for(int n=5; n < nTempSize; n++)
				buffer[n]=0x90;
		}

		if(!VirtualProtect((LPVOID)dwBaseAddr, (nTempSize), PAGE_EXECUTE_READWRITE, &dwOldProtect))
		{
			//Error while setting new protect
		}
		if (!WriteProcessMemory(Server, (LPVOID)(dwBaseAddr), buffer, (nTempSize), &BytesWritten))
		{
			ExitProcess(0);
		}
		if(!VirtualProtect((LPVOID)dwBaseAddr, (nTempSize), dwOldProtect, &dwOldProtect))
		{
			//Error while setting old protect
		}

		delete [] buffer;
	}
	CloseHandle(Server);
}