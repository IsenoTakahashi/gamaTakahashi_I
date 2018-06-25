#include "STATE.h"
#include "INITIALIZE.h"
#include "TCONTROL.h"
#include <time.h>


//テトリスなどの操作に関する関数
VOID Control(VOID)
{
	//time_t t = time(0);

  //srand(t);

	//キーデバイスに入っている情報を読み取る準備
	HRESULT hr = g_pDKeyDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		//キー入力情報のバッファー
		BYTE diks[256];

		//入力された情報を読み取る
		g_pDKeyDevice->GetDeviceState(sizeof(diks), &diks);

		static BOOL canInputLA = true,
			canInputDA = true,
			canInputRA = true,
			canInputR = true,
			canInputL = true,
			canInputSpace = true,
			isGameover = false,
			isNewGame = true,
			canHold = true,
			wasHold = false,
			canCreate = true,
			canSetStartTime = true;

		//生成されるのテトリミノ種類を決める
		static INT 
			rACount = 0,
			lACount = 0,
			dACount = 0,
			stopCount = 0,
			downCount = 0,
			scoreBuf = 0,
			minoIRoatationCount = 0,

			prevEKeyState,              //右回転Eキー入力状態を保存

			prevTEN9KeyState,           //右回転テンキー9入力状態を保存

			prevQKeyState,              //左回転Qキー入力状態を保存

			prevTEN7KeyState,           //左回転テンキー7入力状態を保存

			prevRKeyState,              //ホールドRキー入力状態を保存

			prevTENplusKeyState,        //ホールドテンキー + 入力状態を保存

			currentTetmino = rand() % 7;

		INT lineCount = 0;

		INT FeverTimer = 0;

		
		//INT lineTotalCount = 0;

		INT LEFT[2] = { 0,diks[DIK_A] & 0x80 },             //左移動 Aキー
			TEN_LEFT[2] = { 0,diks[DIK_NUMPAD4] & 0x80 },      //左移動 テンキー4

			DOWN[2] = { 0,diks[DIK_S] & 0x80 },             //下移動 Sキー
			TEN_DOWN[2] = { 0,diks[DIK_NUMPAD2] & 0x80 },   //下移動 テンキー2

			RIGHT[2] = { 0,diks[DIK_D] & 0x80 },            //右移動 Dキー
			TEN_RIGHT[2] = { 0,diks[DIK_NUMPAD6] & 0x80 };   //右移動 テンキー6
			

		//テトリス配列にテトリス配列バッファーの要素全てをコピーしている
		memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

		//リセットボタン、初期状態に戻す
		if (diks[DIK_BACK] & 0x80)
		{
	
			//フラグ、カウント、配列を初期状態に戻しUpdateHoldNextNextNextBoardを用いる
			ReturnToInitialStateWithTetlis(
				&isGameover,
				&canCreate,
				&canInputRA,
				&canInputLA,
				&canInputDA,
				&canInputR,
				&canInputL,
				&canInputSpace,
				&canHold,
				&wasHold,
				&canSetStartTime,
				&rACount,
				&lACount,
				&dACount,
				&stopCount,
				&downCount,
				&scoreBuf,
				&currentTetmino,
				&minoIRoatationCount,
				&g_lineTotalCount,
				&g_elapsedTime,
				&g_startTime,
				&FeverTimer,
				&FallSpeedLevel,
				&FlamePerDown
			);
		}

		sprintf(g_countArray, "%d", g_lineTotalCount);

		sprintf(g_feverTimerArray, "%d", FeverTimer);

		sprintf(g_LevelArray, "%d", FallSpeedLevel);

		//g_lineTotalCountが10以上のときフィーバーモードの開始時間をセット
		if (g_lineTotalCount >= 10) 
		{
			SetFeverStartTime(&g_startTime, &canSetStartTime);
			FeverTime(&g_lineTotalCount, &g_elapsedTime, &g_startTime, &canSetStartTime,&FeverTimer,&FallSpeedLevel,&FlamePerDown);

		}

		sprintf(g_LevelArray, "%d", FallSpeedLevel);


		if (isGameover)
		{
			//ゲームオーバー時に文字列を表示させる
			g_showGameoverStr = true;
		}
		else
		{
			if (isNewGame)
			{

				//ニューゲーム(一番最初のフレーム)時にはg_feverBlock、g_nextとg_nextNext、g_nextNextnextは初期化されていないので初期化し、isNewGameをfalseにする
				InitNextAndFever(&isNewGame);

				InitTetlisBoard();
				InitTetlisBoardBuf();
			}

			for (g_tetminoNum = 0; g_tetminoNum < 7; g_tetminoNum++)
			{
				if (g_tetmino[g_tetminoNum].number == currentTetmino)
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();


					//g_canCreateを確認しtrueならばg_movMinoNumOfArBufにcurrentTetminoと同じ種類のテトリミノ初期座標を代入し、キー入力のフラグ、
					//I型のテトリミノが何回転したかを確認するカウント、ホールドが行われたか否かのフラグを初期状態に戻し、g_canCreateをfalseにする
					CreateTetlimino(
						currentTetmino,
						&canInputLA,
						&canInputDA,
						&canInputRA,
						&canInputR,
						&canInputL,
						&canInputSpace,
						&wasHold,
						&stopCount,
						&downCount,
						&minoIRoatationCount,
						&canCreate
					);

					break;
				}
			}


			//フラグがfalseならばカウントを1増やし、一定値ならばフラグはtrueに変えカウントを初期状態にする
			CountToMakeFlagTrue(&canInputLA, &lACount);
			CountToMakeFlagTrue(&canInputRA, &rACount);
			CountToMakeFlagTrue(&canInputDA, &dACount);


			//ホールド

			//前フレーム時にRキー、+キーが押されていた場合この処理を通さない、
			//とすることによって連続したフレーム毎にこの処理がされるのを防いでいる

			//Rキー
			if (!(prevRKeyState))
			{
				if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();

					
					//canHoldがtrueならばg_holdに現在のテトリミノの値を代入し、すでに-1(空欄)以外が入っていた場合currentTetminoにg_holdの値を入れる、
					//その後g_canCreateをtrueにしUpdateHoldNextNextNextBoardを呼び出す
					HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
				}
			}

			//+キー
			if (!(prevTENplusKeyState))
			{
				if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();


					//canHoldがtrueならばg_holdに現在のテトリミノの値を代入し、すでに-1(空欄)以外が入っていた場合currentTetminoにg_holdの値を入れる、
					//その後g_canCreateをtrueにしUpdateHoldNextNextNextBoardを呼び出す
					HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
				}
			}

			//ホールドが行われていた場合新しくテトリミノを生成するので、この処理を通さない
			if (!(wasHold))
			{
				if (RIGHT[canInputRA] || TEN_RIGHT[canInputRA])
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();


					//g_movMinoNumOfArBufに引数を足した配列番号をg_tetlisBoardBufで参照し、空欄だった場合g_movMinoNumOfArBufに引数を足した値を代入する
					ShiftTetliminoX(1, &canInputRA);
				}

				if (LEFT[canInputLA] || TEN_LEFT[canInputLA])
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();

					ShiftTetliminoX(-1, &canInputLA);
				}

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();


				//右回転

				//前フレーム時にEキー、テンキー9が押されていたならば、この処理を通さない、
				//とすることによって連続で同じ処理がされることを防いでいる

				//Eキー
				if (!(prevEKeyState))
				{
					if (diks[DIK_E] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
						//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
						//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
						RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
					}
				}

				//テンキー9
				if (!(prevTEN9KeyState))
				{
					if (diks[DIK_NUMPAD9] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
						//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
						//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
						RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
					}
				}





				//左回転

				//前フレーム時にQキー、テンキー7が押されていたならば、この処理を通さない、
				//とすることによって連続で同じ処理がされることを防いでいる

				//Qキー
				if (!(prevQKeyState))
				{
					if (diks[DIK_Q] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
						//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
						//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
						RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
					}
				}

				//テンキー7
				if (!(prevTEN7KeyState))
				{
					if (diks[DIK_NUMPAD7] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
						//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
						//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
						RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
					}
				}




				if (DOWN[canInputDA] || TEN_DOWN[canInputDA])
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();

					
					//g_movMinoNumOfArBufのY方向に１足した配列を用いてg_tetlisBoardBufを参照し、空欄の場合移動を行う
					DownTetlimino(&canInputDA);
				}

				////ハードドロップ　テトリミノのブロックを一個づつ下方を確認し、そこが空欄ではない場合、そこから1つ上にワープさせる
				//if (diks[DIK_UP] & 0x80)
				//{
				//	memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				//	SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				//	SynchroTetlisBoardBufToTetlisBoard();

				//	
				//	//ループカウンタを用いg_tetlisBoardBufを参照し、空欄ではなかった場合g_movMinoNumOfArBufを
				//	//ループカウンタ-1の場所にテトリミノを移動させる
				//	HardDropTetlimino();
				//}

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//テトリミノの下方を確認し、空欄だった場合カウントをとり、FLAME_PER_DOWNに達した場合一つ下に移動させる
				
				//g_movMinoNumOfArBuf+1した配列番号を用いてg_tetlisBoardBufを参照し、空欄だった場合カウントを1増やし、
				//一定値ならばg_movMinoNumOfArBufに１を足し、カウントを初期状態にする
				CountToDawnTetlimino(&downCount, &FallSpeedLevel, &FlamePerDown);

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				/*テトリミノ下方を確認し、そこが空欄ではない場合カウントをとり、FLAME_PER_STOPに達した場合
				可動テトリミノのナンバーに10を足し(簡単に可動か非可動を判別するため)、新しい可動テトリミノを生成する*/
				
				//g_movMinoNumOfArBuf+1をした配列番号を用いg_tetlisBoardBufを参照し、空欄(-1)以外が入っていた場合
				//カウントを１増やし、一定値ならばcurrentTetmino + 10をg_tetlisBoardに代入し、
				//テトリミノを生成できるか否か、ホールドができるか否かのフラグをtrue、
				//ホールドが行われたかのフラグをfalseにし、currentTetminoにg_next、g_nextにg_nextNext、
				//g_nextNextにg_nextNextnextを代入して、
				//g_nextNextnextにテトリミノ番号の範囲の乱数を代入する
				CountToStopTetlimino(&stopCount, &currentTetmino, &canCreate, &canHold, &wasHold);

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();


				//そろっている列があるか確認しカウントをとる
				
				//g_tetlisBoardBuf中身を確認し一列が空欄(-1)以外の場合カウントをとり空欄にする
				DeleteAndCountFilledLine(&lineCount, &g_lineTotalCount);

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//そろった列を空欄にして下にずらしている
				
				//g_tetlisBoardBufを参照し、空欄(-1)以外の場合ループカウンタ+1した配列番号を用い、再度参照し、
				//一列全て空欄の場合ループカウンタ+1の配列番号にコピーし、コピー元を空欄に書き換える
				ShiftTetlisLine();
			}

			memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();


			//キー入力状態を保存

			//右回転
			prevEKeyState = diks[DIK_E] & 0x80;
			prevTEN9KeyState=diks[DIK_NUMPAD9] & 0x80;

			//左回転
			prevQKeyState = diks[DIK_Q] & 0x80;
			prevTEN7KeyState = diks[DIK_NUMPAD7] & 0x80;

			//ホールド
			prevRKeyState = diks[DIK_R] & 0x80;
			prevTENplusKeyState= diks[DIK_NUMPADPLUS] & 0x80;
			

			//lineCountの値によってscoreBufの増やす値を変え、文字列にしg_scoreArrayに代入する
			GetScoreByLineCount(lineCount, &scoreBuf);

			//フィーバーゲージの中身を更新する関数
			UpdateFeverGauge(&lineCount, g_feverBlock);

			memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			
			//プレイ時の見える範囲内で一番上の部分に非可動テトリミノがある場合isGameoverをtrueにする
			CheckGameover(&isGameover);

		}
	}

	return;
}


