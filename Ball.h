#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "Player.h"

using namespace std;
using namespace sf;

class Ball
{
public:
	Ball(
		RenderWindow *gameWindow,
		Texture *gameTexture,
		Player *gamePlayer
		);
	~Ball();

	void ProcessEvent();
	void Update(Time time);
	void Render();

private:
	//76x76
	RenderWindow *window;
	Texture *texture;

	CircleShape ball;

	Player *player;
};