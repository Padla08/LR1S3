#ifndef COMPLETEBINARYTREE_H
#define COMPLETEBINARYTREE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
    void printAsTable() const; 
    bool isComplete() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif