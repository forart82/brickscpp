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
		Player *gamePlayer,
		bool *gameStart,
		float gameSpeed
		);
	~Ball();

	void ProcessEvent(Event event);
	void Update(Time time);
	void Render();

	Vector2f getPosition();
	FloatRect getGlobalBounds();
	Vector2f getDirection();
	void setDirection(float x, float y);


private:
	//76x76
	RenderWindow *window;
	Texture *texture;

	CircleShape ball;

	Player *player;

	Vector2f direction;
	float move, speed;
	bool *start;
};