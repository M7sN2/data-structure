#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include <iostream>

// example 1: music playlist
void musicPlaylistExample() {
    std::cout << "\nExample 1: Music Playlist\n" << std::endl;
    SinglyLinkedList playlist;
    
    playlist.insertAtEnd(1);
    playlist.insertAtEnd(2);
    playlist.insertAtEnd(3);
    playlist.insertAtEnd(4);
    
    std::cout << "Playlist: ";
    playlist.display();
    
    playlist.insertAtBeginning(0);
    std::cout << "After add at start: ";
    playlist.display();
    
    playlist.deleteNode(2);
    std::cout << "After remove song 2: ";
    playlist.display();
}

// example 2: browser history
void browserHistoryExample() {
    std::cout << "\nExample 2: Browser History\n" << std::endl;
    DoublyLinkedList history;
    
    history.insertAtEnd(1);
    history.insertAtEnd(2);
    history.insertAtEnd(3);
    history.insertAtEnd(4);
    
    std::cout << "Forward: ";
    history.displayForward();
    std::cout << "Backward: ";
    history.displayBackward();
    
    history.deleteNode(2);
    std::cout << "After remove page 2: ";
    history.displayForward();
}

// example 3: task list
void taskManagementExample() {
    std::cout << "\nExample 3: Task List\n" << std::endl;
    SinglyLinkedList tasks;
    
    tasks.insertAtEnd(101);
    tasks.insertAtEnd(102);
    tasks.insertAtEnd(103);
    
    std::cout << "Tasks: ";
    tasks.display();
    
    tasks.insertAtBeginning(100);
    std::cout << "After urgent task: ";
    tasks.display();
    
    tasks.deleteNode(102);
    std::cout << "After complete task 102: ";
    tasks.display();
    
    if (tasks.search(103)) {
        std::cout << "Task 103 found" << std::endl;
    }
}

// example 4: undo/redo
void undoRedoExample() {
    std::cout << "\nExample 4: Undo/Redo\n" << std::endl;
    DoublyLinkedList actions;
    
    actions.insertAtEnd(1);
    actions.insertAtEnd(2);
    actions.insertAtEnd(3);
    actions.insertAtEnd(4);
    actions.insertAtEnd(5);
    
    std::cout << "Actions: ";
    actions.displayForward();
    std::cout << "Undo order: ";
    actions.displayBackward();
}

int main() {
    musicPlaylistExample();
    browserHistoryExample();
    taskManagementExample();
    undoRedoExample();
    return 0;
}

