#pragma once

#include <SFML/Graphics.hpp>

namespace px {
    
    class Container;

    class Widget :public sf::Drawable, public sf::Transformable
    {
    public:
        Widget(const Container& parent):parent(parent){}

        //range of relative offset coordiantes: 0-100 [%] of the parent container size
        void addRelativeOffset(sf::Vector2f offset);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;

    private:
        const Container& parent;
    };

}