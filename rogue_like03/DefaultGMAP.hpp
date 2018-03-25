//--------------------------------------------------
//
//	Game Map Library		-	by Kasugaccho
//
//--------------------------------------------------
#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <array>

using std::string;
using std::vector;
using std::array;

//変数型

//using u8 = uint8_t;
//using u16 = uint16_t;
//using u32 = uint32_t;
//using u64 = uint64_t;
//
//using i8 = int8_t;
//using i16 = int16_t;
//using i32 = int32_t;
//using i64 = int64_t;

using u8 = uint_fast8_t;
using u16 = uint_fast16_t;
using u32 = uint_fast32_t;
using u64 = uint_fast64_t;

using i8 = int_fast8_t;
using i16 = int_fast16_t;
using i32 = int_fast32_t;
using i64 = int_fast64_t;

using f32 = float;
using f64 = double;

#if defined(__ANDROID__) //Android専用
#if !defined(__STDINT_LIMITS)
#define INT8_MIN         (-127 - 1)
#define INT16_MIN        (-32767 - 1)
#define INT32_MIN        (-2147483647 - 1)
#define INT64_MIN        (-9223372036854775807 - 1)
#define INT8_MAX         127
#define INT16_MAX        32767
#define INT32_MAX        2147483647
#define INT64_MAX        9223372036854775807
#define UINT8_MAX        0xff
#define UINT16_MAX       0xffff
#define UINT32_MAX       0xffffffff
#define UINT64_MAX       0xffffffffffffffff
#endif
#endif

struct ColorGCH {
	u8 r = UINT8_MAX;
	u8 g = UINT8_MAX;
	u8 b = UINT8_MAX;
	u8 a = UINT8_MAX;
};

constexpr u8 KEY_ID_BACK = 0x0E;// BackSpace_BACK
constexpr u8 KEY_ID_TAB = 0x0F;// Tab_TAB
constexpr u8 KEY_ID_RETURN = 0x1C;// Enter_RETURN

constexpr u8 KEY_ID_LSHIFT = 0x2A;// 左Shift_LSHIFT
constexpr u8 KEY_ID_RSHIFT = 0x36;// 右Shift_RSHIFT
constexpr u8 KEY_ID_LCONTROL = 0x1D;// 左Ctrl_LCONTROL
constexpr u8 KEY_ID_RCONTROL = 0x9D;// 右Ctrl_RCONTROL
constexpr u8 KEY_ID_ESCAPE = 0x01;// Esc_ESCAPE
constexpr u8 KEY_ID_SPACE = 0x39;// スペース_SPACE
constexpr u8 KEY_ID_PGUP = 0xC9;// PageUp_PGUP
constexpr u8 KEY_ID_PGDN = 0xD1;// PageDown_PGDN
constexpr u8 KEY_ID_END = 0xCF;// End_END
constexpr u8 KEY_ID_HOME = 0xC7;// Home_HOME
constexpr u8 KEY_ID_LEFT = 0xCB;// 左_LEFT
constexpr u8 KEY_ID_UP = 0xC8;// 上_UP
constexpr u8 KEY_ID_RIGHT = 0xCD;// 右_RIGHT
constexpr u8 KEY_ID_DOWN = 0xD0;// 下_DOWN
constexpr u8 KEY_ID_INSERT = 0xD2;// Insert_INSERT
constexpr u8 KEY_ID_DELETE = 0xD3;// Delete_DELETE

constexpr u8 KEY_ID_MINUS = 0x0C;// －_MINUS
constexpr u8 KEY_ID_YEN = 0x7D;// ￥_YEN
constexpr u8 KEY_ID_PREVTRACK = 0x90;// ＾_PREVTRACK
constexpr u8 KEY_ID_PERIOD = 0x34;// ．_PERIOD
constexpr u8 KEY_ID_SLASH = 0x35;// ／_SLASH
constexpr u8 KEY_ID_LALT = 0x38;// 左Alt_LALT
constexpr u8 KEY_ID_RALT = 0xB8;// 右Alt_RALT
constexpr u8 KEY_ID_SCROLL = 0x46;// ScrollLock_SCROLL
constexpr u8 KEY_ID_SEMICOLON = 0x27;// ；_SEMICOLON
constexpr u8 KEY_ID_COLON = 0x92;// ：_COLON
constexpr u8 KEY_ID_LBRACKET = 0x1A;// ［_LBRACKET
constexpr u8 KEY_ID_RBRACKET = 0x1B;// ］_RBRACKET
constexpr u8 KEY_ID_AT = 0x91;// ＠_AT
constexpr u8 KEY_ID_BACKSLASH = 0x2B;// ＼_BACKSLASH
constexpr u8 KEY_ID_COMMA = 0x33;// ，_COMMA
constexpr u8 KEY_ID_KANJI = 0x94;// 漢字_KANJI
constexpr u8 KEY_ID_CONVERT = 0x79;// 変換_CONVERT
constexpr u8 KEY_ID_NOCONVERT = 0x7B;// 無変換_NOCONVERT
constexpr u8 KEY_ID_KANA = 0x70;// カナ_KANA
constexpr u8 KEY_ID_APPS = 0xDD;// アプリケーションメニュー_APPS
constexpr u8 KEY_ID_CAPSLOCK = 0x3A;// CaspLock_CAPSLOCK
constexpr u8 KEY_ID_SYSRQ = 0xB7;// PrintScreen_SYSRQ
constexpr u8 KEY_ID_PAUSE = 0xC5;// PauseBreak_PAUSE
constexpr u8 KEY_ID_LWIN = 0xDB;// 左Win_LWIN
constexpr u8 KEY_ID_RWIN = 0xDC;// 右Win_RWIN