//テトリスボードを初期化
//－1は空欄を表し、先に全ての配列の中身を空欄にすることにより、
//壁(9)を上から塗りつぶすだけで表が完成する
VOID InitTetlisBoard(VOID)
{
	for (INT column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (INT row = 0; row < TETLIS_WIDTH; row++)
		{

			g_tetlisBoard[column][row] = -1;
			if (row == TETLIS_WIDTH - 12 || row == TETLIS_WIDTH - 1)
			{
				g_tetlisBoard[column][row] = 9;
			}
			if (column == TETLIS_HEIGHT-1)
			{
				g_tetlisBoard[column][row] = 9;
			}
		}
	}

	return;
}


//テトリスボードバッファーを初期化
//可動テトリミノ(動いてるやつ)をテトリスボードバッファーに入れないようにすることにより、
//回転、移動などの際、可動テトリミノを考慮せずとも良い
VOID InitTetlisBoardBuf(VOID)
{

	for (INT column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (INT row = 0; row < TETLIS_WIDTH; row++)
		{
			g_tetlisBoardBuf[column][row] = -1;
			if (row == TETLIS_WIDTH - 12 || row == TETLIS_WIDTH - 1)
			{
				g_tetlisBoardBuf[column][row] = 9;
			}
			if (column == TETLIS_HEIGHT - 1)
			{
				g_tetlisBoardBuf[column][row] = 9;
			}
		}
	}

	return;
}


