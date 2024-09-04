#include "chapter9.hpp"
#include <iostream>

using namespace std;

// less confusing
typedef int* IntPtr;

namespace chapter9 {

void declaring_pointer() {
    // holds a pointer to a double
    double *p;
}

void point_to_variable() {
    int v1 = 5;
    // & [reference operator] gets the address of a variable, similar to "call by reference" functions
    int *p1 = &v1;
    
    cout << "v1 = " << v1 << endl;
    
    // dereferencing
    *p1 = 10;
    
    cout << "v1 = " << v1 << endl;
}

void assign_pointers() {
    int *p1, *p2, v1;
    
    v1 = 10;
    
    p1 = &v1;
    p2 = p1;
    
    *p1 = 15;
    
    cout << "v1: " << v1 << endl;
}

void new_operator() {
    // new basically creates an anonymous int
    int *p1 = new int;
    
    *p1 = 5;
    
    cout << "*p1 = " << *p1 << endl;
}

void delete_operator() {
    int *p1 = new int;
    
    // deletes the int and frees up memory
    delete p1;
    
    // p1 is now a dangling pointer
}

void variable_types() {
    // automatic/ordinary variable
    int v1 = 1;
    
    // dynamic variable
    int *p1 = new int;
    
    delete p1;
    
    // lastly, global variables declared outside any function
}

void typedefs() {
    IntPtr p1;
    p1 = new int;
    delete p1;
}

void arrays_vs_pointers() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    typedef int* IntPtr;
    IntPtr p;
    
    p = a;
    
    cout << "p[1]: " << p[1] << endl;
    
    IntPtr p2;
    // a = p2; illegal
}

void dynamic_arrays() {
    typedef double* DoublePtr;
    DoublePtr p;
    
    p = new double[10];
}

void dynamic_stuff (int num) {
    // dynamic array
    int *p1 = new int[num];
    
    delete [] p1;
}

void test_thing() {
    
}

void run() {
    arrays_vs_pointers();
}

}
