#include "main.h"
#include "stock.h"
#include "order.h"
#include "trader.h"
#include <cctype>
#include <vector>
#include <thread>
#include <iostream>


OrderBook* bookPointer = OrderBook::getInstance();



void executeBuys(Trader& ghostTrader, Trader& trader, Stock& stock, Stock& ghostStock, double quantity, OrderBook* orderBook ) {
    std::thread ghostThread(&Trader::buy, std::ref(ghostTrader), std::ref(ghostStock), 2.0, bookPointer);
    std::thread traderThread(&Trader::buy, std::ref(trader), std::ref(stock), quantity, bookPointer);

    ghostThread.join();
    traderThread.join();
}

void toUpperCase(std::string& input) { //so all stock symbols the same
    for (char&c : input) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
}

void optionMenu(Trader& trader) {
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
        std::cout << "8. View Global OrderBook" << std::endl;
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
                buyStock(trader, bookPointer);
                break;
            case '7':
                sellStock(trader, bookPointer);
                break;
            case '8':
                viewAllOrders(bookPointer);
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

void viewBalance(Trader& trader) {
    std::cout << std::endl << std::endl;
    std::cout << "Current Balance: " << trader.getBalance() << std::endl << std::endl;
    //optionMenu();
    
}

void viewPortfolio(Trader& trader) {
    std::cout<<std::endl << std::endl;
    trader.printHoldings();
    std::cout<< std::endl;
}

void viewOrders(Trader& trader) {
    std::cout<<std::endl<<std::endl;
    trader.printOrders();
    std::cout<<std::endl;
}

void buyStock(Trader& trader, OrderBook* orderBook) {
    std::string symbol;
    double quantity;
    std::cout << std::endl << std::endl;
    std::cout << "Enter Stock you would like to buy: ";
    std::cin >> symbol;
    try {
    toUpperCase(symbol);
    Stock lookUp(symbol);
    double price = lookUp.getPrice();
    std::cout << "Current Price: " << price << std::endl;
    std::cout << "How many shares would you like to buy: ";
    std::cin >> quantity;
    Trader ghostTrader = Trader();
    Stock ghostStock("AAPL");
    ghostStock.setPrice();
    std::cout << "here is ghoststock: " << ghostStock.getSymbol() <<std::endl;
    std::cout << "here is reg stock: " << lookUp.getSymbol() << std::endl;

    executeBuys(ghostTrader, trader, lookUp, ghostStock, quantity, bookPointer);
//    ghostTrader->buy(&lookUp, quantity, bookPointer);
//    trader->buy(&lookUp, quantity, bookPointer);
    } catch(const std::runtime_error& e) {
        std::cerr << "Try another Symbol " << std::endl;
        buyStock(trader, bookPointer);
    }

}

void sellStock(Trader& trader, OrderBook* orderBook) {
    std::string symbol;
    double quantity;
    std::cout << std::endl << std::endl;
    std::cout << "Enter Stock you would like to sell: ";
    std::cin >> symbol;
    try {
    toUpperCase(symbol);
    Stock lookUp = Stock(symbol);
    double price = lookUp.getPrice();
    std::cout << "Current Price: " << price << std::endl;
    std::cout << "How many shares would you like to buy: ";
    std::cin >> quantity;
    trader.sell(lookUp, quantity, bookPointer);
    } catch(const std::runtime_error& e) {
        std::cerr << "Try another Symbol " << std::endl;
        sellStock(trader, bookPointer);
    }
}

void viewAllOrders(OrderBook* orderBook) {
    std::cout << std::endl;
    std::cout << "Here are all orders in the book: " << std::endl;
    bookPointer->viewOrders();
}



int main() {

    //Stock newStock = Stock("IBM");

    //Order newOrder = Order(&newStock, 2.0);
    Trader mainTrader = Trader();

    std::cout << "Welcome to Trading Platform Simulator!" << std::endl << std::endl << std::endl; 
    optionMenu(mainTrader);



}