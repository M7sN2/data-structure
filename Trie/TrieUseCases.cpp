#include "Trie.h"
#include <iostream>

// example 1: autocomplete
void autocompleteExample() {
    std::cout << "\nExample 1: Autocomplete\n" << std::endl;
    Trie autocomplete;
    
    // Adding words to dictionary
    autocomplete.insert("apple");
    autocomplete.insert("app");
    autocomplete.insert("application");
    autocomplete.insert("apply");
    autocomplete.insert("banana");
    autocomplete.insert("band");
    autocomplete.insert("bandana");
    
    // Check if words exist
    std::cout << "Search 'app': " << (autocomplete.search("app") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'apple': " << (autocomplete.search("apple") ? "Found" : "Not found") << std::endl;
    std::cout << "Starts with 'app': " << (autocomplete.startsWith("app") ? "Yes" : "No") << std::endl;
    std::cout << "Starts with 'ban': " << (autocomplete.startsWith("ban") ? "Yes" : "No") << std::endl;
}

// example 2: spell checker
void spellCheckerExample() {
    std::cout << "\nExample 2: Spell Checker\n" << std::endl;
    Trie dictionary;
    
    // Adding correct words
    dictionary.insert("hello");
    dictionary.insert("world");
    dictionary.insert("computer");
    dictionary.insert("programming");
    dictionary.insert("algorithm");
    
    // Check spelling
    std::vector<std::string> words = {"hello", "helo", "world", "worl", "computer"};
    for (const std::string& word : words) {
        if (dictionary.search(word)) {
            std::cout << word << " is spelled correctly" << std::endl;
        } else {
            std::cout << word << " is misspelled" << std::endl;
        }
    }
}

// example 3: IP routing
void ipRoutingExample() {
    std::cout << "\nExample 3: IP Routing\n" << std::endl;
    Trie routingTable;
    
    // Adding IP prefixes
    routingTable.insert("192.168.1");
    routingTable.insert("10.0.0");
    routingTable.insert("172.16.0");
    
    // Check if IP matches prefix
    std::cout << "IP 192.168.1.100 matches prefix: " << (routingTable.startsWith("192.168.1") ? "Yes" : "No") << std::endl;
    std::cout << "IP 10.0.0.5 matches prefix: " << (routingTable.startsWith("10.0.0") ? "Yes" : "No") << std::endl;
}

// example 4: contact search
void contactSearchExample() {
    std::cout << "\nExample 4: Contact Search\n" << std::endl;
    Trie contacts;
    
    // Adding contacts
    contacts.insert("john");
    contacts.insert("johnny");
    contacts.insert("jane");
    contacts.insert("jack");
    contacts.insert("james");
    
    // Search for contacts starting with "ja"
    std::cout << "Contacts starting with 'ja': " << (contacts.startsWith("ja") ? "Found" : "Not found") << std::endl;
    std::cout << "Contact 'john' exists: " << (contacts.search("john") ? "Yes" : "No") << std::endl;
    std::cout << "Contact 'johnny' exists: " << (contacts.search("johnny") ? "Yes" : "No") << std::endl;
}

int main() {
    autocompleteExample();
    spellCheckerExample();
    ipRoutingExample();
    contactSearchExample();
    return 0;
}

