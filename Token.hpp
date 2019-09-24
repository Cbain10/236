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

//enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, FILEEND};
//
//TokenType tokenType = COMMA;

//tokenToString();

#endif /* Token_hpp */
