#include<iostream>
#include "mystack.h"


#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

template <class T>
int process(mystack<T> s1) {
	//mystack<T> s1;
	string var;
	cin >> var;
	while (!cin.eof()) {
		//cout << var << "\n";
		if (var == "size") {
			int sz = s1.size();
			cout << sz << "\n";
		}
		else if (var == "push") {
			T tmp;
			cin >> tmp;
			s1.push(tmp);
		}
		else if (var == "pop") {
			if (s1.empty()) {
				//cout << "pop size is " << s1.size() << "\n";
				cout << "error\n";
				cin >> var;
				continue;
			}else {
				T tmp = s1.pop();
				cout << tmp << "\n";
			}
		}
		else if (var == "top") {
			if (s1.empty()) {
				cout << "top size is " << s1.size() << "\n";
				cout << "error\n";
				cin >> var;
				continue;
			}else {
				T tmp = s1.top();
				cout << tmp << "\n";
			}
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

int main(){
	string someVar;
	cin >> someVar;
	//cout << someVar << "\n";
	//mystack<int> s1;
	if (someVar == "int") {
		mystack<int> s1;
		process(s1);
	}
	else if (someVar == "double") {
		mystack<double> s1;
		process(s1);
	}
	else if (someVar == "char") {
		mystack<char> s1;
		process(s1);
	}
	else if (someVar == "string") {
		mystack<string> s1;
		process(s1);
	}
	return 0;
}
