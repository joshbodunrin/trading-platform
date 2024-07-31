#include "stock.h"


#include <iostream>

int main() {

    Stock newStock = Stock("IBM");

    std:: cout << newStock.getSymbol() << std:: endl;

    newStock.setPrice();
}