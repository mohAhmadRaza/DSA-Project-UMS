#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
private:
    vector<T> elements; 
    size_t frontIndex = 0;

public:
    // Function declarations
    void enqueue(const T& element);
    void dequeue();
    T front() const;
    bool isEmpty() const;
    size_t size() const;
    void display() const;
};

// Function definitions

template <typename T>
void Queue<T>::enqueue(const T& element) {
    elements.push_back(element);
}

template <typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue underflow!");
    }
    frontIndex++;

    // Erase unused elements to optimize memory
    if (frontIndex > elements.size() / 2) {
        elements.erase(elements.begin(), elements.begin() + frontIndex);
        frontIndex = 0;
    }
}

template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty!");
    }
    return elements[frontIndex];
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return frontIndex >= elements.size();
}

template <typename T>
size_t Queue<T>::size() const {
    return elements.size() - frontIndex;
}

template <typename T>
void Queue<T>::display() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements (front to back):" << endl;
    for (size_t i = frontIndex; i < elements.size(); ++i) {
        cout << elements[i] << " ";
    }
    cout << endl;
}

#endif // QUEUE_H
