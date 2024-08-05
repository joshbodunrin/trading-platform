#ifndef ORDER
#define ORDER
#include "stock.h"
#include <ctime>

class Order {

    public:
        Order();
        Order(std::string symbol, double quantity, double orderPrice, std::string orderType);
        double getQuantity();
        double getOrderPrice();
        std::time_t getTime();
        std::string getStock();
        std::string getOrderType();



    private:

        std::string stock;
        double quantity; // buying partial shares
        double orderPrice;
        std::time_t time;
        std::string orderType;

};


#endif //ORDER_H