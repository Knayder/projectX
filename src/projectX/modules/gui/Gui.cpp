#include "Gui.hpp"

namespace px {

    void Gui::init(){
        this->layer = &getModule<Renderer>().getLayer(Renderer::Layer::GUI);
        container = Container( sf::Vector2f( this->layer->getSize() ) );
    }

    void Gui::draw(){
        this->layer->draw(container);
    }

    void Gui::input(const sf::Event& event){
        this->container.handleInput(event);
    }

}