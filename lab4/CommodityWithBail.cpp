//
// Created by piotr on 09.04.19.
//

#include "CommodityWithBail.h"

namespace shop {

    bool CommodityWithBail::write(std::ostream &stream) {
        if (!Commodity::write(stream)) return false;
        stream << " " << bail;
        return !stream.fail();
    }

    bool CommodityWithBail::read(std::istream &stream) {
        if (!Commodity::read(stream)) return false;
        stream >> bail;
        return !stream.fail();
    }
}
