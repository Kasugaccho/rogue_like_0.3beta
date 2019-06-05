/*#######################################################################################
	Copyright (c) 2018-2019 Kasugaccho
	Copyright (c) 2018-2019 As Project
	https://github.com/Kasugaccho/rogue_like_0.3beta
	wanotaitei@gmail.com

	Distributed under the Boost Software License, Version 1.0. (See accompanying
	file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#######################################################################################*/
#ifndef INCLUDED_ROGUE_LIKE_0_3_BETA_GAME_MAP_HPP
#define INCLUDED_ROGUE_LIKE_0_3_BETA_GAME_MAP_HPP

#include "DefaultGMAP.hpp"

#if !defined(GMAP_INCLUDE)
#define GMAP_INCLUDE
#endif

#if defined(GMAP_INCLUDE)

#include <vector>
#include <array>
#include <cstdint>
#include <ctime>
#include <string>
#include <cstdio>

//ゲームマップライブラリ
#if !defined(GMAP_NON_NAMESPACE)
namespace gmap {
#endif

	constexpr u16 NULL_U16 = UINT16_MAX;
	constexpr u8 NULL_U8 = UINT8_MAX;

	//ダンジョン分割
	constexpr u8 DUNGEON_DIVISION_ID_LAST_X = 0;
	constexpr u8 DUNGEON_DIVISION_ID_LAST_Y = 1;
	constexpr u8 DUNGEON_DIVISION_ID_FIRST_X = 2;
	constexpr u8 DUNGEON_DIVISION_ID_FIRST_Y = 3;

	constexpr u8 DUNGEON_COUNT_ID_X = 0;
	constexpr u8 DUNGEON_COUNT_ID_Y = 1;
	constexpr u8 DUNGEON_ROAD_ID_BEFORE = 0;
	constexpr u8 DUNGEON_ROAD_ID_AFTER = 1;

	//#define GRAPH_ID_MAP (1)
	//#define GRAPH_ID_ITEM (2)
	//#define GRAPH_ID_MOB (3)

	//プレイヤーの向き
	constexpr u8 MOB_WALK_ID_DOWN = 0;
	constexpr u8 MOB_WALK_ID_UP = 1;
	constexpr u8 MOB_WALK_ID_LEFT = 2;
	constexpr u8 MOB_WALK_ID_RIGHT = 3;
	constexpr u8 MOB_WALK_ID_LEFTDOWN = 4;
	constexpr u8 MOB_WALK_ID_RIGHTDOWN = 5;
	constexpr u8 MOB_WALK_ID_LEFTUP = 6;
	constexpr u8 MOB_WALK_ID_RIGHTUP = 7;
	constexpr u8 MOB_WALK_ID_ATTACK = 8;
	constexpr u8 MOB_NON_WALK_ID = UINT8_MAX;

	//mob識別ID
	constexpr i32 MOB_ID_EMPTY = 0;
	constexpr i32 MOB_ID_PLAYER = 1;
	constexpr i32 MOB_ID_ENEMY = 2;

	//歩行タイプID
	constexpr size_t NUMBER_OF_WALK_TYPE_ID = size_t(UINT8_MAX + 1);
	constexpr u8 WALK_TYPE_ID_GROUND = 0;
	constexpr u8 WALK_TYPE_ID_WATER = 1;
	constexpr u8 WALK_TYPE_ID_MAGMA = 2;
	constexpr u8 WALK_TYPE_ID_SKY = 3;
	constexpr u8 WALK_TYPE_ID_WALL = 4;
	constexpr u8 WALK_TYPE_ID_FREE = 5;

	//マップタイプID
	constexpr u8 MAP_TYPE_ID_EMPTY = 1;
	constexpr u8 MAP_TYPE_ID_DUNGEON = 1;
	constexpr u8 MAP_TYPE_ID_WORLD_ = 2;
	constexpr u8 MAP_TYPE_ID_SIMPLE = 1;

	//地形ID
	constexpr u16 FIELD_ID_EMPTY = 0;
	constexpr u16 FIELD_ID_WALL = 1;
	constexpr u16 FIELD_ID_WATER = 2;

	constexpr u8 DEFAULT_MAP_ID = 0;

	//キャラチップ種類
	constexpr u8 NUMBER_OF_1_DIRECTION_CHAR_CHIP = 3;
	constexpr u8 NUMBER_OF_4_DIRECTION_CHAR_CHIP = 12;
	constexpr u8 NUMBER_OF_8_DIRECTION_CHAR_CHIP = 24;

	//基本チャンク数
	constexpr u8 WORLD_MAKE_CHUNK = 17;
	constexpr u8 WORLD_CHUNK = 16;

	//レイヤーID
	constexpr i32 LAYER_ID_OPTION1 = 1;
	constexpr i32 LAYER_ID_DEFAULT = 0;
	constexpr i32 LAYER_ID_TITLE = -10;
	constexpr i32 LAYER_ID_UP_STAIRS = -100;
	constexpr i32 LAYER_ID_SELECT_UP_STAIRS = -101;
	constexpr i32 LAYER_ID_TALK = -110;

	//関数キーID
	constexpr i32 FUNC_KEY_ID_UP_STAIRS = 1;
	constexpr i32 FUNC_KEY_ID_DEFAULT_LAYER = 2;

	//マップチップID //todo
	constexpr u8 MAPCHIP_ID_CENTER_LEFT_UP = 0;
	constexpr u8 MAPCHIP_ID_CENTER_RIGHT_UP = 1;
	constexpr u8 MAPCHIP_ID_CENTER_LEFT_DOWN = 2;
	constexpr u8 MAPCHIP_ID_CENTER_RIGHT_DOWN = 3;

	constexpr u8 MAPCHIP_ID_DEPTH_LEFT_UP = 4;
	constexpr u8 MAPCHIP_ID_DEPTH_RIGHT_UP = 5;
	constexpr u8 MAPCHIP_ID_DEPTH_LEFT_DOWN = 6;
	constexpr u8 MAPCHIP_ID_DEPTH_RIGHT_DOWN = 7;

	constexpr u8 MAPCHIP_ID_WIDTH_LEFT_UP = 8;
	constexpr u8 MAPCHIP_ID_WIDTH_RIGHT_UP = 9;
	constexpr u8 MAPCHIP_ID_WIDTH_LEFT_DOWN = 10;
	constexpr u8 MAPCHIP_ID_WIDTH_RIGHT_DOWN = 11;

	constexpr u8 MAPCHIP_ID_OUT_LEFT_UP = 12;
	constexpr u8 MAPCHIP_ID_OUT_RIGHT_UP = 13;
	constexpr u8 MAPCHIP_ID_OUT_LEFT_DOWN = 14;
	constexpr u8 MAPCHIP_ID_OUT_RIGHT_DOWN = 15;

	constexpr u8 MAPCHIP_ID_IN_LEFT_UP = 16;
	constexpr u8 MAPCHIP_ID_IN_RIGHT_UP = 17;
	constexpr u8 MAPCHIP_ID_IN_LEFT_DOWN = 18;
	constexpr u8 MAPCHIP_ID_IN_RIGHT_DOWN = 19;

	//プレイヤー歩行速度
	constexpr f32 MOB_WALK_SPEED = 0.1f;
	constexpr f32 MOB_WALK_LENGTH = 1.0f;
	constexpr f32 MOB_WALK_CLEAR = 0.0f;

	//ウィンドウID
	constexpr i32 WINDOW_ID_LOG = 1;

	constexpr i32 DEFAULT_WINDOW_ALPHA = 200;

	//ログID
	constexpr u8 LOG_ID_EMPTY = 0;
	constexpr u8 LOG_ID_PICK_UP = 1;
	constexpr u8 LOG_ID_RIDE = 2;
	constexpr u8 LOG_ID_KILL = 3;
	constexpr u8 LOG_ID_GET = 4;
	constexpr u8 LOG_ID_EAT = 5;
	constexpr u8 LOG_ID_USE = 6;
	constexpr u8 LOG_ID_DRINK = 7;
	constexpr u8 LOG_ID_UP = 8;
	constexpr u8 LOG_ID_DOWN = 9;

	//mob画像系
	constexpr u8 DEFAULT_ANIME_SPEED = 24;
	constexpr i32 DEFAULT_ANIME_LEN = 200;

	//画像系
	constexpr i32 DEFAULT_PICTURE_SIZE = 120;

	//
	constexpr u8 DEFAULT_CHAR_LEN = 32;


	//イベント系
	constexpr u16 EVENT_TYPE_ID_TALK = 1;
	constexpr u16 EVENT_TYPE_ID_TIME = 2;
	constexpr u16 EVENT_TYPE_ID_ENTER = 3;



	inline u8 notBit(u8 count)
	{
		switch (count)
		{
		case DUNGEON_COUNT_ID_X: return DUNGEON_COUNT_ID_Y;
		case DUNGEON_COUNT_ID_Y: return DUNGEON_COUNT_ID_X;
		}
		return DUNGEON_COUNT_ID_X;
	}

	inline u8 keyCheck()
	{
		bool is_left_down = (countKeyGCH(KEY_ID_S) || countKeyGCH(KEY_ID_DOWN)) && (countKeyGCH(KEY_ID_A) || countKeyGCH(KEY_ID_LEFT));
		if (is_left_down) return MOB_WALK_ID_LEFTDOWN;

		bool is_right_down = (countKeyGCH(KEY_ID_S) || countKeyGCH(KEY_ID_DOWN)) && (countKeyGCH(KEY_ID_D) || countKeyGCH(KEY_ID_RIGHT));
		if (is_right_down) return MOB_WALK_ID_RIGHTDOWN;

		bool is_left_up = (countKeyGCH(KEY_ID_W) || countKeyGCH(KEY_ID_UP)) && (countKeyGCH(KEY_ID_A) || countKeyGCH(KEY_ID_LEFT));
		if (is_left_up) return MOB_WALK_ID_LEFTUP;

		bool is_right_up = (countKeyGCH(KEY_ID_W) || countKeyGCH(KEY_ID_UP)) && (countKeyGCH(KEY_ID_D) || countKeyGCH(KEY_ID_RIGHT));
		if (is_right_up) return MOB_WALK_ID_RIGHTUP;

		bool is_up = countKeyGCH(KEY_ID_W) || countKeyGCH(KEY_ID_UP);
		if (is_up) return MOB_WALK_ID_UP;

		bool is_down = countKeyGCH(KEY_ID_S) || countKeyGCH(KEY_ID_DOWN);
		if (is_down) return MOB_WALK_ID_DOWN;

		bool is_left = countKeyGCH(KEY_ID_A) || countKeyGCH(KEY_ID_LEFT);
		if (is_left) return MOB_WALK_ID_LEFT;

		bool is_right = countKeyGCH(KEY_ID_D) || countKeyGCH(KEY_ID_RIGHT);
		if (is_right) return MOB_WALK_ID_RIGHT;

		bool is_attack = countKeyGCH(KEY_ID_RETURN) || countKeyGCH(KEY_ID_SPACE) || countKeyGCH(KEY_ID_Z);
		if (is_attack) return MOB_WALK_ID_ATTACK;

		return MOB_NON_WALK_ID;
	}

	struct MobPic {
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		int id[NUMBER_OF_8_DIRECTION_CHAR_CHIP];
#endif
#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))
		TEXTURE_VECTOR id;
#endif
	};

	//二次元配列のマップデータを格納する構造体
	struct MapData {
		u16 field = 0;
		u16 item = 0;
		u8 item_stack = 0;

		u8 terrain = 0;
		u8 floor = 0;

		u8 height = 0;

		u8 map_move = UINT8_MAX;

		u8 all_terrain = 0;
	};

	struct Monster {
		u16 texture_id = NULL_U16;
		std::vector<bool> walk_id;
	};

	//mob(player,enemy)のデータ構造
	struct Mob {
		i32 x = 0;
		i32 y = 0;

		u16 hand = 0;

		u8 move_count = 0;
		f32 micro_x = 0.0f;
		f32 micro_y = 0.0f;

		u8 walk = MOB_NON_WALK_ID;
		u8 walk_direction = MOB_WALK_ID_DOWN;
		u8 motion = 0;

		u8 walk_type = 0;

		i32 room = 0;

		u16 id = 0;
		//u16 mob_id = NULL_U16;
		u16 texture_id = NULL_U16;

		u16 monster_id = NULL_U16;

		//移動属性
		std::vector<bool> walk_id;
	};

	struct Item {
		char name[DEFAULT_CHAR_LEN] = {};
		i32 id = 0;

		i32 buy = 0;
		i32 sell = 0;
	};




	//ボタンを管理する構造体
	struct ButtonMap {

		//位置情報
		i32 start_x = 0;
		i32 start_y = 0;
		i32 len_x = 0;
		i32 len_y = 0;
		i32 end_x = 0;
		i32 end_y = 0;

		//サイズ
		bool use_rario = false;
		u8 ratio_x;
		u8 ratio_y;
		i32 ratio_size;


		//押されたか調べる
		bool click = false;
		bool release = false;
		i32 count = 0;
		bool turn = false;

		//キーの配置
		bool use_type = false;
		u8 type = 0;

		//関数の実行
		bool use_func = false;
		i32 func_type = -1;

		//管理(idは-1デフォルト、100がswitch)
		i32 id = -1;
		u16 ui_texture_id = NULL_U16;
		bool use_picture = false;

		//switch機能
		bool on_switch = false;
		i32 switch_key_pos = 0;
		i32 switch_type = -1;

		//文字機能
		bool use_string = false;
		FONT_TYPE string_handle = FONT_INIT;
		char key_string[DEFAULT_CHAR_LEN] = {};
		i32 string_x = 700;

		//色
		ColorGCH color;

		//所属レイヤー(デフォルトは0、全ては-1、裏レイヤーは-2)
		i32 layer = 0;
	};




	//MainMap内でMapDataを扱うためのクラス
	class SubMap {
	private:
		MapData * mapData;
		i32 map_end_x = 0;
		i32 map_end_y = 0;

	public:
		MapData * operator[](const i32 i);
		void resize(MapData *resize_data, const u32& xx, const u32& yy);
	};

	struct SubMapData {
		i32 map_total = 0;

		i32 map_start_x = 0;
		i32 map_start_y = 0;
		i32 map_end_x = 0;
		i32 map_end_y = 0;
		i32 map_end_xb = 0;
		i32 map_end_yb = 0;

		u8 map_type_id = MAP_TYPE_ID_EMPTY;

	};

	//ダンジョン内の領域ごとのデータ構造体
	struct DungeonMapData {

		//マップの区域 [X終点 , Y終点 , X始点 , Y始点]
		std::array<i32, 4> division_apex = {};
		std::array<i32, 4> room_apex = {};

		std::array<u8, 2> roadLine = {};
		std::array<i32, 2> roadPos = {};
		u8 room_id = 0;
		bool room_entered_player = false;
		i32 room_area = 0;
	};

	//ダンジョン内に出てくるアイテムのデータ管理
	struct DungeonItem {
		u16 texture_id = 0;
		i32 min_floor = -1;
		i32 max_floor = -1;
		u8 stack = 0;
	};

	//マップウィンドウ管理
	struct MapWindow {

#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		std::array<int, 9> id = { -1 };
#endif
#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))
		TEXTURE_VECTOR id;
#endif
		TEXTURE_TYPE handle = TEXTURE_INIT;
	};

	//マップチップ管理
	struct MapChip {
		TEXTURE_VECTOR map_chip_picture;
		u8 number_of_anime = 2;
		i32 anime_speed = DEFAULT_ANIME_SPEED;

		u8 anime_count = 0;
		i32 anime_speed_count = 0;
	};

	//フィールド
	struct DungeonField {
		u16 texture_id = NULL_U16;
		//移動属性
		u8 walk_type = UINT8_MAX;
	};

	struct Inventory {
		u16 id = 0;
		u8 stack = 0;
		u8 mode = 0;
	};

	//ウィンドウを管理する
	struct MapWindowData {
		bool on_window = false;
		bool on_write = false;
		i32 write_id = 0;

		i32 on_window_count = 0;
		i32 on_window_count_max = 180;

		i32 alpha_count = 0;
		i32 alpha_max = 30;

		i32 default_id = 0;
		i32 corner_x = 0;
		i32 corner_y = 0;
		i32 pos_x = 0;
		i32 pos_y = 0;
		i32 len_x = 0;
		i32 len_y = 0;
		char talk[UINT8_MAX + 1] = {};
		//char talk[UINT8_MAX + 1] = {"あいうえおかきくけこさしすせそたちつてと\nあいうえおかきくけこさしすせそたちつてと\nあいうえおかきくけこさしすせそたちつてと\nあいうえおかきくけこさしすせそたちつてと\n"};
		u8 talk_count = 0;
		u8 speed_count = 0;
		FONT_TYPE font = FONT_INIT;

		ColorGCH color_gch = { 56,107,141,DEFAULT_WINDOW_ALPHA };
	};

	struct MapLogData {
		i32 s_id = 0;
		u8 v_id = 0;
		i32 o_id = 0;
	};

	struct TalkData {
		char talk_string[UINT8_MAX + 1] = {};
		u16 texture = NULL_U16;
	};

	struct EventData {
		u16 type[UINT8_MAX + 1] = {};
		u16 type_id[UINT8_MAX + 1] = {};

		u8 select = 0; //選択中の項目
		u8 count = 0; //終わり
	};

	struct SelectWindow {
		std::array<char[32], 8> str = {};
		i32 start_x = 0;
		i32 start_y = 0;
		i32 x_len = 0;
		i32 y_len = 0;

		u8 select_count = 5;

		FONT_TYPE font = FONT_INIT;
	};

	struct DungeonData {
		//生成される部屋の数 (正確に言うと生成される区域の数)
		u8 division_min = 3;
		u8 division_len = 4;

		//生成される部屋のサイズ
		u8 room_min_x = 5;
		u8 room_len_x = 3;
		u8 room_min_y = 5;
		u8 room_len_y = 3;

		//生成されるアイテムの個数
		u8 min_room_item = 4;
		u8 len_room_item = 8;
		u8 min_back_item = 0;
		u8 len_back_item = 10;
		u8 item_count;

		//マップの区分け数 (部屋の個数) 0~nまでの部屋ID
		u8 division_count;

		u16 default_make_field_id = 1;
		u16 default_make_rand_pool_id = 2;

		//部屋数
		u8 room_count = 0;

		//部屋の総面積
		u32 room_total_area = 0;

		i32 floor_count = 0;

		i32 default_line_size = 4;
	};







	//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//マップデータ全体を管理するクラス
	//自動生成ダンジョンを管理するクラス
	class MainMap {

	private:
		//マップデータ管理
		std::array<MapData *, UINT8_MAX + 1> mapData = {nullptr};//マップアドレス
		std::array<SubMap, UINT8_MAX + 1> subMap;//マップを配列で使うためのクラス
		std::array<SubMapData, UINT8_MAX + 1> subMapData;//マップの情報管理

		u8 select_map_id = 0;
		u8 map_move_total_count = 0;

		//画面解像度
		i32 map_screen_x = 0;
		i32 map_screen_y = 0;
		i32 map_center_x = 0;
		i32 map_center_y = 0;

		i32 map_up = 0;
		i32 map_down = 0;
		i32 map_left = 0;
		i32 map_right = 0;

		//乱数SEED
		u8 rand_8;
		u32 rand_32;

		std::vector<Mob> mob;
		std::vector<Item> item;
		std::array<Monster, UINT16_MAX> monster;

		u8 key_check = MOB_NON_WALK_ID;

		bool bit_flag = false;

		u16 mob_player_id = NULL_U16;

		i32 check_display_resolution_time = 0;

		//テクスチャ系
		std::vector<MapWindow> windowTexture;//ウィンドウ
		TEXTURE_VECTOR itemTexture;//アイテム
		TEXTURE_VECTOR floorTexture;//床
		TEXTURE_VECTOR fieldTexture;//地形
		TEXTURE_VECTOR uiTexture;//UI
		TEXTURE_VECTOR charTexture;//キャラ立ち絵
		std::vector<MapChip> mapChip;//マップチップ
		std::vector<MobPic> mobPicture;//キャラチップ
		std::vector<ButtonMap> buttonMap;//ボタン

		std::vector<EventData> eventData;
		u16 select_eventData = 0;//現在選んでいるイベント
		u16 event_count = 0;
		bool on_eventData = false;
		bool on_event_write = false;
		u16 event_id = NULL_U16;
		u16 select_event_id = 0;

		std::vector<TalkData> talkData;
		u16 select_talkData = NULL_U16;
		i32 time_talkData = 0;
		u8 string_talkData = 0;
		//bool on_talkData = false;

		SelectWindow selectWindow;
		
		//ダンジョン系
		DungeonData dngData;
		std::array<DungeonMapData, UINT8_MAX + 1> dngList;
		u8 dngList_size = 0;

		std::array<DungeonItem, UINT16_MAX> dngItem;
		std::array<DungeonField, UINT16_MAX> dngField;

		u16 inventory_max = 5;
		u16 select_inventory = 0;

		std::vector<Inventory> inventory;

		i32 itembox_ui = 0;

		i32 motion_count = 0;

		//線画用
		i32 player_look_len = 10;
		i32 player_look_len_half = 5;
		i32 player_look_pixel;
		i32 player_look_pixel_half;
		i32 player_look_pixel_quarter;

		//十字キー用
		i32 cross_key_x = 0;
		i32 cross_key_y = 0;
		i32 cross_key_size = 160;
		i32 cross_key_id = -1;
		i32 cross_key_texture_id = -1;
		bool use_cross_key = false;

		//マップ
		u8 default_ground_id = 1;
		u8 default_stairs_id = 2;

		i32 default_layer = 0;

		

		//時間計測
		i32 half_minute = 0;
		bool on_half_minute = false;

		//フィールド効果
		u16 ground_shine = 0;
		bool use_ground_shine = true;
		bool on_ground_shine = true;

		FONT_TYPE inventory_font = FONT_INIT;



		i32 make_minimap = 0;
		i32 minimap_size = 0;
		bool minimap_update = false;
		bool on_minimap = true;

		TEXTURE_TYPE make_ground = TEXTURE_INIT;
		bool use_ground_picture = false;

		bool square_picture = false;
		bool use_square = false;

		bool on_fast_up_stairs = true;

		i32 up_stairs_event = 0;

		//ワールドチャンクの大きさ
		i32 chunk_len_x = 1;
		i32 chunk_len_y = 1;

		//ワールド生成
		u8 make_field_16[WORLD_MAKE_CHUNK][WORLD_MAKE_CHUNK] = { UINT8_MAX };

		//ワールドSEED
		u8 world_make_rand_x = 0;
		u8 world_make_rand_y = 0;

		//ウィンドウ系
		MapWindowData windowData;

		//ログ系
		std::array<MapLogData, UINT8_MAX + 1> logData;
		u8 logData_size = 0;

		//音声データ
		std::array<std::string, UINT8_MAX + 1> sound_name;
		std::array<int, 4> sound_id = { -1 };
		std::array<int, UINT8_MAX + 1> se_id = { -1 };

		i32 touch_count = 0;
		bool touch_click = false;

	public:
		//メイン関数内で使える
		i32 x;
		i32 y;
		u8 r8;
		i32 r32;
		i32 f;

		//コンストラクタ・デストラクタ
		MainMap(MapData *dngList, const u32 xx, const u32 yy, const u32 screen_x, const u32 screen_y);
		~MainMap();

		MainMap& resize(MapData *resize_data, const u32 xx, const u32 yy);
		MainMap& size();
		MainMap* giveAddress() { return this; }

		//乱数系
		u8 rand8(const u8 number = 0);
		MainMap& srand8(const u8 rand_8_SEED);
		u8 rand8_0toMax(const u8 i = UINT8_MAX);
		u32 rand32();
		MainMap& srand32(const u32 rand_32_SEED);
		i32 rand32_0toMax(const i32 i = INT32_MAX);

		//線画系
		MainMap& drawAll(const i32 pixel_size = 20);
		MainMap& drawField(const i32 pixel_size = 20);
		MainMap& drawMob(const i32 pixel_size = 20);

		TEXTURE_TYPE make_square = TEXTURE_INIT;


		//----------生成系----------

		//ダンジョン
		MainMap& makeFieldD();
		MainMap& makePlayerD();
		MainMap& makeD();
		MainMap& makeEnemyD();
		MainMap& makeRandPoolD();

		//ワールド
		MainMap& makeFieldW();
		MainMap& makeField16W(const u8 x, const u8 y, u8 size, const u8 t1, const u8 t2, const u8 t3, const u8 t4);
		MainMap& makeW();

		//ループワールド
		MainMap& makeFieldWL();
		MainMap& makeWL();

		MainMap& makePlayerS();

		MainMap& makeItem();
		MainMap& makeStairs();
		MainMap& makeGround();
		MainMap& makeSquare();
		MainMap& makeInventoryUI();



		MainMap& upFloor();
		MainMap& upFloor(i32& up_floor_count);

		MainMap& fieldTrrainCheckAll();
		MainMap& fieldTrrainCheck(const i32 start_x, const i32 end_x, const i32 start_y, const i32 end_y);

		MainMap& changeLineSize(const i32 after_line_size);

		//線画系
		MainMap& draw(i32 pixel_size = 20);
		MainMap& drawPlayerMap();
		MainMap& drawPlayer();
		MainMap& drawP();

		MainMap& drawGround();

		//動作制御系
		MainMap& move();
		MainMap& moveKeyCheck();
		MainMap& upFloorKeyCheck();
		MainMap& optionKeyCheck();
		MainMap& squareKeyCheck();
		MainMap& playerThrowKeyCheck();
		MainMap& twitterKeyCheck();
		MainMap& stringKeyCheck();

		//あたり判定
		MainMap& mobCollisionDetection(u8 walk_type, const u16 mob_id);

		//ミニマップ系
		MainMap& drawMiniMap(i32 line_size = 20, i32 pixel_x = 0, i32 pixel_y = 0, u8 r = UINT8_MAX, u8 g = UINT8_MAX, u8 b = UINT8_MAX);
		MainMap& drawMiniMapX(i32 pixel_x = 0, i32 pixel_y = 0, u8 r = UINT8_MAX, u8 g = UINT8_MAX, u8 b = UINT8_MAX);
		MainMap& makeAroundMiniMap(i32 player_id);
		MainMap& makeRoomMiniMap(i32 player_id);
		MainMap& makeAllMiniMap();

		//イベント系
		MainMap& playerWalkEndEvent(const u16 player_id);
		MainMap& playerStairsEvent(const u16 player_id);
		MainMap& playerMapMoveEvent(const u16 player_id);
		MainMap& playerBreakEvent(const u16 player_id);
		MainMap& playerItemGetEvent(const u16 player_id);
		MainMap& mobItemGetEvent(const u16 mob_id);
		u8 mobMotionEvent(const u8 motion);
		MainMap& playerItemThrowEvent(const u16 mob_id);
		void addMotion(const u16 mob_id);

		MainMap& upStairsEvent();

		MainMap& talkEvent();

		//画像追加系
		MainMap& addWindowTexture(const char* name, i32 mob_x = DEFAULT_PICTURE_SIZE, i32 mob_y = DEFAULT_PICTURE_SIZE);
		MainMap& addItemTexture(const char* name);
		MainMap& addFloorTexture(const char* name);
		MainMap& addMobTexture(const char* name, i32 mob_x = DEFAULT_PICTURE_SIZE, i32 mob_y = DEFAULT_PICTURE_SIZE);
		MainMap& addMobTextureW(const char* name, i32 mob_x = DEFAULT_PICTURE_SIZE, i32 mob_y = DEFAULT_PICTURE_SIZE);
		MainMap& addMobTextureWC(const char* name, const char* name2, i32 mob_x = DEFAULT_PICTURE_SIZE, i32 mob_y = DEFAULT_PICTURE_SIZE);
		MainMap& addMapChipTextureNew(const char* name, u8 map_chip_count, i32 map_chip_size);
		MainMap& addMapChipTextureNewWC(const char* name, const char* name2, u8 map_chip_count, i32 map_chip_size = DEFAULT_PICTURE_SIZE);
		MainMap& addUITexture(const char* name);
		MainMap& addCharTexture(const char* name);

		//エフェクト系
		MainMap& effectGroundShine();

		//アイテム追加系
		MainMap& addItemID(u16 add_item_id, u16 add_item_texture_id);
		MainMap& addFloorID(u8 add_floor_id, u8 add_floor_texture_id);
		MainMap& addMobID(u16 add_mob_id, u16 add_mob_texture_id);
		MainMap& addUIID(u16 add_ui_id, u16 add_ui_texture_id);
		MainMap& addFieldID(u16 add_item_id, u16 add_item_texture_id, u8 walk_type);
		MainMap& addTalkID(const char* add_talk, const u16 add_texture_id);
		MainMap& addEvent(const u16 add_event_id, const u16 add_event_type, const u16 add_event_type_id);

		//その他追加系
		MainMap& addMap(u32 add_map_x, u32 add_map_y, MapData* add_map_data);

		//インベントリ系
		MainMap& drawInventory(const i32 pixel_size = 120, const i32 pixel_x = 0, const i32 pixel_y = 0);
		//MainMap& makeInventory();

		//UI系
		MainMap & checkButton();
		MainMap& makeCrossKey(i32 make_cross_key_id, i32 make_cross_key_size = -1);
		MainMap& drawButton();
		MainMap& drawWindow();
		MainMap& checkCrossKey();
		MainMap& checkSwitchKey(const i32 switch_key_number, const bool on_switch_key);
		MainMap& checkFuncKey(const i32 func_key_number);
		bool checkNewSwitchKey(const i32 switch_key_number);

		MainMap& checkKey();
		MainMap& makeOptionKey(const u16 make_option_key_id, const i32 option_key_size = -1, const i32 option_key_x = -1, const i32 option_key_y = 0);
		MainMap& makeNewKey(const u8 make_new_key_type, const i32 make_new_key_layer, const u16 make_new_key_id, const i32 new_key_size = -1, const i32 new_key_x = -1, const i32 new_key_y = 0);
		MainMap& makeNewFuncKey(const i32 make_new_func_key_type, const i32 make_new_key_layer, const u16 make_new_key_id, const i32 new_key_size = -1, const i32 new_key_x = -1, const i32 new_key_y = 0);
		MainMap& makeNewSwitchKey(const i32 make_new_key_type, const i32 make_new_key_layer, const i32 make_new_key_id, const i32 new_key_size = -1, const i32 new_key_x = -1, const i32 new_key_y = 0, const char new_key_string[DEFAULT_CHAR_LEN] = "\0");
		MainMap& makeNewSwitchKeyR(const i32 make_new_key_type, const i32 make_new_key_layer, const i32 make_new_key_id, const i32 new_key_size = -1, const u8 new_key_x = -1, const u8 new_key_y = 0, const char new_key_string[DEFAULT_CHAR_LEN] = "\0");

		MainMap& checkDisplayResolution();

		char InputString[1024] = {};
		
		MainMap& androidString();

		MainMap& timeMeasurement();

		//ファイルデータ読み書き系
		MainMap& loadInventory();
		MainMap& saveInventory();
		MainMap& loadOption();
		MainMap& saveOption();
		MainMap& loadMap();
		MainMap& saveMap();

		MainMap& callbackFunction();

		//ウィンドウ系
		MainMap& windowAdd(const char* add_talk, const u8 add_talk_count);
		MainMap& windowClear();
		MainMap& windowWriteOn(const i32 write_id);
		MainMap& windowWriteLog();
		MainMap& checkWindow();

		//イベント系
		MainMap& checkEvent();
		MainMap& playTolkEvent();
		MainMap& eventTime();
		MainMap& eventEnterKey();

		MainMap& eventTest();

		//選択ウィンドウ系
		MainMap& selectWindowInit();
		MainMap& selectWindowAdd(std::array<char[32], 8>& add_str);
		MainMap& drawSelectWindow();

		//ログ系
		MainMap& addLog(const i32 add_s, const u8 add_v, const i32 add_o);

		MainMap& addSound(const u8 add_sound_id, const char* sound_name);
	};






	inline MainMap& MainMap::drawSelectWindow()
	{
		i32 window_x = map_center_x - (selectWindow.x_len / 2);
		i32 window_y = map_center_y - selectWindow.y_len * selectWindow.select_count / 2;

		drawGraphGCH(window_x, window_y, selectWindow.x_len, selectWindow.y_len*selectWindow.select_count, windowTexture[0].id[4], 190);
		for (u8 i = 0; i < selectWindow.select_count; i++) {
			drawStringGCH(window_x, window_y+selectWindow.y_len*i, ColorGCH{ 255,255,255 }, selectWindow.font, selectWindow.str[0]);
		}
		return *this;
	}

	inline MainMap& MainMap::selectWindowInit()
	{
		selectWindow.y_len = map_screen_y / 9;
		selectWindow.x_len = selectWindow.y_len*16;

		selectWindow.font = createFontGCH("a", selectWindow.y_len);
		//selectWindow.start_x = map_center_x;
		return *this;
	}

	inline MainMap& MainMap::selectWindowAdd(std::array<char[32], 8>& add_str)
	{
		for (u8 j = 0; j < 8; j++) {
			for (u8 i = 0; i < 32; i++) {
				selectWindow.str[j][i] = add_str[j][i];
			}
		}
		
		return *this;
	}

	inline MainMap& MainMap::eventTest()
	{
		if (clickKeyGCH(KEY_ID_H)) {
			default_layer = LAYER_ID_TALK;
			on_eventData = true;
		}
		return *this;
	}

	inline MainMap& MainMap::eventEnterKey()
	{
		if (touch_click || clickKeyGCH(KEY_ID_RETURN) || clickKeyGCH(KEY_ID_SPACE) || clickKeyGCH(KEY_ID_Z)) {
			on_event_write = false;
			event_count = 0;
			event_id = NULL_U16;
			windowData.on_window = false;
		}
		return *this;
	}

	inline MainMap& MainMap::eventTime()
	{
		event_count++;
		if (event_count>= select_event_id) {
			on_event_write = false;
			event_count = 0;
			event_id = NULL_U16;
		}
		return *this;
	}

	//会話イベント
	inline MainMap& MainMap::talkEvent()
	{
		if (select_talkData == NULL_U16) return *this;

		windowData.on_window = true;
		windowData.on_write = true;

		if (touch_click || clickKeyGCH(KEY_ID_RETURN) || clickKeyGCH(KEY_ID_SPACE) || clickKeyGCH(KEY_ID_Z)) {
			for (i32 i = 0; i < UINT8_MAX; i++) {
				windowData.talk[i] = talkData[select_talkData].talk_string[i];
			}
			string_talkData = UINT8_MAX - 1;
		}

		time_talkData++;
		if (time_talkData < 4) return *this;
		time_talkData = 0;

		char add_string = talkData[select_talkData].talk_string[string_talkData];
		windowData.talk[string_talkData] = add_string;

		string_talkData++;
		
		if (string_talkData != UINT8_MAX && add_string != 0) return *this;

		string_talkData = 0;

		windowData.on_write = false;

		event_id = EVENT_TYPE_ID_ENTER;

		//event_id = NULL_U16;
		//on_event_write = false;

		return *this;
	}

	//会話シーンを管理するイベント
	inline MainMap& MainMap::playTolkEvent()
	{
		if (!on_event_write) return *this;
		if (select_eventData >= u16(eventData.size())) return *this;

		drawGraphGCH(map_screen_x - map_screen_y, 0, map_screen_y, map_screen_y, charTexture[0]);

		switch (event_id)
		{
		case EVENT_TYPE_ID_TALK:
			talkEvent();
			break;

		case EVENT_TYPE_ID_TIME:
			eventTime();
			break;

		case EVENT_TYPE_ID_ENTER:
			eventEnterKey();
			break;
		}

		if (!on_eventData) {
			default_layer = 0;
			eventData[select_eventData].select = 0;
		}

		return *this;
	}

	inline MainMap& MainMap::checkEvent()
	{
		if (!on_eventData) return *this;
		if (select_eventData >= u16(eventData.size())) return *this;

		default_layer = LAYER_ID_TALK;

		if (on_event_write) return *this;

		u8 select = eventData[select_eventData].select;

		switch (eventData[select_eventData].type[select])
		{
		case EVENT_TYPE_ID_TALK:
			event_id = EVENT_TYPE_ID_TALK;
			select_talkData = eventData[select_eventData].type_id[select];

			for (i32 i = 0; i < UINT8_MAX; i++) windowData.talk[i] = 0;

			eventData[select_eventData].select++;
			if (eventData[select_eventData].select >= eventData[select_eventData].count) {
				on_eventData = false;
			}
			on_event_write = true;
			break;

		case EVENT_TYPE_ID_TIME:
			event_id = EVENT_TYPE_ID_TIME;
			select_event_id = eventData[select_eventData].type_id[select];

			eventTime();
			eventData[select_eventData].select++;
			if (eventData[select_eventData].select >= eventData[select_eventData].count) {
				on_eventData = false;
			}
			on_event_write = true;
			break;
		}



		return *this;
	}

	inline MainMap& MainMap::addSound(const u8 add_sound_id, const char* add_sound_name)
	{
		sound_name[add_sound_id] = std::string(add_sound_name);
		return *this;
	}

	inline MainMap& MainMap::makeRandPoolD()
	{
		const i32 map_total = subMapData[select_map_id].map_total;
		for (i32 i = 0; i < map_total; i++) {
			if (rand8(i&15) > 20) mapData[select_map_id][i].field = dngData.default_make_rand_pool_id;
		}
		return *this;
	}

	inline MainMap& MainMap::checkWindow()
	{
		if (!windowData.on_window) return *this;
		if (windowData.on_write) return *this;

		if (windowData.on_window_count_max <= windowData.on_window_count) {

			if (windowData.alpha_max <= windowData.alpha_count) {
				windowData.on_window_count = 0;
				windowData.alpha_count = 0;
				windowData.on_window = false;
			}
			else windowData.alpha_count++;

		}
		else windowData.on_window_count++;
		return *this;
	}

	inline MainMap& MainMap::addLog(const i32 add_s, const u8 add_v, const i32 add_o)
	{
		logData[logData_size].s_id = add_s;
		logData[logData_size].v_id = add_v;
		logData[logData_size].o_id = add_o;

		if (logData_size == UINT8_MAX) logData_size = 0;
		else logData_size++;

		return *this;
	}

	inline MainMap& MainMap::windowClear()
	{
		windowData.talk_count = 0;

		for (i32 i = 0; i < UINT8_MAX; i++) {
			windowData.talk[i] = 0;
		}
		return *this;
	}

	inline MainMap& MainMap::windowWriteLog()
	{
		if (!windowData.on_write) return *this;
		if (windowData.write_id != WINDOW_ID_LOG) return *this;
		if (windowData.talk_count == UINT8_MAX) return *this;

		windowData.on_window = true;
		windowData.on_window_count = 0;
		windowData.alpha_count = 0;

		windowClear();

		i32 add_log_count = 0;

		for (i32 i = logData_size - 5; i < logData_size; i++) {

			add_log_count = (i + 0x100) & 0xff;

			//char s[2] = {};
			//s[0] = logData[add_log_count].s_id + 48;
			//windowAdd(s, 2);
			//windowAdd(" ", 2);

			//s[0] = logData[add_log_count].v_id + 48;
			//windowAdd(s, 2);
			//windowAdd(" ", 2);

			//s[0] = logData[add_log_count].o_id + 48;
			//windowAdd(s, 2);
			//windowAdd("\n", 2);
		}

		windowData.on_write = false;
		windowData.write_id = 0;

		return *this;
	}

	inline MainMap& MainMap::windowWriteOn(const i32 write_id)
	{
		windowData.on_write = true;
		windowData.write_id = write_id;
		return *this;
	}

	inline MainMap& MainMap::windowAdd(const char* add_talk, const u8 add_talk_count)
	{
		if (windowData.talk_count == UINT8_MAX) return *this;

		for (i32 i = 0; i < add_talk_count; i++) {
			if (add_talk[i] == 0 || windowData.talk_count == UINT8_MAX) break;
			windowData.talk[windowData.talk_count] = add_talk[i];
			windowData.talk_count++;
		}
		return *this;
	}

	inline MainMap& MainMap::upStairsEvent()
	{
		up_stairs_event++;

		if (up_stairs_event > 60) {
			this->makeD();
			up_stairs_event = 0;
			default_layer = LAYER_ID_DEFAULT;
		}

		return *this;
	}

	inline MainMap& MainMap::loadMap()
	{
		readBinaryFile("Save", "dng.txt", &mapData[select_map_id], sizeof(*mapData[select_map_id]), size_t(subMapData[select_map_id].map_total));
		return *this;
		}

	inline MainMap& MainMap::saveMap()
	{
		writeBinaryFile("Save", "dng.txt", &mapData[select_map_id], sizeof(*mapData[select_map_id]), size_t(subMapData[select_map_id].map_total));
		return *this;
		}