constexpr u8 KEY_ID_NUMLOCK = 0x45;// テンNumLock_NUMLOCK
constexpr u8 KEY_ID_NUMPAD0 = 0x52;// テン０_NUMPAD0
constexpr u8 KEY_ID_NUMPAD1 = 0x4F;// テン１_NUMPAD1
constexpr u8 KEY_ID_NUMPAD2 = 0x50;// テン２_NUMPAD2
constexpr u8 KEY_ID_NUMPAD3 = 0x51;// テン３_NUMPAD3
constexpr u8 KEY_ID_NUMPAD4 = 0x4B;// テン４_NUMPAD4
constexpr u8 KEY_ID_NUMPAD5 = 0x4C;// テン５_NUMPAD5
constexpr u8 KEY_ID_NUMPAD6 = 0x4D;// テン６_NUMPAD6
constexpr u8 KEY_ID_NUMPAD7 = 0x47;// テン７_NUMPAD7
constexpr u8 KEY_ID_NUMPAD8 = 0x48;// テン８_NUMPAD8
constexpr u8 KEY_ID_NUMPAD9 = 0x49;// テン９_NUMPAD9
constexpr u8 KEY_ID_MULTIPLY = 0x37;// テン＊_MULTIPLY
constexpr u8 KEY_ID_ADD = 0x4E;// テン＋_ADD
constexpr u8 KEY_ID_SUBTRACT = 0x4A;// テン－_SUBTRACT
constexpr u8 KEY_ID_DECIMAL = 0x53;// テン．_DECIMAL
constexpr u8 KEY_ID_DIVIDE = 0xB5;// テン／_DIVIDE
constexpr u8 KEY_ID_NUMPADENTER = 0x9C;// テンのエンター_NUMPADENTER

constexpr u8 KEY_ID_F1 = 0x3B;// Ｆ１_F1
constexpr u8 KEY_ID_F2 = 0x3C;// Ｆ２_F2
constexpr u8 KEY_ID_F3 = 0x3D;// Ｆ３_F3
constexpr u8 KEY_ID_F4 = 0x3E;// Ｆ４_F4
constexpr u8 KEY_ID_F5 = 0x3F;// Ｆ５_F5
constexpr u8 KEY_ID_F6 = 0x40;// Ｆ６_F6
constexpr u8 KEY_ID_F7 = 0x41;// Ｆ７_F7
constexpr u8 KEY_ID_F8 = 0x42;// Ｆ８_F8
constexpr u8 KEY_ID_F9 = 0x43;// Ｆ９_F9
constexpr u8 KEY_ID_F10 = 0x44;// Ｆ１０_F10
constexpr u8 KEY_ID_F11 = 0x57;// Ｆ１１_F11
constexpr u8 KEY_ID_F12 = 0x58;// Ｆ１２_F12

constexpr u8 KEY_ID_A = 0x1E;// Ａ_A
constexpr u8 KEY_ID_B = 0x30;// Ｂ_B
constexpr u8 KEY_ID_C = 0x2E;// Ｃ_C
constexpr u8 KEY_ID_D = 0x20;// Ｄ_D
constexpr u8 KEY_ID_E = 0x12;// Ｅ_E
constexpr u8 KEY_ID_F = 0x21;// Ｆ_F
constexpr u8 KEY_ID_G = 0x22;// Ｇ_G
constexpr u8 KEY_ID_H = 0x23;// Ｈ_H
constexpr u8 KEY_ID_I = 0x17;// Ｉ_I
constexpr u8 KEY_ID_J = 0x24;// Ｊ_J
constexpr u8 KEY_ID_K = 0x25;// Ｋ_K
constexpr u8 KEY_ID_L = 0x26;// Ｌ_L
constexpr u8 KEY_ID_M = 0x32;// Ｍ_M
constexpr u8 KEY_ID_N = 0x31;// Ｎ_N
constexpr u8 KEY_ID_O = 0x18;// Ｏ_O
constexpr u8 KEY_ID_P = 0x19;// Ｐ_P
constexpr u8 KEY_ID_Q = 0x10;// Ｑ_Q
constexpr u8 KEY_ID_R = 0x13;// Ｒ_R
constexpr u8 KEY_ID_S = 0x1F;// Ｓ_S
constexpr u8 KEY_ID_T = 0x14;// Ｔ_T
constexpr u8 KEY_ID_U = 0x16;// Ｕ_U
constexpr u8 KEY_ID_V = 0x2F;// Ｖ_V
constexpr u8 KEY_ID_W = 0x11;// Ｗ_W
constexpr u8 KEY_ID_X = 0x2D;// Ｘ_X
constexpr u8 KEY_ID_Y = 0x15;// Ｙ_Y
constexpr u8 KEY_ID_Z = 0x2C;// Ｚ_Z

constexpr u8 KEY_ID_0 = 0x0B;// ０_0
constexpr u8 KEY_ID_1 = 0x02;// １_1
constexpr u8 KEY_ID_2 = 0x03;// ２_2
constexpr u8 KEY_ID_3 = 0x04;// ３_3
constexpr u8 KEY_ID_4 = 0x05;// ４_4
constexpr u8 KEY_ID_5 = 0x06;// ５_5
constexpr u8 KEY_ID_6 = 0x07;// ６_6
constexpr u8 KEY_ID_7 = 0x08;// ７_7
constexpr u8 KEY_ID_8 = 0x09;// ８_8
constexpr u8 KEY_ID_9 = 0x0A;// ９_9

//色系
constexpr ColorGCH COLOR_ID_WHITE = { 250,250,250,250 };
constexpr ColorGCH COLOR_ID_CARMINE = { 204,0,0,255 };

constexpr ColorGCH COLOR_ID_BLUE = { 12,0,20,255 };
constexpr ColorGCH COLOR_ID_BLACK = { 38,38,38,255 };

constexpr ColorGCH COLOR_ID_RGB_RED = { 255,0,0,255 };
constexpr ColorGCH COLOR_ID_RGB_GREEN = { 0,255,0,255 };
constexpr ColorGCH COLOR_ID_RGB_BLUE = { 0,0,255,255 };
constexpr ColorGCH COLOR_ID_RGB_BLACK = { 0,0,0,255 };
constexpr ColorGCH COLOR_ID_RGB_WHITE = { 255,255,255,255 };
constexpr ColorGCH COLOR_ID_ALPHA = { 0,0,0,0 };

i32 count_key_g[UINT8_MAX + 1] = {};
u8 click_key_g[UINT8_MAX + 1] = {};
u8 release_key_g[UINT8_MAX + 1] = {};
u8 keyconfig_g[UINT8_MAX + 1] = {};


#if (defined(__WINDOWS__) || defined(__ANDROID__) || defined(GMAP_USE_D_LIB))

using TEXTURE_VECTOR_TYPE = int;
using TEXTURE_VECTOR = vector<int>;

using FONT_TYPE = int;
constexpr int FONT_INIT = -1;
using TEXTURE_TYPE = int;
constexpr int TEXTURE_INIT = -1;

//臨時
inline int loadDivisionGraphGCH(const char* name, array<int, 9>& handle, const i32 x_count, const i32 y_count, const i32 x_len, const i32 y_len)
{
	return LoadDivGraph(name, x_count*y_count, x_count, y_count, x_len, y_len, handle.data());
}



inline i32 mousePosGCH(int* mouse_x, int* mouse_y)
{
	return GetMousePoint(mouse_x, mouse_y);
}

inline i32 mouseClickGCH()
{
	if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) return 1;
	else return 0;
}

inline int loadDivisionGraphGCH(const char* name, vector<int>& handle, const i32 x_count, const i32 y_count, const i32 x_len, const i32 y_len)
{
	return LoadDivGraph(name, x_count*y_count, x_count, y_count, x_len, y_len, handle.data());
}

inline void loadDivisionGraphGCH(const char* name, int* handle, const i32 x_count, const i32 y_count, const i32 x_len, const i32 y_len)
{
	LoadDivGraph(name, x_count*y_count, x_count, y_count, x_len, y_len, handle);
	return;
}

inline bool loopGCH()
{
	return (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen() && !CheckHitKey(KEY_ID_ESCAPE));
}

inline int loadGraphGCH(const char* name)
{
	return LoadGraph(name);
}

inline int drawGraphGCH(const i32 start_x, const i32 start_y, const i32 len_x, const i32 len_y, const i32 handle, const u8 alpha = UINT8_MAX, const bool turn = false)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	if(turn) return DrawExtendGraph(start_x + len_x, start_y, start_x, start_y + len_y, handle, TRUE);
	else return DrawExtendGraph(start_x, start_y, start_x + len_x, start_y + len_y, handle, TRUE);
}

inline void drawBoxGCH(const i32 start_x, const i32 start_y, const i32 len_x, const i32 len_y, const ColorGCH& color_gch)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, color_gch.a);
	DrawBox(start_x, start_y, start_x + len_x, start_y + len_y, GetColor(color_gch.r, color_gch.g, color_gch.b), TRUE);
	return;
}

inline i32 drawGraphBoxGCH(const i32 start_x, const i32 start_y, const i32 len_x, const i32 len_y, const int handle, const ColorGCH& color_gch)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, color_gch.a);
	if (handle == -1) {
		DrawBox(start_x, start_y, start_x + len_x, start_y + len_y, GetColor(color_gch.r, color_gch.g, color_gch.b), TRUE);
		return -1;
	}

	DrawExtendGraph(start_x, start_y, start_x + len_x, start_y + len_y, handle, TRUE);
	return 0;
}

