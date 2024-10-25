#include "UI.hpp"

// x64 - 0x3F550
void __fastcall OnButtonClick(HWND hWnd, int menu_id)
{
	char buffer[256];

	switch (menu_id)
	{
	case ID_FILE_EXIT: {
		pMMD->KeyStates.X_F9 = VirtualKeyState::Pressed;
		SendMessageA(pMMD->hMainWindow, WM_CLOSE, 0, 0);
		return;
	}

	case ID_HELP_ABOUT: {
		pMMD->KeyStates.I_Numpad9 = VirtualKeyState::Pressed;
		pMMD->KeyStates.Return = VirtualKeyState::Pressed;

		const char* title = "About";

		const char* text = pMMD->IsEnglishModeOn ?
			"MikuMikuDance Ver.%4.2f\n  (64bitOS Version)\n\nprogrammed by Yu Higuchi" :
			"MikuMikuDance Ver.%4.2f\n  (64bitOS Version)\n\nprogrammed by ”óŒû—D";

		HWND window = pMMD->hSeparateWindow ?
			pMMD->hSeparateWindow :
			pMMD->hMainWindow;

		// Yes, the version isn't a float :(
		sprintf_s(buffer, 256, text, 9.32);

		MessageBoxA(window, buffer, title, MB_OK);
		return;
	}
	}
}
