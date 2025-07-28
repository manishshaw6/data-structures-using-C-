C++ Code for Stack Implementation Using Linked List 
#include <iostream>
using namespace std;
// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Pointer to the top element of the stack

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;
        newNode->next = top;  // Link the new node to the previous top
        top = newNode;  // Update the top pointer
        cout << value << " pushed to stack." << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;  // Update the top pointer
        cout << temp->data << " popped from stack." << endl;
        delete temp;  // Free the memory of the popped node
    }

    // Peek the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
// Main function to test the stack
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    return 0;
}
