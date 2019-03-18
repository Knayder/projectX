#pragma once

#include "Widget.hpp"

namespace px {

    class Label :public Widget
    {
    public:
        Label(){}
        virtual ~Label(){}

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
        sf::Text text;
    };

}