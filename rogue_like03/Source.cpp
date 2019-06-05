#include "DxLib.h"
#include "GameMap.hpp"

constexpr int X = 64;
constexpr int Y = 32;
constexpr int XY = X * Y;
constexpr int XY_SIZE = 20;



void load(MainMap& d)
{

	d.addWindowTexture("ASCLL/w.png", 10, 10);

	d.addItemTexture("ASCLL/picture/map/item/mushroom.png");
	d.addItemTexture("ASCLL/picture/map/item/mushroom2.png");
	d.addFloorTexture("ASCLL/picture/map/floor/crystal1.png");

	d.addItemID(5, 0);
	d.addItemID(3, 1);

	d.addCharTexture("ASCLL/2_0.png");
	d.addCharTexture("ASCLL/2_1.png");
	d.addCharTexture("ASCLL/0_0.png");
	d.addTalkID("私の戦闘力は530000です…\nですが、もちろんフルパワーで\nあなたと戦う気はありませんから\nご心配なく…", 0);
	d.addTalkID("当たり前だ…\nたった３匹のアリが\n恐竜に勝てると思ったのか？", 0);
	d.addTalkID("覚悟はよろしいですね。\n１時間経ってもベジータを\nここに連れてくることができなかったら\nこの私があなたを殺しますから…！", 0);

	d.addEvent(0, EVENT_TYPE_ID_TALK, 0);
	//d.addEvent(0, EVENT_TYPE_ID_TIME, 60);
	d.addEvent(0, EVENT_TYPE_ID_TALK, 1);
	//d.addEvent(0, EVENT_TYPE_ID_TIME, 60);
	d.addEvent(0, EVENT_TYPE_ID_TALK, 2);
	//d.addEvent(0, EVENT_TYPE_ID_TIME, 60);
	
	d.addMapChipTextureNewWC("ASCLL/rock3.png", "ASCLL/rnew3no1.png", 1, 60);
	d.addMapChipTextureNewWC("ASCLL/mizup1.png", "ASCLL/mnew4.png", 2, 16);
	d.addMapChipTextureNewWC("ASCLL/g.png", "ASCLL/gnew4.png", 1, 8);

	//d.addMapChipTextureWC("rock.png", "rock22.png", 2, 60);
	//d.addMapChipTextureWC("mizup1.png", "mizup1aa3.png", 2, 16);
	//d.addMapChipTexture("mizuaa2.png", 2, 16);
	//d.addMapChipTextureWC("g.png", "gg.png", 1, 8);
	//d.addMapChipTextureWC("rock.png","rock22.png", 2, 60);

	d.addFieldID(FIELD_ID_EMPTY, NULL_U16, WALK_TYPE_ID_GROUND);
	d.addFieldID(FIELD_ID_WALL, 2, WALK_TYPE_ID_WALL);
	d.addFieldID(FIELD_ID_WATER, 1, WALK_TYPE_ID_WATER);

	d.makeGround().makeSquare();

	d.addFloorTexture("ASCLL/picture/map/floor/undergroundStairs2.png");

	d.addMobTexture("ASCLL/picture/map/mob/onbun.png");
	//d.addMobTexture("ASCLL/picture/map/mob/guchipa.png");
	d.addMobTexture("ASCLL/b2.png", 40, 40);
	//d.addMobTexture("ASCLL/picture/map/mob/bgmap.png", 40, 40);
	//d.addMobTextureW("b.png",40,56);
	d.addMobTexture("ASCLL/picture/map/mob/biribiri.png");

	d.addMobID(0, 1);
	d.addMobID(1, 1);
	d.addMobID(2, 1);

	d.addUITexture("ASCLL/picture/touch_ui//00.png");
	d.addUITexture("ASCLL/picture/touch_ui//01.png");
	d.addUITexture("ASCLL/picture/touch_ui//02.png");
	d.addUITexture("ASCLL/picture/touch_ui//03.png");
	d.addUITexture("ASCLL/picture/touch_ui//04.png");
	d.addUITexture("ASCLL/picture/touch_ui//05.png");
	d.addUITexture("ASCLL/picture/touch_ui//06.png");
	d.addUITexture("ASCLL/picture/touch_ui//07.png");
	d.addUITexture("ASCLL/picture/menu/set2.png");
	d.addUITexture("ASCLL/picture/menu/undo.png");
	d.addUITexture("ASCLL/picture/menu/map.png");

}

#if defined(__WINDOWS__)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
#if defined(__ANDROID__)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
{
	SetOutApplicationLogValidFlag(FALSE);

#if defined(__WINDOWS__)
	SetMainWindowText("AS_CLL Rogue_Like");
	ChangeWindowMode(TRUE);
#endif
	if (DxLib_Init()) return-1;
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	SetDXArchiveExtension("asc");

#if defined(__ANDROID__)
	int SizeX = 800;
	int SizeY = 600;
	GetAndroidDisplayResolution(&SizeX, &SizeY);
	SetGraphMode(SizeX, SizeY, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	MapData m[XY];
	MainMap d(m, X, Y, SizeX, SizeY);
#endif
#if defined(__WINDOWS__)
	SetGraphMode(X*XY_SIZE, Y*XY_SIZE, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	//std::array<MapData,XY> m;
	MapData m[XY];
	MainMap d(m, X, Y, X*XY_SIZE, Y*XY_SIZE);
	//SetGraphMode(600, 900, 32);
	//SetDrawScreen(DX_SCREEN_BACK);
	//
	//MainMap d(m, X, Y, 600, 900);

	//マップ移動
	MapData m2[32 * 64];
	d.addMap(64, 32, m2);
#endif

	load(d);

	d.selectWindowInit();

	//std::array<char[32], 8> add_str;
	//for (u8 j = 0; j < 8; j++) {
	//	for (u8 i = 0; i < 31; i++) {
	//		add_str[j][i] = 'a';
	//	}
	//	add_str[j][31] = 0;
	//}

	//d.selectWindowAdd(add_str);


	d.makeCrossKey(0).makeOptionKey(8).makeD().loadOption();
	//d.makeNewKey(KEY_ID_O, 0, 9, -1, 600, 500);

	d.makeNewFuncKey(FUNC_KEY_ID_UP_STAIRS, LAYER_ID_SELECT_UP_STAIRS, 9, -1, 0, 0);

	d.makeNewSwitchKeyR(0, LAYER_ID_OPTION1, 10, 5, 10, 30);
	d.makeNewSwitchKeyR(1, LAYER_ID_OPTION1, 1, 5, 30, 30);
	d.makeNewSwitchKeyR(2, LAYER_ID_OPTION1, 1, 5, 50, 30);
	d.makeNewSwitchKeyR(3, LAYER_ID_OPTION1, 9, 5, 70, 30);

	d.makeNewKey(KEY_ID_H, 0, 9, -1, 500, 400);



	while (loopGCH()) {
		//入力取得関連
		d.checkKey().checkButton().checkCrossKey().move();
		//線画関連
		d.drawP().drawMiniMapX().drawButton().drawInventory().playTolkEvent().drawWindow().checkWindow();//

		//d.drawSelectWindow();

		d.eventTest();

		//Android関連
		//d.checkDisplayResolution();

	}

	DxLib_End();
	return 0;
}