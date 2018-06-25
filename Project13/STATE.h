#ifndef STATE
#define STATE

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <d3dx9.h>
#include <dinput.h>

#pragma comment(lib,"d3dxof.lib")
#pragma comment(lib,"d3dx9d.lib")
#pragma comment(lib,"ddraw.lib")
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"winmm.lib")

//ウインドウサイズ
#define DISPLAY_WIDTH 1280
#define DISPLAY_HEIGHT 720

//テトリスサイズ
#define TETLIS_WIDTH 12
#define TETLIS_HEIGHT 24

#define SHIFT_FRAME_COUNTER 6
#define DOWN_FRAME_COUNTER 2

#define FLAME_PER_DOWN 55 //テトリミノの落ちる速さ
#define FLAME_PER_STOP 30 //テトリミノが設置までの時間

#define FEVERGAUGEBLOCK_TOTAL 10 //フィーバーゲージブロックの数

#define FEVER_TIME 22 //フィーバーモードの時間

//文字色
#define NORMAL_COLOR (0xFF000000)
#define GAMEOVER_COLOR (0xFFFF0000)
#define HIGHSCORE_COLOR (0xFF0000FF)
#define FEVER_COLOR (0xFFFFFF00)
#define NORMALMODE_COLOR (0xFFFF69B4)
#define FEVERTIMER_COLOR (0xFF4169E1)

//文字
#define GAMEOVER ("GAME OVER")
#define SCORE ("Score")
#define HIGHSCORE ("HighScore")
#define HOLD ("Hold")
#define NEXT ("Next")
#define HIGHSCORESHOW ("100000")
#define FEVERTIME ("FeverTime")
#define FEVERMODE ("FEVER!!!!")
#define NORMALMODE ("NORMAL")
#define LINECOUNT ("LineCount")
#define FEVERGAUGE ("Fever")
#define FALLLEVEL ("FallLevel")

#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)


typedef struct
{
	FLOAT x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CustomVertex;

typedef struct
{
	FLOAT x, y, xScale, yScale;
}ImageState;

extern ImageState g_tetminoState;
extern ImageState g_GameoverStrState;
extern ImageState g_CurrentScoreStrState;

extern ImageState g_HoldStrState;
extern ImageState g_NextStrState;
extern ImageState g_CountStrState;
extern ImageState g_CountShowStrState;
extern ImageState g_GaugeBlockState;
extern ImageState g_CurrentHighScoreStrState;

extern ImageState g_NormalStrState;
extern ImageState g_FeverStrState;
extern ImageState g_FeverTimerStrState;
extern ImageState g_FeverTimeShowStrState;
extern ImageState g_FevergaugeStrState;
extern ImageState g_FallLevelStrState;
extern ImageState g_FallLevelShowStrState;


//テトリミノパターン
typedef struct
{
	INT number;
	CHAR name;
	INT yx[4][2];
} Tetmino;

//ネズミブロック
typedef struct
{
	INT number;
	CHAR name;
	INT yx[2][2];
} TetminoMouse;

extern Tetmino g_tetmino[7];
extern TetminoMouse g_tetmioM[1];

typedef struct
{
	INT YX[4][2];
}MovMinoNumoOfArBuf;

extern MovMinoNumoOfArBuf g_movMinoNumOfArBuf;

enum TEX
{
	g_backgroundTex,
	g_frameTex,
	g_feverbackgroundTex,
	g_feverframeTex,

	g_backgroundTex2,
	g_frameTex2,
	g_feverbackgroundTex2,
	g_feverframeTex2,

	g_holdFrameTex,
	g_gaugeTex,
	g_gaugeFiverTex,
	g_scoreFrameTex,
	g_highScoreFrameTex,
	g_tetminoTex,
	g_feverBlockTex,
	g_texMax
};

enum FONT
{
	g_gameoverFont,
	g_currentscoreFont,
	g_currenthighscoreFont,
	/*g_scoreFont,
	g*/_highscoreFont,
	//g_holdFont,
	g_nextFont,
	g_countFont,
	g_countshowFont,
	g_normalFont,
	g_feverFont,
	g_fevertimerFont,
	g_fevertimeshowFont,
	g_fevergaugeshowFont,
	g_falllevelFont,
	g_falllevelshowFont,
	g_fontMax
};

//tetminoCat1 : 1, tetminoMouse1 : 2, tetminoCat2 : 3, tetminoMouse2 : 4
enum tetminoType
{
	tetminoCat1 = 1,
	tetminoMouse1,
	tetminoCat2,
	tetminoMouse2
};

extern INT g_tetminoNum;
extern INT g_hold, g_next, g_nextNext,g_nextNextnext;

extern INT g_feverBlock;//フィーバーブロック

extern INT g_lineTotalCount;//ラインの合計

extern DWORD g_elapsedTime;//フィーバーモードの経過時間
extern DWORD g_startTime;//フィーバーモードの開始時間
extern INT FallSpeedLevel;
extern INT FlamePerDown;

extern INT g_tetlisBoard[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_tetlisBoardBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_tetminoIBuf[TETLIS_HEIGHT][TETLIS_WIDTH];
extern INT g_holdBoard[4][4];
extern INT g_nextBoard[4][4];
extern INT g_nextNextBoard[4][4];
extern INT g_nextNextNextBoard[4][4];

extern INT g_fevergaugeBoard[1][10]; //フィーバーゲージブロック

extern BOOL g_showGameoverStr;

extern CHAR g_scoreArray[8];

extern CHAR g_countArray[4];

extern CHAR g_feverTimerArray[2];

extern CHAR g_LevelArray[2];

#endif
