#include <iostream>
#include <string>
#include "expr_eval.h"


using namespace std;

int main(){
	string var;
	expr_eval e;
	cin >> var;
	
	while (!cin.eof()) {
		if (var.find("x") != string::npos) {
			cout << "test\n";
			double x;
			cin >> x;
			e.eval(var, x);
		}
		else
			e.eval(var, NULL);
		cin >> var;
	}
  return 0;
}
