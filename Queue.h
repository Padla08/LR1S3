#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>

class Queue {
private:
    int* data;
    int front;
    int rear;
    int capacity;

public:
    Queue(int initialCapacity = 10);
    ~Queue();

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif