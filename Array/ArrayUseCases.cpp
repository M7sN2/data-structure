#include "Array.h"
#include <iostream>

// example 1: storing grades
void studentGradesExample() {
    std::cout << "\nExample 1: Student Grades\n" << std::endl;
    DynamicArray grades;
    
    grades.push_back(85);
    grades.push_back(92);
    grades.push_back(78);
    grades.push_back(96);
    grades.push_back(88);
    
    std::cout << "Grades: ";
    grades.display();
    
    grades.insert(2, 90);
    std::cout << "After insert: ";
    grades.display();
    
    grades.remove(1);
    std::cout << "After remove: ";
    grades.display();
    
    // calc average
    int sum = 0;
    for (int i = 0; i < grades.getSize(); i++) {
        sum += grades.get(i);
    }
    double avg = (double)sum / grades.getSize();
    std::cout << "Average: " << avg << std::endl;
}

// example 2: shopping cart
void shoppingCartExample() {
    std::cout << "\nExample 2: Shopping Cart\n" << std::endl;
    DynamicArray cart;
    
    cart.push_back(25);
    cart.push_back(15);
    cart.push_back(30);
    cart.push_back(10);
    
    std::cout << "Cart: ";
    cart.display();
    
    int total = 0;
    for (int i = 0; i < cart.getSize(); i++) {
        total += cart.get(i);
    }
    std::cout << "Total: $" << total << std::endl;
    
    cart.remove(1);
    std::cout << "After remove: ";
    cart.display();
}

// example 3: temperature data
void temperatureRecordingExample() {
    std::cout << "\nExample 3: Temperature Data\n" << std::endl;
    DynamicArray temps;
    
    temps.push_back(72);
    temps.push_back(75);
    temps.push_back(68);
    temps.push_back(70);
    temps.push_back(73);
    temps.push_back(69);
    temps.push_back(71);
    
    std::cout << "Temperatures: ";
    temps.display();
    
    int max = temps.get(0);
    int min = temps.get(0);
    for (int i = 1; i < temps.getSize(); i++) {
        if (temps.get(i) > max) max = temps.get(i);
        if (temps.get(i) < min) min = temps.get(i);
    }
    std::cout << "Max: " << max << "F" << std::endl;
    std::cout << "Min: " << min << "F" << std::endl;
}

int main() {
    studentGradesExample();
    shoppingCartExample();
    temperatureRecordingExample();
    return 0;
}

