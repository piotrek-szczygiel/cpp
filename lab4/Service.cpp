//
// Created by piotr on 09.04.19.
//

#include "Service.h"

namespace shop {

    bool Service::read(std::istream &stream) {
        if (!Product::read(stream)) return false;
        stream >> hourly_rate >> hours_count;
        return !stream.fail();
    }

    bool Service::write(std::ostream &stream) {
        if (!Product::write(stream)) return false;
        stream << " " << hourly_rate << hours_count;
        return !stream.fail();
    }
}
