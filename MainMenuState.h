#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
// !MAINMENUSTATE_H
#include "GameState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    //variabllee

    sf::RectangleShape background;
    sf::Font font;

    Button* gamestate_btn;



    //func
    void initFonts();
    void initKeybinds();
public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();


    //function

    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif 