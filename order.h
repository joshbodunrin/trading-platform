#ifndef ORDER
#define ORDER
#include "stock.h"
#include <ctime>

class Order {

    public:
        Order();
        Order(Stock* stock, double quantity, double orderPrice);
        double getQuantity();
        double getOrderPrice();
        std::time_t getTime();
        Stock* getStock();



    private:

        Stock* stock;
        double quantity; // buying partial shares
        double orderPrice;
        std::time_t time;

};


#endif //ORDER_H