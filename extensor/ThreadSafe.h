#pragma once
#include <winbase.h>

class CThreadSafe
{
	CRITICAL_SECTION lock;
public:
	CThreadSafe() { InitializeCriticalSection(&lock); };
	virtual ~CThreadSafe() { DeleteCriticalSection(&lock);};
	void Lock() { EnterCriticalSection(&lock); };
	void Unlock() { LeaveCriticalSection(&lock); };
};