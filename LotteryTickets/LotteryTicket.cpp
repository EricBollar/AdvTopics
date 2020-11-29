//
// Created by Kevin Morris on 9/29/19.
//

#include "LotteryTicket.h"
#include <set>
#include <iomanip>
#include <ctime>
#include <sstream>


using namespace std;

LotteryTicket::LotteryTicket(string locationPurchased) {
    while (numbers.size() < NUM_NUMBERS)
        numbers.insert(rand() % MAX_NUMBER + 1);
    loc = locationPurchased;
    timestamp = time(0);
}

LotteryTicket::~LotteryTicket() {

}

string LotteryTicket::getNumbers() const {
    string result;
    for (int number : numbers)
        result += to_string(number) + "-";
    result = result.substr(0, result.length()-1); // remove last dash
    return result;
}

string LotteryTicket::getDateTimePurchased() const {
    auto timeinfo = localtime(&timestamp);
    stringstream ss;
    ss << put_time(timeinfo, "%I:%M:%S%p %m/%d/%Y");
    return ss.str();
}

string LotteryTicket::getLocationPurchased() const {
    return loc;
}

bool LotteryTicket::operator<(const LotteryTicket &other) const {
    return this->getNumbers() < other.getNumbers();
}

