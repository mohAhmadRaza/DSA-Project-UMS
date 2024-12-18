#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class MySTack {
private:
    vector<T> elements;

public:
    void push(const T& element);
    void pop();
    T top() const;
    bool isEmpty() const;
    size_t size() const;
    void display() const;
};

template <typename T>
void MySTack<T>::push(const T& element) {
    elements.push_back(element);
}

template <typename T>
void MySTack<T>::pop() {
    if (elements.empty()) {
        throw runtime_error("stack underflow: No elements to pop!");
    }
    elements.pop_back();
}

template <typename T>
T MySTack<T>::top() const {
    if (elements.empty()) {
        throw runtime_error("stack is empty: No top element!");
    }
    return elements.back();
}

template <typename T>
bool MySTack<T>::isEmpty() const {
    return elements.empty();
}

template <typename T>
size_t MySTack<T>::size() const {
    return elements.size();
}

#endif
