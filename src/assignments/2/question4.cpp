#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const string IN_FILE_PATH = "letter.txt";
const string OUT_FILE_PATH = "encode.txt";

int q4 () {
    char next;
    
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
    
    while (inFile.get(next)) {
        switch (tolower(next)) {
            case 't': {
                outFile << "1Y";
                continue;
            }
            case 'h': {
                outFile << "1O";
                continue;
            }
            case 'j': {
                outFile << "1X";
                continue;
            }
            case 'd': {
                outFile << "1B";
                continue;
            }
            case 'a': {
                outFile << "1S";
                continue;
            }
            case 'p': {
                outFile << "1M";
                continue;
            }
            case 'i': {
                outFile << "1Q";
                continue;
            }
            default: {
                outFile << next;
            }
        }
    }
    
    inFile.close();
    outFile.close();
    return 0;
}
