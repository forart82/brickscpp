#include "Ball.h"

Ball::Ball(
	RenderWindow *gameWindow,
	Texture *gameTexture,
	Player *gamePlayer
	)
{
	window = gameWindow;
	texture = gameTexture;
	player = gamePlayer;

	ball.setRadius(20.f);
	ball.setTexture(texture);
	ball.setTextureRect(IntRect(805, 547, 76, 76));
	ball.setPosition(
		player->getPlayerPosition().x + player->getPlayerGetGlobalBounds().width / 2 - ball.getGlobalBounds().width / 2,
		player->getPlayerPosition().y - ball.getGlobalBounds().height
	);
	ball.setScale(0.5, 0.5);
}

Ball::~Ball()
{
}

void Ball::ProcessEvent()
{
}

void Ball::Update(Time time)
{
	ball.setPosition(
		player->getPlayerPosition().x +player->getPlayerGetGlobalBounds().width/ 2 - ball.getGlobalBounds().width / 2,
		player->getPlayerPosition().y - ball.getGlobalBounds().height
	);
}

void Ball::Render()
{
	window->draw(ball);
}
