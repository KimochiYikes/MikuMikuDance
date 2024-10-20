#include "pch.h"
#include "SourceCode/cKeyframe.hpp"

void Main()
{
    AllocConsole();
    
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);

    printf("Console was allocated. Hello World!\n");

    size_t size = sizeof(cKeyframe_Camera);
    printf("Size of cKeyframe_Camera: 0x%X bytes\n", (unsigned int)size);
}

BOOL APIENTRY DllMain(
    HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Main();
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

