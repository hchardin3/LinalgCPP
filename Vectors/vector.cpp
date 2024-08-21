#include "vector.hpp"


// Constructor
template <typename T>
VectorX<T>::VectorX(int size) : data(new int[size]), size(size) {}

template <typename T>
VectorX<T> VectorX<T>::Zero(int size) {
    VectorX<T> vec = new VectorX<T>(size);
    for (int i = 0; i < size; i++) {
        vec.data[i] = 0;
    }
    return vec;
}

template <typename T>
VectorX<T> VectorX<T>::One(int size) {
    VectorX<T> vec = new VectorX<T>(size);
    for (int i = 0; i < size; i++) {
        vec.data[i] = 1;
    }
    return vec;
}

template <typename T>
VectorX<T> VectorX<T>::Unit(int size, int direction) {
    if (direction < 0 || direction >= size) {
        throw std::out_of_range("Direction index out of range");
    }
    VectorX<T> vec = Zero(size);
    vec[direction] = 1;
    return vec;
}

template <typename T>
VectorX<T> VectorX<T>::Random(int size, T min, T max) {
    if (size <= 0) {
        throw std::invalid_argument("Size must be a positive integer");
    }
    VectorX<T> vec = Zero(size);
    for (int i = 0; i < size; i++) {
        vec.data[i] = min + static_cast<T>(rand()) / (static_cast<T>(RAND_MAX / (max - min)));
    }
    return vec;
}

// Operators
template <typename T>
VectorX<T> VectorX<T>::operator+(const VectorX<T>& other) const {
    if (size!= other.size) {
        throw std::invalid_argument("VectorXs must have the same size for addition");
    }
    VectorX<T> result = new VectorX<T>(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator-(const VectorX<T>& other) const {
    if (size!= other.size) {
        throw std::invalid_argument("VectorXs must have the same size for subtraction");
    }
    VectorX<T> result = new VectorX<T>(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] - other.data[i];
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator*(const T& value) const {
    VectorX<T> result = new VectorX<T>(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] * value;
    }
    return result;
}

template <typename T>
VectorX<T> VectorX<T>::operator/(const T& value) const {
    if (value == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    VectorX<T> result = new VectorX<T>(size);
    for (int i = 0; i < size; i++) {
        result.data[i] = data[i] / value;
    }
    return result;
}

// Utils
template <typename T>
bool VectorX<T>::isTransposed() const {return is_transposed; }

template <typename T>
void VectorX<T>::transpose() {
    is_transposed =!is_transposed;
}

template <typename T>
T VectorX<T>::norm() const {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i] * data[i];
    }
    return std::sqrt(sum);
}

template <typename T>
VectorX<T> VectorX<T>::normalize() const {
    T magnitude = norm();
    if (magnitude == 0) {
        throw std::runtime_error("Cannot normalize a zero VectorX");
    }
    return *this / magnitude;
}

// Display
template <typename T>
void VectorX<T>::display() const {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        if(i < size - 1) {
            std::cout << data[i] << ", ";
        } else {
            std::cout << data[i];
        }
    }
    std::cout << "]" << std::endl;
}