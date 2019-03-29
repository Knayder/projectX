#include "GuiContainer.hpp"
#include <exception>

#include "projectX/utility/TupleForEach.hpp"

namespace px {

    GuiContainer::GuiContainer(sf::Vector2f size, sf::Vector2f position)
    :size(size){
            this->setPosition(position);
    }

    void GuiContainer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        //forEach for tuple from utility doesn't work here
        for(auto& widget : std::get<Child_t<Widget>>(childrenHolder)){
            target.draw(*widget.second);
        }

        for(auto& container : std::get<Child_t<GuiContainer>>(childrenHolder)){
            target.draw(*container.second);
        }
    }

    sf::Vector2f GuiContainer::getSize() const {
        return size;
    }

    void GuiContainer::handleInput(const sf::Event& event) {
        forEach(childrenHolder, [this, event](auto& children) {
            for(auto& child : children){
                child.second->handleInput(event);
            }
        });
    }

    void GuiContainer::setRelativeSize(sf::Vector2f size){
        if(parent == nullptr)
            throw std::runtime_error("Trying to access container parent which is nullptr!");

        size.x *= parent->getSize().x;
        size.y *= parent->getSize().y;

        this->size = size;
    }

}