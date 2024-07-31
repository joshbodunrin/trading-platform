#include "orderBook.h"
#include "order.h"
#include <string>
#include <iostream>
#include <vector>


OrderBook* OrderBook::orderBookPointer = nullptr;
std::vector<Order> orders;

OrderBook::OrderBook() {};

OrderBook* OrderBook::getInstance() {
    if (orderBookPointer == nullptr) {
        orderBookPointer= new OrderBook();
    }
    return orderBookPointer;
}









