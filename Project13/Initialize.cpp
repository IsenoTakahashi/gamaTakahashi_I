#include "STATE.h"
#include "INITIALIZE.h"

LPDIRECT3D9 g_pDirect3D;
LPDIRECT3DDEVICE9 g_pD3dDevice;
LPDIRECTINPUT8 g_pDinput = NULL;
LPDIRECT3DTEXTURE9 g_pTexture[g_texMax];
LPDIRECTINPUTDEVICE8 g_pDKeyDevice = NULL;
LPD3DXFONT g_pFont[g_fontMax];
D3DPRESENT_PARAMETERS g_D3dPresentParameters;


//ダイレクト3Dの初期化に関する関数
HRESULT InitDirect3D(HWND hWnd)
{
	//ダイレクト3Dの作成
	if (NULL == (g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3Dの作成に失敗しました", "", MB_OK);
		return E_FAIL;
	}

	//g_D3dPresentParametersの中身の消去
	ZeroMemory(&g_D3dPresentParameters, sizeof(g_D3dPresentParameters));

	
	//バッファー形式、枚数、切り替えの設定
	SetBuckBufferOverall();

	//ウィンドウモードで動いていることの提示
	g_D3dPresentParameters.Windowed = TRUE;

	//ダイレクト3Dデバイスの作成
	if (FAILED(g_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3dDevice)))
	{
		//描画モードの設定
		MessageBox(0, "HALモードでDIRECT3Dデバイスを作成できません\nREFモードで再試行します", NULL, MB_OK);
		if (FAILED(g_pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&g_D3dPresentParameters, &g_pD3dDevice)))
		{
			MessageBox(0, "DIRECT3Dデバイスの作成に失敗しました", NULL, MB_OK);
			return E_FAIL;
		}
	}

	
	//描画の詳細設定
	SetRenderStateOverall();

	
	//テクスチャ階層の詳細設定
	SetTextureStageStateOverall();

	//頂点情報の登録
	g_pD3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	
	//テクスチャの生成
	CreateTextureFromFile();

	return S_OK;
}


//総合的なバッファの設定をする関数
VOID SetBuckBufferOverall(VOID)
{
	//バッファーの形式設定
	g_D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;

	//バッファーの枚数設定
	g_D3dPresentParameters.BackBufferCount = 1;

	//バッファーの切り替え方法の設定
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;

	return;
}


//総合的な描画の設定をする関数
VOID SetRenderStateOverall(VOID)
{
	g_pD3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	return;
}

//総合的なテクスチャ階層の設定をする関数
VOID SetTextureStageStateOverall(VOID)
{
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);

	return;
}

//テクスチャを作る関数
VOID CreateTextureFromFile(VOID)
{
	//通常背景
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background1.png",
		&g_pTexture[g_backgroundTex]);

	//枠
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background_frame.png",
		&g_pTexture[g_frameTex]);

	//フィーバー背景
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background1.png",
		&g_pTexture[g_feverbackgroundTex]);

	//フィーバー枠
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background1_frame.png",
		&g_pTexture[g_feverframeTex]);


	//通常背景2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background2.png",
		&g_pTexture[g_backgroundTex2]);

	//枠2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"n_background2_frame.png",
		&g_pTexture[g_frameTex2]);

	//フィーバー背景2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background2.png",
		&g_pTexture[g_feverbackgroundTex2]);

	//フィーバー枠2
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"f_background2_frame.png",
		&g_pTexture[g_feverframeTex2]);


	//ホールド枠
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"hold_frame.png",
		&g_pTexture[g_holdFrameTex]);

	//フィーバーゲージ
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"gaugeframe.png",
		&g_pTexture[g_gaugeTex]);

	//フィーバーゲージフィーバー中
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"gaugeframe_fever.png",
		&g_pTexture[g_gaugeFiverTex]);

	//スコア枠
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"score_frame.png",
		&g_pTexture[g_scoreFrameTex]);

	//ハイスコア枠
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"highscore_frame.png",
		&g_pTexture[g_highScoreFrameTex]);

	//フィーバーゲージブロック
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"gauge.png",
		&g_pTexture[g_feverBlockTex]);

	//テトリミノ
	D3DXCreateTextureFromFile(
		g_pD3dDevice,
		"tetmino.png",
		&g_pTexture[g_tetminoTex]);

	return;
}


//ダイレクトインプットの初期化に関する関数
HRESULT InitDinput(HWND hWnd)
{
	HRESULT hr;

	//ダイレクトインプットの生成
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&g_pDinput, NULL)))
	{
		return hr;
	}

	//ダイレクトインプットデバイスの生成
	if (FAILED(hr = g_pDinput->CreateDevice(GUID_SysKeyboard,
		&g_pDKeyDevice, NULL)))
	{
		return hr;
	}

	//入力形式をキーボードに設定
	if (FAILED(hr = g_pDKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}

	//ダイレクトインプットデバイスの権限取得の優先度設定
	if (FAILED(hr = g_pDKeyDevice->SetCooperativeLevel(
		hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}

	return S_OK;
}

HRESULT InitDfont(HWND hWnd)
{
	
	//フォントの生成
	CreateFont();

	return S_OK;
}


//文字描画
VOID CreateFont(VOID)
{
	//ゲームオーバー
	D3DXCreateFont(g_pD3dDevice, 160, 80, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_gameoverFont]);

	//現在のスコア
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currentscoreFont]);

	//現在のハイスコア
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_currenthighscoreFont]);

	//ネクスト文字
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_nextFont]);

	//ラインカウント文字
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countFont]);

	//ラインカウント表示文字
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_countshowFont]);

	//ノーマルモード文字
	D3DXCreateFont(g_pD3dDevice, 50, 30, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_normalFont]);

	//フィーバーモード文字
	D3DXCreateFont(g_pD3dDevice, 50, 30, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_feverFont]);

	//フィーバーモードタイマー文字
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimerFont]);

	//フィーバーモードタイム文字
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevertimeshowFont]);

	//フィーバーゲージ文字
	D3DXCreateFont(g_pD3dDevice, 20, 10, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_fevergaugeshowFont]);

	//落下速度レベル文字
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelFont]);

	//落下速度レベル表示文字
	D3DXCreateFont(g_pD3dDevice, 40, 20, 0, 0, 0, 0, 0, 0, 0, "Times New Roman", &g_pFont[g_falllevelshowFont]);

	return;
}