	inline MainMap& MainMap::loadOption()
	{
#if (defined(GMAP_USE_CFP) || defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB) || defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		FILE  *cfp_fp;

#if defined(__ANDROID__) //Android専用
		char FilePath[256];
		GetExternalDataPath(FilePath, sizeof(FilePath));
		std::string fp_name = std::string(FilePath) + "/option.txt";

		//printfDx(" save:%s file:%s", FilePath, fp_name.c_str());

		cfp_fp = fopen(fp_name.c_str(), "r"); //持ち物ロード
#else
#if (defined(SIV3D_TARGET_MACOS) || defined(SIV3D_TARGET_LINUX)) //MacとLinux専用
		cfp_fp = fopen("Save\\option.txt", "r"); //持ち物ロード
#else
		errno_t cfp_error;
		cfp_error = fopen_s(&cfp_fp, "Save\\option.txt", "r"); //持ち物ロード
#endif
#endif
		unsigned char file_on_minimap = 0;
		unsigned char file_use_cross_key = 0;
		unsigned char file_use_square = 0;
		unsigned char file_ground_picture = 0;
#if (defined(SIV3D_TARGET_MACOS) || defined(SIV3D_TARGET_LINUX) || defined(__ANDROID__)) //AndroidとMacとLinux専用
		if (cfp_fp != nullptr) {
			fscanf(cfp_fp, "%hhu", &file_on_minimap);
			fscanf(cfp_fp, "%hhu", &file_use_cross_key);
			fscanf(cfp_fp, "%hhu", &file_use_square);
			fscanf(cfp_fp, "%hhu", &file_ground_picture);
#else
		if (!cfp_error) {
			fscanf_s(cfp_fp, "%hhu", &file_on_minimap);
			fscanf_s(cfp_fp, "%hhu", &file_use_cross_key);
			fscanf_s(cfp_fp, "%hhu", &file_use_square);
			fscanf_s(cfp_fp, "%hhu", &file_ground_picture);
#endif

			//printfDx("%d,%d,%d,%d", file_on_minimap, file_use_cross_key, file_use_square, file_ground_picture);


			on_minimap = bool(file_on_minimap);
			use_cross_key = bool(file_use_cross_key);
			use_square = bool(file_use_square);
			use_ground_picture = bool(file_ground_picture);
			fclose(cfp_fp);
		}

#endif
		return *this;
		}

	inline MainMap& MainMap::saveOption()
	{
#if (defined(GMAP_USE_CFP) || defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB) || defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		FILE  *cfp_fp; //保存ファイル
					   //インベントリ
#if defined(__ANDROID__) //Android専用
		char FilePath[256];
		GetExternalDataPath(FilePath, sizeof(FilePath));

		std::string fp_file_path = std::string(FilePath);
		std::string fp_name = fp_file_path + "/option.txt";

		//printfDx(" save:%s file:%s", FilePath, fp_name.c_str());

		cfp_fp = fopen(fp_name.c_str(), "w"); //持ち物セーブ
		if (cfp_fp != nullptr) {
#else

#if (defined(SIV3D_TARGET_MACOS) || defined(SIV3D_TARGET_LINUX)) //MacとLinux専用
		cfp_fp = fopen("Save\\option.txt", "w"); //持ち物セーブ
		if (cfp_fp != nullptr) {
#else
		errno_t cfp_error;
		cfp_error = fopen_s(&cfp_fp, "Save\\option.txt", "w"); //持ち物セーブ
		if (!cfp_error) {
#endif
#endif
			fprintf(cfp_fp, "%hhu\n", (unsigned char)on_minimap);
			fprintf(cfp_fp, "%hhu\n", (unsigned char)use_cross_key);
			fprintf(cfp_fp, "%hhu\n", (unsigned char)use_square);
			fprintf(cfp_fp, "%hhu\n", (unsigned char)use_ground_picture);
			fclose(cfp_fp);
		}
#endif
		return *this;
		}

	inline MainMap& MainMap::makeInventoryUI()
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		//インベントリUI作成
		itembox_ui = MakeScreen(60, 60, TRUE);
		SetDrawScreen(itembox_ui);
		ClearDrawScreen();

		drawBoxGCH(0, 0, 60, 60, ColorGCH{ 0, 0, 0,153 });
		drawBoxGCH(0, 0, 60, 5, ColorGCH{ 126, 126, 126 });
		drawBoxGCH(0, 0, 5, 60, ColorGCH{ 126, 126, 126 });
		drawBoxGCH(0, 60 - 5, 60, 5, ColorGCH{ 126, 126, 126 });
		drawBoxGCH(60 - 5, 0, 5, 60, ColorGCH{ 126, 126, 126 });

		drawBoxGCH(0, 0, 60, 2, ColorGCH{ 0, 0, 0 });
		drawBoxGCH(0, 0, 2, 60, ColorGCH{ 0, 0, 0 });
		drawBoxGCH(0, 60 - 2, 60, 2, ColorGCH{ 0, 0, 0 });
		drawBoxGCH(60 - 2, 0, 2, 60, ColorGCH{ 0, 0, 0 });

		SetDrawScreen(DX_SCREEN_BACK);
#endif
		return *this;
	}

	inline MainMap& MainMap::callbackFunction()
	{
		//地形生成
		makeGround();
		makeSquare();
		makeInventoryUI();
		minimap_update = true;
		return *this;
	}

	inline MainMap& MainMap::loadInventory()
	{
		readBinaryFile("Save", "inventory.txt", inventory.data(), sizeof(Inventory), inventory.size());
		return *this;
	}

	inline MainMap& MainMap::saveInventory()
	{
		writeBinaryFile("Save", "inventory.txt", inventory.data(), sizeof(Inventory), inventory.size());
		return *this;
	}

	inline MainMap& MainMap::timeMeasurement()
	{
		half_minute++;
		if (half_minute >= 1800) {
			on_half_minute = true;
			half_minute = 0;
		}
		else on_half_minute = false;

		return *this;
	}

	inline MainMap& MainMap::checkKey()
	{
		for (i32 i = 0; i < UINT8_MAX; i++) {
			click_key_g[i] = 0;
			release_key_g[i] = 0;
			//count_key_g[i] = 0;
		}

#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		updateKey();
#endif
		return *this;
	}

	inline MainMap& MainMap::checkCrossKey()
	{
		if (use_cross_key) {
			if (buttonMap[cross_key_id + MOB_WALK_ID_LEFTDOWN].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_A]]++;
				count_key_g[keyconfig_g[KEY_ID_S]]++;
			}
			else if (buttonMap[cross_key_id + MOB_WALK_ID_RIGHTDOWN].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_D]]++;
				count_key_g[keyconfig_g[KEY_ID_S]]++;
			}
			else if (buttonMap[cross_key_id + MOB_WALK_ID_LEFTUP].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_A]]++;
				count_key_g[keyconfig_g[KEY_ID_W]]++;
			}
			else if (buttonMap[cross_key_id + MOB_WALK_ID_RIGHTUP].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_D]]++;
				count_key_g[keyconfig_g[KEY_ID_W]]++;
			}
			else if (buttonMap[cross_key_id + MOB_WALK_ID_UP].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_W]]++;
			}
			else if (buttonMap[cross_key_id + MOB_WALK_ID_DOWN].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_S]]++;
			}
			else if (buttonMap[cross_key_id + MOB_WALK_ID_LEFT].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_A]]++;
			}
			else if (buttonMap[cross_key_id + MOB_WALK_ID_RIGHT].count > 0) {
				count_key_g[keyconfig_g[KEY_ID_D]]++;
			}
		}
		return *this;
	}

	inline MainMap& MainMap::drawWindow()
	{
		if (!windowData.on_window) return *this;
		if (windowData.default_id >= i32(windowTexture.size())) return *this;

		if (windowData.alpha_count == 0) {
			drawGraphBoxGCH(windowData.pos_x, windowData.pos_y, windowData.len_x, windowData.len_y, windowTexture[windowData.default_id].handle, windowData.color_gch);
			drawStringGCH(windowData.corner_x + windowData.pos_x, windowData.corner_y + windowData.pos_y, ColorGCH{ 255,255,255 }, windowData.font, windowData.talk);
		}
		else {
			ColorGCH window_color = windowData.color_gch;
			window_color.a = u8(DEFAULT_WINDOW_ALPHA * (windowData.alpha_max - windowData.alpha_count) / f32(windowData.alpha_max));
			drawGraphBoxGCH(windowData.pos_x, windowData.pos_y, windowData.len_x, windowData.len_y, windowTexture[windowData.default_id].handle, window_color);
			drawStringGCH(windowData.corner_x + windowData.pos_x, windowData.corner_y + windowData.pos_y, ColorGCH{ 255,255,255, window_color.a }, windowData.font, windowData.talk);
		}
		return *this;
	}

	inline MainMap& MainMap::drawButton()
	{
		//レイヤー
		if (default_layer > 0) {
			drawBoxGCH(0, 0, map_screen_x, map_screen_y, ColorGCH{ 0,0,0,100 });
		}
		switch (default_layer)
		{
		case LAYER_ID_UP_STAIRS:
			if (up_stairs_event <= 60) {
				drawBoxGCH(0, 0, map_screen_x, map_screen_y, ColorGCH{ 0,0,0,u8(up_stairs_event * 4) });
			}
			break;
		}

		const u16 button_size = u16(buttonMap.size());
		const u16 ui_texture_size = u16(buttonMap.size());
		u16 button_texture_id = 0;

		i32 start_end_half_x = 0;
		i32 start_end_half = 0;

		i32 button_switch_key = 0;

		for (u16 i = 0; i < button_size; i++) {
			if (buttonMap[i].layer == default_layer || buttonMap[i].layer == -1) {

				switch (buttonMap[i].id)
				{
				case 100: //switch
					start_end_half = (buttonMap[i].len_x >> 1);
					start_end_half_x = buttonMap[i].start_x + start_end_half;
					button_texture_id = buttonMap[i].ui_texture_id;
					button_switch_key = buttonMap[i].switch_key_pos;

					drawBoxGCH(buttonMap[i].start_x, buttonMap[i].start_y, start_end_half_x - buttonMap[i].start_x, buttonMap[i].len_y, ColorGCH{ 60, 200, 60 });
					drawBoxGCH(start_end_half_x, buttonMap[i].start_y, start_end_half, buttonMap[i].len_y, ColorGCH{ 220, 220, 220 });

					if (buttonMap[i].use_picture  && buttonMap[i].ui_texture_id >= 0 && buttonMap[i].ui_texture_id<i32(uiTexture.size())) {
						drawBoxGCH(buttonMap[i].start_x + button_switch_key, buttonMap[i].start_y, start_end_half, buttonMap[i].len_y, ColorGCH{ 255, 255, 255 });
						drawGraphGCH(buttonMap[i].start_x + button_switch_key, buttonMap[i].start_y, start_end_half, buttonMap[i].len_y, uiTexture[buttonMap[i].ui_texture_id]);
					}
					else {
						drawBoxGCH(buttonMap[i].start_x + button_switch_key, buttonMap[i].start_y, start_end_half, buttonMap[i].len_y, ColorGCH{ 255, 255, 255 });
					}

					if (buttonMap[i].use_string) {
						drawStringGCH(buttonMap[i].start_x - buttonMap[i].string_x, buttonMap[i].start_y, ColorGCH{ 255,255,255 }, buttonMap[i].string_handle, "%s", buttonMap[i].key_string);
					}

					if (buttonMap[i].on_switch && button_switch_key < start_end_half) buttonMap[i].switch_key_pos += (start_end_half >> 2);
					else if (!buttonMap[i].on_switch && button_switch_key > 0) buttonMap[i].switch_key_pos -= (start_end_half >> 2);

					if (button_switch_key > start_end_half) buttonMap[i].switch_key_pos = start_end_half;
					else if (button_switch_key < 0) buttonMap[i].switch_key_pos = 0;

					break;

					//十字キー
				case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:
					if (use_cross_key) {
						button_texture_id = buttonMap[i].ui_texture_id;
						if (button_texture_id >= 0 && button_texture_id < ui_texture_size) drawGraphGCH(buttonMap[i].start_x, buttonMap[i].start_y, buttonMap[i].len_x, buttonMap[i].len_y, uiTexture[button_texture_id]);
						else if (button_texture_id == -1) drawBoxGCH(buttonMap[i].start_x, buttonMap[i].start_y, buttonMap[i].len_x, buttonMap[i].len_y, ColorGCH{ 255, 255, 100 });
					}
					break;

				default:
					button_texture_id = buttonMap[i].ui_texture_id;
					if (button_texture_id >= 0 && button_texture_id < ui_texture_size) drawGraphGCH(buttonMap[i].start_x, buttonMap[i].start_y, buttonMap[i].len_x, buttonMap[i].len_y, uiTexture[button_texture_id]);
					else if (button_texture_id == -1) drawBoxGCH(buttonMap[i].start_x, buttonMap[i].start_y, buttonMap[i].len_x, buttonMap[i].len_y, ColorGCH{ 255, 255, 100 });
					break;
				}

			}
		}
		return *this;
	}

	//設定ボタンを作成する関数
	inline MainMap& MainMap::makeOptionKey(const u16 make_option_key_id, const i32 option_key_size, const i32 option_key_x, const i32 option_key_y)
	{
		return makeNewKey(KEY_ID_HOME, -1, make_option_key_id, option_key_size, option_key_x, option_key_y);
	}

	inline MainMap& MainMap::makeNewKey(const u8 make_new_key_type, const i32 make_new_key_layer, const u16 make_new_key_id, const i32 new_key_size, const i32 new_key_x, const i32 new_key_y)
	{
		const u16 ui_texture_size = u16(uiTexture.size());
		if (make_new_key_id >= ui_texture_size) return *this;
		ButtonMap newKey;
		newKey.layer = make_new_key_layer;
		newKey.use_type = true;
		newKey.type = make_new_key_type;

		if (new_key_x == -1) newKey.start_x = map_center_x;
		else newKey.start_x = new_key_x;
		newKey.start_y = new_key_y;

		if (new_key_size == -1) {
			newKey.end_x = newKey.start_x + player_look_pixel;
			newKey.end_y = newKey.start_y + player_look_pixel;
			newKey.len_x = player_look_pixel;
			newKey.len_y = player_look_pixel;
		}
		else {
			newKey.end_x = new_key_x + new_key_size;
			newKey.end_y = new_key_y + new_key_size;
			newKey.len_x = new_key_size;
			newKey.len_y = new_key_size;
		}

		newKey.ui_texture_id = make_new_key_id;
		buttonMap.push_back(newKey);
		return *this;
	}

	inline MainMap& MainMap::makeNewFuncKey(const i32 make_new_func_key_type, const i32 make_new_key_layer, const u16 make_new_key_id, const i32 new_key_size, const i32 new_key_x, const i32 new_key_y)
	{
		const u16 ui_texture_size = u16(uiTexture.size());
		if (make_new_key_id >= ui_texture_size) return *this;
		ButtonMap newKey;
		newKey.layer = make_new_key_layer;
		newKey.use_func = true;
		newKey.func_type = make_new_func_key_type;

		if (new_key_x == -1) newKey.start_x = map_center_x;
		else newKey.start_x = new_key_x;
		newKey.start_y = new_key_y;

		if (new_key_size == -1) {
			newKey.end_x = newKey.start_x + player_look_pixel;
			newKey.end_y = newKey.start_y + player_look_pixel;
			newKey.len_x = player_look_pixel;
			newKey.len_y = player_look_pixel;
		}
		else {
			newKey.end_x = new_key_x + new_key_size;
			newKey.end_y = new_key_y + new_key_size;
			newKey.len_x = new_key_size;
			newKey.len_y = new_key_size;
		}

		newKey.ui_texture_id = make_new_key_id;
		buttonMap.push_back(newKey);
		return *this;
	}

	//ボタンで関数を管理する関数
	inline MainMap& MainMap::checkFuncKey(const i32 func_key_number)
	{
		switch (func_key_number)
		{
		default:
			break;

		case FUNC_KEY_ID_UP_STAIRS:
			default_layer = LAYER_ID_UP_STAIRS;
			break;
		case FUNC_KEY_ID_DEFAULT_LAYER:
			default_layer = LAYER_ID_DEFAULT;
			break;
		case 3:

			break;
		}
		return *this;
	}

	//スイッチボタンを管理する関数
	inline MainMap& MainMap::checkSwitchKey(const i32 switch_key_number, const bool on_switch_key)
	{
		switch (switch_key_number)
		{
		default:
			break;
		case 0: //地図線画
			if (on_switch_key) on_minimap = true;
			else on_minimap = false;
			break;
		case 1: //十字キー使用
			if (on_switch_key) use_cross_key = true;
			else use_cross_key = false;
			break;
		case 2: //グリッド使用
			if (on_switch_key) use_square = true;
			else use_square = false;
			break;
		case 3: //地面画像使用
			if (on_switch_key) use_ground_picture = true;
			else use_ground_picture = false;
			break;
		}
		return *this;
	}

	//新しく作ったswitchのオンオフを初期化する
	inline bool MainMap::checkNewSwitchKey(const i32 switch_key_number)
	{
		switch (switch_key_number)
		{
		default:
			break;
		case 0: //地図線画
			return on_minimap;

		case 1: //十字キー使用
			return use_cross_key;

		case 2: //グリッド使用
			return use_square;

		case 3: //地面画像使用
			return use_ground_picture;
		}
		return false;
	}

	inline MainMap& MainMap::makeNewSwitchKeyR(const i32 make_new_key_type, const i32 make_new_key_layer, const i32 make_new_key_id, const i32 new_key_size, const u8 new_key_x, const u8 new_key_y, const char new_key_string[DEFAULT_CHAR_LEN])
	{
		ButtonMap newKey;
		newKey.use_rario = true;
		newKey.id = 100;
		newKey.layer = make_new_key_layer;
		newKey.switch_type = make_new_key_type;

		newKey.on_switch = checkNewSwitchKey(make_new_key_type);

		newKey.ratio_x = new_key_x;
		newKey.ratio_y = new_key_y;
		newKey.ratio_size = new_key_size;

		const i32 make_new_size_x = i32(new_key_x*map_screen_x / 100.0f);
		const i32 make_new_size_y = i32(new_key_y*map_screen_y / 100.0f);
		const i32 make_new_key_size = i32(new_key_size * map_screen_x / 100.0f);

		if (new_key_size == -1) {
			newKey.start_x = make_new_size_x - player_look_pixel;
			newKey.start_y = make_new_size_y - (player_look_pixel >> 1);
			newKey.len_x = player_look_pixel;
			newKey.len_y = (player_look_pixel >> 1);
			newKey.end_x = make_new_size_x + player_look_pixel;
			newKey.end_y = make_new_size_y + (player_look_pixel >> 1);
		}
		else {
			newKey.start_x = make_new_size_x - make_new_key_size;
			newKey.start_y = make_new_size_y - (make_new_key_size >> 1);
			newKey.len_x = make_new_key_size;
			newKey.len_y = (make_new_key_size >> 1);
			newKey.end_x = make_new_size_x + make_new_key_size;
			newKey.end_y = make_new_size_y + (make_new_key_size >> 1);
		}


		//todo
		//		if (new_key_string != "") {
		//			newKey.use_string = true;
		//			newKey.key_string = new_key_string;
		//#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		//			newKey.string_handle = CreateFontToHandle(nullptr, newKey.end_y - newKey.start_y, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
		//#endif
		//		}

		newKey.ui_texture_id = make_new_key_id;
		if (make_new_key_id >= 0) newKey.use_picture = true;
		buttonMap.push_back(newKey);

		return *this;
	}

	//
	inline MainMap& MainMap::makeNewSwitchKey(const i32 make_new_key_type, const i32 make_new_key_layer, const i32 make_new_key_id, const i32 new_key_size, const i32 new_key_x, const i32 new_key_y, const char new_key_string[DEFAULT_CHAR_LEN])
	{
		ButtonMap newKey;
		newKey.id = 100;
		newKey.layer = make_new_key_layer;
		newKey.switch_type = make_new_key_type;

		newKey.on_switch = checkNewSwitchKey(make_new_key_type);

		if (new_key_x == -1) newKey.start_x = map_center_x;
		else newKey.start_x = new_key_x;
		newKey.start_y = new_key_y;

		if (new_key_size == -1) {
			newKey.len_x = player_look_pixel;
			newKey.len_y = (player_look_pixel >> 1);
			newKey.end_x = newKey.start_x + player_look_pixel;
			newKey.end_y = newKey.start_y + (player_look_pixel >> 1);
		}
		else {
			newKey.len_x = (new_key_size << 1);
			newKey.len_y = new_key_size;
			newKey.end_x = new_key_x + (new_key_size << 1);
			newKey.end_y = new_key_y + new_key_size;
		}

		//todo
		//		if (new_key_string != "") {
		//			newKey.use_string = true;
		//			newKey.key_string = new_key_string;
		//#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		//			newKey.string_handle = CreateFontToHandle(nullptr, newKey.end_y - newKey.start_y, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
		//#endif
		//		}

		newKey.ui_texture_id = make_new_key_id;
		if (make_new_key_id >= 0) newKey.use_picture = true;
		buttonMap.push_back(newKey);
		return *this;
	}

	//十字キーを作成する関数
	inline MainMap& MainMap::makeCrossKey(i32 make_cross_key_id, i32 make_cross_key_size)
	{
		if (make_cross_key_size != -1) cross_key_size = make_cross_key_size;
		i32 ui_texture_size = i32(uiTexture.size());
		if (make_cross_key_id >= 0 && make_cross_key_id + 7 < ui_texture_size && !use_cross_key) {
			use_cross_key = true;
			cross_key_id = i32(buttonMap.size());
			cross_key_texture_id = make_cross_key_id;

			i32 cross_key_up_x = cross_key_size + cross_key_x;
			i32 cross_key_up_y = cross_key_y;
			ButtonMap buttonUp;

			i32 cross_key_down_x = cross_key_size + cross_key_x;
			i32 cross_key_down_y = cross_key_size * 2 + cross_key_y;
			ButtonMap buttonDown;

			i32 cross_key_left_x = cross_key_x;
			i32 cross_key_left_y = cross_key_size + cross_key_y;
			ButtonMap buttonLeft;

			i32 cross_key_right_x = cross_key_size * 2 + cross_key_x;
			i32 cross_key_right_y = cross_key_size + cross_key_y;
			ButtonMap buttonRight;

			i32 cross_key_leftup_x = cross_key_x;
			i32 cross_key_leftup_y = cross_key_y;
			ButtonMap buttonLeftUp;

			i32 cross_key_rightup_x = cross_key_size * 2 + cross_key_x;
			i32 cross_key_rightup_y = cross_key_y;
			ButtonMap buttonRightUp;

			i32 cross_key_leftdown_x = cross_key_x;
			i32 cross_key_leftdown_y = cross_key_size * 2 + cross_key_y;
			ButtonMap buttonLeftDown;

			i32 cross_key_rightdown_x = cross_key_size * 2 + cross_key_x;
			i32 cross_key_rightdown_y = cross_key_size * 2 + cross_key_y;
			ButtonMap buttonRightDown;

			buttonDown.start_x = cross_key_down_x;
			buttonDown.len_x = cross_key_size;
			buttonDown.end_x = cross_key_down_x + cross_key_size;
			buttonDown.start_y = cross_key_down_y;
			buttonDown.len_y = cross_key_size;
			buttonDown.end_y = cross_key_down_y + cross_key_size;
			buttonDown.ui_texture_id = make_cross_key_id + MOB_WALK_ID_DOWN;

			buttonUp.start_x = cross_key_up_x;
			buttonUp.len_x = cross_key_size;
			buttonUp.end_x = cross_key_up_x + cross_key_size;
			buttonUp.start_y = cross_key_up_y;
			buttonUp.len_y = cross_key_size;
			buttonUp.end_y = cross_key_up_y + cross_key_size;
			buttonUp.ui_texture_id = make_cross_key_id + MOB_WALK_ID_UP;

			buttonLeft.start_x = cross_key_left_x;
			buttonLeft.len_x = cross_key_size;
			buttonLeft.end_x = cross_key_left_x + cross_key_size;
			buttonLeft.start_y = cross_key_left_y;
			buttonLeft.len_y = cross_key_size;
			buttonLeft.end_y = cross_key_left_y + cross_key_size;
			buttonLeft.ui_texture_id = make_cross_key_id + MOB_WALK_ID_LEFT;

			buttonRight.start_x = cross_key_right_x;
			buttonRight.len_x = cross_key_size;
			buttonRight.end_x = cross_key_right_x + cross_key_size;
			buttonRight.start_y = cross_key_right_y;
			buttonRight.len_y = cross_key_size;
			buttonRight.end_y = cross_key_right_y + cross_key_size;
			buttonRight.ui_texture_id = make_cross_key_id + MOB_WALK_ID_RIGHT;

			buttonLeftDown.start_x = cross_key_leftdown_x;
			buttonLeftDown.len_x = cross_key_size;
			buttonLeftDown.end_x = cross_key_leftdown_x + cross_key_size;
			buttonLeftDown.start_y = cross_key_leftdown_y;
			buttonLeftDown.len_y = cross_key_size;
			buttonLeftDown.end_y = cross_key_leftdown_y + cross_key_size;
			buttonLeftDown.ui_texture_id = make_cross_key_id + MOB_WALK_ID_LEFTDOWN;

			buttonRightDown.start_x = cross_key_rightdown_x;
			buttonRightDown.len_x = cross_key_size;
			buttonRightDown.end_x = cross_key_rightdown_x + cross_key_size;
			buttonRightDown.start_y = cross_key_rightdown_y;
			buttonRightDown.len_y = cross_key_size;
			buttonRightDown.end_y = cross_key_rightdown_y + cross_key_size;
			buttonRightDown.ui_texture_id = make_cross_key_id + MOB_WALK_ID_RIGHTDOWN;

			buttonLeftUp.start_x = cross_key_leftup_x;
			buttonLeftUp.len_x = cross_key_size;
			buttonLeftUp.end_x = cross_key_leftup_x + cross_key_size;
			buttonLeftUp.start_y = cross_key_leftup_y;
			buttonLeftUp.len_y = cross_key_size;
			buttonLeftUp.end_y = cross_key_leftup_y + cross_key_size;
			buttonLeftUp.ui_texture_id = make_cross_key_id + MOB_WALK_ID_LEFTUP;

			buttonRightUp.start_x = cross_key_rightup_x;
			buttonRightUp.len_x = cross_key_size;
			buttonRightUp.end_x = cross_key_rightup_x + cross_key_size;
			buttonRightUp.start_y = cross_key_rightup_y;
			buttonRightUp.len_y = cross_key_size;
			buttonRightUp.end_y = cross_key_rightup_y + cross_key_size;
			buttonRightUp.ui_texture_id = make_cross_key_id + MOB_WALK_ID_RIGHTUP;

			buttonUp.id = MOB_WALK_ID_UP;
			buttonDown.id = MOB_WALK_ID_DOWN;
			buttonLeft.id = MOB_WALK_ID_LEFT;
			buttonRight.id = MOB_WALK_ID_RIGHT;
			buttonLeftUp.id = MOB_WALK_ID_LEFTUP;
			buttonRightUp.id = MOB_WALK_ID_RIGHTUP;
			buttonLeftDown.id = MOB_WALK_ID_LEFTDOWN;
			buttonRightDown.id = MOB_WALK_ID_RIGHTDOWN;

			buttonMap.push_back(buttonDown);
			buttonMap.push_back(buttonUp);
			buttonMap.push_back(buttonLeft);
			buttonMap.push_back(buttonRight);
			buttonMap.push_back(buttonLeftDown);
			buttonMap.push_back(buttonRightDown);
			buttonMap.push_back(buttonLeftUp);
			buttonMap.push_back(buttonRightUp);
		}
		return *this;
	}


	//----------    class SubMap    ----------


	inline MapData* SubMap::operator[](const i32 i) {
		return mapData + map_end_x * i;
	}

	inline void SubMap::resize(MapData *resize_data, const u32& xx, const u32& yy)
	{
#if defined(__ANDROID__) //Android専用
		if (resize_data != nullptr)mapData = resize_data;
#else
		if (resize_data != nullptr)mapData = resize_data;
#endif
		map_end_x = xx;
		map_end_y = yy;

		return;
	}


	//----------    class MainMap    ----------

	inline MainMap& MainMap::makeGround()
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		u8 floor_texture_size = u8(floorTexture.size());
		if (floor_texture_size && default_ground_id <= floor_texture_size && default_stairs_id) {
			if (make_ground != -1) DeleteGraph(make_ground);
			make_ground = MakeScreen(map_screen_x + (player_look_pixel << 1), map_screen_y + (player_look_pixel << 1), FALSE);
			SetDrawScreen(make_ground);
			ClearDrawScreen();

			i32 player_look_len_y = i32(player_look_len * ((f32)map_screen_y / (f32)map_screen_x)) + 1;
			i32 player_look_x = 0;
			i32 player_look_y = 0;

			for (i32 j = 0; j <= player_look_len_y + 1; j++) {
				player_look_y = j * player_look_pixel;

				for (i32 i = 0; i <= player_look_len + 1; i++) {
					player_look_x = i * player_look_pixel;


					drawGraphGCH(player_look_x, player_look_y, player_look_pixel, player_look_pixel, floorTexture[default_ground_id - 1]);
				}
			}
			SetDrawScreen(DX_SCREEN_BACK);
			use_ground_picture = true;
		}
#endif
		return *this;
	}

	inline MainMap& MainMap::makeSquare()
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))

		int make_tile = MakeScreen(60, 60, TRUE);
		SetDrawScreen(make_tile);
		ClearDrawScreen();

		drawBoxGCH(0, 0, 5, 60, ColorGCH{ 255, 255, 50 });
		drawBoxGCH(55, 0, 5, 60, ColorGCH{ 255, 255, 50 });
		drawBoxGCH(5, 0, 50, 5, ColorGCH{ 255, 255, 50 });
		drawBoxGCH(5, 55, 50, 5, ColorGCH{ 255, 255, 50 });

		if (make_square != -1) DeleteGraph(make_square);
		make_square = MakeScreen(map_screen_x + (player_look_pixel << 1), map_screen_y + (player_look_pixel << 1), TRUE);
		SetDrawScreen(make_square);
		ClearDrawScreen();

		i32 player_look_len_y = i32(player_look_len * ((f32)map_screen_y / (f32)map_screen_x)) + 1;
		i32 player_look_x = 0;
		i32 player_look_y = 0;

		for (i32 j = 0; j <= player_look_len_y + 1; j++) {
			player_look_y = j * player_look_pixel;

			for (i32 i = 0; i <= player_look_len + 1; i++) {
				player_look_x = i * player_look_pixel;
				drawGraphGCH(player_look_x, player_look_y, player_look_pixel, player_look_pixel, make_tile, 190);
			}
		}
		SetDrawScreen(DX_SCREEN_BACK);
		square_picture = true;
		DeleteGraph(make_tile);
#endif
		return *this;
	}

	inline MainMap& MainMap::checkDisplayResolution()
	{
		//drawGraphGCH(0, 0, map_screen_y, map_screen_y, charTexture[2], 255, true);
		//drawGraphGCH(map_screen_x-map_screen_y, 0, map_screen_y, map_screen_y, charTexture[0]);
#if defined(__ANDROID__) //Android専用
		//check_display_resolution_time++;

		//if (check_display_resolution_time > 3) {
		//	check_display_resolution_time = 0;

		int screen_x = 800;
		int screen_y = 600;
		GetAndroidDisplayResolution(&screen_x, &screen_y);

		if (screen_x != map_screen_x || screen_y != map_screen_y) {

			SetGraphMode(screen_x, screen_y, 32);
			SetDrawScreen(DX_SCREEN_BACK);

			map_screen_x = screen_x;
			map_screen_y = screen_y;
			map_center_x = screen_x >> 1;
			map_center_y = screen_y >> 1;
			map_down = screen_y - (screen_y >> 3);
			map_up = screen_y >> 3;
			map_right = screen_x - (screen_x >> 3);
			map_left = screen_x >> 3;

			cross_key_size = (map_screen_x >> 3);
			//minimap_update = true;

			//ボタンサイズ変更
			i32 make_new_size_x = 0;
			i32 make_new_size_y = 0;
			i32 make_new_key_size = 0;

			i32 button_size = i32(buttonMap.size());
			for (i32 i = 0; i < button_size; i++) {
				if (buttonMap[i].use_rario) {
					make_new_size_x = i32(buttonMap[i].ratio_x*map_screen_x / 100.0f);
					make_new_size_y = i32(buttonMap[i].ratio_y*map_screen_y / 100.0f);
					make_new_key_size = i32(buttonMap[i].ratio_size * map_screen_x / 100.0f);

					if (buttonMap[i].ratio_size == -1) {
						buttonMap[i].start_x = make_new_size_x - player_look_pixel;
						buttonMap[i].start_y = make_new_size_y - (player_look_pixel >> 1);
						buttonMap[i].len_x = player_look_pixel;
						buttonMap[i].len_y = (player_look_pixel >> 1);
						buttonMap[i].end_x = make_new_size_x + player_look_pixel;
						buttonMap[i].end_y = make_new_size_y + (player_look_pixel >> 1);
					}
					else {
						buttonMap[i].start_x = make_new_size_x - make_new_key_size;
						buttonMap[i].start_y = make_new_size_y - (make_new_key_size >> 1);
						buttonMap[i].len_x = make_new_key_size;
						buttonMap[i].len_y = (make_new_key_size >> 1);
						buttonMap[i].end_x = make_new_size_x + make_new_key_size;
						buttonMap[i].end_y = make_new_size_y + (make_new_key_size >> 1);
					}
				}
			}

			makeGround();
			makeSquare();
		}
		//}
#endif
		return *this;
	}



	inline MainMap& MainMap::resize(MapData *resize_data, const u32 xx, const u32 yy)
	{
#if defined(__ANDROID__) //Android専用
		if (resize_data != nullptr)mapData[select_map_id] = resize_data;
#else
		if (resize_data != nullptr)mapData[select_map_id] = resize_data;
#endif
		subMapData[select_map_id].map_end_x = xx;
		subMapData[select_map_id].map_end_y = xx;
		subMap[select_map_id].resize(resize_data, xx, yy);

		return *this;
	}

	inline MainMap& MainMap::size()
	{
		x = subMapData[select_map_id].map_end_x;
		y = subMapData[select_map_id].map_end_y;
		r8 = rand_8;
		r32 = rand_32;

		return *this;
	}

	inline u8 MainMap::rand8(const u8 number)
	{
		u8 shift_1, shift_2, shift_3;

		switch (number)
		{
		case 0: shift_1 = 1; shift_2 = 1; shift_3 = 2; break;
		case 1: shift_1 = 1; shift_2 = 1; shift_3 = 3; break;
		case 2: shift_1 = 1; shift_2 = 7; shift_3 = 3; break;
		case 3: shift_1 = 1; shift_2 = 7; shift_3 = 6; break;
		case 4: shift_1 = 1; shift_2 = 7; shift_3 = 7; break;
		case 5: shift_1 = 2; shift_2 = 1; shift_3 = 1; break;
		case 6: shift_1 = 2; shift_2 = 5; shift_3 = 5; break;
		case 7: shift_1 = 3; shift_2 = 1; shift_3 = 1; break;
		case 8: shift_1 = 3; shift_2 = 1; shift_3 = 5; break;
		case 9: shift_1 = 3; shift_2 = 5; shift_3 = 4; break;
		case 10: shift_1 = 3; shift_2 = 5; shift_3 = 5; break;
		case 11: shift_1 = 3; shift_2 = 5; shift_3 = 7; break;
		case 12: shift_1 = 3; shift_2 = 7; shift_3 = 1; break;
		case 13: shift_1 = 4; shift_2 = 5; shift_3 = 3; break;
		case 14: shift_1 = 5; shift_2 = 1; shift_3 = 3; break;
		case 15: shift_1 = 5; shift_2 = 3; shift_3 = 6; break;
		case 16: shift_1 = 5; shift_2 = 3; shift_3 = 7; break;
		case 17: shift_1 = 5; shift_2 = 5; shift_3 = 2; break;
		case 18: shift_1 = 5; shift_2 = 5; shift_3 = 3; break;
		case 19: shift_1 = 6; shift_2 = 3; shift_3 = 5; break;
		case 20: shift_1 = 6; shift_2 = 7; shift_3 = 1; break;
		case 21: shift_1 = 7; shift_2 = 3; shift_3 = 5; break;
		case 22: shift_1 = 7; shift_2 = 5; shift_3 = 3; break;
		case 23: shift_1 = 7; shift_2 = 7; shift_3 = 1; break;
		default: shift_1 = 7; shift_2 = 7; shift_3 = 1; break;
		}

		rand_8 ^= (rand_8 << shift_1);
		rand_8 ^= (rand_8 >> shift_2);
		return rand_8 ^= (rand_8 << shift_3);
	}

	inline MainMap& MainMap::srand8(const u8 rand_8_SEED)
	{
		rand_8 = rand_8_SEED;
		return *this;
	}

	inline u8 MainMap::rand8_0toMax(const u8 i)
	{
		switch (i) {
		case 0:
			return 0;
		case UINT8_MAX:
			return rand8();
		default:
			return (rand8() % (i + 1));
		}
	}

	inline u32 MainMap::rand32()
	{
		rand_32 = rand_32 ^ (rand_32 << 13);
		rand_32 = rand_32 ^ (rand_32 >> 17);
		return rand_32 = rand_32 ^ (rand_32 << 5);
	}

	inline MainMap& MainMap::srand32(const u32 rand_32_SEED)
	{
		rand_32 = rand_32_SEED;
		return *this;
	}

	inline i32 MainMap::rand32_0toMax(const i32 i)
	{
		if (i <= 0) {
			return 0;
		}

		switch (i) {
		case INT32_MAX:
			return rand32();
		default:
			return ((rand32() & INT32_MAX) % (i + 1));
		}
	}

	inline MainMap& MainMap::drawInventory(const i32 pixel_size, const i32 pixel_x, const i32 pixel_y)
	{
		const i32 ui_size1 = (pixel_size / 12);
		const i32 ui_size2 = (pixel_size / 30);

		const i32 i_size = i32(inventory.size());
		for (i32 i = 0; i < i_size; i++) {
			const i32 rect_x = i * pixel_size + map_center_x + pixel_x - (pixel_size >> 1);
			const i32 rect_y = map_down + pixel_y - (pixel_size >> 1);
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
			drawGraphGCH(rect_x, rect_y, pixel_size, pixel_size, itembox_ui);
#endif
#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))

			Rect(rect_x, rect_y, pixel_size).draw(Color(0, 0, 0, 153));
			Rect(rect_x, rect_y, pixel_size).drawFrame(ui_size1, 0, Color(126, 126, 126));
			Rect(rect_x, rect_y, pixel_size).drawFrame(ui_size2, 0, Color(13, 2, 0));
#endif
			switch (inventory[i].id)
			{
			case NULL_U16:
			case 0:
				break;
			default:
				if (inventory[i].id<dngItem.size() && dngItem[inventory[i].id].texture_id < itemTexture.size()) {
					drawGraphGCH(rect_x, rect_y, pixel_size, pixel_size, itemTexture[dngItem[inventory[i].id].texture_id]);
					drawStringGCH(i * pixel_size + map_center_x + pixel_x, map_down + pixel_y, ColorGCH{ 255,255,255 }, inventory_font, "%d", inventory[i].stack);
				}
				break;
			}
		}

		return *this;
	}

	inline MainMap& MainMap::drawField(const i32 pixel_size)
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		drawBoxGCH(0, 0, subMapData[select_map_id].map_end_x*pixel_size, subMapData[select_map_id].map_end_y*pixel_size, ColorGCH{ 120,120,120 });
#endif
		i32 i_size;
		i32 j_size;

		for (i32 i = 0; i < subMapData[select_map_id].map_end_y; i++)
			for (i32 j = 0; j < subMapData[select_map_id].map_end_x; j++) {

				i_size = i * pixel_size;
				j_size = j * pixel_size;

				switch (subMap[select_map_id][i][j].field)
				{
				case 0:
					drawBoxGCH(j_size, i_size, pixel_size, pixel_size, ColorGCH{ 60, 160, 90 });
					break;
				case 1:
					drawBoxGCH(j_size, i_size, pixel_size, pixel_size, ColorGCH{ 223, 162, 112 });
					//drawMap(j_size, i_size, pixel_size, pixel_size, pixel_x, pixel_y, r, g, b);
					break;
				case 2:
					drawBoxGCH(j_size, i_size, pixel_size, pixel_size, ColorGCH{ 118, 151, 235 });
					break;
				}

				switch (subMap[select_map_id][i][j].floor)
				{
				case 0:
					break;
				default:

					if (subMap[select_map_id][i][j].floor <= floorTexture.size()) {
						drawGraphGCH(j_size, i_size, pixel_size, pixel_size, floorTexture[subMap[select_map_id][i][j].floor - 1]);
					}
					break;
				}

				switch (subMap[select_map_id][i][j].item)
				{
				case 0:
					break;

				default:
					if (subMap[select_map_id][i][j].item <= itemTexture.size()) {
						drawGraphGCH(j_size, i_size, pixel_size, pixel_size, itemTexture[subMap[select_map_id][i][j].item - 1]);
					}
					break;
				}
			}
		return *this;
	}

	inline MainMap& MainMap::drawMob(const i32 pixel_size)
	{
		i32 mob_start_x;
		i32 mob_start_y;

		const u16 mob_size = u16(mob.size());
		for (u16 i = 0; i < mob_size; i++) {

			if (mob[i].id >= u16(mobPicture.size()) || mob[i].id == 0) break;

			mob_start_x = i32((mob[i].x + mob[i].micro_x) * pixel_size);
			mob_start_y = i32((mob[i].y + mob[i].micro_y) * pixel_size);

			drawGraphGCH(mob_start_x, mob_start_y, pixel_size, pixel_size, mobPicture[mob[i].id - 1].id[mob[i].walk_type]);
		}

		return *this;
	}

	inline MainMap& MainMap::drawAll(const i32 pixel_size)
	{
		drawField(pixel_size);
		drawMob(pixel_size);
		return *this;
	}

	inline MainMap& MainMap::changeLineSize(const i32 after_line_size)
	{
		dngData.default_line_size = 8 / after_line_size;
		return *this;
	}

	inline u8 MainMap::mobMotionEvent(const u8 motion)
	{
		switch (motion)
		{
		case 0:
			return 1;
		case 1:
			return 0;
		case 2:
			return 2;
		case 3:
			return 0;
		}
		return 0;
	}

	inline void MainMap::addMotion(const u16 mob_id)
	{
		motion_count++;
		if (motion_count == 7) {
			mob[mob_id].motion = ((mob[mob_id].motion + 1) & 3);
			if (mob[mob_id].walk_direction >= 0 && mob[mob_id].walk_direction < 8) {
				mob[mob_id].walk_type = mob[mob_id].walk_direction + (mobMotionEvent(mob[mob_id].motion) << 3);
			}
			else {
				mob[mob_id].walk_type = mob[mob_id].walk_type + (mobMotionEvent(mob[mob_id].motion) << 3);
			}
			motion_count = 0;
		}
	}

	//mobのあたり判定
	inline MainMap& MainMap::mobCollisionDetection(u8 walk_type, const u16 mob_id)
	{
		if (mob_id >= u16(mob.size())) return *this;
		if (mob[mob_id].monster_id >= u16(monster.size())) return *this;

		mob[mob_id].walk = walk_type;
		mob[mob_id].walk_direction = walk_type;

		u8 on_move_type = MOB_NON_WALK_ID;
		const i32 mob_before_x = mob[mob_id].x;
		const i32 mob_before_y = mob[mob_id].y;
		i32 mob_after_x = 0;
		i32 mob_after_y = 0;

		u8 mob_before = 0;
		u8 mob_after = 0;
		u8 mob_left = 0;
		u8 mob_right = 0;

		bool on_move = false;
		bool moved = false;

		//壁破壊、壁通過は判定なし
		if (mob[mob_id].walk_id[WALK_TYPE_ID_FREE] || mob[mob_id].walk_id[WALK_TYPE_ID_WALL]) { //todo
			on_move_type = walk_type;
			walk_type = UINT8_MAX;
			on_move = true;
			moved = true;
		}

		if (!on_move) {
			switch (walk_type)
			{
			case MOB_WALK_ID_UP:
				mob_after_x = (mob[mob_id].x);
				mob_after_y = ((mob[mob_id].y - 1)&subMapData[select_map_id].map_end_yb);
				break;
			case MOB_WALK_ID_DOWN:
				mob_after_x = (mob[mob_id].x);
				mob_after_y = ((mob[mob_id].y + 1)&subMapData[select_map_id].map_end_yb);
				break;
			case MOB_WALK_ID_LEFT:
				mob_after_x = ((mob[mob_id].x - 1)&subMapData[select_map_id].map_end_xb);
				mob_after_y = (mob[mob_id].y);
				break;
			case MOB_WALK_ID_RIGHT:
				mob_after_x = ((mob[mob_id].x + 1)&subMapData[select_map_id].map_end_xb);
				mob_after_y = (mob[mob_id].y);
				break;
			case MOB_WALK_ID_LEFTUP:
				mob_after_x = ((mob[mob_id].x - 1)&subMapData[select_map_id].map_end_xb);
				mob_after_y = ((mob[mob_id].y - 1)&subMapData[select_map_id].map_end_yb);
				break;
			case MOB_WALK_ID_RIGHTUP:
				mob_after_x = ((mob[mob_id].x + 1)&subMapData[select_map_id].map_end_xb);
				mob_after_y = ((mob[mob_id].y - 1)&subMapData[select_map_id].map_end_yb);
				break;
			case MOB_WALK_ID_LEFTDOWN:
				mob_after_x = ((mob[mob_id].x - 1)&subMapData[select_map_id].map_end_xb);
				mob_after_y = ((mob[mob_id].y + 1)&subMapData[select_map_id].map_end_yb);
				break;
			case MOB_WALK_ID_RIGHTDOWN:
				mob_after_x = ((mob[mob_id].x + 1)&subMapData[select_map_id].map_end_xb);
				mob_after_y = ((mob[mob_id].y + 1)&subMapData[select_map_id].map_end_yb);
				break;
			}

			mob_before = dngField[subMap[select_map_id][mob_before_y][mob_before_x].field].walk_type;
			mob_after = dngField[subMap[select_map_id][mob_after_y][mob_after_x].field].walk_type;
			mob_left = dngField[subMap[select_map_id][mob_before_y][mob_after_x].field].walk_type;
			mob_right = dngField[subMap[select_map_id][mob_after_y][mob_before_x].field].walk_type;



			//空属性
			if (mob_after != WALK_TYPE_ID_WALL && mob[mob_id].walk_id[WALK_TYPE_ID_SKY]) {
				on_move = true;
			}//マグマ属性
			else if (mob_after != WALK_TYPE_ID_WALL && mob_after != WALK_TYPE_ID_WATER && mob_after != WALK_TYPE_ID_SKY && mob[mob_id].walk_id[WALK_TYPE_ID_MAGMA]) {
				on_move = true;
			}//水属性
			else if ((mob_after == WALK_TYPE_ID_GROUND || mob_after == WALK_TYPE_ID_WATER) && mob[mob_id].walk_id[WALK_TYPE_ID_WATER]) {
				on_move = true;
			}//普通の属性
			else if (mob_after == WALK_TYPE_ID_GROUND && mob[mob_id].walk_id[WALK_TYPE_ID_GROUND]) {
				on_move = true;
			}
			else {
				//walk_type = UINT8_MAX;
			}

			if (on_move) {
				switch (walk_type)
				{
				case MOB_WALK_ID_UP:
				case MOB_WALK_ID_DOWN:
				case MOB_WALK_ID_LEFT:
				case MOB_WALK_ID_RIGHT:
					on_move_type = walk_type;
					walk_type = UINT8_MAX;
					moved = true;
					break;

				case MOB_WALK_ID_LEFTUP:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = walk_type;
						moved = true;
					}
					break;
				case MOB_WALK_ID_RIGHTUP:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = walk_type;
						moved = true;
					}
					break;
				case MOB_WALK_ID_LEFTDOWN:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = walk_type;
						moved = true;
					}
					break;
				case MOB_WALK_ID_RIGHTDOWN:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = walk_type;
						moved = true;
					}
					break;
				}
			}



			if (!moved) {
				switch (walk_type)
				{
				case MOB_WALK_ID_LEFTUP:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						//printfDx("1\n");
						on_move_type = MOB_WALK_ID_LEFT;//
						mob[mob_id].walk = MOB_WALK_ID_LEFT;
						moved = true;
					}
					else if (mob_left == WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						//printfDx("2\n");
						on_move_type = MOB_WALK_ID_UP;//
						mob[mob_id].walk = MOB_WALK_ID_UP;
						moved = true;
					}
					else if (mob_left != WALK_TYPE_ID_WALL && mob_right == WALK_TYPE_ID_WALL) {
						//printfDx("3\n");
						on_move_type = MOB_WALK_ID_LEFT;//
						mob[mob_id].walk = MOB_WALK_ID_LEFT;
						moved = true;
					}
					break;
				case MOB_WALK_ID_RIGHTUP:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_UP;//
						mob[mob_id].walk = MOB_WALK_ID_UP;
						moved = true;
					}
					else if (mob_left == WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_UP;//
						mob[mob_id].walk = MOB_WALK_ID_UP;
						moved = true;
					}
					else if (mob_left != WALK_TYPE_ID_WALL && mob_right == WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_RIGHT;//
						mob[mob_id].walk = MOB_WALK_ID_RIGHT;
						moved = true;
					}
					break;
				case MOB_WALK_ID_LEFTDOWN:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_DOWN;//
						mob[mob_id].walk = MOB_WALK_ID_DOWN;
						moved = true;
					}
					else if (mob_left == WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_DOWN;//
						mob[mob_id].walk = MOB_WALK_ID_DOWN;
						moved = true;
					}
					else if (mob_left != WALK_TYPE_ID_WALL && mob_right == WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_LEFT;//
						mob[mob_id].walk = MOB_WALK_ID_LEFT;
						moved = true;
					}
					break;
				case MOB_WALK_ID_RIGHTDOWN:
					if (mob_left != WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_DOWN;//
						mob[mob_id].walk = MOB_WALK_ID_DOWN;
						moved = true;
					}
					else if (mob_left == WALK_TYPE_ID_WALL && mob_right != WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_DOWN;//
						mob[mob_id].walk = MOB_WALK_ID_DOWN;
						moved = true;
					}
					else if (mob_left != WALK_TYPE_ID_WALL && mob_right == WALK_TYPE_ID_WALL) {
						on_move_type = MOB_WALK_ID_RIGHT;//
						mob[mob_id].walk = MOB_WALK_ID_RIGHT;
						moved = true;
					}
					break;
				}
			}

			//switch (walk_type)
			//{
			//case MOB_WALK_ID_UP:
			//case MOB_WALK_ID_DOWN:
			//case MOB_WALK_ID_LEFT:
			//case MOB_WALK_ID_RIGHT:

			//	break;
			//case MOB_WALK_ID_LEFTUP:
			//case MOB_WALK_ID_RIGHTUP:
			//case MOB_WALK_ID_LEFTDOWN:
			//case MOB_WALK_ID_RIGHTDOWN:

			//	break;
			//}
		}

		if (!moved) {
			addMotion(mob_id);
			mob[mob_id].walk = MOB_NON_WALK_ID;
			return *this;
		}

		switch (on_move_type)
		{
		case MOB_WALK_ID_UP:
			mob[mob_id].micro_y -= MOB_WALK_SPEED;
			break;
		case MOB_WALK_ID_DOWN:
			mob[mob_id].micro_y += MOB_WALK_SPEED;
			break;
		case MOB_WALK_ID_LEFT:
			mob[mob_id].micro_x -= MOB_WALK_SPEED;
			break;
		case MOB_WALK_ID_RIGHT:
			mob[mob_id].micro_x += MOB_WALK_SPEED;
			break;
		case MOB_WALK_ID_LEFTUP:
			mob[mob_id].micro_x -= MOB_WALK_SPEED;
			mob[mob_id].micro_y -= MOB_WALK_SPEED;
			break;
		case MOB_WALK_ID_RIGHTUP:
			mob[mob_id].micro_x += MOB_WALK_SPEED;
			mob[mob_id].micro_y -= MOB_WALK_SPEED;
			break;
		case MOB_WALK_ID_LEFTDOWN:
			mob[mob_id].micro_x -= MOB_WALK_SPEED;
			mob[mob_id].micro_y += MOB_WALK_SPEED;
			break;
		case MOB_WALK_ID_RIGHTDOWN:
			mob[mob_id].micro_x += MOB_WALK_SPEED;
			mob[mob_id].micro_y += MOB_WALK_SPEED;
			break;
		}
		addMotion(mob_id);
		return *this;
	}

	inline MainMap& MainMap::moveKeyCheck()
	{
		//プレイヤーの入力確認
		key_check = keyCheck();

		u16 mob_size = u16(mob.size());
		for (u16 mob_id = 0; mob_id < mob_size; mob_id++) {
			switch (mob[mob_id].walk)
			{
			case MOB_NON_WALK_ID: //まだ歩いていない時

				switch (key_check)
				{
				default:
					mob[mob_id].walk = MOB_NON_WALK_ID;
					mob[mob_id].motion = 0;
					mob[mob_id].walk_type = (mob[mob_id].walk_type & 0x7);
					break;

				case MOB_WALK_ID_UP:
				case MOB_WALK_ID_DOWN:
				case MOB_WALK_ID_LEFT:
				case MOB_WALK_ID_RIGHT:
				case MOB_WALK_ID_LEFTUP:
				case MOB_WALK_ID_RIGHTUP:
				case MOB_WALK_ID_LEFTDOWN:
				case MOB_WALK_ID_RIGHTDOWN:
					//あたり判定
					mobCollisionDetection(key_check, mob_id);
					break;
				case MOB_WALK_ID_ATTACK:
					switch (mob[mob_id].walk_direction)
					{
					case MOB_WALK_ID_UP:
						mob[mob_id].micro_y -= MOB_WALK_SPEED;
						break;
					case MOB_WALK_ID_DOWN:
						mob[mob_id].micro_y += MOB_WALK_SPEED;
						break;
					case MOB_WALK_ID_LEFT:
						mob[mob_id].micro_x -= MOB_WALK_SPEED;
						break;
					case MOB_WALK_ID_RIGHT:
						mob[mob_id].micro_x += MOB_WALK_SPEED;
						break;
					case MOB_WALK_ID_LEFTUP:
						mob[mob_id].micro_x -= MOB_WALK_SPEED;
						mob[mob_id].micro_y -= MOB_WALK_SPEED;
						break;
					case MOB_WALK_ID_RIGHTUP:
						mob[mob_id].micro_x += MOB_WALK_SPEED;
						mob[mob_id].micro_y -= MOB_WALK_SPEED;
						break;
					case MOB_WALK_ID_LEFTDOWN:
						mob[mob_id].micro_x -= MOB_WALK_SPEED;
						mob[mob_id].micro_y += MOB_WALK_SPEED;
						break;
					case MOB_WALK_ID_RIGHTDOWN:
						mob[mob_id].micro_x += MOB_WALK_SPEED;
						mob[mob_id].micro_y += MOB_WALK_SPEED;
						break;
					}

					mob[mob_id].move_count++;
					if (mob[mob_id].move_count >= 10) {
						mob[mob_id].walk = MOB_NON_WALK_ID;
					}
					break;
				}

				break;

				//動いているとき
			case MOB_WALK_ID_UP:
				mob[mob_id].micro_y -= MOB_WALK_SPEED;
				addMotion(mob_id);
				//mob[mob_id].motion = ((mob[mob_id].motion + 1) & 3);
				if (mob[mob_id].micro_y <= -MOB_WALK_LENGTH) {
					mob[mob_id].micro_y = MOB_WALK_CLEAR;
					if (mob[mob_id].y != subMapData[select_map_id].map_start_y) mob[mob_id].y--;
					else mob[mob_id].y = subMapData[select_map_id].map_end_y - 1;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				break;
			case MOB_WALK_ID_DOWN:
				mob[mob_id].micro_y += MOB_WALK_SPEED;
				addMotion(mob_id);
				//mob[mob_id].motion = ((mob[mob_id].motion + 1) & 3);
				if (mob[mob_id].micro_y >= MOB_WALK_LENGTH) {
					mob[mob_id].micro_y = MOB_WALK_CLEAR;
					if (mob[mob_id].y != subMapData[select_map_id].map_end_y - 1) mob[mob_id].y++;
					else mob[mob_id].y = subMapData[select_map_id].map_start_y;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				break;
			case MOB_WALK_ID_LEFT:
				mob[mob_id].micro_x -= MOB_WALK_SPEED;
				addMotion(mob_id);
				//mob[mob_id].motion = ((mob[mob_id].motion + 1) & 3);
				if (mob[mob_id].micro_x <= -MOB_WALK_LENGTH) {
					mob[mob_id].micro_x = MOB_WALK_CLEAR;
					if (mob[mob_id].x != subMapData[select_map_id].map_start_x) mob[mob_id].x--;
					else mob[mob_id].x = subMapData[select_map_id].map_end_x - 1;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				break;
			case MOB_WALK_ID_RIGHT:
				mob[mob_id].micro_x += MOB_WALK_SPEED;
				addMotion(mob_id);
				//mob[mob_id].motion = ((mob[mob_id].motion + 1) & 3);
				if (mob[mob_id].micro_x >= MOB_WALK_LENGTH) {
					mob[mob_id].micro_x = MOB_WALK_CLEAR;
					if (mob[mob_id].x != subMapData[select_map_id].map_end_x - 1) mob[mob_id].x++;
					else mob[mob_id].x = subMapData[select_map_id].map_start_x;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				break;

			case MOB_WALK_ID_LEFTUP:
				mob[mob_id].micro_x -= MOB_WALK_SPEED;
				mob[mob_id].micro_y -= MOB_WALK_SPEED;
				addMotion(mob_id);
				if (mob[mob_id].micro_x <= -MOB_WALK_LENGTH) {
					mob[mob_id].micro_x = MOB_WALK_CLEAR;
					mob[mob_id].micro_y = MOB_WALK_CLEAR;
					if (mob[mob_id].y != subMapData[select_map_id].map_start_y) mob[mob_id].y--;
					else mob[mob_id].y = subMapData[select_map_id].map_end_y - 1;
					if (mob[mob_id].x != subMapData[select_map_id].map_start_x) mob[mob_id].x--;
					else mob[mob_id].x = subMapData[select_map_id].map_end_x - 1;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				break;
			case MOB_WALK_ID_RIGHTUP:
				mob[mob_id].micro_x += MOB_WALK_SPEED;
				mob[mob_id].micro_y -= MOB_WALK_SPEED;
				addMotion(mob_id);
				if (mob[mob_id].micro_x >= MOB_WALK_LENGTH) {
					mob[mob_id].micro_x = MOB_WALK_CLEAR;
					mob[mob_id].micro_y = MOB_WALK_CLEAR;
					if (mob[mob_id].y != subMapData[select_map_id].map_start_y) mob[mob_id].y--;
					else mob[mob_id].y = subMapData[select_map_id].map_end_y - 1;
					if (mob[mob_id].x != subMapData[select_map_id].map_end_x - 1) mob[mob_id].x++;
					else mob[mob_id].x = subMapData[select_map_id].map_start_x;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				break;
			case MOB_WALK_ID_LEFTDOWN:
				mob[mob_id].micro_x -= MOB_WALK_SPEED;
				mob[mob_id].micro_y += MOB_WALK_SPEED;
				addMotion(mob_id);
				if (mob[mob_id].micro_x <= -MOB_WALK_LENGTH) {
					mob[mob_id].micro_x = MOB_WALK_CLEAR;
					mob[mob_id].micro_y = MOB_WALK_CLEAR;
					if (mob[mob_id].y != subMapData[select_map_id].map_end_y - 1) mob[mob_id].y++;
					else mob[mob_id].y = subMapData[select_map_id].map_start_y;
					if (mob[mob_id].x != subMapData[select_map_id].map_start_x) mob[mob_id].x--;
					else mob[mob_id].x = subMapData[select_map_id].map_end_x - 1;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				addMotion(mob_id);
				break;
			case MOB_WALK_ID_RIGHTDOWN:
				mob[mob_id].micro_x += MOB_WALK_SPEED;
				mob[mob_id].micro_y += MOB_WALK_SPEED;
				addMotion(mob_id);
				if (mob[mob_id].micro_x >= MOB_WALK_LENGTH) {
					mob[mob_id].micro_x = MOB_WALK_CLEAR;
					mob[mob_id].micro_y = MOB_WALK_CLEAR;
					if (mob[mob_id].y != subMapData[select_map_id].map_end_y - 1) mob[mob_id].y++;
					else mob[mob_id].y = subMapData[select_map_id].map_start_y;
					if (mob[mob_id].x != subMapData[select_map_id].map_end_x - 1) mob[mob_id].x++;
					else mob[mob_id].x = subMapData[select_map_id].map_start_x;
					mob[mob_id].walk = MOB_NON_WALK_ID;
					if (mob[mob_id].id == MOB_ID_PLAYER) playerWalkEndEvent(mob_id);
				}
				break;


			case MOB_WALK_ID_ATTACK:
				//if()
				switch (mob[mob_id].walk_direction)
				{
				case MOB_WALK_ID_UP:
					mob[mob_id].micro_y -= MOB_WALK_SPEED;
					break;
				case MOB_WALK_ID_DOWN:
					mob[mob_id].micro_y += MOB_WALK_SPEED;
					break;
				case MOB_WALK_ID_LEFT:
					mob[mob_id].micro_x -= MOB_WALK_SPEED;
					break;
				case MOB_WALK_ID_RIGHT:
					mob[mob_id].micro_x += MOB_WALK_SPEED;
					break;
				case MOB_WALK_ID_LEFTUP:
					mob[mob_id].micro_x -= MOB_WALK_SPEED;
					mob[mob_id].micro_y -= MOB_WALK_SPEED;
					break;
				case MOB_WALK_ID_RIGHTUP:
					mob[mob_id].micro_x += MOB_WALK_SPEED;
					mob[mob_id].micro_y -= MOB_WALK_SPEED;
					break;
				case MOB_WALK_ID_LEFTDOWN:
					mob[mob_id].micro_x -= MOB_WALK_SPEED;
					mob[mob_id].micro_y += MOB_WALK_SPEED;
					break;
				case MOB_WALK_ID_RIGHTDOWN:
					mob[mob_id].micro_x += MOB_WALK_SPEED;
					mob[mob_id].micro_y += MOB_WALK_SPEED;
					break;
				}

				if (mob[mob_id].micro_x >= 1.0f || mob[mob_id].micro_x <= -1.0f || mob[mob_id].micro_y >= 1.0f || mob[mob_id].micro_y <= -1.0f) {
					mob[mob_id].micro_x = MOB_WALK_CLEAR;
					mob[mob_id].micro_y = MOB_WALK_CLEAR;
					mob[mob_id].walk = MOB_NON_WALK_ID;
				}

				break;

			}
		}
		return *this;
	}

	inline MainMap& MainMap::optionKeyCheck()
	{
		if (clickKeyGCH(KEY_ID_HOME)) {
			if (!default_layer) default_layer = 1;
			else default_layer = 0;
		}
		return *this;
	}

	inline MainMap& MainMap::upFloorKeyCheck()
	{
		if (clickKeyGCH(KEY_ID_P)) this->makeD();
		return *this;
	}

	inline MainMap & MainMap::playerThrowKeyCheck()
	{
		if (!clickKeyGCH(KEY_ID_Q)) return *this;

		u16 mob_size = u16(mob.size());
		for (u16 i = 0; i < mob_size; i++) {
			if (mob[i].id == MOB_ID_PLAYER) {
				playerItemThrowEvent(i);
				break;
			}
		}
		return *this;
	}

	inline MainMap& MainMap::squareKeyCheck()
	{
		if (clickKeyGCH(KEY_ID_O)) {
			if (use_square) use_square = false;
			else use_square = true;
		}
		return *this;
	}

	inline MainMap& MainMap::stringKeyCheck()
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		if (click_key_g[KEY_ID_LALT]) {
#if defined(__ANDROID__) //Android専用
			//AndroidNotification("title", "SubTitle", -1, TRUE, TRUE, 0, nullptr, 0, 0, 0, 0);
			this->androidString();
			//printfDx("%s", InputString);
#endif
		}
#endif
		return *this;
	}

	inline MainMap& MainMap::twitterKeyCheck()
	{
#if defined(__ANDROID__) //Android専用
		if (click_key_g[KEY_ID_RALT]) {
			AndroidJumpURL("http://twitter.com", nullptr, nullptr);
		}
#endif
		return *this;
	}

	//mobの動作やボタンの操作
	inline MainMap& MainMap::move()
	{
		//printfDx("%d ", default_layer);

		upFloorKeyCheck();
		squareKeyCheck();
		optionKeyCheck();
		twitterKeyCheck();
		stringKeyCheck();

		switch (default_layer)
		{
		case 0:
			moveKeyCheck();
			playerThrowKeyCheck();
			break;
		case LAYER_ID_UP_STAIRS:
			upStairsEvent();
			break;
		case LAYER_ID_TALK:
			checkEvent();
			break;
		default:
			break;
		}

		return *this;
	}

	inline MainMap& MainMap::drawMiniMapX(i32 pixel_x, i32 pixel_y, u8 r, u8 g, u8 b)
	{
		const i32 line_size = map_screen_x / subMapData[select_map_id].map_end_x;
		drawMiniMap(line_size, pixel_x, pixel_y, r, g, b);
		return *this;
	}


	inline MainMap& MainMap::drawMiniMap(i32 line_size, i32 pixel_x, i32 pixel_y, u8 r, u8 g, u8 b)
	{
		if (!on_minimap) return *this;

		u8 terrain = 0;

		i32 start_x_line_size;
		i32 start_y_line_size;
		i32 end_x_line_size;
		i32 end_y_line_size;
		i32 center_x_line_size;
		i32 center_y_line_size;
		f32 line_size_f;

		i32 line_size_half = (line_size >> 1);

#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))

		i32 default_line_size_half = (dngData.default_line_size >> 1);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 240);
		unsigned int color = GetColor(r, g, b);
		unsigned int minimap_color = GetColor(r, g, b);
		unsigned int minimap_item_color = GetColor(100, 100, 255);
		ColorGCH minimap_floor_color = { 100, 255, 100 };

		//dngData.default_line_size = 8;

		//if (minimap_size != dngData.default_line_size || minimap_update) {
		if (minimap_size != dngData.default_line_size) {
			if (minimap_size) DeleteGraph(make_minimap);
			make_minimap = MakeScreen(subMapData[select_map_id].map_end_x*dngData.default_line_size, subMapData[select_map_id].map_end_y*dngData.default_line_size, TRUE);
			minimap_size = dngData.default_line_size;
		}

		if (!minimap_update)
		{
			drawGraphGCH(0, 0, subMapData[select_map_id].map_end_x*line_size, subMapData[select_map_id].map_end_y*line_size, make_minimap);
		}
		else {

			SetDrawScreen(make_minimap);
			ClearDrawScreen();

			/*全てのマップを選択*/
			for (i32 i = 0; i < subMapData[select_map_id].map_end_y; i++) {

				start_y_line_size = i * dngData.default_line_size + pixel_y;
				end_y_line_size = start_y_line_size + dngData.default_line_size;
				center_y_line_size = start_y_line_size + default_line_size_half;

				for (i32 j = 0; j < subMapData[select_map_id].map_end_x; j++) {

					terrain = subMap[select_map_id][i][j].terrain;
					start_x_line_size = j * dngData.default_line_size + pixel_x;
					end_x_line_size = start_x_line_size + dngData.default_line_size;
					center_x_line_size = start_x_line_size + default_line_size_half;

					line_size_f = f32(line_size) / f32(dngData.default_line_size);

					//部屋の線画
					switch (terrain)
					{
					case 0b0000:
					case 0b10000:
						break;

					case 0b0001:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b0010:
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						break;
					case 0b0011:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						break;
					case 0b0100:
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b0101:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b0110:
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b0111:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1000:
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1001:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1010:
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1011:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1100:
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1101:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1110:
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					case 0b1111:
						DrawLine(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size, color, TRUE);
						DrawLine(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size, color, TRUE);
						DrawLine(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size, color, TRUE);
						break;
					}

					switch (terrain)
					{
					case 0:break;

					default:
						switch (subMap[select_map_id][i][j].item) {
						case 0:break;
						default: DrawCircle(center_x_line_size, center_y_line_size, default_line_size_half, minimap_item_color, TRUE); break;
						}
						switch (subMap[select_map_id][i][j].floor) {
						case 0:break;
						default: drawBoxGCH(start_x_line_size, start_y_line_size, dngData.default_line_size, dngData.default_line_size, minimap_floor_color); break;
						}

						break;
					}

				}
			}
			SetDrawScreen(DX_SCREEN_BACK);
			drawGraphGCH(0, 0, subMapData[select_map_id].map_end_x*line_size, subMapData[select_map_id].map_end_y*line_size, make_minimap);
			minimap_update = false;
		}

		unsigned int minimap_player_color = GetColor(255, 255, 100);

		u16 mob_size = u16(mob.size());
		for (u16 i = 0; i < mob_size; i++) {
			if (subMap[select_map_id][mob[i].y][mob[i].x].terrain) {

				switch (mob[i].id)
				{
				case 1:
					center_y_line_size = i32((mob[i].y + mob[i].micro_y) * line_size) + pixel_y + line_size_half;
					center_x_line_size = i32((mob[i].x + mob[i].micro_x) * line_size) + pixel_x + line_size_half;
					DrawCircle(center_x_line_size, center_y_line_size, line_size_half, minimap_player_color, TRUE);
					break;
				}

			}
		}

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
#endif
#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))

		Color minimap_color = Color(r, g, b, 220);
		Color minimap_item_color = Color(100, 100, 255, 220);
		Color minimap_floor_color = Color(100, 255, 100, 220);
		line_size_f = f32(line_size) / f32(dngData.default_line_size);

		/*全てのマップを選択*/
		for (i32 i = 0; i < subMapData[select_map_id].map_end_y; i++) {

			start_y_line_size = i * line_size + pixel_y;
			end_y_line_size = start_y_line_size + line_size;
			center_y_line_size = start_y_line_size + line_size_half;

			for (i32 j = 0; j < subMapData[select_map_id].map_end_x; j++) {

				terrain = subMap[select_map_id][i][j].terrain;
				start_x_line_size = j * line_size + pixel_x;
				end_x_line_size = start_x_line_size + line_size;
				center_x_line_size = start_x_line_size + line_size_half;


				//部屋の線画
				switch (terrain)
				{
				case 0b0000:
				case 0b10000:
					break;
				case 0b0001:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b0010:
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b0011:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b0100:
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b0101:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b0110:
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b0111:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1000:
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1001:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1010:
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1011:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1100:
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1101:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1110:
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				case 0b1111:
					Line(start_x_line_size, end_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, end_x_line_size, start_y_line_size).draw(line_size_f, minimap_color);
					Line(start_x_line_size, start_y_line_size, start_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					Line(end_x_line_size, start_y_line_size, end_x_line_size, end_y_line_size).draw(line_size_f, minimap_color);
					break;
				}

				switch (terrain)
				{
				case 0:break;

				default:
					switch (subMap[select_map_id][i][j].item) {
					case 0:break;
					default: Circle(center_x_line_size, center_y_line_size, line_size_half).draw(minimap_item_color); break;
					}
					switch (subMap[select_map_id][i][j].floor) {
					case 0:break;
					default: Rect(start_x_line_size, start_y_line_size, line_size, line_size).drawFrame(line_size_f, 0, minimap_floor_color); break;
					}

					break;
				}

			}
		}

		Color minimap_player_color = Color(255, 255, 100, 220);

		u16 mob_size = u16(mob.size());
		for (u16 i = 0; i < mob_size; i++) {
			if (subMap[select_map_id][mob[i].y][mob[i].x].terrain) {

				switch (mob[i].id)
				{
				case 1:
					center_y_line_size = i32((mob[i].y + mob[i].micro_y) * line_size) + pixel_y + line_size_half;
					center_x_line_size = i32((mob[i].x + mob[i].micro_x) * line_size) + pixel_x + line_size_half;
					Circle(center_x_line_size, center_y_line_size, line_size_half).draw(minimap_player_color);
					break;
				}

			}
		}

#endif
		return *this;
	}


	//プレーヤーが動き終わった後のイベント
	inline MainMap& MainMap::playerWalkEndEvent(const u16 player_id)
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		minimap_update = true;
#endif
		playerBreakEvent(player_id);
		makeAroundMiniMap(player_id);
		makeRoomMiniMap(player_id);
		playerItemGetEvent(player_id);
		playerStairsEvent(player_id);
		playerMapMoveEvent(player_id);
		return *this;
	}

	inline MainMap& MainMap::playerBreakEvent(const u16 mob_id)
	{
		if (!mob[mob_id].walk_id[WALK_TYPE_ID_FREE]) return *this;
		if (subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].field) {
			subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].field = 0;
		}
		return *this;
	}

	inline MainMap& MainMap::playerItemThrowEvent(const u16 mob_id)
	{
		if (select_inventory >= u16(inventory.size())) return *this;

		u16 ground_item = subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item;
		u8 ground_item_stack = subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item_stack;
		//bool get_item = false;

		if (ground_item) {
			subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item = inventory[select_inventory].id;
			subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item_stack = inventory[select_inventory].stack;
			inventory[select_inventory].id = ground_item;
			inventory[select_inventory].stack = ground_item_stack;
		}
		else {
			subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item = inventory[select_inventory].id;
			subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item_stack = inventory[select_inventory].stack;
			inventory[select_inventory].id = 0;
			inventory[select_inventory].stack = 0;
		}
		return *this;
	}

	inline MainMap& MainMap::playerItemGetEvent(const u16 mob_id)
	{
		u16 ground_item = subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item;
		u8 ground_item_stack = subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item_stack;
		bool get_item = false;

		if (ground_item) {

			u16 inventory_size = u16(inventory.size());
			for (u16 i = 0; i < inventory_size; i++) {

				if (!inventory[i].id) {
					inventory[i].id = ground_item;
					inventory[i].stack += ground_item_stack;
					get_item = true;
					break;
				}
				//dngItem[ground_item - 1].stack
				if (inventory[i].id == ground_item && (inventory[i].stack + ground_item_stack) <= dngItem[ground_item].stack) {
					inventory[i].stack += ground_item_stack;
					get_item = true;
					break;
				}
			}
			if (!get_item && u16(inventory.size()) < inventory_max) {
				Inventory new_item;
				new_item.id = ground_item;
				new_item.stack = ground_item_stack;
#if defined(__ANDROID__) //Android専用
				inventory.push_back(new_item);
#else
				inventory.emplace_back(new_item);
#endif

				get_item = true;
			}

			if (get_item) {
				subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item = 0;
				subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item_stack = 0;

				//ログ
				addLog(mob_id, LOG_ID_PICK_UP, i32(ground_item)).windowWriteOn(WINDOW_ID_LOG).windowWriteLog();
			}
			else addLog(mob_id, LOG_ID_RIDE, i32(ground_item)).windowWriteOn(WINDOW_ID_LOG).windowWriteLog();
		}
		return *this;
	}

	inline MainMap& MainMap::playerStairsEvent(const u16 mob_id)
	{
		if (subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].floor == default_stairs_id) {
			if (on_fast_up_stairs) default_layer = LAYER_ID_UP_STAIRS;
			else default_layer = LAYER_ID_SELECT_UP_STAIRS;
		}
		return *this;
	}

	inline MainMap& MainMap::playerMapMoveEvent(const u16 mob_id)
	{
		u8 player_map_move = subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].map_move;
		if (player_map_move != UINT8_MAX && player_map_move < map_move_total_count) {
			select_map_id = player_map_move;
		}
		return *this;
	}

	inline MainMap& MainMap::mobItemGetEvent(const u16 mob_id)
	{
		u16 ground_item = subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item;
		if (ground_item && !mob[mob_id].hand) {
			mob[mob_id].hand = ground_item;
			subMap[select_map_id][mob[mob_id].y][mob[mob_id].x].item = 0;
		}
		return *this;
	}

	inline MainMap& MainMap::makeAroundMiniMap(i32 player_id)
	{
		u8 line_count = 0;
		i32 player_x;
		i32 player_y;

		fieldTrrainCheck(mob[player_id].x - 1, mob[player_id].x + 1, mob[player_id].y - 1, mob[player_id].y + 1);

		//プレイヤーが通ってきた道(周囲3*3)をマップとして線画
		for (i32 i = -1; i < 2; i++) {
			player_x = mob[player_id].x + i;
			for (i32 j = -1; j < 2; j++) {
				line_count = 0; //マップ表示の数値
				player_y = mob[player_id].y + j;

				if (((player_x - 1) >= subMapData[select_map_id].map_start_x) && ((player_y - 1) >= subMapData[select_map_id].map_start_y) && ((player_x + 1) < subMapData[select_map_id].map_end_x) && ((player_y + 1) < subMapData[select_map_id].map_end_y)) {

					switch (subMap[select_map_id][player_y][player_x].field)
					{
					case 0:
						if (subMap[select_map_id][player_y + 1][player_x].field != 0) {
							line_count++;
						}
						if (subMap[select_map_id][player_y - 1][player_x].field != 0) {
							line_count += 2;
						}
						if (subMap[select_map_id][player_y][player_x - 1].field != 0) {
							line_count += 4;
						}
						if (subMap[select_map_id][player_y][player_x + 1].field != 0) {
							line_count += 8;
						}
						if (line_count < 1) {
							line_count = 16;
						}
						subMap[select_map_id][player_y][player_x].terrain = line_count;
						break;

					default:
						subMap[select_map_id][player_y][player_x].terrain = 0;
						break;
					}
				}

			}
		}
		return *this;
	}

	inline MainMap& MainMap::makeRoomMiniMap(i32 player_id)
	{
		u8 line_count = 0;
		u16 player_field = 0;
		mob[player_id].room = 0; //プレイヤーの位置情報を初期化
								 //プレイヤーが部屋に入ったときに線画する
		for (i32 i = 0; i < dngData.division_count; i++) {
			if (dngList[i].room_apex[2] <= mob[player_id].x && dngList[i].room_apex[0] > mob[player_id].x && dngList[i].room_apex[3] <= mob[player_id].y && dngList[i].room_apex[1] > mob[player_id].y) {
				dngList[i].room_entered_player = 1; //プレイヤーがどこの部屋に入ったか記憶
														//プレイヤーの部屋情報を記録
				mob[player_id].room = i + 1;
			}
			if (dngList[i].room_entered_player == 1) {

				for (i32 k = dngList[i].room_apex[3] - 1; k <= dngList[i].room_apex[1]; k++) {
					for (i32 j = dngList[i].room_apex[2] - 1; j <= dngList[i].room_apex[0]; j++) {
						line_count = 0;
						player_field = subMap[select_map_id][k][j].field;

						if (((j - 1) >= subMapData[select_map_id].map_start_x) && ((k - 1) >= subMapData[select_map_id].map_start_y) && ((j + 1) < subMapData[select_map_id].map_end_x) && ((k + 1) < subMapData[select_map_id].map_end_y)) {
							if (subMap[select_map_id][k + 1][j].field != player_field) {
								line_count++;
							}
							if (subMap[select_map_id][k - 1][j].field != player_field) {
								line_count += 2;
							}
							if (subMap[select_map_id][k][j - 1].field != player_field) {
								line_count += 4;
							}
							if (subMap[select_map_id][k][j + 1].field != player_field) {
								line_count += 8;
							}
							if (line_count < 1) {
								line_count = 16;
							}
							subMap[select_map_id][k][j].terrain = line_count;
						}
					}
				}
			}
		}
		return *this;
	}

	inline MainMap& MainMap::makeAllMiniMap()
	{
		u8 line_count = 0;
		u16 player_field = 0;

		for (i32 i = subMapData[select_map_id].map_start_y; i < subMapData[select_map_id].map_end_y; i++) {
			for (i32 j = subMapData[select_map_id].map_start_x; j < subMapData[select_map_id].map_end_x; j++) {
				line_count = 0;


				if (((j - 1) >= subMapData[select_map_id].map_start_x) && ((i - 1) >= subMapData[select_map_id].map_start_y) && ((j + 1) < subMapData[select_map_id].map_end_x) && ((i + 1) < subMapData[select_map_id].map_end_y)) {
					switch (subMap[select_map_id][i][j].field)
					{
					case 0:

						player_field = subMap[select_map_id][i][j].field;

						if (subMap[select_map_id][i + 1][j].field != player_field) {
							line_count++;
						}
						if (subMap[select_map_id][i - 1][j].field != player_field) {
							line_count += 2;
						}
						if (subMap[select_map_id][i][j - 1].field != player_field) {
							line_count += 4;
						}
						if (subMap[select_map_id][i][j + 1].field != player_field) {
							line_count += 8;
						}
						if (line_count < 1) {
							line_count = 16;
						}
						subMap[select_map_id][i][j].terrain = line_count;
						break;
					default:
						subMap[select_map_id][i][j].terrain = 0;
						break;

					}
				}
			}
		}
		return *this;
	}

	inline MainMap& MainMap::addMap(u32 add_map_x, u32 add_map_y, MapData* add_map_data)
	{
		if (map_move_total_count == UINT8_MAX) return *this;

#if defined(__ANDROID__) //Android専用
		if (add_map_data != nullptr)mapData[map_move_total_count] = add_map_data;
#else
		if (add_map_data != nullptr)mapData[map_move_total_count] = add_map_data;
#endif
		subMapData[map_move_total_count].map_end_x = add_map_x;
		subMapData[map_move_total_count].map_end_y = add_map_y;
		subMapData[map_move_total_count].map_end_xb = add_map_x - 1;
		subMapData[map_move_total_count].map_end_yb = add_map_y - 1;
		subMapData[map_move_total_count].map_total = add_map_x * add_map_y;

		subMap[map_move_total_count].resize(add_map_data, add_map_x, add_map_y);

		map_move_total_count++;
		return *this;
	}

	//----------    class MainMap    ----------


	//コンストラクタ(MainMapのものを継承)
	inline MainMap::MainMap(MapData *dngList, const u32 xx, const u32 yy, const u32 screen_x, const u32 screen_y)
	{
		addMap(xx, yy, dngList);

		u8 bit_x = 0;
		u8 bit_y = 0;
		for (i32 i = 0; i < 32; i++) {
			if (xx&(1 << i)) bit_x++;
			if (yy&(1 << i)) bit_y++;
		}
		if (bit_x == 1 && bit_y == 1) bit_flag = true;

		map_screen_x = screen_x;
		map_screen_y = screen_y;
		map_center_x = screen_x >> 1;
		map_center_y = screen_y >> 1;
		map_down = screen_y - (screen_y >> 3);
		map_up = screen_y >> 3;
		map_right = screen_x - (screen_x >> 3);
		map_left = screen_x >> 3;


		//ウィンドウ系
		windowData.corner_x = i32(map_screen_x*0.8f / 64.0f);
		windowData.corner_y = i32(map_screen_y*0.4f / 64.0f);
		windowData.pos_x = i32(map_screen_x*0.1f);
		windowData.pos_y = i32(map_screen_y*0.55f);
		windowData.len_x = windowData.corner_x * 64;
		windowData.len_y = windowData.corner_y * 64;
		if (windowData.corner_x <= windowData.corner_y) windowData.corner_x = windowData.corner_y;
		else windowData.corner_y = windowData.corner_x;

		windowData.font = createFontGCH("aaa", i32(windowData.corner_x*3.3f));

		inventory_font = createFontGCH("Playbill", map_screen_x / 32);

		//乱数SEED作成
		time_t a = time(nullptr), ff = UINT8_MAX;
		rand_8 = u8(a & ff);
		if (!rand_8) rand_8++;

		rand_32 = u32(a) + (u32(rand8(a & 15)) << 24);
		if (!rand_32) rand_32++;

		//キーコンフィグ設定
		for (u8 i = 0; i <= UINT8_MAX; i++) {
			keyconfig_g[i] = i;
			if (i == UINT8_MAX) break;
		}
		//ダンジョン


		//this->make();

		inventory.resize(inventory_max);

		cross_key_size = (map_screen_x >> 3);

		makeInventoryUI();

		loadInventory();

		//線画用
		if (map_screen_y > map_screen_x) player_look_len = i32(player_look_len*map_screen_x / f32(map_screen_y)) - 1;

		player_look_len_half = player_look_len / 2 + 2;
		player_look_pixel = map_screen_x / player_look_len;
		player_look_pixel_half = player_look_pixel / 2;
		player_look_pixel_quarter = player_look_pixel / 4;


		//loadMap();

		//World
		chunk_len_x = subMapData[select_map_id].map_end_x >> 4;
		chunk_len_y = subMapData[select_map_id].map_end_y >> 4;

		world_make_rand_x = rand8();
		world_make_rand_y = rand8();




			}

	inline MainMap::~MainMap()
	{
		saveInventory();
		saveOption();
		saveMap();
	}

	inline MainMap& MainMap::makeFieldD()
	{
		this->upFloor();

		//初期化処理
		dngData.room_total_area = 0;
		dngData.room_count = 0;

		minimap_update = true;

		//マップを全て初期化
		for (i32 i = 0; i < subMapData[select_map_id].map_total; i++) {
			mapData[select_map_id][i].field = dngData.default_make_field_id;
			mapData[select_map_id][i].item = 0;
			mapData[select_map_id][i].item_stack = 0;
			mapData[select_map_id][i].terrain = 0;
			mapData[select_map_id][i].floor = 0;
			mapData[select_map_id][i].map_move = 0;
		}

		//水路生成
		if (dngData.default_make_rand_pool_id != NULL_U16) makeRandPoolD();

		//for (u8 i = 0; i < dng_room_count; i++) {


		//}
		//			//dngList std::vector初期化
		//			dngList.clear();
		//#if !defined(__ANDROID__) //Android以外専用
		//			dngList.shrink_to_fit();
		//#endif
		//mob std::vector初期化
		mob_player_id = NULL_U16;
		mob.clear();
#if !defined(__ANDROID__) //Android以外専用
		mob.shrink_to_fit();
#endif
		//マップの区分け数(部屋の個数)を決める
		dngData.division_count = dngData.division_min + rand8_0toMax(dngData.division_len);
		if (dngData.division_count < dngData.division_min || dngData.division_count == 0 || dngData.division_count == UINT8_MAX) dngData.division_count = 2;

		//ダンジョン配列数を指定
		dngList_size = dngData.division_count;

		//マップの区分け初期サイズ指定
		dngList[0].division_apex[DUNGEON_DIVISION_ID_FIRST_X] = 1;
		dngList[0].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] = 1;
		dngList[0].division_apex[DUNGEON_DIVISION_ID_LAST_X] = (subMapData[select_map_id].map_end_x - 1);
		dngList[0].division_apex[DUNGEON_DIVISION_ID_LAST_Y] = (subMapData[select_map_id].map_end_y - 1);

		dngList[0].roadLine[DUNGEON_COUNT_ID_X] = UINT8_MAX;
		dngList[0].roadLine[DUNGEON_COUNT_ID_Y] = UINT8_MAX;


		//マップを区分けしていく処理(区域を分割する処理)
		u8 division_after;

		//(0:X, 1:Y) X軸で分けるかY軸で分けるか決める
		u8 count;

		i32 after_last_x;
		i32 after_last_y;
		i32 after_first_x;
		i32 after_first_y;

		for (u8 i = 1; i < dngData.division_count; i++) {

			//今まで作った区分けをランダムに指定(指定した区域をさらに区分けする)
			division_after = rand8_0toMax(i - 1);

			//指定した区域のXとYの長さによって、分割する向きを決める(長いほうを分割する)
			after_last_x = dngList[division_after].division_apex[DUNGEON_DIVISION_ID_LAST_X];
			after_last_y = dngList[division_after].division_apex[DUNGEON_DIVISION_ID_LAST_Y];
			after_first_x = dngList[division_after].division_apex[DUNGEON_DIVISION_ID_FIRST_X];
			after_first_y = dngList[division_after].division_apex[DUNGEON_DIVISION_ID_FIRST_Y];

			if (after_last_x - after_first_x > after_last_y - after_first_x) count = DUNGEON_COUNT_ID_X;
			else count = DUNGEON_COUNT_ID_Y;

			if (dngList[division_after].division_apex[count] - dngList[division_after].division_apex[count + 2] < dngData.division_len * 2 + 8) {
				i32 k = 0;
				for (u8 j = 1; j < dngData.division_count; j++) {
					if (dngList[j].division_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[j].division_apex[DUNGEON_DIVISION_ID_FIRST_X] > k) {
						k = dngList[j].division_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[j].division_apex[DUNGEON_DIVISION_ID_FIRST_X];
						division_after = j;
						count = DUNGEON_COUNT_ID_X;
					}
					if (dngList[j].division_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[j].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] > k) {
						k = dngList[j].division_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[j].division_apex[DUNGEON_DIVISION_ID_FIRST_Y];
						division_after = j;
						count = DUNGEON_COUNT_ID_Y;
					}
				}
			}

			dngList[i].roadLine[DUNGEON_COUNT_ID_X] = division_after;
			dngList[i].roadLine[DUNGEON_COUNT_ID_Y] = count;

			for (u8 j = 1; j < i; j++)
				if (dngList[j].roadLine[DUNGEON_COUNT_ID_X] == division_after) dngList[j].roadLine[DUNGEON_COUNT_ID_X] = i;

			//count軸の設定
			dngList[i].division_apex[count] = dngList[division_after].division_apex[count + 2] + (dngList[division_after].division_apex[count] - dngList[division_after].division_apex[count + 2]) / 3 + rand32_0toMax((dngList[division_after].division_apex[count] - dngList[division_after].division_apex[count + 2]) / 3); //0.軸の右端(iR)の座標(division_after*R/3~2division_after*R/3)
			dngList[i].division_apex[count + 2] = dngList[division_after].division_apex[count + 2]; //0.軸の左端(iL)の座標(division_afterL)
			dngList[division_after].division_apex[count + 2] = dngList[i].division_apex[count]; //division_after軸の左端(division_afterL)の座標(iR)

																										//countとは逆の軸の設定
			dngList[i].division_apex[notBit(count)] = dngList[division_after].division_apex[notBit(count)]; //軸の右端(iR)の座標(division_afterR)
			dngList[i].division_apex[notBit(count) + 2] = dngList[division_after].division_apex[notBit(count) + 2]; //軸の左端(iL)の座標(division_afterL)
		}





		//部屋を生成する処理
		for (u8 i = 0; i < dngData.division_count; i++) {//区分け
			dngList[i].room_entered_player = false;//プレイヤー侵入初期化
			dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_X] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_X]; //区分けX始点をマップX始点へ代入
			dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_Y] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_Y]; //区分けY始点をマップY始点へ代入

																															   //X座標の部屋の長さを指定
			dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_X] + dngData.division_len + rand8_0toMax(dngData.room_len_x);
			if (dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_X] < dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_X] + 5) {
				dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] = dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_X] - 4;
				if (dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_X] < dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_X] + 5) {
					dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_X] + 1;
				}
			}

			dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] + dngData.room_min_y + rand32_0toMax(dngData.room_len_y);
			if (dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] < dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_Y] + 5) {
				dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] = dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_Y] - 4;
				if (dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] < dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_Y] + 5) {
					dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] + 1;
				}
			}

			if (dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_X] <= 1 || dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] <= 1) {
				dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_X] + 1;
				dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] = dngList[i].division_apex[DUNGEON_DIVISION_ID_FIRST_Y] + 1;
			}
			i32 l = rand32_0toMax(dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] - 5) + 2;
			i32 m = rand32_0toMax(dngList[i].division_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] - 5) + 2;
			dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X] += l;
			dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_X] += l;
			dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y] += m;
			dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_Y] += m;

			for (i32 k = dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]; k < dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_Y]; k++) {
				for (i32 j = dngList[i].room_apex[DUNGEON_DIVISION_ID_FIRST_X]; j < dngList[i].room_apex[DUNGEON_DIVISION_ID_LAST_X]; j++) {

					subMap[select_map_id][k][j].field = 0;
					dngList[i].room_area++;
				}
			}

			if (dngList[i].room_area > 1) {
				dngList[dngData.room_count].room_id = i;
				dngData.room_count++;
				dngData.room_total_area += dngList[i].room_area;
			}

		}




		//通路を生成する処理
		//通路は２部屋間の細い道のことを指す。
		//通路を作るために２部屋をそれぞれ前(Before)と後(After)で分ける。
		//for文で全ての部屋をチェックし、前後の部屋を繋ぐ通路を作る。
		//まず、前の通路を作り、次に後の通路を作る。
		//最後に前と後の通路を繋げる。

		u8 room_after;
		for (u8 room_before = 0; room_before < dngData.division_count; room_before++) {
			room_after = dngList[room_before].roadLine[DUNGEON_COUNT_ID_X];

			//X座標の通路
			switch (dngList[room_before].roadLine[DUNGEON_COUNT_ID_Y]) {
			case DUNGEON_COUNT_ID_X:
				dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] = rand32_0toMax(dngList[room_before].room_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_Y] - 2); //前側の通路の位置
				dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] = rand32_0toMax(dngList[room_after].room_apex[DUNGEON_DIVISION_ID_LAST_Y] - dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_Y] - 2); //後側の通路の位置

																																																							 //前の通路
				for (i32 j = dngList[room_before].room_apex[DUNGEON_DIVISION_ID_LAST_X]; j < dngList[room_before].division_apex[DUNGEON_DIVISION_ID_LAST_X]; j++)
					subMap[select_map_id][dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] + dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]][j].field = 0; //通路をマップチップに線画

																																												 //後の通路
				for (i32 j = dngList[room_after].division_apex[DUNGEON_DIVISION_ID_FIRST_X]; j < dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_X]; j++)
					subMap[select_map_id][dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] + dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]][j].field = 0; //通路をマップチップに線画

																																											   //通路をつなぐ
				for (i32 j = dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] + dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]; j <= dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] + dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]; j++)
					subMap[select_map_id][j][dngList[room_before].division_apex[DUNGEON_DIVISION_ID_LAST_X]].field = 0; //通路をマップチップに線画 2から5(上から下)

				for (i32 j = dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] + dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]; j <= dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] + dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]; j++)
					subMap[select_map_id][j][dngList[room_before].division_apex[DUNGEON_DIVISION_ID_LAST_X]].field = 0; //通路をマップチップに線画 5から2(下から上)
				break;

			case DUNGEON_COUNT_ID_Y:
				dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] = rand32_0toMax(dngList[room_before].room_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_X] - 2); //前側の通路の位置
				dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] = rand32_0toMax(dngList[room_after].room_apex[DUNGEON_DIVISION_ID_LAST_X] - dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_X] - 2); //後側の通路の位置

																																																							 //前の通路
				for (i32 j = dngList[room_before].room_apex[DUNGEON_DIVISION_ID_LAST_Y]; j < dngList[room_before].division_apex[DUNGEON_DIVISION_ID_LAST_Y]; j++)
					subMap[select_map_id][j][dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] + dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_X]].field = 0; //通路をマップチップに線画

																																												 //後の通路
				for (i32 j = dngList[room_after].division_apex[DUNGEON_DIVISION_ID_FIRST_Y]; j < dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_Y]; j++)
					subMap[select_map_id][j][dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] + dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_X]].field = 0; //通路をマップチップに線画

																																											   //通路をつなぐ
				for (i32 j = dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] + dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_X]; j <= dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] + dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_X]; j++)
					subMap[select_map_id][dngList[room_before].division_apex[DUNGEON_DIVISION_ID_LAST_Y]][j].field = 0; //通路をマップチップに線画
				for (i32 j = dngList[room_before].roadPos[DUNGEON_ROAD_ID_AFTER] + dngList[room_after].room_apex[DUNGEON_DIVISION_ID_FIRST_X]; j <= dngList[room_before].roadPos[DUNGEON_ROAD_ID_BEFORE] + dngList[room_before].room_apex[DUNGEON_DIVISION_ID_FIRST_X]; j++)
					subMap[select_map_id][dngList[room_before].division_apex[DUNGEON_DIVISION_ID_LAST_Y]][j].field = 0; //通路をマップチップに線画
				break;
			}

		}

		return *this;
	}

	inline MainMap& MainMap::makePlayerS()
	{
		//プレイヤー生成
		Mob player;
		player.id = MOB_ID_PLAYER;
		player.monster_id = 1;
		player.texture_id = monster[player.monster_id].texture_id;


		i32 random_x = rand32_0toMax(subMapData[select_map_id].map_end_x - 1); //マップのX座標の長さの中からランダムに指定
		i32 random_y = rand32_0toMax(subMapData[select_map_id].map_end_y - 1); //マップのY座標の長さの中からランダムに指定

		player.x = random_x;
		player.y = random_y;

#if defined(__ANDROID__) //Android専用
		mob.push_back(player);
#else
		mob.emplace_back(player);
#endif
		if (mobPicture.size() >= 1) mob_player_id = u16(mob.size() - 1);
		playerWalkEndEvent(i32(mob.size() - 1));
		return *this;
	}

	inline MainMap& MainMap::makeEnemyD()
	{

		if (dngData.room_total_area <= 5) return *this;

		//プレイヤー生成
		Mob player;
		player.id = MOB_ID_PLAYER;
		player.monster_id = 2;
		player.texture_id = monster[player.monster_id].texture_id;

		i32 player_born_room;

		while (1) {

			player_born_room = rand32_0toMax(dngList_size - 1);

			i32 random_x = rand32_0toMax(this->dngList[player_born_room].room_apex[0] - this->dngList[player_born_room].room_apex[2] - 1); //マップのX座標の長さの中からランダムに指定
			i32 random_y = rand32_0toMax(this->dngList[player_born_room].room_apex[1] - this->dngList[player_born_room].room_apex[3] - 1); //マップのY座標の長さの中からランダムに指定

			if (this->dngList[player_born_room].room_apex[0] - this->dngList[player_born_room].room_apex[2] > 1 && this->dngList[player_born_room].room_apex[1] - this->dngList[player_born_room].room_apex[3] > 1) {
				player.x = this->dngList[player_born_room].room_apex[2] + random_x;
				player.y = this->dngList[player_born_room].room_apex[3] + random_y;
				break;
			}

		}
		this->dngList[player_born_room].room_entered_player = true;

#if defined(__ANDROID__) //Android専用
		mob.push_back(player);
#else
		mob.emplace_back(player);
#endif
		if (mobPicture.size() >= 1) mob_player_id = u16(mob.size() - 1);
		playerWalkEndEvent(i32(mob.size() - 1));
		return *this;
	}

	inline MainMap& MainMap::makePlayerD()
	{

		if (dngData.room_total_area <= 5) return *this;

		//プレイヤー生成
		Mob player;
		player.id = MOB_ID_PLAYER;
		//if (mobPicture.size() >= 1) player.mob_id = 1;
		//else player.mob_id = NULL_U16;
		player.monster_id = 1;
		player.walk_id.resize(NUMBER_OF_WALK_TYPE_ID, false);
		player.walk_id = monster[player.monster_id].walk_id;
		player.texture_id = monster[player.monster_id].texture_id;

		u8 player_born_room;

		while (1) {

			player_born_room = rand8_0toMax(dngList_size - 1);

			i32 random_x = rand32_0toMax(this->dngList[player_born_room].room_apex[0] - this->dngList[player_born_room].room_apex[2] - 1); //マップのX座標の長さの中からランダムに指定
			i32 random_y = rand32_0toMax(this->dngList[player_born_room].room_apex[1] - this->dngList[player_born_room].room_apex[3] - 1); //マップのY座標の長さの中からランダムに指定

			if (this->dngList[player_born_room].room_apex[0] - this->dngList[player_born_room].room_apex[2] > 1 && this->dngList[player_born_room].room_apex[1] - this->dngList[player_born_room].room_apex[3] > 1) {
				player.x = this->dngList[player_born_room].room_apex[2] + random_x;
				player.y = this->dngList[player_born_room].room_apex[3] + random_y;
				break;
			}

		}
		this->dngList[player_born_room].room_entered_player = true;

#if defined(__ANDROID__) //Android専用
		mob.push_back(player);
#else
		mob.emplace_back(player);
#endif
		if (u16(mobPicture.size()) >= 1) mob_player_id = u16(mob.size() - 1);
		playerWalkEndEvent(u16(mob.size() - 1));
		return *this;
	}

	inline MainMap& MainMap::makeStairs()
	{
		if (dngData.room_total_area < 5) return *this;

		i32 stairs_room_road = 0;
		/*階段を設置する*/
		for (i32 i = 1; i > 0; i--) {
			i32 map_random = rand32_0toMax(dngData.division_count - 1); //マップ上の部屋をランダムに指定する
			i32 stairs_floor_x = rand32_0toMax(dngList[map_random].room_apex[0] - dngList[map_random].room_apex[2] - 1); //マップのX座標の長さの中からランダムに指定
			i32 stairs_floor_y = rand32_0toMax(dngList[map_random].room_apex[1] - dngList[map_random].room_apex[3] - 1); //マップのY座標の長さの中からランダムに指定

																																 //階段を通路と部屋の間に置かないための処理
			if (subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y][dngList[map_random].room_apex[2] + stairs_floor_x - 1].field == 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y - 1][dngList[map_random].room_apex[2] + stairs_floor_x - 1].field != 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y + 1][dngList[map_random].room_apex[2] + stairs_floor_x - 1].field != 0) {
				stairs_room_road++;
			}
			if (subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y][dngList[map_random].room_apex[2] + stairs_floor_x + 1].field == 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y - 1][dngList[map_random].room_apex[2] + stairs_floor_x + 1].field != 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y + 1][dngList[map_random].room_apex[2] + stairs_floor_x + 1].field != 0) {
				stairs_room_road++;
			}
			if (subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y - 1][dngList[map_random].room_apex[2] + stairs_floor_x].field == 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y - 1][dngList[map_random].room_apex[2] + stairs_floor_x - 1].field != 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y - 1][dngList[map_random].room_apex[2] + stairs_floor_x + 1].field != 0) {
				stairs_room_road++;
			}
			if (subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y + 1][dngList[map_random].room_apex[2] + stairs_floor_x].field == 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y + 1][dngList[map_random].room_apex[2] + stairs_floor_x - 1].field != 0 && subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y + 1][dngList[map_random].room_apex[2] + stairs_floor_x + 1].field != 0) {
				stairs_room_road++;
			}

			/*もし指定した場所(座標)に床がなくて、部屋の大きさが１より大きければ階段を設置する*/
			if (subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y][dngList[map_random].room_apex[2] + stairs_floor_x].floor == 0 && dngList[map_random].room_apex[0] - dngList[map_random].room_apex[2] > 1 && dngList[map_random].room_apex[1] - dngList[map_random].room_apex[3] > 1 && stairs_room_road == 0) {
				subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y][dngList[map_random].room_apex[2] + stairs_floor_x].floor = 2; //マップにアイテムを配置
																																							//stairs_room = map_random + 1;

				subMap[select_map_id][dngList[map_random].room_apex[3] + stairs_floor_y][dngList[map_random].room_apex[2] + stairs_floor_x].floor = default_stairs_id;

				//dngMap->stairsX = dngList[map_random].room_apex[2] + stairs_floor_x;
				//dngMap->stairsY = dngList[map_random].room_apex[3] + stairs_floor_y;
			}
			else {
				i++; //条件がそろわなければもう１回ループさせる
				stairs_room_road = 0;
			}
		}

		return *this;
	}

	inline MainMap& MainMap::makeItem()
	{
		i32 floorItemCount = 0;
		u16 dng_item = 0;

		const u16 item_max_count = u16(dngItem.size());

		for (u16 i = 0; i < item_max_count; i++) {
			if (dngData.floor_count >= dngItem[i].min_floor && dngData.floor_count <= dngItem[i].max_floor) {
				floorItemCount++;
				break;
			}
		}

		if (floorItemCount) {
			/*アイテム生成＆配置*/
			dngData.item_count = dngData.min_room_item + rand8_0toMax(dngData.min_room_item); //マップ上に置くアイテムの個数を決める
			if (dngData.item_count < dngData.min_room_item) dngData.item_count = UINT8_MAX;

			//int dngData.room_total_area = 0;
			/*部屋の面積(マスの合計)を数える*/
			//for (int i = dngData.division_count - 1; i >= 0; i--) {
			//	if (dngList[i].room_apex[1] - dngList[i].room_apex[3] > 1 && dngList[i].room_apex[0] - dngList[i].room_apex[2] > 1) {
			//		dngData.room_total_area += (dngList[i].room_apex[1] - dngList[i].room_apex[3])*(dngList[i].room_apex[0] - dngList[i].room_apex[2]);
			//	}
			//}

			if (dngData.item_count > dngData.room_total_area) { //もし部屋の面積よりもアイテムの方が多い場合
												//部屋の全てにアイテムを設置する
				for (i32 i = 0; i < dngData.division_count; i++) {
					if (dngList[i].room_apex[1] - dngList[i].room_apex[3] > 1) {
						for (i32 k = dngList[i].room_apex[3]; k < dngList[i].room_apex[1]; k++) {//Y
							for (i32 j = dngList[i].room_apex[2]; j < dngList[i].room_apex[0]; j++) {//X

								dng_item = u16(rand32_0toMax(item_max_count - 1));
								while (1) {
									if (dngData.floor_count >= dngItem[dng_item].min_floor && dngData.floor_count <= dngItem[dng_item].max_floor) {
										break;
									}
									else {
										dng_item = u16(rand32_0toMax(item_max_count - 1));
									}
								}

								subMap[select_map_id][k][j].item = dngItem[dng_item].texture_id;
								subMap[select_map_id][k][j].item_stack = 1;
								//subMap[select_map_id]->mapData[j][k] = 0;
							}
						}
					}
				}
			}
			else {
				//ランダムな部屋のランダムな場所にアイテムを設置
				for (i32 i = dngData.item_count - 1; i >= 0; i--) {
					i32 a = rand32_0toMax(dngData.division_count - 1); //マップ上の部屋をランダムに指定する
					i32 b = rand32_0toMax(dngList[a].room_apex[0] - dngList[a].room_apex[2] - 1); //マップのX座標の長さの中からランダムに指定
					i32 c = rand32_0toMax(dngList[a].room_apex[1] - dngList[a].room_apex[3] - 1); //マップのY座標の長さの中からランダムに指定

																										  //もし指定した場所(座標)にアイテムがなくて、部屋の大きさが１より大きければアイテムを設置する
					if (subMap[select_map_id][dngList[a].room_apex[3] + c][dngList[a].room_apex[2] + b].item == 0 && dngList[a].room_apex[0] - dngList[a].room_apex[2] > 1 && dngList[a].room_apex[1] - dngList[a].room_apex[3] > 1) {

						dng_item = u16(rand32_0toMax(item_max_count - 1));
						while (1) {
							if (dngData.floor_count >= dngItem[dng_item].min_floor && dngData.floor_count <= dngItem[dng_item].max_floor) {
								break;
							}
							else {
								dng_item = u16(rand32_0toMax(item_max_count - 1));
							}
						}

						//subMap[select_map_id][dngList[a].room_apex[3] + c][dngList[a].room_apex[2] + b].item = dngItem[dng_item].id; //マップにアイテムを配置
						subMap[select_map_id][dngList[a].room_apex[3] + c][dngList[a].room_apex[2] + b].item = dng_item;
						subMap[select_map_id][dngList[a].room_apex[3] + c][dngList[a].room_apex[2] + b].item_stack = 1;
					}
					else i++; //条件がそろわなければもう１回ループさせる
				}
			}
		}
		return *this;
	}

	inline MainMap& MainMap::addFieldID(u16 add_item_id, u16 add_item_texture_id, u8 walk_type)
	{
		if (add_item_texture_id >= 0 && add_item_texture_id < u16(mapChip.size())) {
			dngField[add_item_id].texture_id = u16(add_item_texture_id);
		}
		else dngField[add_item_id].texture_id = NULL_U16;
		//else dngField[add_item_id].id = u16(itemTexture.size() - 1);

		dngField[add_item_id].walk_type = walk_type;
		return *this;
	}

	inline MainMap& MainMap::addTalkID(const char* add_talk, const u16 add_texture_id)
	{
		TalkData addTalkData;

		for (i32 i = 0; i < UINT8_MAX; i++) {
			if (add_talk[i] == 0) break;
			addTalkData.talk_string[i] = add_talk[i];
		}

		addTalkData.texture = add_texture_id;
		talkData.push_back(addTalkData);

		return *this;
	}

	inline MainMap& MainMap::addEvent(const u16 add_event_id, const u16 add_event_type, const u16 add_event_type_id)
	{
		if (add_event_id >= u16(eventData.size())) eventData.resize(add_event_id + 1);
		if (eventData[add_event_id].count == UINT8_MAX) return *this;

		eventData[add_event_id].type[eventData[add_event_id].count] = add_event_type;
		eventData[add_event_id].type_id[eventData[add_event_id].count] = add_event_type_id;
		eventData[add_event_id].count++;

		return *this;
	}



	inline MainMap& MainMap::addItemID(u16 add_item_id, u16 add_item_texture_id)
	{
		if (add_item_texture_id >= 0) dngItem[add_item_id].texture_id = u16(add_item_texture_id);
		else dngItem[add_item_id].texture_id = u16(itemTexture.size() - 1);
		dngItem[add_item_id].min_floor = 1;
		dngItem[add_item_id].max_floor = INT32_MAX;

		dngItem[add_item_id].stack = 32;
		return *this;
	}

	inline MainMap& MainMap::addFloorID(u8 add_floor_id, u8 add_floor_texture_id)
	{

		return *this;
	}
	inline MainMap& MainMap::addMobID(u16 add_mob_id, u16 add_mob_texture_id)
	{
		monster[add_mob_id].texture_id = add_mob_texture_id;
		monster[add_mob_id].walk_id.resize(NUMBER_OF_WALK_TYPE_ID, false);
		monster[add_mob_id].walk_id[WALK_TYPE_ID_GROUND] = true;

		return *this;
	}

	inline MainMap& MainMap::addUIID(u16 add_ui_id, u16 add_ui_texture_id)
	{

		return *this;
	}

	inline MainMap& MainMap::addWindowTexture(const char* name, i32 mob_x, i32 mob_y)
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		MapWindow add_mob;
		loadDivisionGraphGCH(name, add_mob.id, 3, 3, mob_x, mob_y);

		add_mob.handle = MakeScreen(windowData.len_x, windowData.len_y, TRUE);
		SetDrawScreen(add_mob.handle);
		ClearDrawScreen();

		drawGraphGCH(0, 0, windowData.corner_x, windowData.corner_y, add_mob.id[0]);
		drawGraphGCH(windowData.corner_x, 0, windowData.len_x - windowData.corner_x * 2, windowData.corner_y, add_mob.id[1]);
		drawGraphGCH(windowData.len_x - windowData.corner_x, 0, windowData.corner_x, windowData.corner_y, add_mob.id[2]);

		drawGraphGCH(0, windowData.corner_y, windowData.corner_x, windowData.len_y - windowData.corner_y * 2, add_mob.id[3]);
		drawGraphGCH(windowData.corner_x, windowData.corner_y, windowData.len_x - windowData.corner_x * 2, windowData.len_y - windowData.corner_y * 2, add_mob.id[4]);
		drawGraphGCH(windowData.len_x - windowData.corner_x, windowData.corner_y, windowData.corner_x, windowData.len_y - windowData.corner_y * 2, add_mob.id[5]);

		drawGraphGCH(0, windowData.len_y - windowData.corner_y, windowData.corner_x, windowData.corner_y, add_mob.id[6]);
		drawGraphGCH(windowData.corner_x, windowData.len_y - windowData.corner_y, windowData.len_x - windowData.corner_x * 2, windowData.corner_y, add_mob.id[7]);
		drawGraphGCH(windowData.len_x - windowData.corner_x, windowData.len_y - windowData.corner_y, windowData.corner_x, windowData.corner_y, add_mob.id[8]);

		SetDrawScreen(DX_SCREEN_BACK);
		windowTexture.push_back(add_mob);
#endif
#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))
		MapWindow add_mob;
		loadDivisionGraphGCH(name, add_mob.id, 3, 3, mob_x, mob_y);
		windowTexture.emplace_back(add_mob);
#endif
		return *this;
	}

	inline MainMap& MainMap::addItemTexture(const char* name)
	{
		if (u16(itemTexture.size()) == NULL_U16) return *this;
		itemTexture.push_back(loadGraphGCH(name));
		return *this;
	}

	inline MainMap& MainMap::addFloorTexture(const char* name)
	{
		if (u8(floorTexture.size()) == NULL_U8) return *this;
		floorTexture.push_back(loadGraphGCH(name));
		return *this;
	}

	inline MainMap& MainMap::addUITexture(const char* name)
	{
		if (u16(uiTexture.size()) == NULL_U16) return *this;
		uiTexture.push_back(loadGraphGCH(name));
		return *this;
	}

	inline MainMap& MainMap::addCharTexture(const char* name)
	{
		if (u16(charTexture.size()) == NULL_U16) return *this;
		charTexture.push_back(loadGraphGCH(name));
		return *this;
	}

	//キャラチップを読み込む関数
	inline MainMap& MainMap::addMobTexture(const char* name, i32 mob_x, i32 mob_y)
	{
		if (u16(mobPicture.size()) == NULL_U16) return *this;
		MobPic add_mob;
		loadDivisionGraphGCH(name, add_mob.id, 8, 3, mob_x, mob_y);
		mobPicture.emplace_back(add_mob);
		return *this;
	}

	//別規格のキャラチップを読み取る関数
	inline MainMap& MainMap::addMobTextureW(const char* name, i32 mob_x, i32 mob_y)
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))

		if (u16(mobPicture.size()) == NULL_U16) return *this;
		MobPic add_mob;
		int add_before_mob[NUMBER_OF_8_DIRECTION_CHAR_CHIP];
		loadDivisionGraphGCH(name, add_mob.id, 6, 4, mob_x, mob_y);

		add_mob.id[MOB_WALK_ID_DOWN + 8] = add_before_mob[0];
		add_mob.id[MOB_WALK_ID_DOWN] = add_before_mob[1];
		add_mob.id[MOB_WALK_ID_DOWN + 16] = add_before_mob[2];
		add_mob.id[MOB_WALK_ID_LEFTDOWN + 8] = add_before_mob[3];
		add_mob.id[MOB_WALK_ID_LEFTDOWN] = add_before_mob[4];
		add_mob.id[MOB_WALK_ID_LEFTDOWN + 16] = add_before_mob[5];

		add_mob.id[MOB_WALK_ID_LEFT + 8] = add_before_mob[6];
		add_mob.id[MOB_WALK_ID_LEFT] = add_before_mob[7];
		add_mob.id[MOB_WALK_ID_LEFT + 16] = add_before_mob[8];
		add_mob.id[MOB_WALK_ID_RIGHTDOWN + 8] = add_before_mob[9];
		add_mob.id[MOB_WALK_ID_RIGHTDOWN] = add_before_mob[10];
		add_mob.id[MOB_WALK_ID_RIGHTDOWN + 16] = add_before_mob[11];

		add_mob.id[MOB_WALK_ID_RIGHT + 8] = add_before_mob[12];
		add_mob.id[MOB_WALK_ID_RIGHT] = add_before_mob[13];
		add_mob.id[MOB_WALK_ID_RIGHT + 16] = add_before_mob[14];
		add_mob.id[MOB_WALK_ID_LEFTUP + 8] = add_before_mob[15];
		add_mob.id[MOB_WALK_ID_LEFTUP] = add_before_mob[16];
		add_mob.id[MOB_WALK_ID_LEFTUP + 16] = add_before_mob[17];

		add_mob.id[MOB_WALK_ID_UP + 8] = add_before_mob[18];
		add_mob.id[MOB_WALK_ID_UP] = add_before_mob[19];
		add_mob.id[MOB_WALK_ID_UP + 16] = add_before_mob[20];
		add_mob.id[MOB_WALK_ID_RIGHTUP + 8] = add_before_mob[21];
		add_mob.id[MOB_WALK_ID_RIGHTUP] = add_before_mob[22];
		add_mob.id[MOB_WALK_ID_RIGHTUP + 16] = add_before_mob[23];

		mobPicture.push_back(add_mob);
