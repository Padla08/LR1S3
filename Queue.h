#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
#include <string>

class Queue {
private:
    std::string* data;  // �������� �� std::string*
    int front;
    int rear;
    int capacity;

public:
    Queue(int initialCapacity = 10);
    ~Queue();

    void push(const std::string& value);  // �������� �� std::string
    std::string pop();  // �������� �� std::string
    std::string peek() const;  // �������� �� std::string
    bool isEmpty() const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif