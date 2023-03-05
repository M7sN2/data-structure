#include "BinarySearchTree.h"
#include <iostream>

// example 1: dictionary
void dictionaryExample() {
    std::cout << "\nExample 1: Dictionary\n" << std::endl;
    BinarySearchTree dictionary;
    
    dictionary.insert(50);
    dictionary.insert(30);
    dictionary.insert(70);
    dictionary.insert(20);
    dictionary.insert(40);
    dictionary.insert(60);
    dictionary.insert(80);
    
    std::cout << "Sorted: ";
    dictionary.inorder();
    
    if (dictionary.search(40)) {
        std::cout << "Found!" << std::endl;
    }
}

// example 2: file system
void fileSystemExample() {
    std::cout << "\nExample 2: File System\n" << std::endl;
    BinarySearchTree fileSystem;
    
    fileSystem.insert(100);
    fileSystem.insert(50);
    fileSystem.insert(150);
    fileSystem.insert(25);
    fileSystem.insert(75);
    fileSystem.insert(125);
    fileSystem.insert(175);
    
    std::cout << "Inorder: ";
    fileSystem.inorder();
    std::cout << "Level order: ";
    fileSystem.levelOrder();
}

// example 3: database index
void databaseIndexExample() {
    std::cout << "\nExample 3: Database Index\n" << std::endl;
    BinarySearchTree index;
    
    index.insert(1001);
    index.insert(1002);
    index.insert(1003);
    index.insert(1004);
    index.insert(1005);
    
    std::cout << "Index: ";
    index.inorder();
    
    if (index.search(1003)) {
        std::cout << "Record 1003 found" << std::endl;
    }
    
    index.remove(1003);
    std::cout << "After delete: ";
    index.inorder();
}

// example 4: expression tree
void expressionTreeExample() {
    std::cout << "\nExample 4: Expression Tree\n" << std::endl;
    BinarySearchTree expression;
    
    expression.insert(5);
    expression.insert(3);
    expression.insert(7);
    expression.insert(2);
    expression.insert(4);
    expression.insert(6);
    expression.insert(8);
    
    std::cout << "Preorder: ";
    expression.preorder();
    std::cout << "Inorder: ";
    expression.inorder();
    std::cout << "Postorder: ";
    expression.postorder();
}

// example 5: priority scheduling
void prioritySchedulingExample() {
    std::cout << "\nExample 5: Priority Schedule\n" << std::endl;
    BinarySearchTree scheduler;
    
    scheduler.insert(10);
    scheduler.insert(5);
    scheduler.insert(15);
    scheduler.insert(3);
    scheduler.insert(7);
    scheduler.insert(12);
    scheduler.insert(18);
    
    std::cout << "Priority order: ";
    scheduler.inorder();
}

int main() {
    dictionaryExample();
    fileSystemExample();
    databaseIndexExample();
    expressionTreeExample();
    prioritySchedulingExample();
    return 0;
}

