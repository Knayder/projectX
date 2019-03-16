#include "InputData.hpp"

#include <exception>

namespace px	{
	InputData::InputData() {

	}

	void InputData::pressKey(size_t key) {
		getKey(key) = true;
	}

	void InputData::releaseKey(size_t key) {
		getKey(key) = false;
	}

	bool InputData::isKeyPressed(size_t key) const {
		return getKey(key);
	}

	bool & InputData::getKey(size_t key) {
		if (key >= Keyboard::KeyCount)
			throw std::length_error("Key ID not correct");
		return keysStatus[key];

	}

	const bool & InputData::getKey(size_t key) const {
		if (key >= Keyboard::KeyCount)
			throw std::length_error("Key ID not correct");
		return keysStatus[key];

	}
}