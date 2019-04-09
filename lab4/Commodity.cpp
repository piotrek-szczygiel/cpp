//
// Created by piotr on 09.04.19.
//

#include "Commodity.h"

namespace shop {

    bool Commodity::write(std::ostream &stream) {
        if (!Product::write(stream)) return false;
        stream << " " << price << " " << tax << " " << expiration_date;
        return !stream.fail();
    }

    bool Commodity::read(std::istream &stream) {
        if (!Product::read(stream)) return false;
        stream >> price >> tax;
        expiration_date.read(stream);
        return !stream.fail();
    }

    std::string Commodity::info() {
        std::stringstream ss;
        ss << " " << price << " " << tax << " " << expiration_date;
        return Product::info() + ss.str();
    }
}