inline int createFontGCH(const char* font_name, const i32 font_size)
{
	return CreateFontToHandle(font_name, font_size, 9, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

inline void updateKey() {
	char push_key_g[256] = {};
	GetHitKeyStateAll(push_key_g);
	for (i32 i = 0; i < 256; i++) {
		//キーコンフィグ
		i32 ii = keyconfig_g[i];

		if (push_key_g[ii] != 0 && count_key_g[ii] != INT32_MAX) {
			//クリック判定
			if (!count_key_g[ii]) click_key_g[ii] = 1;
			else click_key_g[ii] = 0;

			release_key_g[ii] = 0;
			count_key_g[ii]++;

		}
		else {
			//リリース判定
			if (count_key_g[ii]) release_key_g[ii] = 1;
			else release_key_g[ii] = 0;

			click_key_g[ii] = 0;
			count_key_g[ii] = 0;
		}
	}
}

inline bool clickKeyGCH(const u8 key_id)
{
	return click_key_g[key_id];
}

inline bool releaseKeyGCH(const u8 key_id)
{
	return release_key_g[key_id];
}

inline bool countKeyGCH(const u8 key_id)
{
	return count_key_g[key_id];
}

template<typename... Rest> inline void printfGCH(const char *format_string, const Rest&... rest)
{
	printfDx(format_string, rest...);
	return;
}

template<typename... Rest> inline void drawStringGCH(const i32 x, const i32 y, const ColorGCH& color, const int font, const char *format_string, const Rest&... rest)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, color.a);
	DrawFormatStringFToHandle(f32(x), f32(y), GetColor(color.r, color.g, color.b), font, format_string, rest...);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, UINT8_MAX);
	return;
}

inline void drawStringGCH(const i32 x, const i32 y, const ColorGCH& color, const int font, const char *format_string)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, color.a);
	DrawStringFToHandle(f32(x), f32(y), format_string, GetColor(color.r, color.g, color.b), font);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, UINT8_MAX);
	return;
}

inline void loadSound(const char *file_name)
{
	LoadSoundMem(file_name);
	return;
}

inline void playSound(const int sound_handle)
{
	PlaySoundMem(sound_handle, DX_PLAYTYPE_LOOP);
	return;
}

inline void playSE(const int sound_handle)
{
	PlaySoundMem(sound_handle, DX_PLAYTYPE_BACK);
	return;
}

void deleteSound(const int sound_handle)
{
	DeleteSoundMem(sound_handle);
	return;
}

inline void mapChipGCH(i32 mc_x, i32 mc_y, i32 mc_size, i32 mc_max, i32 mc_count, int* chip_p, i32 n1, i32 n2, i32 n3, i32 n4)
{
	drawGraphGCH(mc_size * mc_x, mc_size * (mc_y + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n1 * 2) * mc_max + mc_count)]);
	drawGraphGCH(mc_size * (mc_x + 1), mc_size * (mc_y + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n2 * 2) * mc_max + mc_count) + 1]);

	drawGraphGCH(mc_size * mc_x, mc_size * (mc_y + 1 + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n3 * 2 + 1) * mc_max + mc_count)]);
	drawGraphGCH(mc_size * (mc_x + 1), mc_size * (mc_y + 1 + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n4 * 2 + 1) * mc_max + mc_count) + 1]);
	return;
}

#endif


#if (defined(SIV3D_INCLUDED) || defined(GMAP_USE_S_LIB))

using TEXTURE_VECTOR = Array<TextureRegion>;
using FONT_TYPE = Font;
#define FONT_INIT Font(60)
using TEXTURE_TYPE = Texture;
#define TEXTURE_INIT TEXTURE_TYPE(U"a.png")

inline i32 resizeGCH(i32 resize_x, i32 resize_y)
{
	Window::Resize(resize_x, resize_y);
	return 0;
}

inline i32 initGCH()
{
	static RenderStateBlock2D wireframe(SamplerState::ClampNearest);
	return 0;
}

inline i32 mousePosGCH(int* mouse_x, int* mouse_y)
{
	*mouse_x = Cursor::Pos().x;
	*mouse_y = Cursor::Pos().y;
	return 0;
}

inline i32 mouseClickGCH()
{
	if (MouseL.down()) return 1;
	else return 0;
}

template<typename... Rest> string printString(const char *FormatString, const Rest&... rest)
{
	constexpr i32 PRINT_STRING_MAX = 1024;
	char snString[PRINT_STRING_MAX];
	snprintf(snString, sizeof(snString), FormatString, rest...);
	return string(snString);
}

template<typename... Rest> void printfGCH(const char *format_string, const Rest&... rest)
{
	Print(Unicode::UTF8ToUTF32(printString(format_string, rest...)));
	return;
}

template<typename... Rest> void drawStringGCH(i32 x, i32 y, ColorGCH color, Font& font, const char *format_string, const Rest&... rest)
{
	font(Unicode::UTF8ToUTF32(printString(format_string, rest...))).draw(x, y, Color(color.r, color.g, color.b, color.a));
	return;
}

