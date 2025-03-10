#include "trader.h"
//#include "stock.h"
//#include "order.h"
//#include "orderBook.h"
#include <string>
#include <iostream>





Trader::Trader() {
    balance = 10000;
    
}

Trader::~Trader() {}

void Trader::buy(Stock& stock, double quantity, OrderBook* orderBook) { //need to remeber to create order
    double amount = stock.getPrice() * quantity;
    if (balance > amount) {
        balance -= amount;
        createOrder(stock.getSymbol(), quantity, amount, "Buy", orderBook);
        std::string symbol = stock.getSymbol();
        holdings[symbol] += quantity;
    } else {
       std:: cout << "Not enough balance in account to buy" << std:: endl;
    }

}

void Trader::sell(Stock& stock, double quantity, OrderBook* orderBook) {
    auto it = holdings.find(stock.getSymbol());
    if (it != holdings.end()) {
        double currentHoldings = it->second;
        if (currentHoldings > quantity) {
            double amount = stock.getPrice() * quantity;
            balance += amount;
            it->second -= quantity;
            createOrder(stock.getSymbol(), quantity, amount, "Sell", orderBook);
            return;
        } else {
            std:: cout << "Not enough of " + stock.getSymbol() + " currently have: " << currentHoldings << std::endl;
            return;
        }
    }
    std :: cout << "Do not have any holdings of " + stock.getSymbol() + " to sell" << std::endl;
}

void Trader::createOrder(std::string stock, double quantity, double orderPrice, std::string orderType, OrderBook* orderBook) {
    std::shared_ptr<Order> newOrder = std::make_shared<Order>(stock, quantity, orderPrice, orderType);
    orders.push_back(newOrder);
    orderBook->addOrder(newOrder);
}

void Trader::printHoldings() {
    for (auto& pair : holdings) {
        std::string stock = pair.first;
        double quantity = pair.second;
        Stock stk(stock);
        stk.setPrice();
        double value = stk.getPrice() * quantity;
        std::cout << "Stock: " << stock << ", Quantity: " << quantity << ", Value: " << value << std::endl;
    }
}

void Trader::printOrders() {
    for (auto& order: orders) {
        std::cout << "Stock: " << order->getStock() << ", Quantity: " << order->getQuantity() << ", Price: " << order->getOrderPrice() << std::endl;

    }
}

double Trader::getBalance() {
    return balance;
}
