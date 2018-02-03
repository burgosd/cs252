#include<iostream>
#include "mystack.h"


#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
	string someVar;
	cin >> someVar;
	//cout << someVar << "\n";
	//mystack<int> s1;
	if (someVar == "int") {
		mystack<int> s1;
	}
	else if (someVar == "double") {
		mystack<double> s1;
	}
	else if (someVar == "char") {
		mystack<char> s1;
	}
	else if (someVar == "string") {
		mystack<string> s1;
	}
	
	string var;
	cin >> var;
	while (!cin.eof()) {
		//cout << var << "\n";
		if (var == "size") {
			int sz = s1.size();
			cout << sz << "\n";
		}
		else if (var == "push") {
			int tmp;
			cin >> tmp;
			s1.push(tmp);
		}
		else if (var == "pop") {
			int tmp = s1.pop();
			if (tmp == 0) {
				cout << "error\n";
				cin >> var;
				continue;
			}
			cout << tmp << "\n";
		}
		else if (var == "top") {
			int tmp = s1.top();
			if (tmp == 0) {
				cout << "error\n";
				cin >> var;
				continue;
			}
			cout << tmp << "\n";
		}
		else if (var == "empty") {
			if (s1.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		cin >> var;
	}
	return 0;
}
