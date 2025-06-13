#include <iostream>
using namespace std;

// Node structure
struct Node {
    int x;
    int y;
    char sign;
    Node* next;
    Node(int xVal, int yVal, char sign) : x(xVal), y(yVal), sign(sign), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue: add element to the rear
    void enqueue(int x, int y, char sign) {
        Node* newNode = new Node(x, y, sign);
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
    Node* peek() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return nullptr;
        }
        return front;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Print the queue
    void print() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->x << ",";
            cout << current->y << " ";
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