#ifndef WINMAIN
#define WINMAIN

#include <windows.h>
#include <time.h>

//�v���V�[�W���̐����֐�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

//�E�B���h�E�̐ݒ�A���C���֐�
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow);

//�������J��������֐�
VOID FreeDx(VOID);

#endif
