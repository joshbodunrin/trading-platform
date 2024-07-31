#ifndef ORDER
#define ORDER
#include "stock.h"
#include <ctime>

class Order {

    public:
        Order();
        Order(Stock* stock, double quantity);
        double getQuantity();
        double getTotal();
        std::time_t getTime();
        Stock* getStock();



    private:

        Stock* stock;
        double quantity; // buying partial shares
        double total;
        std::time_t time;

};


#endif //ORDER_H