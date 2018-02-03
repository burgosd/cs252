#ifndef MYSTACK_H
#define MYSTACK_H
#define MAX_SIZE 10000

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

template <class T>
class mystack{
  private:
        // Declare necessary variables and methods
		T* S;
		//int capacity;
		int t;
  public:
		//mystack(int cap = defSize);
        mystack();
        void push(T x);
        T top();
        T pop();
        bool empty();
        int size();
};

template <class T>
//mystack<T>::mystack(int cap)
	//: S(new T[cap]), capacity(cap), t(-1) {}
mystack<T>::mystack()
	: S(new T[MAX_SIZE]), t(-1) {}
	
template <class T>
int mystack<T>::size() {
	return (t + 1);
}

template <class T>
bool mystack<T>::empty() {
	return (t < 0);
}

template <class T>
T mystack<T>::top() {
	/*if (empty()) {
		//cout<<"top of empty stack\n";
		return nullptr;
	}*/
	return S[t];
}

template <class T>
void mystack<T>::push(T x) {
	//if (size() == capacity) {
	//	cout<<"not enough space\n";
	//	return;
	//}
	S[++t] = x;
}

template <class T>
T mystack<T>::pop() {
	/*if (empty()) {
		//cout<<"pop form empty stack\n";
		return nullptr;
	}*/
	return S[t--];
}
#endif
