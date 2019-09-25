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
    
    string userInput = argv[1];
    cout << userInput << endl;

//    string userInput = "test_case2.txt";
    
    Scanner scanFile(userInput);
    scanFile.Scan(userInput);
    
    return 0;
}
