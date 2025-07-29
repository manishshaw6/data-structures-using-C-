//Circular Queue Code in C++
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int size;
    int *items;

public:
    CircularQueue(int s) {
        front = -1;
        rear = -1;
        size = s;
        items = new int[size];
    }

    ~CircularQueue() {
        delete[] items;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enQueue(int element) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        // If the queue is initially empty
        if (isEmpty()) {
            front = 0;
        }

        // Calculate the new rear position in circular manner
        rear = (rear + 1) % size;
        items[rear] = element;
        cout << "Inserted " << element << endl;
    }

    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int element = items[front];

        // If there's only one element, reset the queue
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;  // Move front in a circular manner
        }

        cout << "Deleted -> " << element << endl;
        return element;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;

        // Traverse the circular queue
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

// Main function to demonstrate the Circular Queue operations
int main() {
    CircularQueue cq(5);

    cq.enQueue(10);
    cq.enQueue(20);
    cq.enQueue(30);
    cq.enQueue(40);
    cq.display();

    cq.deQueue();
    cq.deQueue();
    cq.display();

    cq.enQueue(50);
    cq.enQueue(60);
    cq.display();

    cq.enQueue(70);  // Attempt to enqueue in a full queue

    return 0;
}