#endif
#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))
		MobPic add_mob;
		loadDivisionGraphGCH(name, add_mob.id, 8, 3, mob_x, mob_y);
		mobPicture.emplace_back(add_mob);
#endif
		return *this;
	}

	//別規格のキャラチップを読み取る関数
	inline MainMap& MainMap::addMobTextureWC(const char* name, const char* name2, i32 mob_x, i32 mob_y)
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))

		if (u16(mobPicture.size()) == NULL_U16) return *this;
		MobPic add_mob;

		i32 mob_size;

		if (mob_x >= mob_y) mob_size = mob_x;
		else mob_size = mob_y;

		if (LoadDivGraph(name2, NUMBER_OF_8_DIRECTION_CHAR_CHIP, 8, 3, mob_size, mob_size, add_mob.id) == 0) {
			mobPicture.push_back(add_mob);
			return *this;
		}

		//
		int add_before_mob[NUMBER_OF_8_DIRECTION_CHAR_CHIP];
		LoadDivGraph(name, NUMBER_OF_8_DIRECTION_CHAR_CHIP, 6, 4, mob_x, mob_y, add_before_mob);

		add_mob.id[MOB_WALK_ID_DOWN + 8] = add_before_mob[0];
		add_mob.id[MOB_WALK_ID_DOWN] = add_before_mob[1];
		add_mob.id[MOB_WALK_ID_DOWN + 16] = add_before_mob[2];
		add_mob.id[MOB_WALK_ID_LEFTDOWN + 8] = add_before_mob[3];
		add_mob.id[MOB_WALK_ID_LEFTDOWN] = add_before_mob[4];
		add_mob.id[MOB_WALK_ID_LEFTDOWN + 16] = add_before_mob[5];

		add_mob.id[MOB_WALK_ID_LEFT + 8] = add_before_mob[6];
		add_mob.id[MOB_WALK_ID_LEFT] = add_before_mob[7];
		add_mob.id[MOB_WALK_ID_LEFT + 16] = add_before_mob[8];
		add_mob.id[MOB_WALK_ID_RIGHTDOWN + 8] = add_before_mob[9];
		add_mob.id[MOB_WALK_ID_RIGHTDOWN] = add_before_mob[10];
		add_mob.id[MOB_WALK_ID_RIGHTDOWN + 16] = add_before_mob[11];

		add_mob.id[MOB_WALK_ID_RIGHT + 8] = add_before_mob[12];
		add_mob.id[MOB_WALK_ID_RIGHT] = add_before_mob[13];
		add_mob.id[MOB_WALK_ID_RIGHT + 16] = add_before_mob[14];
		add_mob.id[MOB_WALK_ID_LEFTUP + 8] = add_before_mob[15];
		add_mob.id[MOB_WALK_ID_LEFTUP] = add_before_mob[16];
		add_mob.id[MOB_WALK_ID_LEFTUP + 16] = add_before_mob[17];

		add_mob.id[MOB_WALK_ID_UP + 8] = add_before_mob[18];
		add_mob.id[MOB_WALK_ID_UP] = add_before_mob[19];
		add_mob.id[MOB_WALK_ID_UP + 16] = add_before_mob[20];
		add_mob.id[MOB_WALK_ID_RIGHTUP + 8] = add_before_mob[21];
		add_mob.id[MOB_WALK_ID_RIGHTUP] = add_before_mob[22];
		add_mob.id[MOB_WALK_ID_RIGHTUP + 16] = add_before_mob[23];

		//画像を作成
		int make_mob_graph = MakeScreen(mob_size * 8, mob_size * 3, TRUE);
		SetDrawScreen(make_mob_graph);
		ClearDrawScreen();
		for (i32 i = 0; i < 8; i++) {
			for (i32 j = 0; j < 3; j++) {
				drawGraphGCH(mob_size * i + ((mob_size - mob_x) >> 1), mob_size * j + ((mob_size - mob_y) >> 1), mob_x, mob_y, add_mob.id[i + (j * 8)]);
			}
		}
		SaveDrawScreenToPNG(0, 0, mob_size * 8, mob_size * 3, name2, 9);
		DeleteGraph(make_mob_graph);
		SetDrawScreen(DX_SCREEN_BACK);

		if (LoadDivGraph(name2, NUMBER_OF_8_DIRECTION_CHAR_CHIP, 8, 3, mob_size, mob_size, add_mob.id) == 0) {
			mobPicture.push_back(add_mob);
			return *this;
		}
		mobPicture.push_back(add_mob);
