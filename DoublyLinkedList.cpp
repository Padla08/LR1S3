#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::addToHead(const string& value) {  // Изменено на string
    DNode* newNode = new DNode{ value, nullptr, head };
    if (head) {
        head->prev = newNode;
    }
    else {
        tail = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::addToTail(const string& value) {  // Изменено на string
    DNode* newNode = new DNode{ value, tail, nullptr };
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

void DoublyLinkedList::removeFromHead() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    DNode* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::removeFromTail() {
    if (!tail) {
        cout << "List is empty!\n";
        return;
    }
    DNode* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::removeByValue(const string& value) {  // Изменено на string
    DNode* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }
            delete current;
            return;
        }
        current = current->next;
    }
    cout << "Value not found!\n";
}

bool DoublyLinkedList::search(const string& value) const {  // Изменено на string
    DNode* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::print() const {
    DNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void DoublyLinkedList::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "DoublyLinkedList\n";
    DNode* current = head;
    while (current) {
        file << current->data << "\n";
        current = current->next;
    }
    file.close();
}

void DoublyLinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    getline(file, header);
    if (header != "DoublyLinkedList") {
        cout << "Invalid file format!\n";
        return;
    }
    string value;
    while (getline(file, value)) {
        addToTail(value);
    }
    file.close();
}