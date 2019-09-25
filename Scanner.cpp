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
        exit(0);
    }
    
    string tempString = "";
    int currentLine = 1;
    int startingLine = 1;
    vector<Token*> myVector;
    
    do {
        if (inFile.peek() == '\n') {
            currentLine++;
        }
        
        // ID or Keywords
        if (isalpha(inFile.peek())) {
            startingLine = currentLine;
            do {
                tempString.push_back(inFile.get());
            } while ((inFile.peek() != '\n') && (inFile.peek() != ' ') && (inFile.peek() != '\t') && (isalnum(inFile.peek())));
            // Keywords
            if (tempString == "Schemes") {
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "SCHEMES";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            }
            else if (tempString == "Facts") {
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "FACTS";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            }
            else if (tempString == "Rules") {
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "RULES";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            }
            else if (tempString == "Queries") {
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "QUERIES";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            }
            else {
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "ID";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            }
        }
        
        // MLComment and Single-Line Comment
        else if (inFile.peek() == '#') {
            startingLine = currentLine;
            bool goodComment = false;
            tempString.push_back(inFile.get());
            if (inFile.peek() == '|') {
                do {
                    if (inFile.peek() == '\n') {
                        currentLine++;
                    }
                    tempString.push_back(inFile.get());
                } while ((inFile.peek() != '|') && (inFile.peek() != EOF));
                
                // do while loop
                // do
                //      if peek == '|'
                //          pushback
                //
                
                if (inFile.peek() == '|') {
                    tempString.push_back(inFile.get());
                    if (inFile.peek() == '#') {
                        tempString.push_back(inFile.get());
                        goodComment = true;
                    } else {
                        do {
                            if (inFile.peek() == '\n') {
                                currentLine++;
                            }
                            tempString.push_back(inFile.get());
                        } while (inFile.peek() != EOF);
                    }
                }
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                
                if (goodComment) {
                    tokenObject->tokenType = "COMMENT";
                } else {
                    tokenObject->tokenType = "UNDEFINED";
                }
                tokenObject->startLine = startingLine;
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
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            }
        }
        
        // STRING
        else if (inFile.peek() == '\'') {
            //            bool goodApostrophe = false;
            bool goodString = false;
            startingLine = currentLine;
            do {
                if (inFile.peek() == '\n') {
                    currentLine++;
                }
                tempString.push_back(inFile.get());
                if (inFile.peek() == '\'') {
                    tempString.push_back(inFile.get());
                    if (inFile.peek() == '\'') {
                        //                        goodApostrophe = true;
                    } else {
                        goodString = true;
                    }
                }
            } while ((inFile.peek() != EOF) && (!goodString));
            if (goodString) {
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "STRING";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            } else {
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "UNDEFINED";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
            }
        }
        
        // symbols or UNDEFINED
        else {
            startingLine = currentLine;
            if (inFile.peek() == ',') {
                tempString.push_back(inFile.get());
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "COMMA";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
                // COMMA
            }
            else if (inFile.peek() == '.') {
                tempString.push_back(inFile.get());
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "PERIOD";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
                // PERIOD
            }
            else if (inFile.peek() == '?') {
                tempString.push_back(inFile.get());
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "Q_MARK";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
                // Q_MARK
            }
            else if (inFile.peek() == '(') {
                tempString.push_back(inFile.get());
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "LEFT_PAREN";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
                // LEFT_PAREN
            }
            else if (inFile.peek() == ')') {
                tempString.push_back(inFile.get());
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "RIGHT_PAREN";
                tokenObject->startLine = startingLine;
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
                    tokenObject->startLine = startingLine;
                    myVector.push_back(tokenObject);
                    isColonDash = true;
                    // COLON_DASH
                }
                if (!isColonDash) {
                    Token* tokenObject = new Token();
                    tokenObject->tokenValue = tempString;
                    tokenObject->tokenType = "COLON";
                    tokenObject->startLine = startingLine;
                    myVector.push_back(tokenObject);
                    // COLON
                }
            }
            else if (inFile.peek() == '*') {
                tempString.push_back(inFile.get());
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "MULTIPLY";
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
                // MULTIPLY
            }
            else if (inFile.peek() == '+') {
                tempString.push_back(inFile.get());
                Token* tokenObject = new Token();
                tokenObject->tokenValue = tempString;
                tokenObject->tokenType = "ADD";
                tokenObject->startLine = startingLine;
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
                tokenObject->startLine = startingLine;
                myVector.push_back(tokenObject);
                // UNDEFINED
            }
        }
        // clear tempString after every iteration
        tempString = "";
    } while (inFile.peek() != EOF);
    
    //    currentLine++;
    startingLine = currentLine;
    Token* tokenObject = new Token();
    tokenObject->tokenValue = "";
    tokenObject->tokenType = "EOF";
    tokenObject->startLine = startingLine;
    myVector.push_back(tokenObject);
    
    // print the vector
    for (unsigned int i = 0; i < myVector.size(); i++) {
        myVector.at(i)->toString();
    }
    
    cout << "Total Tokens = " << myVector.size() << endl;
    
    inFile.close();
}
