#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <string>

class HashNode {
public:
    std::string key;
    std::string value;
    HashNode* next;

    HashNode(const std::string& key, const std::string& value) : key(key), value(value), next(nullptr) {}
};

class HashTable {
private:
    HashNode** table;
    int capacity;

    int hash(const std::string& key) const;

public:
    HashTable(int initialCapacity = 10);
    ~HashTable();

    void insert(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    void remove(const std::string& key);
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif