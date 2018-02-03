#ifndef EXPR_EVAL_H
#define EXPR_EVAL_H

#include <string>
#include "mystack.h"

using namespace std;

class expr_eval{
  private:
        // Declare which ever necessary variables and methods
		mystack<string> s1;
		mystack<double> n1;
  public:
        double eval(string s, double d);
};

double expr_eval::eval(string s, double d) {
	if (d == NULL) {
		for (int i = 0; i < s.length(); i++) {
			cout << s[i] << "\n";
		}
	}
}
#endif
