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

void GameState::updateInput(const float & dt)
{
	this->checkforQuit();


	//pl unpur
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player.move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player.move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player.move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player.move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	this->player.render(target);
}
