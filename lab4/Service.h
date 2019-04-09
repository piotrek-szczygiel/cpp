#include <utility>

//
// Created by piotr on 09.04.19.
//

#ifndef LAB4_SERVICE_H
#define LAB4_SERVICE_H


#include "Product.h"

namespace shop {

    class Service : public Product {
    protected:
        double hourly_rate;
        double hours_count;

    public:
        Service() = delete;

        Service(std::string name,
                const Date &production_date,
                double hourly_rate,
                double hours_count) : Product(std::move(name), production_date),
                                      hourly_rate(hourly_rate),
                                      hours_count(hours_count) {}

        ~Service() override = default;

        double get_price() override {
            return hourly_rate * hours_count;
        }

        std::string info() override {
            return Product::info() + std::to_string(hourly_rate) + " " + std::to_string(hours_count);
        }

        bool read(std::istream &stream) override;

        bool write(std::ostream &stream) override;
    };
}

#endif //LAB4_SERVICE_H
