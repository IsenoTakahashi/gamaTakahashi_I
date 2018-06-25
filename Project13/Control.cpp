#include "STATE.h"
#include "INITIALIZE.h"
#include "TCONTROL.h"
#include <time.h>


//�e�g���X�Ȃǂ̑���Ɋւ���֐�
VOID Control(VOID)
{
	//time_t t = time(0);

  //srand(t);

	//�L�[�f�o�C�X�ɓ����Ă������ǂݎ�鏀��
	HRESULT hr = g_pDKeyDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		//�L�[���͏��̃o�b�t�@�[
		BYTE diks[256];

		//���͂��ꂽ����ǂݎ��
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

		//���������̃e�g���~�m��ނ����߂�
		static INT 
			rACount = 0,
			lACount = 0,
			dACount = 0,
			stopCount = 0,
			downCount = 0,
			scoreBuf = 0,
			minoIRoatationCount = 0,

			prevEKeyState,              //�E��]E�L�[���͏�Ԃ�ۑ�

			prevTEN9KeyState,           //�E��]�e���L�[9���͏�Ԃ�ۑ�

			prevQKeyState,              //����]Q�L�[���͏�Ԃ�ۑ�

			prevTEN7KeyState,           //����]�e���L�[7���͏�Ԃ�ۑ�

			prevRKeyState,              //�z�[���hR�L�[���͏�Ԃ�ۑ�

			prevTENplusKeyState,        //�z�[���h�e���L�[ + ���͏�Ԃ�ۑ�

			currentTetmino = rand() % 7;

		INT lineCount = 0;

		INT FeverTimer = 0;

		
		//INT lineTotalCount = 0;

		INT LEFT[2] = { 0,diks[DIK_A] & 0x80 },             //���ړ� A�L�[
			TEN_LEFT[2] = { 0,diks[DIK_NUMPAD4] & 0x80 },      //���ړ� �e���L�[4

			DOWN[2] = { 0,diks[DIK_S] & 0x80 },             //���ړ� S�L�[
			TEN_DOWN[2] = { 0,diks[DIK_NUMPAD2] & 0x80 },   //���ړ� �e���L�[2

			RIGHT[2] = { 0,diks[DIK_D] & 0x80 },            //�E�ړ� D�L�[
			TEN_RIGHT[2] = { 0,diks[DIK_NUMPAD6] & 0x80 };   //�E�ړ� �e���L�[6
			

		//�e�g���X�z��Ƀe�g���X�z��o�b�t�@�[�̗v�f�S�Ă��R�s�[���Ă���
		memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);

		//���Z�b�g�{�^���A������Ԃɖ߂�
		if (diks[DIK_BACK] & 0x80)
		{
	
			//�t���O�A�J�E���g�A�z���������Ԃɖ߂�UpdateHoldNextNextNextBoard��p����
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

		//g_lineTotalCount��10�ȏ�̂Ƃ��t�B�[�o�[���[�h�̊J�n���Ԃ��Z�b�g
		if (g_lineTotalCount >= 10) 
		{
			SetFeverStartTime(&g_startTime, &canSetStartTime);
			FeverTime(&g_lineTotalCount, &g_elapsedTime, &g_startTime, &canSetStartTime,&FeverTimer,&FallSpeedLevel,&FlamePerDown);

		}

		sprintf(g_LevelArray, "%d", FallSpeedLevel);


		if (isGameover)
		{
			//�Q�[���I�[�o�[���ɕ������\��������
			g_showGameoverStr = true;
		}
		else
		{
			if (isNewGame)
			{

				//�j���[�Q�[��(��ԍŏ��̃t���[��)���ɂ�g_feverBlock�Ag_next��g_nextNext�Ag_nextNextnext�͏���������Ă��Ȃ��̂ŏ��������AisNewGame��false�ɂ���
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


					//g_canCreate���m�F��true�Ȃ��g_movMinoNumOfArBuf��currentTetmino�Ɠ�����ނ̃e�g���~�m�������W�������A�L�[���͂̃t���O�A
					//I�^�̃e�g���~�m������]���������m�F����J�E���g�A�z�[���h���s��ꂽ���ۂ��̃t���O��������Ԃɖ߂��Ag_canCreate��false�ɂ���
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


			//�t���O��false�Ȃ�΃J�E���g��1���₵�A���l�Ȃ�΃t���O��true�ɕς��J�E���g��������Ԃɂ���
			CountToMakeFlagTrue(&canInputLA, &lACount);
			CountToMakeFlagTrue(&canInputRA, &rACount);
			CountToMakeFlagTrue(&canInputDA, &dACount);


			//�z�[���h

			//�O�t���[������R�L�[�A+�L�[��������Ă����ꍇ���̏�����ʂ��Ȃ��A
			//�Ƃ��邱�Ƃɂ���ĘA�������t���[�����ɂ��̏����������̂�h���ł���

			//R�L�[
			if (!(prevRKeyState))
			{
				if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();

					
					//canHold��true�Ȃ��g_hold�Ɍ��݂̃e�g���~�m�̒l�������A���ł�-1(��)�ȊO�������Ă����ꍇcurrentTetmino��g_hold�̒l������A
					//���̌�g_canCreate��true�ɂ�UpdateHoldNextNextNextBoard���Ăяo��
					HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
				}
			}

			//+�L�[
			if (!(prevTENplusKeyState))
			{
				if (diks[DIK_R] & 0x80 || diks[DIK_NUMPADPLUS] & 0x80)
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();


					//canHold��true�Ȃ��g_hold�Ɍ��݂̃e�g���~�m�̒l�������A���ł�-1(��)�ȊO�������Ă����ꍇcurrentTetmino��g_hold�̒l������A
					//���̌�g_canCreate��true�ɂ�UpdateHoldNextNextNextBoard���Ăяo��
					HoldTetlimino(&canHold, &currentTetmino, &canCreate, &wasHold);
				}
			}

			//�z�[���h���s���Ă����ꍇ�V�����e�g���~�m�𐶐�����̂ŁA���̏�����ʂ��Ȃ�
			if (!(wasHold))
			{
				if (RIGHT[canInputRA] || TEN_RIGHT[canInputRA])
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();


					//g_movMinoNumOfArBuf�Ɉ����𑫂����z��ԍ���g_tetlisBoardBuf�ŎQ�Ƃ��A�󗓂������ꍇg_movMinoNumOfArBuf�Ɉ����𑫂����l��������
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


				//�E��]

				//�O�t���[������E�L�[�A�e���L�[9��������Ă����Ȃ�΁A���̏�����ʂ��Ȃ��A
				//�Ƃ��邱�Ƃɂ���ĘA���œ�������������邱�Ƃ�h���ł���

				//E�L�[
				if (!(prevEKeyState))
				{
					if (diks[DIK_E] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
						//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
						//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
						RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
					}
				}

				//�e���L�[9
				if (!(prevTEN9KeyState))
				{
					if (diks[DIK_NUMPAD9] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
						//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
						//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
						RotateTetliminoRight(&minoIRoatationCount, currentTetmino);
					}
				}





				//����]

				//�O�t���[������Q�L�[�A�e���L�[7��������Ă����Ȃ�΁A���̏�����ʂ��Ȃ��A
				//�Ƃ��邱�Ƃɂ���ĘA���œ�������������邱�Ƃ�h���ł���

				//Q�L�[
				if (!(prevQKeyState))
				{
					if (diks[DIK_Q] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
						//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
						//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
						RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
					}
				}

				//�e���L�[7
				if (!(prevTEN7KeyState))
				{
					if (diks[DIK_NUMPAD7] & 0x80)
					{
						memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
						SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
						SynchroTetlisBoardBufToTetlisBoard();


						//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
						//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
						//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
						RotateTetliminoLeft(&minoIRoatationCount, currentTetmino);
					}
				}




				if (DOWN[canInputDA] || TEN_DOWN[canInputDA])
				{
					memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
					SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
					SynchroTetlisBoardBufToTetlisBoard();

					
					//g_movMinoNumOfArBuf��Y�����ɂP�������z���p����g_tetlisBoardBuf���Q�Ƃ��A�󗓂̏ꍇ�ړ����s��
					DownTetlimino(&canInputDA);
				}

				////�n�[�h�h���b�v�@�e�g���~�m�̃u���b�N����Â������m�F���A�������󗓂ł͂Ȃ��ꍇ�A��������1��Ƀ��[�v������
				//if (diks[DIK_UP] & 0x80)
				//{
				//	memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				//	SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				//	SynchroTetlisBoardBufToTetlisBoard();

				//	
				//	//���[�v�J�E���^��p��g_tetlisBoardBuf���Q�Ƃ��A�󗓂ł͂Ȃ������ꍇg_movMinoNumOfArBuf��
				//	//���[�v�J�E���^-1�̏ꏊ�Ƀe�g���~�m���ړ�������
				//	HardDropTetlimino();
				//}

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//�e�g���~�m�̉������m�F���A�󗓂������ꍇ�J�E���g���Ƃ�AFLAME_PER_DOWN�ɒB�����ꍇ����Ɉړ�������
				
				//g_movMinoNumOfArBuf+1�����z��ԍ���p����g_tetlisBoardBuf���Q�Ƃ��A�󗓂������ꍇ�J�E���g��1���₵�A
				//���l�Ȃ��g_movMinoNumOfArBuf�ɂP�𑫂��A�J�E���g��������Ԃɂ���
				CountToDawnTetlimino(&downCount, &FallSpeedLevel, &FlamePerDown);

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				/*�e�g���~�m�������m�F���A�������󗓂ł͂Ȃ��ꍇ�J�E���g���Ƃ�AFLAME_PER_STOP�ɒB�����ꍇ
				���e�g���~�m�̃i���o�[��10�𑫂�(�ȒP�ɉ�������𔻕ʂ��邽��)�A�V�������e�g���~�m�𐶐�����*/
				
				//g_movMinoNumOfArBuf+1�������z��ԍ���p��g_tetlisBoardBuf���Q�Ƃ��A��(-1)�ȊO�������Ă����ꍇ
				//�J�E���g���P���₵�A���l�Ȃ��currentTetmino + 10��g_tetlisBoard�ɑ�����A
				//�e�g���~�m�𐶐��ł��邩�ۂ��A�z�[���h���ł��邩�ۂ��̃t���O��true�A
				//�z�[���h���s��ꂽ���̃t���O��false�ɂ��AcurrentTetmino��g_next�Ag_next��g_nextNext�A
				//g_nextNext��g_nextNextnext�������āA
				//g_nextNextnext�Ƀe�g���~�m�ԍ��͈̗̔͂�����������
				CountToStopTetlimino(&stopCount, &currentTetmino, &canCreate, &canHold, &wasHold);

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();


				//������Ă���񂪂��邩�m�F���J�E���g���Ƃ�
				
				//g_tetlisBoardBuf���g���m�F����񂪋�(-1)�ȊO�̏ꍇ�J�E���g���Ƃ�󗓂ɂ���
				DeleteAndCountFilledLine(&lineCount, &g_lineTotalCount);

				memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
				SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
				SynchroTetlisBoardBufToTetlisBoard();

				//�����������󗓂ɂ��ĉ��ɂ��炵�Ă���
				
				//g_tetlisBoardBuf���Q�Ƃ��A��(-1)�ȊO�̏ꍇ���[�v�J�E���^+1�����z��ԍ���p���A�ēx�Q�Ƃ��A
				//���S�ċ󗓂̏ꍇ���[�v�J�E���^+1�̔z��ԍ��ɃR�s�[���A�R�s�[�����󗓂ɏ���������
				ShiftTetlisLine();
			}

			memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();


			//�L�[���͏�Ԃ�ۑ�

			//�E��]
			prevEKeyState = diks[DIK_E] & 0x80;
			prevTEN9KeyState=diks[DIK_NUMPAD9] & 0x80;

			//����]
			prevQKeyState = diks[DIK_Q] & 0x80;
			prevTEN7KeyState = diks[DIK_NUMPAD7] & 0x80;

			//�z�[���h
			prevRKeyState = diks[DIK_R] & 0x80;
			prevTENplusKeyState= diks[DIK_NUMPADPLUS] & 0x80;
			

			//lineCount�̒l�ɂ����scoreBuf�̑��₷�l��ς��A������ɂ�g_scoreArray�ɑ������
			GetScoreByLineCount(lineCount, &scoreBuf);

			//�t�B�[�o�[�Q�[�W�̒��g���X�V����֐�
			UpdateFeverGauge(&lineCount, g_feverBlock);

			memcpy(g_tetlisBoard, g_tetlisBoardBuf, sizeof(INT)*TETLIS_HEIGHT*TETLIS_WIDTH);
			SynchroTetlisBoardToMovMinoNumOfArBuf(currentTetmino);
			SynchroTetlisBoardBufToTetlisBoard();

			
			//�v���C���̌�����͈͓��ň�ԏ�̕����ɔ���e�g���~�m������ꍇisGameover��true�ɂ���
			CheckGameover(&isGameover);

		}
	}

	return;
}


//�e�g���X�{�[�h��������
//�|1�͋󗓂�\���A��ɑS�Ă̔z��̒��g���󗓂ɂ��邱�Ƃɂ��A
//��(9)���ォ��h��Ԃ������ŕ\����������
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


//�e�g���X�{�[�h�o�b�t�@�[��������
//���e�g���~�m(�����Ă���)���e�g���X�{�[�h�o�b�t�@�[�ɓ���Ȃ��悤�ɂ��邱�Ƃɂ��A
//��]�A�ړ��Ȃǂ̍ہA���e�g���~�m���l�������Ƃ��ǂ�
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


//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g�{�[�h�̒��g���X�V����֐�
//�e�g���~�m�̏������W(���������Ƃ��̍��W)��p���邽�߁Ax���W��-4���炷���ƂŃl�N�X�g���̕\�Ƃ̐��������Ƃ�A
//�z�[���h�ɓ����Ă���l�ɂ���āA�����e�g���~�m��ς���
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


//���e�g���~�m�ȊO��g_tetlisBoardBuf�ɓ��������Ă��� 
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


//�e�g���X�z��ɉ��e�g���~�m�𓯊�������֐�
//g_tetlisBoard��g_movMinoNumOfArBuf�𓯊������Ă���
VOID SynchroTetlisBoardToMovMinoNumOfArBuf(INT currentTetmino)
{
	for (INT block = 0; block < 4; block++)
	{
		g_tetlisBoard[g_movMinoNumOfArBuf.YX[block][0]][g_movMinoNumOfArBuf.YX[block][1]] = currentTetmino;
	}

	return;
}


