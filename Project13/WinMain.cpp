// WinMain

#include "STATE.h"
#include "INITIALIZE.h"
#include "TCONTROL.h"
#include "RENDER.h"
#include "WINMAIN.h"

//�e�g���~�m���W
ImageState g_tetminoState = { 0.f, 0.f, 32.f / 2, 32.f / 2 };

//�Q�[���I�[�o�[���W
ImageState g_GameoverStrState = { 850.f,790.f,800.f, 450.f };

//���݃X�R�A���W
ImageState g_CurrentScoreStrState = { 910.f,700.f,200.f, 225.f };

//���݃n�C�X�R�A���W
ImageState g_CurrentHighScoreStrState = { 1170.f,820.f,400.f, 225.f };

//�z�[���h�g�������W
ImageState g_HoldStrState = { 200.f,150.f,170.f, 140.f };

//�l�N�X�g�������W
ImageState g_NextStrState = { 1170.f,235.f,500.f, 225.f };

//���C���J�E���g�������W
ImageState g_CountStrState = { 1550.f,445.f,400.f, 200.f };

//���C���J�E���g�\���������W
ImageState g_CountShowStrState = { 1380.f,385.f,400.f, 200.f };

//�m�[�}�����[�h�������W
ImageState g_NormalStrState = { 1200.f,220.f,300.f, 200.f };

//�t�B�[�o�[���[�h�������W
ImageState g_FeverStrState = { 1200.f,220.f,300.f, 200.f };

//�t�B�[�o�[�^�C�}�[���W
ImageState g_FeverTimerStrState = { 1165.f,500.f,50.f, 50.f };

//�t�B�[�o�[�^�C�����W
ImageState g_FeverTimeShowStrState = { 1100.f,435.f,150.f, 50.f };

//�t�B�[�o�[�Q�[�W�������W
ImageState g_FevergaugeStrState = { 335.f,370.f,150.f, 50.f };

//�������x���x���������W
ImageState g_FallLevelStrState = { 1190.f,190.f,50.f, 50.f };

//�������x���x���\���������W
ImageState g_FallLevelShowStrState = { 1140.f,150.f,150.f, 50.f };

//�t�B�[�o�[�Q�[�W�u���b�N
ImageState g_GaugeBlockState = { 215.f, 655.f, 32.f / 2, 32.f / 2 };


//�e�g���~�m�p�^�[��
Tetmino g_tetmino[7] =
{
{ 0,'I',1,4,1,5,1,6,1,7 },
{ 1,'J',1,5,2,5,2,6,2,7 },
{ 2,'L',1,7,2,7,2,6,2,5 },
{ 3,'S',1,7,1,6,2,6,2,5 },
{ 4,'Z',1,5,1,6,2,6,2,7 },
{ 5,'T',2,5,1,6,2,6,2,7 },
{ 6,'O',1,5,2,5,1,6,2,6 }
};

//�l�Y�~�u���b�N
TetminoMouse g_tetminoM[1] = 
{
	{0,'M',1,4,1,5}
};


MovMinoNumoOfArBuf g_movMinoNumOfArBuf;

INT g_tetminoNum;
INT g_hold = -1, g_next, g_nextNext,g_nextNextnext;

INT g_feverBlock;//�t�B�[�o�[�u���b�N

INT g_lineTotalCount;//���C���̍��v

DWORD g_elapsedTime;//�t�B�[�o�[���[�h�̌o�ߎ���

DWORD g_startTime;//�t�B�[�o�[���[�h�̊J�n����

INT FallSpeedLevel = 1;
INT FlamePerDown = 55;

INT g_minoIRoatationCount = 0;
INT g_tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
INT g_tetlisBoardBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
INT g_tetminoIBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
INT g_holdBoard[4][4];
INT g_nextBoard[4][4];
INT g_nextNextBoard[4][4];
INT g_nextNextNextBoard[4][4];

BOOL g_showGameoverStr = false;

CHAR g_scoreArray[8];

CHAR g_countArray[4];

CHAR g_feverTimerArray[2];

CHAR g_LevelArray[2];//���x��


//�E�B���h�E�̐����A�G���g���|�C���g
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR szStr, INT iCmdShow)
{
	srand((unsigned int)time(NULL));
	//�E�B���h�E�̐���
	HWND hWnd = NULL;
	MSG	msg;
	
	static CHAR szAppName[] = "CatsTetris";
	WNDCLASSEX wndclass;
	
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInst;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	
	RegisterClassEx(&wndclass);
	
	hWnd = CreateWindow(szAppName, szAppName, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, DISPLAY_WIDTH, DISPLAY_HEIGHT, NULL, NULL, hInst, NULL);


	//�E�B���h�E��������悤�ɂ���
	ShowWindow(hWnd, SW_SHOW);

	//�E�B���h�E���X�V����悤�ɂ���
	UpdateWindow(hWnd);

	//�_�C���N�g3D�̏�����
	if (FAILED(InitDirect3D(hWnd)))
	{
		return 0;
	}

	//�_�C���N�g�C���v�b�g�̏�����
	if (FAILED(InitDinput(hWnd)))
	{
		return 0;
	}

	//�_�C���N�g�t�H���g�̏�����
	if (FAILED(InitDfont(hWnd)))
	{
		return 0;
	}

	//���b�Z�[�W�̒��g�̏���
	ZeroMemory(&msg, sizeof(msg));

	//���Ԃ̗L�������̐ݒ�
	timeBeginPeriod(1);

	//�V�X�e�����Ԃ̎擾
	DWORD sync_prev = timeGetTime();
	DWORD sync_current;

	//���b�Z�[�W���[�v
	while (msg.message != WM_QUIT)
	{

		//���b�Z�[�W��`��
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			//���b�Z�[�W�̖|��
			TranslateMessage(&msg);

			//���b�Z�[�W�̑��M
			DispatchMessage(&msg);
		}
		else
		{
			sync_current = timeGetTime();

			//1�b�Ԃ�60�񂱂̒��ɓ���
			if (sync_current - sync_prev >= 1000 / 60)
			{
				Control();
				Render();
				sync_prev = sync_current;
			}
		}
	}
	timeEndPeriod(1);

	//�������J��
	FreeDx();

	return(INT)msg.wParam;
}

//�E�B�����b�Z�[�W�̏������s��
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)//////////////////////////////////////////////////////////////////////////////////
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch ((CHAR)wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

VOID FreeDx(VOID)
{
	if (g_pDKeyDevice)
	{
		g_pDKeyDevice->Unacquire();
	}

	SAFE_RELEASE(g_pDKeyDevice);

	SAFE_RELEASE(g_pDinput);

	for (int coordinateX = 0; coordinateX < g_texMax; coordinateX++)
	{
		SAFE_RELEASE(g_pTexture[coordinateX]);
	}

	for (int coordinateX = 0; coordinateX < g_fontMax; coordinateX++)
	{
		SAFE_RELEASE(g_pFont[coordinateX]);
	}
	SAFE_RELEASE(g_pD3dDevice);
	SAFE_RELEASE(g_pDirect3D);
}