#include "Collision.h"

Collision::Collision(Player * gamePlayer, Ball * gameBall, Unity * gameUnity)
{
	player = gamePlayer;
	ball = gameBall;
	unity = gameUnity;
}

Collision::~Collision()
{
}

void Collision::Update(Time time)
{
	CollisionBallBoundries();
	CollisionBallPlayer();
}

void Collision::CollisionBallBoundries()
{
	if (ball->getPosition().y <= 0)
	{
		ball->setDirection(ball->getDirection().x, ball->getDirection().y*-1);
	}
}

void Collision::CollisionBallPlayer()
{
	if(CheckBallInsidePlayerWidth() && CheckBallUnderPlayerHeight())
		if (CheckBallOnPlayerHeight())
		{
			ball->setDirection(ball->getDirection().x, ball->getDirection().y*-1);
		}
}

bool Collision::CheckBallInsidePlayerWidth()
{
	if (
		ball->getPosition().x + ball->getGlobalBounds().width >
		player->getPlayerPosition().x &&
		ball->getPosition().x <
		player->getPlayerGetGlobalBounds().width + player->getPlayerPosition().x
		)
	{
		return true;
	}
	return false;
}

bool Collision::CheckBallOnPlayerHeight()
{
	if (
		ball->getPosition().y + ball->getGlobalBounds().width >
		player->getPlayerPosition().y
		)
	{
		return true;
	}
	return false;
}

bool Collision::CheckBallUnderPlayerHeight()
{
	if (
		ball->getPosition().y + ball->getGlobalBounds().width / 2  >
		player->getPlayerPosition().y
		)
	{
		return false;
	}
	return true;
}
