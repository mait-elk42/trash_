#include<SFML/Graphics.hpp>
#include<iostream>
#include "src/GameObject.cpp"
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
int checkcollition(T &obj1,T2 &obj2,T2 &obj3,moves plrmoves)
{
    int r = 0;
    Vector2 obj1pos = {obj1->getPosition().x, obj1->getPosition().y};
    Vector2 originpos = obj1pos;
    Vector2 newpos = {obj1pos.x + plrmoves.right + plrmoves.left, obj1pos.y + plrmoves.up + plrmoves.down};

    obj1->setPosition({newpos.x,newpos.y});
    r = obj1->getGlobalBounds().intersects(obj2->getGlobalBounds()) || obj1->getGlobalBounds().intersects(obj3->getGlobalBounds());
    if(r)
        obj1->setPosition({originpos.x,originpos.y});
    if(!r)
        obj1->setPosition(obj1->getPosition().x + plrmoves.right + plrmoves.left, obj1->getPosition().y + plrmoves.up + plrmoves.down);
    return r;
}
int main()
{
    moves plrmoves = {0,0};
    sf::RenderWindow window(sf::VideoMode(700, 400), "SFML works!");
    window.setIcon(10,10,new sf::Uint8());
    sf::CircleShape *player = new sf::CircleShape(20);
    sf::RectangleShape *square = new sf::RectangleShape(sf::Vector2f(100,100));
    square->setPosition(200,100);
    sf::RectangleShape *square2 = new sf::RectangleShape(sf::Vector2f(100,100));
    square2->setPosition(400,200);
    player->setFillColor(sf::Color::Green);
    player->setPosition(window.getSize().x / 2 ,window.getSize().y / 2);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized)
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
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
        int cd  = checkcollition(player,square,square2,plrmoves);
        // Vector2 originpos = {player->getPosition().x, player->getPosition().y};
        // Vector2 newpos = {player->getPosition().x + plrmoves.right + plrmoves.left, player->getPosition().y + plrmoves.up + plrmoves.down};
        // // you stopped here
        // int cd  = checkcollition(*player,*square,plrmoves);
        // if(cd)
        //     player->setPosition({originpos.x,originpos.y});
        // if(!cd && !cd2)
        //     player->setPosition(player->getPosition().x + plrmoves.right + plrmoves.left, player->getPosition().y + plrmoves.up + plrmoves.down);
        window.clear();
        window.draw(*player);
        window.draw(*square);
        window.draw(*square2);
        sf::VertexArray lines = sf::VertexArray(sf::PrimitiveType::Lines, 2);
        lines[0].position = sf::Vector2f(100, 100);
        lines[1].position = sf::Vector2f(500, 500);
        window.draw(lines);
        window.display();
    }
    return 0;
}