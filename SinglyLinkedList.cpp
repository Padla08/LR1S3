#include "SinglyLinkedList.h"
using namespace std;

SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SinglyLinkedList::addToHead(int value) {
    Node* newNode = new Node{ value, head };
    head = newNode;
    if (!tail) {
        tail = head;
    }
}

void SinglyLinkedList::addToTail(int value) {
    Node* newNode = new Node{ value, nullptr };
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
}

void SinglyLinkedList::removeFromHead() {
    if (!head) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    if (!head) {
        tail = nullptr;
    }
}

void SinglyLinkedList::removeFromTail() {
    if (!tail) {
        cout << "List is empty!\n";
        return;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void SinglyLinkedList::removeByValue(int value) {
    Node* current = head;
    Node* previous = nullptr;
    while (current) {
        if (current->data == value) {
            if (previous) {
                previous->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current == tail) {
                tail = previous;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Value not found!\n";
}

bool SinglyLinkedList::search(int value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SinglyLinkedList::print() const {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void SinglyLinkedList::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "SinglyLinkedList\n";
    Node* current = head;
    while (current) {
        file << current->data << "\n";
        current = current->next;
    }
    file.close();
}

void SinglyLinkedList::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    file >> header;
    if (header != "SinglyLinkedList") {
        cout << "Invalid file format!\n";
        return;
    }
    int value;
    while (file >> value) {
        addToTail(value);
    }
    file.close();
}