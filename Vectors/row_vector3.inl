#include "row_vector3.hpp"

template<typename T>
RowVector3<T>::RowVector3() : RowVector<T, 3>() {}

template <typename T>
RowVector3<T>::RowVector3(const RowVector<T, 3>& other) : RowVector<T, 3>(other) {}

template<typename T>
RowVector3<T>::RowVector3(const T& x, const T& y, const T& z) : RowVector<T, 3>() {
    this->data[0] = x;
    this->data[1] = y;
    this->data[2] = z;
}

template<typename T>
RowVector3<T>::RowVector3(const Matrix<T, 1, 3>& matrix) : RowVector<T, 3>(matrix) {}

// Special constructors
template <typename T>
RowVector3<T> RowVector3<T>::Zero() {
    return RowVector3(T(0), T(0), T(0));
}

template <typename T>
RowVector3<T> RowVector3<T>::One() {
    return RowVector3(T(1), T(1), T(1));
}

template <typename T>
RowVector3<T> RowVector3<T>::Unit(int direction) {
    switch(direction) {
        case 0:
            return RowVector3(T(1), T(0), T(0));
        case 1:
            return RowVector3(T(0), T(1), T(0));
        case 2:
            return RowVector3(T(0), T(0), T(1));
        default:
            throw std::out_of_range("Invalid direction for unit vector");
    }
}

// Specific utils
template<typename T>
RowVector3<T> RowVector3<T>::cross(const RowVector3<T>& other) const {
    return RowVector3<T>({
        this->data[1] * other.data[2] - this->data[2] * other.data[1],
        this->data[2] * other.data[0] - this->data[0] * other.data[2],
        this->data[0] * other.data[1] - this->data[1] * other.data[0]
    });
}

template<typename T>
Vector3<T> RowVector3<T>::transpose() const {
    Vector3<T> result;
    for (int i = 0; i < this->actual_cols; ++i) {
        result(i) = this->data[i];
    }
    return result;
}
