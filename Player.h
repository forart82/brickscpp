#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "SFML/Window.hpp"
#include "list"

using namespace std;
using namespace sf;

class Player
{
public:
	Player(
		RenderWindow *gameWindow,
		Texture *gameTexture
		);
	~Player();

	void PorcessEvent(Event event);
	void Update(Time time);
	void Render();

	void CheckBorder();
	void Animation();
	Vector2f getPlayerPosition();
	FloatRect getPlayerGetGlobalBounds();


private:
	RenderWindow *window;
	Texture *texture;
	Clock clock;
	Sprite player, electic;
	Time animationTime = clock.restart();

	bool canDoInput, isMoving;
	float move, direction;
	
	const float speed= 0.0005;

	int spritesElectric[3] = { 426,600,770 };
	int spritesCounter = 0;


};


