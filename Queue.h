#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
#include <string>

class Queue {
private:
    std::string* data;  // Изменено на std::string*
    int front;
    int rear;
    int capacity;

public:
    Queue(int initialCapacity = 10);
    ~Queue();

    void push(const std::string& value);  // Изменено на std::string
    std::string pop();  // Изменено на std::string
    std::string peek() const;  // Изменено на std::string
    bool isEmpty() const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif