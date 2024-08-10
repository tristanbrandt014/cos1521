#include "chapter6.hpp"
#include <iostream>
// for file stuff
#include <fstream>
// for exit
#include <cstdlib>
#include <string>
// for toupper/tolower
#include <cctype>


using namespace std;

namespace chapter6 {

void randomOutput() {
    ofstream outStream;
    
    outStream.open("data.txt");
    
    if (outStream.fail()) {
        cout << "Failed to open file" << endl;
        exit(1);
    }
    
    
    outStream << "Hello" << endl;
    
    outStream.close();
}

void printInput() {
    ifstream inStream;
    
    inStream.open("data.txt");
    
    if (inStream.fail()) {
        // handle error
        exit(1);
    }
    
    int num1, num2, num3;
    inStream >> num1 >> num2 >> num3;
    
    cout << "Numbers: " << endl << num1 << endl << num2 << endl << num3 << endl;
}

void selftest2() {
    ifstream inFile;
    ofstream outFile;
    
    const string IN_FILE_PATH = "selftest2/stuff1.dat";
    const string OUT_FILE_PATH = "selftest2/stuff2.dat";
    
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
    
    string line;
    
    while(getline(inFile, line)) {
        outFile << line << endl;
    }
    
    inFile.close();
    outFile.close();
}

void appendStuff() {
    ofstream outFile;
    outFile.open("chapter6/append.dat", ios::app);
    
    if (outFile.fail()) {
        cout << "Failed to open file" << endl;
        exit(1);
    }
    
    outFile << "Hello there!" << endl << "I have appened :)" << endl;
    outFile.close();
}

void flagsNShit() {
    float num = 163456567.54354245524352345;
    float otherNum = 1.0;
    
    cout << "Before ~ " << num << " | " << otherNum << endl;
    
    
    cout.setf(ios::showpoint);
    
    cout << "ios::showpoint - " << num << " | " << otherNum << endl;
    
    
    cout.setf(ios::fixed);
    
    cout << "ios::fixed - " << num << " | " << otherNum << endl;


    cout.precision(2);
    
    cout << "precision - " << num << " | " << otherNum << endl;
}

void leftNRight() {
    cout << "Hello ";
    cout.width(10);
    cout << "154" << endl;
    
    cout << "Hello ";
    cout.setf(ios::left);
    cout.width(10);
    cout << "154" << "There" << endl;
    
    cout.unsetf(ios::left);
    cout << "Back to normal :)" << endl;
}

void manipulators() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    
    cout << setprecision(2) << "R" << 10.3 << endl << "R" << 5 << endl;
}

void copypasta(ifstream& inFile, ofstream& outFile) {
    string line;
    while(getline(inFile, line)) {
        outFile << line << endl;
    }
}

void runCopyPasta() {
    ifstream inFile;
    ofstream outFile;
    
    const string IN_FILE_PATH = "chapter6/argsIn.dat";
    const string OUT_FILE_PATH = "chapter6/argsOut.dat";
    
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
    
    copypasta(inFile, outFile);
    
    inFile.close();
    outFile.close();
}

void toScreen(ifstream &fileStream) {
    int num;
    while (fileStream >> num) {
        cout << num << endl;
    }
}

void readSingleChar() {
    char thing;
    cout << "Enter a thing ~ ";
    cin.get(thing);
    cout << "I only saw the first piece of the thing :( ~ " << thing << endl;
}

void writeSingleChar() {
    cout.put('h');
    cout.put('\n');
}

void printFromFirstW() {
    cout << "Enter a string that contains a w ~ ";
    char thing;
    while(cin.get(thing)) {
        if (tolower(thing) == 'w') {
            cin.putback(thing);
            break;
        }
    }
    string rest;
    getline(cin, rest);
    cout << rest << endl;
}

void randomInputStream(istream &inStream) {
    char thing;
    inStream.get(thing);
    
    cout << thing;
}

void eofstuff () {
    const string IN_FILE_PATH = "chapter6/eofstuff.dat";
    
    ifstream inFile;
    inFile.open(IN_FILE_PATH);
    
    if (inFile.fail()) {
        cout << "Failed to open " << IN_FILE_PATH << endl;
        exit(1);
    }
    
    char next;
    inFile.get(next);
    while (!inFile.eof()) {
        cout << next;
        inFile.get(next);
    }
}

void charStuff () {
    // These return ints, must store it in char
    toupper('a'); // Returns A
    toupper('/'); // Returns /
    tolower('B'); // Returns b, similar for /
    isspace(' '); // Returns true for whitespace characters
    
    // Returns 65
    cout << "Without cast: " << toupper('a') << endl;
    // Manually cast
    cout << "With cast: " << static_cast<char>(toupper('a')) << endl;
}

void run() {
    charStuff();
}
}
