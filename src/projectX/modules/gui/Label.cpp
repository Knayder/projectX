#include "Label.hpp"
#include <exception>

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

    void Label::setString(const std::string& string) {
        if(text.getFont() == nullptr)
            throw std::runtime_error("Can't call Label::setString() when font is not set!");
        
        text.setString(string);
        this->updateOrigin();
    }

    const Label::Text_t& Label::getText() const{
        return text;
    }

    void Label::setFont(const sf::Font& font) {
        text.setFont(font);
    }
    
    void Label::setCharacterSize(unsigned int size) {
        if(text.getFont() == nullptr)
            throw std::runtime_error("Can't call Label::setCharacterSize() when font is not set!");

        text.setCharacterSize(size);
        this->updateOrigin();
    }

    void Label::setColor(const sf::Color& color) {
        text.setFillColor(color);
    }

    void Label::setStyle(sf::Uint32 style) {
        text.setStyle(style);
    }

    bool Label::isMouseOver(sf::Vector2f mousePosition){
        sf::FloatRect labelRect = text.getGlobalBounds();

        labelRect.top = this->getPosition().y - text.getLocalBounds().height * 0.5f;
        labelRect.left = this->getPosition().x - text.getLocalBounds().width * 0.5f;

        return labelRect.contains(mousePosition);
    }

}