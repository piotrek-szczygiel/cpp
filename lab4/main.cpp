#include <iostream>
#include "Date.h"
#include "Product.h"
#include "CommodityWithBail.h"
#include "Service.h"

using namespace std;
using namespace shop;

int main() {
    Date date1(2019, 4, 9);
    cout << date1 << endl;

    Date date2(0, 0, 0);
    // date2.read(cin);
    date2.write(cout);

    date2.set_year(2020);
    cout << endl << date2.get_year() << endl;

    Product *products[] = {
            new CommodityWithBail("commodity_with_bail", date1, 7.77, 0.23, date2, 100.0),
            new Commodity("commodity", Date(1, 2, 3), 5.0, 0.1, Date(1, 2, 13)),
            new Service("service", Date(10, 10, 10), 50.0, 2.0)
    };

    for(auto& product : products) {
        cout << endl << "info: " << product->info() << endl;
        cout << "get_price: " << product->get_price() << endl;
        product->write(cout);
        cout << endl << endl;
    }

    return 0;
}