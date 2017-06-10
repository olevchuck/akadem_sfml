#include <SFML/Audio.hpp>
sf::SoundBuffer ramenbuffer;
sf::Sound ramen;
sf::Music audiomenu;
sf::Music audiogame;
sf::Music audioend;

void setaudiofiles()
{
	ramenbuffer.loadFromFile("ramen.wav");
	ramen.setBuffer(ramenbuffer);
	ramen.setVolume(25);
	audiomenu.openFromFile("menu.wav");
	audiomenu.setVolume(10);
	audiogame.openFromFile("game.wav");
	audiogame.setVolume(10);
	audioend.openFromFile("end.wav");
	audioend.setVolume(100);
}