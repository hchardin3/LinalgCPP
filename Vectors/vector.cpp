#include "vector.hpp"

template <typename T, int Size>
VectorX<T, Size>::VectorX() : MatrixX<T, Size, 1>() {}

template <typename T, int Size>
VectorX<T, Size> VectorX<T, Size>::Unit(int n) const { 
        if (n < 0) {n += Size;}  // Handle negative indices
        if (n < 0 || n >= Size) {
            throw std::out_of_range("Index out of range for unit vector");
        }
        VectorX result;
        result = VectorX::Zero(); // Initialize with zeros
        result(n, 0) = T(1);      // Set the n-th element to 1
        return result;
}

// Overloading the [] operator
template<typename T, int Size>
T& VectorX<T, Size>::operator[](int i) {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
const T& VectorX<T, Size>::operator[](int i) const {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

// Overloading the () operator
template<typename T, int Size>
T& VectorX<T, Size>::operator()(int i) {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
const T& VectorX<T, Size>::operator()(int i) const {
    if (i < 0) {i += Size;}  // Handle negative indices

    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

// Other methods
template <typename T, int Size>
T VectorX<T, Size>::dot(const VectorX& other) const {
    if (Size!= other.size()) {
        throw std::invalid_argument("Dot product requires vectors of the same size");
    }

    T result = T(0);
    for (int i = 0; i < Size; ++i) {
        result += (*this)(i) * other(i);
    }
    return result;
}
