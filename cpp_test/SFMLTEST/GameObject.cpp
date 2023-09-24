
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