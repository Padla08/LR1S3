#include "CompleteBinaryTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

CompleteBinaryTree::CompleteBinaryTree(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    data = new int[capacity];
}

CompleteBinaryTree::~CompleteBinaryTree() {
    delete[] data;
}

void CompleteBinaryTree::add(int value) {
    // Проверка на уникальность значения
    if (search(value)) {
        cout << "Value already exists in the tree.\n";
        return;
    }

    if (size == capacity) {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value;
}

bool CompleteBinaryTree::search(int value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

void CompleteBinaryTree::print() const {
    int height = log2(size + 1);
    int maxWidth = pow(2, height) * 2;

    for (int level = 0; level <= height; level++) {
        int levelStart = pow(2, level) - 1;
        int levelEnd = pow(2, level + 1) - 2;
        int levelWidth = pow(2, height - level) * 2;

        for (int i = levelStart; i <= levelEnd && i < size; i++) {
            int padding = (maxWidth / (levelWidth + 1)) - 1;
            for (int p = 0; p < padding; p++) {
                cout << " ";
            }
            cout << data[i];
            for (int p = 0; p < padding; p++) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void CompleteBinaryTree::printAsTable() const {
    for (int i = 0; i < size; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        cout << "Node " << i << ": " << data[i];
        if (leftChild < size) {
            cout << " Left Child: " << data[leftChild];
        }
        if (rightChild < size) {
            cout << " Right Child: " << data[rightChild];
        }
        cout << "\n";
    }
}

bool CompleteBinaryTree::isComplete() const {
    // Вычисляем высоту дерева
    int height = log2(size + 1);

    // Максимальное количество узлов для полного бинарного дерева на высоте height
    int maxNodes = (1 << height) - 1;

    // Если количество узлов равно максимальному, то дерево полное
    if (size == maxNodes) {
        return true;
    }

    // Если количество узлов меньше максимального, проверяем, что все узлы на последнем уровне расположены слева
    int lastLevelStart = (1 << (height - 1)) - 1; // Индекс начала последнего уровня
    int lastLevelEnd = (1 << height) - 2; // Индекс конца последнего уровня

    // Проверяем, что все узлы на последнем уровне расположены слева
    for (int i = lastLevelStart; i < size; i++) {
        if (i > lastLevelEnd) {
            return false; // Если есть пропуски, дерево не полное
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
    int value;
    while (file >> value) {
        add(value);
    }
    file.close();
}