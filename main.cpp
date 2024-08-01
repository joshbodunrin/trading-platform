#include "stock.h"
#include "order.h"


#include <iostream>

int main() {

    //Stock newStock = Stock("IBM");

    //Order newOrder = Order(&newStock, 2.0);

    int option;

    std::cout << "Welcome to Trading Platform Simulator!" << std::endl << std::endl << std::endl; 
    while(1) {
        std::cout << "Choose Option:" << std:: endl;
        std::cout << "1. Look up Stock " << std::endl;
        std::cout << "2. View Balance " << std:: endl;
        std::cout << "3. View Portfolio " << std:: endl;
        std::cout << "4. View Order History " << std:: endl;
        std::cout << "5. Exit " << std:: endl;
        std::cin >> option;
        if (option == 5) break;
    }


}