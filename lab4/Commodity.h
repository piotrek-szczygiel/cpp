//
// Created by piotr on 09.04.19.
//

#ifndef LAB4_COMMODITY_H
#define LAB4_COMMODITY_H


#include "Date.h"
#include "Product.h"

namespace shop {

    class Commodity : public Product {
    protected:
        double price;
        double tax;
        Date expiration_date;

    public:
        Commodity() = delete;

        Commodity(std::string name,
                  const Date &production_date,
                  double price,
                  double tax,
                  const Date &expiration_date) : Product(std::move(name), production_date),
                                                 price(price), tax(tax), expiration_date(expiration_date) {}

        ~Commodity() override = default;

        Date get_expiration_date() {
            return expiration_date;
        }

        double get_price() override {
            return price * (1.0 + tax);
        }

        std::string info() override;

        bool read(std::istream &stream) override;

        bool write(std::ostream &stream) override;
    };
}

#endif //LAB4_COMMODITY_H
