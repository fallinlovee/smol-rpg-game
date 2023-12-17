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

Game::Game()
{
    this->initWindow();

}

Game::~Game()
{
	delete this->window;
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

}

void Game::render()
{

    this->window->clear();

    //render item

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

