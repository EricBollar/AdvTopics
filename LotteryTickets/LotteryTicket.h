//
// Created by Kevin Morris on 9/29/19.
//

#ifndef LOTTERYTICKETS_LOTTERYTICKET_H
#define LOTTERYTICKETS_LOTTERYTICKET_H
#include <string>
#include <set>


using namespace std;

class LotteryTicket {
public:
    LotteryTicket(string locationPurchased);
    ~LotteryTicket();
    string getNumbers() const;
    string getDateTimePurchased() const;
    string getLocationPurchased() const;
    bool operator<(const LotteryTicket & other) const;

private:
    set<int> numbers;
    time_t timestamp;
    string loc;

    const int NUM_NUMBERS = 7;
    const int MAX_NUMBER = 49;
};



#endif //LOTTERYTICKETS_LOTTERYTICKET_H
