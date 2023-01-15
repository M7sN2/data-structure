#ifndef STACK_H
#define STACK_H

#include <iostream>

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        StackNode* temp = top;
        int value = top->data;
        top = top->next;
        delete temp;
        size--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() const {
        return size;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        StackNode* current = top;
        std::cout << "Stack (top to bottom): ";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) std::cout << " -> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif

