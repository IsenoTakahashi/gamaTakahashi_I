#include "STATE.h"
#include "INITIALIZE.h"
#include "RENDER.h"

VOID Render(VOID)
{
	
	//���_�ʒu�̐ݒ�A�Ō�ɐ�΍��W�ւ̕ϊ����s��
	SetViewPointOverall();

	
	//����p�̐ݒ�A�Ō�ɐ�΍��W�ւ̕ϊ����s��
	SetFocusOfViewOverall();

	//�J�X�^���o�[�e�b�N�X�̐���

	//�ʏ�w�i

	CustomVertex cusV4Background[4]
		{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	 };
	

	//�g

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

	//�t�B�[�o�[�w�i

	CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g

	CustomVertex cusV4FeverFrame[4]
	{
	{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�ʏ�w�i2

	CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�g2

	CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i2

	CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g2

	CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�z�[���h�g
	CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�t�B�[�o�[�Q�[�W
	CustomVertex cusV4GaugeFrame[4]{
	{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�Q�[�W�t�B�[�o�[��
	CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 199.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�n�C�X�R�A�g
	CustomVertex cusV4HighScoreframe[4]{
		{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�X�R�A�g
	CustomVertex cusV4ScoreFrame[4]{
	{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	
	};

	//�t�B�[�o�[�Q�[�W�u���b�N

	CustomVertex cusV4GaugeBlock[4]{
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//�e�g���~�m

	CustomVertex cusV4Tetmino[4]
		{
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
		{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
		{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};
	

	//�Q�[���I�[�o�[�\��

	RECT rectGameoverStr
	{
		(LONG)(g_GameoverStrState.x - g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y - g_GameoverStrState.yScale),(LONG)(g_GameoverStrState.x + g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y + g_GameoverStrState.yScale)
	};
	

	//���݃X�R�A�\��

	RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	//���݃n�C�X�R�A�\��

	RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};
	
	////�z�[���h�g����

	//RECT rectHoldStr
	//{
	//	(LONG)(g_HoldStrState.x - g_HoldStrState.xScale),(LONG)(g_HoldStrState.y - g_HoldStrState.yScale),(LONG)(g_HoldStrState.x + g_HoldStrState.xScale),(LONG)(g_HoldStrState.y + g_HoldStrState.yScale)

	//};

	//�l�N�X�g����

	RECT rectNextStr
	{ 
		(LONG)(g_NextStrState.x - g_NextStrState.xScale),(LONG)(g_NextStrState.y - g_NextStrState.yScale),(LONG)(g_NextStrState.x + g_NextStrState.xScale),(LONG)(g_NextStrState.y + g_NextStrState.yScale)

	};

	//���C���J�E���g����

	RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)

	};

	//���C���J�E���g�\������

	RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//�m�[�}�����[�h����

	RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)

	};

	//�t�B�[�o�[���[�h����

	RECT rectFeverStr
	{
		(LONG)(g_FeverStrState.x - g_FeverStrState.xScale),(LONG)(g_FeverStrState.y - g_FeverStrState.yScale),(LONG)(g_FeverStrState.x + g_FeverStrState.xScale),(LONG)(g_FeverStrState.y + g_FeverStrState.yScale)

	};

	//�t�B�[�o�[�^�C�}�[����

	RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)

	};

	//�t�B�[�o�[�^�C������
	RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//�t�B�[�o�[�Q�[�W����
	RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//�������x���x������
	RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//�������x���x���\������
	RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)
	};
	
	//��ʕ\���֌W�̏����A�J�X�^���o�[�e�b�N�X��g_tetlisBoard�̔z��ԍ���p���āA
	//���������e�g���X��\�����Ă���
	DisplayScreen(
		cusV4Background, //�ʏ�w�i
		cusV4Frame,      //�g
		cusV4FeverBackground, //�t�B�[�o�[�w�i
		cusV4FeverFrame,      //�t�B�[�o�[�g

		cusV4Background2, //�ʏ�w�i2
		cusV4Frame2,      //�g2

		cusV4FeverBackground2, //�t�B�[�o�[�w�i2
		cusV4FeverFrame2,      //�t�B�[�o�[�g2

		cusV4HoldFrame,  //�z�[���h�g
		cusV4GaugeFrame, //�t�B�[�o�[�Q�[�W
		cusV4GaugeFrame_Fiver, //�t�B�[�o�[�Q�[�W�t�B�[�o�[��

		cusV4ScoreFrame, //�X�R�A�g
		cusV4HighScoreframe,//�n�C�X�R�A�g
		cusV4GaugeBlock,    //�t�B�[�o�[�Q�[�W�u���b�N
		cusV4Tetmino,       //�e�g���~�m
		&rectGameoverStr,            //�Q�[���I�[�o�[����
		&rectCurrentScoreStr,        //���݃X�R�A����
		&rectCurrentHighScoreStr,    //���݃n�C�X�R�A����
		&rectNextStr,                 //�l�N�X�g�ɕ\�����镶��
		&rectCountStr,                //���C���J�E���g����
		&rectCountShowStr,                //���C���J�E���g�\������
		&rectNormalStr,                //�m�[�}�����[�h����
		&rectFeverStr,                //�t�B�[�o�[���[�h����
		&rectFeverTimerStr,            //�t�B�[�o�[���[�h�^�C�}�[
		&rectFeverTimeShowStr,         //�t�B�[�o�[���[�h�^�C��
		&rectFevergaugeShowStr,        //�t�B�[�o�[�Q�[�W����
		&rectFallLevelStr,              //�������x���x������
		&rectFallLevelShowStr            //�������x���x���\������
	);

	//��ʕ\�����s��ꂽ���Ƃ��o�b�N�o�b�t�@�[�ɓ`����
	g_pD3dDevice->Present(NULL, NULL, NULL, NULL);

	return;
}

//���_�ʒu�̐ݒ�
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

//����p�̐ݒ�
VOID SetFocusOfViewOverall(VOID)
{
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pD3dDevice->SetTransform(D3DTS_VIEW, &matProj);

	return;
}

VOID CreateCustomVertex(VOID)
{
	//�ʏ�w�i
	static CustomVertex cusV4Background[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�g
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

	//�t�B�[�o�[�w�i
	static CustomVertex cusV4FeverBackground[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g
	static CustomVertex cusV4FeverFrame[4]
	{
	{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�ʏ�w�i2
	static CustomVertex cusV4Background2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�g
	static CustomVertex cusV4Frame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�w�i
	static CustomVertex cusV4FeverBackground2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�g
	static CustomVertex cusV4FeverFrame2[4]
	{
		{ 0.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 1280.f,   0.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 1280.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 0.f, 720.f, 0.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�z�[���h�g
	static CustomVertex cusV4HoldFrame[4]
	{
		{ 30.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 205.f,   10.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 205.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 30.f, 230.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�Q�[�W
	static CustomVertex cusV4GaugeFrame[4]{
	{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�Q�[�W�t�B�[�o�[��
	static CustomVertex cusV4GaugeFrame_Fiver[4]{
		{ 199.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 231.f,   350.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 231.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 19.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�X�R�A�g
	static CustomVertex cusV4ScoreFrame[4]{
		{ 670.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 940.f,   430.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 940.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 670.f, 550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};


	//�n�C�X�R�A�g
	static CustomVertex cusV4HighScoreframe[4]{
	{ 675.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ 935.f,   550.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ 935.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ 675.f, 670.f, 1.f,1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	//�t�B�[�o�[�Q�[�W�u���b�N

	CustomVertex cusV4GaugeBlock[4]{
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y - g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
	{ g_GaugeBlockState.x + g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
	{ g_GaugeBlockState.x - g_GaugeBlockState.xScale, g_GaugeBlockState.y + g_GaugeBlockState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }

	};

	//�e�g���~�m
	static CustomVertex cusV4Tetmino[4]
	{
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y - g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.f },
	{ g_tetminoState.x + g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.5f, 0.5f },
	{ g_tetminoState.x - g_tetminoState.xScale, g_tetminoState.y + g_tetminoState.yScale, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.5f }
	};

	//�Q�[���I�[�o�[�\��
	static RECT rectGameoverStr
	{
		(LONG)(g_GameoverStrState.x - g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y - g_GameoverStrState.yScale),(LONG)(g_GameoverStrState.x + g_GameoverStrState.xScale),(LONG)(g_GameoverStrState.y + g_GameoverStrState.yScale)
	};

	//���݃X�R�A�\��
	static RECT rectCurrentScoreStr
	{
		(LONG)(g_CurrentScoreStrState.x - g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y - g_CurrentScoreStrState.yScale),(LONG)(g_CurrentScoreStrState.x + g_CurrentScoreStrState.xScale),(LONG)(g_CurrentScoreStrState.y + g_CurrentScoreStrState.yScale)
	};

	// ���݃n�C�X�R�A�\��
		static RECT rectCurrentHighScoreStr
	{
		(LONG)(g_CurrentHighScoreStrState.x - g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y - g_CurrentHighScoreStrState.yScale),(LONG)(g_CurrentHighScoreStrState.x + g_CurrentHighScoreStrState.xScale),(LONG)(g_CurrentHighScoreStrState.y + g_CurrentHighScoreStrState.yScale)
	};

	//�l�N�X�g����

	static RECT rectNextStr
	{
		(LONG)(g_NextStrState.x - g_NextStrState.xScale),(LONG)(g_NextStrState.y - g_NextStrState.yScale),(LONG)(g_NextStrState.x + g_NextStrState.xScale),(LONG)(g_NextStrState.y + g_NextStrState.yScale)

	};

	//���C���J�E���g����
	static RECT rectCountStr
	{
		(LONG)(g_CountStrState.x - g_CountStrState.xScale),(LONG)(g_CountStrState.y - g_CountStrState.yScale),(LONG)(g_CountStrState.x + g_CountStrState.xScale),(LONG)(g_CountStrState.y + g_CountStrState.yScale)
	};

	//���C���J�E���g�\������

	static RECT rectCountShowStr
	{
		(LONG)(g_CountShowStrState.x - g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y - g_CountShowStrState.yScale),(LONG)(g_CountShowStrState.x + g_CountShowStrState.xScale),(LONG)(g_CountShowStrState.y + g_CountShowStrState.yScale)

	};

	//�m�[�}�����[�h����
	static RECT rectNormalStr
	{
		(LONG)(g_NormalStrState.x - g_NormalStrState.xScale),(LONG)(g_NormalStrState.y - g_NormalStrState.yScale),(LONG)(g_NormalStrState.x + g_NormalStrState.xScale),(LONG)(g_NormalStrState.y + g_NormalStrState.yScale)
	};

	//�t�B�[�o�[���[�h����
	static RECT rectFeverStr
	{
		(LONG)(g_FeverStrState.x - g_FeverStrState.xScale),(LONG)(g_FeverStrState.y - g_FeverStrState.yScale),(LONG)(g_FeverStrState.x + g_FeverStrState.xScale),(LONG)(g_FeverStrState.y + g_FeverStrState.yScale)
	};

	//�t�B�[�o�[�^�C�}�[����
	static RECT rectFeverTimerStr
	{
		(LONG)(g_FeverTimerStrState.x - g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y - g_FeverTimerStrState.yScale),(LONG)(g_FeverTimerStrState.x + g_FeverTimerStrState.xScale),(LONG)(g_FeverTimerStrState.y + g_FeverTimerStrState.yScale)
	};

	//�t�B�[�o�[�^�C������
	static RECT rectFeverTimeShowStr
	{
		(LONG)(g_FeverTimeShowStrState.x - g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y - g_FeverTimeShowStrState.yScale),(LONG)(g_FeverTimeShowStrState.x + g_FeverTimeShowStrState.xScale),(LONG)(g_FeverTimeShowStrState.y + g_FeverTimeShowStrState.yScale)

	};

	//�t�B�[�o�[�Q�[�W����
	static RECT rectFevergaugeShowStr
	{
		(LONG)(g_FevergaugeStrState.x - g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y - g_FevergaugeStrState.yScale),(LONG)(g_FevergaugeStrState.x + g_FevergaugeStrState.xScale),(LONG)(g_FevergaugeStrState.y + g_FevergaugeStrState.yScale)

	};

	//�������x���x������
	static RECT rectFallLevelStr
	{
		(LONG)(g_FallLevelStrState.x - g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y - g_FallLevelStrState.yScale),(LONG)(g_FallLevelStrState.x + g_FallLevelStrState.xScale),(LONG)(g_FallLevelStrState.y + g_FallLevelStrState.yScale)
	};

	//�������x���x���\������
	static RECT rectFallLevelShowStr
	{
		(LONG)(g_FallLevelShowStrState.x - g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y - g_FallLevelShowStrState.yScale),(LONG)(g_FallLevelShowStrState.x + g_FallLevelShowStrState.xScale),(LONG)(g_FallLevelShowStrState.y + g_FallLevelShowStrState.yScale)

	};
	return;
}


//�`��
VOID DisplayScreen(
	CustomVertex *cusV4Background, //�ʏ�w�i
	CustomVertex *cusV4Frame,      //�g
	CustomVertex *cusV4FeverBackground, //�t�B�[�o�[�w�i
	CustomVertex *cusV4FeverFrame,      //�t�B�[�o�[�g

	CustomVertex *cusV4Background2, //�ʏ�w�i2
	CustomVertex *cusV4Frame2,      //�g

	CustomVertex *cusV4FeverBackground2, //�t�B�[�o�[�w�i2
	CustomVertex *cusV4FeverFrame2,      //�t�B�[�o�[�g2

	CustomVertex *cusV4HoldFrame,  //�z�[���h�g
	CustomVertex *cusV4GaugeFrame, //�t�B�[�o�[�Q�[�W

	CustomVertex *cusV4GaugeFrame_Fiver, //�t�B�[�o�[�Q�[�W�t�B�[�o�[��

	CustomVertex *cusV4ScoreFrame, //�X�R�A�g
	CustomVertex *cusV4HighScoreframe,//�n�C�X�R�A�g
	CustomVertex *cusV4GaugeBlock,    //�t�B�[�o�[�Q�[�W�u���b�N
	CustomVertex *cusV4Tetmino,       //�e�g���~�m
	RECT *rectGameoverStr,            //�Q�[���I�[�o�[����
	RECT *rectCurrentScoreStr,        //���݃X�R�A����
	RECT *rectCurrentHighScoreStr,    //���݃n�C�X�R�A����
	RECT *rectNextStr,                 //�l�N�X�g�ɕ\�����镶��
	RECT *rectCountStr,                //���C���J�E���g����
	RECT *rectCountShowStr,                //���C���J�E���g�\������
	RECT *rectNormalStr,                //�m�[�}�����[�h����
	RECT *rectFeverStr,                //�t�B�[�o�[���[�h����
	RECT *rectFeverTimerStr,            //�t�B�[�o�[���[�h�^�C�}�[
	RECT *rectFeverTimeShowStr,            //�t�B�[�o�[���[�h�^�C��
	RECT *rectFevergaugeShowStr,         //�t�B�[�o�[�Q�[�W����
	RECT *rectFallLevelStr,               //�������x���x������
	RECT *rectFallLevelShowStr            //�������x���x���\������
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

	//���C���̐���10�ȏ�̂Ƃ��t�B�[�o�[�w�i 10�ȉ��Ȃ�ʏ�w�i
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//�t�B�[�o�[�w�i2�\��
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverbackgroundTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground2, sizeof(CustomVertex));

		}

		else
		{
			//�t�B�[�o�[�w�i1�\��
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverbackgroundTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverBackground, sizeof(CustomVertex));

		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//�w�i�\��2
			g_pD3dDevice->SetTexture(0, g_pTexture[g_backgroundTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background2, sizeof(CustomVertex));

		}

		else
		{
			//�w�i�\��1
			g_pD3dDevice->SetTexture(0, g_pTexture[g_backgroundTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Background, sizeof(CustomVertex));

		}

	}



	//�e�g���~�m�\��
	for (int column = 0; column < TETLIS_HEIGHT; column++)
	{
		for (int row = 0; row < TETLIS_WIDTH; row++)
		{
			if ((g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9))
			{
				cusV4Tetmino->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
				cusV4Tetmino->y = -64.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
				//��}�X����ĕ`��
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


	//���C���̐���10�ȏ�̂Ƃ��t�B�[�o�[�g 10�ȉ��Ȃ�ʏ�g
	if (g_lineTotalCount >= 10)
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//�t�B�[�o�[�g2
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverframeTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame2, sizeof(CustomVertex));
		}

		else
		{
			//�t�B�[�o�[�g1
			g_pD3dDevice->SetTexture(0, g_pTexture[g_feverframeTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4FeverFrame, sizeof(CustomVertex));
		}

	}
	else
	{
		if (FallSpeedLevel % 2 == 0)
		{
			//�g2
			g_pD3dDevice->SetTexture(0, g_pTexture[g_frameTex2]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame2, sizeof(CustomVertex));

		}

		else
		{
			//�g
			g_pD3dDevice->SetTexture(0, g_pTexture[g_frameTex]);

			g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4Frame, sizeof(CustomVertex));

		}

	}

	//�z�[���h�g
	g_pD3dDevice->SetTexture(0, g_pTexture[g_holdFrameTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HoldFrame, sizeof(CustomVertex));

	//�t�B�[�o�[�Q�[�W
	g_pD3dDevice->SetTexture(0, g_pTexture[g_gaugeTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4GaugeFrame, sizeof(CustomVertex));

	//�n�C�X�R�A�g
	g_pD3dDevice->SetTexture(0, g_pTexture[g_scoreFrameTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4ScoreFrame, sizeof(CustomVertex));

	//�X�R�A�g
	g_pD3dDevice->SetTexture(0, g_pTexture[g_highScoreFrameTex]);

	g_pD3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, cusV4HighScoreframe, sizeof(CustomVertex));



	//�Q�[���I�[�o�[
	if (g_showGameoverStr)
	{
		g_pFont[g_gameoverFont]->DrawText(NULL, GAMEOVER, -1, rectGameoverStr, NULL, GAMEOVER_COLOR);
	}

	//���݃X�R�A
	g_pFont[g_currentscoreFont]->DrawText(NULL, g_scoreArray, -1, rectCurrentScoreStr, NULL, NORMAL_COLOR);

	//���݃n�C�X�R�A
	g_pFont[g_currenthighscoreFont]->DrawText(NULL, HIGHSCORESHOW, -1, rectCurrentHighScoreStr, NULL, HIGHSCORE_COLOR);

	//�t�B�[�o�[�Q�[�W����
	g_pFont[g_fevergaugeshowFont]->DrawText(NULL, FEVERGAUGE, -1, rectFevergaugeShowStr, NULL, GAMEOVER_COLOR);

	//�������x���x������
	g_pFont[g_falllevelFont]->DrawText(NULL, g_LevelArray, -1, rectFallLevelStr, NULL, FEVERTIMER_COLOR);

	//�������x���x���\������
	g_pFont[g_falllevelshowFont]->DrawText(NULL, FALLLEVEL, -1, rectFallLevelShowStr, NULL, FEVERTIMER_COLOR);


	//���C���̐���10�ȏ�̂Ƃ��ԕ��� 10�ȉ��Ȃ獕���� �t�B�[�o�[���[�h�����\��
	if (g_lineTotalCount >= 10)
	{
		//�l�N�X�g����
		g_pFont[g_nextFont]->DrawText(NULL, NEXT, -1, rectNextStr, NULL, FEVER_COLOR);

		//�t�B�[�o�[���[�h����
		g_pFont[g_feverFont]->DrawText(NULL, FEVERMODE, -1, rectFeverStr, NULL, FEVER_COLOR);

		//�t�B�[�o�[�^�C�}�[����
		g_pFont[g_fevertimerFont]->DrawText(NULL, g_feverTimerArray, -1, rectFeverTimerStr, NULL, FEVER_COLOR);

		//�t�B�[�o�[�^�C������
		g_pFont[g_fevertimeshowFont]->DrawText(NULL, FEVERTIME, -1, rectFeverTimeShowStr, NULL, FEVER_COLOR);

	}

	else
	{
		//���C���J�E���g����
		g_pFont[g_countFont]->DrawText(NULL, g_countArray, -1, rectCountStr, NULL, NORMAL_COLOR);


		//���C���J�E���g�\������
		g_pFont[g_countFont]->DrawText(NULL, LINECOUNT, -1, rectCountShowStr, NULL, NORMAL_COLOR);


		//�l�N�X�g����
		g_pFont[g_nextFont]->DrawText(NULL, NEXT, -1, rectNextStr, NULL, NORMAL_COLOR);

		//�z�[���h�g����
		//g_pFont[g_holdFont]->DrawText(NULL, HOLD, -1, rectHoldStr, NULL, NORMAL_COLOR);

		//�m�[�}�����[�h����
		g_pFont[g_normalFont]->DrawText(NULL, NORMALMODE, -1, rectNormalStr, NULL, NORMALMODE_COLOR);

	}





	//�z�[���h�\��
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

			//�l�N�X�g
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


			//�l�N�X�g�l�N�X�g
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

			//�l�N�X�g�l�N�X�g�l�N�X�g
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


	////�e�g���~�m�\��
	//for (int column = 0; column < TETLIS_HEIGHT; column++)
	//{
	//	for (int row = 0; row < TETLIS_WIDTH; row++)
	//	{
	//		if ((g_tetlisBoard[column][row] != -1) && (g_tetlisBoard[column][row] != 9))
	//		{
	//			cusV4Tetmino->x = 260.f + row * (g_tetminoState.xScale * 2) - g_tetminoState.xScale;
	//			cusV4Tetmino->y = -72.f + column * (g_tetminoState.yScale * 2) - g_tetminoState.yScale;
	//			//��}�X����ĕ`��
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

	//�t�B�[�o�[�Q�[�W�u���b�N
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
