#include <iostream>
#include <string>
#include "Array.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "HashTable.h"
#include "CompleteBinaryTree.h"

using namespace std;

void arrayMenu() {
    Array arr;
    int choice, index;
    string value, filename;

    while (true) {
        cout << "Array Menu:\n";
        cout << "1. Add to index\n";
        cout << "2. Add to end\n";
        cout << "3. Get by index\n";
        cout << "4. Remove by index\n";
        cout << "5. Set by index\n";
        cout << "6. Length\n";
        cout << "7. Print\n";
        cout << "8. Save to file\n";
        cout << "9. Load from file\n";
        cout << "10. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Index: ";
            cin >> index;
            cout << "Value: ";
            cin >> value;
            arr.add(index, value);
            break;
        case 2:
            cout << "Value: ";
            cin >> value;
            arr.addToEnd(value);
            break;
        case 3:
            cout << "Index: ";
            cin >> index;
            cout << "Value: " << arr.get(index) << "\n";
            break;
        case 4:
            cout << "Index: ";
            cin >> index;
            arr.remove(index);
            break;
        case 5:
            cout << "Index: ";
            cin >> index;
            cout << "Value: ";
            cin >> value;
            arr.set(index, value);
            break;
        case 6:
            cout << "Length: " << arr.length() << "\n";
            break;
        case 7:
            arr.print();
            break;
        case 8:
            cout << "Enter filename: ";
            cin >> filename;
            arr.saveToFile(filename);
            break;
        case 9:
            cout << "Enter filename: ";
            cin >> filename;
            arr.loadFromFile(filename);
            break;
        case 10:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void singlyLinkedListMenu() {
    SinglyLinkedList list;
    int choice;
    string filename;
    string value;

    while (true) {
        cout << "Singly Linked List Menu:\n";
        cout << "1. Add to head\n";
        cout << "2. Add to tail\n";
        cout << "3. Remove from head\n";
        cout << "4. Remove from tail\n";
        cout << "5. Remove by value\n";
        cout << "6. Search\n";
        cout << "7. Print\n";
        cout << "8. Save to file\n";
        cout << "9. Load from file\n";
        cout << "10. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value: ";
            cin >> value;
            list.addToHead(value);
            break;
        case 2:
            cout << "Value: ";
            cin >> value;
            list.addToTail(value);
            break;
        case 3:
            list.removeFromHead();
            break;
        case 4:
            list.removeFromTail();
            break;
        case 5:
            cout << "Value: ";
            cin >> value;
            list.removeByValue(value);
            break;
        case 6:
            cout << "Value: ";
            cin >> value;
            cout << (list.search(value) ? "Found\n" : "Not Found\n");
            break;
        case 7:
            list.print();
            break;
        case 8:
            cout << "Enter filename: ";
            cin >> filename;
            list.saveToFile(filename);
            break;
        case 9:
            cout << "Enter filename: ";
            cin >> filename;
            list.loadFromFile(filename);
            break;
        case 10:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void doublyLinkedListMenu() {
    DoublyLinkedList list;
    int choice;
    string value, filename;

    while (true) {
        cout << "Doubly Linked List Menu:\n";
        cout << "1. Add to head\n";
        cout << "2. Add to tail\n";
        cout << "3. Remove from head\n";
        cout << "4. Remove from tail\n";
        cout << "5. Remove by value\n";
        cout << "6. Search\n";
        cout << "7. Print\n";
        cout << "8. Save to file\n";
        cout << "9. Load from file\n";
        cout << "10. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value: ";
            cin >> value;
            list.addToHead(value);
            break;
        case 2:
            cout << "Value: ";
            cin >> value;
            list.addToTail(value);
            break;
        case 3:
            list.removeFromHead();
            break;
        case 4:
            list.removeFromTail();
            break;
        case 5:
            cout << "Value: ";
            cin >> value;
            list.removeByValue(value);
            break;
        case 6:
            cout << "Value: ";
            cin >> value;
            cout << (list.search(value) ? "Found\n" : "Not Found\n");
            break;
        case 7:
            list.print();
            break;
        case 8:
            cout << "Enter filename: ";
            cin >> filename;
            list.saveToFile(filename);
            break;
        case 9:
            cout << "Enter filename: ";
            cin >> filename;
            list.loadFromFile(filename);
            break;
        case 10:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void queueMenu() {
    Queue queue;
    int choice;
    string value, filename;

    while (true) {
        cout << "Queue Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Print\n";
        cout << "5. Save to file\n";
        cout << "6. Load from file\n";
        cout << "7. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value: ";
            cin >> value;
            queue.push(value);
            break;
        case 2:
            cout << "Popped: " << queue.pop() << "\n";
            break;
        case 3:
            cout << "Peek: " << queue.peek() << "\n";
            break;
        case 4:
            queue.print();
            break;
        case 5:
            cout << "Enter filename: ";
            cin >> filename;
            queue.saveToFile(filename);
            break;
        case 6:
            cout << "Enter filename: ";
            cin >> filename;
            queue.loadFromFile(filename);
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void stackMenu() {
    Stack stack;
    int choice;
    string value, filename;

    while (true) {
        cout << "Stack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Print\n";
        cout << "5. Save to file\n";
        cout << "6. Load from file\n";
        cout << "7. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            cout << "Popped: " << stack.pop() << "\n";
            break;
        case 3:
            cout << "Peek: " << stack.peek() << "\n";
            break;
        case 4:
            stack.print();
            break;
        case 5:
            cout << "Enter filename: ";
            cin >> filename;
            stack.saveToFile(filename);
            break;
        case 6:
            cout << "Enter filename: ";
            cin >> filename;
            stack.loadFromFile(filename);
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void hashTableMenu() {
    HashTable hashTable;
    int choice;
    string key, value, filename;

    while (true) {
        cout << "Hash Table Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Get\n";
        cout << "3. Remove\n";
        cout << "4. Print\n";
        cout << "5. Save to file\n";
        cout << "6. Load from file\n";
        cout << "7. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Key: ";
            cin >> key;
            cout << "Value: ";
            cin >> value;
            hashTable.insert(key, value);
            break;
        case 2:
            cout << "Key: ";
            cin >> key;
            cout << "Value: " << hashTable.get(key) << "\n";
            break;
        case 3:
            cout << "Key: ";
            cin >> key;
            hashTable.remove(key);
            break;
        case 4:
            hashTable.print();
            break;
        case 5:
            cout << "Enter filename: ";
            cin >> filename;
            hashTable.saveToFile(filename);
            break;
        case 6:
            cout << "Enter filename: ";
            cin >> filename;
            hashTable.loadFromFile(filename);
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

void completeBinaryTreeMenu() {
    CompleteBinaryTree tree;
    int choice;
    string value, filename;

    while (true) {
        cout << "Complete Binary Tree Menu:\n";
        cout << "1. Add\n";
        cout << "2. Search\n";
        cout << "3. Print\n";
        cout << "4. Is Complete\n";
        cout << "5. Save to file\n";
        cout << "6. Load from file\n";
        cout << "7. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value: ";
            cin >> value;
            tree.add(value);
            break;
        case 2:
            cout << "Value: ";
            cin >> value;
            cout << (tree.search(value) ? "Found\n" : "Not Found\n");
            break;
        case 3:
            tree.print();
            break;
        case 4:
            cout << (tree.isComplete() ? "Complete\n" : "Not Complete\n");
            break;
        case 5:
            cout << "Enter filename: ";
            cin >> filename;
            tree.saveToFile(filename);
            break;
        case 6:
            cout << "Enter filename: ";
            cin >> filename;
            tree.loadFromFile(filename);
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Main Menu:\n";
        cout << "1. Array\n";
        cout << "2. Singly Linked List\n";
        cout << "3. Doubly Linked List\n";
        cout << "4. Queue\n";
        cout << "5. Stack\n";
        cout << "6. Hash Table\n";
        cout << "7. Complete Binary Tree\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            arrayMenu();
            break;
        case 2:
            singlyLinkedListMenu();
            break;
        case 3:
            doublyLinkedListMenu();
            break;
        case 4:
            queueMenu();
            break;
        case 5:
            stackMenu();
            break;
        case 6:
            hashTableMenu();
            break;
        case 7:
            completeBinaryTreeMenu();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}