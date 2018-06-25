#include "STATE.h"
#include "INITIALIZE.h"
#include "RENDER.h"

VOID Render(VOID)
{
	
	//視点位置の設定、最後に絶対座標への変換を行う
	SetViewPointOverall();

	
	//視野角の設定、最後に絶対座標への変換を行う
	SetFocusOfViewOverall();

	//カスタムバーテックスの生成

	//通常背景

	CustomVertex cusV4Background[4]
		{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	 };
	

	//枠

	CustomVertex cusV4Frame[4]
		{
		/*{ 250.f,   20.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 620.f,   20.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 620.f, 670.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 250.f, 670.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }*/
			{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景

	CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠

	CustomVertex cusV4FeverFrame[4]
	{
	{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//通常背景2

	CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//枠2

	CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景2

	CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠2

	CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//ホールド枠
	CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//フィーバーゲージ
	CustomVertex cusV4GaugeFrame[4]{
	{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバーゲージフィーバー中
	CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//ハイスコア枠
	CustomVertex cusV4HighScoreframe[4]{
		{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//スコア枠
	CustomVertex cusV4ScoreFrame[4]{
	{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	
	};

	//フィーバーゲージブロック

	CustomVertex cusV4GaugeBlock[4]{
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//テトリミノ

	CustomVertex cusV4Tetmino[4]
		{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};
	

	//ゲームオーバー表示

	RECT rectGameoverStr
	{
		(LONG)(g_GameoverStrState.x - g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y - g_GameoverStrState.yScale),(LONG)(g_GameoverStrState.x + g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y + g_GameoverStrState.yScale)
	};
	

	//現在スコア表示

	RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	//現在ハイスコア表示

	RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};
	
	////ホールド枠文字

	//RECT rectHoldStr
	//{
	//	(LONG)(g_HoldStrState.x - g_HoldStrState.xScale),(LONG)(g_HoldStrState.y - g_HoldStrState.yScale),(LONG)(g_HoldStrState.x + g_HoldStrState.xScale),(LONG)(g_HoldStrState.y + g_HoldStrState.yScale)

	//};

	//ネクスト文字

	RECT rectNextStr
	{ 
		(LONG)(g_NextStrState.x - g_NextStrState.xScale),(LONG)(g_NextStrState.y - g_NextStrState.yScale),(LONG)(g_NextStrState.x + g_NextStrState.xScale),(LONG)(g_NextStrState.y + g_NextStrState.yScale)

	};

	//ラインカウント文字

	RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)

	};

	//ラインカウント表示文字

	RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//ノーマルモード文字

	RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)

	};

	//フィーバーモード文字

	RECT rectFeverStr
	{
		(LONG)(g_FeverStrState.x - g_FeverStrState.xScale),(LONG)(g_FeverStrState.y - g_FeverStrState.yScale),(LONG)(g_FeverStrState.x + g_FeverStrState.xScale),(LONG)(g_FeverStrState.y + g_FeverStrState.yScale)

	};

	//フィーバータイマー文字

	RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)

	};

	//フィーバータイム文字
	RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//フィーバーゲージ文字
	RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//落下速度レベル文字
	RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//落下速度レベル表示文字
	RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)
	};
	
	//画面表示関係の処理、カスタムバーテックスをg_tetlisBoardの配列番号を用いて、
	//書き換えテトリスを表示している
	DisplayScreen(
		cusV4Background, //通常背景
		cusV4Frame,      //枠
		cusV4FeverBackground, //フィーバー背景
		cusV4FeverFrame,      //フィーバー枠

		cusV4Background2, //通常背景2
		cusV4Frame2,      //枠2

		cusV4FeverBackground2, //フィーバー背景2
		cusV4FeverFrame2,      //フィーバー枠2

		cusV4HoldFrame,  //ホールド枠
		cusV4GaugeFrame, //フィーバーゲージ
		cusV4GaugeFrame_Fiver, //フィーバーゲージフィーバー中

		cusV4ScoreFrame, //スコア枠
		cusV4HighScoreframe,//ハイスコア枠
		cusV4GaugeBlock,    //フィーバーゲージブロック
		cusV4Tetmino,       //テトリミノ
		&rectGameoverStr,            //ゲームオーバー文字
		&rectCurrentScoreStr,        //現在スコア文字
		&rectCurrentHighScoreStr,    //現在ハイスコア文字
		&rectNextStr,                 //ネクストに表示する文字
		&rectCountStr,                //ラインカウント文字
		&rectCountShowStr,                //ラインカウント表示文字
		&rectNormalStr,                //ノーマルモード文字
		&rectFeverStr,                //フィーバーモード文字
		&rectFeverTimerStr,            //フィーバーモードタイマー
		&rectFeverTimeShowStr,         //フィーバーモードタイム
		&rectFevergaugeShowStr,        //フィーバーゲージ文字
		&rectFallLevelStr,              //落下速度レベル文字
		&rectFallLevelShowStr            //落下速度レベル表示文字
	);

	//画面表示が行われたことをバックバッファーに伝える
	g_pD3dDevice->Present(NULL, NULL, NULL, NULL);

	return;
}

//視点位置の設定
VOID SetViewPointOverall(VOID)
{
	D3DXVECTOR3 vecEyePt(0.0f, 1.0f, -3.0f);
	D3DXVECTOR3 vecLookatPt(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 vecUpVec(0.0f, 1.0f, 100.0f);
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vecEyePt, &vecLookatPt, &vecUpVec);
	g_pD3dDevice->SetTransform(D3DTS_VIEW, &matView);

	return;
}

//視野角の設定
VOID SetFocusOfViewOverall(VOID)
{
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pD3dDevice->SetTransform(D3DTS_VIEW, &matProj);

	return;
}

VOID CreateCustomVertex(VOID)
{
	//通常背景
	static CustomVertex cusV4Background[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//枠
	static CustomVertex cusV4Frame[4]
	{
		/*{ 250.f,   20.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 620.f,   20.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 620.f, 670.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 250.f, 670.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }*/
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景
	static CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠
	static CustomVertex cusV4FeverFrame[4]
	{
	{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//通常背景2
	static CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//枠
	static CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー背景
	static CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバー枠
	static CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//ホールド枠
	static CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバーゲージ
	static CustomVertex cusV4GaugeFrame[4]{
	{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバーゲージフィーバー中
	static CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//スコア枠
	static CustomVertex cusV4ScoreFrame[4]{
		{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//ハイスコア枠
	static CustomVertex cusV4HighScoreframe[4]{
	{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//フィーバーゲージブロック

	CustomVertex cusV4GaugeBlock[4]{
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//テトリミノ
	static CustomVertex cusV4Tetmino[4]
	{
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};

	//ゲームオーバー表示
	static RECT rectGameoverStr
	{
		(LONG)(g_GameoverStrState.x - g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y - g_GameoverStrState.yScale),(LONG)(g_GameoverStrState.x + g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y + g_GameoverStrState.yScale)
	};

	//現在スコア表示
	static RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	// 現在ハイスコア表示
		static RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};

	//ネクスト文字

	static RECT rectNextStr
	{
		(LONG)(g_NextStrState.x - g_NextStrState.xScale),(LONG)(g_NextStrState.y - g_NextStrState.yScale),(LONG)(g_NextStrState.x + g_NextStrState.xScale),(LONG)(g_NextStrState.y + g_NextStrState.yScale)

	};

	//ラインカウント文字
	static RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)
	};

	//ラインカウント表示文字

	static RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//ノーマルモード文字
	static RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)
	};

	//フィーバーモード文字
	static RECT rectFeverStr
	{
		(LONG)(g_FeverStrState.x - g_FeverStrState.xScale),(LONG)(g_FeverStrState.y - g_FeverStrState.yScale),(LONG)(g_FeverStrState.x + g_FeverStrState.xScale),(LONG)(g_FeverStrState.y + g_FeverStrState.yScale)
	};

	//フィーバータイマー文字
	static RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)
	};

	//フィーバータイム文字
	static RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//フィーバーゲージ文字
	static RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//落下速度レベル文字
	static RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//落下速度レベル表示文字
	static RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)

	};
	return;
}


//描画
VOID DisplayScreen(
	CustomVertex *cusV4Background, //通常背景
	CustomVertex *cusV4Frame,      //枠
	CustomVertex *cusV4FeverBackground, //フィーバー背景
	CustomVertex *cusV4FeverFrame,      //フィーバー枠

	CustomVertex *cusV4Background2, //通常背景2
	CustomVertex *cusV4Frame2,      //枠

	CustomVertex *cusV4FeverBackground2, //フィーバー背景2
	CustomVertex *cusV4FeverFrame2,      //フィーバー枠2

	CustomVertex *cusV4HoldFrame,  //ホールド枠
	CustomVertex *cusV4GaugeFrame, //フィーバーゲージ

	CustomVertex *cusV4GaugeFrame_Fiver, //フィーバーゲージフィーバー中

	CustomVertex *cusV4ScoreFrame, //スコア枠
	CustomVertex *cusV4HighScoreframe,//ハイスコア枠
	CustomVertex *cusV4GaugeBlock,    //フィーバーゲージブロック
	CustomVertex *cusV4Tetmino,       //テトリミノ
	RECT *rectGameoverStr,            //ゲームオーバー文字
	RECT *rectCurrentScoreStr,        //現在スコア文字
	RECT *rectCurrentHighScoreStr,    //現在ハイスコア文字
	RECT *rectNextStr,                 //ネクストに表示する文字
	RECT *rectCountStr,                //ラインカウント文字
	RECT *rectCountShowStr,                //ラインカウント表示文字
	RECT *rectNormalStr,                //ノーマルモード文字
	RECT *rectFeverStr,                //フィーバーモード文字
	RECT *rectFeverTimerStr,            //フィーバーモードタイマー
	RECT *rectFeverTimeShowStr,            //フィーバーモードタイム
	RECT *rectFevergaugeShowStr,         //フィーバーゲージ文字
	RECT *rectFallLevelStr,               //落下速度レベル文字
	RECT *rectFallLevelShowStr            //落下速度レベル表示文字
)
{
	g_pD3dDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET,
		D3DCOLOR_XRGB(0x00, 0x00, 0x00),
		1.0,
		0
	);

	g_pD3dDevice->BeginScene();

	//ラインの数が10以上のときフィーバー背景 10以下なら通常背景
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//フィーバー背景2表示
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverbackgroundTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground2, sizeof(CustomVertex));

		}

		else
		{
			//フィーバー背景1表示
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverbackgroundTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground, sizeof(CustomVertex));

		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//背景表示2
			g_pD3dDevice->SetTexture(0, g_pTexture[g_backgroundTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background2, sizeof(CustomVertex));

		}

		else
		{
			//背景表示1
			g_pD3dDevice->SetTexture(0, g_pTexture[g_backgroundTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background, sizeof(CustomVertex));

		}

	}



	//テトリミノ表示
	for (int column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (int row = 0; row < TETLIS_WIDTH; row++)
		{
			if ((g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9))
			{
				cusV4Tetmino->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				//一マスずれて描画
				(cusV4Tetmino + 1)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 1)->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 2)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 2)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				(cusV4Tetmino + 3)->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				(cusV4Tetmino + 3)->y = -64.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}
		}
	}


	//ラインの数が10以上のときフィーバー枠 10以下なら通常枠
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//フィーバー枠2
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverframeTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame2, sizeof(CustomVertex));
		}

		else
		{
			//フィーバー枠1
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverframeTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame, sizeof(CustomVertex));
		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//枠2
			g_pD3dDevice->SetTexture(0, g_pTexture[g_frameTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame2, sizeof(CustomVertex));

		}

		else
		{
			//枠
			g_pD3dDevice->SetTexture(0, g_pTexture[g_frameTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame, sizeof(CustomVertex));

		}

	}

	//ホールド枠
	g_pD3dDevice->SetTexture(0, g_pTexture[g_holdFrameTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HoldFrame, sizeof(CustomVertex));

	//フィーバーゲージ
	g_pD3dDevice->SetTexture(0, g_pTexture[g_gaugeTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame, sizeof(CustomVertex));

	//ハイスコア枠
	g_pD3dDevice->SetTexture(0, g_pTexture[g_scoreFrameTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4ScoreFrame, sizeof(CustomVertex));

	//スコア枠
	g_pD3dDevice->SetTexture(0, g_pTexture[g_highScoreFrameTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HighScoreframe, sizeof(CustomVertex));



	//ゲームオーバー
	if (g_showGameoverStr)
	{
		g_pFont[g_gameoverFont]->DrawText(NULL, GAMEOVER, -1, rectGameoverStr, NULL, GAMEOVER_COLOR);
	}

	//現在スコア
	g_pFont[g_currentscoreFont]->DrawText(NULL, g_scoreArray, -1, rectCurrentScoreStr, NULL, NORMAL_COLOR);

	//現在ハイスコア
	g_pFont[g_currenthighscoreFont]->DrawText(NULL, HIGHSCORESHOW, -1, rectCurrentHighScoreStr, NULL, HIGHSCORE_COLOR);

	//フィーバーゲージ文字
	g_pFont[g_fevergaugeshowFont]->DrawText(NULL, FEVERGAUGE, -1, rectFevergaugeShowStr, NULL, GAMEOVER_COLOR);

	//落下速度レベル文字
	g_pFont[g_falllevelFont]->DrawText(NULL, g_LevelArray, -1, rectFallLevelStr, NULL, FEVERTIMER_COLOR);

	//落下速度レベル表示文字
	g_pFont[g_falllevelshowFont]->DrawText(NULL, FALLLEVEL, -1, rectFallLevelShowStr, NULL, FEVERTIMER_COLOR);


	//ラインの数が10以上のとき赤文字 10以下なら黒文字 フィーバーモード文字表示
	if (g_lineTotalCount >= 10)
	{
		//ネクスト文字
		g_pFont[g_nextFont]->DrawText(NULL, NEXT, -1, rectNextStr, NULL, FEVER_COLOR);

		//フィーバーモード文字
		g_pFont[g_feverFont]->DrawText(NULL, FEVERMODE, -1, rectFeverStr, NULL, FEVER_COLOR);

		//フィーバータイマー文字
		g_pFont[g_fevertimerFont]->DrawText(NULL, g_feverTimerArray, -1, rectFeverTimerStr, NULL, FEVER_COLOR);

		//フィーバータイム文字
		g_pFont[g_fevertimeshowFont]->DrawText(NULL, FEVERTIME, -1, rectFeverTimeShowStr, NULL, FEVER_COLOR);

	}

	else
	{
		//ラインカウント文字
		g_pFont[g_countFont]->DrawText(NULL, g_countArray, -1, rectCountStr, NULL, NORMAL_COLOR);


		//ラインカウント表示文字
		g_pFont[g_countFont]->DrawText(NULL, LINECOUNT, -1, rectCountShowStr, NULL, NORMAL_COLOR);


		//ネクスト文字
		g_pFont[g_nextFont]->DrawText(NULL, NEXT, -1, rectNextStr, NULL, NORMAL_COLOR);

		//ホールド枠文字
		//g_pFont[g_holdFont]->DrawText(NULL, HOLD, -1, rectHoldStr, NULL, NORMAL_COLOR);

		//ノーマルモード文字
		g_pFont[g_normalFont]->DrawText(NULL, NORMALMODE, -1, rectNormalStr, NULL, NORMALMODE_COLOR);

	}





	//ホールド表示
	for (int coordinateY = 0; coordinateY < 4; coordinateY++)
	{
		for (int coordinateX = 0; coordinateX < 4; coordinateX++)
		{
			if (g_holdBoard[coordinateY][coordinateX] != -1)
			{
				cusV4Tetmino->x = 65.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino->y = 80.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 1)->x = 65.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 1)->y = 80.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 2)->x = 65.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 2)->y = 80.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				(cusV4Tetmino + 3)->x = 65.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				(cusV4Tetmino + 3)->y = 80.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}

			//ネクスト
			if (g_nextBoard[coordinateY][coordinateX] != -1)
			{
				cusV4Tetmino->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino->y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 1)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 1)->y = 70.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 2)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 2)->y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				(cusV4Tetmino + 3)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				(cusV4Tetmino + 3)->y = 70.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}


			//ネクストネクスト
			if (g_nextNextBoard[coordinateY][coordinateX] != -1)
			{
				cusV4Tetmino->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino->y = 150.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 1)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 1)->y = 150.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 2)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 2)->y = 150.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				(cusV4Tetmino + 3)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				(cusV4Tetmino + 3)->y = 150.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}

			//ネクストネクストネクスト
			if (g_nextNextNextBoard[coordinateY][coordinateX] != -1)
			{
				cusV4Tetmino->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino->y = 230.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 1)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 1)->y = 230.f + coordinateY * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				(cusV4Tetmino + 2)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
				(cusV4Tetmino + 2)->y = 230.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				(cusV4Tetmino + 3)->x = 670.f + coordinateX * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				(cusV4Tetmino + 3)->y = 230.f + coordinateY * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
				g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
			}
		}
	}


	////テトリミノ表示
	//for (int column = 0; column < TETLIS_HEIGHT; column++)
	//{
	//	for (int row = 0; row < TETLIS_WIDTH; row++)
	//	{
	//		if ((g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9))
	//		{
	//			cusV4Tetmino->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
	//			cusV4Tetmino->y = -72.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
	//			//一マスずれて描画
	//			(cusV4Tetmino + 1)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
	//			(cusV4Tetmino + 1)->y = -72.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
	//			(cusV4Tetmino + 2)->x = 260.f + row * (g_tetminoState.xScale * 2) + g_tetminoState.xScale;
	//			(cusV4Tetmino + 2)->y = -72.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
	//			(cusV4Tetmino + 3)->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
	//			(cusV4Tetmino + 3)->y = -72.f + column * (g_tetminoState.yScale * 2) + g_tetminoState.yScale;
	//			g_pD3dDevice->SetTexture(0, g_pTexture[g_tetminoTex]);
	//			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Tetmino, sizeof(CustomVertex));
	//		}
	//	}
	//}

	//フィーバーゲージブロック
	if (g_lineTotalCount != 0)
	{
		switch (g_lineTotalCount)
		{

		case 1:

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			break;

		case 2:

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);


			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 3:

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));



			break;

		case 4:

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 5:

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			break;

		case 6:

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 7:
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 8:
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			break;

		case 9:
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			break;

		case 10:
			/*g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

			cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);
			(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);
			(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);
			(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);

			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));
*/

			g_pD3dDevice->SetTexture(0, g_pTexture[g_gaugeFiverTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame_Fiver, sizeof(CustomVertex));

			break;

		default:
			break;

		}

		if (/*g_lineTotalCount <= 9 && */g_lineTotalCount >= 10)
		{
				/*g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));


				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 2);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 4);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 6);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 8);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 10);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 12);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 14);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 16);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));

				cusV4GaugeBlock->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);
				(cusV4GaugeBlock + 1)->y = (g_GaugeBlockState.y - g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);
				(cusV4GaugeBlock + 2)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);
				(cusV4GaugeBlock + 3)->y = (g_GaugeBlockState.y + g_GaugeBlockState.yScale) - (g_GaugeBlockState.yScale * 18);

				g_pD3dDevice->SetTexture(0, g_pTexture[g_feverBlockTex]);
				g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeBlock, sizeof(CustomVertex));
*/
			g_pD3dDevice->SetTexture(0, g_pTexture[g_gaugeFiverTex]);
			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame_Fiver, sizeof(CustomVertex));

		}
	}

	g_pD3dDevice->EndScene();

	return;
}
