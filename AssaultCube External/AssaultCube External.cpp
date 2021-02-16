#include <iostream> //Windows.h
#include <Windows.h>
#include "proc.h"
#include "mem.h"

using namespace std;

DWORD GamePID = NULL;
HWND Game = FindWindow(NULL, L"AssaultCube"); // Find The Window Of Assault Cube

HANDLE hProc = 0;
uintptr_t ModuleBase = 0, LocalPlayerPtr = 0, HealthAddr = 0;

BOOL bHealth = false, bAmmo = false, bRecoil = false;
BOOL Show = true;

int main()
{
	SetConsoleTitleA("External Assault Cube - Cheat > xo1337");

	cout << "Waiting for ac_client.exe . . ." << endl;

	while (GamePID == NULL)
		GamePID = GetWindowThreadProcessId(Game, &GamePID);
	if (GamePID != NULL)
	{
		cout << "Found ac_client.exe -> " << std::dec << GamePID << endl;
		cout << "================================================================" << endl << endl;
		hProc = OpenProcess(PROCESS_ALL_ACCESS, NULL, GamePID);
		ModuleBase = GetModuleBaseAddress(GamePID, L"ac_client.exe");

		LocalPlayerPtr = ModuleBase + 0x10F4F4;
		HealthAddr = FindDMAAddy(hProc, LocalPlayerPtr, { 0xF8 });

		auto Base = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
		cout << "xo1337 : https://www.unknowncheats.me/forum/members/3742498.html" << endl;
		cout << "================================================================" << endl << endl;
		cout << "\"ac_client.exe\" ProcessID   -> " << std::dec << GamePID << endl;
		cout << "\"ac_client.exe\" HWND        -> " << std::hex << "0x" << Game << endl;
		cout << "================================================================" << endl << endl;
		cout << "[F1] -> No Recoil" << endl;
		cout << "================================================================" << endl << endl;

		


		while (true)
		{
			if (GetAsyncKeyState(VK_F1))
			{
				bRecoil = !bRecoil;

				if (bRecoil)
				{
					mem::NopEx((BYTE*)(ModuleBase + 0x63786), 10, hProc);
				}
				else
				{
					mem::PatchEx((BYTE*)(ModuleBase + 0x63786), (BYTE*)"\x50\x8d\x4c\x24\x1c\x51\x8b\xce\xff\xd2", 10, hProc);
				}
			}

			

			
		}

		getchar();
	}
}