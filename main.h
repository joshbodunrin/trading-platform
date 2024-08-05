#ifndef MAIN_H 
#define MAIN_H
#include "trader.h"
#include "orderBook.h"
#include <thread>

void optionMenu(Trader& trader);
void lookUpStock();
void viewBalance(Trader& trader);
void viewPortfolio(Trader& trader);
void viewOrders(Trader& trader);
void buyStock(Trader& trader, OrderBook* orderBook);
void sellStock(Trader& trader, OrderBook* orderBook);
void viewAllOrders(OrderBook* orderBook);
double getRandomDouble(double min, double max);


#endif //MAIN_H