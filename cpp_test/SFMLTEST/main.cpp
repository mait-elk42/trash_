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
            if (event.type == sf::Event::KeyPressed)
                player->keypressed(event.key); 
            if (event.type == sf::Event::KeyReleased)
                player->keyreleased(event.key);
        }
        if(player->down)
                player->move(0,1);
            if(player->up)
                player->move(0,-1);
            if(player->left)
                player->move(-1,0);
            if(player->right)
                player->move(1,0);
        window.clear();
        window.draw(player->getobj());
        window.display();
    }

    return 0;
}