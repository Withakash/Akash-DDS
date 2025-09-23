#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string& expr) {
    stack<int> s;
    for (char ch : expr) {
        if (isspace(ch)) continue;
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expr = "3 4 + 5 *"; // Example postfix expression
    cout << "Result: " << evaluatePostfix(expr)<<"  is Evalution" << endl;
    return 0;
}