//ホールド、ネクスト、ネクストネクストボードの中身を更新する関数
//テトリミノの初期座標(生成されるときの座標)を用いるため、x座標を-4ずらすことでネクスト等の表との整合性をとり、
//ホールドに入っている値によって、入れるテトリミノを変える
VOID UpdateHoldNextNextNextBoard(VOID)
{
	for (INT column = 0; column < 4; column++)
	{
		for (INT row = 0; row < 4; row++)
		{
			g_nextNextNextBoard[column][row] = -1;
			g_nextNextBoard[column][row] = -1;
			g_holdBoard[column][row] = -1;
			g_nextBoard[column][row] = -1;
			

			if (0 <= g_hold && g_hold <= 6)
			{
				if (((column == g_tetmino[g_hold].yx[0][0]) && (row == g_tetmino[g_hold].yx[0][1] - 4)) ||
					((column == g_tetmino[g_hold].yx[1][0]) && (row == g_tetmino[g_hold].yx[1][1] - 4)) ||
					((column == g_tetmino[g_hold].yx[2][0]) && (row == g_tetmino[g_hold].yx[2][1] - 4)) ||
					((column == g_tetmino[g_hold].yx[3][0]) && (row == g_tetmino[g_hold].yx[3][1] - 4)))
				{
					g_holdBoard[column][row] = g_hold;
				}
			}

			if (0 <= g_next && g_next <= 6)
			{
				if (((column == g_tetmino[g_next].yx[0][0]) && (row == g_tetmino[g_next].yx[0][1] - 4)) ||
					((column == g_tetmino[g_next].yx[1][0]) && (row == g_tetmino[g_next].yx[1][1] - 4)) ||
					((column == g_tetmino[g_next].yx[2][0]) && (row == g_tetmino[g_next].yx[2][1] - 4)) ||
					((column == g_tetmino[g_next].yx[3][0]) && (row == g_tetmino[g_next].yx[3][1] - 4)))
				{
					g_nextBoard[column][row] = g_next;
				}
			}

			if (0 <= g_nextNext && g_nextNext <= 6)
			{
				if (((column == g_tetmino[g_nextNext].yx[0][0]) && (row == g_tetmino[g_nextNext].yx[0][1] - 4)) ||
					((column == g_tetmino[g_nextNext].yx[1][0]) && (row == g_tetmino[g_nextNext].yx[1][1] - 4)) ||
					((column == g_tetmino[g_nextNext].yx[2][0]) && (row == g_tetmino[g_nextNext].yx[2][1] - 4)) ||
					((column == g_tetmino[g_nextNext].yx[3][0]) && (row == g_tetmino[g_nextNext].yx[3][1] - 4)))
				{
					g_nextNextBoard[column][row] = g_nextNext;
				}
			}

			if (0 <= g_nextNextnext && g_nextNextnext <= 6)
			{
				if (((column == g_tetmino[g_nextNextnext].yx[0][0]) && (row == g_tetmino[g_nextNextnext].yx[0][1] - 4)) ||
					((column == g_tetmino[g_nextNextnext].yx[1][0]) && (row == g_tetmino[g_nextNextnext].yx[1][1] - 4)) ||
					((column == g_tetmino[g_nextNextnext].yx[2][0]) && (row == g_tetmino[g_nextNextnext].yx[2][1] - 4)) ||
					((column == g_tetmino[g_nextNextnext].yx[3][0]) && (row == g_tetmino[g_nextNextnext].yx[3][1] - 4)))
				{
					g_nextNextNextBoard[column][row] = g_nextNextnext;
				}
			}
		}
	}

	return;
}


