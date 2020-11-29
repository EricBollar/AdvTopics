//
// Eric Bollar, 9/10/20
//

#ifndef CELEBRITIES_CELEBRITY_H
#define CELEBRITIES_CELEBRITY_H
#include <string>
#include <vector>

using namespace std;

class Celebrity {
private:
    string name;
    vector<string> clues;
public:
    Celebrity(string name, string clues);
    string getName();
    string getClue();
};


#endif //CELEBRITIES_CELEBRITY_H
