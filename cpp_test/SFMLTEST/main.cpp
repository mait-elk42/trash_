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
int checkcollition(Vector2 pos1, Vector2 pos2,float size1, float size2)
{
     if((pos1.x < pos2.x + size2 && pos1.y < pos2.x+size2 && pos1.x+size1 > pos2.x && pos1.y+size1 > pos2.y))
            return 1;
    return 0;
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
    square->setPosition(100,100);
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
        int cd = checkcollition({player->getPosition().x+ plrmoves.right + plrmoves.left, player->getPosition().y+ plrmoves.up + plrmoves.down},{square->getPosition().x, square->getPosition().y},player->getLocalBounds().height,square->getLocalBounds().height);
        //if(!cd)
            //player->setPosition(player->getPosition().x,player->getPosition().y + 0.2f);
        if(!cd)
            player->setPosition(player->getPosition().x + plrmoves.right + plrmoves.left, player->getPosition().y + plrmoves.up + plrmoves.down);
        window.clear();
        window.draw(*player);
        window.draw(*square);
        window.display();
    }

    return 0;
}