#include "Framework.hpp"

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

enum class BoneInterpolationType
{
	MoveX,
	MoveY,
	MoveZ,
	Rotation
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

struct cKeyframe_Light
{
};

struct cKeyframe_Shadow
{
};

struct cKeyframe_Gravity
{
};

struct cKeyframe_Accessory
{
};

struct cKeyframe_Bone
{
	_BYTE gap0[12];
	char AX[4];
	char AY[4];
	char BX[4];
	char BY[4];
	cVector3 Position;
	cVector4 Quaternion;
	_BYTE gap38[3];
	char temp_end;
};


#endif // !CKEYFRAME_HPP
