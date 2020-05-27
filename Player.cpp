#include "Player.h"

Player::Player(
	RenderWindow *gameWindow,
	Texture *gameTexture,
	bool *gameStart,
	float gameSpeed
	)
{
	window = gameWindow;
	texture = gameTexture;
	start = gameStart;
	speed = gameSpeed;

	player.setTexture(*texture);
	player.setTextureRect(IntRect(395, 15, 152, 45));
	player.setPosition(
		(float)window->getSize().x/2-player.getGlobalBounds().width/2, 
		(float)window->getSize().y-50
	);
	player.setScale(0.5f, 0.5f);

	electic.setTexture(*texture);
	electic.setTextureRect(IntRect(spritesElectric[0], 15, 92, 12));
	electic.setPosition(player.getPosition().x+15, player.getPosition().y);
	electic.setScale(0.5f, 0.5f);

	canDoInput = true;

}

Player::~Player()
{
}

void Player::PorcessEvent(Event event)
{
	if (canDoInput)
	{
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			move = speed;
			directX = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			move = speed;
			directX = -1;
		}
	}
	canDoInput = true;
	if (!*start)
	{
		move = 0;
	}

}

void Player::Update(Time time)
{
	player.setPosition(player.getPosition().x + (directX)*(move*time.asMicroseconds()), player.getPosition().y);
	move -= 0.00000005f;
	if (move <= 0)
	{
		move = 0;
	}
	
	CheckBorder();
	Animation();
}

void Player::Render()
{
	window->draw(player);
	window->draw(electic);
}

void Player::CheckBorder()
{
	if (player.getPosition().x <= 0)
	{
		move = speed;
		directX = 3;
		canDoInput = false;
	}
	if (player.getPosition().x + player.getGlobalBounds().width >= window->getSize().x)
	{
		move = speed;
		directX = -3;
		canDoInput = false;
	}
}

void Player::Animation()
{
	animationTime = clock.getElapsedTime();
	if (animationTime.asSeconds() > 0.1)
	{
		spritesCounter++;
		if (spritesCounter >= sizeof(spritesElectric) / sizeof(spritesElectric[0]))
		{
			spritesCounter = 0;
		}
		electic.setTextureRect(IntRect(spritesElectric[spritesCounter], 15, 92, 12));
		animationTime = clock.restart();
	}
	electic.setPosition(player.getPosition().x + 15, player.getPosition().y);
}

Vector2f Player::getPlayerPosition()
{
	return player.getPosition();
}

FloatRect Player::getPlayerGetGlobalBounds()
{
	return player.getGlobalBounds();
}

