#include "Types.hpp"

#ifndef CKEYFRAME_HPP
#define CKEYFRAME_HPP

enum class CameraInterpolationType
{
	MoveX,
	MoveY,
	MoveZ,
	Rotation,
	Distance,
	ViewAngle
};

// sizeof=0x54
struct cKeyframe_Camera
{
	int FrameIndex;
	int PreviousIndex;
	int NextIndex;
	float Distance;
	cVector3 Position;
	cVector3 Radians;
	char AX[6];
	char AY[6];
	char BX[6];
	char BY[6];
	bool OrthographicModeOn;
	gap _0[3];
	int FOV;
	bool IsSelected;
	gap _1[3];
	int FollowModel;
	int FollowBone;
};

#endif // !CKEYFRAME_HPP
