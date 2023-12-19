#include "MainMenuState.h"


void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/Arial.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}

}

void MainMenuState::initKeybinds()
{


	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())

	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}
	ifs.close();

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();

	this->gamestate_btn = new Button(100, 200, 150, 50, 
		&this->font, "eee game", 
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}


MainMenuState::~MainMenuState()
{
	delete this->gamestate_btn;
}


void MainMenuState::endState()
{
	std::cout << "ending gamestate" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkforQuit();
}

	//pl unpur

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->gamestate_btn->render(target);
}
