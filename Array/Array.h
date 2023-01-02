#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(int value) {
        if (size >= capacity) {
            resize();
        }
        arr[size++] = value;
    }

    void insert(int index, int value) {
        if (index < 0 || index > size) {
            std::cout << "Invalid index!" << std::endl;
            return;
        }
        if (size >= capacity) {
            resize();
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index!" << std::endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index!" << std::endl;
            return -1;
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    void display() {
        std::cout << "Array: [";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i];
            if (i < size - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

#endif

