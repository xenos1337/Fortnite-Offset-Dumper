#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <psapi.h>
#include <iostream>

PVOID* uWorld = 0;
// https://github.com/lhaasper/FORTNITE-CHEATS/blob/4a533dc97fd25c674e1efae628c669213aecccb0/l0st.dev%20FN/Util.cpp#L22
BOOLEAN MaskCompare(PVOID buffer, LPCSTR pattern, LPCSTR mask) {
	for (auto b = reinterpret_cast<PBYTE>(buffer); *mask; ++pattern, ++mask, ++b) {
		if (*mask == 'x' && *reinterpret_cast<LPCBYTE>(pattern) != *b) {
			return FALSE;
		}
	}

	return TRUE;
}

// https://github.com/lhaasper/FORTNITE-CHEATS/blob/4a533dc97fd25c674e1efae628c669213aecccb0/l0st.dev%20FN/Util.cpp#L32
PBYTE FindPattern(LPCSTR pattern, LPCSTR mask) {
	MODULEINFO info = { 0 };
	GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info));

	info.SizeOfImage -= static_cast<DWORD>(strlen(mask));

	for (auto i = 0UL; i < info.SizeOfImage; ++i) {
		auto addr = reinterpret_cast<PBYTE>(info.lpBaseOfDll) + i;
		if (MaskCompare(addr, pattern, mask)) {
			return addr;
		}
	}
}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		try 
		{
			AllocConsole();
			static_cast<VOID>(freopen("CONIN$", "r", stdin));
			static_cast<VOID>(freopen("CONOUT$", "w", stdout));
			static_cast<VOID>(freopen("CONOUT$", "w", stderr));

			std::cout << "Uworld Dumper by Android#1336 and xenos#1337" << std::endl;
			std::cout << "-------------------" << std::endl;
			std::cout << "uWorld: " << "0x" << std::hex << (uintptr_t)reinterpret_cast<decltype(uWorld)>((PBYTE)((UINT_PTR)(FindPattern("\x48\x8B\x05\x00\x00\x00\x00\x4D\x8B\xC2", "xxx????xxx")) + *(PINT)((UINT_PTR)(FindPattern("\x48\x8B\x05\x00\x00\x00\x00\x4D\x8B\xC2", "xxx????xxx"))+((7)-sizeof(INT))) + (7))) - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe") << std::endl;
			std::cout << "--------------------" << std::endl;
			std::cout << "Done :)" << std::endl;
		}
		catch(std::exception e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return TRUE;
}
