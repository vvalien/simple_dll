#include "our_dll.h"
#include <iostream>
#include "windows.h"
#pragma comment(lib, "user32.lib") // needed for cl.exe not vs
// RUNDLL.EXE <dllname>,<entrypoint> <optional arguments>


void popup_box(LPCSTR lpText) {
	MessageBox(0, lpText, "DLL Message", MB_OK | MB_ICONINFORMATION);
}

// a sample exported function
int DLL_EXPORT MsgBox(int x = 0) {
	MessageBox(0, "This is inside the our_dll.dll", "DLL Message", MB_OK | MB_ICONINFORMATION);
	DWORD rez = GetLastError();
	printf("GetLastError() from inside our_dll %ld\n", rez);
	return x;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		popup_box("attach to process");
		// return FALSE to fail DLL load
		break;

	case DLL_PROCESS_DETACH:
		popup_box("detach from process");
		// detach from process
		break;

	case DLL_THREAD_ATTACH:
		popup_box("attach to thread");
		// attach to thread
		break;

	case DLL_THREAD_DETACH:
		popup_box("detach from thread");
		// detach from thread
		break;
	}
	return TRUE; // successful
}