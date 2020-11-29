#include <iostream>
#include <chrono>
#include <thread>
#include <set>
#include "LotteryTicket.h"

using namespace std;

string getTicketInfo(LotteryTicket t) {
    return t.getNumbers() + " [" + t.getDateTimePurchased() + " at " +
           t.getLocationPurchased() + "]";
}

int main() {
    cout << "Let's play the lottery..." << endl;

//    LotteryTicket ticketA("Campbell Building");
//    cout << getTicketInfo(ticketA) << endl;
//
//    this_thread::sleep_for(chrono::seconds(10));
//
//    LotteryTicket ticketB("Campbell Building");
//    cout << getTicketInfo(ticketB) << endl;

    set<LotteryTicket> tickets;
    for (int i = 0; i < 100; i++) {
        LotteryTicket ticket("Homer Building");
        tickets.insert(ticket);
    }

    for (LotteryTicket t : tickets) {
        cout << getTicketInfo(t) << endl;
    }

    return 0;
}