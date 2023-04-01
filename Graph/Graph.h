#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjList;
    bool directed;

public:
    Graph(int v, bool dir = false) : vertices(v), directed(dir) {
        adjList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        if (!directed) {
            adjList[dest].push_back(src);
        }
    }

    void display() {
        std::cout << "Graph (Adjacency List):" << std::endl;
        for (int i = 0; i < vertices; i++) {
            std::cout << i << " -> ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void BFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;
        
        visited[start] = true;
        q.push(start);
        
        std::cout << "BFS starting from " << start << ": ";
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            std::cout << vertex << " ";
            
            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }

    void DFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::stack<int> s;
        
        s.push(start);
        std::cout << "DFS starting from " << start << ": ";
        
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();
            
            if (!visited[vertex]) {
                visited[vertex] = true;
                std::cout << vertex << " ";
                
                for (int neighbor : adjList[vertex]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    void DFSRecursive(int start) {
        std::vector<bool> visited(vertices, false);
        std::cout << "DFS (Recursive) starting from " << start << ": ";
        DFSHelper(start, visited);
        std::cout << std::endl;
    }

private:
    void DFSHelper(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";
        
        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }
};

#endif

