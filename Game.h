#ifndef GAME_H
#define GAME_H

#include "GameState.h"

class Game
{
private:

	
	sf::RenderWindow *window;
	sf::Event sfEvent;
	

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	void initWindow();
	void initStates();

public:
	Game();
	virtual ~Game();

	//function
	// 
	// 
	//regular app}

	void endApplication();
	
	//UPDATE
	void uadateDt();
	void updateSFMLEvents();
	void update();

	//rend
	void render();

	//core
	void run();
};
#endif
