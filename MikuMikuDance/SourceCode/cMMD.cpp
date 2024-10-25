#include "Framework.hpp"
#include "cMMD.hpp"

// x64 - 0x26F50, x32 - 0xE3D0
/* Update the press state of a key */
void cMMD::UpdateKeyState(VirtualKey virtualKey, VirtualKeyState* virtualKeyState)
{
    if (GetKeyState((int)virtualKey) & (1 << 7))
    {
        if (*virtualKeyState != VirtualKeyState::Idle)
        {
            *virtualKeyState = VirtualKeyState::Held;
            return;
        }

        *virtualKeyState = VirtualKeyState::Pressed;
    }
    else
    {
        if (*virtualKeyState != VirtualKeyState::Pressed && *virtualKeyState != VirtualKeyState::Held)
        {
            *virtualKeyState = VirtualKeyState::Idle;
            return;
        }

        *virtualKeyState = VirtualKeyState::Released;
    }
    this->KeyUpdateTick = 1;
    return;
}


// x64 - 0x26AD0, x32 - 0x2D3A0
/* Update the press state of all required key combos */
void cMMD::UpdateKeyStates()
{
    this->UpdateKeyState(VirtualKey::Up, &this->KeyStates.Up);
    this->UpdateKeyState(VirtualKey::Down, &this->KeyStates.Down);
    this->UpdateKeyState(VirtualKey::Left, &this->KeyStates.Left);
    this->UpdateKeyState(VirtualKey::Right, &this->KeyStates.Right);

    this->UpdateKeyState(VirtualKey::Shift, &this->KeyStates.Shift);
    this->UpdateKeyState(VirtualKey::Space, &this->KeyStates.Space);
    this->UpdateKeyState(VirtualKey::Control, &this->KeyStates.Control);
    this->UpdateKeyState(VirtualKey::Delete, &this->KeyStates.Delete);
    this->UpdateKeyState(VirtualKey::Escape, &this->KeyStates.Escape);
    this->UpdateKeyState(VirtualKey::Tab, &this->KeyStates.Tab);

    this->UpdateKeyState(VirtualKey::F9, &this->KeyStates.X_F9);
    this->UpdateKeyState(VirtualKey::X, &this->KeyStates.X_F9);

    this->UpdateKeyState(VirtualKey::F11, &this->KeyStates.Z_F11);
    this->UpdateKeyState(VirtualKey::Z, &this->KeyStates.Z_F11);

    this->UpdateKeyState(VirtualKey::Numpad3, &this->KeyStates.C_Numpad3);
    this->UpdateKeyState(VirtualKey::C, &this->KeyStates.C_Numpad3);

    this->UpdateKeyState(VirtualKey::F7, &this->KeyStates.V_F7);
    this->UpdateKeyState(VirtualKey::V, &this->KeyStates.V_F7);

    this->UpdateKeyState(VirtualKey::Numpad4, &this->KeyStates.D_Numpad4);
    this->UpdateKeyState(VirtualKey::D, &this->KeyStates.D_Numpad4);

    this->UpdateKeyState(VirtualKey::Numpad1, &this->KeyStates.A_Numpad1);
    this->UpdateKeyState(VirtualKey::A, &this->KeyStates.A_Numpad1);

    this->UpdateKeyState(VirtualKey::Numpad2, &this->KeyStates.B_Numpad2);
    this->UpdateKeyState(VirtualKey::B, &this->KeyStates.B_Numpad2);

    this->UpdateKeyState(VirtualKey::F4, &this->KeyStates.S_F4);
    this->UpdateKeyState(VirtualKey::S, &this->KeyStates.S_F4);

    this->UpdateKeyState(VirtualKey::Numpad7, &this->KeyStates.G_Numpad7);
    this->UpdateKeyState(VirtualKey::G, &this->KeyStates.G_Numpad7);

    this->UpdateKeyState(VirtualKey::Numpad8, &this->KeyStates.H_Numpad8);
    this->UpdateKeyState(VirtualKey::H, &this->KeyStates.H_Numpad8);

    this->UpdateKeyState(VirtualKey::Numpad9, &this->KeyStates.I_Numpad9);
    this->UpdateKeyState(VirtualKey::I, &this->KeyStates.I_Numpad9);

    this->UpdateKeyState(VirtualKey::Add, &this->KeyStates.K_Add);
    this->UpdateKeyState(VirtualKey::K, &this->KeyStates.K_Add);

    this->UpdateKeyState(VirtualKey::F1, &this->KeyStates.P_F1);
    this->UpdateKeyState(VirtualKey::P, &this->KeyStates.P_F1);

    this->UpdateKeyState(VirtualKey::F6, &this->KeyStates.U_F6);
    this->UpdateKeyState(VirtualKey::U, &this->KeyStates.U_F6);

    this->UpdateKeyState(VirtualKey::Multiply, &this->KeyStates.J_Multiply);
    this->UpdateKeyState(VirtualKey::J, &this->KeyStates.J_Multiply);

    this->UpdateKeyState(VirtualKey::Numpad6, &this->KeyStates.F_Numpad6);
    this->UpdateKeyState(VirtualKey::F, &this->KeyStates.F_Numpad6);

    this->UpdateKeyState(VirtualKey::F3, &this->KeyStates.R_F3);
    this->UpdateKeyState(VirtualKey::R, &this->KeyStates.R_F3);

    this->UpdateKeyState(VirtualKey::Separator, &this->KeyStates.L_Separator);
    this->UpdateKeyState(VirtualKey::L, &this->KeyStates.L_Separator);

    this->UpdateKeyState(VirtualKey::LButton, &this->KeyStates.LButton);
    this->UpdateKeyState(VirtualKey::RButton, &this->KeyStates.RButton);
    this->UpdateKeyState(VirtualKey::MButton, &this->KeyStates.MButton);

    this->UpdateKeyState(VirtualKey::Return, &this->KeyStates.Return);
    this->UpdateKeyState(VirtualKey::Menu, &this->KeyStates.Menu);

    this->UpdateKeyState(VirtualKey::Numpad0, &this->KeyStates.Numpad0);
    this->UpdateKeyState(VirtualKey::Numpad1, &this->KeyStates.Numpad1);
    this->UpdateKeyState(VirtualKey::Numpad2, &this->KeyStates.Numpad2);
    this->UpdateKeyState(VirtualKey::Numpad3, &this->KeyStates.Numpad3);
    this->UpdateKeyState(VirtualKey::Numpad4, &this->KeyStates.Numpad4);
    this->UpdateKeyState(VirtualKey::Numpad5, &this->KeyStates.Numpad5);
    this->UpdateKeyState(VirtualKey::Numpad6, &this->KeyStates.Numpad6);
    this->UpdateKeyState(VirtualKey::Numpad7, &this->KeyStates.Numpad7);
    this->UpdateKeyState(VirtualKey::Numpad8, &this->KeyStates.Numpad8);
    this->UpdateKeyState(VirtualKey::Numpad9, &this->KeyStates.Numpad9);

    this->UpdateKeyState(VirtualKey::OEM_6, &this->KeyStates.OEM_6);
    this->UpdateKeyState(VirtualKey::OEM_102, &this->KeyStates.OEM_102);
}

// x64 - 0x5A8B0, x86 - 0x10140
/* Calculate the interpolation weight for the next keyframe using cubic bézier */
float cMMD::CalculateCameraInterpolationFactor(CameraInterpolationType type, int index, float linear)
{
    /*
        type: Interpolation type, e.g. x axis move, rotation, etc.
        index: Index of the keyframe we are interpolating to
        time: Blending factor towards the next keyframe withing 0 and 1
    */
    unsigned int typeValue = (unsigned int)type;

    cKeyframe_Camera* KeyframeList_Camera = this->KeyframeList_Camera;

    if (
        KeyframeList_Camera[index].AX[typeValue] == KeyframeList_Camera[index].AY[typeValue] &&
        KeyframeList_Camera[index].BX[typeValue] == KeyframeList_Camera[index].BY[typeValue]
    )
        return linear;

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