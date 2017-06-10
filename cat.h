#include "map.h"
#include"view.h"
#include <windows.h>
#include <iostream>
#include"menu.h"

using namespace sf;

class Cat {
private: float x, y;
public:
	float w, h, dx, dy, ia, ja,iia,jja;
	int dir, count, countramen, iexit, jexit, k, kol, levelg;
	bool endf;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Cat(String F, float W, float H, int level) {
		endf = false;
		dx = 0;dy = 0;iia = -1;jja = -1;ia = -1; ja = -1;dir = 0;count = 0; countramen = 0; k = 0, kol = 0;levelg = level;
		File = F;
		w = W; h = H;
		image.loadFromFile(File);
		image.createMaskFromColor(Color(255, 255, 255));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = 32 * 2;y = HEIGHT_MAP*32- 32 * 4;
		sprite.setTextureRect(IntRect(0, 96, w, h));
		
		update();
	}

	void update()
	{

		x += dx;
		y += dy;

		if ((dx == 0) && (dy == 0)) sprite.setTextureRect(IntRect(0, 96, w, h));
		sprite.setPosition(x, y);
		interactionWithMap();
		Sleep(10);
		dx = 0;dy = 0;
	}

	float getplayercoordinateX() {
		return x;
	}

	float getplayercoordinateY() {
		return y;
	}

	void control()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			for (int i = 0;i < 32;i++)
			{
				if (k == 3)k = 0;
				sprite.setTextureRect(IntRect(32 * k, 32, 32, 32));
				k++;
				dx = -1;dy = 0;
				update();
				getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			for (int i = 0;i<32;i++)
			{
				if (k == 3)k = 0;
				sprite.setTextureRect(IntRect(32 * k, 64, 32, 32));
				k++;
				dx = 1;dy = 0;
				update();
				getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			for (int i = 0;i<32;i++)
			{
				if (k == 3)k = 0;
				sprite.setTextureRect(IntRect(32 * k, 96, 32, 32));
				k++;
				dx = 0;dy = -1;
				update();
				getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());

			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			for (int i = 0;i<32;i++)
			{
				if (k == 3)k = 0;
				sprite.setTextureRect(IntRect(32 * k, 0, 32, 32));
				k++;
				dx = 0;dy = 1;
				update();
				getplayercoordinateforview(getplayercoordinateX(), getplayercoordinateY());
			}
		}
	}

	void paintmap(Sprite map_sprite, RenderWindow & window) {
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{

				if (TileMap[i][j] == ' ')  map_sprite.setTextureRect(IntRect(128, 0, 32, 32));
				else
					if (TileMap[i][j] == 'e')
					{
						iexit = i; jexit = j;
						map_sprite.setTextureRect(IntRect(64, 0, 32, 32));

					}
					else
						if ((TileMap[i][j] == 'f'))
						{
							map_sprite.setTextureRect(IntRect(96, 0, 32, 32));
							if (kol == 0) countramen++;
						}
						else
							if ((TileMap[i][j] == '0')) map_sprite.setTextureRect(IntRect(160, 0, 32, 32));
							else
								if (TileMap[i][j] == 'q')  map_sprite.setTextureRect(IntRect(160, 32, 32, 32));
								else
									if (TileMap[i][j] == 's') map_sprite.setTextureRect(IntRect(32, 64, 32, 32));
									else
										if (TileMap[i][j] == 'a') map_sprite.setTextureRect(IntRect(0, 64, 32, 32));
										else
											if (TileMap[i][j] == 'p') {
												sprite.setTextureRect(IntRect(0, 96, w, h)); x = j * 32;y = i * 32; update();
											}


				map_sprite.setPosition(j * 32, i * 32);
				window.draw(map_sprite);
			}

		kol++;
		Texture endt;
		endt.loadFromFile("end.png");
		Sprite end(endt);
		if (endf != false) {
			audiogame.stop();
			audioend.play();
			audioend.setLoop(true);
			window.clear(Color(129, 181, 221));
			View view;
			view.reset(sf::FloatRect(0, 0, 288, 352));
			window.setView(view);
			window.draw(end); window.display(); while (true) { if (Keyboard::isKeyPressed(Keyboard::Return)) exit(0); }

		}
	}

	void interactionWithMap()
	{
		
		int ii = (y + 2) / 32;
		int jj = (x + 2) / 32;

		

		if ((ja != -1) && ((abs(ja - jj) > 1) || (abs(ia - ii) > 1) || ((abs(ja - jj) == 1) && (abs(ia - ii) == 1)))) {
			if ((jja != -1) && ((jja != jj) || (iia != ii)) && ((jja != ja) || (iia != ia))) {
				TileMap[iia][jja] = 'a', iia = ia;jja = ja;
			}
			TileMap[ia][ja] = 'a'; ia = -1;ja = -1;

			
		}
		for (int i = y / 32; i < (y + h) / 32; i++)
			for (int j = x / 32; j < (x + w) / 32; j++)

			{
				if ((TileMap[i][j] == '0') || (TileMap[i][j] == 'a'))
				{
					if (dy > 0)
					{
						y = i * 32 - h;
					}
					if (dy < 0)
					{
						y = i * 32 + 32;
					}

					if (dx > 0)
					{
						x = j * 32 - w;
					}
					if (dx < 0)
					{
						x = j * 32 + 32;
					}

				}
			}
		if (TileMap[ii][jj] == 'f') {
			
			count++;
			TileMap[ii][jj] = ' ';
			ramen.play();
		}
		if (TileMap[ii][jj] == 's') 
		{
			if ((ia != -1)&&((iia!=ia)||(jja!=ja))&&((ia!=ii)||(ja!=jj))) 
			{
				iia = ia;jja = ja;
			}
			ia = ii;ja = jj;
		}
		if (TileMap[ii][jj] == 'p') TileMap[ii][jj] = ' ';
		if ((countramen != 0) && (count == countramen)) TileMap[iexit][jexit] = 'q';

		if (TileMap[ii][jj] == 'q') {
			if (levelg == 6) endf=true;
			else
			{
				levelchoice(++levelg);
				endf = false;
				//view.setCenter(144, 176 + (HEIGHT_MAP-11) * 32);
				x = 32 * 3;y = HEIGHT_MAP * 32 - 32 * 3;
				dx = 0;dy = 0;iia = -1;jja = -1;ia = -1; ja = -1;dir = 0;count = 0; countramen = 0; k = 0, kol = 0;
				update();
			}
		}
	}

};