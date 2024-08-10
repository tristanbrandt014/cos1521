// This flag disables assert statements
//#define NDEBUG
#include <cassert>
#include "chapter5.hpp"
#include "iostream"



using namespace std;

namespace chapter5 {
void run() {
    assert(false);
    cout << "Hello there" << endl;
}
}
