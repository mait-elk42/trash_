#include "include/includes.hpp"

int checkcollition()
{
    if((playerpos.x < groundpos.x + groundsize && playerpos.y < groundpos.x+groundsize && playerpos.x+playersize > groundpos.x && playerpos.y+playersize > groundpos.y))
        return 1;
    return 0;
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");    
    sf::CircleShape circle = sf::CircleShape(10);
    float xgo = 2;
    float ygo = 2;
    clrterm;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                0;
        }
        if(circle.getPosition().y+10 > 400)
            ygo = -ygo;
        if(circle.getPosition().y+10 < 0)
            ygo = -ygo;
        if(circle.getPosition().x+10 >  600)
            xgo = -xgo;
        if(circle.getPosition().x+10 < 0)
            xgo = -xgo;
        
        circle.move(xgo,ygo);
        window.draw(circle);
        window.display();
        window.clear();
    }

    return 0;
}