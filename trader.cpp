#include "trader.h"
//#include "stock.h"
//#include "order.h"
//#include "orderBook.h"
#include <string>
#include <iostream>



double balance;
std::unordered_map<Stock*,int> holdings;
std::vector<std::shared_ptr<Order>> orders;
OrderBook* bookPointer;

Trader::Trader() {
    balance = 10000;
    bookPointer = OrderBook::getInstance();
}

void Trader::buy(Stock* stock, double quantity) { //need to remeber to create order
    double amount = stock->getPrice() * quantity;
    if (balance > amount) {
        balance -= amount;
        createOrder(stock, quantity, amount);
        auto it = holdings.find(stock);
        if (it!= holdings.end()) {
            it->second += quantity;
        } else {
            holdings[stock] = quantity;
        }
    } else {
       std:: cout << "Not enough balance in account to buy" << std:: endl;
    }

}

void Trader::sell(Stock* stock, double quantity) {
    auto it = holdings.find(stock);
    if (it != holdings.end()) {
        double currentHoldings = it->second;
        if (currentHoldings > quantity) {
            double amount = stock->getPrice() * quantity;
            balance += amount;
            it->second -= quantity;
            createOrder(stock, quantity, amount);
            return;
        } else {
            std:: cout << "Not enough of " + stock->getSymbol() + " currently have: " << currentHoldings << std::endl;
            return;
        }
    }
    std :: cout << "Do not have any holdings of " + stock->getSymbol() + " to sell" << std::endl;
}

void Trader::createOrder(Stock* stock, double quantity, double orderPrice) {
    std::shared_ptr<Order> newOrder = std::make_shared<Order>(stock, quantity, orderPrice);
    orders.push_back(newOrder);
    bookPointer->addOrder(newOrder);
}