#ifndef STOCK_H
#define STOCK_H
#include <string>


class Stock {
    public:
            Stock();
            ~Stock();
            Stock(const std::string&);
            void setSymbol(const std::string&);
            void setPrice();
            double getPrice();
            std::string getSymbol();
            void parseData(std::string&);
            
    private:
            double price;
            std::string name;



};

#endif //STOCK_H
