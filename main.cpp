//
//  main.cpp
//  Project 1
//
//  Created by Christian Bain on 9/17/19.
//  Copyright © 2019 Christian Bain. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

#include "Token.hpp"
#include "Scanner.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    
    // input from command line
    // change name to "lab1"
    // Valgrind? Need to go through and delete pointers to avoid memory leaks
    
    string userInput;
    cout << "Enter Filename:" << endl;
    cin >> userInput;
    
    Scanner scanFile(userInput);
    scanFile.Scan(userInput);
    
    return 0;
}
