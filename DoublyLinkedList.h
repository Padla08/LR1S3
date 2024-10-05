#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <fstream>

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

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