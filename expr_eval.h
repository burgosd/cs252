#ifndef EXPR_EVAL_H
#define EXPR_EVAL_H

#include <string>
#include "mystack.h"
#include <math.h>

using namespace std;

class expr_eval{
  private:
        // Declare which ever necessary variables and methods
	mystack<string> op;
	mystack<double> number;
	double math(string s, double x, double y);
  public:
        double eval(string s, double d);
};

double expr_eval::eval(string s, double d) {
	for (int i = 0; i < s.length(); i++) {
		cout << s[i] << "\n";
		if (&s[i] == "(")
			continue;
		else if (&s[i] == "x")
			number.push(d);
		else if (&s[i] == "+" || &s[i] == "-" || &s[i] == "*" || &s[i] == "/" || &s[i] == "^")
			op.push(&s[i]);
		//TODO: figure out how to pull out trig functions and logs from string and put into operation stack.
		else if (&s[i] == ")") {
			string oper = op.pop();
			if (oper == "+" || oper == "-" || oper == "*" || oper == "/" || oper == "^") {
				double y = number.pop();
				double x = number.pop();
				double result = math(oper, y, x);
				number.push(result);
			}
			else if (oper == "sin" || oper == "cos" || oper == "tan" || oper == "log") {
				double y = number.pop();
				double result = math(oper, y, 0);
				number.push(result);
			}
			//number.push(math(oper, number.pop(), number.pop()));
		}
	}
}

double expr_eval::math(string s, double y, double x) {
	if (s == "+") {
		return (x + y);
	}
	else if (s == "*") {
		return (x * y);
	}
	else if (s == "-") {
		return (x - y);
	}
	else if (s == "/") {
		return (x / y);
	}
	else if (s == "^") {
		return pow(x, y);
	}
	else if (s == "sin") {
		return (sin(y));
	}
	else if (s == "cos") {
		return (cos(y));
	}
	else if (s == "tan") {
		return (tan(y));
	}
	else if (s == "log") {
		return (log10(y));
	}
	return 0;
}
#endif
