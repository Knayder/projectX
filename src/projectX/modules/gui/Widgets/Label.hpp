#pragma once

#include "../Widget.hpp"

namespace px {

    class Label :public Widget
    {
    public:
        using Text_t = sf::Text;

        Label();
        virtual ~Label(){}

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void setFont(const sf::Font& font);

        void setString(const std::string& string);

        void setCharacterSize(unsigned int size);

        void setColor(const sf::Color& color);

        void setStyle(sf::Uint32 style);

        const Text_t& getText() const;
    protected:
        
        Text_t text;
    private:
        bool isMouseOver(sf::Vector2f mousePosition) override;
        void updateOrigin();
    };

}