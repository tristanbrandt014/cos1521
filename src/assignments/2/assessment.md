---
# Generate with `pandoc assessment.md -o assessment.pdf --pdf-engine=xelatex`
title: "Assessment 2"
author: "Tristan Brandt"
date: "18259464"
header-includes:
  - \usepackage[margin=1in]{geometry}
  - \usepackage{fontspec}
  - \setmainfont{Times New Roman}
  - \usepackage{unicode-math}
  - \setmathfont{Noto Sans Math}
  - \setmonofont{Noto Sans Math}
  - \pagestyle{empty}
---

\thispagestyle{empty}


# Question 1

## Code

 ```cpp
#include <iostream>

using namespace std;

const double GLOBAL_MAIL_COST_1_3 = 108;
const double GLOBAL_MAIL_COST_4_6 = 130;
const double DHL_COST = 70;
const double VOLUMETRIC_WEIGHT_QUOTIENT = 5000;

/**
 * GlobalMail
 * Precondition: zone ∈ [1, 6]
 */
double calcPostage(double weight, int zone) {
    double cost = GLOBAL_MAIL_COST_1_3;
    if (zone > 3) {
        cost = GLOBAL_MAIL_COST_4_6;
    }
    return weight * cost;
}

/**
 * DHL
 */
double calcPostage(double weight, double length, double width, double height) {
    double weightToUse = length * width * height / VOLUMETRIC_WEIGHT_QUOTIENT;
    
    if (weight > weightToUse) {
        weightToUse = weight;
    }
    
    return weightToUse * DHL_COST;
}

/**
 *Precondition: num is defined
 */
void collectGt0 (string prompt, double& num) {
    while (num <= 0) {
        cout << prompt;
        cin >> num;
        if (num > 0) {
            break;
        }
        cout << "Number must be ≥ 0" << endl;
    }
}

int main() {

    char selection;
    int zone = 0;
    double length = 0.0, width = 0.0, height = 0.0, weight = 0.0, total;
    
    while (true) {
        cout << "Would you like to use (g) GlobalMail or (d) DHL? (g/d): ";
        cin >> selection;
        
        
        if (selection == 'g') {
            while (true) {
                cout << "Which zone are you sending to? [1, 6]: ";
                cin >> zone;
                
                if (zone < 1 || zone > 6) {
                    cout << "Zone must be between 1 and 6 (inclusive)" << endl;
                    continue;
                }
                break;
            }
            break;
        }
        
        if (selection == 'd') {
            collectGt0("Length (cm): ", length);
            collectGt0("Width (cm): ", width);
            collectGt0("Height (cm): ", height);
            break;
        }
        
        cout << "Selection must be one of [g,d]" << endl;
    }
    
    collectGt0("Weight (kg): ", weight);
    
    if (selection == 'd') {
        total = calcPostage(weight, length, width, height);
    } else {
        total = calcPostage(weight, zone);
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Total: R" << total << endl;
}
 ```

## Output

### GlobalMail Zone 1

Would you like to use (g) GlobalMail or (d) DHL? (g/d): g

Which zone are you sending to? [1, 6]: 1

Weight (kg): 1

Total: R108.00

### GlobalMail Zone 4

Would you like to use (g) GlobalMail or (d) DHL? (g/d): g

Which zone are you sending to? [1, 6]: 4

Weight (kg): 1

Total: R130.00

### DHL Higher Weight

Would you like to use (g) GlobalMail or (d) DHL? (g/d): d

Length (cm): 1

Width (cm): 1

Height (cm): 1

Weight (kg): 2

Total: R140.00

### DHL Higher Volumetric Weight

Would you like to use (g) GlobalMail or (d) DHL? (g/d): d

Length (cm): 5000

Width (cm): 2

Height (cm): 1

Weight (kg): 1

Total: R140.00

\newpage

### GlobalMail Validation

Would you like to use (g) GlobalMail or (d) DHL? (g/d): a

Selection must be one of [g,d]

Would you like to use (g) GlobalMail or (d) DHL? (g/d): c

Selection must be one of [g,d]

Would you like to use (g) GlobalMail or (d) DHL? (g/d): G

Selection must be one of [g,d]

Would you like to use (g) GlobalMail or (d) DHL? (g/d): g

Which zone are you sending to? [1, 6]: -1

Zone must be between 1 and 6 (inclusive)

Which zone are you sending to? [1, 6]: 0

Zone must be between 1 and 6 (inclusive)

Which zone are you sending to? [1, 6]: 7

Zone must be between 1 and 6 (inclusive)

Which zone are you sending to? [1, 6]: 1

Weight (kg): -1

Number must be ≥ 0

Weight (kg): 0

Number must be ≥ 0

Weight (kg): 1

Total: R108.00

### DHL Validation

Would you like to use (g) GlobalMail or (d) DHL? (g/d): d

Length (cm): -1

Number must be ≥ 0

Length (cm): 0

Number must be ≥ 0

Length (cm): 1

Width (cm): 3

Height (cm): -5

Number must be ≥ 0

Height (cm): 0

Number must be ≥ 0

Height (cm): 4

Weight (kg): 1

Total: R70.00

\newpage

# Question 2

## Code

```cpp
#include <cassert>
#include <iostream>

using namespace std;

const int CURRENT_YEAR = 2024;

int main () {
    int year;
    bool canVote;
    
    cout << "Enter your year of birth: ";
    cin >> year;
    
    assert(year < CURRENT_YEAR);
    
    canVote = (CURRENT_YEAR - year) >= 18;
    
    cout << "Eligible for voting: " << (canVote ? "Yes" : "No") << endl;
    
    return 0;
}
```

## Output

### Over 18

Enter your year of birth: 2000

Eligible for voting: Yes

### Under 18

Enter your year of birth: 2010

Eligible for voting: No

\newpage

# Question 3

## Code

```cpp
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

const string IN_FILE_PATH = "orders.dat";
const string OUT_FILE_PATH = "result.dat";
const double COMMISSION_RATE = 0.03;

int main () {
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
```

## Output (result.dat)

Number of families that ordered the special: 3

Commission earned from the special meal: R102.67

Average spent per person for the evening: R148.80

\newpage

# Question 4

## Code

```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const string IN_FILE_PATH = "letter.txt";
const string OUT_FILE_PATH = "encode.txt";

int main () {
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
}
```

## Output (encode.txt)

1Be1Sr 1Xul1Q1S,

You 1Sre 1Y1Oe mos1Y be1Su1Y1Qful g1Qrl 1Y1O1S1Y 1Q 1O1Sve ever seen. 1Q w1Ss won1Ber1Qng
1Qf you woul1B l1Qke 1Yo come 1Sn1B v1Qs1Q1Y me. My mo1Y1Oer w1Qll m1Ske us
1M1Snc1Skes w1Q1Y1O 1Qce cre1Sm. My 1Bog, Bell1S, 1Xus1Y 1O1S1B 1Y1Oree be1Su1Y1Qful 1Mu1M1M1Qes.

Mom s1Sys 1Q m1Sy only kee1M one of 1Y1Oem. 1Q woul1B l1Qke you 1Yo 1Oel1M me
c1Ooose one, bec1Suse 1Y1Oey 1Sre 1Sll so cu1Ye 1Sn1B 1S1Bor1Sble. 1Sn1B 1Xus1Y
bec1Suse you 1Sre my s1Mec1Q1Sl fr1Qen1B, you m1Sy 1Slso 1O1Sve one 1Qf you w1Sn1Y.

Your fr1Qen1B,

1Oec1Yor.