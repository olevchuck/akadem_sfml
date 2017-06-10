#include <SFML/Graphics.hpp>
#include "audio.h"
#include <iostream>
#include <sstream>
#include "cat.h"
bool startGame()
{
	setaudiofiles();
	sf::RenderWindow window(sf::VideoMode(288, 352), "Test");
	int choice=menu(window);
	view.reset(sf::FloatRect(0, HEIGHT_MAP * 32 - 176 * 2, 288, 352));
	audiogame.play();
	audiogame.setLoop(true);
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 20);
	text.setOutlineColor(Color::Blue);
	Cat cat("cat.png", 32, 32, choice);
	Image map_img;
	map_img.loadFromFile("map.png");
	Texture map;
	map.loadFromImage(map_img);
	Sprite map_sprite;
	map_sprite.setTexture(map);

	int k = 0;
	//window.setFramerateLimit(60);
	Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1500;

		cat.control();

		window.setView(view);
		window.clear(Color(59, 173, 63));

		viewmap(time);

		cat.paintmap(map_sprite, window);
		
		window.draw(cat.sprite);
		std::ostringstream playerScoreString, total;
		playerScoreString << cat.count;
		total << cat.countramen;
		text.setString("Собрано раменов:" + playerScoreString.str()+" из "+total.str());
		text.setPosition(view.getCenter().x - 140, view.getCenter().y - 170);
		window.draw(text);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Tab)) { return true; }
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			return false;
		}
	}
}