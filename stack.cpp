#include <iostream>
using namespace std;

class Stack {
private:
    static const int CAPACITY = 5;
    int items[CAPACITY];
    int topIndex;

public:
    Stack() : topIndex(-1) {}

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == CAPACITY - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow: cannot push " << value << ".\n";
            return;
        }
        items[++topIndex] = value;
        cout << value << " pushed onto the stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: cannot pop from an empty stack.\n";
            return;
        }
        cout << items[topIndex--] << " popped from the stack.\n";
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty; no top element.\n";
            return;
        }
        cout << "Top element: " << items[topIndex] << '\n';
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; --i) {
            cout << items[i] << ' ';
        }
        cout << '\n';
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.peek();
    stack.pop();
    stack.display();
    return 0;
}
