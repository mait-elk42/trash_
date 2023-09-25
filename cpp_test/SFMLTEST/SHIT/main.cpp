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
        
        V2 playerpos = player->getPosition();
        V2 groundpos = ground->getPosition();
        float playersize = player->getobj()->getLocalBounds().height;
        float groundsize = ground->getobj()->getLocalBounds().height;
        //if((playerpos.x < groundpos.x + groundsize && playerpos.y < groundpos.x+groundsize && playerpos.x+playersize > groundpos.x && playerpos.y+playersize > groundpos.y))
        //  if((playerpos.x + playersize > groundpos.x))
        // {
        //     if(playerpos.y < groundpos.y + groundsize)
        //         if(playerpos.y+playersize > groundpos.y)
        //             prt("coll right");
        //         else
        //         prt("else?");
        //     else
        //         prt("else?");
        //     //std::cout << " player : "<<  playerpos.y + playersize <<  " ground : " <<  (playerpos.y < groundpos.y + groundsize && playerpos.y+playersize > groundpos.y) << std::endl;
        // }
        // else
        // {
        //     prt("no collition");
        // }
        // if(playerpos.y < groundpos.y + groundsize)
        // {
        //         prt("11");
        // }else
        // if(playerpos.y+playersize > groundpos.y)
        // {
        //         prt("22");
        // }else{
        //     prt("noo");
        // }
        player->__ObjectIsColliRecord(ground);
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

        
        player->printcollider(window,1);
        ground->printcollider(window,1);
        window.display();
    }

    return 0;
}