//可動テトリミノ以外をg_tetlisBoardBufに同期させている 
VOID SynchroTetlisBoardBufToTetlisBoard(VOID)
{
	for (INT column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (INT row = 0; row < TETLIS_WIDTH; row++)
		{
			if ((0 <= g_tetlisBoard[column][row]) && (g_tetlisBoard[column][row] <= 6))
			{
				g_tetlisBoardBuf[column][row] = -1;
			}
			else
			{
				g_tetlisBoardBuf[column][row] = g_tetlisBoard[column][row];
			}
		}
	}

	return;
}


//テトリス配列に可動テトリミノを同期させる関数
//g_tetlisBoardにg_movMinoNumOfArBufを同期させている
VOID SynchroTetlisBoardToMovMinoNumOfArBuf(INT currentTetmino)
{
	for (INT block = 0; block < 4; block++)
	{
		g_tetlisBoard[g_movMinoNumOfArBuf.YX[block][0]][g_movMinoNumOfArBuf.YX[block][1]] = currentTetmino;
	}

	return;
}


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
	BOOL *canSetStartTime,
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
)
{
	g_showGameoverStr = false;
	*isGameover = false;
	*canCreate = true;
	*canInputRA = true;
	*canInputLA = true;
	*canInputDA = true;
	*canInputR = true;
	*canInputSpace = true;
	*canHold = true;
	*wasHold = false;

	*canSetStartTime = true;

	*rACount = 0;
	*lACount = 0;
	*dACount = 0;
	*stopCount = 0;
	*downCount = 0;
	*scoreBuf = 0;

	*FeverTimer = 0;

	*FallSpeedLevel = 1;
	*FlamePerDown = 55;

	*g_lineTotalCount = 0;
	*g_elapsedTime = 0;
	*g_startTime = 0;

	g_hold = -1;
	g_next = rand() % 7;
	g_nextNext = rand() % 7;
	g_nextNextnext = rand() % 7;
	*currentTetmino = rand() % 7;
	*minoIRoatationCount = 0;

	
	InitTetlisBoardBuf();
	UpdateHoldNextNextNextBoard();
	memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

	return;
}


//テトリミノを生成に関する関数
VOID CreateTetlimino(INT currentTetmino, BOOL *canInputLA, BOOL *canInputDA, BOOL *canInputRA,
	BOOL *canInputR,BOOL *canInputL, BOOL *canInputSpace, BOOL *wasHold, INT *stopCount, INT *downCount, INT *minoIRoatationCount, BOOL *canCreate)
{
	if (*canCreate)
	{
		for (INT block = 0; block < 4; block++)
		{
			for (INT YX = 0; YX < 2; YX++)
			{
				g_movMinoNumOfArBuf.YX[block][YX] = g_tetmino[currentTetmino].yx[block][YX];
			}
		}

		UpdateHoldNextNextNextBoard();
		*canInputLA = true;
		*canInputDA = true;
		*canInputRA = true;
		*canInputR = true;
		*canInputSpace = true;
		*wasHold = false;
		*stopCount = 0;
		*downCount = 0;
		*minoIRoatationCount = 0;
		*canCreate = false;
	}

	return;
}


//キー入力をカウントをとり可能にする関数
VOID CountToMakeFlagTrue(BOOL *canInputLA, INT *lACount)
{
	if (*canInputLA == false)
	{
		*lACount += 1;
		if (*lACount == SHIFT_FRAME_COUNTER)
		{
			*canInputLA = true;
			*lACount = 0;
		}
	}

	return;
}


