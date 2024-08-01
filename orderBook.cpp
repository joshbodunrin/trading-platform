#include "orderBook.h"
#include "order.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>


OrderBook* OrderBook::orderBookPointer = nullptr; // do this bc static member
std::vector<std::shared_ptr<Order>> allOrders;

OrderBook::OrderBook() {};

OrderBook* OrderBook::getInstance() {
    if (orderBookPointer == nullptr) {
        orderBookPointer= new OrderBook();
    }
    return orderBookPointer;
}

void OrderBook::addOrder(std::shared_ptr<Order> order) {
    allOrders.push_back(order);
}













