#include "Label.hpp"

namespace px {

    void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(text, this->getTransform());
    }

}