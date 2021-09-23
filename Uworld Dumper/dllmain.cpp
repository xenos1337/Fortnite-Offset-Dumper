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

			std::cout << "Uworld Dumper by android#1337 and xenos#1337" << std::endl;
			std::cout << "-------------------" << std::endl;
			std::cout << "uWorld: " << "0x" << std::hex << (uintptr_t)reinterpret_cast<decltype(uWorld)>((PBYTE)((UINT_PTR)(FindPattern("\x48\x8B\x05\x00\x00\x00\x00\x4D\x8B\xC2", "xxx????xxx")) + *(PINT)((UINT_PTR)(FindPattern("\x48\x8B\x05\x00\x00\x00\x00\x4D\x8B\xC2", "xxx????xxx"))+((7)-sizeof(INT))) + (7))) - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe") << std::endl;
			std::cout << "GoObjects: " << "0x" << std::hex << (uintptr_t)reinterpret_cast<decltype(uWorld)>((PBYTE)((UINT_PTR)(FindPattern("\x48\x8B\x05\x00\x00\x00\x00\x4D\x8B\xC2", "xxx????xxx")) + *(PINT)((UINT_PTR)(FindPattern("\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\x0C\xC8\x48\x8B\x04\xD1", "xxx????xxxxxxxx"))+((7)-sizeof(INT))) + (7))) - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe") << std::endl;
			std::cout << "LineOfSightTo: " << "0x" << std::hex << (uintptr_t)reinterpret_cast<decltype(LineOfSightTo)>((PBYTE)((UINT_PTR)(FindPattern("\xE8\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x33\xD2\x40\x8A\xF8", "x????xxx????xxxxx")) + *(PINT)((UINT_PTR)(FindPattern("\xE8\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x33\xD2\x40\x8A\xF8", "x????xxx????xxxxx")) + ((7) - sizeof(INT))) + (7))) - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe") << std::endl;
			std::cout << "ProjectWorldToScreen: " << "0x" << std::hex << (uintptr_t)reinterpret_cast<decltype(ProjectWorldToScreen)>((PBYTE)((UINT_PTR)(FindPattern("\xE8\x00\x00\x00\x00\x41\x88\x07\x48\x83\xC4\x30", "x????xxxxxxx")) + *(PINT)((UINT_PTR)(FindPattern("\xE8\x00\x00\x00\x00\x41\x88\x07\x48\x83\xC4\x30", "x????xxxxxxx")) + ((7) - sizeof(INT))) + (7))) - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe") << std::endl;
			std::cout << "CalculateSpreadHook: " << "0x" << std::hex << (uintptr_t)reinterpret_cast<decltype(CalculateSpreadHook)>((PBYTE)((UINT_PTR)(FindPattern("\xE8\x00\x00\x00\x00\x48\x8D\x4B\x28\xE8\x00\x00\x00\x00\x48\x8B\xC8", "x????xxxxx????xxx")) + *(PINT)((UINT_PTR)(FindPattern("\xE8\x00\x00\x00\x00\x48\x8D\x4B\x28\xE8\x00\x00\x00\x00\x48\x8B\xC8", "x????xxxxx????xxx")) + ((7) - sizeof(INT))) + (7))) - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe") << std::endl;
			std::cout << "SpreadCaller: " << "0x" << std::hex << (uintptr_t)reinterpret_cast<decltype(SpreadCaller)>((PBYTE)((UINT_PTR)(FindPattern("\x0F\x57\xD2\x48\x8D\x4C\x24\x00\x41\x0F\x28\xCC\xE8\x00\x00\x00\x00\x48\x8B\x4D\xB0\x0F\x28\xF0\x48\x85\xC9", "xxxxxxx?xxxxx????xxxxxxxxxx")) + *(PINT)((UINT_PTR)(FindPattern("\x0F\x57\xD2\x48\x8D\x4C\x24\x00\x41\x0F\x28\xCC\xE8\x00\x00\x00\x00\x48\x8B\x4D\xB0\x0F\x28\xF0\x48\x85\xC9", "xxxxxxx?xxxxx????xxxxxxxxxx")) + ((7) - sizeof(INT))) + (7))) - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe") << std::endl;
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
