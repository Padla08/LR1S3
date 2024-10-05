#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <fstream>

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void addToHead(int value);
    void addToTail(int value);
    void removeFromHead();
    void removeFromTail();
    void removeByValue(int value);
    bool search(int value) const;
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif