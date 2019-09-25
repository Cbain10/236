//
//  Scanner.hpp
//  Project 1
//
//  Created by Christian Bain on 9/17/19.
//  Copyright © 2019 Christian Bain. All rights reserved.
//

#ifndef Scanner_hpp
#define Scanner_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Token.hpp"

using namespace std;

class Scanner {
    
public:
    Scanner(string filename);
    vector<Token> getAllTokens();
    void Scan(string fileName);
protected:
};


#endif /* Scanner_hpp */
