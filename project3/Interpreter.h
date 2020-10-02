#ifndef INTERPRETER
#define INTERPRETER

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <exception>
#include <map>

#include "DatalogProgram.h"
#include "Database.h"

using namespace std;

class Interpreter {
private:
  DatalogProgram oldData;
  vector<Rule> rulez;
  vector<Predicate> schemez;
  vector<Predicate> factz;
  vector<Predicate> queriez;
  Database db;
public:
   Interpreter(DatalogProgram data);
   void evaluateSingleQuery(Predicate queeery);
   void evaluateQueries();
};

Interpreter::Interpreter(DatalogProgram data) {
  oldData = data;
  rulez = data.getRules();
  schemez = data.getSchemes();
  factz = data.getFacts();
  queriez = data.getQueries();
  Relation rel;
  // Database db;
  //Setting up all relations
  for (unsigned int i = 0; i < schemez.size(); ++i){
     rel.addRelation((schemez.at(i)).getId(), (schemez.at(i)).getParams());
     db.insert(pair<string,Relation>(rel.getName(), rel));
     rel.clearAttributes();
  }
  //filling relations
  for (unsigned int i= 0; i <factz.size(); ++i) {
    (db.find((factz.at(i)).getId())->second).insert((factz.at(i)).getParams());
  }

// // Printing Relations in Database
  // map<string, Relation>::iterator it;
  //
  // for ( it = db.begin(); it != db.end(); it++ )
  // {
  //     cout << it->first << ':' << endl;
  //     (it->second).toString();
  //     cout << endl;
  // }
// // END print section
}

void Interpreter::evaluateSingleQuery(Predicate queeery) {
  // cout << "Begin single query" << endl;
  vector<string> parameterz = queeery.getParams();
  // cout << "right before problem" << endl;
  // cout << queeery.getId() << endl;
  Relation newRelation = db.find(queeery.getId())->second;
  // cout << "before for-loop" << endl;
  set<Tuple> tuuples = newRelation.getTuples();
  Scheme tempAttributes = newRelation.getAttributes();
  map<string, vector<int>> constantsMap;
  map<string, int> variables1;
  map<string, vector<int>> variables;
  vector<int> repeatingVariables;


  for (unsigned int i = 0; i < parameterz.size(); i++) {
    if ((parameterz.at(i)).front() == '\'') {   // will check for CONSTANTS
      // cout << "making new relation" << endl;
      newRelation.selectConstant(parameterz.at(i), i);
      if (constantsMap.find(parameterz.at(i)) != constantsMap.end()) {
        constantsMap[parameterz.at(i)].push_back(i);
      } else {
        constantsMap.insert(pair<string, vector<int>>(parameterz.at(i), repeatingVariables));
        constantsMap[parameterz.at(i)].push_back(i);
      }
    } else {                                    // will check for VARIABLES
        variables1.insert(pair<string, int>(parameterz.at(i), i));
        if (variables.find(parameterz.at(i)) != variables.end()) {
          variables[parameterz.at(i)].push_back(i);
        } else {
          variables.insert(pair<string, vector<int>>(parameterz.at(i), repeatingVariables));
        }
    }
  }
  // cout << "half-way through single query" << endl;
  // end for-loop
  map<string, vector<int>>::iterator mapIterator;
  for (mapIterator = variables.begin(); mapIterator != variables.end(); mapIterator++) {
      // iterate through map of strings and vector<int>
    if ((mapIterator->second).size() > 1) {
      for (unsigned int i = 0; i < (mapIterator->second).size(); i++) {
        repeatingVariables.push_back((mapIterator->second).at(i));
      }
      newRelation.selectVariable(repeatingVariables);
      repeatingVariables.clear();
    }
  }
    newRelation.project(variables1);
    newRelation.rename(variables1);
    queeery.toString();
    cout << "?";
    if ((newRelation.getTuples()).size() > 0) {   // prints YES(#)
      cout << " Yes(" << (newRelation.getTuples()).size() << ")" << endl;
      if (variables1.size() > 0) {
        newRelation.toString();
      }
    } else {  // prints NO
      cout << "No" << endl;
    }
  // cout << "End single query" << endl;
}

void Interpreter::evaluateQueries() {
    // cout << "YOUR MOM" << endl;
  for (unsigned int i = 0; i < queriez.size(); i++) {
    // cout << "NAMED SHARON" << endl;
    // (queriez.at(i)).toString();
    // cout << endl;
    evaluateSingleQuery(queriez.at(i));
    // cout << endl;
    // cout << "GOES TO COLLEGE" << endl;
  }
}



// hard code this shiz
// void Interpreter::checkIsConstant() {
//   bool isConstant;
//   for (unsigned int i = 0; i < queriez.size(); i++) {
//     isConstant = false;
//     vector<string> tempQuery = (queriez.at(i)).getParams();
//     for (unsigned int j = 0; j < ((queriez.at(i)).getParams()).size(); j++) {
//       if ((tempQuery.at(j)).at(0) == '\'') {
//         // (((queriez.at(i)).getParams()).at(j)).front == '\'')
//         isConstant = true;
//       }
//       else {
//         isConstant = false;
//       }
//       (queriez.at(i)).addQueryConstant(isConstant);
//     }
//   }
//   // checkIsConstant seems to be working
//   // not implemented
// }

#endif
