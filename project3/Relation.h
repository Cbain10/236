#ifndef RELATION
#define RELATION

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <exception>

#include "Scheme.h"
#include "Tuple.h"

using namespace std;

class Relation {
private:
  string name;
  Scheme attributes;
  set<Tuple> tuples;

public:
  void addRelation(string nam, vector<string> attbs);
  void insert(vector<string> fcts);
  void toString();
  void clearAttributes() {attributes.clear();}
  void selectConstant(string constant, int index);
  void selectVariable(vector<int> repeatingVars);
  void project(map<string, int> variables, vector<int> order = {});
  void rename(map<string, int> variables, bool preserve = false);
  void setTuples(set<Tuple> tpls);
  void setAttributes(Scheme attribs);
  set<Tuple> getTuples();
  Scheme getAttributes() {return attributes;}
  string getName() {return name;}

};

void Relation::addRelation(string nam, vector<string> attbs) {
  name = nam;
  for(unsigned int i = 0; i < attbs.size(); ++i) {
    attributes.push_back(attbs.at(i));
  }
}

void Relation::insert(vector<string> fcts) {
  Tuple tple;
  //cout << fcts.size();
  for (unsigned int i = 0; i < fcts.size(); ++i) {
    tple.push_back(fcts.at(i));
  }
  tuples.insert(tple);
  tple.clear();
}

void Relation::toString() {
  set<Tuple>::iterator it = tuples.begin();

  while (it != tuples.end()){
	// Print the element
    for(unsigned int i = 0; i < attributes.size(); ++i){
      if (i == 0) {
        cout << "  "<< attributes.at(i) << "=" << (*it).at(i);
      } else {
        cout << ", "<< attributes.at(i) << "=" << (*it).at(i);
      }
    }
    cout << endl;
  	 it++;
  }
}

set<Tuple> Relation::getTuples() {
  return tuples;
}

void Relation::selectConstant(string constant, int index) {
  set<Tuple> selectedTupleSet;  // initialize empty tuple set
  // iterate through non-empty tuple set (from chosen relation)
  set<Tuple>::iterator it = tuples.begin();
  while (it != tuples.end()) {
    if ((*it).at(index) == constant) {
      selectedTupleSet.insert(*it);   // insert function defined above
      // tuples with matching constant now added to new selectedTupleSet
    }
    // increment iterator
    it++;
  }
  setTuples(selectedTupleSet);
  selectedTupleSet.clear();   // be able able repeat function and start with empty set
}

void Relation::selectVariable(vector<int> repeatingVars) {
  set<Tuple> selectedTupleSet;
  set<Tuple>::iterator it = tuples.begin();
  vector<string> valueVector;
  while (it != tuples.end()) {
    for (unsigned int i = 0; i < repeatingVars.size(); i++) {
      valueVector.push_back((*it).at(repeatingVars.at(i)));
    }
    bool match = true;
    for (unsigned int i = 0; i < valueVector.size(); i++) {
      if (valueVector.at(0) != valueVector.at(i)) {
        match = false;
      }
    }
    if (match) {
      selectedTupleSet.insert(*it);
    }
    valueVector.clear();
    it++;
  }
  setTuples(selectedTupleSet);
  selectedTupleSet.clear();
}

void Relation::project(map<string, int> variables, vector<int> order) {
  set<Tuple> tupleSet;
  Tuple tup;
  vector<string> dataVector;
  if (order.size() > 0) {
    attributes.clear();
    for (unsigned int i = 0; i < order.size(); i++) {
      map<string, int>::iterator it;
      for (it = variables.begin(); it != variables.end(); it++ ) {
        if (it->second == order.at(i)){
          attributes.push_back(it->first);
        }
      }
    }
    set<Tuple>::iterator tupleIt = tuples.begin();
    while (tupleIt != tuples.end()) {
      for (unsigned int i = 0; i < order.size(); i++) {
        map<string, int>::iterator mapIt;
        for (mapIt = variables.begin(); mapIt != variables.end(); mapIt++) {
          if (mapIt->second == order.at(i)){
            tup.push_back((*tupleIt).at((mapIt->second)));
          }
        }
      }
      tupleIt++;
      // check to see if the new attributes match
        // check tuples to ensure matching
      tupleSet.insert(tup);
      tup.clear();
    }
    setTuples(tupleSet);
    tupleSet.clear();
  } else {
    set<Tuple>::iterator tupleIt = tuples.begin();
    while (tupleIt != tuples.end()) {
      unsigned int j = 0;
      while (j < attributes.size()) {
        map<string, int>::iterator mapIt;
        for (mapIt = variables.begin(); mapIt != variables.end(); mapIt++) {
          unsigned int compare = mapIt->second;
          if (compare == j) {
            tup.push_back((*tupleIt).at(mapIt->second));
          }
        }
        j++;
      }
      tupleIt++;
      tupleSet.insert(tup);
      tup.clear();
    }
    setTuples(tupleSet);
    tupleSet.clear();
  }
}

void Relation::rename(map<string, int> variables, bool preserve) {
  Scheme newAttbs;
  if (preserve == true) {
    for (unsigned int i = 0; i < attributes.size(); ++i){
      map<string, int>::iterator it1;
      for ( it1 = variables.begin(); it1 != variables.end(); it1++ ){
        unsigned int comp = it1->second;
        if (comp == i){
          attributes.at(i) = it1->first;
          }
        }
      }
    return;
  }

  for (unsigned int i = 0; i < attributes.size(); ++i){
    map<string, int>::iterator it1;
    for ( it1 = variables.begin(); it1 != variables.end(); it1++ ){
      unsigned int comp = it1->second;
      if (comp == i){
        newAttbs.push_back(it1->first);
      }

    }
  }
  setAttributes(newAttbs);
  newAttbs.clear();
}

void Relation::setTuples(set<Tuple> tpls) {
  set<Tuple>::iterator it = tpls.begin();
  tuples.clear();   // clear 'orginal set'
  while (it != tpls.end()) {
    tuples.insert(*it);
    it++;
  }
}

void Relation::setAttributes(Scheme attbs) {
  attributes.clear();
  for (unsigned int i = 0; i < attbs.size(); i++) {
    attributes.push_back(attbs.at(i));
  }
}

#endif
