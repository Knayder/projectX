#include "Widget.hpp"
#include "Container.hpp"
#include <exception>

namespace px {

    Widget::Widget(){
        for(size_t i=0; i<GuiEvent::COUNT; ++i)
            callbacks.insert(std::pair<size_t, std::function<void(Widget*)>>(i, [](Widget*){}) );
    }

    void Widget::setParent(Container* parent){
        this->parent = parent;
    }

    void Widget::addRelativeOffset(sf::Vector2f offset){
        if(parent == nullptr)
            throw std::length_error("Trying to access widget parent which is nullptr! (use Container::getWidget)");
        
        offset = offset/100.0f;
        offset.x *= parent->getSize().x;
        offset.y *= parent->getSize().y;
        this->move(offset);
    }

    void Widget::bindCallback(size_t event, std::function<void(Widget*)> callback) {
        if( callbacks.find(event) == callbacks.end())
            throw std::length_error("Invalid event value!");
        callbacks.at(event) = callback;
    }

    void Widget::handleInput(const sf::Event& event){
        static bool mouseOver = false;
        
        if( isMouseOver( sf::Vector2f(event.mouseMove.x, event.mouseMove.y) ) ) {
            if( mouseOver == false )
                callbacks.at(GuiEvent::ON_MOUSE_ENTER)(this);
            mouseOver = true;
        }

        else {
            if( mouseOver == true )
                callbacks.at(GuiEvent::ON_MOUSE_EXIT)(this);
            mouseOver = false;
        }

        if(event.type == sf::Event::MouseButtonPressed){
            if(mouseOver){

                switch(event.mouseButton.button){
                    case sf::Mouse::Left:
                        callbacks.at(GuiEvent::LEFT_MB_PRESSED)(this);
                    break;
                    case sf::Mouse::Right:
                        callbacks.at(GuiEvent::RIGHT_MB_PRESSED)(this);
                    break;
                    case sf::Mouse::Middle:
                        callbacks.at(GuiEvent::MIDDLE_MB_PRESSED)(this);
                    break;
                }

            }
        }

    }
}