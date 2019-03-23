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
        this->resizeBackground(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height));
    }

    void Button::setBackgroundPadding(sf::Vector2f padding){
        sf::Vector2f newSize;

        newSize.x = text.getLocalBounds().width + (2.0f * padding.x);
        newSize.y = text.getLocalBounds().height + (2.0f * padding.y);
        this->resizeBackground(newSize);

        background.move(-padding/2.0f);
    } 

    void Button::resizeBackground(sf::Vector2f size){
        background.setScale(size.x / background.getLocalBounds().width, 
                            size.y / background.getLocalBounds().height);
    }

}