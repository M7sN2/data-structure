#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

struct PriorityNode {
    int data;
    int priority;
    PriorityNode* next;
    PriorityNode(int val, int pri) : data(val), priority(pri), next(nullptr) {}
};

class PriorityQueue {
private:
    PriorityNode* front;

public:
    PriorityQueue() : front(nullptr) {}
    
    ~PriorityQueue() {
        while (front != nullptr) {
            PriorityNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int value, int priority) {
        PriorityNode* newNode = new PriorityNode(value, priority);
        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            PriorityNode* current = front;
            while (current->next != nullptr && current->next->priority >= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            std::cout << "Priority queue is empty!" << std::endl;
            return -1;
        }
        PriorityNode* temp = front;
        int value = front->data;
        front = front->next;
        delete temp;
        return value;
    }

    int peek() {
        if (front == nullptr) {
            std::cout << "Priority queue is empty!" << std::endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (front == nullptr) {
            std::cout << "Priority queue is empty!" << std::endl;
            return;
        }
        PriorityNode* current = front;
        std::cout << "Priority Queue: ";
        while (current != nullptr) {
            std::cout << "(" << current->data << ", " << current->priority << ")";
            if (current->next != nullptr) std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif

