#pragma once
#include "SceneManager.h"
#include "GameObjcet.h"
#include "Game.h"
#include "Keyboard.h"

class Title : public Scene
{
public:
	bool Initialize() override;
	void Update() override;
	void Draw() override;
	void Finalize() override;
	GameObject logo_N,logo_B, back;

	KeyBoard key;
};