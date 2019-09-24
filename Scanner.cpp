//
//  Scanner.cpp
//  Project 1
//
//  Created by Christian Bain on 9/17/19.
//  Copyright © 2019 Christian Bain. All rights reserved.
//

#include "Scanner.hpp"

Scanner::Scanner(string filename){};

void Scanner::Scan(string fileName) {
    
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        cout << "The file had a problem opening." << endl;
        exit(1);
    }
    
    string tempString = "";
    int currentLine;
    int startingLine;
    vector<Token*> myVector;
    
        do {
            // ID or Keywords
            if (isalpha(inFile.peek())) {
                do {
                    tempString.push_back(inFile.get());
                } while ((inFile.peek() != '\n') && (inFile.peek() != ' ') && (inFile.peek() != '\t') && (isalnum(inFile.peek())));
    //            if ((inFile.peek() == ' ') || (inFile.peek() == '\t') || (inFile.peek() == '\n')) {
    //                inFile.get();
    //            }
                // Keywords
                if (tempString == "Schemes") {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "SCHEMES";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
                else if (tempString == "Facts") {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "FACTS";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
                else if (tempString == "Rules") {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "RULES";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
                else if (tempString == "Queries") {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "QUERIES";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
                else {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "ID";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
            }
    
            // MLComment and Single-Line Comment
            else if (inFile.peek() == '#') {
                tempString.push_back(inFile.get());
                if (inFile.peek() == '|') {
                    do {
                        tempString.push_back(inFile.get());
                    } while ((inFile.peek() != '|') && (inFile.peek() != EOF));
                    if (inFile.peek() == '|') {
                        tempString.push_back(inFile.get());
                        if (inFile.peek() == '#') {
                            tempString.push_back(inFile.get());
                        }
                    }
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "COMMENT";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
                // Single-Line Comment
                else {
                    do {
                        tempString.push_back(inFile.get());
                    } while ((inFile.peek() != '\n') && (inFile.peek() != EOF));
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "COMMENT";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
            }
    
            // STRING
            else if (inFile.peek() == '\'') {
                bool goodApostrophe = false;
                bool goodString = false;
                do {
                    tempString.push_back(inFile.get());
                    if (inFile.peek() == '\'') {
                        tempString.push_back(inFile.get());
                        if (inFile.peek() == '\'') {
                            goodApostrophe = true;
                        } else {
                            goodString = true;
                        }
                    }
                } while ((inFile.peek() != EOF) && (!goodString));
                if (goodString) {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "STRING";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                } else {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "UNDEFINED";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                }
            }
    
            // symbols or UNDEFINED
            else {
                if (inFile.peek() == ',') {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "COMMA";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // COMMA
                }
                else if (inFile.peek() == '.') {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "PERIOD";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // PERIOD
                }
                else if (inFile.peek() == '?') {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "Q_MARK";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // Q_MARK
                }
                else if (inFile.peek() == '(') {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "LEFT_PAREN";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // LEFT_PAREN
                }
                else if (inFile.peek() == ')') {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "RIGHT_PAREN";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // RIGHT_PAREN
                }
                else if (inFile.peek() == ':') {
                    tempString.push_back(inFile.get());
                    bool isColonDash = false;
                    if (inFile.peek() == '-') {
                        tempString.push_back(inFile.get());
                        Token* tokenObject = new Token();
                        tokenObject->tokenValue = tempString;
                        tokenObject->tokenType = "COLON_DASH";
//                        tokenObject->toString();
                        myVector.push_back(tokenObject);
                        isColonDash = true;
                        // COLON_DASH
                    }
                    if (!isColonDash) {
                        Token* tokenObject = new Token();
                        tokenObject->tokenValue = tempString;
                        tokenObject->tokenType = "COLON";
//                        tokenObject->toString();
                        myVector.push_back(tokenObject);
                        // COLON
                    }
                }
                else if (inFile.peek() == '*') {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "MULTIPLY";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // MULTIPLY
                }
                else if (inFile.peek() == '+') {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "ADD";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // ADD
                } else if ((inFile.peek() == ' ') || (inFile.peek() == '\t') || (inFile.peek() == '\n')) {
                    tempString.push_back(inFile.get());
                }
                else {
                    tempString.push_back(inFile.get());
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "UNDEFINED";
//                    tokenObject->toString();
                    myVector.push_back(tokenObject);
                    // UNDEFINED
                }
            }
            // clear tempString after every iteration
            tempString = "";
        } while (inFile.peek() != EOF);
    
    // print the vector
    for (int i = 0; i < myVector.size(); i++) {
        myVector.at(i)->toString();
    }
    
        // will need to keep track of a variable starting line and also current line.
        // at beginning of every function call, starting line should == current line.
    
        // initialize empty vector of Token objects
        // for all cout calls, create new Token object, push it to the vector
            // next iteration the object will be recreated, but the old one will still be in the TokenVector
    
        // pushback token into vector
        // change print toString() to iterated through vector
    
    
        inFile.close();
    
    inFile.close();
}
