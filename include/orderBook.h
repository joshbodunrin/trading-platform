#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include <string.h>
#include <vector>
#include <memory>
#include "order.h"

//makes sense to implement this as a singleton since there should only be one orderbook
class OrderBook {
    public:
        OrderBook(const OrderBook& orderBook) = delete;
        OrderBook& operator=(const OrderBook&) = delete;

        static OrderBook* getInstance();
        void addOrder(std::shared_ptr<Order> order);
        void viewOrders();





    private:
        static OrderBook* orderBookPointer;  // maybe make unique pointer
        OrderBook();
        ~OrderBook();
        std::vector<std::shared_ptr<Order>> allOrders;

};



#endif //ORDERBOOK_H