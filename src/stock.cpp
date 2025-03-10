#include "stock.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <mutex>

using json = nlohmann::json;


size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string* s) {
    size_t totalSize = size * nmemb;
    s->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

Stock::Stock() {}

Stock::~Stock() {}


Stock::Stock(const std::string& sym) { //shouldnt be able to initialize stock w/o a name
        setSymbol(sym);
    }

void Stock::setSymbol(const std::string& sym) {
        std::lock_guard<std::mutex> lock(symbolMutex);
        symbol = sym;
}

void Stock::setPrice() { //gets corr
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
        
    curl = curl_easy_init();

    if(curl) {
            
        std::string api_key = "";
        std::string symbol = getSymbol();
        std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=" + symbol + "&interval=1min&apikey=" + api_key;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        //std:: cout << url.c_str() << std:: endl;

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        } else {
            try {
                //std::cout<< "Response data: " << readBuffer << std::endl;
                auto jsonRespone = json::parse(readBuffer);
                if (jsonRespone.contains("Error Message")) {
                    std::string errorMessage = jsonRespone["Error Message"];
                    throw std::runtime_error("API Error: " + errorMessage);
                }
                parseData(readBuffer);
            } catch (const std::exception& e) {
                std::cerr << "Invalid stock symbol" << std::endl;
                throw;
                //e.what();
            }

        }


    }

        curl_easy_cleanup(curl);
}
        
        
        


std::string Stock::getSymbol() const {
    std::lock_guard<std::mutex> lock(symbolMutex);
    return symbol;
}

double Stock::getPrice() const {
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
