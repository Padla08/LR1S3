# Лабораторная работа №1 Семестр 3
<p><b>Цели и задачи работы:</b>
<p>изучение алгоритмов формирования и работы с абстрактными структурами данных.</p>
<p></p><b>Задание к работе:</b></p>
<p></p>1. Разработать алгоритм решения задачи по индивидуальному заданию.

<p> 2. Написать и отладить программу решения задачи.</p>
<p>3. Протестировать работу программы на различных исходных данных.</p>
<p> 4. По запросу преподавателя быть готовым модифицировать алгоритм и добавить операцию работы с данными.</p>
<p>5. Отобразить работу с git</p>
</p>

<h2>Пример работы:</h2>
<p>В качестве примера мы возьмём первое задание, выполненное на ЯП <em>C++</em>:</p>

```cpp

#include "Stack.h"
using namespace std;

// Конструктор с параметром начальной вместимости
Stack::Stack(int initialCapacity) {
    capacity = initialCapacity;
    data = new int[capacity];
    top = -1;
}

// Деструктор
Stack::~Stack() {
    delete[] data;
}

// Добавление элемента в стек
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

// Удаление элемента из стека
int Stack::pop() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return data[top--];
}

// Получение элемента с вершины стека без удаления
int Stack::peek() const {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }
    return data[top];
}

// Проверка, пуст ли стек
bool Stack::isEmpty() const {
    return top == -1;
}

// Вывод стека на экран
void Stack::print() const {
    for (int i = 0; i <= top; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
}

// Сохранение стека в файл
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

// Загрузка стека из файла
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


```
<p>Давайте разберём наш код: </p>
<p>Необходимо было воспроизвести собственно ручно такую структуру данных как массив,стэк, двусвязный/односвязный списки, хэш таблицу, законченное бинарное дерево. В данном коде представлен Стэк, а именно его файл объявления.  </p>
<p>В процессе выполнения задачи трудностей не возникло, так как в целом это было просто игра в конструктор лего, создавая свою АТД. Единственная трудность которая могла возникнуть, это запрет на использование стандартных типов данных.</p>

<p>Вывод:</p>

<p>В целом, лабораторная работа была довольно простой и не заставляла как-то сильно напрягаться. </em></p>
<b>В работе остальных кодов вы можете убедится сами, желаю удачи!</b>
