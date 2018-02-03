#include <iostream>
#include <string>
#include "expr_eval.h"


using namespace std;

int main(){
	string someVar;
	expr_eval e;
	cin >> someVar;
	
	e.eval(someVar, NULL);
  return 0;
}