//ホールド、ネクスト、ネクストネクストを初期化する関数
VOID InitNextAndFever(BOOL *isNewGame)
{
	g_next = rand() % 7;
	g_nextNext = rand() % 7;
	g_nextNextnext = rand() % 7;
	g_feverBlock = 0; //フィーバーブロックの初期化
	*isNewGame = false;

	return;
}


//テトリミノをホールドすることに関する関数
VOID HoldTetlimino(BOOL *canHold, INT *currentTetmino, BOOL *canCreate, BOOL *wasHold)
{
	if (*canHold)
	{
		if (g_hold == -1)
		{
			g_hold = *currentTetmino;
			*currentTetmino = rand() % 7;
		}
		else
		{
			*currentTetmino = g_hold;
			g_hold = g_tetmino[g_tetminoNum].number;
			*canHold = false;
		}

		*wasHold = true;
		*canCreate = true;

		UpdateHoldNextNextNextBoard();
	}

	return;
}


//テトリミノのX軸方向の移動に関する関数
VOID ShiftTetliminoX(INT shiftX, BOOL *canInputRA)
{
	if ((g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[0][0]][g_movMinoNumOfArBuf.YX[0][1] + shiftX] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[1][0]][g_movMinoNumOfArBuf.YX[1][1] + shiftX] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[2][0]][g_movMinoNumOfArBuf.YX[2][1] + shiftX] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[3][0]][g_movMinoNumOfArBuf.YX[3][1] + shiftX] == -1))
	{
		for (INT block = 0; block < 4; block++)
		{
			g_movMinoNumOfArBuf.YX[block][1] += shiftX;
		}

		*canInputRA = false;
	}

	return;
}


//右回転

