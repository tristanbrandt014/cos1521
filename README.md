# COS1512

This repository contains my code for the COS1512 module at the University of South Africa (UNISA).

## Requirements
 - Xcode
 - [xcodegen](https://github.com/yonaskolb/XcodeGen)

## Usage
1. Clone the repository
2. Run `xcodegen` to generate the Xcode project
3. Open the generated `COS1512.xcodeproj` file

## Structure

 - Chapters and module content live in the `src/chapters` directory. 
 - Each chapter has its own directory with a `chapter{n}.cpp` file that contains the code for that chapter, where `n` is the chapter number. 
 - Each main file has a package declaration at the top of the file that corresponds to the chapter number. 
 - Each namespace will have a `run` function that will be called from `src/main.cpp`.

E.g. `src/chapters/chapter1/chapter1.cpp`:
```cpp
#include <iostream>

namespace chapter1 {
    void run() {
        std::cout << "Hello, World!" << std::endl;
    }
}
```
