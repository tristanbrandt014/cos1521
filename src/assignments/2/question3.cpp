#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

const string IN_FILE_PATH = "orders.dat";
const string OUT_FILE_PATH = "result.dat";
const double COMMISSION_RATE = 0.03;

int run3 () {
    int totalNumFamilies = 0, totalNumMembers = 0, currentNumMembers, currentNumSpecials, currentNumWine;
    float totalBill = 0, commission, average, currentBill;
    
    ifstream inFile;
    ofstream outFile;
    
    inFile.open(IN_FILE_PATH);
    outFile.open(OUT_FILE_PATH);
    
    if (inFile.fail()) {
        cout << "Failed to open " << IN_FILE_PATH << endl;
        exit(1);
    }
    
    if (outFile.fail()) {
        cout << "Failed to open " << OUT_FILE_PATH << endl;
        exit(1);
    }
    
    while (inFile >> currentNumMembers) {
        inFile >> currentNumSpecials;
        inFile >> currentNumWine;
        inFile >> currentBill;
        
        if (currentNumMembers < 5) {
            continue;
        }
        
        if (currentNumSpecials < 4) {
            continue;
        }
        
        if (currentNumWine < 2) {
            continue;
        }
        
        totalNumFamilies += 1;
        totalNumMembers += currentNumMembers;
        totalBill += currentBill;
    }
    
    commission = totalBill * COMMISSION_RATE;
    average = totalBill / totalNumMembers;
    
    outFile.setf(ios::fixed);
    outFile.setf(ios::showpoint);
    outFile.precision(2);
    
    outFile << "Number of families that ordered the special: " << totalNumFamilies << endl;
    outFile << "Commission earned from the special meal: R" << commission << endl;
    outFile << "Average spent per person for the evening: R" << average << endl;
    
    inFile.close();
    outFile.close();
    
    return 0;
}
