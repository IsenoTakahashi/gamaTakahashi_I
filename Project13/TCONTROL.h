#ifndef TCONTROL
#define TCONTROL

#include <windows.h>
#include <stdio.h>
#include <dinput.h>

//�e�g���X�Ȃǂ̑���Ɋւ���֐�
VOID Control(VOID);

//�e�g���X�{�[�h������������֐�
VOID InitTetlisBoard(VOID);

//�e�g���X�{�[�h�o�b�t�@�[������������֐�
VOID InitTetlisBoardBuf(VOID);



//�t�B�[�o�[�Q�[�W�̒��g���X�V����֐�
VOID UpdateFeverGauge(INT *lineCount,INT g_feverBlock);

//���������C���̍��v�Ńt�B�[�o�[�Q�[�W�u���b�N��\������֐�
VOID FeverGaugeBlock(VOID);

//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g������������֐�
VOID InitNextAndFever(BOOL *isNewGame);

//�z�[���h�A�l�N�X�g�A�l�N�X�g�l�N�X�g�{�[�h�̒��g���X�V����֐�
VOID UpdateHoldNextNextNextBoard(VOID);

//�e�g���X�z��o�b�t�@�[�ɉ��e�g���~�m���������e�g���X�z��̗v�f�𓯊�������֐�
VOID SynchroTetlisBoardBufToTetlisBoard(VOID);

//�e�g���X�z��ɉ��e�g���~�m�𓯊�������֐�
VOID SynchroTetlisBoardToMovMinoNumOfArBuf(INT currentTetmino);

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

//�e�g���~�m�𐶐��Ɋւ���֐�
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

//�L�[���͂��J�E���g���Ƃ�\�ɂ���֐�
VOID CountToMakeFlagTrue(BOOL *canInputLA, INT *lACount);

//�e�g���~�m���z�[���h���邱�ƂɊւ���֐�
VOID HoldTetlimino(
	BOOL *canHold,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *wasHold
);

//�e�g���~�m��X�������̈ړ��Ɋւ���֐�
VOID ShiftTetliminoX(INT shiftX, BOOL *canInputRA);

//�e�g���~�m�̉�]�Ɋւ���֐�(�E��])
VOID RotateTetliminoRight(BOOL *minoIRoatationCount, INT currentTetmino);

//�e�g���~�m�̉�]�Ɋւ���֐�(����])
VOID RotateTetliminoLeft(BOOL *minoIRoatationCount, INT currentTetmino);

//�e�g���~�m��Y�������̈ړ��Ɋւ���֐�
VOID DownTetlimino(BOOL *canInputDA);

//�e�g���~�m�̃n�[�h�h���b�v�Ɋւ���֐�
//VOID HardDropTetlimino(VOID);

//�e�g���~�m�̎��������Ɋւ���֐�
VOID CountToDawnTetlimino(INT *downCount, INT *FallSpeedLevel, INT *FlamePerDown);

//�e�g���~�m��~�Ɋւ���֐�
VOID CountToStopTetlimino(
	INT *stopCount,
	INT *currentTetmino,
	BOOL *canCreate,
	BOOL *canHold,
	BOOL *wasHold
);

//��������e�g���X�̃��C���������J�E���g���Ƃ�֐�
VOID DeleteAndCountFilledLine(INT *lineCount,INT *g_lineTotalCount);

//�����ꂽ�e�g���X�̃��C�������ɂ��炷�֐�
VOID ShiftTetlisLine(VOID);

//�e�g���X�̃X�R�A�Ɋւ���֐�
VOID GetScoreByLineCount(INT lineCount, INT *scoreBuf);

//�Q�[���I�[�o�[���A�ۂ��𒲂ׂ邷��֐�
VOID CheckGameover(BOOL *isGameover);

//�t�B�[�o�[���[�h�̎��Ԋ֐� �t�B�[�o�[���[�h���I����FallSpeedLevel�� +1�AFlamePerDown��-2�ɂ���
VOID FeverTime(INT *g_lineTotalCount, DWORD *g_elapsedTime,DWORD *g_startTime, BOOL *canSetStartTime,INT *FeverTimer, INT *FallSpeedLevel, INT *FlamePerDown);

//�t�B�[�o�[���[�h�̊J�n���Ԋ֐�
VOID SetFeverStartTime(DWORD *g_startTime,BOOL *canSetStartTime);
#endif
