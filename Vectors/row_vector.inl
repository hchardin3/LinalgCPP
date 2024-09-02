#include "row_vector.hpp"

template <typename T, int Size>
RowVector<T, Size>::RowVector() : Matrix<T, 1, Size>() {}

template <typename T, int Size>
RowVector<T, Size>::RowVector(int size) : Matrix<T, 1, Size>(1, size) {
    this->actual_cols = size;
}

template <typename T, int Size>
RowVector<T, Size>::RowVector(const Matrix<T, 1, Size>& other) : Matrix<T, 1, Size>(other) {}

template <typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::Zero(int size) {
    return RowVector<T, Size>(Matrix<T, 1, Size>::Zero(1, size));
}

template <typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::One(int size) {
    return RowVector<T, Size>(Matrix<T, 1, Size>::Ones(1, size));
}

template <typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::Unit(int size, int direction) { 
        if (direction < 0) {direction += size;}  // Handle negative indices
        if (direction < 0 || direction >= size) {
            throw std::out_of_range("Index out of range for unit vector");
        }
        RowVector result;
        result = RowVector::Zero(size); // Initialize with zeros
        result(direction, 0) = T(1);      // Set the n-th element to 1
        return result;
}

// Overloading the [] operator
template<typename T, int Size>
T& RowVector<T, Size>::operator[](int i) {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
const T& RowVector<T, Size>::operator[](int i) const {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

// Overloading the () operator
template<typename T, int Size>
T& RowVector<T, Size>::operator()(int i) {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
const T& RowVector<T, Size>::operator()(int i) const {
    if (i < 0) {i += Size;}  // Handle negative indices

    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
int RowVector<T, Size>::size() const {
    return this->actual_cols;
}

template<typename T, int Size>
Vector<T, Size> RowVector<T, Size>::transpose() const {
    Vector<T, Size> result(this->actual_cols);
    for (int i = 0; i < this->actual_cols; ++i) {
        result(i) = this->data[i];
    }
    return result;
}


// Other methods
template <typename T, int Size>
T RowVector<T, Size>::dot(const RowVector& other) const {
    if (Size!= other.size()) {
        throw std::invalid_argument("Dot product requires vectors of the same size");
    }

    T result = T(0);
    for (int i = 0; i < Size; ++i) {
        result += (*this)(i) * other(i);
    }
    return result;
}
