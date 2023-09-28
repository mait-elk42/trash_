typedef struct _keynode{
    sf::Keyboard::Key keycode;
    int pressed;
    struct _keynode *nextkey;
} key_node;


class GameSession{
public:
    key_node *__keyslist;
    key_node *currentadding;
    int __TherePindingKeys__;
    sf::Event __event__;
    sf::RenderWindow *__window__;
    float __HEIGHT__;
    float __WIDTH__;
    sf::String __NAME__;
public:
    GameSession(float HEIGHT, float WIDTH,const sf::String & NAME)
    {
        this->__HEIGHT__ = HEIGHT;
        this->__WIDTH__ = WIDTH;
        this->__NAME__ = NAME;
        this->__window__ = new sf::RenderWindow(sf::VideoMode(this->__WIDTH__, this->__HEIGHT__), this->__NAME__);
        this->__keyslist = new key_node();
        this->currentadding = __keyslist;
    }
    int SessionLives()
    {
        key_node *tmp_save = __keyslist;
        while(this->__window__->pollEvent(__event__))
        {
            if (this->__event__.type == sf::Event::Closed)
            {
                this->__window__->close();
                break;
            }
            __keyslist = __keyslist->nextkey;
            while(__keyslist)
            {
                if(this->__event__.key.code == sf::Keyboard::Key::A)
                {
                    if(this->__event__.type == this->__event__.KeyPressed)
                        __keyslist->pressed = 1;
                    if(this->__event__.type == this->__event__.KeyReleased)
                        __keyslist->pressed = 0;
                }
                __keyslist = __keyslist->nextkey;
            }
            __keyslist = tmp_save;
        }
        return this->__window__->isOpen();
    }
    int KeyPressed(int key)
    {
        int resutl = 0;
        key_node **_tmpnode = &__keyslist;
        __keyslist = __keyslist->nextkey;
        while(__keyslist)
            {
                if(__keyslist->keycode == key)
                {
                    resutl = __keyslist->pressed;
                    break;
                }
                __keyslist = __keyslist->nextkey;
            }
        std::cout << __keyslist->keycode << std::endl;
        __keyslist = *_tmpnode;
        return resutl;
    }
    int RegisterKey(sf::Keyboard::Key key)
    {
        _keynode *newkey = new key_node();
        newkey->keycode = key;
        newkey->pressed = 0;
        newkey->nextkey = 0;
        currentadding->nextkey = newkey;
        currentadding = currentadding->nextkey;
    }
    void Display()
    {
        __window__->display();
    }
    void Clear()
    {
        __window__->clear();
    }
    void Draw(GameObject *object)
    {
        __window__->draw(*object->GetShape());
    }
    // int TherePendingEvents()
    // {
    //     int r = ;
    //     return r;
    // }
};