#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

class Stack {
private:
    int* data;
    int top;
    int capacity;

public:
    Stack(int initialCapacity = 10);
    ~Stack();

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif