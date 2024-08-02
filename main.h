#ifndef MAIN_H 
#define MAIN_H
#include "trader.h"

void optionMenu(Trader* trader);
void lookUpStock();
void viewBalance(Trader* trader);
void viewPortfolio(Trader* trader);
void viewOrders(Trader* trader);
void buyStock(Trader* trader);
void sellStock(Trader* trader);


#endif //MAIN_H