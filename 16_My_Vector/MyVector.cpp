#include "MyVector.hpp"
#include <iostream>
#include <algorithm> // Add this for std::max

// Implement constructor

template <typename T>
MyVector<T>::MyVector(int capacity) : size(0) {
    this->capacity = capacity;
    elements = new T[capacity];
}

template <typename T>
MyVector<T>::~MyVector() {
    delete [] elements;
}
template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other) {
    capacity = other.capacity;
    size = other.size;
    elements = new T[capacity];
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (size >= capacity) {
      allocate_memory(2 * capacity);
    }
    elements[size] = value;
    size++;
}

template <typename T>
T MyVector<T>::pop_back(void) {
    if (size > 0) {
        if (size - 1 < capacity / 2) {
            allocate_memory(capacity / 2);
        }
        return elements[--size];
    }
    throw "The vector is empty";
}

template <typename T>
void MyVector<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void MyVector<T>::allocate_memory(int memory_size){
    if (memory_size < 1) memory_size = 1; // Ensure at least 1
    T *old = elements;
    elements = new T[memory_size];
    for(int i = 0; i < size; i++){
        elements[i] = old[i];
    }
    delete [] old;
    capacity = memory_size;
}

template <typename T>
T& MyVector<T>::at(int index) {
    if (index < 0 || index > size-1) {
        throw "Invalid index";
    }
    return elements[index];
}

template <typename T>
void MyVector<T>::clear() {
    size = 0;
    allocate_memory(1);
}
template <typename T>
void MyVector<T>::getSize() const {
    
    return size;
}
template <typename T>
void MyVector<T>::push_front(const T& value) {
    if (size >= capacity) {
        allocate_memory(2 * capacity);
    }
    for (int i = size; i > 0; i--) {
        elements[i] = elements[i - 1];
    }
    elements[0] = value;
    size++;
}

template <typename T>
void MyVector<T>::insert(int pos, const T& value) {
    if (pos < 0 || pos > size) {
        throw "Invalid position";
    }
    if (size >= capacity) {
        allocate_memory(2 * capacity);
    }
    for (int i = size; i > pos; i--) {
        elements[i] = elements[i - 1];
    }
    elements[pos] = value;
    size++;
}