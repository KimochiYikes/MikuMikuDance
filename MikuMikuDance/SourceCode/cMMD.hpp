#include "cKeyframe.hpp"
#include "cModel.hpp"
#include "cAccessory.hpp"
#include "cMMD_A16E0.hpp"

#ifndef CMMD_HPP
#define CMMD_HPP

struct cKeyStates
{
    VirtualKeyState Up;
    VirtualKeyState Down;
    VirtualKeyState Left;
    VirtualKeyState Right;
    VirtualKeyState Shift;
    VirtualKeyState Space;
    VirtualKeyState Escape;
    VirtualKeyState X_F9;
    VirtualKeyState Z_F11;
    VirtualKeyState C_Numpad3;
    VirtualKeyState V_F7;
    VirtualKeyState D_Numpad4;
    VirtualKeyState A_Numpad1;
    VirtualKeyState B_Numpad2;
    VirtualKeyState G_Numpad7;
    VirtualKeyState S_F4;
    VirtualKeyState I_Numpad9;
    VirtualKeyState H_Numpad8;
    VirtualKeyState K_Add;
    VirtualKeyState P_F1;
    VirtualKeyState U_F6;
    VirtualKeyState J_Multiply;
    VirtualKeyState F_Numpad6;
    VirtualKeyState R_F3;
    VirtualKeyState L_Separator;
    VirtualKeyState OEM_6;
    VirtualKeyState OEM_102;
    VirtualKeyState Tab;
    VirtualKeyState LButton;
    VirtualKeyState RButton;
    VirtualKeyState MButton;
    VirtualKeyState Numpad0;
    VirtualKeyState Numpad1;
    VirtualKeyState Numpad2;
    VirtualKeyState Numpad3;
    VirtualKeyState Numpad4;
    VirtualKeyState Numpad5;
    VirtualKeyState Numpad6;
    VirtualKeyState Numpad7;
    VirtualKeyState Numpad8;
    VirtualKeyState Numpad9;
    VirtualKeyState Delete;
    VirtualKeyState Return;
    VirtualKeyState Control;
    VirtualKeyState Menu;
};

struct cColors
{
    cRGBA Character;
    cRGBA BackgroundUpper;
    cRGBA BackgroundLower;
    cRGBA FrameManipulationUpper;
    cRGBA FrameManipulationLower;
    cRGBA BoneFrameManipulationUpper;
    cRGBA BoneFrameManipulationLower;
    cRGBA InterpolationCurveUpper;
    cRGBA InterpolationCurveLower;
    cRGBA ModelManipulationUpper;
    cRGBA ModelManipulationLower;
    cRGBA CameraBoneManipulationUpper;
    cRGBA CameraBoneManipulationLower;
    cRGBA LightFacialManipulationUpper;
    cRGBA LightFacialManipulationLower;
    cRGBA AccessoryManipulationUpper;
    cRGBA AccessoryManipulationLower;
    cRGBA ViewUpper;
    cRGBA ViewLower;
    cRGBA PlayVolumeUpper;
    cRGBA PlayVolumeLower;
    cRGBA SelfShadowColor1;
    cRGBA SelfShadowColor2;
    cRGBA FrameBackground1;
    cRGBA FrameBackground2;
    cRGBA FrameBackgroundLine;
    cRGBA FrameSelected1;
    cRGBA FrameSelected2;
    cRGBA FrameName1;
    cRGBA FrameName2;
    cRGBA FrameNameLine;
    cRGBA FrameVerticalLineNow;
    cRGBA FrameVerticalLine5;
    cRGBA FrameVerticalLine1;
    cRGBA FrameCharacter;
    cRGBA FrameSelectedCharacter;
};


