#ifndef MYQUEUE_H
#define MYQUEUE_H
#define MAX_SIZE 10000

#include <stdio.h>
using namespace std;
template <class T>
class myqueue{
  private:
        // Declare necessary variables and methods
		T* Q;
		int f, r , n;
  public:
        myqueue();
    	void enqueue(T x);
    	T front();
        T dequeue();
    	bool empty();
        int size();
};

template <class T>
myqueue<T>::myqueue()
	: Q(new T[MAX_SIZE]), f(0), r(0), n(0) {}
	
template <class T>
int myqueue<T>::size() {
	return n;
}

template <class T>
bool myqueue<T>::empty() {
	return (n == 0);
}

template <class T>
T myqueue<T>::front() {
	/*if (empty()) {
		return 0;
	}*/
	return Q[f];
}

template <class T>
T myqueue<T>::dequeue() {
	/*if (empty()) {
		return 0;
	}*/
	int tmp = f;
	f = (f + 1) % MAX_SIZE;
	n--;
	return Q[tmp];
}

template <class T>
void myqueue<T>::enqueue(T x) {
	Q[r] = x;
	//cout << "enqueue " << r << " ";
	r = (r + 1) % MAX_SIZE;
	//cout << r << "\n";
	n++;
}

#endif
