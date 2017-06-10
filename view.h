#include <SFML/Graphics.hpp>
using namespace sf;

sf::View view;


void getplayercoordinateforview(float x, float y) {

	float tempX = x; float tempY = y;

	if ((x < 144)||(WIDTH_MAP==9)) tempX = 144;
	if ((y < (HEIGHT_MAP * 32 - 176)) || (HEIGHT_MAP == 11))tempY = 176;
	else
		tempY = 176+(HEIGHT_MAP * 32 - 176 * 2);
	view.setCenter(tempX,tempY);


}
void viewmap(float time) { 
	Vector2f center = view.getCenter();
	float tempX = center.x;
	float tempY = center.y;

	if ((Keyboard::isKeyPressed(Keyboard::D)) && (tempX+144 < WIDTH_MAP*32)) {
		view.move(0.1*time, 0);
	}

	if ((Keyboard::isKeyPressed(Keyboard::S)) && (tempY + 176 < HEIGHT_MAP* 32)) {
		view.move(0, 0.1*time);
	}

	if ((Keyboard::isKeyPressed(Keyboard::A)) && (tempX-144 > 0)) {
		view.move(-0.1*time, 0);
	}
	if ((Keyboard::isKeyPressed(Keyboard::W)) && (tempY - 176 > 0)) {
		view.move(0, -0.1*time);
	}

}
