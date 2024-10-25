#include "Framework.hpp"

void Main()
{
    /* Console */
    AllocConsole();
    
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);

    printf("Console was allocated. Hello world!\n");

    /* Globals */
    HMODULE hModule = GetModuleHandle(NULL);
    void* hModuleAddr = (void*)hModule;

    printf("Executable is located at 0x%p\n", hModuleAddr);

    pMMD = *reinterpret_cast<cMMD**>((uintptr_t)hModule + 0x1445F8);

    /* Tests */
    //printf("%f", pMMD->CameraPosition.Y);
    /*printf("%ls", pMMD->Path_UserFile_Model);*/

    /*pMMD->CameraPosition.X = 10.0f;
    pMMD->CameraPosition.Y = 8.0f;
    pMMD->CameraPosition.Z = -2.5f;*/

    /*pMMD->Colors.LightFacialManipulationUpper.R = 255;
    pMMD->Colors.LightFacialManipulationUpper.G = 0;
    pMMD->Colors.LightFacialManipulationUpper.B = 0;

    pMMD->Colors.LightFacialManipulationLower.R = 0;
    pMMD->Colors.LightFacialManipulationLower.G = 0;
    pMMD->Colors.LightFacialManipulationLower.B = 255;*/
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

