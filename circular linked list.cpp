
Circular Singly Linked List (CSLL) Code
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* tail;

    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (tail == nullptr) {
            newNode->next = newNode; // Self loop for a single node
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (tail == nullptr) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; // Update tail to the new last node
        }
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = tail->next;
        for (int i = 0; i < position - 1 && temp != tail; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) {
            tail = newNode;
        }
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* head = tail->next;
        if (tail == head) { // Only one node in the list
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    // Delete from the end
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        if (tail == temp) { // Only one node
            delete temp;
            tail = nullptr;
        } else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = tail->next;
            delete tail;
            tail = temp;
        }
    }

    // Delete from a specific position
    void deleteFromPosition(int position) {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        for (int i = 0; temp->next != tail->next && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp->next == tail->next) {
            cout << "Invalid position!\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        if (toDelete == tail) {
            tail = temp;
        }
        delete toDelete;
    }

    // Traversal of the circular linked list
    void display() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << " (Back to head)\n";
    }
};

// Main function with menu-driven approach
int main() {
    CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\nCircular Linked List Operations\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                cll.insertAtPosition(value, position);
                break;
            case 4:
                cll.deleteFromBeginning();
                break;
            case 5:
                cll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                cll.deleteFromPosition(position);
                break;
            case 7:
                cll.display();
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}


Circular Doubly Linked List (CDLL) - All Operations
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* tail;

    CircularLinkedList() {
        tail = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (tail == nullptr) {
            newNode->next = newNode; // Self loop for a single node
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (tail == nullptr) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; // Update tail to the new last node
        }
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = tail->next;
        for (int i = 0; i < position - 1 && temp != tail; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail) {
            tail = newNode;
        }
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* head = tail->next;
        if (tail == head) { // Only one node in the list
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    // Delete from the end
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        if (tail == temp) { // Only one node
            delete temp;
            tail = nullptr;
        } else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = tail->next;
            delete tail;
            tail = temp;
        }
    }

    // Delete from a specific position
    void deleteFromPosition(int position) {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        for (int i = 0; temp->next != tail->next && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp->next == tail->next) {
            cout << "Invalid position!\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        if (toDelete == tail) {
            tail = temp;
        }
        delete toDelete;
    }

    // Traversal of the circular linked list
    void display() {
        if (tail == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << " (Back to head)\n";
    }
};

// Main function with menu-driven approach
int main() {
    CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\nCircular Linked List Operations\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cll.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                cll.insertAtPosition(value, position);
                break;
            case 4:
                cll.deleteFromBeginning();
                break;
            case 5:
                cll.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                cll.deleteFromPosition(position);
                break;
            case 7:
                cll.display();
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
