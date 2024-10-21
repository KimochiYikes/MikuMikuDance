#ifndef TYPES_HPP
#define TYPES_HPP

enum class VirtualKey
{
	LButton = 0x1,
	RButton = 0x2,
	MButton = 0x4,
	Tab = 0x9,
	Return = 0xD,
	Shift = 0x10,
	Control = 0x11,
	Menu = 0x12,
	Escape = 0x1B,
	Space = 0x20,
	Left = 0x25,
	Up = 0x26,
	Right = 0x27,
	Down = 0x28,
	Delete = 0x2E,
	A = 0x41,
	B = 0x42,
	C = 0x43,
	D = 0x44,
	F = 0x46,
	G = 0x47,
	H = 0x48,
	I = 0x49,
	J = 0x4A,
	K = 0x4B,
	L = 0x4C,
	P = 0x50,
	R = 0x52,
	S = 0x53,
	U = 0x55,
	V = 0x56,
	X = 0x58,
	Z = 0x5A,
	Numpad0 = 0x60,
	Numpad1 = 0x61,
	Numpad2 = 0x62,
	Numpad3 = 0x63,
	Numpad4 = 0x64,
	Numpad5 = 0x65,
	Numpad6 = 0x66,
	Numpad7 = 0x67,
	Numpad8 = 0x68,
	Numpad9 = 0x69,
	Multiply = 0x6A,
	Add = 0x6B,
	Separator = 0x6C,
	F1 = 0x70,
	F3 = 0x72,
	F4 = 0x73,
	F6 = 0x75,
	F7 = 0x76,
	F9 = 0x78,
	F11 = 0x7A,
	OEM_6 = 0xDD,
	OEM_102 = 0xE2,
};

enum class VirtualKeyState
{
	Idle,
	Pressed,
	Released,
	Held,
};

enum eSelfShadowMode : __int8
{
	NoShadow = 0u,
	Mode1 = 1u,
	Mode2 = 2u,
};



struct cVector3
{
	float X, Y, Z;
};

struct cVectorRGB
{
	float R, G, B;
};

struct cRGBA
{
	unsigned __int8 R, G, B, A;
};

typedef unsigned long long QWORD;
typedef unsigned char _BYTE;
typedef unsigned char gap;

#endif // !TYPES_HPP
