#include "Stack.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// postfix expression eval
int evaluatePostfix(const std::string& expression) {
    Stack stack;
    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = stack.pop();
            int a = stack.pop();
            switch (c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }
    return stack.pop();
}

// check if parentheses are balanced
bool isBalanced(const std::string& expression) {
    Stack stack;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.isEmpty()) return false;
            char top = stack.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

// reverse a string using stack
std::string reverseString(const std::string& str) {
    Stack stack;
    for (char c : str) {
        stack.push(c);
    }
    std::string reversed = "";
    while (!stack.isEmpty()) {
        reversed += (char)stack.pop();
    }
    return reversed;
}

// browser back button example
void browserBackButtonExample() {
    std::cout << "\nExample 4: Browser Back\n" << std::endl;
    Stack backStack;
    
    backStack.push(1);
    backStack.push(2);
    backStack.push(3);
    backStack.push(4);
    
    std::cout << "Current: " << backStack.peek() << std::endl;
    backStack.display();
    
    std::cout << "Back to: " << backStack.pop() << std::endl;
    std::cout << "Current: " << backStack.peek() << std::endl;
}

// undo operation example
void undoOperationExample() {
    std::cout << "\nExample 5: Undo\n" << std::endl;
    Stack undoStack;
    
    undoStack.push(1);
    undoStack.push(2);
    undoStack.push(3);
    undoStack.push(4);
    undoStack.push(5);
    
    undoStack.display();
    
    std::cout << "Undo: " << undoStack.pop() << std::endl;
    undoStack.display();
}

int main() {
    std::cout << "\nExample 1: Postfix Eval\n" << std::endl;
    std::string postfix = "231*+9-";
    std::cout << "Expression: " << postfix << std::endl;
    std::cout << "Result: " << evaluatePostfix(postfix) << std::endl;
    
    std::cout << "\nExample 2: Balanced Parentheses\n" << std::endl;
    std::string expr1 = "({[]})";
    std::string expr2 = "({[})";
    std::cout << expr1 << ": " << (isBalanced(expr1) ? "balanced" : "not balanced") << std::endl;
    std::cout << expr2 << ": " << (isBalanced(expr2) ? "balanced" : "not balanced") << std::endl;
    
    std::cout << "\nExample 3: Reverse String\n" << std::endl;
    std::string original = "Hello";
    std::cout << "Original: " << original << std::endl;
    std::cout << "Reversed: " << reverseString(original) << std::endl;
    
    browserBackButtonExample();
    undoOperationExample();
    
    return 0;
}

