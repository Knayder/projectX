#pragma once

#include "Widget.hpp"
#include <memory>
#include <map>

#include "RelativeGuiObject.hpp"
#include "projectX/utility/TypeTraits.hpp"

namespace px {

    class Container :public sf::Drawable, public RelativeGuiObject
    {
        template <typename ChildType>
        using Child_t = std::map<size_t, std::unique_ptr<ChildType>>;
    protected:
        using ChildrenHolder_t = std::tuple<Child_t<Widget>, Child_t<Container>>;
    public:
        Container(sf::Vector2f size=sf::Vector2f(0.0f, 0.0f), sf::Vector2f position=sf::Vector2f(0.0f, 0.0f));

        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void handleInput(const sf::Event& event);

        template <typename ChildType>
        void addChild(size_t hash, std::unique_ptr<ChildType> child){
            static_assert(tt::tuple_contains_type<Child_t<ChildType>, ChildrenHolder_t>(), "Container can't have this type of child!");

            child->setPosition(this->getPosition());

            std::get<Child_t<ChildType>>(childrenHolder).insert(std::pair<size_t, std::unique_ptr<ChildType>>(hash, std::move(child)));
            std::get<Child_t<ChildType>>(childrenHolder).at(hash)->setParent(this);
        }

        template <typename ChildType>
        ChildType& getChild(size_t hash) const {
            static_assert(tt::tuple_contains_type<Child_t<ChildType>, ChildrenHolder_t>(), "Container doesn't have this type of child!");

            if( std::get<Child_t<ChildType>>(childrenHolder).find(hash) == std::get<Child_t<ChildType>>(childrenHolder).end() )
                throw std::length_error("Invalid child hash!");

            return ( *std::get<Child_t<ChildType>>(childrenHolder).at(hash) );
        }

        sf::Vector2f getSize() const;

        void setRelativeSize(sf::Vector2f size);
    private:
        sf::Vector2f size;
        ChildrenHolder_t childrenHolder;
    };

}