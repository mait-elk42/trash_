#include "include/includes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");
    sf::Shape *box = new sf::RectangleShape(sf::Vector2f(50.0f,50.0f));
    sf::Shape *circle = new sf::CircleShape(10.0);
    GameObject* player = new GameObject(circle,200,100,1);
    GameObject* ground = new GameObject(box,200,200,0);

    circle->setFillColor(sf::Color::Red);
    clrterm;
    // sf::CircleShape ciiir = sf::CircleShape(10.0);
    while (window.isOpen())
    {
        //player->__ObjectIsColliRecord(ground);
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
        //
        // prt("player :");
        // prt(player->getobj()->getPosition().x);
        // prt("ground");
        // prt(ground->getobj()->getPosition().x);
        //graviiity
            //player->move(0,0.2f);

        if(player->down)
            player->move(0,1);
        if(player->up)
            player->move(0,-1);                
        if(player->left)
            player->move(-1,0);
        if(player->right)
            player->move(1,0);
        window.clear();
        window.draw(*(ground->getobj()));
        window.draw(*(player->getobj()));

        
        player->printcollider(window);
        ground->printcollider(window);
        window.display();
    }

    return 0;
}