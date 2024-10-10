#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void addToHead(const string& value);
    void addToTail(const string& value);
    void removeFromHead();
    void removeFromTail();
    void removeByValue(const string& value);
    bool search(const string& value) const;
    void print() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif // SINGLYLINKEDLIST_H