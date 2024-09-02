#include "vector.hpp"

template <typename T, int Size>
Vector<T, Size>::Vector() : Matrix<T, Size, 1>() {}

template <typename T, int Size>
Vector<T, Size>::Vector(int size) : Matrix<T, Size, 1>(size, 1) {
    this->actual_rows = size;
}

template<typename T, int Size>
Vector<T, Size>::Vector(const Matrix<T, Size, 1>& mat) {
        for (int i = 0; i < Size; ++i) {
            this->data[i] = mat(i, 0);
        }
    }

template <typename T, int Size>
Vector<T, Size> Vector<T, Size>::Zero(int size) {
    if constexpr (Size == DynamicSize) {
        if (size <= 0) {
            throw std::invalid_argument("Size must be greater than zero for dynamically-sized vector.");
        }
        return Vector<T, DynamicSize>(Matrix<T, DynamicSize, 1>::Zero(size, 1));
    } else {
        return Vector<T, Size>(Matrix<T, Size, 1>::Zero(Size, 1));
    }
}

template <typename T, int Size>
Vector<T, Size> Vector<T, Size>::One(int size) {
    if constexpr (Size == DynamicSize) {
        if (size <= 0) {
            throw std::invalid_argument("Size must be greater than zero for dynamically-sized vector.");
        }
        return Vector<T, DynamicSize>(Matrix<T, DynamicSize, 1>::One(size, 1));
    } else {
        return Vector<T, Size>(Matrix<T, Size, 1>::One(Size, 1));
    }
}

template <typename T, int Size>
Vector<T, Size> Vector<T, Size>::Unit(int size, int direction) {
    if constexpr (Size == DynamicSize) {
        if (size <= 0) {
            throw std::invalid_argument("Size must be greater than zero for dynamically-sized vector.");
        }
        if (direction < 0 || direction >= size) {
            throw std::out_of_range("Index out of range for unit vector");
        }
        Vector<T, DynamicSize> result = Vector<T, DynamicSize>::Zero(size);
        result(direction, 0) = T(1); // Set the nth element to 1
        return result;
    } else {
        if (direction < 0 || direction >= Size) {
            throw std::out_of_range("Index out of range for unit vector");
        }
        Vector<T, Size> result = Vector<T, Size>::Zero();
        result(direction, 0) = T(1); // Set the nth element to 1
        return result;
    }
}

// Overloading the [] operator
template<typename T, int Size>
T& Vector<T, Size>::operator[](int i) {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
const T& Vector<T, Size>::operator[](int i) const {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

// Overloading the () operator
template<typename T, int Size>
T& Vector<T, Size>::operator()(int i) {
    if (i < 0) {i += Size;}  // Handle negative indices
    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
const T& Vector<T, Size>::operator()(int i) const {
    if (i < 0) {i += Size;}  // Handle negative indices

    if (i < 0 || i >= Size) {
        throw std::out_of_range("Index out of range");
    }
    return this->data[i];
}

template<typename T, int Size>
RowVector<T, Size> Vector<T, Size>::transpose() const {
    RowVector<T, Size> result(this->actual_rows);
    for (int i = 0; i < this->actual_rows; ++i) {
        result(i) = this->data[i];
    }
    return result;
}

// Other methods
template<typename T, int Size>
int Vector<T, Size>::size() const {
    return (*this).actual_rows;
}

template <typename T, int Size>
T Vector<T, Size>::dot(const Vector& other) const {
    if (Size!= other.size()) {
        throw std::invalid_argument("Dot product requires vectors of the same size");
    }

    T result = T(0);
    for (int i = 0; i < Size; ++i) {
        result += (*this)(i) * other(i);
    }
    return result;
}