bool loopGCH()
{
	return System::Update();
}

Font createFontGCH(const char* font_name, i32 font_size)
{
	string string_name = string(font_name);
	Font newFont(font_size);//, Typeface::Heavy, Unicode::UTF8ToUTF32(string_name)
	return newFont;
}

Array<TextureRegion> LoadDiv(const FilePath& path, int a, int b, const Size& size)
{
#if defined(SIV3D_TARGET_MACOS)
	const Texture texture(Resource(path));
#else
	const Texture texture(path);
#endif
	Array<TextureRegion> textureRegions;

	for (auto p : step(Size(a, b)))
	{
		textureRegions.push_back(texture(p * size, size));
	}

	return textureRegions;
}

i32 loadDivisionGraphGCH(const char* name, Array<TextureRegion>& handle, i32 x_count, i32 y_count, i32 x_len, i32 y_len)
{
	string string_name = string(name);
	handle = LoadDiv(Unicode::UTF8ToUTF32(string_name), x_count, y_count, Size(x_len, y_len));
	return 0;
}

Texture loadGraphGCH(const char* name)
{
	string string_name = string(name);
#if defined(SIV3D_TARGET_MACOS)
	Texture newTexture(Resource(Unicode::UTF8ToUTF32(string_name)));
#else
	Texture newTexture(Unicode::UTF8ToUTF32(string_name));
#endif
	return newTexture;
}

i32 drawGraphGCH(i32 start_x, i32 start_y, i32 len_x, i32 len_y, TextureRegion& handle, u8 alpha = UINT8_MAX)
{
	handle.resized(len_x, len_y).draw(start_x, start_y, Alpha(alpha));
	return 0;
}

i32 drawGraphGCH(i32 start_x, i32 start_y, i32 len_x, i32 len_y, Texture& handle, u8 alpha = UINT8_MAX)
{
	//if (!handle) return -1;
	handle.resized(len_x, len_y).draw(start_x, start_y, Alpha(alpha));
	return 0;
}

i32 drawGraphBoxGCH(i32 start_x, i32 start_y, i32 len_x, i32 len_y, Texture& handle, ColorGCH& color_gch)
{
	if (!handle) {
		Rect(start_x, start_y, len_x, len_y).draw(Color(color_gch.r, color_gch.g, color_gch.b, color_gch.a));
		return -1;
	}

	handle.resized(len_x, len_y).draw(start_x, start_y, Alpha(color_gch.a));
	return 0;
}

inline void mapChipGCH(i32 mc_x, i32 mc_y, i32 mc_size, i32 mc_max, i32 mc_count, TEXTURE_VECTOR& chip_p, i32 n1, i32 n2, i32 n3, i32 n4)
{
	drawGraphGCH(mc_size * mc_x, mc_size * (mc_y + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n1 * 2) * mc_max + mc_count)]);
	drawGraphGCH(mc_size * (mc_x + 1), mc_size * (mc_y + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n2 * 2) * mc_max + mc_count) + 1]);

	drawGraphGCH(mc_size * mc_x, mc_size * (mc_y + 1 + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n3 * 2 + 1) * mc_max + mc_count)]);
	drawGraphGCH(mc_size * (mc_x + 1), mc_size * (mc_y + 1 + mc_count * 12), mc_size, mc_size, chip_p[2 * ((n4 * 2 + 1) * mc_max + mc_count) + 1]);
	return;
}

void drawBoxGCH(i32 start_x, i32 start_y, i32 len_x, i32 len_y, ColorGCH color_gch)
{
	Rect(start_x, start_y, len_x, len_y).draw(Color(color_gch.r, color_gch.g, color_gch.b, color_gch.a));
	return;
}

bool clickKeyGCH(u8 key_id)
{
	switch (keyconfig_g[key_id])
	{
	case KEY_ID_Q:return (click_key_g[key_id] || KeyQ.down());
	case KEY_ID_W:return (click_key_g[key_id] || KeyW.down());
	case KEY_ID_E:return (click_key_g[key_id] || KeyE.down());
	case KEY_ID_R:return (click_key_g[key_id] || KeyR.down());
	case KEY_ID_T:return (click_key_g[key_id] || KeyT.down());
	case KEY_ID_Y:return (click_key_g[key_id] || KeyY.down());
	case KEY_ID_U:return (click_key_g[key_id] || KeyU.down());
	case KEY_ID_I:return (click_key_g[key_id] || KeyI.down());
	case KEY_ID_O:return (click_key_g[key_id] || KeyO.down());
	case KEY_ID_P:return (click_key_g[key_id] || KeyP.down());
	case KEY_ID_A:return (click_key_g[key_id] || KeyA.down());
	case KEY_ID_S:return (click_key_g[key_id] || KeyS.down());
	case KEY_ID_D:return (click_key_g[key_id] || KeyD.down());
	case KEY_ID_F:return (click_key_g[key_id] || KeyF.down());
	case KEY_ID_G:return (click_key_g[key_id] || KeyG.down());
	case KEY_ID_H:return (click_key_g[key_id] || KeyH.down());
	case KEY_ID_J:return (click_key_g[key_id] || KeyJ.down());
	case KEY_ID_K:return (click_key_g[key_id] || KeyK.down());
	case KEY_ID_L:return (click_key_g[key_id] || KeyL.down());
	case KEY_ID_Z:return (click_key_g[key_id] || KeyZ.down());
	case KEY_ID_X:return (click_key_g[key_id] || KeyX.down());
	case KEY_ID_C:return (click_key_g[key_id] || KeyC.down());
	case KEY_ID_V:return (click_key_g[key_id] || KeyV.down());
	case KEY_ID_B:return (click_key_g[key_id] || KeyB.down());
	case KEY_ID_N:return (click_key_g[key_id] || KeyN.down());
	case KEY_ID_M:return (click_key_g[key_id] || KeyM.down());

	case KEY_ID_0:return (click_key_g[key_id] || Key0.down());
	case KEY_ID_1:return (click_key_g[key_id] || Key1.down());
	case KEY_ID_2:return (click_key_g[key_id] || Key2.down());
	case KEY_ID_3:return (click_key_g[key_id] || Key3.down());
	case KEY_ID_4:return (click_key_g[key_id] || Key4.down());
	case KEY_ID_5:return (click_key_g[key_id] || Key5.down());
	case KEY_ID_6:return (click_key_g[key_id] || Key6.down());
	case KEY_ID_7:return (click_key_g[key_id] || Key7.down());
	case KEY_ID_8:return (click_key_g[key_id] || Key8.down());
	case KEY_ID_9:return (click_key_g[key_id] || Key9.down());

	case KEY_ID_F1:return (click_key_g[key_id] || KeyF1.down());
	case KEY_ID_F2:return (click_key_g[key_id] || KeyF2.down());
	case KEY_ID_F3:return (click_key_g[key_id] || KeyF3.down());
	case KEY_ID_F4:return (click_key_g[key_id] || KeyF4.down());
	case KEY_ID_F5:return (click_key_g[key_id] || KeyF5.down());
	case KEY_ID_F6:return (click_key_g[key_id] || KeyF6.down());
	case KEY_ID_F7:return (click_key_g[key_id] || KeyF7.down());
	case KEY_ID_F8:return (click_key_g[key_id] || KeyF8.down());
	case KEY_ID_F9:return (click_key_g[key_id] || KeyF9.down());
	case KEY_ID_F10:return (click_key_g[key_id] || KeyF10.down());
	case KEY_ID_F11:return (click_key_g[key_id] || KeyF11.down());
	case KEY_ID_F12:return (click_key_g[key_id] || KeyF12.down());

	case KEY_ID_UP:return (click_key_g[key_id] || KeyUp.down());
	case KEY_ID_DOWN:return (click_key_g[key_id] || KeyDown.down());
	case KEY_ID_LEFT:return (click_key_g[key_id] || KeyLeft.down());
	case KEY_ID_RIGHT:return (click_key_g[key_id] || KeyRight.down());

	case KEY_ID_HOME:return (click_key_g[key_id] || KeyHome.down());
	}
	return false;
}

bool releaseKeyGCH(u8 key_id)
{
	switch (keyconfig_g[key_id])
	{
	case KEY_ID_Q:return (release_key_g[key_id] || KeyQ.up());
	case KEY_ID_W:return (release_key_g[key_id] || KeyW.up());
	case KEY_ID_E:return (release_key_g[key_id] || KeyE.up());
	case KEY_ID_R:return (release_key_g[key_id] || KeyR.up());
	case KEY_ID_T:return (release_key_g[key_id] || KeyT.up());
	case KEY_ID_Y:return (release_key_g[key_id] || KeyY.up());
	case KEY_ID_U:return (release_key_g[key_id] || KeyU.up());
	case KEY_ID_I:return (release_key_g[key_id] || KeyI.up());
	case KEY_ID_O:return (release_key_g[key_id] || KeyO.up());
	case KEY_ID_P:return (release_key_g[key_id] || KeyP.up());
	case KEY_ID_A:return (release_key_g[key_id] || KeyA.up());
	case KEY_ID_S:return (release_key_g[key_id] || KeyS.up());
	case KEY_ID_D:return (release_key_g[key_id] || KeyD.up());
	case KEY_ID_F:return (release_key_g[key_id] || KeyF.up());
	case KEY_ID_G:return (release_key_g[key_id] || KeyG.up());
	case KEY_ID_H:return (release_key_g[key_id] || KeyH.up());
	case KEY_ID_J:return (release_key_g[key_id] || KeyJ.up());
	case KEY_ID_K:return (release_key_g[key_id] || KeyK.up());
	case KEY_ID_L:return (release_key_g[key_id] || KeyL.up());
	case KEY_ID_Z:return (release_key_g[key_id] || KeyZ.up());
	case KEY_ID_X:return (release_key_g[key_id] || KeyX.up());
	case KEY_ID_C:return (release_key_g[key_id] || KeyC.up());
	case KEY_ID_V:return (release_key_g[key_id] || KeyV.up());
	case KEY_ID_B:return (release_key_g[key_id] || KeyB.up());
	case KEY_ID_N:return (release_key_g[key_id] || KeyN.up());
	case KEY_ID_M:return (release_key_g[key_id] || KeyM.up());

	case KEY_ID_0:return (release_key_g[key_id] || Key0.up());
	case KEY_ID_1:return (release_key_g[key_id] || Key1.up());
	case KEY_ID_2:return (release_key_g[key_id] || Key2.up());
	case KEY_ID_3:return (release_key_g[key_id] || Key3.up());
	case KEY_ID_4:return (release_key_g[key_id] || Key4.up());
	case KEY_ID_5:return (release_key_g[key_id] || Key5.up());
	case KEY_ID_6:return (release_key_g[key_id] || Key6.up());
	case KEY_ID_7:return (release_key_g[key_id] || Key7.up());
	case KEY_ID_8:return (release_key_g[key_id] || Key8.up());
	case KEY_ID_9:return (release_key_g[key_id] || Key9.up());

	case KEY_ID_F1:return (release_key_g[key_id] || KeyF1.up());
	case KEY_ID_F2:return (release_key_g[key_id] || KeyF2.up());
	case KEY_ID_F3:return (release_key_g[key_id] || KeyF3.up());
	case KEY_ID_F4:return (release_key_g[key_id] || KeyF4.up());
	case KEY_ID_F5:return (release_key_g[key_id] || KeyF5.up());
	case KEY_ID_F6:return (release_key_g[key_id] || KeyF6.up());
	case KEY_ID_F7:return (release_key_g[key_id] || KeyF7.up());
	case KEY_ID_F8:return (release_key_g[key_id] || KeyF8.up());
	case KEY_ID_F9:return (release_key_g[key_id] || KeyF9.up());
	case KEY_ID_F10:return (release_key_g[key_id] || KeyF10.up());
	case KEY_ID_F11:return (release_key_g[key_id] || KeyF11.up());
	case KEY_ID_F12:return (release_key_g[key_id] || KeyF12.up());

	case KEY_ID_UP:return (release_key_g[key_id] || KeyUp.up());
	case KEY_ID_DOWN:return (release_key_g[key_id] || KeyDown.up());
	case KEY_ID_LEFT:return (release_key_g[key_id] || KeyLeft.up());
	case KEY_ID_RIGHT:return (release_key_g[key_id] || KeyRight.up());

	case KEY_ID_HOME:return (release_key_g[key_id] || KeyHome.up());
	}
	return false;
}

bool countKeyGCH(u8 key_id)
{
	switch (keyconfig_g[key_id])
	{
	case KEY_ID_Q:return (click_key_g[key_id] || KeyQ.pressed());
	case KEY_ID_W:return (click_key_g[key_id] || KeyW.pressed());
	case KEY_ID_E:return (click_key_g[key_id] || KeyE.pressed());
	case KEY_ID_R:return (click_key_g[key_id] || KeyR.pressed());
	case KEY_ID_T:return (click_key_g[key_id] || KeyT.pressed());
	case KEY_ID_Y:return (click_key_g[key_id] || KeyY.pressed());
	case KEY_ID_U:return (click_key_g[key_id] || KeyU.pressed());
	case KEY_ID_I:return (click_key_g[key_id] || KeyI.pressed());
	case KEY_ID_O:return (click_key_g[key_id] || KeyO.pressed());
	case KEY_ID_P:return (click_key_g[key_id] || KeyP.pressed());
	case KEY_ID_A:return (click_key_g[key_id] || KeyA.pressed());
	case KEY_ID_S:return (click_key_g[key_id] || KeyS.pressed());
	case KEY_ID_D:return (click_key_g[key_id] || KeyD.pressed());
	case KEY_ID_F:return (click_key_g[key_id] || KeyF.pressed());
	case KEY_ID_G:return (click_key_g[key_id] || KeyG.pressed());
	case KEY_ID_H:return (click_key_g[key_id] || KeyH.pressed());
	case KEY_ID_J:return (click_key_g[key_id] || KeyJ.pressed());
	case KEY_ID_K:return (click_key_g[key_id] || KeyK.pressed());
	case KEY_ID_L:return (click_key_g[key_id] || KeyL.pressed());
	case KEY_ID_Z:return (click_key_g[key_id] || KeyZ.pressed());
	case KEY_ID_X:return (click_key_g[key_id] || KeyX.pressed());
	case KEY_ID_C:return (click_key_g[key_id] || KeyC.pressed());
	case KEY_ID_V:return (click_key_g[key_id] || KeyV.pressed());
	case KEY_ID_B:return (click_key_g[key_id] || KeyB.pressed());
	case KEY_ID_N:return (click_key_g[key_id] || KeyN.pressed());
	case KEY_ID_M:return (click_key_g[key_id] || KeyM.pressed());

	case KEY_ID_0:return (click_key_g[key_id] || Key0.pressed());
	case KEY_ID_1:return (click_key_g[key_id] || Key1.pressed());
	case KEY_ID_2:return (click_key_g[key_id] || Key2.pressed());
	case KEY_ID_3:return (click_key_g[key_id] || Key3.pressed());
	case KEY_ID_4:return (click_key_g[key_id] || Key4.pressed());
	case KEY_ID_5:return (click_key_g[key_id] || Key5.pressed());
	case KEY_ID_6:return (click_key_g[key_id] || Key6.pressed());
	case KEY_ID_7:return (click_key_g[key_id] || Key7.pressed());
	case KEY_ID_8:return (click_key_g[key_id] || Key8.pressed());
	case KEY_ID_9:return (click_key_g[key_id] || Key9.pressed());

	case KEY_ID_F1:return (click_key_g[key_id] || KeyF1.pressed());
	case KEY_ID_F2:return (click_key_g[key_id] || KeyF2.pressed());
	case KEY_ID_F3:return (click_key_g[key_id] || KeyF3.pressed());
	case KEY_ID_F4:return (click_key_g[key_id] || KeyF4.pressed());
	case KEY_ID_F5:return (click_key_g[key_id] || KeyF5.pressed());
	case KEY_ID_F6:return (click_key_g[key_id] || KeyF6.pressed());
	case KEY_ID_F7:return (click_key_g[key_id] || KeyF7.pressed());
	case KEY_ID_F8:return (click_key_g[key_id] || KeyF8.pressed());
	case KEY_ID_F9:return (click_key_g[key_id] || KeyF9.pressed());
	case KEY_ID_F10:return (click_key_g[key_id] || KeyF10.pressed());
	case KEY_ID_F11:return (click_key_g[key_id] || KeyF11.pressed());
	case KEY_ID_F12:return (click_key_g[key_id] || KeyF12.pressed());

	case KEY_ID_UP:return (click_key_g[key_id] || KeyUp.pressed());
	case KEY_ID_DOWN:return (click_key_g[key_id] || KeyDown.pressed());
	case KEY_ID_LEFT:return (click_key_g[key_id] || KeyLeft.pressed());
	case KEY_ID_RIGHT:return (click_key_g[key_id] || KeyRight.pressed());

	case KEY_ID_HOME:return (click_key_g[key_id] || KeyHome.pressed());
	}
	return false;
}

