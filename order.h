#ifndef ORDER
#define ORDER
#include "stock.h"
#include <ctime>

class Order {

    public:
        Order();
        Order(std::string symbol, double quantity, double orderPrice);
        double getQuantity();
        double getOrderPrice();
        std::time_t getTime();
        std::string getStock();



    private:

        std::string stock;
        double quantity; // buying partial shares
        double orderPrice;
        std::time_t time;

};


#endif //ORDER_H