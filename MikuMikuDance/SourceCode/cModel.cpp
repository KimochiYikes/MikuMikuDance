#include "cModel.hpp"

// x64 - 0xCDB00
/* Calculate the interpolation weight for the next keyframe using cubic bézier */
float cModel::CalculateBoneInterpolationFactor(BoneInterpolationType type, int index, float linear)
{
    /*
        type: Interpolation type, e.g. x axis move, rotation, etc.
        index: Index of the keyframe we are interpolating to
        time: Blending factor towards the next keyframe withing 0 and 1
    */
    unsigned int typeValue = (unsigned int)type;

    cKeyframe_Bone* KeyframeList_Bone = this->KeyframeList_Bone;

    if (
        KeyframeList_Bone[index].AX[typeValue] == KeyframeList_Bone[index].AY[typeValue] &&
        KeyframeList_Bone[index].BX[typeValue] == KeyframeList_Bone[index].BY[typeValue]
    )
        return linear;

    float org = 0.5f;
    float stepSize = 0.5f;

    float ax = (float)(KeyframeList_Bone[index].AX[typeValue] / 127);
    float bx = (float)(KeyframeList_Bone[index].BX[typeValue] / 127);
    float ay = (float)(KeyframeList_Bone[index].AY[typeValue] / 127);
    float by = (float)(KeyframeList_Bone[index].BY[typeValue] / 127);

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
