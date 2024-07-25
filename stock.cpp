#include "stock.h"
#include <iostream>
#include <string>
#include <curl/curl.h>


Stock::Stock() {}

Stock::~Stock() {}
std::string symbol;
double price;

Stock::Stock(const std::string& sym) { //shouldnt be able to initialize stock w/o a name
        Stock::setSymbol(sym);
    }

void Stock::setSymbol(const std::string& sym) {
        symbol = sym;
}

void Stock::setPrice() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
        
    curl = curl_easy_init();

    if(curl) {
            
        std::string api_key = "";
        std::string symbol = Stock::getSymbol();
        std::string url = "https://www.aplhavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" + symbol + "&interval=1min&apikey=" + api_key;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        } else {
            std:: cout << "Response data: " << readBuffer << std:: endl;

        }

        curl_easy_cleanup(curl);
    }
        
        
        
}

std::string getSymbol() {
    return symbol;
}

double getPrice() {
    return price;
}
