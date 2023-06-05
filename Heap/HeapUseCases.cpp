#include "Heap.h"
#include <iostream>

// example 1: priority queue
void priorityQueueExample() {
    std::cout << "\nExample 1: Priority Queue\n" << std::endl;
    MinHeap pq;
    
    // Adding tasks with priorities
    pq.insert(10);
    pq.insert(5);
    pq.insert(15);
    pq.insert(3);
    pq.insert(7);
    
    pq.display();
    
    // Process tasks in priority order
    std::cout << "Processing tasks:" << std::endl;
    while (!pq.isEmpty()) {
        std::cout << "Processing: " << pq.extractMin() << std::endl;
    }
}

// example 2: find k largest
void findKLargestExample() {
    std::cout << "\nExample 2: Find K Largest\n" << std::endl;
    MaxHeap heap;
    
    // Adding numbers
    heap.insert(10);
    heap.insert(5);
    heap.insert(20);
    heap.insert(15);
    heap.insert(8);
    heap.insert(25);
    
    heap.display();
    
    // Find 3 largest
    int k = 3;
    std::cout << "Top " << k << " largest elements: ";
    for (int i = 0; i < k && !heap.isEmpty(); i++) {
        std::cout << heap.extractMax() << " ";
    }
    std::cout << std::endl;
}

// example 3: job scheduling
void jobSchedulingExample() {
    std::cout << "\nExample 3: Job Scheduling\n" << std::endl;
    MinHeap scheduler;
    
    // Jobs with execution times
    scheduler.insert(5);  // Job 1: 5 minutes
    scheduler.insert(2);  // Job 2: 2 minutes
    scheduler.insert(8);  // Job 3: 8 minutes
    scheduler.insert(1);  // Job 4: 1 minute
    scheduler.insert(3);  // Job 5: 3 minutes
    
    scheduler.display();
    
    // Schedule jobs (shortest first)
    std::cout << "Job execution order:" << std::endl;
    while (!scheduler.isEmpty()) {
        std::cout << "Executing job with time: " << scheduler.extractMin() << " minutes" << std::endl;
    }
}

// example 4: median maintenance
void medianMaintenanceExample() {
    std::cout << "\nExample 4: Median Maintenance\n" << std::endl;
    MaxHeap maxHeap; // Lower half
    MinHeap minHeap; // Upper half
    
    std::vector<int> numbers = {5, 15, 10, 20, 3};
    
    for (int num : numbers) {
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.insert(num);
        } else {
            minHeap.insert(num);
        }
        
        // Balance heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.insert(maxHeap.extractMax());
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.insert(minHeap.extractMin());
        }
        
        // Calculate median
        int median;
        if (maxHeap.size() == minHeap.size()) {
            median = (maxHeap.peek() + minHeap.peek()) / 2;
        } else if (maxHeap.size() > minHeap.size()) {
            median = maxHeap.peek();
        } else {
            median = minHeap.peek();
        }
        std::cout << "After inserting " << num << ", median: " << median << std::endl;
    }
}

// example 5: event management
void eventManagementExample() {
    std::cout << "\nExample 5: Event Management\n" << std::endl;
    MinHeap events;
    
    // Events with timestamps
    events.insert(100); // Event at time 100
    events.insert(50);  // Event at time 50
    events.insert(200); // Event at time 200
    events.insert(30);  // Event at time 30
    events.insert(150); // Event at time 150
    
    events.display();
    
    // Process events in chronological order
    std::cout << "Processing events:" << std::endl;
    while (!events.isEmpty()) {
        std::cout << "Processing event at time: " << events.extractMin() << std::endl;
    }
}

int main() {
    priorityQueueExample();
    findKLargestExample();
    jobSchedulingExample();
    medianMaintenanceExample();
    eventManagementExample();
    return 0;
}

