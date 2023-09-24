
struct V2{
    float x;
    float y;
};
class GameObject{
private:
    float speed = 0;
    sf::CircleShape shape;
    V2 *position = new V2();
public:
    int up = 0,down = 0,left = 0,right = 0;
    GameObject(sf::CircleShape shape,float x,float y,float movementspeed)
    {
        this->shape = shape;
        position->x = x;
        position->y = y;
        speed = movementspeed;
        this->shape.setPosition(position->x,position->y);
    }
    sf::CircleShape getobj()
    {
        return shape;
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
        shape.setFillColor(color);
    }
    void move(float x,float y)
    {
        position->x += x * speed;
        position->y += y * speed;
        shape.setPosition(position->x,position->y);
    }
};