#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
#include <string>

class Stack {
private:
    std::string* data;  // Изменено на std::string*
    int top;
    int capacity;

public:
    Stack(int initialCapacity = 10);
    ~Stack();

    void push(const std::string& value);  // Изменено на std::string
    std::string pop();  // Изменено на std::string
    std::string peek() const;  // Изменено на std::string
    bool isEmpty() const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif