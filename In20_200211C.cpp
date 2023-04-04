#include <iostream>
#include <chrono>
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
};


int main() {
    Stack s;

    auto start = chrono::high_resolution_clock::now();
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken for specific push operations using array: " << duration.count() << " microseconds" << endl;
    
    return 0;
}




// Using Linked list
struct Node {
    int data; 
    Node* next; 
};


class Stack {
private:
    Node* top; 
public:
    Stack() {
        top = NULL; 
    }

    
    void push(int val) {
        Node* newNode = new Node; 
        newNode->data = val; 
        newNode->next = top; 
        top = newNode; 
    }

    
    void pop() {
        if (top == NULL) { 
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top; 
        top = top->next; 
        delete temp; 
    }

    
    bool isEmpty() {
        return top == NULL; 
    }

    
    bool isFull() {
        return false; 
    }

    
    int stackTop() {
        if (top == NULL) { 
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data; 
    }

    
    void display() {
        if (top == NULL) { 
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top; 
        while (temp != NULL) { 
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Example usage




int main() {
    Stack s;

    auto start = chrono::high_resolution_clock::now(); // start the timer
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto end = chrono::high_resolution_clock::now(); // end the timer
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // calculate duration in microseconds
    cout << "Time taken for specific push operations using linked list: " << duration.count() << " microseconds" << endl;
    
    return 0;
}
