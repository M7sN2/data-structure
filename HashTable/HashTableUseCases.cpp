#include "HashTable.h"
#include <iostream>

// example 1: student database
void studentDatabaseExample() {
    std::cout << "\nExample 1: Student Database\n" << std::endl;
    HashTable students;
    
    students.insert("John", 1001);
    students.insert("Alice", 1002);
    students.insert("Bob", 1003);
    students.insert("Charlie", 1004);
    
    students.display();
    
    int id;
    if (students.get("Alice", id)) {
        std::cout << "Alice ID: " << id << std::endl;
    }
    
    students.remove("Bob");
    std::cout << "After remove:" << std::endl;
    students.display();
}

// example 2: cache system
void cacheSystemExample() {
    std::cout << "\nExample 2: Cache System\n" << std::endl;
    HashTable cache;
    
    cache.insert("user:123", 45000);
    cache.insert("user:456", 32000);
    cache.insert("product:789", 99);
    
    cache.display();
    
    int value;
    if (cache.get("user:123", value)) {
        std::cout << "user:123 = " << value << std::endl;
    }
}

// example 3: word frequency
void wordFrequencyExample() {
    std::cout << "\nExample 3: Word Frequency\n" << std::endl;
    HashTable wordCount;
    
    wordCount.insert("hello", 5);
    wordCount.insert("world", 3);
    wordCount.insert("hello", 6);
    wordCount.insert("cpp", 10);
    
    wordCount.display();
    
    int count;
    if (wordCount.get("hello", count)) {
        std::cout << "hello count: " << count << std::endl;
    }
}

// example 4: phone directory
void phoneDirectoryExample() {
    std::cout << "\nExample 4: Phone Directory\n" << std::endl;
    HashTable directory;
    
    directory.insert("John", 1234567890);
    directory.insert("Alice", 9876543210);
    directory.insert("Bob", 5555555555);
    
    directory.display();
    
    int phone;
    if (directory.get("Alice", phone)) {
        std::cout << "Alice phone: " << phone << std::endl;
    }
    
    if (directory.contains("John")) {
        std::cout << "John found" << std::endl;
    }
}

// example 5: session management
void sessionManagementExample() {
    std::cout << "\nExample 5: Session Management\n" << std::endl;
    HashTable sessions;
    
    sessions.insert("session:abc123", 1);
    sessions.insert("session:def456", 2);
    sessions.insert("session:ghi789", 3);
    
    sessions.display();
    
    int userId;
    if (sessions.get("session:abc123", userId)) {
        std::cout << "Session valid, user: " << userId << std::endl;
    }
    
    sessions.remove("session:def456");
    std::cout << "After remove:" << std::endl;
    sessions.display();
}

int main() {
    studentDatabaseExample();
    cacheSystemExample();
    wordFrequencyExample();
    phoneDirectoryExample();
    sessionManagementExample();
    return 0;
}

