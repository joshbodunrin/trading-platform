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

void OrderBook::viewOrders() {
    for (auto& order: allOrders) {
        std::cout << "Stock: " << order->getStock() << ", Quantity: " << order->getQuantity() << ", Price: " << order->getOrderPrice() << ", Order Type: " << order->getOrderType() << std::endl;

    }
}













