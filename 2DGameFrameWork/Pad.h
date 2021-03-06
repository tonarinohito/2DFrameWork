#pragma once
#include "DirectX9/DX9_Input.h"
#include "Keyboard.h"
class Pad
{
public:
	enum class NO {
		P1,
		P2,
	};
	enum class Button
	{
		//仮(Logicool Gamepad F310)
		PAD_X,		//0
		PAD_A,		//1
		PAD_B,		//2
		PAD_Y,		//3
		PAD_L1,		//4
		PAD_R1,		//5
		PAD_L2,		//6
		PAD_R2,		//7
		PAD_SELECT,	//8(BACK)
		PAD_START,	//9
		PAD_L3,		//10
		PAD_R3,		//11
	
	};

	// パッドの方向キー用  
	enum class Stick
	{
		UP = 0x1,
		RIGHT = 0x2,
		DOWN = 0x4,
		LEFT = 0x8,
		UP_RIGHT = 0x1 | 0x2,
		UP_LEFT = 0x1 | 0x8,
		DOWN_RIGHT = 0x4 | 0x2,
		DOWN_LEFT = 0x4 | 0x8,
		NONE,
	};
 
	void Run();

	bool Down(const Button& key, const NO& no = Pad::NO::P1);

	bool On(const Button& key, const NO& no = Pad::NO::P1);

	bool Free(const Button& key, const NO& no = Pad::NO::P1);

	bool Pull(const Button& key, const NO& no = Pad::NO::P1);

	bool StickOn(const Stick& key, const NO& no = Pad::NO::P1);

};