//gcc -m32 %path% -o loadlib.exe
#include <windows.h>

typedef int (__cdecl *MYPROC)(LPWSTR); 
int main()
{
	HINSTANCE hGetProcIDDLL = LoadLibrary("LBTServ.dll");
	if (!hGetProcIDDLL) {
		MessageBox(0,"load lib fail","load lib fail",MB_OK);
		return 1;
	}
	MessageBox(0,"load ok","load ok",MB_OK);
	MYPROC ProcAdd;
	ProcAdd = (MYPROC)GetProcAddress((HMODULE) hGetProcIDDLL, "LGBT_Launch");
	if(ProcAdd == 0){
		MessageBox(0,"load proc fail","load proc fail",MB_OK);
		return 1;
	}
	ProcAdd(L"ok");
	
  return 0;
}
