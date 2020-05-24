#include "Game.h"

Game::Game()
{
	window = new RenderWindow();
	window->create(sf::VideoMode(1500, 500), "SFML works!");
	texture = new Texture();
	
	if (!texture->loadFromFile("gamesprite.png"))
	{
		texture->create(200, 200);
	}

	player = new Player(window,texture);
	unity = new Unity(window, true, texture);
	ball = new Ball(window, texture, player);

	font.loadFromFile("arial.ttf");

	tStart = Time::Zero;
	tLap = clock.restart();
	tTpf = seconds(1.f/ 60);
	tFps = fpsClock.restart();
	tTest = clock.restart();

	fpsCounter = 0;
	unityCounter = 0;

	// For tests
	outerLoop.setFont(font);
	outerLoop.setFillColor(Color::Red);
	outerLoop.setCharacterSize(20);
	innerLoop.setFont(font);
	innerLoop.setFillColor(Color::Red);
	innerLoop.setCharacterSize(20);
	innerLoop.setPosition(0, 200);
}

Game::~Game()
{
	delete window;
	delete texture;
	delete player;
	delete unity;
	delete ball;
}

int Game::Run()
{
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			ProcessEvent(event);
		}
		// Execute update in time steps
		tLap = clock.restart();
		while (tLap > tTpf)
		{
			tLap -= tTpf;
			Update(tTpf);
		}
		Update(tLap);
		Render();
	}
	return 0;
}

void Game::ProcessEvent(Event event)
{
	player->PorcessEvent(event);
}

void Game::Update(Time time)
{
	tTest = testClock.getElapsedTime();
	if (tTest.asSeconds()> 3)
	{
		Fps();
		player->Update(time);
		unity->Update(time);
		ball->Update(time);
	}

}

void Game::Render()
{
	window->clear();
	player->Render();
	unity->Render();
	ball->Render();
	window->draw(outerLoop);
	window->draw(innerLoop);
	window->display();
}

void Game::Fps()
{
	//if enought time update
	fpsCounter++;
	tFps = fpsClock.getElapsedTime();
	// Reste timelap to 0 after 1 seconde
	if (tFps.asSeconds() >= 1)
	{
		tmpFpsCounter = fpsCounter;
		outerLoop.setString("time:" + std::to_string(tLap.asMicroseconds()) + "\nFps:" + std::to_string(tmpFpsCounter));
		tFps = fpsClock.restart();
		fpsCounter = 0;
	}
}