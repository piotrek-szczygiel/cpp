//
// Created by piotr on 09.04.19.
//

#include "Date.h"

namespace shop {

    bool Date::read(std::istream &stream) {
        stream >> year >> month >> day;
        return !stream.fail();
    }

    bool Date::write(std::ostream &stream) {
        stream << year << " " << month << " " << day;
        return !stream.fail();
    }

    std::ostream &operator<<(std::ostream &stream, Date &date) {
        date.write(stream);
        return stream;
    }
}
