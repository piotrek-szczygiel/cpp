//
// Created by piotr on 09.04.19.
//

#ifndef LAB4_DATE_H
#define LAB4_DATE_H


#include <string>
#include <istream>
#include <ostream>

namespace shop {

    class Date {
    private:
        int year;
        int month;
        int day;

    public:
        Date() = delete;

        Date(int year, int month, int day) : year(year), month(month), day(day) {}

        void set_year(int new_year) {
            year = new_year;
        }

        int get_year() {
            return year;
        }

        bool read(std::istream &stream);

        bool write(std::ostream &stream);

        friend std::ostream &operator<<(std::ostream &stream, Date &date);
    };
}


#endif //LAB4_DATE_H
