#include <iostream>
using namespace std;
class Stack {
    int arr[10];
    int top;
public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == sizeof(arr) - 1;
    }

    void push(int x) {
        if (isFull()) {
               cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
                cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() const {
        if (isEmpty()) {
                 cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    void display() const {
        if (isEmpty()) {
                   cout << "Stack is empty\n";
            return;
        }
                cout << "Stack elements: ";
        for (int i = top; i >= 0; --i)
                     cout << arr[i] << " ";
                  cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
     cout << "Popped: " << s.pop() << "\n";
    s.display();
      cout << "Top element: " << s.peek() << "\n";
    return 0;
}