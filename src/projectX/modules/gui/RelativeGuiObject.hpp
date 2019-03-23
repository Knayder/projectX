#pragma once

#include <SFML/Graphics.hpp>

namespace px {

    class Container;

    class RelativeGuiObject : public sf::Transformable
    {
    public:
        RelativeGuiObject():parent(nullptr){}
        virtual ~RelativeGuiObject(){}

        void setParent(Container* parent);

        void addRelativeOffset(sf::Vector2f offset);

        void setRelativePosition(sf::Vector2f position);
    private:
        Container* parent;
    };

}