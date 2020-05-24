#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
#include "list"

using namespace std;
using namespace sf;

class Unity {
	public:
		Unity(
			RenderWindow *window, 
			bool create, 
			Texture *gameTexture
		);
		~Unity();

		void ProcessEvents();
		void Update(Time time);
		void Render();

		void CheckBorder();
		void CreateBricks();
		void CreateBrick();
		float SetPositionX(int w,int i);
		float SetPositionY(int h, int i);

	
	private:
		RenderWindow *window;
		Texture *texture;
		Sprite sprite;
		Clock clock;
		Time delay = clock.restart();
		float speed;

		//175x60
		int elementsHeight, elementsWidth, height, width;
		bool create;
		Unity *unity;
		list<Unity*> enemys;
};

