//Reversing a vector using Stack
#include <iostream>
#include <vector>
using namespace std;
// Implementing the Custom Stack
class Stack {
private:
    int top;
    int capacity;
    int* arr;
public:
    // Constructor to initialize the stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];  // Dynamic memory allocation
        top = -1;  // Stack is initially empty
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void push(int value) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }
    // Pop operation
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        return arr[top--];
    }
    // Peek operation
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    // Check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }
};
// Function to reverse the vector
void reverseVector(vector<int>& vec) {
    int n = vec.size();
    Stack s(n);  // Create a stack of the same size as the vector

    // Push all vector elements onto the stack
    for (int elem : vec) {
        s.push(elem);
    }

    // Pop elements from the stack back to the vector
    for (int i = 0; i < n; i++) {
        vec[i] = s.pop();
    }
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Original Vector: ";
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    // Call the reverse function
    reverseVector(vec);

    cout << "Reversed Vector: ";
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
