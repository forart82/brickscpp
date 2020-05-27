#include "Collision.h"

Collision::Collision(
	RenderWindow *gameWindow,
	Player * gamePlayer, 
	Ball * gameBall, 
	Unity * gameUnity
)
{
	window = gameWindow;
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
	if (CheckBallTop())
	{
		ball->setDirection(ball->getDirection().x, ball->getDirection().y*-1);
	}
	if (CheckBallRight())
	{
		ball->setDirection(ball->getDirection().x*-1, ball->getDirection().y);
	}
	if (CheckBallBottom())
	{
		ball->setDirection(ball->getDirection().x, ball->getDirection().y*-1);
	}
	if (CheckBallLeft())
	{
		ball->setDirection(ball->getDirection().x*-1, ball->getDirection().y);
	}
}

bool Collision::CheckBallTop()
{
	if (ball->getPosition().y <= 0) return true;

	return false;
}

bool Collision::CheckBallRight()
{
	if (ball->getPosition().x + ball->getGlobalBounds().width >= window->getSize().x) return true;

	return false;
}

bool Collision::CheckBallBottom()
{
	if (ball->getPosition().y +ball->getGlobalBounds().height >= window->getSize().y) return true;

	return false;
}

bool Collision::CheckBallLeft()
{
	if (ball->getPosition().x <= 0) return true;

	return false;
}

void Collision::CollisionBallPlayer()
{
	if(CheckBallInsidePlayerWidth() && CheckBallUnderPlayerHeight())
		if (CheckBallOnPlayerHeight())
		{
			CreateBallDirections();
			ball->setDirection(ball->getDirection().x*-1, ball->getDirection().y*-1);
		}
}

bool Collision::CheckBallInsidePlayerWidth()
{
	if (
		ball->getPosition().x + ball->getGlobalBounds().width >
		player->getPosition().x &&
		ball->getPosition().x <
		player->getGlobalBounds().width + player->getPosition().x
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
		player->getPosition().y
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
		player->getPosition().y
		)
	{
		return false;
	}
	return true;
}

void Collision::CreateBallDirections()
{
	float segments = player->getGlobalBounds().width / 10;
	float ballPosition = ball->getPosition().x + ball->getGlobalBounds().width / 2;
	float playerPosition = player->getPosition().x;
	float segement = playerPosition - ballPosition;
	cout << segement << endl;
	if (segement < 25)
	{
		ball->setDirection(1, ball->getDirection().y);
	}
	if (segement > 25 && segement <50)
	{
		ball->setDirection(0, ball->getDirection().y);
	}
	if (segement >50 && segement <75)
	{
		ball->setDirection(-1, ball->getDirection().y);
	}

}

