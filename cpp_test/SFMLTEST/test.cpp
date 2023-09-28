#include "head.hpp"

int main()
{    
    GameSession *gamesession = new GameSession(400,700,"GAME!");
    GameObject *player = (new GameObject(new sf::CircleShape(20.0)))
                        ->SetPosition(100,100)
                        ->SetBodyColor(Colors_List::Blue);
    gamesession->RegisterKey(sf::Keyboard::Key::A);
    gamesession->RegisterKey(sf::Keyboard::Key::S);
    gamesession->RegisterKey(sf::Keyboard::Key::D);
    while(gamesession->SessionLives())
    {
        //THE FU**ING INPUT DOES NOT WORK I WILL GIVE UP THIS FU**ING LIB 
        //GOODBYE XD
        // if(gamesession->KeyPressed(sf::Keyboard::Key::A))
        //     std::cout << "AAA" <<std::endl;
        // else
        // if(gamesession->KeyPressed(sf::Keyboard::Key::D))
        //     std::cout << "DDD" <<std::endl;
        if(gamesession->KeyPressed(sf::Keyboard::Key::W))
            std::cout << "W" << std::endl;
        // if(gamesession->KeyPressed(sf::Keyboard::Key::A))
        //     std::cout << "A" << std::endl;
        // if(gamesession->KeyPressed(sf::Keyboard::Key::S))
        //     std::cout << "S" << std::endl;
       
        gamesession->Clear();
        gamesession->Draw(player);
        gamesession->Display();
    }
    return 0;
}