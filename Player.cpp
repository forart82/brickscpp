#include "Player.h"

Player::Player(
	RenderWindow *gameWindow,
	Texture *gameTexture
	)
{
	window = gameWindow;
	texture = gameTexture;
	player.setTexture(*texture);
	player.setTextureRect(IntRect(395, 15, 152, 45));
	player.setPosition(
		window->getSize().x/2-player.getGlobalBounds().width/2, 
		window->getSize().y-50
	);
	player.setScale(0.5, 0.5);

	electic.setTexture(*texture);
	electic.setTextureRect(IntRect(spritesElectric[0], 15, 92, 12));
	electic.setPosition(player.getPosition().x+15, player.getPosition().y);
	electic.setScale(0.5, 0.5);

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
			direction = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			move = speed;
			direction = -1;
		}
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			move = 0;
		}
	}

	// Both option are good. ist just a style qustion.
	//if (event.type == Event::KeyReleased)
	//{
	//	canDoInput = true;
	//}
	canDoInput = true;

}

void Player::Update(Time time)
{
	player.setPosition(player.getPosition().x + (direction)*(move*time.asMicroseconds()), player.getPosition().y);
	move -= 0.00000005;
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
		direction = 3;
		canDoInput = false;
	}
	if (player.getPosition().x + player.getGlobalBounds().width >= window->getSize().x)
	{
		move = speed;
		direction = -3;
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

