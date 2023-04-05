#include "Graph.h"
#include <iostream>

// example 1: social network
void socialNetworkExample() {
    std::cout << "\nExample 1: Social Network\n" << std::endl;
    Graph network(6, false);
    
    network.addEdge(0, 1);
    network.addEdge(0, 2);
    network.addEdge(1, 3);
    network.addEdge(2, 3);
    network.addEdge(3, 4);
    network.addEdge(4, 5);
    
    network.display();
    network.BFS(0);
}

// example 2: web navigation
void webNavigationExample() {
    std::cout << "\nExample 2: Web Navigation\n" << std::endl;
    Graph webPages(5, true);
    
    webPages.addEdge(0, 1);
    webPages.addEdge(0, 2);
    webPages.addEdge(1, 3);
    webPages.addEdge(2, 3);
    webPages.addEdge(3, 4);
    
    webPages.display();
    webPages.DFS(0);
}

// example 3: road network
void roadNetworkExample() {
    std::cout << "\nExample 3: Road Network\n" << std::endl;
    Graph city(7, false);
    
    city.addEdge(0, 1);
    city.addEdge(0, 2);
    city.addEdge(1, 3);
    city.addEdge(2, 3);
    city.addEdge(3, 4);
    city.addEdge(4, 5);
    city.addEdge(4, 6);
    
    city.display();
    std::cout << "Path from 0:" << std::endl;
    city.BFS(0);
}

// example 4: course prerequisites
void coursePrerequisitesExample() {
    std::cout << "\nExample 4: Course Prerequisites\n" << std::endl;
    Graph courses(6, true);
    
    courses.addEdge(0, 1);
    courses.addEdge(0, 2);
    courses.addEdge(1, 3);
    courses.addEdge(2, 3);
    courses.addEdge(3, 4);
    courses.addEdge(4, 5);
    
    courses.display();
    std::cout << "Course order: ";
    courses.DFSRecursive(0);
}

// example 5: computer network
void computerNetworkExample() {
    std::cout << "\nExample 5: Computer Network\n" << std::endl;
    Graph network(8, false);
    
    network.addEdge(0, 1);
    network.addEdge(0, 2);
    network.addEdge(1, 3);
    network.addEdge(2, 4);
    network.addEdge(3, 5);
    network.addEdge(4, 5);
    network.addEdge(5, 6);
    network.addEdge(6, 7);
    
    network.display();
    std::cout << "BFS from 0:" << std::endl;
    network.BFS(0);
    std::cout << "DFS from 0:" << std::endl;
    network.DFSRecursive(0);
}

int main() {
    socialNetworkExample();
    webNavigationExample();
    roadNetworkExample();
    coursePrerequisitesExample();
    computerNetworkExample();
    return 0;
}

