# Makefile for Data Structures Project

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = main_demo

# Individual demo targets
ARRAY_DEMO = array_demo
LINKEDLIST_DEMO = linkedlist_demo
STACK_DEMO = stack_demo
QUEUE_DEMO = queue_demo
TREE_DEMO = tree_demo
GRAPH_DEMO = graph_demo
HASHTABLE_DEMO = hashtable_demo
HEAP_DEMO = heap_demo
TRIE_DEMO = trie_demo

# Main target
all: $(TARGET)

# Main demo
$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

# Individual demos
array: Array/ArrayUseCases.cpp Array/Array.h
	$(CXX) $(CXXFLAGS) Array/ArrayUseCases.cpp -o $(ARRAY_DEMO)

linkedlist: LinkedList/LinkedListUseCases.cpp LinkedList/SinglyLinkedList.h LinkedList/DoublyLinkedList.h
	$(CXX) $(CXXFLAGS) LinkedList/LinkedListUseCases.cpp -o $(LINKEDLIST_DEMO)

stack: Stack/StackUseCases.cpp Stack/Stack.h
	$(CXX) $(CXXFLAGS) Stack/StackUseCases.cpp -o $(STACK_DEMO)

queue: Queue/QueueUseCases.cpp Queue/Queue.h Queue/PriorityQueue.h
	$(CXX) $(CXXFLAGS) Queue/QueueUseCases.cpp -o $(QUEUE_DEMO)

tree: Tree/TreeUseCases.cpp Tree/BinarySearchTree.h
	$(CXX) $(CXXFLAGS) Tree/TreeUseCases.cpp -o $(TREE_DEMO)

graph: Graph/GraphUseCases.cpp Graph/Graph.h
	$(CXX) $(CXXFLAGS) Graph/GraphUseCases.cpp -o $(GRAPH_DEMO)

hashtable: HashTable/HashTableUseCases.cpp HashTable/HashTable.h
	$(CXX) $(CXXFLAGS) HashTable/HashTableUseCases.cpp -o $(HASHTABLE_DEMO)

heap: Heap/HeapUseCases.cpp Heap/Heap.h
	$(CXX) $(CXXFLAGS) Heap/HeapUseCases.cpp -o $(HEAP_DEMO)

trie: Trie/TrieUseCases.cpp Trie/Trie.h
	$(CXX) $(CXXFLAGS) Trie/TrieUseCases.cpp -o $(TRIE_DEMO)

# Build all individual demos
all-demos: array linkedlist stack queue tree graph hashtable heap trie

# Clean compiled files
clean:
	rm -f $(TARGET) $(ARRAY_DEMO) $(LINKEDLIST_DEMO) $(STACK_DEMO) $(QUEUE_DEMO)
	rm -f $(TREE_DEMO) $(GRAPH_DEMO) $(HASHTABLE_DEMO) $(HEAP_DEMO) $(TRIE_DEMO)
	rm -f *.exe

# Windows clean
clean-win:
	del /Q $(TARGET).exe $(ARRAY_DEMO).exe $(LINKEDLIST_DEMO).exe $(STACK_DEMO).exe $(QUEUE_DEMO).exe
	del /Q $(TREE_DEMO).exe $(GRAPH_DEMO).exe $(HASHTABLE_DEMO).exe $(HEAP_DEMO).exe $(TRIE_DEMO).exe

.PHONY: all array linkedlist stack queue tree graph hashtable heap trie all-demos clean clean-win

