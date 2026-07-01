#include <Windows.h>
#include <thread>
#include <cstdlib>
#include <cmath>

DWORD WINAPI payload0(LPVOID lpParam) {
	while (1) {
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(SM_CXSCREEN),
			h = GetSystemMetrics(SM_CYSCREEN);
		StretchBlt(hdc, 10, 10, w - 20, h - 20, hdc, 0, 0, w, h, SRCINVERT);
		StretchBlt(hdc, -10, -10, w + 20, h + 20, hdc, 0, 0, w, h, SRCINVERT);
		ReleaseDC(NULL, hdc);
	}
}
DWORD WINAPI payload1(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		hdc = GetDC(0);
		BitBlt(hdc, 1, 1, w, h, hdc, 0, 0, SRCINVERT);
		BitBlt(hdc, -1, -1, w, h, hdc, 0, 0, SRCINVERT);
		ReleaseDC(GetDesktopWindow(), hdc);
		DeleteDC(hdc);
		Sleep(10);
	}

}
DWORD WINAPI payload2(LPVOID lpParam) {
	HDC desktop = GetDC(NULL);
	int xs = GetSystemMetrics(SM_CXSCREEN);
	int ys = GetSystemMetrics(SM_CYSCREEN);
	while (true) {
		desktop = GetDC(NULL);
		BitBlt(desktop, 0, 0, xs, ys, desktop, -1, -1, SRCERASE);
		ReleaseDC(0, desktop);
		Sleep(10);
	}
}
DWORD WINAPI payload3(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		hdc = GetDC(0);
		BitBlt(hdc, 30, 30, w, h, hdc, 0, 0, SRCINVERT);
		BitBlt(hdc, -30, -30, w, h, hdc, 0, 0, SRCINVERT);
		ReleaseDC(GetDesktopWindow(), hdc);
		DeleteDC(hdc);
		Sleep(10);
	}

}
DWORD WINAPI payload4(LPVOID lpParam) {
	while (1) {
		HDC hdc = GetDC(NULL);
		int w = GetSystemMetrics(SM_CXSCREEN),
			h = GetSystemMetrics(SM_CYSCREEN);
		StretchBlt(hdc, 5, 5, w - 10, h - 10, hdc, 0, 0, w, h, SRCINVERT);
		StretchBlt(hdc, -5, -5, w + 10, h + 10, hdc, 0, 0, w, h, SRCINVERT);
		ReleaseDC(NULL, hdc);
	}
}
DWORD WINAPI payload5(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		hdc = GetDC(0);
		BitBlt(hdc, 1, 1, w, h, hdc, 0, 0, SRCINVERT);
		BitBlt(hdc, -1, -1, w, h, hdc, 0, 0, SRCINVERT);
		ReleaseDC(GetDesktopWindow(), hdc);
		DeleteDC(hdc);
		Sleep(10);
	}

}
DWORD WINAPI payload6(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		hdc = GetDC(0);
		BitBlt(hdc, 0.9, 0.9, w, h, hdc, 0, 0, SRCINVERT);
		BitBlt(hdc, -0.9, -0.9, w, h, hdc, 0, 0, SRCINVERT);
		ReleaseDC(GetDesktopWindow(), hdc);
		DeleteDC(hdc);
		Sleep(10);
	}

}
DWORD WINAPI payload7(LPVOID lpParam) {
	HDC hdc = GetDC(0);
	int w = GetSystemMetrics(0);
	int h = GetSystemMetrics(1);
	while (true)
	{
		hdc = GetDC(0);
		BitBlt(hdc, 1, 1, w, h, hdc, 0, 0, SRCINVERT);
		BitBlt(hdc, -1, -1, w, h, hdc, 0, 0, SRCINVERT);
		ReleaseDC(GetDesktopWindow(), hdc);
		DeleteDC(hdc);
		Sleep(10);
	}

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	if (MessageBoxW(NULL, L"This is a mpq-GDI.exe.\r\nRun?", L"mpq-GDI.exe by prgbquad-370", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
	{
		ExitProcess(0);
	}
	else
	{
		if (MessageBoxW(NULL, L"Are you sure?", L"Final warning - mpq-GDI.exe", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
		{
			ExitProcess(0);
		}
		else

	Sleep(1000);
        HANDLE P1 = CreateThread(0, 0, payload0, 0, 0, 0);
	Sleep(30000);
	TerminateThread(P1, 0);
	CloseHandle(P1);
	Sleep(100);
	HANDLE P2 = CreateThread(0, 0, payload1, 0, 0, 0);
	Sleep(30000);
	TerminateThread(P2, 0);
	CloseHandle(P2);
	Sleep(100);
	HANDLE P3 = CreateThread(0, 0, payload2, 0, 0, 0);
	Sleep(30000);
	TerminateThread(P3, 0);
	CloseHandle(P3);
	Sleep(100);
	HANDLE P4 = CreateThread(0, 0, payload3, 0, 0, 0);
	Sleep(30000);
	TerminateThread(P4, 0);
	CloseHandle(P4);
	Sleep(100);
	HANDLE P5 = CreateThread(0, 0, payload4, 0, 0, 0);
	Sleep(40000);
	TerminateThread(P5, 0);
	CloseHandle(P5);
	Sleep(100);
	HANDLE P6 = CreateThread(0, 0, payload5, 0, 0, 0);
	Sleep(30000);
	TerminateThread(P6, 0);
	CloseHandle(P6);
	Sleep(100);
	HANDLE P7 = CreateThread(0, 0, payload6, 0, 0, 0);
	Sleep(30000);
	TerminateThread(P7, 0);
	CloseHandle(P7);
	Sleep(100);
	HANDLE P8 = CreateThread(0, 0, payload7, 0, 0, 0);
	Sleep(30000);
	TerminateThread(P8, 0);
	CloseHandle(P8);
	Sleep(100);
	}
}


