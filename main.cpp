#include <iostream>
#include "Array/Array.h"
#include "LinkedList/SinglyLinkedList.h"
#include "LinkedList/DoublyLinkedList.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "Queue/PriorityQueue.h"
#include "Tree/BinarySearchTree.h"
#include "Graph/Graph.h"
#include "HashTable/HashTable.h"
#include "Heap/Heap.h"
#include "Trie/Trie.h"

void testArray() {
    std::cout << "\n--- Array ---\n" << std::endl;
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.display();
    arr.insert(1, 15);
    arr.display();
    arr.remove(2);
    arr.display();
}

void testLinkedList() {
    std::cout << "\n--- Linked List ---\n" << std::endl;
    SinglyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.display();
    list.insertAtBeginning(0);
    list.display();
    list.deleteNode(2);
    list.display();
}

void testStack() {
    std::cout << "\n--- Stack ---\n" << std::endl;
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    std::cout << "Top: " << stack.peek() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    stack.display();
}

void testQueue() {
    std::cout << "\n--- Queue ---\n" << std::endl;
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    std::cout << "Front: " << queue.peek() << std::endl;
    std::cout << "Dequeue: " << queue.dequeue() << std::endl;
    queue.display();
}

void testBST() {
    std::cout << "\n--- Binary Search Tree ---\n" << std::endl;
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    std::cout << "Inorder: ";
    bst.inorder();
    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
}

void testGraph() {
    std::cout << "\n--- Graph ---\n" << std::endl;
    Graph graph(5, false);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.display();
    graph.BFS(0);
    graph.DFS(0);
}

void testHashTable() {
    std::cout << "\n--- Hash Table ---\n" << std::endl;
    HashTable ht;
    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("cherry", 30);
    ht.display();
    
    int value;
    if (ht.get("banana", value)) {
        std::cout << "banana: " << value << std::endl;
    }
}

void testHeap() {
    std::cout << "\n--- Heap ---\n" << std::endl;
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(3);
    minHeap.display();
    std::cout << "Min: " << minHeap.peek() << std::endl;
    std::cout << "Extract: " << minHeap.extractMin() << std::endl;
    minHeap.display();
}

void testTrie() {
    std::cout << "\n--- Trie ---\n" << std::endl;
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    
    std::cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << std::endl;
    std::cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << std::endl;
}

int main() {
    std::cout << "Data Structures Test\n" << std::endl;
    
    testArray();
    testLinkedList();
    testStack();
    testQueue();
    testBST();
    testGraph();
    testHashTable();
    testHeap();
    testTrie();
    
    std::cout << "\nDone\n" << std::endl;
    return 0;
}

