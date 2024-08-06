#include "order.h"
#include <string>
#include <iostream>



//Order::Order() {}

Order::Order(std::string stk, double qty, double prc, std::string ot) {
    stock = stk;
    quantity = qty;
    orderPrice = prc;
    orderType = ot;
}

std::string Order::getStock() {
    return stock;
}

double Order::getQuantity() {
    return quantity;
}

double Order::getOrderPrice() {
    return orderPrice;
}

time_t Order::getTime() {
    return time;
}
std::string Order::getOrderType() {
    return orderType;
}
