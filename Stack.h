#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
#include <string>

class Stack {
private:
    std::string* data;  // �������� �� std::string*
    int top;
    int capacity;

public:
    Stack(int initialCapacity = 10);
    ~Stack();

    void push(const std::string& value);  // �������� �� std::string
    std::string pop();  // �������� �� std::string
    std::string peek() const;  // �������� �� std::string
    bool isEmpty() const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif