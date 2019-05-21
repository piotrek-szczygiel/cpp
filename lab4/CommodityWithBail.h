//
// Created by piotr on 09.04.19.
//

#ifndef LAB4_COMMODITYWITHBAIL_H
#define LAB4_COMMODITYWITHBAIL_H


#include "Commodity.h"

namespace shop {

    class CommodityWithBail : public Commodity {
    protected:
        double bail;

    public:
        CommodityWithBail() = delete;

        CommodityWithBail(std::string name,
                          const Date &production_date,
                          double price,
                          double tax,
                          const Date &expiration_date,
                          double bail) : Commodity(std::move(name), production_date,
                                                   price, tax, expiration_date),
                                         bail(bail) {}

        ~CommodityWithBail() override = default;

        double get_bail() {
            return bail;
        }

        double get_price() override {
            return price * (1.0 + tax) + bail;
        }

        std::string info() override {
            return Commodity::info() + " " + std::to_string(bail);
        }

        bool read(std::istream &stream) override;

        bool write(std::ostream &stream) override;

    };
}


#endif //LAB4_COMMODITYWITHBAIL_H
