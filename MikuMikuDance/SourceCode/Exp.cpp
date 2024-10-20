#include "pch.h"
#include "Exp.hpp"

// x64 - 0xDB5B0
float ExpGetFrameTime()
{
    if (pMMD->IsRendering)
        return pMMD->FrameTime;
    else
        return pMMD->FrameIndex / 30.0f;
}

// x64 - 0xDBBE0
bool ExpGetEnglishMode()
{
    return pMMD->IsEnglishModeOn;
}
