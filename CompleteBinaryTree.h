#ifndef COMPLETEBINARYTREE_H
#define COMPLETEBINARYTREE_H

#include <iostream>
#include <fstream>

class CompleteBinaryTree {
private:
    int* data;
    int size;
    int capacity;

public:
    CompleteBinaryTree(int initialCapacity = 10);
    ~CompleteBinaryTree();

    void add(int value);
    bool search(int value) const;
    void print() const;
    bool isComplete() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif