#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <fstream>
#include <string>

class DNode {
public:
    std::string data;  // Изменено на std::string
    DNode* prev;
    DNode* next;

    DNode(const std::string& value, DNode* prevNode = nullptr, DNode* nextNode = nullptr)
        : data(value), prev(prevNode), next(nextNode) {}
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addToHead(const std::string& value);  // Изменено на std::string
    void addToTail(const std::string& value);  // Изменено на std::string
    void removeFromHead();
    void removeFromTail();
    void removeByValue(const std::string& value);  // Изменено на std::string
    bool search(const std::string& value) const;  // Изменено на std::string
    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif