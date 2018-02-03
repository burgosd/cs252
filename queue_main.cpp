#include<iostream>
#include "myqueue.h"

using namespace std;

template <class T>
int process(myqueue<T> q1) {
	string var;
	cin >> var;
	while (!cin.eof()) {
		//cout << var << "\n";
		if (var == "size") {
			int sz = q1.size();
			cout << sz << "\n";
		}
		else if (var == "enqueue") {
			int tmp;
			cin >> tmp;
			q1.enqueue(tmp);
		}
		else if (var == "dequeue") {
			if (q1.empty()) {
				cout << "error\n";
				cin >> var;
				continue;
			}
			else {
				int tmp = q1.dequeue();
				cout << tmp << "\n";
			}
		}
		else if (var == "front") {
			if (q1.empty()) {
				cout << "error\n";
				cin >> var;
				continue;
			}
			else {
				int tmp = q1.front();
				cout << tmp << "\n";
			}
		}
		else if (var == "empty") {
			if (q1.empty()) {
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
	myqueue<int> q1;
	if (someVar == "int") {
		myqueue<int> q1;
		process(q1)
	}
	else if (someVar == "double") {
		myqueue<double> q1;
		process(q1)
	}
	else if (someVar == "char") {
		myqueue<char> q1;
		process(q1)
	}
	else if (someVar == "string") {
		myqueue<string> q1;
		process(q1)
	}
	
	return 0;
}
