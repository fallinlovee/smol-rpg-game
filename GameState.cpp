#include "GameState.h"

GameState::GameState(sf::RenderWindow* window)
	: State(window)
{

}


GameState::~GameState()
{

}


void GameState::endState()
{
	std::cout << "ending gamestate" << "\n";
}

void GameState::updateKeybinds(const float & dt)
{
	this->checkforQuit();
}

void GameState::update(const float& dt)
{
	this->updateKeybinds(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	this->player.render(target);
}
