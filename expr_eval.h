#ifndef EXPR_EVAL_H
#define EXPR_EVAL_H

#include <string>
#include "mystack.h"
#include <sstream>
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
	string tmp = "";
	for (int i = 0; i < s.length() + 1; i++) {
		//cout << s[i] << "\n";
		if (i == s.length() && tmp != "") {
			//push the number in tmp to stack
			stringstream t(tmp);
			double j = 0;
			t >> j;
			//cout << j << "\n";
			number.push(j);
			tmp = "";
		}
		else if (s[i] == '(') {
			op.push("(");
		}
		else if (s[i] == 'x') {
			number.push(d);
		}
		//else if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
		else if (isdigit(s[i])) {
			tmp += s[i];
			//cout << s[i];
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
			if (s[i] == '+')
				op.push("+");
			else if (s[i] == '-')
				op.push("-");
			else if (s[i] == '*')
				op.push("*");
			else if (s[i] == '/')
				op.push("/");
			else if (s[i] == '^')
				op.push("^");
			//push the number in tmp to stack
			if (tmp != "") {
				stringstream t(tmp);
				double j = 0;
				t >> j;
				//cout << j << "\n";
				number.push(j);
				tmp = "";
			}
		}
		//TODO: figure out how to pull out trig functions and logs from string and put into operation stack.
		// try using strstr to find the trig functions and logs
		else if (s[i] == 's' || s[i] == 'c' || s[i] == 't' || s[i] == 'l') {
			if (s[i+1] == 'i' && s[i+2] == 'n')
				op.push("sin");
			else if (s[i+1] == 'o' && s[i+2] == 's')
				op.push("cos");
			else if (s[i+1] == 'a' && s[i+2] == 'n')
				op.push("tan");
			else if (s[i+1] == 'o' && s[i+2] == 'g')
				op.push("log");
			i += 2;
			if (tmp != "") {
				stringstream t(tmp);
				double j = 0;
				t >> j;
				//cout << j << "\n";
				number.push(j);
				tmp = "";
			}
		}
		else if (s[i] == ')') {
			if (tmp != "") {
				stringstream t(tmp);
				double j = 0;
				t >> j;
				//cout << j << "\n";
				number.push(j);
				tmp = "";
			}
			while (op.top() != "(") {
				string oper = op.pop();
				if (oper == "+" || oper == "-" || oper == "*" || oper == "/" || oper == "^") {
					double y = number.pop();
					double x = number.pop();
					double result = math(oper, y, x);
					number.push(result);
				}
			//number.push(math(oper, number.pop(), number.pop()));
			}
			if (op.top() == "(") {
				op.pop();
				if (op.top() == "sin" || op.top() == "cos" || op.top() == "tan" || op.top() == "log") {
					string oper = op.pop();
					double y = number.pop();
					double result = math(oper, y, 0);
					number.push(result);
				}
			}
		}
	}
	
	while (!op.empty()) {
		string oper = op.pop();
		if (oper == "+" || oper == "-" || oper == "*" || oper == "/" || oper == "^") {
			double y = number.pop();
			double x = number.pop();
			double result = math(oper, y, x);
			number.push(result);
		}
	}
	//cout << number.size() << "\n";
	cout << number.pop() << "\n";
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
		double tmp = (y * M_PI) / 180;
		return (sin(tmp));
	}
	else if (s == "cos") {
		double tmp = (y * M_PI) / 180;
		return (cos(tmp));
	}
	else if (s == "tan") {
		double tmp = (y * M_PI) / 180;
		return (tan(tmp));
	}
	else if (s == "log") {
		return (log10(y));
	}
	return 0;
}
#endif
