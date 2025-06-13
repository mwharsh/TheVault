#ifndef QUEUE_H
#define QUEUE_H

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int value);
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue();
    void enqueue(int x, int y, char sign);
    void dequeue();
    Node* peek();
    bool isEmpty();
    void print();
    ~Queue();
};

#endif // QUEUE_H