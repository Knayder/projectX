#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <array>

#include "GuiEvents.hpp"
#include "RelativeGuiObject.hpp"

namespace px {
    
    class GuiContainer;

    class Widget :public sf::Drawable, public RelativeGuiObject
    {
	protected:
		using Callback_t = std::function<void(Widget*)>;
    public:
        Widget();
        virtual ~Widget(){}

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

        void handleInput(const sf::Event& event);

        void bindCallback(GuiEvent event, Callback_t callback);

    protected:
        std::array<Callback_t, GuiEvent::COUNT> callbacks;
		void invokeEvent(GuiEvent eventKey);
    
    private:
        virtual bool isMouseOver(sf::Vector2f mousePosition) { return false; }

        bool mouseOver;
    };

}