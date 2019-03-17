#include "Widget.hpp"
#include "Container.hpp"

namespace px {

    void Widget::addRelativeOffset(sf::Vector2f offset){
        offset = offset/100.0f;
        offset.x *= parent.getSize().x;
        offset.y *= parent.getSize().y;
        this->move(offset);
    }

}