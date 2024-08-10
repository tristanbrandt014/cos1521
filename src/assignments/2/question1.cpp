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

void run() {

    
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
