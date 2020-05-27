#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "Player.h"
#include "Ball.h"
#include "Unity.h"

using namespace std;
using namespace sf;

class Collision
{
public:
	Collision(
		RenderWindow *gameWindow,
		Player *gamePlayer, 
		Ball *gameBall, 
		Unity *gameUnity
	);
	~Collision();

	void Update(Time time);

	void CollisionBallBoundries();
	bool CheckBallTop();
	bool CheckBallRight();
	bool CheckBallBottom();
	bool CheckBallLeft();

	void CollisionBallPlayer();
	bool CheckBallInsidePlayerWidth();
	bool CheckBallOnPlayerHeight();
	bool CheckBallUnderPlayerHeight();

	void CreateBallDirections();

private:
	RenderWindow *window;
	Player *player;
	Ball *ball;
	Unity *unity;
};

