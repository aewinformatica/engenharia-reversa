#include <windows.h>

// Função que será exportada pela DLL
extern "C" __declspec(dllexport) void DllMain()
{
    // Obtenha o identificador do processo atual (seu próprio processo)
    HANDLE hProcess = GetCurrentProcess();

    // Endereço base onde você deseja escrever os dados (pode ser alterado)
    LPVOID lpBaseAddress = (LPVOID)0x0040140B; // Endereço de exemplo

    // Dados a serem escritos
    const char* dados = "Olá, mundo!";

    // Escreva os dados na memória do processo atual
    SIZE_T NumberOfBytesWritten;
    BOOL sucesso = WriteProcessMemory(hProcess, lpBaseAddress, dados, strlen(dados), &NumberOfBytesWritten);

    if (sucesso)
    {
        // Os dados foram escritos com sucesso
        // Faça algo aqui...
    }
    else
    {
        // Algo deu errado
        DWORD erro = GetLastError();
        // Lide com o erro conforme necessário
    }
}