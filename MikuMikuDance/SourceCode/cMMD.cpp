#include "pch.h"
#include "cMMD.hpp"

// x64 - 0x5A8B0, x86 - 0x10140 1234
float cMMD::CalculateCameraInterpolationFactor(CameraInterpolationType type, int index, float linear)
{
    unsigned int typeValue = (unsigned int)type;

    cKeyframe_Camera* KeyframeList_Camera = this->KeyframeList_Camera;

    if (
        KeyframeList_Camera[index].AX[typeValue] != KeyframeList_Camera[index].AY[typeValue] ||
        KeyframeList_Camera[index].BX[typeValue] != KeyframeList_Camera[index].BY[typeValue]
    )
    {
        float org = 0.5f;
        float stepSize = 0.5f;

        float ax = (float)(KeyframeList_Camera[index].AX[typeValue] / 127);
        float bx = (float)(KeyframeList_Camera[index].BX[typeValue] / 127);
        float ay = (float)(KeyframeList_Camera[index].AY[typeValue] / 127);
        float by = (float)(KeyframeList_Camera[index].BY[typeValue] / 127);

        for (int i = 0; i < 12; i++)
        {
            stepSize *= 0.5;

            float inv = (1 - org);
            float bezier = (
                3 * (
                    ax * org * powf(inv, 2) + 
                    bx * inv * powf(org, 2)
                ) + powf(org, 3)
            );

            if (linear == bezier)
                break;

            org = linear <= bezier ? org - stepSize : org + stepSize;
        }

        float inv = (1 - org);
        float bezier = (
            3 * (
                ay * org * powf(inv, 2) +
                by * inv * powf(org, 2)
                ) + powf(org, 3)
            );
        return bezier;
    }
    return linear;
}
