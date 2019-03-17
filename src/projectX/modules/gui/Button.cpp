#include "Button.hpp"

namespace px {

    void Button::setBackgroundImage(const sf::Texture& backgroundImage, sf::Vector2f offset){
        background.setTexture(backgroundImage);
        background.setPosition(this->getPosition());
        background.move(-offset);
    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(this->text, this->getTransform());
        target.draw(background);
    }

    bool Button::isMouseOver(sf::Vector2f mousePosition){
        if(background.getTexture() != nullptr)
            return background.getGlobalBounds().contains(mousePosition);

        return text.getGlobalBounds().contains(mousePosition);
    }

}