//�e�g���X�Ɋւ���f�[�^��������Ԃɖ߂��֐�
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


//�e�g���~�m�𐶐��Ɋւ���֐�
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


//�L�[���͂��J�E���g���Ƃ�\�ɂ���֐�
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


//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g������������֐�
VOID InitNextAndFever(BOOL *isNewGame)
{
	g_next = rand() % 7;
	g_nextNext = rand() % 7;
	g_nextNextnext = rand() % 7;
	g_feverBlock = 0; //�t�B�[�o�[�u���b�N�̏�����
	*isNewGame = false;

	return;
}


//�e�g���~�m���z�[���h���邱�ƂɊւ���֐�
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


//�e�g���~�m��X�������̈ړ��Ɋւ���֐�
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


//�E��]

//�e�g���~�m�̉�]�Ɋւ���֐�
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


//����]

//g_minoIRoatationCount���R�𒴂��Ă����ꍇ0�������AI�^�̃e�g���~�m�̏ꍇg_minoIRoatationCount�̒l�ɂ���Ď������炷�A
//X2�AY2�𒆐S�Ƃ��邽�߂�X2�AY2�ł��ꂼ��4�u���b�N���������S��0,0�Ɉړ��������]�����鏈�����s���O��
//g_tetlisBoardBuf���Q�Ƃ��ĉ�]���ł���ꍇ�ɏ������s���A��]�ł��Ȃ��ꍇI�^�̃e�g���~�m�����炵�����������ɖ߂�
//�e�g���~�m�̉�]�Ɋւ���֐�
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


