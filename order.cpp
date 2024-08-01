#include "order.h"
#include <string>
#include <iostream>


double quantity;
double total;
double orderPrice;
Stock* stock;

//Order::Order() {}

Order::Order(Stock* stk, double qty, double prc) {
    stock = stk;
    quantity = qty;
    orderPrice = prc;
}

Stock* Order::getStock() {
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
