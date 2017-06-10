#include <SFML\Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>

int HEIGHT_MAP=0;//размер карты высота
int WIDTH_MAP=0;//размер карты ширина 
std::string name;
std::vector <std::string>TileMap;

void getmap(std::string name);

void delvect();

void levelchoice(int level) {
	if (level == 1)
	{
		HEIGHT_MAP = 11;
		WIDTH_MAP = 9;
		name = "map1.txt";
	}
	else
		if (level == 2)
		{
			HEIGHT_MAP = 14;
			WIDTH_MAP = 12;
			name = "map2.txt";
		}
		else
			if (level == 3)
			{
				HEIGHT_MAP = 14;
				WIDTH_MAP = 9;
				name = "map3.txt";
			}
			else if (level == 4)
			{
				WIDTH_MAP = 14;
				HEIGHT_MAP = 11;
				name = "map4.txt";
			}
			else
				if(level==5)
				{
					WIDTH_MAP = 15;
					HEIGHT_MAP = 15;
					name = "map5.txt";
				}
				else
					if (level == 6)
					{
						WIDTH_MAP = 15;
						HEIGHT_MAP = 15;
						name = "map6.txt";
					}
	getmap(name);
}

void getmap(std::string name)
{
	if(!TileMap.empty())
		delvect();

	std::ifstream file(name);

	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty())
			TileMap.push_back(line);
	}
}

void delvect() {
	while(!TileMap.empty())
		TileMap.pop_back();
}