
struct V2{
    float x;
    float y;
};
class GameObject{
private:
    sf::Vertex collider[8] =
    {
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, 0))
    };
    int collition_down = 0 , collition_up = 0, collition_left = 0, collition_right = 0;
    float speed = 0;
    sf::Shape *shape;
    V2 *position = new V2();
public:
    int up = 0,down = 0,left = 0,right = 0;

    GameObject(sf::Shape *shape,float x,float y,float movementspeed)
    {
        collider[0].color = sf::Color::Green;
        collider[1].color = sf::Color::Green;
        collider[2].color = sf::Color::Green;
        collider[3].color = sf::Color::Green;
        collider[4].color = sf::Color::Green;
        collider[5].color = sf::Color::Green;
        collider[6].color = sf::Color::Green;
        collider[7].color = sf::Color::Green;
    
        this->shape = shape;
        position->x = x;
        position->y = y;
        speed = movementspeed;
        this->shape->setPosition(position->x,position->y);
    }
    sf::Shape *getobj()
    {
        return shape;
    }
    V2 getscale()
    {
        return {shape->getScale().x, shape->getScale().y};
    }
    V2 getPosition()
    {
        return {shape->getPosition().x, shape->getPosition().y};
    }
    // int ObjectIscollited()
    // {
    //     return collited;
    // }
    void printcollider(sf::RenderWindow& window)
    {
        collider[0].position = {getPosition().x, getPosition().y};
        collider[1].position = {getPosition().x+20, getPosition().y};
        collider[2].position = {getPosition().x+20, getPosition().y+20};
        collider[3].position = {getPosition().x+20, getPosition().y};
        collider[4].position = {getPosition().x+20, getPosition().y+20};
        collider[5].position = {getPosition().x, getPosition().y+20};
        collider[6].position = {getPosition().x, getPosition().y+20};
        collider[7].position = {getPosition().x, getPosition().y};

        window.draw(collider, 8, sf::Lines);
    }
    void __ObjectIsColliRecord(GameObject *othergameobject)
    {
        // if(getPosition().y+20 < othergameobject->getPosition().y)
        //     collition_down = 1;
        // else
        //     collition_down = 0;
        // if(getPosition().y > othergameobject->getPosition().y+50) 
        //     collition_up = 1;
        // else
        //     collition_up = 0;
        if(getPosition().x+20 < othergameobject->getPosition().x)
            collition_right = 1;
        else
            collition_left = 0;
        if(getPosition().x > othergameobject->getPosition().x+50)
            collition_left = 1;
        else
            collition_right = 0;
    }
    void keypressed(sf::Event::KeyEvent keyclicked)
    {
        if(keyclicked.code == sf::Keyboard::W)
            up = 1;
        else
        if(keyclicked.code == sf::Keyboard::S)
            down = 1;
        if(keyclicked.code == sf::Keyboard::A)
            left = 1;
        else
        if(keyclicked.code == sf::Keyboard::D)
            right = 1;
    }
    void keyreleased(sf::Event::KeyEvent keyclicked)
    {
       if(keyclicked.code == sf::Keyboard::W)
            up = 0;
        else
        if(keyclicked.code == sf::Keyboard::S)
            down = 0;
        if(keyclicked.code == sf::Keyboard::A)
            left = 0;
        else
        if(keyclicked.code == sf::Keyboard::D)
            right = 0;
    }
    void set_color(sf::Color color)
    {
        shape->setFillColor(color);
    }
    void move(float x,float y)
    {
        // std::cout << " right: "<<collition_right <<  " left: " <<collition_left << std::endl;
        // if(x > 0 && !collition_right)
        //     position->x += x * speed;
        // else
        //     if(x < 0)
        //         position->x += x * speed;
        
        // if(x < 0 && !collition_left)
            //position->x += x * speed;
        position->x += x * speed;
        position->y += y * speed;
        shape->setPosition(position->x,position->y);
    }
};