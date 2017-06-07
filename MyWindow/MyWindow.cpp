#include<windows.h>
#include"resource.h"
//This is my code
//global function declarations
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG  msg;
	TCHAR szAppName[] = TEXT("SAB-Window");
	int WND_WIDTH = 700;
	int WND_HEIGHT = 500;

	int centerX = (GetSystemMetrics(SM_CXFULLSCREEN) - WND_WIDTH) / 2;
	int centerY = (GetSystemMetrics(SM_CXFULLSCREEN) - WND_HEIGHT) / 2;

	//code
	//initialixation of wndclass
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
//	wndclass.hIcon = LoadIcon(hInstance, TEXT(""));
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCEW(MY_ICON));
//	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCEW(MY_CURSOR));
//	wndclass.hCursor = LoadCursor(hInstance, TEXT("icon-developer-icon.cur"));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
//	wndclass.hbrBackground = CreateSolidBrush(RGB(0,0,255));
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCEW(MY_ICON));

	//register above class
	RegisterClassEx(&wndclass);

	

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("SAB-Window"),
		WS_OVERLAPPEDWINDOW, 
		centerX,
		centerY,
		WND_WIDTH,
		WND_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);


	//messageloop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}
	LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
	{
		//code 
		switch (iMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		return (DefWindowProc(hwnd,iMsg,wParam,lParam));
	}



