//
//  Token.hpp
//  Project 1
//
//  Created by Christian Bain on 9/17/19.
//  Copyright © 2019 Christian Bain. All rights reserved.
//

#ifndef Token_hpp
#define Token_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Token {
public:
    Token() {
    };
    string tokenType;
    string tokenValue;
    int startLine;
    void toString();
protected:
};

#endif /* Token_hpp */
