#include "main.h"
#include "stock.h"
#include "order.h"
#include "trader.h"
#include <cctype>

#include <iostream>

void toUpperCase(std::string& input) { //so all stock symbols the same
    for (char&c : input) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
}

void optionMenu(Trader* trader) {
    char option;
    while(1) {
        std::cout << "Choose Option:" << std:: endl;
        std::cout << "1. Look up Stock " << std::endl;
        std::cout << "2. View Balance " << std:: endl;
        std::cout << "3. View Portfolio " << std:: endl;
        std::cout << "4. View Order History " << std:: endl;
        std::cout << "5. Exit " << std:: endl;
        std::cout << "6. Buy Stock" << std::endl;
        std::cout << "7. Sell Stock" << std::endl;
        std::cin >> option; 
        std:: cout << std::endl;
        switch (option) {
            case '1':
                lookUpStock();
                break;
            case '2':
                viewBalance(trader);
                break;
            case '3':
                viewPortfolio(trader);
                break;
            case '4':
                viewOrders(trader);
                break;
            case '5':
                break;
            case '6':
                buyStock(trader);
                break;
            case '7':
                sellStock(trader);
                break;
        }
    }
}

void lookUpStock() {
    std::string symbol;
    std::cout << std::endl << std::endl;
    std::cout << "Enter Symbol you want to see data for: ";
    std::cin >> symbol;
    try {
    Stock lookUp = Stock(symbol);
    double price = lookUp.getPrice();
    std::cout << "Current Price: " << price << std::endl;
    } catch(const std::runtime_error& e) {
        std::cerr << "Try another Symbol " << std::endl;
        lookUpStock();
    }


    //optionMenu();
}

void viewBalance(Trader* trader) {
    std::cout << std::endl << std::endl;
    std::cout << "Current Balance: " << trader->getBalance() << std::endl << std::endl;
    //optionMenu();
    
}

void viewPortfolio(Trader* trader) {
    std::cout<<std::endl << std::endl;
    trader->printHoldings();
    std::cout<< std::endl;
}

void viewOrders(Trader* trader) {
    std::cout<<std::endl<<std::endl;
    trader->printOrders();
    std::cout<<std::endl;
}

void buyStock(Trader* trader) {
    std::string symbol;
    double quantity;
    std::cout << std::endl << std::endl;
    std::cout << "Enter Stock you would like to buy: ";
    std::cin >> symbol;
    try {
    //toUpperCase(symbol);
    Stock lookUp = Stock(symbol);
    double price = lookUp.getPrice();
    std::cout << "Current Price: " << price << std::endl;
    std::cout << "How many shares would you like to buy: ";
    std::cin >> quantity;
    trader->buy(&lookUp, quantity);
    } catch(const std::runtime_error& e) {
        std::cerr << "Try another Symbol " << std::endl;
        buyStock(trader);
    }

}

void sellStock(Trader* trader) {}

int main() {

    //Stock newStock = Stock("IBM");

    //Order newOrder = Order(&newStock, 2.0);
    Trader mainTrader = Trader();

    std::cout << "Welcome to Trading Platform Simulator!" << std::endl << std::endl << std::endl; 
    optionMenu(&mainTrader);



}