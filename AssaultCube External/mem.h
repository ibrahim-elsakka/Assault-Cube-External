#pragma once

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

namespace mem
{
	void PatchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProc);
	void NopEx(BYTE* dst, unsigned int size, HANDLE hProc);
}