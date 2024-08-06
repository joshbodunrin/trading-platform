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

        void buy(Stock& stock, double quantity, OrderBook* orderBook);
        void sell(Stock& stock, double quantity, OrderBook* orderBook);
        void createOrder(std::string stock, double quantity, double orderPrice, std::string orderType, OrderBook* orderBook);
        void printHoldings();
        void printOrders();
        double getBalance();


    private:
        double balance; // amount in account
        std::unordered_map<std::string , int> holdings;
        std::vector<std::shared_ptr<Order>> orders;
        



};




#endif // TRADER_H