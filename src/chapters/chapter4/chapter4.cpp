#include "chapter4.hpp"
#include "iostream"

using namespace std;

namespace chapter4 {
int sum (int a, int b) {
    return a + b;
}

int sum (int a, int b, int c) {
    return a + b + c;
}

void run() {
    cout << sum(1, 3) << endl;
    cout << sum(1, 2, 3) << endl;
}
}
