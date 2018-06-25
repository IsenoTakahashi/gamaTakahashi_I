#ifndef RENDER
#define RENDER

#include <windows.h>
#include <d3dx9.h>

//�`��Ɋւ���֐�
VOID Render(VOID);

//�����I�Ȏ��_�̐ݒ������֐�
VOID SetViewPointOverall(VOID);

//�����I�Ȏ���p�̐ݒ������֐�
VOID SetFocusOfViewOverall(VOID);

//��ʂ�\��������֐�
VOID DisplayScreen(
	CustomVertex *cusV4Background, //�ʏ�w�i1
	CustomVertex *cusV4Frame,      //�g1

	CustomVertex *cusV4Background2, //�ʏ�w�i2
	CustomVertex *cusV4Frame2,      //�g2

	CustomVertex *cusV4FeverBackground, //�t�B�[�o�[�w�i1
	CustomVertex *cusV4FeverFrame,      //�t�B�[�o�[�g1

	CustomVertex *cusV4FeverBackground2, //�t�B�[�o�[�w�i2
	CustomVertex *cusV4FeverFrame2,      //�t�B�[�o�[�g2

	CustomVertex *cusV4HoldFrame,  //�z�[���h�g
	CustomVertex *cusV4GaugeFrame, //�t�B�[�o�[�Q�[�W

	CustomVertex *cusV4GaugeFrame_Fiver,//�t�B�[�o�[�Q�[�W�t�B�[�o�[��

	CustomVertex *cusV4ScoreFrame, //�X�R�A�g
	CustomVertex *cusV4HighScoreframe,//�n�C�X�R�A�g
	CustomVertex *cusV4GaugeBlock,    //�t�B�[�o�[�Q�[�W�u���b�N
	CustomVertex *cusV4Tetmino,       //�e�g���~�m
	RECT *rectGameoverStr,            //�Q�[���I�[�o�[����
	RECT *rectCurrentScoreStr,        //���݃X�R�A����
	RECT *rectCurrentHighScoreStr,    //���݃n�C�X�R�A����
	//RECT *rectHoldStr,                //�z�[���h�g�ɕ\�����镶��
	RECT *rectNextStr,                 //�l�N�X�g�ɕ\�����镶��
	RECT *rectCountStr,                //���C���J�E���g����
	RECT *rectCountShowStr,                //���C���J�E���g�\������
	RECT *rectNormalStr,                //�m�[�}�����[�h����
	RECT *rectFeverStr,                //�t�B�[�o�[���[�h����
	RECT *rectFeverTimerStr,            //�t�B�[�o�[���[�h�^�C�}�[
	RECT *rectFeverTimeShowStr,          //�t�B�[�o�[���[�h�^�C��
	RECT *rectFevergaugeShowStr,         //�t�B�[�o�[�Q�[�W����
	RECT *rectFallLevelStr,               //�������x���x������
	RECT *rectFallLevelShowStr            //�������x���x���\������

);

#endif
