#include "Ball.h"

Ball::Ball(
	RenderWindow *gameWindow,
	Texture *gameTexture,
	Player *gamePlayer,
	bool *gameStart,
	float gameSpeed
	)
{
	window = gameWindow;
	texture = gameTexture;
	player = gamePlayer;
	start = gameStart;
	speed = gameSpeed;

	ball.setRadius(20.f);
	ball.setTexture(texture);
	ball.setTextureRect(IntRect(805, 547, 76, 76));
	ball.setPosition(
		player->getPlayerPosition().x + player->getPlayerGetGlobalBounds().width / 2 - ball.getGlobalBounds().width / 2,
		player->getPlayerPosition().y - ball.getGlobalBounds().height
	);
	ball.setScale(0.5, 0.5);

	move = speed;
	direction.x = 1;
	direction.y = 1;


}

Ball::~Ball()
{
}

void Ball::ProcessEvent(Event)
{

}

void Ball::Update(Time time)
{
	if (!*start)
	{
		ball.setPosition(
			player->getPlayerPosition().x + player->getPlayerGetGlobalBounds().width / 2 - ball.getGlobalBounds().width / 2,
			player->getPlayerPosition().y - ball.getGlobalBounds().height
		);
	}
	else
	{
		ball.setPosition(
			ball.getPosition().x, 
			ball.getPosition().y - direction.y *(move * time.asMicroseconds())
		);
		//move -= 0.00000005f;
		if (move <= 0)
		{
			move = 0;
		}
	}

}

void Ball::Render()
{
	window->draw(ball);
}

Vector2f Ball::getPosition()
{
	return ball.getPosition();
}

FloatRect Ball::getGlobalBounds()
{
	return ball.getGlobalBounds();
}

Vector2f Ball::getDirection()
{
	return direction;
}

void Ball::setDirection(float x, float y)
{
	direction.x = x;
	direction.y = y;
}
