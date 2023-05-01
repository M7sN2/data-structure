#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

struct KeyValue {
    std::string key;
    int value;
    KeyValue(const std::string& k, int v) : key(k), value(v) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<std::list<KeyValue>> table;

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                pair.value = value; // Update existing
                return;
            }
        }
        table[index].push_back(KeyValue(key, value));
    }

    bool get(const std::string& key, int& value) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                value = pair.value;
                return true;
            }
        }
        return false;
    }

    void remove(const std::string& key) {
        int index = hashFunction(key);
        table[index].remove_if([&key](const KeyValue& pair) {
            return pair.key == key;
        });
    }

    bool contains(const std::string& key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                return true;
            }
        }
        return false;
    }

    void display() {
        std::cout << "Hash Table:" << std::endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].empty()) {
                std::cout << "Bucket " << i << ": ";
                for (const auto& pair : table[i]) {
                    std::cout << "(" << pair.key << ", " << pair.value << ") ";
                }
                std::cout << std::endl;
            }
        }
    }
};

#endif

