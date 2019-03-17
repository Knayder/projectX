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

    void Container::addWidget(size_t id, std::shared_ptr<Widget> widget) {
        widget->setPosition(this->getPosition());
        widgets.insert(std::pair<size_t, std::shared_ptr<Widget>>(id, widget));
    }

    std::shared_ptr<Widget> Container::getWidget(size_t id) const {
        if( widgets.find(id) == widgets.end() )
            throw std::length_error("Invalid widget id!");

        return widgets.at(id);
    }

    sf::Vector2f Container::getSize() const {
        return size;
    }

}