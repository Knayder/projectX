#pragma once

#include "Widget.hpp"
#include <memory>
#include <map>

namespace px {

    class Container :public sf::Drawable, public sf::Transformable
    {
    public:
        Container(sf::Vector2f size=sf::Vector2f(0.0f, 0.0f), sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void handleInput(const sf::Event& event);

        void addWidget(size_t hash, std::unique_ptr<Widget> widget);

        Widget& getWidget(size_t hash) const;

        sf::Vector2f getSize() const;

    private:
        sf::Vector2f size;
        std::map<size_t, std::unique_ptr<Widget>> widgets;
    };

}