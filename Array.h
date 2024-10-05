#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <fstream>

class Array {
private:
    int* data;
    int size;
    int capacity;

public:
    Array(int initialCapacity = 10);
    ~Array();

    void add(int index, int value);
    void addToEnd(int value);
    int get(int index) const;
    void remove(int index);
    void set(int index, int value);
    int length() const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif