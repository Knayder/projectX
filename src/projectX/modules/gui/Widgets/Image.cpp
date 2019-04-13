#include "Image.hpp"

namespace px {

    void Image::setTexture(const sf::Texture& texture) {
        sprite.setTexture(texture);

        sf::Vector2f newOrigin;

        newOrigin.x = sprite.getLocalBounds().width * 0.5f;
        newOrigin.y = sprite.getLocalBounds().height * 0.5f;

        this->setOrigin(newOrigin);
    }

    void Image::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(sprite, this->getTransform());
    }

    bool Image::isMouseOver(sf::Vector2f mousePosition) {
        sf::FloatRect rect = sprite.getGlobalBounds();
        rect.top = this->getPosition().y - sprite.getLocalBounds().height * 0.5f;
        rect.left = this->getPosition().x - sprite.getLocalBounds().width * 0.5f;;

        return rect.contains(mousePosition);
    }

}