#include "stock.h"
#include "order.h"


#include <iostream>

int main() {

    Stock newStock = Stock("IBM");

    Order newOrder = Order(&newStock, 2.0);

}