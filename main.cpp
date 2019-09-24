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
    
    string userInput;
    cout << "Enter Filename:" << endl;
    cin >> userInput;
    Scanner scanFile(userInput);
    scanFile.Scan(userInput);
    
    
    
    cout << "END" << endl;

    
//    string filename = argv[1];
//    Scanner scanFile(filename);
//    vector<Token> tokenVector = scanFile.getAllTokens();
//    Scanner file;
//    file.Scan(inFile);
    
//    ifstream inFile;
//
//    //Done in Scanner Class
//    inFile.open("inputText.txt");
//    if (!inFile) {
//        cout << "The file had a problem opening." << endl;
//        exit(1);
//    }
//
//    string tempString = "";
//    vector<Token> myVector;
//
//    do {
//        // ID or Keywords
//        if (isalpha(inFile.peek())) {
//            do {
//                tempString.push_back(inFile.get());
//            } while ((inFile.peek() != '\n') && (inFile.peek() != ' ') && (inFile.peek() != '\t') && (isalnum(inFile.peek())));
////            if ((inFile.peek() == ' ') || (inFile.peek() == '\t') || (inFile.peek() == '\n')) {
////                inFile.get();
////            }
//            // Keywords
//            if (tempString == "Schemes") {
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "SCHEMES";
//                tokenObject->toString();
////                myVector.push_back(tokenObject);
//            }
//            else if (tempString == "Facts") {
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "FACTS";
//                tokenObject->toString();
//            }
//            else if (tempString == "Rules") {
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "RULES";
//                tokenObject->toString();
//            }
//            else if (tempString == "Queries") {
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "QUERIES";
//                tokenObject->toString();
//            }
//            else {
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "ID";
//                tokenObject->toString();
//            }
//        }
//
//        // MLComment and Single-Line Comment
//        else if (inFile.peek() == '#') {
//            tempString.push_back(inFile.get());
//            if (inFile.peek() == '|') {
//                do {
//                    tempString.push_back(inFile.get());
//                } while ((inFile.peek() != '|') && (inFile.peek() != EOF));
//                if (inFile.peek() == '|') {
//                    tempString.push_back(inFile.get());
//                    if (inFile.peek() == '#') {
//                        tempString.push_back(inFile.get());
//                    }
//                }
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "COMMENT";
//                tokenObject->toString();
//            }
//            // Single-Line Comment
//            else {
//                do {
//                    tempString.push_back(inFile.get());
//                } while ((inFile.peek() != '\n') && (inFile.peek() != EOF));
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "COMMENT";
//                tokenObject->toString();
//            }
//        }
//
//        // STRING
//        else if (inFile.peek() == '\'') {
//            bool goodApostrophe = false;
//            bool goodString = false;
//            do {
//                tempString.push_back(inFile.get());
//                if (inFile.peek() == '\'') {
//                    tempString.push_back(inFile.get());
//                    if (inFile.peek() == '\'') {
//                        goodApostrophe = true;
//                    } else {
//                        goodString = true;
//                    }
//                }
//            } while ((inFile.peek() != EOF) && (!goodString));
//            if (goodString) {
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "STRING";
//                tokenObject->toString();
//            } else {
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "UNDEFINED";
//                tokenObject->toString();
//            }
//        }
//
//        // symbols or UNDEFINED
//        else {
//            if (inFile.peek() == ',') {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "COMMA";
//                tokenObject->toString();
//                // COMMA
//            }
//            else if (inFile.peek() == '.') {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "PERIOD";
//                tokenObject->toString();
//                // PERIOD
//            }
//            else if (inFile.peek() == '?') {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "Q_MARK";
//                tokenObject->toString();
//                // Q_MARK
//            }
//            else if (inFile.peek() == '(') {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "LEFT_PAREN";
//                tokenObject->toString();
//                // LEFT_PAREN
//            }
//            else if (inFile.peek() == ')') {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "RIGHT_PAREN";
//                tokenObject->toString();
//                // RIGHT_PAREN
//            }
//            else if (inFile.peek() == ':') {
//                tempString.push_back(inFile.get());
//                bool isColonDash = false;
//                if (inFile.peek() == '-') {
//                    tempString.push_back(inFile.get());
//                    Token* tokenObject = new Token();
//                    tokenObject->tokenValue = tempString;
//                    tokenObject->tokenType = "COLON_DASH";
//                    tokenObject->toString();
//                    isColonDash = true;
//                    // COLON_DASH
//                }
//                if (!isColonDash) {
//                    Token* tokenObject = new Token();
//                    tokenObject->tokenValue = tempString;
//                    tokenObject->tokenType = "COLON";
//                    tokenObject->toString();
//                    // COLON
//                }
//            }
//            else if (inFile.peek() == '*') {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "MULTIPLY";
//                tokenObject->toString();
//                // MULTIPLY
//            }
//            else if (inFile.peek() == '+') {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "ADD";
//                tokenObject->toString();
//                // ADD
//            } else if ((inFile.peek() == ' ') || (inFile.peek() == '\t') || (inFile.peek() == '\n')) {
//                tempString.push_back(inFile.get());
//            }
//            else {
//                tempString.push_back(inFile.get());
//                Token* tokenObject = new Token();
//                tokenObject->tokenValue = tempString;
//                tokenObject->tokenType = "UNDEFINED";
//                tokenObject->toString();
//                // UNDEFINED
//            }
//        }
//        // clear tempString after every iteration
//        tempString = "";
//    } while (inFile.peek() != EOF);
//
//
//    // will need to keep track of a variable starting line and also current line.
//    // at beginning of every function call, starting line should == current line.
//
//    // initialize empty vector of Token objects
//    // for all cout calls, create new Token object, push it to the vector
//        // next iteration the object will be recreated, but the old one will still be in the TokenVector
//
//    // pushback token into vector
//    // change print toString() to iterated through vector
//
//
//    inFile.close();
//
    
    return 0;
}
