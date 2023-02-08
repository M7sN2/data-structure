#include "Queue.h"
#include "PriorityQueue.h"
#include <iostream>

// example 1: print queue
void printQueueExample() {
    std::cout << "\nExample 1: Print Queue\n" << std::endl;
    Queue printQueue;
    
    printQueue.enqueue(101);
    printQueue.enqueue(102);
    printQueue.enqueue(103);
    
    std::cout << "Queue: ";
    printQueue.display();
    
    std::cout << "Printing: " << printQueue.dequeue() << std::endl;
    std::cout << "Remaining: ";
    printQueue.display();
    
    printQueue.enqueue(104);
    std::cout << "After add: ";
    printQueue.display();
}

// example 2: customer service
void customerServiceExample() {
    std::cout << "\nExample 2: Customer Service\n" << std::endl;
    Queue serviceQueue;
    
    serviceQueue.enqueue(1);
    serviceQueue.enqueue(2);
    serviceQueue.enqueue(3);
    
    std::cout << "Queue: ";
    serviceQueue.display();
    
    while (!serviceQueue.isEmpty()) {
        std::cout << "Serving: " << serviceQueue.dequeue() << std::endl;
    }
}

// example 3: BFS simulation
void bfsSimulation() {
    std::cout << "\nExample 3: BFS\n" << std::endl;
    Queue bfsQueue;
    
    bfsQueue.enqueue(0);
    std::cout << "BFS order: ";
    
    while (!bfsQueue.isEmpty()) {
        int node = bfsQueue.dequeue();
        std::cout << node << " ";
        
        if (node < 5) {
            bfsQueue.enqueue(node + 1);
            bfsQueue.enqueue(node + 2);
        }
        if (bfsQueue.getSize() > 10) break;
    }
    std::cout << std::endl;
}

// example 4: priority scheduler
void taskSchedulerExample() {
    std::cout << "\nExample 4: Priority Scheduler\n" << std::endl;
    PriorityQueue taskQueue;
    
    taskQueue.enqueue(1, 3);
    taskQueue.enqueue(2, 5);
    taskQueue.enqueue(3, 1);
    taskQueue.enqueue(4, 4);
    
    std::cout << "Tasks: ";
    taskQueue.display();
    
    std::cout << "Executing:" << std::endl;
    while (!taskQueue.isEmpty()) {
        std::cout << "Task: " << taskQueue.dequeue() << std::endl;
    }
}

// example 5: message queue
void messageQueueExample() {
    std::cout << "\nExample 5: Message Queue\n" << std::endl;
    Queue messageQueue;
    
    messageQueue.enqueue(1001);
    messageQueue.enqueue(1002);
    messageQueue.enqueue(1003);
    
    std::cout << "Messages: ";
    messageQueue.display();
    
    while (!messageQueue.isEmpty()) {
        std::cout << "Processing: " << messageQueue.dequeue() << std::endl;
    }
}

int main() {
    printQueueExample();
    customerServiceExample();
    bfsSimulation();
    taskSchedulerExample();
    messageQueueExample();
    return 0;
}

