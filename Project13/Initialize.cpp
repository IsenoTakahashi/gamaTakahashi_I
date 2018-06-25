#include "STATE.h"
#include "INITIALIZE.h"

LPDIRECT3D9 g_pDirect3D;
LPDIRECT3DDEVICE9 g_pD3dDevice;
LPDIRECTINPUT8 g_pDinput = NULL;
LPDIRECT3DTEXTURE9 g_pTexture[g_texMax];
LPDIRECTINPUTDEVICE8 g_pDKeyDevice = NULL;
LPD3DXFONT g_pFont[g_fontMax];
D3DPRESENT_PARAMETERS g_D3dPresentParameters;


//�_�C���N�g3D�̏������Ɋւ���֐�
HRESULT InitDirect3D(HWND hWnd)
{
	//�_�C���N�g3D�̍쐬
	if (NULL == (g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3D�̍쐬�Ɏ��s���܂���", "", MB_OK);
		return E_FAIL;
	}

	//g_D3dPresentParameters�̒��g�̏���
	ZeroMemory(&g_D3dPresentParameters, sizeof(g_D3dPresentParameters));

	
	//�o�b�t�@�[�`���A�����A�؂�ւ��̐ݒ�
	SetBuckBufferOverall();

	//�E�B���h�E���[�h�œ����Ă��邱�Ƃ̒�
	g_D3dPresentParameters.Windowed = TRUE;

	//�_�C���N�g3D�f�o�C�X�̍쐬
	if (FAILED(g_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3dDevice)))
	{
		//�`�惂�[�h�̐ݒ�
		MessageBox(0, "HAL���[�h��DIRECT3D�f�o�C�X���쐬�ł��܂���\nREF���[�h�ōĎ��s���܂�", NULL, MB_OK);
		if (FAILED(g_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&g_D3dPresentParameters, &g_pD3dDevice)))
		{
			MessageBox(0, "DIRECT3D�f�o�C�X�̍쐬�Ɏ��s���܂���", NULL, MB_OK);
			return E_FAIL;
		}
	}

	
	//�`��̏ڍאݒ�
	SetRenderStateOverall();

	
	//�e�N�X�`���K�w�̏ڍאݒ�
	SetTextureStageStateOverall();

	//���_���̓o�^
	g_pD3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	
	//�e�N�X�`���̐���
	CreateTextureFromFile();

	return S_OK;
}


//�����I�ȃo�b�t�@�̐ݒ������֐�
VOID SetBuckBufferOverall(VOID)
{
	//�o�b�t�@�[�̌`���ݒ�
	g_D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;

	//�o�b�t�@�[�̖����ݒ�
	g_D3dPresentParameters.BackBufferCount = 1;

	//�o�b�t�@�[�̐؂�ւ����@�̐ݒ�
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;

	return;
}


//�����I�ȕ`��̐ݒ������֐�
VOID SetRenderStateOverall(VOID)
{
	g_pD3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	return;
}

//�����I�ȃe�N�X�`���K�w�̐ݒ������֐�
VOID SetTextureStageStateOverall(VOID)
{
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	return;
}

//�e�N�X�`�������֐�
VOID CreateTextureFromFile(VOID)
{
	//�ʏ�w�i
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background1.png",
		&g_pTexture[g_backgroundTex]);

	//�g
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background_frame.png",
		&g_pTexture[g_frameTex]);

	//�t�B�[�o�[�w�i
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background1.png",
		&g_pTexture[g_feverbackgroundTex]);

	//�t�B�[�o�[�g
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background1_frame.png",
		&g_pTexture[g_feverframeTex]);


	//�ʏ�w�i2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background2.png",
		&g_pTexture[g_backgroundTex2]);

	//�g2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background2_frame.png",
		&g_pTexture[g_frameTex2]);

	//�t�B�[�o�[�w�i2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background2.png",
		&g_pTexture[g_feverbackgroundTex2]);

	//�t�B�[�o�[�g2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background2_frame.png",
		&g_pTexture[g_feverframeTex2]);


	//�z�[���h�g
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"hold_frame.png",
		&g_pTexture[g_holdFrameTex]);

	//�t�B�[�o�[�Q�[�W
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"gaugeframe.png",
		&g_pTexture[g_gaugeTex]);

	//�t�B�[�o�[�Q�[�W�t�B�[�o�[��
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"gaugeframe_fever.png",
		&g_pTexture[g_gaugeFiverTex]);

	//�X�R�A�g
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"score_frame.png",
		&g_pTexture[g_scoreFrameTex]);

	//�n�C�X�R�A�g
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"highscore_frame.png",
		&g_pTexture[g_highScoreFrameTex]);

	//�t�B�[�o�[�Q�[�W�u���b�N
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"gauge.png",
		&g_pTexture[g_feverBlockTex]);

	//�e�g���~�m
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"tetmino.png",
		&g_pTexture[g_tetminoTex]);

	return;
}


//�_�C���N�g�C���v�b�g�̏������Ɋւ���֐�
HRESULT InitDinput(HWND hWnd)
{
	HRESULT hr;

	//�_�C���N�g�C���v�b�g�̐���
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&g_pDinput, NULL)))
	{
		return hr;
	}

	//�_�C���N�g�C���v�b�g�f�o�C�X�̐���
	if (FAILED(hr = g_pDinput->CreateDevice(GUID_SysKeyboard,
		&g_pDKeyDevice, NULL)))
	{
		return hr;
	}

	//���͌`�����L�[�{�[�h�ɐݒ�
	if (FAILED(hr = g_pDKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}

	//�_�C���N�g�C���v�b�g�f�o�C�X�̌����擾�̗D��x�ݒ�
	if (FAILED(hr = g_pDKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}

	return S_OK;
}

HRESULT InitDfont(HWND hWnd)
{
	
	//�t�H���g�̐���
	CreateFont();

	return S_OK;
}


//�����`��
VOID CreateFont(VOID)
{
	//�Q�[���I�[�o�[
	D3DXCreateFont(g_pD3dDevice, 160, 80, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_gameoverFont]);

	//���݂̃X�R�A
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currentscoreFont]);

	//���݂̃n�C�X�R�A
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currenthighscoreFont]);

	//�l�N�X�g����
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_nextFont]);

	//���C���J�E���g����
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countFont]);

	//���C���J�E���g�\������
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countshowFont]);

	//�m�[�}�����[�h����
	D3DXCreateFont(g_pD3dDevice, 50, 30, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_normalFont]);

	//�t�B�[�o�[���[�h����
	D3DXCreateFont(g_pD3dDevice, 50, 30, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_feverFont]);

	//�t�B�[�o�[���[�h�^�C�}�[����
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimerFont]);

	//�t�B�[�o�[���[�h�^�C������
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimeshowFont]);

	//�t�B�[�o�[�Q�[�W����
	D3DXCreateFont(g_pD3dDevice, 20, 10, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevergaugeshowFont]);

	//�������x���x������
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelFont]);

	//�������x���x���\������
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelshowFont]);

	return;
}