//�e�g���~�m��Y�������̈ړ��Ɋւ���֐�
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


//�e�g���~�m�̎��������Ɋւ���֐�
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


//�e�g���~�m��~�Ɋւ���֐�
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

//g_tetlisBoardBuf���g���m�F����񂪋�(-1)�ȊO�̏ꍇ�J�E���g���Ƃ�󗓂ɂ���
//��������e�g���X�̃��C���������J�E���g���Ƃ�֐�
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

//�����ꂽ�e�g���X�̃��C�������ɂ��炷�֐�
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


//�e�g���X�̃X�R�A�Ɋւ���֐�
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
	//�t�B�[�o�[���[�h�ɓ��������񂾂��J�n���Ԃ��Z�b�g����
	//������Z�b�g����Ȃ��悤�ɂ��Ă���
	if (*canSetStartTime)
	{
		*g_startTime = timeGetTime();

		*canSetStartTime = false;
	}

}

//�t�B�[�o�[���[�h�̎��Ԋ֐�
VOID FeverTime(INT *g_lineTotalCount,DWORD *g_elapsedTime, DWORD *startTime, BOOL *canSetStartTime,INT *FeverTimer,INT *FallSpeedLevel, INT *FlamePerDown)
{
	//22�b��g_lineTotalCount��0�ɂ���
		timeBeginPeriod(1);
		//��������22�b
		DWORD timeLimit = FEVER_TIME;
		
		*g_elapsedTime = (timeGetTime() - *startTime) / 1000;

		*FeverTimer = timeLimit - *g_elapsedTime;

		sprintf(g_feverTimerArray, "%d", *FeverTimer);

		if (timeLimit - *g_elapsedTime <= 0)
		{
			*g_lineTotalCount = 0;
			*g_elapsedTime = 0;

			if (*FallSpeedLevel < 19)//18���ō����x��
			{
				*FallSpeedLevel += 1;//�������x���x����1�グ��

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

//�t�B�[�o�[�Q�[�W�̒��g���X�V����֐�
VOID UpdateFeverGauge(INT *lineCount,INT g_feverBlock)
{
	

}

//�v���C���̌�����͈͓��ň�ԏ�̕����ɔ���e�g���~�m������ꍇisGameover��true�ɂ���
//�Q�[���I�[�o�[���A�ۂ��𒲂ׂ邷��֐�
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