#endif
#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))
		MobPic add_mob;
		loadDivisionGraphGCH(name, add_mob.id, 8, 3, mob_x, mob_y);
		mobPicture.emplace_back(add_mob);
#endif
		return *this;
	}

	inline MainMap& MainMap::addMapChipTextureNew(const char* name, u8 map_chip_count, i32 map_chip_size)
	{
		if (u16(mapChip.size()) == NULL_U16) return *this;
		if (map_chip_count == NULL_U8) return *this;

		MapChip addMapChip;
		addMapChip.number_of_anime = map_chip_count;
		addMapChip.map_chip_picture.resize(map_chip_count * 48);

		loadDivisionGraphGCH(name, addMapChip.map_chip_picture, 8, map_chip_count * 6, map_chip_size * 2, map_chip_size * 2);
		mapChip.push_back(addMapChip);
		return *this;
	}

	//別規格のマップチップを読み取る関数
	inline MainMap& MainMap::addMapChipTextureNewWC(const char* name, const char* name2, u8 map_chip_count, i32 map_chip_size)
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		if (u16(mapChip.size()) == NULL_U16) return *this;
		if (map_chip_count == NULL_U8) return *this;

		MapChip addMapChip;
		addMapChip.number_of_anime = map_chip_count;
		addMapChip.map_chip_picture.resize(map_chip_count * 48);

		if (loadDivisionGraphGCH(name2, addMapChip.map_chip_picture, 8, map_chip_count * 6, map_chip_size * 2, map_chip_size * 2) == 0) {
			mapChip.push_back(addMapChip);
			return *this;
		}

		std::vector<int> add_before_mob;
		add_before_mob.resize(map_chip_count * 20);

		loadDivisionGraphGCH(name, add_before_mob.data(), 2 * map_chip_count, 10, map_chip_size, map_chip_size);

		//	//2 * (縦の番号(0~10) * アニメ数(1~254) + アニメ番号(0~253)) + 横の番号(0,1)
		//	add_before_mob[2 * (0 * map_chip_count + i) + 1];

		//画像を作成
		int make_mob_graph = MakeScreen(map_chip_size * 16, map_chip_size * 12 * map_chip_count, TRUE);
		SetDrawScreen(make_mob_graph);
		ClearDrawScreen();

		for (i32 k = 0; k < map_chip_count; k++) {

			mapChipGCH(2, 0, map_chip_size, map_chip_count, k, add_before_mob.data(), 0, 0, 0, 0);
			mapChipGCH(4, 0, map_chip_size, map_chip_count, k, add_before_mob.data(), 0, 0, 1, 1);
			mapChipGCH(6, 0, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 0, 2, 0);
			mapChipGCH(8, 0, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 1, 0, 0);
			mapChipGCH(10, 0, map_chip_size, map_chip_count, k, add_before_mob.data(), 0, 2, 0, 2);
			mapChipGCH(12, 0, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 1, 1, 1);
			mapChipGCH(14, 0, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 2, 2, 2);

			mapChipGCH(0, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 0, 3, 1);
			mapChipGCH(2, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 0, 4, 1);
			mapChipGCH(4, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 1, 2, 0);
			mapChipGCH(6, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 1, 2, 0);
			mapChipGCH(8, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 3, 0, 2);
			mapChipGCH(10, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 4, 0, 2);
			mapChipGCH(12, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 0, 2, 1, 3);
			mapChipGCH(14, 2, map_chip_size, map_chip_count, k, add_before_mob.data(), 0, 2, 1, 4);

			mapChipGCH(0, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 1, 3, 1);
			mapChipGCH(2, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 1, 4, 1);
			mapChipGCH(4, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 1, 3, 1);
			mapChipGCH(6, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 1, 4, 1);
			mapChipGCH(8, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 3, 2, 2);
			mapChipGCH(10, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 3, 2, 2);
			mapChipGCH(12, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 4, 2, 2);
			mapChipGCH(14, 4, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 4, 2, 2);

			mapChipGCH(0, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 3, 1, 3);
			mapChipGCH(2, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 4, 1, 3);
			mapChipGCH(4, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 3, 1, 4);
			mapChipGCH(6, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 1, 4, 1, 4);
			mapChipGCH(8, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 2, 3, 3);
			mapChipGCH(10, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 2, 3, 4);
			mapChipGCH(12, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 2, 4, 3);
			mapChipGCH(14, 6, map_chip_size, map_chip_count, k, add_before_mob.data(), 2, 2, 4, 4);

			mapChipGCH(0, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 3, 3, 3);
			mapChipGCH(2, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 3, 3, 3);
			mapChipGCH(4, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 4, 3, 3);
			mapChipGCH(6, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 4, 3, 3);

			mapChipGCH(8, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 3, 4, 3);
			mapChipGCH(10, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 3, 4, 3);
			mapChipGCH(12, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 4, 4, 3);
			mapChipGCH(14, 8, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 4, 4, 3);

			mapChipGCH(0, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 3, 3, 4);
			mapChipGCH(2, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 3, 3, 4);
			mapChipGCH(4, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 4, 3, 4);
			mapChipGCH(6, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 4, 3, 4);

			mapChipGCH(8, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 3, 4, 4);
			mapChipGCH(10, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 3, 4, 4);
			mapChipGCH(12, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 3, 4, 4, 4);
			mapChipGCH(14, 10, map_chip_size, map_chip_count, k, add_before_mob.data(), 4, 4, 4, 4);

		}
		SaveDrawScreenToPNG(0, 0, map_chip_size * 16, map_chip_size * 12 * map_chip_count, name2, 9);
		DeleteGraph(make_mob_graph);
		SetDrawScreen(DX_SCREEN_BACK);

		if (loadDivisionGraphGCH(name2, addMapChip.map_chip_picture, 8, map_chip_count * 6, map_chip_size * 2, map_chip_size * 2) == 0) {
			mapChip.push_back(addMapChip);
			return *this;
		}
