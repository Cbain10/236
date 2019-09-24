//
//  Token.cpp
//  Project 1
//
//  Created by Christian Bain on 9/17/19.
//  Copyright © 2019 Christian Bain. All rights reserved.
//

#include <iostream>
#include <string>
#include "Token.hpp"

using namespace std;

void Token::toString() {
    // change to iterate through the vector of Tokens
    cout << "(" << tokenType << ",\"" << tokenValue << "\"," << startLine << ")" << endl;
};
