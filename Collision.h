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
		Player *gamePlayer, 
		Ball *gameBall, 
		Unity *gameUnity);
	~Collision();

	void Update(Time time);

	void CollisionBallBoundries();
	void CollisionBallPlayer();
	bool CheckBallInsidePlayerWidth();
	bool CheckBallOnPlayerHeight();
	bool CheckBallUnderPlayerHeight();

private:
	Player *player;
	Ball *ball;
	Unity *unity;
};

