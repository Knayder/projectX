#pragma once

#include "Widget.hpp"

namespace px {

    class Label :public Widget
    {
    public:
        Label();
        virtual ~Label(){}

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
        void updateOrigin() override;

        sf::Text text;
    private:
        bool isMouseOver(sf::Vector2f mousePosition) override;
    };

}