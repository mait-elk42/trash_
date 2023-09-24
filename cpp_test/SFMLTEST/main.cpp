#include "includes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(250, 500), "SFML works!");
    GameObject* player = new GameObject(sf::CircleShape(10.f),125,250,7);
    //clrterm;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::A)
                {
                    prt("<");
                    player->move(-1,0);
                }
                //else
                if(event.key.code == sf::Keyboard::D)
                {
                    prt(">");
                    player->move(1,0);
                }
                //else
                if(event.key.code == sf::Keyboard::W)
                {
                    prt("^");
                    player->move(0,-1);
                }
                //else
                if(event.key.code == sf::Keyboard::S)
                {
                    prt("v");
                    player->move(0,1);
                }
            }
        }

        window.clear();
        window.draw(player->getobj());
        window.display();
    }

    return 0;
}