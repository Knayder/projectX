#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <map>

#include "GuiEvents.hpp"

namespace px {
    
    class Container;

    class Widget :public sf::Drawable, public sf::Transformable
    {
    public:
        Widget();
        virtual ~Widget(){}
        
        //range of relative offset coordiantes: 0-100 [%] of the parent container size
        void addRelativeOffset(sf::Vector2f offset);

        void setParent(Container* parent);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const=0;

        void handleInput(const sf::Event& event);

        void bindCallback(size_t event, std::function<void(Widget*)> callback);

    protected:
        std::map< size_t, std::function<void(Widget*)> > callbacks;    
    
    private:
        virtual bool isMouseOver(sf::Vector2f mousePosition) { return false; }

        Container* parent;
    };

}