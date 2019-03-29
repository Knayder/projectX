#pragma once

#include <SFML/Graphics.hpp>

namespace px {

    class GuiContainer;

    class RelativeGuiObject : public sf::Transformable
    {
    public:
        RelativeGuiObject():parent(nullptr){}
        virtual ~RelativeGuiObject(){}

        void setParent(GuiContainer* parent);

        void addRelativeOffset(sf::Vector2f offset);

        void setRelativePosition(sf::Vector2f position);
    protected:
        GuiContainer* parent;
    };

}