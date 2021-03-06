#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "Unity.h"
#include "list"
#include "Player.h"
#include "Ball.h"
#include "Collision.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();

	int Run();

	void ProcessEvent(Event event);
	void Update(Time time);
	void Render();

	void Fps();



private:
	RenderWindow *window;
	Texture *texture;
	Font font;
	Text outerLoop, innerLoop;
	Clock clock, fpsClock, testClock;
	Time tStart, tLap, tTpf, tFps, tTest;
	Event event;

	int fpsCounter, tmpFpsCounter, unityCounter;
	bool *start;

	const float speed = 0.0005f;

	Player *player;
	Unity *unity;
	Ball *ball;
	Collision *collision;

};