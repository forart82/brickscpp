#include "Unity.h"

Unity::Unity(
	RenderWindow *gameWindow, 
	bool gameCreate,
	Texture *gameTexture
)
{
	window = gameWindow;
	create = gameCreate;
	texture = gameTexture;

	speed = 0.00001f;

	width = 175;
	height = 60;
	elementsWidth = (int)window->getSize().x / 10;
	elementsHeight = (int)window->getSize().y / 10;
}

Unity::~Unity() 
{
	for (auto it : enemys)
	{
		delete it;
	}
	enemys.clear();
}

void Unity::ProcessEvents()
{

}

void Unity::Update(Time time)
{

	CreateBricks();
	CheckBorder();
	//sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + (speed*time.asMicroseconds()));
	for (auto it : enemys)
	{
		it->Update(time);
	}

}

void Unity::Render()
{

		for (auto it : enemys)
		{
			it->Render();
		}
		window->draw(sprite);


}

void Unity::CheckBorder()
{
	if (sprite.getPosition().y >= window->getSize().y)
	{
		// TODO game lost!
	}
}

void Unity::CreateBricks()
{
	if (create)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				unity = new Unity(window, false, texture);
				unity->CreateBrick();
				unity->sprite.setPosition(
					SetPositionX(elementsWidth, j),
					SetPositionY(elementsHeight / 2, i)
				);
				enemys.push_back(unity);

			}
		}
	}
	create = false;

}

void Unity::CreateBrick()
{
	sprite.setTexture(*texture);
	sprite.setTextureRect(IntRect(18, 14, 175, 60));
	sprite.setPosition(0, 0);
	sprite.setScale((float)elementsWidth/width, 0.5);
}

float Unity::SetPositionX(int eWidth,int element)
{
	return (float)eWidth * element;
}

float Unity::SetPositionY(int eHeight, int element)
{
	return (float)eHeight * element;
}

