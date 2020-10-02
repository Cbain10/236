#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <locale>

#include "Token.h"
#include "Scanner.h"
#include "Parser.h"
#include "Interpreter.h"


using namespace std;

int main (int argc, char* argv[]){
  string fileName = argv[1];

// Christian you can freaking do this!!
// this little midnight cowboy has got some fight left in him

  Scanner read_n_poo(fileName);
  Parser data(read_n_poo.getTokens());
  data.parse();
  Interpreter inter(data.getDataprogram());
  cout << "Rule Evaluation" << endl;
  inter.evaluateRules();
  cout << endl;
  cout << "Query Evaluation" << endl;
  inter.evaluateQueries();


  return 0;
}