#endif

#if (defined(__WINDOWS__) || defined(SIV3D_TARGET_WINDOWS))
inline void readBinaryFile(const char* save_name, const char* file_name, void* read_buf, size_t read_size, size_t read_nmemb)
{
	FILE  *cfp_fp;
	errno_t cfp_error;
	string read_file_name = string(save_name) + "\\" + string(file_name);

	cfp_error = fopen_s(&cfp_fp, read_file_name.c_str(), "rb");
	if (!cfp_error) {
		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
	}
	return;
}

inline void writeBinaryFile(const char* save_name, const char* file_name, void* read_buf, size_t read_size, size_t read_nmemb)
{
	FILE  *cfp_fp;
	errno_t cfp_error;
	string read_file_name = string(save_name) + "\\" + string(file_name);

	cfp_error = fopen_s(&cfp_fp, read_file_name.c_str(), "wb");
	if (!cfp_error) {
		fwrite(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
	}
	return;
}
#endif

#if (defined(SIV3D_TARGET_MACOS) || defined(SIV3D_TARGET_LINUX))
inline void readBinaryFile(const char* save_name, const char* file_name, void* read_buf, size_t read_size, size_t read_nmemb)
{
	FILE  *cfp_fp;
	string read_file_name = string(save_name) + "\\" + string(file_name);

	cfp_fp = fopen(read_file_name.c_str(), "rb");
	if (cfp_fp != NULL) {
		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
	}
	return;
}

inline void writeBinaryFile(const char* save_name, const char* file_name, void* read_buf, size_t read_size, size_t read_nmemb)
{
	FILE  *cfp_fp;
	string read_file_name = string(save_name) + "\\" + string(file_name);

	cfp_fp = fopen(read_file_name.c_str(), "wb");
	if (cfp_fp != NULL) {
		fwrite(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
	}
	return;
}
#endif

#if defined(__ANDROID__)
inline void readBinaryFile(const char* save_name, const char* file_name, void* read_buf, size_t read_size, size_t read_nmemb)
{
	FILE  *cfp_fp;
	char FilePath[256];
	GetExternalDataPath(FilePath, sizeof(FilePath));

	string fp_name = string(FilePath) + "\\" + string(file_name);

	cfp_fp = fopen(fp_name.c_str(), "rb");
	if (cfp_fp != NULL) {
		fread(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
	}
	return;
}

inline void writeBinaryFile(const char* save_name, const char* file_name, void* read_buf, size_t read_size, size_t read_nmemb)
{
	FILE  *cfp_fp;
	char FilePath[256];
	GetExternalDataPath(FilePath, sizeof(FilePath));

	string fp_name = string(FilePath) + "\\" + string(file_name);

	cfp_fp = fopen(fp_name.c_str(), "wb");
	if (cfp_fp != NULL) {
		fwrite(read_buf, read_size, read_nmemb, cfp_fp);
		fclose(cfp_fp);
	}
	return;
}
#endif