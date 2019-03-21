#include "Button.hpp"

namespace px {

    void Button::setBackgroundImage(const sf::Texture& backgroundImage, sf::Vector2f offset, sf::Vector2f scale){
        background.setTexture(backgroundImage);
        background.setScale(scale);
        background.setPosition(this->getPosition());
        background.move(-offset);
    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(background, this->getTransform());
        target.draw(this->text, this->getTransform());
    }

    bool Button::isMouseOver(sf::Vector2f mousePosition){
        sf::FloatRect buttonRect;

        if(background.getTexture() != nullptr)
            buttonRect = background.getGlobalBounds();
    
        else buttonRect = text.getGlobalBounds();

        buttonRect.top = this->getPosition().y - text.getLocalBounds().height * 0.5f;
        buttonRect.left = this->getPosition().x - text.getLocalBounds().width * 0.5f;

        return buttonRect.contains(mousePosition);
    }

}