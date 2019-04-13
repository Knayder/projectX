#pragma once

#include "../Widget.hpp"

namespace px {

    class Image : public Widget
    {
    public:
        Image(){}
        virtual ~Image(){}

        void setTexture(const sf::Texture& texture);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    private:
        bool isMouseOver(sf::Vector2f mousePosition) override;

        sf::Sprite sprite;
    };

}