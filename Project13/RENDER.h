#ifndef RENDER
#define RENDER

#include <windows.h>
#include <d3dx9.h>

//描画に関する関数
VOID Render(VOID);

//総合的な視点の設定をする関数
VOID SetViewPointOverall(VOID);

//総合的な視野角の設定をする関数
VOID SetFocusOfViewOverall(VOID);

//画面を表示させる関数
VOID DisplayScreen(
	CustomVertex *cusV4Background, //通常背景1
	CustomVertex *cusV4Frame,      //枠1

	CustomVertex *cusV4Background2, //通常背景2
	CustomVertex *cusV4Frame2,      //枠2

	CustomVertex *cusV4FeverBackground, //フィーバー背景1
	CustomVertex *cusV4FeverFrame,      //フィーバー枠1

	CustomVertex *cusV4FeverBackground2, //フィーバー背景2
	CustomVertex *cusV4FeverFrame2,      //フィーバー枠2

	CustomVertex *cusV4HoldFrame,  //ホールド枠
	CustomVertex *cusV4GaugeFrame, //フィーバーゲージ

	CustomVertex *cusV4GaugeFrame_Fiver,//フィーバーゲージフィーバー中

	CustomVertex *cusV4ScoreFrame, //スコア枠
	CustomVertex *cusV4HighScoreframe,//ハイスコア枠
	CustomVertex *cusV4GaugeBlock,    //フィーバーゲージブロック
	CustomVertex *cusV4Tetmino,       //テトリミノ
	RECT *rectGameoverStr,            //ゲームオーバー文字
	RECT *rectCurrentScoreStr,        //現在スコア文字
	RECT *rectCurrentHighScoreStr,    //現在ハイスコア文字
	//RECT *rectHoldStr,                //ホールド枠に表示する文字
	RECT *rectNextStr,                 //ネクストに表示する文字
	RECT *rectCountStr,                //ラインカウント文字
	RECT *rectCountShowStr,                //ラインカウント表示文字
	RECT *rectNormalStr,                //ノーマルモード文字
	RECT *rectFeverStr,                //フィーバーモード文字
	RECT *rectFeverTimerStr,            //フィーバーモードタイマー
	RECT *rectFeverTimeShowStr,          //フィーバーモードタイム
	RECT *rectFevergaugeShowStr,         //フィーバーゲージ文字
	RECT *rectFallLevelStr,               //落下速度レベル文字
	RECT *rectFallLevelShowStr            //落下速度レベル表示文字

);

#endif
