#pragma once

#include "Label.hpp"

namespace px {

    class Button :public Label
    {
    public:
        Button(){}
        virtual ~Button(){}
        
        void setBackgroundImage(const sf::Texture& backgroundImage, 
                                sf::Vector2f offset=sf::Vector2f(0.0f, 0.0f), 
                                sf::Vector2f scale=sf::Vector2f(1.0f, 1.0f));

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        inline sf::Sprite& getBackgroundImage() { return background; }

    private:
        bool isMouseOver(sf::Vector2f mousePosition) override;
        sf::Sprite background;
    };

}