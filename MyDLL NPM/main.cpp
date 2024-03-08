#include "main.h"

#define DLL_EXPORT __declspec(dllexport)

// Variável global para armazenar o identificador da janela
HWND g_HWND = NULL;

// Função de callback para EnumWindows
BOOL CALLBACK EnumWindowsProcMy(HWND hwnd, LPARAM lParam)
{
    DWORD lpdwProcessId;
    GetWindowThreadProcessId(hwnd, &lpdwProcessId);
    if (lpdwProcessId == lParam)
    {
        g_HWND = hwnd;
        return FALSE; // Interrompe a enumeração
    }
    return TRUE; // Continua a enumeração
}

void TitleReplaceHookThread(void *param)
{
    DWORD pid = 0;
    DWORD current_pid = GetCurrentProcessId();
    
	while(true)
	{
		Sleep(50);
        EnumWindows(EnumWindowsProcMy, current_pid);
		if(g_HWND&&current_pid){
        SetWindowText(g_HWND, "MEU TITULO DE FODAO DOS FODOES ENGENHARIA REVERSA NO NPM");
        break;
        }
	}
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
             HANDLE hThread;
            hThread = (HANDLE)_beginthread(TitleReplaceHookThread, 0, NULL);
            CloseHandle(hThread);
            break;
    }
    return TRUE;
}