#include "Label.hpp"

namespace px {

    Label::Label(){
    }

    void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(text, this->getTransform());
    }

    void Label::updateOrigin(){
        sf::Vector2f newOrigin;
        newOrigin.x = text.getLocalBounds().width * 0.5f;
        newOrigin.y = text.getLocalBounds().height * 0.5f;

        this->setOrigin(newOrigin);
    }

    bool Label::isMouseOver(sf::Vector2f mousePosition){
        sf::FloatRect labelRect = text.getGlobalBounds();

        labelRect.top = this->getPosition().y - text.getLocalBounds().height * 0.5f;
        labelRect.left = this->getPosition().x - text.getLocalBounds().width * 0.5f;

        return labelRect.contains(mousePosition);
    }

}