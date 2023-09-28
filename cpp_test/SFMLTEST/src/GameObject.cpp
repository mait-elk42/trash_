typedef sf::Color Colors_List;

class GameObject {
public:
    int _IsColliding = 0;
    sf::Shape *_Shape;
public:
    GameObject(sf::Shape *shape = new sf::CircleShape(20))
    {
        this->_Shape = shape;
    }
    GameObject *SetPosition(float x, float y)
    {
        this->_Shape->setPosition(x,y);
        return this;
    }
    GameObject *SetBodyColor(sf::Color color)
    {
        this->_Shape->setFillColor(color);
        return this;
    }
    sf::Shape *GetShape()
    {
        return _Shape;
    }
};