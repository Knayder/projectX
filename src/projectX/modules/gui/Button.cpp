#include "Button.hpp"

namespace px {

    void Button::setBackgroundImage(const sf::Texture& backgroundImage){
        background.setTexture(backgroundImage);
        background.setPosition(this->getPosition());
        setUpBackgroundScale();
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


    void Button::setUpBackgroundScale(){
        sf::Vector2f scale;
        
        //TODO: remove hardcoded padding
        scale.x = text.getLocalBounds().width / static_cast<float>(background.getTextureRect().width) + 0.1f;
        scale.y = text.getLocalBounds().height / static_cast<float>(background.getTextureRect().height) + 0.2f;

        background.setScale(scale);
    }

    void Button::setBackgroundPadding(sf::Vector2f padding){
    }

}