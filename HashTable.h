#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>

struct HashNode {
    int key;
    int value;
    HashNode* next;
};

class HashTable {
private:
    HashNode** table;
    int capacity;

    int hash(int key) const;

public:
    HashTable(int initialCapacity = 10);
    ~HashTable();

    void insert(int key, int value);
    int get(int key) const;
    void remove(int key);
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif