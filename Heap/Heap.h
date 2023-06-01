#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                std::swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            std::cout << "Heap is empty!" << std::endl;
            return -1;
        }
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return min;
    }

    int peek() {
        if (heap.empty()) {
            std::cout << "Heap is empty!" << std::endl;
            return -1;
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void display() {
        std::cout << "Heap: ";
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                std::swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            std::cout << "Heap is empty!" << std::endl;
            return -1;
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return max;
    }

    int peek() {
        if (heap.empty()) {
            std::cout << "Heap is empty!" << std::endl;
            return -1;
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    void display() {
        std::cout << "Heap: ";
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

#endif

