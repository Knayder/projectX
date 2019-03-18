#pragma once

#include "Label.hpp"

namespace px {

    class Button :public Label
    {
    public:
        Button(){}
        virtual ~Button(){}
        
        void setBackgroundImage(const sf::Texture& backgroundImage, sf::Vector2f offset=sf::Vector2f(5.0f, 5.0f));

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        bool isMouseOver(sf::Vector2f mousePosition) override;
        sf::Sprite background;
    };

}