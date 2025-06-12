#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue: add element to the rear
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue: remove element from the front
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;  // queue is now empty
        delete temp;
    }

    // Peek: view front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Print the queue
    void print() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // Destructor: free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Example usage
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();          // Output: 10 20 30
    q.dequeue();
    q.print();          // Output: 20 30
    cout << q.peek();   // Output: 20
    return 0;
}