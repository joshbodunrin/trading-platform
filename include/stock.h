#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <mutex>


class Stock {
    public:
            Stock();
            ~Stock();
            Stock(const std::string&);
            void setSymbol(const std::string&);
            void setPrice();
            double getPrice() const;
            std::string getSymbol() const;
            void parseData(std::string&);
            
    private:
            double price;
            std::string symbol;
            mutable std::mutex symbolMutex;



};

#endif //STOCK_H
