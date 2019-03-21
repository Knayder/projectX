#include "Widget.hpp"
#include "Container.hpp"
#include <exception>

namespace px {

    Widget::Widget()
    :mouseOver(false){
		for (auto& callback : callbacks)
		{
			callback = [](Widget*) {};
		}
    }

    void Widget::setParent(Container* parent){
        this->parent = parent;
    }

    void Widget::addRelativeOffset(sf::Vector2f offset){
        if(parent == nullptr)
            throw std::length_error("Trying to access widget parent which is nullptr! (use Container::getWidget)");
        
        offset.x *= parent->getSize().x;
        offset.y *= parent->getSize().y;
        this->move(offset);
    }

    void Widget::bindCallback(GuiEvent eventKey, Callback_t callback) {
		if (eventKey >= GuiEvent::COUNT)
			throw std::length_error("Trying to bind incorrect GuiEvent!");
        callbacks[eventKey] = callback;
    }

    void Widget::handleInput(const sf::Event& event){

        if(event.type == sf::Event::MouseButtonPressed){
            if(mouseOver){

                switch(event.mouseButton.button){
                    case sf::Mouse::Left:
                        invokeEvent(GuiEvent::LEFT_MB_PRESSED);
                    break;
                    case sf::Mouse::Right:
                        invokeEvent(GuiEvent::RIGHT_MB_PRESSED);
                    break;
                    case sf::Mouse::Middle:
                        invokeEvent(GuiEvent::MIDDLE_MB_PRESSED);
                    break;
                }

            }
        }
        
        if( isMouseOver( sf::Vector2f(float(event.mouseMove.x), float(event.mouseMove.y)) ) ) {
            if( mouseOver == false ) 
                invokeEvent(GuiEvent::ON_MOUSE_ENTER);
            mouseOver = true;
        }

        else {
            if( mouseOver == true )
				invokeEvent(GuiEvent::ON_MOUSE_EXIT);
            mouseOver = false;
        }

    }
	void Widget::invokeEvent(GuiEvent eventKey)
	{
		if (eventKey >= GuiEvent::COUNT)
			throw std::length_error("Trying to invoke incorrect GuiEvent!");

		callbacks[eventKey](this);
	}
}