#endif
		return *this;
	}



	inline MainMap& MainMap::fieldTrrainCheckAll()
	{
		this->fieldTrrainCheck(subMapData[select_map_id].map_start_x, subMapData[select_map_id].map_end_x, subMapData[select_map_id].map_start_y, subMapData[select_map_id].map_end_y); //地形チェック
		return *this;
	}

	inline MainMap& MainMap::fieldTrrainCheck(const i32 start_x, const i32 end_x, const i32 start_y, const i32 end_y)
	{
		u8 line_count = 0;
		u8 add_line_count = 0;
		u16 map_field;
		i32 i2 = 0, j2 = 0, i2p = 0, i2m = 0, j2p = 0, j2m = 0, i2d = 0, j2d = 0;

		for (i32 i = start_y; i < end_y; i++) {

			i2d = i + subMapData[select_map_id].map_end_y;
			i2 = i2d % subMapData[select_map_id].map_end_y;
			i2p = (i2d + 1) % subMapData[select_map_id].map_end_y;
			i2m = (i2d - 1) % subMapData[select_map_id].map_end_y;

			for (i32 j = start_x; j < end_x; j++) {
				j2d = j + subMapData[select_map_id].map_end_x;
				j2 = j2d % subMapData[select_map_id].map_end_x;
				j2p = (j2d + 1) % subMapData[select_map_id].map_end_x;
				j2m = (j2d - 1) % subMapData[select_map_id].map_end_x;

				line_count = 0;
				map_field = subMap[select_map_id][i][j].field;


				if (subMap[select_map_id][i2p][j2].field != map_field) {
					line_count += 0x1;
				}
				if (subMap[select_map_id][i2][j2m].field != map_field) {
					line_count += 0x2;
				}
				if (subMap[select_map_id][i2m][j2].field != map_field) {
					line_count += 0x4;
				}
				if (subMap[select_map_id][i2][j2p].field != map_field) {
					line_count += 0x8;
				}

				switch (line_count)
				{
				case 0x0:
					add_line_count = 32;//4
					if (subMap[select_map_id][i2m][j2m].field == map_field) {
						add_line_count += 1;
					}
					if (subMap[select_map_id][i2m][j2p].field == map_field) {
						add_line_count += 2;
					}
					if (subMap[select_map_id][i2p][j2m].field == map_field) {
						add_line_count += 4;
					}
					if (subMap[select_map_id][i2p][j2p].field == map_field) {
						add_line_count += 8;
					}

					break;
				case 0x1:
					add_line_count = 20;//3
					if (subMap[select_map_id][i2m][j2m].field == map_field) {
						add_line_count += 1;
					}
					if (subMap[select_map_id][i2m][j2p].field == map_field) {
						add_line_count += 2;
					}

					break;
				case 0x2:
					add_line_count = 24;//3
					if (subMap[select_map_id][i2m][j2p].field == map_field) {
						add_line_count += 1;
					}
					if (subMap[select_map_id][i2p][j2p].field == map_field) {
						add_line_count += 2;
					}

					break;
				case 0x3:
					add_line_count = 12;//2
					if (subMap[select_map_id][i2m][j2p].field == map_field) {
						add_line_count += 1;
					}

					break;
				case 0x4:
					add_line_count = 28;//3
					if (subMap[select_map_id][i2p][j2p].field == map_field) {
						add_line_count += 1;
					}
					if (subMap[select_map_id][i2p][j2m].field == map_field) {
						add_line_count += 2;
					}

					break;
				case 0x5:
					add_line_count = 7;
					break;
				case 0x6:
					add_line_count = 14;//2
					if (subMap[select_map_id][i2p][j2p].field == map_field) {
						add_line_count += 1;
					}

					break;
				case 0x7:
					add_line_count = 5;
					break;
				case 0x8:
					add_line_count = 16;//3
					if (subMap[select_map_id][i2p][j2m].field == map_field) {
						add_line_count += 1;
					}
					if (subMap[select_map_id][i2m][j2m].field == map_field) {
						add_line_count += 2;
					}

					break;
				case 0x9:
					add_line_count = 10;//2
					if (subMap[select_map_id][i2m][j2m].field == map_field) {
						add_line_count += 1;
					}

					break;
				case 0xa:
					add_line_count = 6;

					break;
				case 0xb:
					add_line_count = 4;

					break;
				case 0xc:
					add_line_count = 8;//2
					if (subMap[select_map_id][i2p][j2m].field == map_field) {
						add_line_count += 1;
					}

					break;
				case 0xd:
					add_line_count = 3;
					break;
				case 0xe:
					add_line_count = 2;
					break;
				case 0xf:
					add_line_count = 1;
					break;
				}

				subMap[select_map_id][i][j].all_terrain = add_line_count;//
			}
		}
		return *this;
	}

	inline MainMap& MainMap::makeD()
	{
		this->makeFieldD(); //地形生成
		this->fieldTrrainCheckAll(); //地形チェック

		this->makePlayerD(); //
							 //for (i32 i = 0; i < 100;i++)this->makeEnemyD();
		this->makeItem(); //
		this->makeStairs(); //

		return *this;
	}

	inline MainMap& MainMap::makeW()
	{
		this->makeFieldW();
		this->fieldTrrainCheckAll(); //地形チェック

		this->makePlayerS(); //
		return *this;
	}

	inline MainMap& MainMap::makeWL()
	{
		this->makeFieldWL();
		this->fieldTrrainCheckAll(); //地形チェック

		this->makePlayerS(); //
		return *this;
	}

	inline MainMap& MainMap::upFloor()
	{
		if (dngData.floor_count < INT32_MAX) this->dngData.floor_count++;
		this->f = this->dngData.floor_count;
		return *this;
	}

	inline MainMap& MainMap::upFloor(i32& up_floor_count)
	{
		if (dngData.floor_count < INT32_MAX) this->dngData.floor_count++;
		up_floor_count = this->dngData.floor_count;
		return *this;
	}

	inline MainMap& MainMap::draw(i32 pixel_size)
	{
		drawAll(pixel_size);
		timeMeasurement();
		return *this;
	}

	inline MainMap& MainMap::drawP()
	{
		checkDisplayResolution();
		drawPlayerMap();

		if (use_square && square_picture && mob_player_id < u16(mobPicture.size())) {
			drawGraphGCH(-player_look_pixel_half + i32(-player_look_pixel * mob[mob_player_id].micro_x), -player_look_pixel_half + i32(-player_look_pixel * mob[mob_player_id].micro_y), map_screen_x + player_look_pixel_half, map_screen_y + player_look_pixel_half, make_square, 190);
		}


		drawPlayer();
		timeMeasurement();
		if (on_half_minute) saveInventory();
		return *this;
	}

	inline MainMap& MainMap::drawPlayer()
	{
		if (mob_player_id != NULL_U16) {
			drawGraphGCH(map_center_x - player_look_pixel_half, map_center_y - player_look_pixel_half - player_look_pixel_quarter, player_look_pixel, player_look_pixel, mobPicture[mob[mob_player_id].texture_id].id[mob[mob_player_id].walk_type]); //todo
		}
		return *this;
	}

	inline MainMap& MainMap::drawPlayerMap()
	{
		if (use_ground_picture && mob_player_id < u16(mobPicture.size())) {
			drawGround();
			if (on_ground_shine) effectGroundShine();
		}
		else drawBoxGCH(0, 0, map_screen_x, map_screen_y, ColorGCH{ 60, 160, 90 });

		if (mob_player_id == NULL_U16) return *this;

		u16 map_chip_size = u16(mapChip.size());
		for (u16 i = 0; i < map_chip_size; i++) {
			mapChip[i].anime_speed_count++;
			if (mapChip[i].anime_speed_count >= mapChip[i].anime_speed) {
				mapChip[i].anime_speed_count = 0;
				mapChip[i].anime_count++;
				if (mapChip[i].anime_count >= mapChip[i].number_of_anime) mapChip[i].anime_count = 0;
			}
		}

		const i32 a = map_center_x - (i32)(player_look_pixel * (mob[mob_player_id].x + 0.5f + mob[mob_player_id].micro_x));
		const i32 b = map_center_y - (i32)(player_look_pixel * (mob[mob_player_id].y + 0.5f + mob[mob_player_id].micro_y));
		const i32 left = mob[mob_player_id].x - player_look_len_half;
		const i32 right = mob[mob_player_id].x + player_look_len_half;
		const i32 up = mob[mob_player_id].y - player_look_len_half;
		const i32 down = mob[mob_player_id].y + player_look_len_half;

		i32 graphXS;
		i32 graphYS;

		i32 i2 = 0, j2 = 0;
		u8 map_all_terrain = 0;

		u8 map_count = 0;
		u8 map_anime = 0;

		u16 map_field_id = 0;
		u16 map_field_texture_id = 0;

		i32 map_end_x = subMapData[select_map_id].map_end_x;
		i32 map_end_y = subMapData[select_map_id].map_end_y;

		for (i32 j = up; j < down; j++) {
			j2 = (j + map_end_y) % map_end_y;
			graphYS = player_look_pixel * j + b;

			for (i32 i = left; i < right; i++) {
				i2 = (i + map_end_x) % map_end_x;
				graphXS = player_look_pixel * i + a;

				map_field_id = subMap[select_map_id][j2][i2].field;
				map_field_texture_id = dngField[map_field_id].texture_id;



				if (map_field_id) {
					if (map_field_id < u16(dngField.size()) && map_field_texture_id != NULL_U16) {

						map_all_terrain = subMap[select_map_id][j2][i2].all_terrain;
						map_count = mapChip[map_field_texture_id].anime_count;
						map_anime = mapChip[map_field_texture_id].number_of_anime;

						drawGraphGCH(graphXS, graphYS, player_look_pixel, player_look_pixel, mapChip[map_field_texture_id].map_chip_picture[map_all_terrain + 48 * map_count]);
					}
					else drawBoxGCH(graphXS, graphYS, player_look_pixel, player_look_pixel, ColorGCH{ 120, 120, 120, 180 });
				}

				if (subMap[select_map_id][j2][i2].floor) {
					if (subMap[select_map_id][j2][i2].floor <= u8(floorTexture.size())) {
						drawGraphGCH(graphXS, graphYS, player_look_pixel, player_look_pixel, floorTexture[subMap[select_map_id][j2][i2].floor - 1]);
					}
				}

				if (subMap[select_map_id][j2][i2].item) {
					if (subMap[select_map_id][j2][i2].item <= u16(dngItem.size()) && dngItem[subMap[select_map_id][j2][i2].item].texture_id <= u16(itemTexture.size())) {

						if (dngField[map_field_id].walk_type == WALK_TYPE_ID_WATER) drawGraphGCH(graphXS + player_look_pixel_quarter, graphYS + player_look_pixel_quarter, player_look_pixel_half, player_look_pixel_half, itemTexture[dngItem[subMap[select_map_id][j2][i2].item].texture_id], 120);
						else drawGraphGCH(graphXS + player_look_pixel_quarter, graphYS + player_look_pixel_quarter, player_look_pixel_half, player_look_pixel_half, itemTexture[dngItem[subMap[select_map_id][j2][i2].item].texture_id]);
					}
				}


			}
		}
		return *this;
	}

	inline MainMap& MainMap::makeField16W(const u8 field_x_16, const u8 field_y_16, u8 size, const u8 t1, const u8 t2, const u8 t3, const u8 t4)
	{
		//再起の終了処理
		if (!size) return *this;

		//頂点の高さを決める
		const i32 mapPlus_32 = ((i32(t1) + t2 + t3 + t4) >> 2) + rand8_0toMax(size);
		u8 mapPlus;
		if (mapPlus_32 >= UINT8_MAX) mapPlus = UINT8_MAX;
		else mapPlus = u8(mapPlus_32);

		make_field_16[field_x_16][field_y_16] = mapPlus;

		//四角形の2点同士の中点の高さを決定
		const u8 s1 = (t1 >> 1) + (t2 >> 1);
		const u8 s2 = (t1 >> 1) + (t3 >> 1);
		const u8 s3 = (t2 >> 1) + (t4 >> 1);
		const u8 s4 = (t3 >> 1) + (t4 >> 1);

		//4つの地点の座標を決める
		make_field_16[field_x_16 + size][field_y_16] = s3;
		make_field_16[field_x_16 - size][field_y_16] = s2;
		make_field_16[field_x_16][field_y_16 + size] = s4;
		make_field_16[field_x_16][field_y_16 - size] = s1;

		//分割サイズを半分にする
		size >>= 1;

		//4つに分割
		makeField16W(field_x_16 - size, field_y_16 - size, size, t1, s1, s2, make_field_16[field_x_16][field_y_16]);
		makeField16W(field_x_16 + size, field_y_16 - size, size, s1, t2, make_field_16[field_x_16][field_y_16], s3);
		makeField16W(field_x_16 - size, field_y_16 + size, size, s2, make_field_16[field_x_16][field_y_16], t3, s4);
		makeField16W(field_x_16 + size, field_y_16 + size, size, make_field_16[field_x_16][field_y_16], s3, s4, t4);


		return *this;
	}


	inline MainMap& MainMap::makeFieldW()
	{
		i32 i16, j16;
		i32 i8, j8;

		//clsDx();
		for (i32 i = 0; i < chunk_len_y; i++) {
			for (i32 j = 0; j < chunk_len_x; j++) {

				i8 = i + world_make_rand_x;
				j8 = j + world_make_rand_y;

				i16 = (i << 4);
				j16 = (j << 4);

				//四角形の4点の高さを決定
				srand8(u8(i8 + (j8 << 2)));
				make_field_16[0][0] = rand8((j8 & 15) + (i8 & 7));

				srand8(u8((i8 + 1) + (j8 << 2)));
				make_field_16[WORLD_CHUNK][0] = rand8((j8 & 15) + ((i8 + 1) & 7));

				srand8(u8(i8 + ((j8 + 1) << 2)));
				make_field_16[0][WORLD_CHUNK] = rand8(((j8 + 1) & 15) + (i8 & 7));

				srand8(u8((i8 + 1) + ((j8 + 1) << 2)));
				make_field_16[WORLD_CHUNK][WORLD_CHUNK] = rand8(((j8 + 1) & 15) + ((i8 + 1) & 7));

				//チャンク生成
				makeField16W(8, 8, 8, make_field_16[0][0], make_field_16[WORLD_CHUNK][0], make_field_16[0][WORLD_CHUNK], make_field_16[WORLD_CHUNK][WORLD_CHUNK]);

				for (u8 i2 = 0; i2 < WORLD_CHUNK; i2++) {
					for (u8 j2 = 0; j2 < WORLD_CHUNK; j2++) {
						//生成したチャンクをワールドマップにコピペ
						subMap[select_map_id][i16 + i2][j16 + j2].height = make_field_16[i2][j2];
						if (make_field_16[i2][j2] > 140) subMap[select_map_id][i16 + i2][j16 + j2].field = FIELD_ID_WALL;
						else subMap[select_map_id][i16 + i2][j16 + j2].field = FIELD_ID_EMPTY;
					}
				}


			}
		}

		return *this;
	}

	inline MainMap& MainMap::makeFieldWL()
	{
		i32 i16, j16;
		i32 i8, j8, i8p, j8p;

		//clsDx();
		for (i32 i = 0; i < chunk_len_y; i++) {
			for (i32 j = 0; j < chunk_len_x; j++) {

				i8 = i + world_make_rand_x;
				i8p = ((i + 1) % chunk_len_y) + world_make_rand_x;

				j8 = j + world_make_rand_y;
				j8p = ((j + 1) % chunk_len_x) + world_make_rand_y;

				i16 = (i << 4);
				j16 = (j << 4);

				//四角形の4点の高さを決定
				srand8(u8(i8 + (j8 << 2)));
				make_field_16[0][0] = rand8((j8 & 15) + (i8 & 7));

				srand8(u8((i8p)+(j8 << 2)));
				make_field_16[WORLD_CHUNK][0] = rand8((j8 & 15) + ((i8p) & 7));

				srand8(u8(i8 + ((j8p) << 2)));
				make_field_16[0][WORLD_CHUNK] = rand8(((j8p) & 15) + (i8 & 7));

				srand8(u8((i8p)+((j8p) << 2)));
				make_field_16[WORLD_CHUNK][WORLD_CHUNK] = rand8(((j8p) & 15) + ((i8p) & 7));

				//チャンク生成
				makeField16W(8, 8, 8, make_field_16[0][0], make_field_16[WORLD_CHUNK][0], make_field_16[0][WORLD_CHUNK], make_field_16[WORLD_CHUNK][WORLD_CHUNK]);

				for (u8 i2 = 0; i2 < WORLD_CHUNK; i2++) {
					for (u8 j2 = 0; j2 < WORLD_CHUNK; j2++) {
						//生成したチャンクをワールドマップにコピペ
						if (make_field_16[i2][j2] > 140) subMap[select_map_id][i16 + i2][j16 + j2].field = 1;
						else subMap[select_map_id][i16 + i2][j16 + j2].field = 0;
					}
				}


			}
		}

		return *this;
	}


	inline MainMap& MainMap::checkButton()
	{

		const u16 button_size = u16(buttonMap.size());

#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		const i32 touch_num = GetTouchInputNum();
		const i32 num = touch_num + mouseClickGCH();
#else
		const i32 touch_num = 0;
		const i32 num = touch_num + mouseClickGCH();
#endif

		if (touch_count == 0 && num>0) touch_click = true;
		else touch_click = false;

		touch_count = num;

		i32 button_x = 0;
		i32 button_y = 0;
		for (i32 i = 0; i < num; i++)
		{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
			if (i == touch_num) mousePosGCH(&button_x, &button_y);
			else GetTouchInput(i, &button_x, &button_y, nullptr, nullptr);
#else
			if (i == touch_num) mousePosGCH(&button_x, &button_y);
#endif
			for (u16 j = 0; j < button_size; j++) {

				if ((buttonMap[j].layer == default_layer || buttonMap[j].layer == -1) && !buttonMap[j].turn && buttonMap[j].start_x <= button_x && buttonMap[j].end_x >= button_x && buttonMap[j].start_y <= button_y && buttonMap[j].end_y >= button_y) {
					if (!buttonMap[j].count) buttonMap[j].click = true;
					else buttonMap[j].click = false;
					if (buttonMap[j].count < INT32_MAX) buttonMap[j].count++;

					buttonMap[j].turn = true;
				}
			}
		}

		for (u16 j = 0; j < button_size; j++) {

			//if (buttonMap[j].layer == default_layer || buttonMap[j].layer == -1) {
			//一度も触れられなかった場合
			if (!buttonMap[j].turn) {
				if (buttonMap[j].count) {
					buttonMap[j].release = true;
					buttonMap[j].count = 0;
				}
				else buttonMap[j].release = false;
				buttonMap[j].click = false;
			}
			else buttonMap[j].turn = false;

			if (buttonMap[j].use_type) {
				if (buttonMap[j].click) click_key_g[buttonMap[j].type] = 1;
				//else click_key_g[buttonMap[j].type] = 0;

				if (buttonMap[j].release) release_key_g[buttonMap[j].type] = 1;
				//else release_key_g[buttonMap[j].type] = 0;
			}

			//if (buttonMap[j].click && buttonMap[j].use_type) click_key_g[buttonMap[j].type] = 1;


			//if (buttonMap[j].release && buttonMap[j].use_type) release_key_g[buttonMap[j].type] = 1;
			if (buttonMap[j].count > 0 && buttonMap[j].use_type && count_key_g[buttonMap[j].type] < INT32_MAX) count_key_g[buttonMap[j].type]++;
			//}

			//関数キーチェック
			if (buttonMap[j].click && buttonMap[j].use_func) {
				checkFuncKey(buttonMap[j].func_type);
			}

			switch (buttonMap[j].id)
			{
			default:
				break;
			case 100: //switch
				if (buttonMap[j].click && buttonMap[j].on_switch) buttonMap[j].on_switch = false;
				else if (buttonMap[j].click && !buttonMap[j].on_switch) buttonMap[j].on_switch = true;

				checkSwitchKey(buttonMap[j].switch_type, buttonMap[j].on_switch);

				break;
			}

		}
		return *this;
	}

	inline MainMap& MainMap::androidString()
	{
#if defined(__ANDROID__) //Android専用
		JNIEnv *env;
		const ANativeActivity *NativeActivity;
		int InputEnd;

		NativeActivity = GetNativeActivity();

		{
			if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, nullptr) != JNI_OK) {
				return *this;
			}
			jclass jclass_as_cll = env->GetObjectClass(NativeActivity->clazz);
			jmethodID jmethodID_StartInputDialog = env->GetMethodID(jclass_as_cll, "StartInputStringDialog", "()V");
			env->CallVoidMethod(NativeActivity->clazz, jmethodID_StartInputDialog);
			env->DeleteLocalRef(jclass_as_cll);
			NativeActivity->vm->DetachCurrentThread();
		}

		InputEnd = 0;

		while (!ProcessMessage())
		{
			if (!InputEnd)
			{
				if (NativeActivity->vm->AttachCurrentThreadAsDaemon(&env, nullptr) != JNI_OK) return *this;

				jclass jclass_as_cll = env->GetObjectClass(NativeActivity->clazz);
				jfieldID jfieldID_InputEnd = env->GetFieldID(jclass_as_cll, "InputEnd", "I");
				InputEnd = env->GetIntField(NativeActivity->clazz, jfieldID_InputEnd);

				if (InputEnd == 1) {
					jfieldID jfieldID_InputString = env->GetFieldID(jclass_as_cll, "InputString", "Ljava/lang/String;");
					jstring jstring_InputString = (jstring)env->GetObjectField(NativeActivity->clazz, jfieldID_InputString);
					const char *chars_InputString = env->GetStringUTFChars(jstring_InputString, nullptr);
					strcpy(InputString, chars_InputString);
					env->ReleaseStringUTFChars(jstring_InputString, chars_InputString);
					env->DeleteLocalRef(jstring_InputString);

				}
				env->DeleteLocalRef(jclass_as_cll);
				NativeActivity->vm->DetachCurrentThread();
			}
			else {
				break;
			}
		}
#endif
		return *this;
	}


	inline MainMap & MainMap::drawGround()
	{
		i32 about_x = -player_look_pixel + i32(-player_look_pixel * mob[mob_player_id].micro_x);
		i32 about_y = -player_look_pixel + i32(-player_look_pixel * mob[mob_player_id].micro_y);
		drawGraphGCH(about_x, about_y, map_screen_x + (player_look_pixel << 1), map_screen_y + (player_look_pixel << 1), make_ground); //todo
		return *this;
	}

	inline MainMap & MainMap::effectGroundShine()
	{
#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))
		i32 about_x = -player_look_pixel + i32(-player_look_pixel * mob[mob_player_id].micro_x);
		i32 about_y = -player_look_pixel + i32(-player_look_pixel * mob[mob_player_id].micro_y);
		drawGraphGCH(about_x, about_y, map_screen_x + (player_look_pixel << 1), map_screen_y + (player_look_pixel << 1), make_ground, u8(ground_shine >> 2)); //todo

		if (use_ground_shine) {
			ground_shine++;
			if (ground_shine == 512) use_ground_shine = false;
		}
		else {
			ground_shine--;
			if (ground_shine == 0) use_ground_shine = true;
		}
#endif
		return *this;
	}


#if !defined(GMAP_NON_NAMESPACE)
		}
#endif


#if !defined(GMAP_NON_NAMESPACE) && !defined(GMAP_NON_USE_NAMESPACE)
using namespace gmap;
#endif

#endif

#endif //Included RogueLike 0.3 Beta