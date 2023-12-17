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

	std::map<std::string, int> supportedKeys;

	void initWindow();
	void initKeys();
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
