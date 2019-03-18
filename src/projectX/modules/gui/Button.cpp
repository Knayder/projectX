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
        sf::FloatRect buttonRect;

        if(background.getTexture() != nullptr)
            buttonRect = background.getGlobalBounds();
    
        else buttonRect = text.getGlobalBounds();

        buttonRect.top = this->getPosition().y;
        buttonRect.left = this->getPosition().x;

        return buttonRect.contains(mousePosition);
    }

}