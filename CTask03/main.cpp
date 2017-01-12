#include<DxLib.h>
#include"Keyboard.h"
#include"scene_mgr.h"
#include"menu.h"

//int font100;

void Init();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//初期設定★
	SetGraphMode(1920, 1080, 16);            	//(必須)画面のサイズ設定
	//ChangeWindowMode(TRUE);                	//()FullScreenではなくWindowで開く
	if (DxLib_Init() == -1) return -1;            	//(必須)DXライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);    	//(必須)グラフィックの描画先を裏画面にセット

	

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && Keyboard_Get(KEY_INPUT_ESCAPE) == 0) {
		Keyboard_Update();

		switch (SceneMgr::GetScene()) {
		case SCENE_INIT:
			Init();
			break;

		//Menu
		case SCENE_TITLE:
			TitleScene();
			break;
		case SCENE_GENRE:
			GenreSelectScene();
			break;
		case SCENE_MODE:
			ModeSelectScene();
			break;
		case SCENE_LIST:

			break;
		
		/*
		case SCENE_PROGRAM:
			DrawBox(0, 0, 2000, 1000, GetColor(0, 100, 100), TRUE);
			break;
		case SCENE_NETWORK:
			DrawBox(0, 0, 2000, 1000, GetColor(0, 200, 100), TRUE);
			break;
		case SCENE_CIPHER:
			DrawBox(0, 0, 2000, 1000, GetColor(50, 50, 50), TRUE);
			break;
		*/
		}

	}

	DxLib_End();
	return 0;
}


void Init()
{
	//font100= CreateFontToHandle("メイリオ", 100, 3);



	//End init
	SceneMgr::SetScene(SCENE_TITLE);
	return;
}