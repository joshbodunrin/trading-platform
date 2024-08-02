#include "order.h"
#include <string>
#include <iostream>


double quantity;
double total;
double orderPrice;
std::string stock;

//Order::Order() {}

Order::Order(std::string stk, double qty, double prc) {
    stock = stk;
    quantity = qty;
    orderPrice = prc;
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
