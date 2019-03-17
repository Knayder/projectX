#pragma once

namespace px {

    size_t hash(const std::string& obj) {
        return std::hash<std::string>{}(obj);
    }

}