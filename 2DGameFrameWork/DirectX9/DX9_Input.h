#pragma once
#define DIRECTINPUT_VERSION 0x0800
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#include <dinput.h>

namespace DX9
{

	class Input
	{
	private:
		LPDIRECTINPUT8 pDI;
		LPDIRECTINPUTDEVICE8 pKey;
		unsigned char buf[256];
		unsigned char prebuf[256];
		static const int MAX_KEY = 61;
		int dikCode[MAX_KEY];
	public:
	
		Input();
		 ~Input();
		bool CreateInput(const HWND& hwnd);
		void UpDate();
		//押した
		bool Press(const int key);
		//押している
		bool Push(const int key);
		//押されていない
		bool Free(const int key);
		//離された
		bool Pull(const int key);
		LPDIRECTINPUT8 GetpDI() const
		{
			return pDI;
		}
	};
// パッドの方向キー用  
#define PAD_UP 0x1  
#define PAD_RIGHT 0x2  
#define PAD_DOWN 0x4  
#define PAD_LEFT 0x8  
	class PadInput
	{
	private:
		
		//接続されているpadを検知する
		static BOOL CALLBACK EnumPadCallback(
			const DIDEVICEINSTANCE* inst,
			void* pContext
		);
		//パッドの設定
		static BOOL CALLBACK EnumAxisCallback(
			const DIDEVICEOBJECTINSTANCE* objInst,
			void* pContext);
		//現在使用しているパッド
		static int padNo;
		//使用するパッド数(最大4つまで)
		static const int padNum = 1;
		//DirectInputデバイスへのポインタ(最大4つまで)
		static LPDIRECTINPUTDEVICE8 pPad[padNum];
		//デバイス情報保存用
		DIDEVCAPS didevCaps[padNum];
		//現在の入力保存用
		DIJOYSTATE buf[padNum];
		//直前の入力保存
		DIJOYSTATE prebuf[padNum];

	public:
		PadInput();
		 ~PadInput();

		void CreatePadInput(const HWND& hwnd);
		void UpDate();
		//押した
		bool Press(const int key, const int no);
		//押されている
		bool Push(const int key, const int no);
		//はなされている
		bool Free(const int key, const int no);
		//はなされた
		bool Pull(const int key, const int no);

		BYTE GetPovPosition(const int no);          // 十字キーの位置を取得 
	};

	class DxMouse
	{
	private:
		LPDIRECTINPUTDEVICE8 pDIMouse;	//マウスデバイス
		DIMOUSESTATE pMouseState;				//マウス状態
		HWND pwnd;
	public:
		DxMouse();
		~DxMouse();
		POINT pos;
		bool CreateMousenput(const HWND& hwnd);

		void UpDate();
		//押されている
		bool LPush();
		bool RPush();
		POINT GetMousePos();
	};
	extern Input in;	//DirectX初期化時に生成する
	extern PadInput pad;
	extern DxMouse mouse;
}