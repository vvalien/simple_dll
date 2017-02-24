#include <iostream>
#include <windows.h>
// http://www.infernodevelopment.com/simple-c-dll-loading-message-box

using namespace std;

typedef int(*MsgFunction)(int);

HINSTANCE hinstDLL;

int main(){
	MsgFunction MsgBox(0);
	hinstDLL = LoadLibrary("our_dll.dll");
	if (hinstDLL != 0){
		MsgBox = (MsgFunction)GetProcAddress(hinstDLL, "MsgBox");
	}
	if (MsgBox == 0)cout << "MsgBox is NULL\n";
	int x = MsgBox(5);
	if (x == 5){
		cout << "Message displayed!\n";
	}
	FreeLibrary(hinstDLL);
	return 0;
}