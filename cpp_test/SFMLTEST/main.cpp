#include "include/includes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(250, 500), "SFML works!");
    GameObject* player = new GameObject(sf::CircleShape(10.f),125,250,1);
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
                //std::cout << "key pressed" << event.key.code << std::endl;
                player->keypressed(event.key);
                // if(event.key.code == sf::Keyboard::A)
                // {
                //     prt("<");
                //     player->move(-1,0);
                // }
                // //else
                // if(event.key.code == sf::Keyboard::D)
                // {
                //     prt(">");
                //     player->move(1,0);
                // }
                // //else
                // if(event.key.code == sf::Keyboard::W)
                // {
                //     prt("^");
                //     player->move(0,-1);
                // }
                // //else
                // if(event.key.code == sf::Keyboard::S)
                // {
                //     prt("v");
                //     player->move(0,1);
                // }
            }
            else
            if (event.type == sf::Event::KeyReleased)
            {
                //std::cout << "key released" << event.key.code << std::endl;
                player->keyreleased(event.key);
            }

            // if(player->down)
            //     prt("v");
            //     //player->move(0,1);
            // if(player->up)
            //     prt("^");
            //     //player->move(0,-1);
            // if(player->left)
            //     prt("<");
            //     //player->move(-1,0);
            // if(player->right)
            //     prt(">");
            //     //player->move(1,0);
        }
        if(player->down)
                player->move(0,1);
            if(player->up)
                player->move(0,-1);
            if(player->left)
                player->move(-1,0);
            if(player->right)
                player->move(1,0);
        //std::cout << " LEFT: " << player->left  << " UP: " << player->up  << " RIGHT: " << player->right  << " DOWN: " << player->down << std::endl;
        window.clear();
        window.draw(player->getobj());
        window.display();
    }

    return 0;
}