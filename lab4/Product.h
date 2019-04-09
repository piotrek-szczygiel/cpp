#include <utility>

#include <utility>

//
// Created by piotr on 09.04.19.
//

#ifndef LAB4_PRODUCT_H
#define LAB4_PRODUCT_H


#include <iostream>
#include <sstream>
#include "Date.h"

namespace shop {

    class Product {
    protected:
        std::string name;
        Date production_date;

    public:
        Product() = delete;

        Product(std::string name, const Date &production_date) : name(std::move(name)),
                                                                 production_date(production_date) {}

        virtual ~Product() = default;

        virtual std::string info();

        virtual double get_price() = 0;

        virtual bool read(std::istream &stream);

        virtual bool write(std::ostream &stream);
    };
}

#endif //LAB4_PRODUCT_H
