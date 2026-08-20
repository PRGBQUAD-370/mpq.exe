#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <thread>
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES 1
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
VOID WINAPI Initialize(VOID) {
	HMODULE hModUser32 = LoadLibraryW(L"user32.dll");
	BOOL(WINAPI * SetProcessDPIAware)(VOID) = (BOOL(WINAPI*)(VOID))GetProcAddress(hModUser32, "SetProcessDPIAware");
	if (SetProcessDPIAware) SetProcessDPIAware();
	FreeLibrary(hModUser32);
}
typedef union _RGBQUAD {
    COLORREF rgb;
    struct {
        BYTE r;
        BYTE g;
        BYTE b;
        BYTE Reserved;
    };
} _RGBQUAD, * PRGBQUAD;
DWORD WINAPI shader1(LPVOID lpParam) {
    while (1) {
        HDC hdc = GetDC(0);
        int x = GetSystemMetrics(0);
        int y = GetSystemMetrics(1);
        StretchBlt(hdc, -10, -10, x + 20, y + 20, hdc, 0, 0, x, y, SRCERASE);
        StretchBlt(hdc, 10, 10, x - 20, y - 20, hdc, 0, 0, x, y, SRCERASE);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI shader2(LPVOID lpParam) {
    HDC desk;
    int sw, sh;
    while (1) {
        desk = GetDC(0);
        sw = GetSystemMetrics(0);
        sh = GetSystemMetrics(1);
        StretchBlt(desk, -20, 0, sw + 40, sh, desk, 0, 0, sw, sh, SRCINVERT);
        ReleaseDC(0, desk);
        Sleep(4);
    }
}
DWORD WINAPI shader3(LPVOID lpParam) {
    HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
    INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    BITMAPINFO bmi = { 0 };
    PRGBQUAD rgbScreen = { 0 };
    bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biWidth = w;
    bmi.bmiHeader.biHeight = h;
    HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
    SelectObject(hdcMem, hbmTemp);
    for (;;) {
        hdcScreen = GetDC(0);
        BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCERASE);
        for (INT i = 0; i < w * h; i++) {
            INT x = i % w, y = i / w;
            rgbScreen[i].rgb = (x ^ y);
        }
        BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, SRCERASE);
        ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
    }
}
DWORD WINAPI shader4(LPVOID lpParam) {
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1) {
        HDC hdc = GetDC(0);
        BitBlt(hdc, -30, 0, w, h, hdc, 0, 0, SRCERASE);
        BitBlt(hdc, w - 30, 0, w, h, hdc, 0, 0, SRCERASE);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI shader5(LPVOID lpParam) {
    int time = GetTickCount();
    int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
    RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    for (int i = 0;; i++, i %= 3) {
        HDC desk = GetDC(NULL);
        HDC hdcdc = CreateCompatibleDC(desk);
        HBITMAP hbm = CreateBitmap(w, h, 1, 32, data);
        SelectObject(hdcdc, hbm);
        BitBlt(hdcdc, 0, 0, w, h, desk, 0, 0, SRCERASE);
        GetBitmapBits(hbm, 4 * h * w, data);
        int v = 0;
        BYTE byte = 0;
        if ((GetTickCount() - time) > 10)
            byte = rand() % 0xff;
        for (int i = 0; w * h > i; ++i) {
            if (!(i % h) && !(rand() % 110))
                v = rand() % 24;
            *((BYTE*)data + 4 * i + v) -= 5;
        }
        SetBitmapBits(hbm, w * h * 4, data);
        BitBlt(desk, 0, 0, w, h, hdcdc, 0, 0, SRCERASE);
        DeleteObject(hbm);
        DeleteObject(hdcdc);
        DeleteObject(desk);
    }
}
DWORD WINAPI shader6(LPVOID lpParam) {
    while (1) {
        HDC hdc = GetDC(NULL);
        int w = GetSystemMetrics(SM_CXSCREEN),
            h = GetSystemMetrics(SM_CYSCREEN),
            rx = rand() % w;
        BitBlt(hdc, rx, 10, 100, h, hdc, rx, 0, SRCERASE);
        ReleaseDC(NULL, hdc);
    }
}
DWORD WINAPI shader7(LPVOID lpParam) {
    HDC hdc;
    int w = GetSystemMetrics(0);
    int h = GetSystemMetrics(1);
    while (1) {
        hdc = GetDC(0);
        BitBlt(hdc, rand() % 2, rand() % 2, w, h, hdc, rand() % 2, rand() % 2, SRCERASE);
        Sleep(10);
        ReleaseDC(0, hdc);
    }
}
DWORD WINAPI shader8(LPVOID lpParam) {
    HDC desk;
    int sw, sh;
    while (1) {
        desk = GetDC(0);
        sw = GetSystemMetrics(0);
        sh = GetSystemMetrics(1);
        StretchBlt(desk, 0, -20, sw, sh + 40, desk, 0, 0, sw, sh, SRCINVERT);
        ReleaseDC(0, desk);
        Sleep(4);
    }
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	Initialize();

    if (MessageBoxW(NULL, L"This is a mpq-GDI.exe,\r\nRun?", L"mpq-GDI.exe by prgbquad-370", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
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
            HANDLE hThread1 = CreateThread(NULL, 0, shader1, NULL, 0, NULL);
            Sleep(30000);
            TerminateThread(hThread1, 0);
            CloseHandle(hThread1);
            Sleep(100);
            HANDLE hThread2 = CreateThread(NULL, 0, shader2, NULL, 0, NULL);
            Sleep(30000);
            TerminateThread(hThread2, 0);
            CloseHandle(hThread2);
            Sleep(100);
            HANDLE hThread3 = CreateThread(NULL, 0, shader3, NULL, 0, NULL);
            Sleep(30000);
            TerminateThread(hThread3, 0);
            CloseHandle(hThread3);
            Sleep(100);
            HANDLE hThread4 = CreateThread(NULL, 0, shader4, NULL, 0, NULL);
            Sleep(30000);
            TerminateThread(hThread4, 0);
            CloseHandle(hThread4);
            Sleep(100);
            HANDLE hThread5 = CreateThread(NULL, 0, shader5, NULL, 0, NULL);
            Sleep(40000);
            TerminateThread(hThread5, 0);
            CloseHandle(hThread5);
            Sleep(100);
            HANDLE hThread6 = CreateThread(NULL, 0, shader6, NULL, 0, NULL);
            Sleep(30000);
            TerminateThread(hThread6, 0);
            CloseHandle(hThread6);
            Sleep(100);
            HANDLE hThread7 = CreateThread(NULL, 0, shader7, NULL, 0, NULL);
            Sleep(30000);
            TerminateThread(hThread7, 0);
            CloseHandle(hThread7);
            Sleep(100);
            HANDLE hThread8 = CreateThread(NULL, 0, shader8, NULL, 0, NULL);
            Sleep(30000);
    }
}