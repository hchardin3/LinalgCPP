#include "row_vector.hpp"

template <typename T, int Size>
RowVector<T, Size>::RowVector() : Matrix<T, 1, Size>() {}

template <typename T, int Size>
RowVector<T, Size>::RowVector(int size) : Matrix<T, 1, Size>(1, size) {
    this->actual_cols = size;
}

template <typename T, int Size>
RowVector<T, Size>::RowVector(const Matrix<T, 1, Size>& other) {
    this.data = other.data;
}

template <typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::Unit(int n) const { 
        if (n < 0) {n += Size;}  // Handle negative indices
        if (n < 0 || n >= Size) {
            throw std::out_of_range("Index out of range for unit vector");
        }
        RowVector result;
        result = RowVector::Zero(); // Initialize with zeros
        result(n, 0) = T(1);      // Set the n-th element to 1
        return result;
}

// Operators
template<typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::operator+(const RowVector<T, Size>& other) const {
    return RowVector<T, Size>((*this) + other);
}

template<typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::operator-(const RowVector<T, Size>& other) const {
    return RowVector<T, Size>((*this) - other);
}

template<typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::operator*(const T& scalar) const {
    return RowVector<T, Size>((*this) * scalar);
}

template<typename T, int Size>
RowVector<T, Size> RowVector<T, Size>::operator/(const T& scalar) const {
    return RowVector<T, Size>((*this) / scalar);
}

template<typename T, int Size>
template<int N>
RowVector<T, N> RowVector<T, Size>::operator*(const Matrix<T, Size, N>& other) const {
    return RowVector<T, N>((*this) * other);
}

template<typename T, int Size>
T RowVector<T, Size>::operator*(const Vector<T, Size>& other) const {
    return (*this) * other;
}

template<typename T, int Size>
RowVector<T, Size>& RowVector<T, Size>::operator+=(const RowVector<T, Size>& other) {
    (*this) = (*this) + other;
    return *this;
}

template<typename T, int Size>
RowVector<T, Size>& RowVector<T, Size>::operator-=(const RowVector<T, Size>& other) {
    (*this) = (*this) - other;
    return *this;
}

template<typename T, int Size>
RowVector<T, Size>& RowVector<T, Size>::operator*=(const T& scalar) {
    (*this) = (*this) * scalar;
    return *this;
}

template<typename T, int Size>
RowVector<T, Size>& RowVector<T, Size>::operator/=(const T& scalar) {
    (*this) = (*this) / scalar;
    return *this;
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
