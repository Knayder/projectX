#include "Container.hpp"
#include <exception>

namespace px {

    Container::Container(sf::Vector2f size, sf::Vector2f position)
    :size(size){
            this->setPosition(position);
    }

    void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for(const auto& widget : widgets){
            target.draw(*(widget.second));
        }
    }

    void Container::addWidget(size_t hash, std::unique_ptr<Widget> widget) {
        widget->setPosition(this->getPosition());
        widgets.insert(std::pair<size_t, std::unique_ptr<Widget>>(hash, std::move(widget)));
        widgets.at(hash)->setParent(this);
    }

    Widget& Container::getWidget(size_t hash) const {
        if( widgets.find(hash) == widgets.end() )
            throw std::length_error("Invalid widget id!");

        return (*widgets.at(hash));
    }

    sf::Vector2f Container::getSize() const {
        return size;
    }

    void Container::handleInput(const sf::Event& event) {
        for(const auto& widget : widgets){
            widget.second->handleInput(event);
        }
    }

}