#include "order.h"
#include <string>
#include <iostream>


double quantity;
double total;
Stock* stock;

//Order::Order() {}

Order::Order(Stock* stk, double quantity) {
    stock = stk;
    double price = stock->getPrice();
    total = price * quantity;
}

Stock* Order::getStock() {
    return stock;
}

double Order::getQuantity() {
    return quantity;
}

double Order::getTotal() {
    return total;
}

time_t Order::getTime() {
    return time;
}
