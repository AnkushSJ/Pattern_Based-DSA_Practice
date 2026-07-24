#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int size;

public:
    Stack(int s = 10) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top = top + 1;
        arr[top] = x;
    }

    int pop() {
        if (top == -1) return -1; // Stack is empty
        int x = arr[top];
        top = top - 1;
        return x;
    }

    int getTop() {
        if (top == -1) return -1;
        return arr[top];
    }

    int getSize() {
        return top + 1;
    }
};