//テトリミノの回転に関する関数
VOID RotateTetliminoRight(INT *minoIRoatationCount, INT currentTetmino)
{
	INT swap[4];
	INT backupY2X2[2] = { g_movMinoNumOfArBuf.YX[2][0], g_movMinoNumOfArBuf.YX[2][1] };
	*minoIRoatationCount = (*minoIRoatationCount > 3) ? 0 : *minoIRoatationCount;
	if (currentTetmino == 0)
	{
		for (INT block = 0; block < 4; block++)
		{
			switch (*minoIRoatationCount)
			{
			case 0:
				g_movMinoNumOfArBuf.YX[block][0] += 1;
				break;
			case 1:
				g_movMinoNumOfArBuf.YX[block][1] -= 1;
				break;
			case 2:
				g_movMinoNumOfArBuf.YX[block][0] -= 1;
				break;
			case 3:
				g_movMinoNumOfArBuf.YX[block][1] += 1;
				break;
			}
			backupY2X2[0] = g_movMinoNumOfArBuf.YX[2][0];
			backupY2X2[1] = g_movMinoNumOfArBuf.YX[2][1];
		}
	}
	if (currentTetmino != 6)
	{
		if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1)
		{
			for (INT block = 0; block < 4; block++)
			{
				swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
				g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
				g_movMinoNumOfArBuf.YX[block][0] = swap[block];
			}
			*minoIRoatationCount += 1;
		}
		else
		{
			if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1)
			{
				for (INT block = 0; block < 4; block++)
				{
					swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
					g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] + 1;
					g_movMinoNumOfArBuf.YX[block][0] = swap[block];
				}
				*minoIRoatationCount += 1;
			}
			else
			{
				if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1)
				{
					for (INT block = 0; block < 4; block++)
					{
						swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
						g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 1;
						g_movMinoNumOfArBuf.YX[block][0] = swap[block];
					}
					*minoIRoatationCount += 1;
				}
				else
				{
					if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1)
					{
						for (INT block = 0; block < 4; block++)
						{
							swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
							g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
							g_movMinoNumOfArBuf.YX[block][0] = swap[block];
						}
						*minoIRoatationCount += 1;
					}
					else
					{
						if (currentTetmino == 0)
						{
							if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1)
							{
								for (INT block = 0; block < 4; block++)
								{
									swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] - 1;
									g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + 2;
									g_movMinoNumOfArBuf.YX[block][0] = swap[block];
								}
								*minoIRoatationCount += 1;
							}
							else
							{
								if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1)
								{
									for (INT block = 0; block < 4; block++)
									{
										swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
										g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 2;
										g_movMinoNumOfArBuf.YX[block][0] = swap[block];
									}
									*minoIRoatationCount += 1;
								}
								else
								{
									for (INT block = 0; block < 4; block++)
									{
										switch (*minoIRoatationCount)
										{
										case 0:
											g_movMinoNumOfArBuf.YX[block][0] -= 1;
											break;
										case 1:
											g_movMinoNumOfArBuf.YX[block][1] += 1;
											break;
										case 2:
											g_movMinoNumOfArBuf.YX[block][0] += 1;
											break;
										case 3:
											g_movMinoNumOfArBuf.YX[block][1] -= 1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return;
}


//左回転

//g_minoIRoatationCountが３を超えていた場合0代入する、I型のテトリミノの場合g_minoIRoatationCountの値によって軸をずらす、
//X2、Y2を中心とするためにX2、Y2でそれぞれ4ブロックを引き中心を0,0に移動させる回転させる処理を行う前に
//g_tetlisBoardBufを参照して回転ができる場合に処理を行う、回転できない場合I型のテトリミノをずらした分だけ元に戻す
//テトリミノの回転に関する関数
VOID RotateTetliminoLeft(INT *minoIRoatationCount, INT currentTetmino)
{
	INT swap[4];
	INT backupY2X2[2] = { g_movMinoNumOfArBuf.YX[2][0], g_movMinoNumOfArBuf.YX[2][1] };
	*minoIRoatationCount = (*minoIRoatationCount > 3) ? 0 : *minoIRoatationCount;
	if (currentTetmino == 0)
	{
		for (INT block = 0; block < 4; block++)
		{
			switch (*minoIRoatationCount)
			{
			case 0:
				g_movMinoNumOfArBuf.YX[block][0] += 1;
				break;
			case 1:
				g_movMinoNumOfArBuf.YX[block][1] -= 1;
				break;
			case 2:
				g_movMinoNumOfArBuf.YX[block][0] -= 1;
				break;
			case 3:
				g_movMinoNumOfArBuf.YX[block][1] += 1;
				break;
			}
			backupY2X2[0] = g_movMinoNumOfArBuf.YX[2][0];
			backupY2X2[1] = g_movMinoNumOfArBuf.YX[2][1];
		}
	}
	if (currentTetmino != 6)
	{
		if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
			g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1)
		{
			for (INT block = 0; block < 4; block++)
			{
				swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
				g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
				g_movMinoNumOfArBuf.YX[block][0] = swap[block];
			}
			*minoIRoatationCount += 1;
		}
		else
		{
			if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1 &&
				g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 1] == -1)
			{
				for (INT block = 0; block < 4; block++)
				{
					swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
					g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] + 1;
					g_movMinoNumOfArBuf.YX[block][0] = swap[block];
				}
				*minoIRoatationCount += 1;
			}
			else
			{
				if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1 &&
					g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0]][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 1] == -1)
				{
					for (INT block = 0; block < 4; block++)
					{
						swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0];
						g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 1;
						g_movMinoNumOfArBuf.YX[block][0] = swap[block];
					}
					*minoIRoatationCount += 1;
				}
				else
				{
					if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1]] == -1 &&
						g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1]] == -1)
					{
						for (INT block = 0; block < 4; block++)
						{
							swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
							g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1];
							g_movMinoNumOfArBuf.YX[block][0] = swap[block];
						}
						*minoIRoatationCount += 1;
					}
					else
					{
						if (currentTetmino == 0)
						{
							if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1 &&
								g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] - 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] + 2] == -1)
							{
								for (INT block = 0; block < 4; block++)
								{
									swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] - 1;
									g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + 2;
									g_movMinoNumOfArBuf.YX[block][0] = swap[block];
								}
								*minoIRoatationCount += 1;
							}
							else
							{
								if (g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[0][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[0][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[1][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[1][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[2][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[2][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1 &&
									g_tetlisBoardBuf[(g_movMinoNumOfArBuf.YX[3][1] - backupY2X2[1]) + backupY2X2[0] + 1][(-(g_movMinoNumOfArBuf.YX[3][0] - backupY2X2[0])) + backupY2X2[1] - 2] == -1)
								{
									for (INT block = 0; block < 4; block++)
									{
										swap[block] = g_movMinoNumOfArBuf.YX[block][1] - backupY2X2[1] + backupY2X2[0] + 1;
										g_movMinoNumOfArBuf.YX[block][1] = (-(g_movMinoNumOfArBuf.YX[block][0] - backupY2X2[0])) + backupY2X2[1] - 2;
										g_movMinoNumOfArBuf.YX[block][0] = swap[block];
									}
									*minoIRoatationCount += 1;
								}
								else
								{
									for (INT block = 0; block < 4; block++)
									{
										switch (*minoIRoatationCount)
										{
										case 0:
											g_movMinoNumOfArBuf.YX[block][0] -= 1;
											break;
										case 1:
											g_movMinoNumOfArBuf.YX[block][1] += 1;
											break;
										case 2:
											g_movMinoNumOfArBuf.YX[block][0] += 1;
											break;
										case 3:
											g_movMinoNumOfArBuf.YX[block][1] -= 1;
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return;
}


//テトリミノのY軸方向の移動に関する関数
VOID DownTetlimino(BOOL *canInputDA)
{
	if ((g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[0][0] + 1][g_movMinoNumOfArBuf.YX[0][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[1][0] + 1][g_movMinoNumOfArBuf.YX[1][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[2][0] + 1][g_movMinoNumOfArBuf.YX[2][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[3][0] + 1][g_movMinoNumOfArBuf.YX[3][1]] == -1))
	{
		for (int block = 0; block < 4; block++)
		{
			g_movMinoNumOfArBuf.YX[block][0] += 1;
		}
		*canInputDA = false;
	}

	return;
}

//VOID HardDropTetlimino(VOID)
//{
//	for (INT column = 1; column < TETLIS_HEIGHT; column++)
//	{
//		if ((g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[0][0] + column][g_movMinoNumOfArBuf.YX[0][1]] != -1) ||
//			(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[1][0] + column][g_movMinoNumOfArBuf.YX[1][1]] != -1) ||
//			(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[2][0] + column][g_movMinoNumOfArBuf.YX[2][1]] != -1) ||
//			(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[3][0] + column][g_movMinoNumOfArBuf.YX[3][1]] != -1))
//		{
//			for (int block = 0; block < 4; block++)
//			{
//				g_movMinoNumOfArBuf.YX[block][0] += column - 1;
//			}
//			break;
//		}
//	}
//
//	return;
//}


//テトリミノの自動落下に関する関数
VOID CountToDawnTetlimino(INT *downCount, INT *FallSpeedLevel, INT *FlamePerDown)
{
	if ((g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[0][0] + 1][g_movMinoNumOfArBuf.YX[0][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[1][0] + 1][g_movMinoNumOfArBuf.YX[1][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[2][0] + 1][g_movMinoNumOfArBuf.YX[2][1]] == -1) &&
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[3][0] + 1][g_movMinoNumOfArBuf.YX[3][1]] == -1))
	{
		*downCount += 1;

		/*if (*FallSpeedLevel == 1) 
		{*/
			if (*downCount == *FlamePerDown)
			{
				for (int block = 0; block < 4; block++)
				{
					g_movMinoNumOfArBuf.YX[block][0] += 1;
				}

				*downCount = 0;
			}
		//}
		
	}

	return;
}


//テトリミノ停止に関する関数
VOID CountToStopTetlimino(INT *stopCount, INT *currentTetmino, BOOL *canCreate, BOOL *canHold, BOOL *wasHold)
{
	if ((g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[0][0] + 1][g_movMinoNumOfArBuf.YX[0][1]] != -1) ||
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[1][0] + 1][g_movMinoNumOfArBuf.YX[1][1]] != -1) ||
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[2][0] + 1][g_movMinoNumOfArBuf.YX[2][1]] != -1) ||
		(g_tetlisBoardBuf[g_movMinoNumOfArBuf.YX[3][0] + 1][g_movMinoNumOfArBuf.YX[3][1]] != -1))
	{
		*stopCount += 1;
		if (*stopCount == FLAME_PER_STOP)
		{
			for (INT column = 0; column < TETLIS_HEIGHT; column++)
			{
				for (INT row = 0; row < TETLIS_WIDTH; row++)
				{
					if (g_tetlisBoard[column][row] == *currentTetmino)
					{
						g_tetlisBoard[column][row] = *currentTetmino + 10;
					}
				}
			}

			for (INT block = 0; block < 4; block++)
			{
				for (INT YX = 0; YX < 2; YX++)
				{
					g_movMinoNumOfArBuf.YX[block][YX] = g_tetmino[*currentTetmino].yx[block][YX];
				}
			}

			SynchroTetlisBoardBufToTetlisBoard();

			*canCreate = true;
			*canHold = true;
			*wasHold = false;
			*stopCount = 0;
			*currentTetmino = g_next;
			g_next = g_nextNext;
			g_nextNext = g_nextNextnext;
			g_nextNextnext = rand() % 7;
		}
	}

	return;
}

//g_tetlisBoardBuf中身を確認し一列が空欄(-1)以外の場合カウントをとり空欄にする
//そろったテトリスのラインを消しカウントをとる関数
VOID DeleteAndCountFilledLine(INT *lineCount,INT *g_lineTotalCount)
{
	for (INT column = 1; column < TETLIS_HEIGHT - 1; column++)
	{
		if (g_tetlisBoardBuf[column][1] != -1 &&
			g_tetlisBoardBuf[column][2] != -1 &&
			g_tetlisBoardBuf[column][3] != -1 &&
			g_tetlisBoardBuf[column][4] != -1 &&
			g_tetlisBoardBuf[column][5] != -1 &&
			g_tetlisBoardBuf[column][6] != -1 &&
			g_tetlisBoardBuf[column][7] != -1 &&
			g_tetlisBoardBuf[column][8] != -1 &&
			g_tetlisBoardBuf[column][9] != -1 &&
			g_tetlisBoardBuf[column][10] != -1)
		{
			for (INT row = 0; row < TETLIS_WIDTH; row++)
			{
				g_tetlisBoardBuf[column][row] = -1;
				g_tetlisBoard[column][row] = -1;
			}

			*lineCount += 1;

			

			*g_lineTotalCount += 1;

			sprintf(g_countArray, "%d", *g_lineTotalCount);


			

		}
	}

	return;
}

//消されたテトリスのライン部分にずらす関数
VOID ShiftTetlisLine(VOID)
{
	for (INT column = 3; column < TETLIS_HEIGHT - 1; column++)
	{
		if (g_tetlisBoardBuf[column][1] != -1 ||
			g_tetlisBoardBuf[column][2] != -1 ||
			g_tetlisBoardBuf[column][3] != -1 ||
			g_tetlisBoardBuf[column][4] != -1 ||
			g_tetlisBoardBuf[column][5] != -1 ||
			g_tetlisBoardBuf[column][6] != -1 ||
			g_tetlisBoardBuf[column][7] != -1 ||
			g_tetlisBoardBuf[column][8] != -1 ||
			g_tetlisBoardBuf[column][9] != -1 ||
			g_tetlisBoardBuf[column][10] != -1)
		{
			if (g_tetlisBoardBuf[column + 1][1] == -1 &&
				g_tetlisBoardBuf[column + 1][2] == -1 &&
				g_tetlisBoardBuf[column + 1][3] == -1 &&
				g_tetlisBoardBuf[column + 1][4] == -1 &&
				g_tetlisBoardBuf[column + 1][5] == -1 &&
				g_tetlisBoardBuf[column + 1][6] == -1 &&
				g_tetlisBoardBuf[column + 1][7] == -1 &&
				g_tetlisBoardBuf[column + 1][8] == -1 &&
				g_tetlisBoardBuf[column + 1][9] == -1 &&
				g_tetlisBoardBuf[column + 1][10] == -1)
			{
				for (int coordinateX = 1; coordinateX < 11; coordinateX++)
				{
					g_tetlisBoardBuf[column + 1][coordinateX] = g_tetlisBoardBuf[column][coordinateX];
					g_tetlisBoardBuf[column][coordinateX] = -1;

					g_tetlisBoard[column + 1][coordinateX] = g_tetlisBoard[column][coordinateX];
					g_tetlisBoard[column][coordinateX] = -1;
				}
			}
		}
	}

	return;
}


//テトリスのスコアに関する関数
VOID GetScoreByLineCount(INT lineCount, INT *scoreBuf)
{
	switch (lineCount)
	{
	case 1:
		*scoreBuf += 40;
		break;
	case 2:
		*scoreBuf += 100;
		break;
	case 3:
		*scoreBuf += 300;
		break;
	case 4:
		*scoreBuf += 1200;
		break;
	}

	sprintf(g_scoreArray, "%d", *scoreBuf);

	return;
}

VOID SetFeverStartTime(DWORD *g_startTime,BOOL *canSetStartTime)
{
	//フィーバーモードに入ったら一回だけ開始時間をセットする
	//何回もセットされないようにしている
	if (*canSetStartTime)
	{
		*g_startTime = timeGetTime();

		*canSetStartTime = false;
	}

}

//フィーバーモードの時間関数
VOID FeverTime(INT *g_lineTotalCount,DWORD *g_elapsedTime, DWORD *startTime, BOOL *canSetStartTime,INT *FeverTimer,INT *FallSpeedLevel, INT *FlamePerDown)
{
	//22秒後g_lineTotalCountを0にする
		timeBeginPeriod(1);
		//制限時間22秒
		DWORD timeLimit = FEVER_TIME;
		
		*g_elapsedTime = (timeGetTime() - *startTime) / 1000;

		*FeverTimer = timeLimit - *g_elapsedTime;

		sprintf(g_feverTimerArray, "%d", *FeverTimer);

		if (timeLimit - *g_elapsedTime <= 0)
		{
			*g_lineTotalCount = 0;
			*g_elapsedTime = 0;

			if (*FallSpeedLevel < 19)//18が最高レベル
			{
				*FallSpeedLevel += 1;//落下速度レベルを1上げる

				if(*FallSpeedLevel ==2|| *FallSpeedLevel ==3)
				{
					*FlamePerDown = 50;				
				}

				else if (*FallSpeedLevel == 4 || *FallSpeedLevel == 5)
				{
					*FlamePerDown = 40;
				}

				else if (*FallSpeedLevel == 6 || *FallSpeedLevel == 7 || *FallSpeedLevel == 8)
				{
					*FlamePerDown = 30;
				}

				else if (*FallSpeedLevel == 9 || *FallSpeedLevel == 10 || *FallSpeedLevel == 11)
				{
					*FlamePerDown = 20;
				}

				else if (*FallSpeedLevel == 12 || *FallSpeedLevel == 13 || *FallSpeedLevel == 14)
				{
					*FlamePerDown = 10;
				}

				else if (*FallSpeedLevel == 15 || *FallSpeedLevel == 16 || *FallSpeedLevel == 17)
				{
					*FlamePerDown = 5;
				}

				else if (*FallSpeedLevel == 18)
				{
					*FlamePerDown = 1;
				}
				
			}			
			
			*canSetStartTime = true;
		}

		timeEndPeriod(1);
	
}

//フィーバーゲージの中身を更新する関数
VOID UpdateFeverGauge(INT *lineCount,INT g_feverBlock)
{
	

}

//プレイ時の見える範囲内で一番上の部分に非可動テトリミノがある場合isGameoverをtrueにする
//ゲームオーバーか、否かを調べるする関数
VOID CheckGameover(BOOL *isGameover)
{
	for (INT coordinateX = 1; coordinateX < 11; coordinateX++)
	{
		if (g_tetlisBoardBuf[3][coordinateX] == 10 ||
			g_tetlisBoardBuf[3][coordinateX] == 11 ||
			g_tetlisBoardBuf[3][coordinateX] == 12 ||
			g_tetlisBoardBuf[3][coordinateX] == 13 ||
			g_tetlisBoardBuf[3][coordinateX] == 14 ||
			g_tetlisBoardBuf[3][coordinateX] == 15 ||
			g_tetlisBoardBuf[3][coordinateX] == 16)
		{
			*isGameover = true;
		}
	}

	SynchroTetlisBoardBufToTetlisBoard();

	return;
}