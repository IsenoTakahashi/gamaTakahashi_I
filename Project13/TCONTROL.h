#ifndef TCONTROL
#define TCONTROL

#include <windows.h>
#include <stdio.h>
#include <dinput.h>

//テトリスなどの操作に関する関数
VOID Control(VOID);

//テトリスボードを初期化する関数
VOID InitTetlisBoard(VOID);

//テトリスボードバッファーを初期化する関数
VOID InitTetlisBoardBuf(VOID);



//フィーバーゲージの中身を更新する関数
VOID UpdateFeverGauge(INT *lineCount,INT g_feverBlock);

//消したラインの合計でフィーバーゲージブロックを表示する関数
VOID FeverGaugeBlock(VOID);

//ホールド、ネクスト、ネクストネクストを初期化する関数
VOID InitNextAndFever(BOOL *isNewGame);

//ホールド、ネクスト、ネクストネクストボードの中身を更新する関数
VOID UpdateHoldNextNextNextBoard(VOID);

//テトリス配列バッファーに可動テトリミノを除いたテトリス配列の要素を同期させる関数
VOID SynchroTetlisBoardBufToTetlisBoard(VOID);

//テトリス配列に可動テトリミノを同期させる関数
VOID SynchroTetlisBoardToMovMinoNumOfArBuf(INT currentTetmino);

//テトリスに関するデータを初期状態に戻す関数
VOID ReturnToInitialStateWithTetlis(
	BOOL *isGameover,
	BOOL *canCreate,
	BOOL *canInputRA,
	BOOL *canInputLA,
	BOOL *canInputDA,
	BOOL *canInputR,
	BOOL *canInputL,
	BOOL *canInputSpace,
	BOOL *canHold,
	BOOL *wasHold,
	BOOL *canSetStatrTime,
	INT *rACount,
	INT *lACount,
	INT *dACount,
	INT *stopCount,
	INT *downCount,
	INT *scoreBuf,
	INT *currentTetmino,
	INT *minoIRoatationCount,
	INT *g_lineTotalCount,
	DWORD *g_elapsedTime,
	DWORD *g_startTime,
	INT *FeverTimer,
	INT *FallSpeedLevel,
	INT *FlamePerDown
);

//テトリミノを生成に関する関数
VOID CreateTetlimino(
	INT currentTetmino,
	BOOL *canInputLA,
	BOOL *canInputDA,
	BOOL *canInputRA,
	BOOL *canInputR,
	BOOL *canInputL,
	BOOL *canInputSpace,
	BOOL *wasHold,
	INT *stopCount,
	INT *downCount,
	INT *minoIRoatationCount,
	BOOL *canCreate
);

//キー入力をカウントをとり可能にする関数
VOID CountToMakeFlagTrue(BOOL *canInputLA, INT *lACount);

//テトリミノをホールドすることに関する関数
VOID HoldTetlimino(
	BOOL *canHold,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *wasHold
);

//テトリミノのX軸方向の移動に関する関数
VOID ShiftTetliminoX(INT shiftX, BOOL *canInputRA);

//テトリミノの回転に関する関数(右回転)
VOID RotateTetliminoRight(BOOL *minoIRoatationCount, INT currentTetmino);

//テトリミノの回転に関する関数(左回転)
VOID RotateTetliminoLeft(BOOL *minoIRoatationCount, INT currentTetmino);

//テトリミノのY軸方向の移動に関する関数
VOID DownTetlimino(BOOL *canInputDA);

//テトリミノのハードドロップに関する関数
//VOID HardDropTetlimino(VOID);

//テトリミノの自動落下に関する関数
VOID CountToDawnTetlimino(INT *downCount, INT *FallSpeedLevel, INT *FlamePerDown);

//テトリミノ停止に関する関数
VOID CountToStopTetlimino(
	INT *stopCount,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *canHold,
	BOOL *wasHold
);

//そろったテトリスのラインを消しカウントをとる関数
VOID DeleteAndCountFilledLine(INT *lineCount,INT *g_lineTotalCount);

//消されたテトリスのライン部分にずらす関数
VOID ShiftTetlisLine(VOID);

//テトリスのスコアに関する関数
VOID GetScoreByLineCount(INT lineCount, INT *scoreBuf);

//ゲームオーバーか、否かを調べるする関数
VOID CheckGameover(BOOL *isGameover);

//フィーバーモードの時間関数 フィーバーモードが終わるとFallSpeedLevelが +1、FlamePerDownが-2にする
VOID FeverTime(INT *g_lineTotalCount, DWORD *g_elapsedTime,DWORD *g_startTime, BOOL *canSetStartTime,INT *FeverTimer, INT *FallSpeedLevel, INT *FlamePerDown);

//フィーバーモードの開始時間関数
VOID SetFeverStartTime(DWORD *g_startTime,BOOL *canSetStartTime);
#endif
