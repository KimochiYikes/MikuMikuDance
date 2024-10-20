#include "cKeyframe.hpp"

#ifndef CMMD_HPP
#define CMMD_HPP


struct cMMD
{
    gap _0[0x3D0];
    cKeyframe_Camera* KeyframeList_Camera;

	float CalculateCameraInterpolationFactor(
        CameraInterpolationType type, int index, float linear
    );
};

#endif // !CMMD_HPP
