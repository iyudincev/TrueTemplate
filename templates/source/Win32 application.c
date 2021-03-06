/*==========================================================================*/
/*
@@INCLUDE:$\templates\source\header-base@@
*/
/*--------------------------------------------------------------------------*/
/*
@@INCLUDE:$\templates\source\header-gnu@@
*/
/*--------------------------------------------------------------------------*/
/*
@@INCLUDE:$\templates\source\header-cvs@@
*/
/*==========================================================================*/
#ifndef __@@UPPERFILE_NAME@@_@@UPPERFILE_EXT@@__
#define __@@UPPERFILE_NAME@@_@@UPPERFILE_EXT@@__
/*==========================================================================*/
#include <windows.h>
/*==========================================================================*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	RECT rect;
	HDC hDC;

	switch (iMsg)
	{
		case WM_CREATE:
		{
			return 0;
		}
		case WM_PAINT:
		{
			hDC = BeginPaint(hWnd, &ps);
			GetClientRect(hWnd, &rect);
			DrawText(hDC, "Hello, Windows!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			EndPaint(hWnd, &ps);
			return 0;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
/*==========================================================================*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	@@HERE@@const char ClassName[] = "Win32 class";
	WNDCLASSEX WndClass;
	HWND hWnd;
	MSG Msg;

	WndClass.cbSize			= sizeof(WndClass);
	WndClass.style			= CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc	= WndProc;
	WndClass.cbClsExtra		= 0;
	WndClass.cbWndExtra		= 0;
	WndClass.hInstance		= hInstance;
	WndClass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor		= LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName	= NULL;
	WndClass.lpszClassName	= ClassName;
	WndClass.hIconSm		= LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(ClassName,	// Window class name
		"The Hello Program",		// Window caption
		WS_OVERLAPPEDWINDOW,		// Window style
		CW_USEDEFAULT,				// Initial x position
		CW_USEDEFAULT,				// Initial y position
		CW_USEDEFAULT,				// Initial x size
		CW_USEDEFAULT,				// Initial y size
		NULL,						// Parent window handle
		NULL,						// Window menu handle
		hInstance,					// Program instance handle
		NULL);						// Creation parameters

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return (int)Msg.wParam;
}
/*==========================================================================*/
#endif
