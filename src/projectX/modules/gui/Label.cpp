#include "Label.hpp"

namespace px {

    Label::Label(){
    }

    void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(text, this->getTransform());
    }

    void Label::updateOrigin(){
        sf::Vector2f newOrigin;
        newOrigin.x = text.getLocalBounds().width/2.0f;
        newOrigin.y = text.getLocalBounds().height/2.0f;

        this->setOrigin(newOrigin);
    }

}