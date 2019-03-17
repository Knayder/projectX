#include "Widget.hpp"
#include "Container.hpp"
#include <exception>

namespace px {

    Widget::Widget(const Container& parent):parent(parent){
        for(size_t i=0; i<GuiEvent::COUNT; ++i)
            callbacks.insert(std::pair<size_t, std::function<void()>>(i, [](){}) );
    }

    void Widget::addRelativeOffset(sf::Vector2f offset){
        offset = offset/100.0f;
        offset.x *= parent.getSize().x;
        offset.y *= parent.getSize().y;
        this->move(offset);
    }

    void Widget::bindCallback(size_t event, std::function<void()> callback) {
        if( callbacks.find(event) == callbacks.end())
            throw std::length_error("Invalid event value!");
        callbacks.at(event) = callback;
    }

    void Widget::handleInput(const sf::Event& event){
        static bool mouseOver = false;

        if(event.type == sf::Event::MouseMoved){

            if( isMouseOver( sf::Vector2f(event.mouseMove.x, event.mouseMove.y) ) ) {
                callbacks.at(GuiEvent::ON_MOUSE_ENTER)();
                mouseOver = true;
            }
            else {
                callbacks.at(GuiEvent::ON_MOUSE_EXIT)();
                mouseOver = false;
            }

        }

        if(event.type == sf::Event::MouseButtonPressed){
            if(mouseOver){

                switch(event.mouseButton.button){
                    case sf::Mouse::Left:
                        callbacks.at(GuiEvent::LEFT_MB_PRESSED)();
                    break;
                    case sf::Mouse::Right:
                        callbacks.at(GuiEvent::RIGHT_MB_PRESSED)();
                    break;
                    case sf::Mouse::Middle:
                        callbacks.at(GuiEvent::MIDDLE_MB_PRESSED)();
                    break;
                }

            }
        }

    }
}