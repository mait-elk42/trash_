#include<SFML/Graphics.hpp>
#include<iostream>
#define prt(str) (std::cout<< str <<std::endl)

typedef struct _moves{
    int up;
    int left;
    int down;
    int right;
}moves;
typedef struct _vctr2 {
    float x;
    float y;
}Vector2;
template <typename T,typename T2>
int checkcollition(T *obj1,T2 *obj2)
{
    return  obj1->getGlobalBounds().intersects(obj2->getGlobalBounds());
}
int main()
{
    moves plrmoves = {0,0};
    sf::RenderWindow window(sf::VideoMode(700, 400), "SFML works!");
    sf::CircleShape *player = new sf::CircleShape(20);
    sf::RectangleShape *square = new sf::RectangleShape(sf::Vector2f(100,100));
    player->setFillColor(sf::Color::Green);
    window.setIcon(10,10,new sf::Uint8());
    player->setPosition(window.getSize().x / 2 ,window.getSize().y / 2);
    square->setPosition(200,100);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // else if (event.type == sf::Event::Resized)
            //     window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
            if(event.type == sf::Event::KeyPressed)
                {
                    if(event.key.code == sf::Keyboard::W)
                        plrmoves.up = -1;
                    if(event.key.code == sf::Keyboard::A)
                        plrmoves.left = -1;
                    if(event.key.code == sf::Keyboard::S)
                        plrmoves.down = 1;
                    if(event.key.code == sf::Keyboard::D)
                        plrmoves.right = 1;
                    
                }
            if(event.type == sf::Event::KeyReleased)
                {
                    if(event.key.code == sf::Keyboard::W)
                        plrmoves.up = 0;
                    if(event.key.code == sf::Keyboard::A)
                        plrmoves.left = 0;
                    if(event.key.code == sf::Keyboard::S)
                        plrmoves.down = 0;
                    if(event.key.code == sf::Keyboard::D)
                        plrmoves.right = 0;
                    
                }
        }
        Vector2 originpos = {player->getPosition().x, player->getPosition().y};
        Vector2 newpos = {player->getPosition().x + plrmoves.right + plrmoves.left, player->getPosition().y + plrmoves.up + plrmoves.down};

        // you stopped here
        player->setPosition({newpos.x,newpos.y});
        int cd  = checkcollition(player,square);
        if(cd)
            player->setPosition({originpos.x,originpos.y});
        if(!cd)
            player->setPosition(player->getPosition().x + plrmoves.right + plrmoves.left, player->getPosition().y + plrmoves.up + plrmoves.down);
        window.clear();
        window.draw(*player);
        window.draw(*square);
        window.display();
    }

    return 0;
}