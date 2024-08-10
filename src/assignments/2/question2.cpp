#include <cassert>
#include <iostream>

using namespace std;

const int CURRENT_YEAR = 2024;

int run2 () {
    int year;
    bool canVote;
    
    cout << "Enter your year of birth: ";
    cin >> year;
    
    assert(year < CURRENT_YEAR);
    
    canVote = (CURRENT_YEAR - year) >= 18;
    
    cout << "Eligible for voting: " << (canVote ? "Yes" : "No") << endl;
    
    return 0;
}
