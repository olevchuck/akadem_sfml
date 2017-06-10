
int menu(RenderWindow & window) {
	audiomenu.play();
	audiomenu.setLoop(true);
	Texture fontexture,menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("111.png");
	menuTexture2.loadFromFile("222.png");
	menuTexture3.loadFromFile("333.png");
	fontexture.loadFromFile("fon.png");
	aboutTexture.loadFromFile("about.png");
	menuBackground.loadFromFile("menu.jpg");
	Sprite fon(fontexture),menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	int choice ;
	
	menu1.setPosition(0, 10);
	menu2.setPosition(0, 40);
	menu3.setPosition(0, 70);
	menuBg.setPosition(0, 0);
	while (isMenu)
	{
		menu1.setColor(Color::Cyan);
		menu2.setColor(Color::Cyan);
		menu3.setColor(Color::Cyan);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 10, 285, 25).contains(Mouse::getPosition(window))) { menu1.setColor(Color::White); menuNum = 1; }
		if (IntRect(100, 40, 285, 25).contains(Mouse::getPosition(window))) { menu2.setColor(Color::White); menuNum = 2; }
		if (IntRect(100, 70, 285, 25).contains(Mouse::getPosition(window))) { menu3.setColor(Color::White); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) 
			{ 
				bool ismenu2 = true;
				window.clear(Color(129, 181, 221));
				window.draw(fon);
				choice = 0;
				std::map<int,IntRect> choices;
				choices[1] = IntRect(50, 50, 50, 50);
				choices[2] = IntRect(100, 50, 50, 50);
				choices[3] = IntRect(150, 50, 50, 50);
				choices[4] = IntRect(50, 100, 50, 50);
				choices[5] = IntRect(100, 100, 50, 50);
				choices[6] = IntRect(150, 100, 50, 50);
				window.display();while (ismenu2)
				{
					for (std::map<int, sf::IntRect>::iterator it = choices.begin(); it != choices.end(); ++it)
					{
						if (it->second.contains(Mouse::getPosition(window)))
							choice = it->first;
						printf("%d\n", choice);
					}
				
					if (Mouse::isButtonPressed(Mouse::Right))
					{
						levelchoice(choice);ismenu2 = false;
						isMenu = false; audiomenu.stop();
					}
				}
				
			 }
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { exit(0); isMenu = false;audiomenu.stop();
			}

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	return choice;
}
