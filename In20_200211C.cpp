#include <iostream>
#define MAX_SIZE 100 

using namespace std;

class Stack {
private:
    int top; 
    int arr[MAX_SIZE]; 

public:
    Stack() { 
        top = -1; 
    }

    void push(int val) {
        if (top == MAX_SIZE - 1) { 
            cout << "Stack overflow" << endl;
            return;
        }
        top++; 
        arr[top] = val; 
    }

    void pop() {
        if (top == -1) { 
            cout << "Stack underflow" << endl;
            return;
        }
        top--; 
    }

    bool isEmpty() {
        return (top == -1); 
    }

    bool isFull() {
        return (top == MAX_SIZE - 1); 
    }

    int stackTop() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Elements in the stack: ";
        for (int i = top; i >= 0; i--) { 
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