struct cMMD
{
    HINSTANCE hInstance;
    _BYTE field_8[16];
    cKeyStates KeyStates;
    _BYTE gapCC[604];
    bool IsCameraModeOn;
    _BYTE gap329[31];
    cVector3 CameraRadians;
    bool IsCameraOrthographic;
    _BYTE gap355[19];
    bool IsRendering;
    cVector3 CameraPosition;
    _BYTE gap378[88];
    cKeyframe_Camera* KeyframeList_Camera;
    cKeyframe_Light* KeyframeList_Light;
    cKeyframe_Shadow* KeyframeList_Shadow;
    cKeyframe_Gravity* KeyframeList_Gravity;
    cKeyframe_Accessory** KeyframeList_Accessory[255];
    cModel* ModelList[255];
    unsigned __int8 SelectedModelIdx;
    _BYTE gap13E1[111];
    int FrameIndex;
    _BYTE gap1454[644076];
    cAccessory* AccessoriesList[255];
    __declspec(align(16)) cVector3 LightManipulationPosition;
    _BYTE gap9F04C[36];
    cVectorRGB LightManipulationColor;
    _BYTE gap9F07C[56];
    float CameraFOV;
    _BYTE gap9F0B8[1160];
    float FrameTime;
    _BYTE gap9F544[1920];
    cVector3 GravityDirection;
    float GravityAcceleration;
    unsigned int GravityNoise;
    _BYTE gap9FCD8[1480];
    wchar_t UserFileRoot[256];
    wchar_t CurrentDirectoryCopy[256];
    _BYTE gapA06A0[2876];
    DWORD CurrentTechnic;
    _BYTE gapA11E0[548];
    signed int CameraFollowModel;         ///< By default -1
    signed int CameraFollowBone;          ///< By default 0, might be unsigned
    float field_A140C;
    __declspec(align(32)) float field_A1420;
    _BYTE gapA1424[16];
    float field_A1434;
    _BYTE gapA1438[16];
    float field_A1448;
    _BYTE gapA144C[92];
    HBRUSH field_A14A8;
    HBRUSH field_A14B0;
    HBRUSH field_A14B8;
    HBRUSH field_A14C0;
    HBRUSH field_A14C8;
    HBRUSH field_A14D0;
    HBRUSH field_A14D8;
    HBRUSH field_A14E0;
    HBRUSH SelfShadow;
    HBRUSH CameraBoneManipulation;
    HBRUSH PlayVolume;
    _BYTE gapA1500[220];
    cColors Colors;
    _BYTE gapA166C[92];
    HWND hMainWindow;
    float float_A16D0;
    __declspec(align(16)) cMMD_A16E0* field_A16E0;
    _BYTE gapA16E8[6];
    wchar_t CurrentDirectory[256];
    __declspec(align(32)) float CameraDistance;
    float float_A1904;
    _BYTE gapA1908[28];
    wchar_t FilePath_PMM[256];
    _BYTE gapA1B24[108];
    bool IsEnglishModeOn;
    _BYTE gapA1B91[35];
    char HasUnsavedEnhancedModels;
    QWORD SystemTime;
    float RenderTimeInterval;
    _BYTE gapA1BC4[420];
    bool IsGravityNoiseEnabled;
    _BYTE gapA1D69[27];
    float field_A1D84;
    float field_A1D88;
    float field_A1D8C;
    float field_A1D90;
    float field_A1D94;
    _BYTE gapA1D98[12];
    float field_A1DA4;
    __declspec(align(32)) HWND hRecordingWindow;
    _BYTE gapA1DC8[4];
    float SelfShadowRange;
    eSelfShadowMode SelfShadowMode;
    __declspec(align(16)) HWND hSeparateWindow;
    _BYTE gapA1DE8[48];
    int KeyUpdateTick;
    wchar_t Path_UserFile_Model[1000];
    wchar_t Path_UserFile[1000];
    wchar_t Path_UserFile_Accessory[1000];
    wchar_t Path_UserFile_Motion[1000];
    wchar_t Path_UserFile_Pose[1000];
    wchar_t Path_UserFile_Wave[1000];
    wchar_t Path_UserFile_Background[1000];
    _BYTE gapA54CC[275];
    char temp_end;

    void UpdateKeyState(
        VirtualKey virtualKey, VirtualKeyState* virtualKeyState
    );

	float CalculateCameraInterpolationFactor(
        CameraInterpolationType type, int index, float linear
    );
};

#endif // !CMMD_HPP
