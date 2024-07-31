#include "stock.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string* s) {
    size_t totalSize = size * nmemb;
    s->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

Stock::Stock() {}

Stock::~Stock() {}
std::string symbol;
double price;

Stock::Stock(const std::string& sym) { //shouldnt be able to initialize stock w/o a name
        this->setSymbol(sym);
        this->setPrice();
    }

void Stock::setSymbol(const std::string& sym) {
        symbol = sym;
}

void Stock::setPrice() { //gets corr
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
        
    curl = curl_easy_init();

    if(curl) {
            
        std::string api_key = "";
        std::string symbol = Stock::getSymbol();
        std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" + symbol + "&interval=1min&apikey=" + api_key;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        std:: cout << url.c_str() << std:: endl;

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        } else {
            //std:: cout << "Response data: " << readBuffer << std:: endl;
            parseData(readBuffer);

        }

        curl_easy_cleanup(curl);
    }
        
        
        
}

std::string Stock::getSymbol() {
    return symbol;
}

double Stock::getPrice() {
    return price;
}

void Stock::parseData(std::string& data) {
    try {
        json jsonData = json::parse(data);

        auto timeSeries = jsonData["Time Series (1min)"];
        auto firstEntry = timeSeries.begin();

        std::string dateTime = firstEntry.key();
        double open = std::stod(firstEntry.value()["1. open"].get<std::string>());
        double high = std::stod(firstEntry.value()["2. high"].get<std::string>());
        double low = std::stod(firstEntry.value()["3. low"].get<std::string>());
        double close = std::stod(firstEntry.value()["4. close"].get<std::string>());
        int volume = std::stod(firstEntry.value()["5. volume"].get<std::string>());
        price = open;
        //std:: cout << "open: " << open << std::endl;
    } catch (json::parse_error& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }



}
