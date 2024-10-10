#ifndef COMPLETEBINARYTREE_H
#define COMPLETEBINARYTREE_H

#include <iostream>
#include <fstream>
#include <string>

class CompleteBinaryTree {
private:
    std::string* data;  
    int size;
    int capacity;

public:
    CompleteBinaryTree(int initialCapacity = 10);
    ~CompleteBinaryTree();

    void add(const std::string& value);  
    bool search(const std::string& value) const;  
    void print() const;
    bool isComplete() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif