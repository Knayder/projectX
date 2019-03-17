#pragma once

#include "Widget.hpp"
#include <memory>
#include <map>

namespace px {

    class Container :public sf::Drawable, public sf::Transformable
    {
    public:
        Container(sf::Vector2f size, sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void addWidget(size_t id, std::shared_ptr<Widget> widget);

        std::shared_ptr<Widget> getWidget(size_t id) const;

        sf::Vector2f getSize() const;

    private:
        sf::Vector2f size;
        std::map<size_t, std::shared_ptr<Widget>> widgets;
    };

}