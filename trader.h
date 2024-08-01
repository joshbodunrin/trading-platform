#ifndef TRADER_H
#define TRADER_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include "stock.h"
#include "order.h"
#include "orderBook.h"


class Trader {

    public:
        Trader();
        ~Trader();

        void buy(Stock* stock, double quantity);
        void sell(Stock* stock, double quantity);
        void createOrder(Stock* stock, double quantity, double orderPrice);
        void viewHoldings(std::unordered_map<Stock*, int> holdings);


    private:
        double balance; // amount in account
        std::unordered_map<Stock* , int> holdings;
        std::vector<std::shared_ptr<Order>> orders;
        OrderBook* bookPointer;



};




#endif // TRADER_H