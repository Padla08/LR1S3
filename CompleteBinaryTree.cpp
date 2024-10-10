#include "CompleteBinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

CompleteBinaryTree::CompleteBinaryTree(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    data = new string[capacity];
}

CompleteBinaryTree::~CompleteBinaryTree() {
    delete[] data;
}

void CompleteBinaryTree::add(const string& value) {
    if (size == capacity) {
        capacity *= 2;
        string* newData = new string[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;
}

bool CompleteBinaryTree::search(const string& value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

void CompleteBinaryTree::print() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

bool CompleteBinaryTree::isComplete() const {
    for (int i = 0; i < size; i++) {
        if (data[i].empty()) {
            return false;
        }
    }
    return true;
}

void CompleteBinaryTree::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "CompleteBinaryTree\n";
    for (int i = 0; i < size; i++) {
        file << data[i] << "\n";
    }
    file.close();
}

void CompleteBinaryTree::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    file >> header;
    if (header != "CompleteBinaryTree") {
        cout << "Invalid file format!\n";
        return;
    }
    string value;
    while (file >> value) {
        add(value);
    }
    file.close();
}