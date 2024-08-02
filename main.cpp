#include "main.h"
#include "stock.h"
#include "order.h"


#include <iostream>

void optionMenu() {
    char option;
    while(1) {
        std::cout << "Choose Option:" << std:: endl;
        std::cout << "1. Look up Stock " << std::endl;
        std::cout << "2. View Balance " << std:: endl;
        std::cout << "3. View Portfolio " << std:: endl;
        std::cout << "4. View Order History " << std:: endl;
        std::cout << "5. Exit " << std:: endl;
        std::cin >> option; 
        std:: cout << std::endl;
        switch (option) {
            case '1':
                lookUpStock();
                break;
            case '2':
                //View Balance
                break;
            case '3':
                //viewPortfolio()
                break;
            case '4':
                //viewOrderHistory();
                break;
            case '5':
                break;
        }
    }
}

void lookUpStock() {
    std::string symbol;
    std::cout << std::endl << std::endl;
    std::cout << "Enter Symbol you want to see data for: ";
    std::cin >> symbol;
    Stock lookUp = Stock(symbol);
    std::cout << "Current Price: " << lookUp.getPrice() << std::endl;
    //optionMenu();
}

int main() {

    //Stock newStock = Stock("IBM");

    //Order newOrder = Order(&newStock, 2.0);

    std::cout << "Welcome to Trading Platform Simulator!" << std::endl << std::endl << std::endl; 
    optionMenu();



}