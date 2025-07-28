#include <iostream>
#include <stack>
using namespace std;

// Function to check if parentheses are balanced
bool isBalanced(string expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false; // Unmatched closing parenthesis
            }

            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched pair
            }

            s.pop(); // Pop the matching opening parenthesis
        }
    }

    return s.empty(); // If stack is empty, parentheses are balanced
}

int main() {
    string expression;
    cout << "Enter an expression with parentheses: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "The parentheses are balanced." << endl;
    } else {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}
