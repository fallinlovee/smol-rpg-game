#ifndef STATE_H
#define STATE_H

#include<vector>

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"

class State
{
private:
	std::vector<sf::Texture> texture;


public:
	State();
	virtual ~State();

	virtual void update() = 0;
	virtual void rander() = 0;

};

#endif