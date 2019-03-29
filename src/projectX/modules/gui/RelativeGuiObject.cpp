#include "RelativeGuiObject.hpp"
#include "GuiContainer.hpp"

#include <exception>

namespace px {
    void RelativeGuiObject::setParent(GuiContainer* parent){
        this->parent = parent;
    }

    void RelativeGuiObject::addRelativeOffset(sf::Vector2f offset){
        if(parent == nullptr)
            throw std::runtime_error("Trying to access widget parent which is nullptr!");
        
        offset.x *= parent->getSize().x;
        offset.y *= parent->getSize().y;
        this->move(offset);
    }

    void RelativeGuiObject::setRelativePosition(sf::Vector2f position){
        if(parent == nullptr)
            throw std::runtime_error("Trying to access widget parent which is nullptr!");
        
        position.x *= parent->getSize().x;
        position.y *= parent->getSize().y;
        this->setPosition(position);
    }
}