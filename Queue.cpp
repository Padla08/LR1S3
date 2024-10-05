#include "Queue.h"

using namespace std;

Queue::Queue(int initialCapacity) {
    capacity = initialCapacity;
    data = new int[capacity];
    front = 0;
    rear = -1;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::push(int value) {
    if (rear == capacity - 1) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= rear; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[++rear] = value;
}

int Queue::pop() {
    if (front > rear) {
        cout << "Queue is empty!\n";
        return -1;
    }
    return data[front++];
}

int Queue::peek() const {
    if (front > rear) {
        cout << "Queue is empty!\n";
        return -1;
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
    file >> header;
    if (header != "Queue") {
        cout << "Invalid file format!\n";
        return;
    }
    int value;
    while (file >> value) {
        push(value);
    }
    file.close();
}