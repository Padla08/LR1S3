#include "Stack.h"

using namespace std;

Stack::Stack(int initialCapacity) {
    capacity = initialCapacity;
    data = new int[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(int value) {
    if (top == capacity - 1) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= top; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[++top] = value;
}

int Stack::pop() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return data[top--];
}

int Stack::peek() const {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return data[top];
}

bool Stack::isEmpty() const {
    return top == -1;
}

void Stack::print() const {
    for (int i = 0; i <= top; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

void Stack::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "Stack\n";
    for (int i = 0; i <= top; i++) {
        file << data[i] << "\n";
    }
    file.close();
}

void Stack::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    file >> header;
    if (header != "Stack") {
        cout << "Invalid file format!\n";
        return;
    }
    int value;
    while (file >> value) {
        push(value);
    }
    file.close();
}