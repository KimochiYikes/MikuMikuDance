#include "Framework.hpp"
#include "ExportedFunctions.hpp"

/* Exported functions with official names for use for other DLLs (like MMEffects) */
/* TODO: pMMD is temporary so these functions shouldn't be used yet */

// x64 - 0xDB5B0
float ExpGetFrameTime()
{
    if (pMMD->IsRendering)
        return pMMD->FrameTime;
    else
        return pMMD->FrameIndex / 30.0f;
}

// x64 - 0xDBA70
bool ExpGetAcsDisp(int index)
{
    int counter = -1;

    for (int i = 0; i < 255; ++i) 
    {
        cAccessory* ptr = pMMD->AccessoriesList[i];

        if (ptr && ++counter == index)
            return ptr->IsDisplayOn;
    }

    return false;
}

// x64 - 0xDBBE0
bool ExpGetEnglishMode()
{
    return pMMD->IsEnglishModeOn;
}
