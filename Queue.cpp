#include "Queue.h"
#include <iostream>
#include <fstream>

using namespace std;

Queue::Queue(int initialCapacity) {
    capacity = initialCapacity;
    data = new string[capacity];  // Изменено на string
    front = 0;
    rear = -1;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::push(const string& value) {  // Изменено на string
    if (rear == capacity - 1) {
        capacity *= 2;
        string* newData = new string[capacity];  // Изменено на string
        for (int i = 0; i <= rear; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[++rear] = value;
}

string Queue::pop() {  // Изменено на string
    if (front > rear) {
        cout << "Queue is empty!\n";
        return "";  // Возвращаем пустую строку вместо -1
    }
    return data[front++];
}

string Queue::peek() const {  // Изменено на string
    if (front > rear) {
        cout << "Queue is empty!\n";
        return "";  // Возвращаем пустую строку вместо -1
    }
    return data[front];
}

bool Queue::isEmpty() const {
    return front > rear;
}

void Queue::print() const {
    for (int i = front; i <= rear; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

void Queue::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for writing!\n";
        return;
    }
    file << "Queue\n";
    for (int i = front; i <= rear; i++) {
        file << data[i] << "\n";
    }
    file.close();
}

void Queue::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file for reading!\n";
        return;
    }
    string header;
    getline(file, header);
    if (header != "Queue") {
        cout << "Invalid file format!\n";
        return;
    }
    string value;
    while (getline(file, value)) {
        push(value);
    }
    file.close();
}