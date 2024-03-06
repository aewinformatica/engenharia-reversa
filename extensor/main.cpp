#include "main.h"

SPLASH g_SplashScreen;

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpvReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:

				g_SplashScreen.Init(NULL, hInstance, IDB_BITMAP);
				g_SplashScreen.Show();
				// g_SplashScreen.Hide();
				            
            break;
         case DLL_PROCESS_DETACH:
            // detach from process
            break;
        case DLL_THREAD_ATTACH:
            // attach to thread
            break;
        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE;// succesful
}