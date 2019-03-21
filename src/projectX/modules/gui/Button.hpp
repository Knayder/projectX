#pragma once

#include "Label.hpp"

namespace px {

    class Button :public Label
    {
    public:
        Button(){}
        virtual ~Button(){}
        
        void setBackgroundImage(const sf::Texture& backgroundImage);

        //TODO: implement setBackgroundPadding method
        void setBackgroundPadding(sf::Vector2f padding);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        inline sf::Sprite& getBackgroundImage() { return background; }

    private:
        bool isMouseOver(sf::Vector2f mousePosition) override;

        void setUpBackgroundScale();

        sf::Sprite background;
    };

}