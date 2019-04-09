//
// Created by piotr on 09.04.19.
//

#include "Product.h"

namespace shop {

    std::string Product::info() {
        std::stringstream ss;
        ss << " " << name << " " << production_date;
        return ss.str();
    }

    bool Product::read(std::istream &stream) {
        stream >> name;
        production_date.read(stream);
        return !stream.fail();
    }

    bool Product::write(std::ostream &stream) {
        stream << name << " " << production_date;
        return !stream.fail();
    }
}
