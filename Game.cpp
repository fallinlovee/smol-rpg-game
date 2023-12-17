#include "Game.h"

//str

//initi

//

void Game::initWindow()
{
       std::ifstream ifs("Config/window.ini");

       std::string title= "None";
       sf::VideoMode window_bounds(800, 600);
       unsigned framerate_limit = 120;
       bool vertical_sync_enaled = false;



       if (ifs.is_open())
       {
           std::getline(ifs, title);
           ifs >> window_bounds.width >> window_bounds.height;
           ifs >> framerate_limit;
           ifs >> vertical_sync_enaled;

       }
       
       ifs.close();

	   this->window = new sf::RenderWindow(window_bounds, title);
       this->window->setFramerateLimit(framerate_limit);
       this->window->setVerticalSyncEnabled(vertical_sync_enaled);
}

void Game::initKeys()
{
    this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
    this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
    this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
    this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
    this->supportedKeys.emplace("S", sf::Keyboard::Key::S);


}

void Game::initStates()
{
    this->states.push(new GameState(this->window, &this->supportedKeys));
}



Game::Game()
{

    this->initWindow();
    this->initKeys();
    this->initStates();

}

Game::~Game()
{
    delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}


//func

void Game::endApplication()
{
    std::cout << "ending app" << "\n";
}

void Game::uadateDt()
{

    /*updates th dt variable with takes update*/

    this->dt = this->dtClock.restart().asSeconds();
    system("cls");
    std::cout << this->dt << "\n";

}

void Game::updateSFMLEvents()
{
    sf::Event event;
    while (this->window->pollEvent(this->sfEvent))
    {
     if (this->sfEvent.type == sf::Event::Closed)
         this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);
        if (this->states.top()->getQuit())
        {
            //some aa
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //app end
    else
    {
        this->endApplication();
        this->window->close();
    }
 
}

void Game::render()
{

    this->window->clear();

    //render item
    if (!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
    

}

void Game::run()
{

    while (this->window->isOpen())
    {
        this->uadateDt();
        this->update();
        this->render();
    }
}

