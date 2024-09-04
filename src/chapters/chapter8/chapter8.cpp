#include "chapter8.hpp"
#include <iostream>
#include <cstring>
//for atoi
#include <cstdlib>
//for isdigit
#include <cctype>
#include <vector>

namespace chapter8 {

using namespace std;

void cstring() {
    // autogenerate the array of length 5 (characters + '\0'
    char smolString1[] = "smol";
    // manual length (be sure to add 1 for '\0'
    char smolString2[5] = "smol";
    // manual array of char
    char smolString3[5] = {'s', 'm', 'o', 'l', '\0'};
    
    cout << "str1: " << smolString1 << endl;
    cout << "str2: " << smolString2 << endl;
    cout << "str3: " << smolString3 << endl;
}

void respect_null() {
    // don't try modifying null char otherwise weird shit happens
    char str[10] = "smol";
    cout << "before: " << str << endl;
    // DON"T DO THIS BECAUSE IDK SOMETHING WILL HAPPEN
    str[4] = 'a';
    cout << "Length: " << strlen(str) << endl;
}

void assignment() {
    // when assigning, use strcpy
    char hello[10];
    // don't do this
    // hello = "hi";
    // rather do:
    strcpy(hello, "hi");
    cout << hello << endl;
}

void saferassignment() {
    // also, use strncpy over strcpy because safety
    char smolBakkie[1];
    // this will break
//     strcpy(smolBakkie, "tons of food");
    // rather do this
    strncpy(smolBakkie, "tons of food", 1);
}

void equality() {
    // because array, using == won't work
    char str1[] = "a";
    char str2[] = "b";
    
    // this will always return "false"
    cout << ((str1 == str2) ? "true" : "false") << endl;
    
    // Rather do this
    cout << (strcmp(str1, str2) ? "true" : "false") << endl;
}


int strlen2(const char* str) {
  int len = -1;
  char next;
  do {
      len++;
      next = str[len];
  } while (next != '\0');
  return len;
}

void get_the_whole_line() {
    char someText[10];
    cout << "Enter some text: " << endl;
    cin.getline(someText, 10);
    cout << someText << endl;
    cout << "Done" << endl;
}

void converting_the_things() {
    // a = 345
    int a = atoi("345");
    
    // b = 12.54
    float b = atof("12.54");
    
    // c = 0, because # is not digit
    int c = atoi("#2543");
    
    long d = atol("2435243524352");
    
    cout << "a = " << a << " | b = " << b << " | c = " << c;
    cout << " | d = " << d;
    cout << endl;
}

// Vectors
void general_vec_stuff() {
    vector<int> v;
    
    // to add an element:
    v.push_back(0);
    
    // you can then change it;
    v[0] = 1;
    
    // but you can't add new one with [];
    v[3] = 2; // this will do nothing
    
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    cout << "----" << endl;
    
    // use ranged for loop for simplicity
    
    for (auto i : v) {
        cout << i << endl;
    }
    
    cout << "----" << endl;
    
    // You can initialise with a size
    vector<int> vec2(10);
    
    vec2.push_back(1);
    
    for (auto i : vec2) {
        cout << i << endl;
    }
}

void vec_capacity() {
    // capacity is how much space the vector has in memory
    // not same as size
    vector<int> v;
    
    cout << "Capacity: " << v.capacity() << endl;
    
    // if necessary, you can explicitly change capacity
    
    v.reserve(32);
    
    cout << "Capacity: " << v.capacity() << endl;
    
    // you can also resize a vector like so:
    // this removes alles after 20
    v.resize(20);
}

void run() {
    vec_capacity();
}
}
