#include "vector3.hpp"

template<typename T>
Vector3<T>::Vector3() : Vector<T, 3>() {}

template<typename T>
Vector3<T>::Vector3(const T& x, const T& y, const T& z) : Vector<T, 3>() {
    this->data[0] = x;
    this->data[1] = y;
    this->data[2] = z;
}

template<typename T>
Vector3<T>::Vector3(const Vector<T, 3>& vector) : Vector<T, 3>() {
    this.data = vector.data;
}

template<typename T>
Vector3<T> Vector3<T>::Zero() {
    return Vector3<T>(T(0), T(0), T(0));
}

template<typename T>
Vector3<T> Vector3<T>::One() {
    return Vector3<T>(T(1), T(1), T(1));
}

template<typename T>
Vector3<T> Vector3<T>::Unit(int direction) {
    switch (direction) {
        case 0: return Vector3<T>(T(1), T(0), T(0));
        case 1: return Vector3<T>(T(0), T(1), T(0));
        case 2: return Vector3<T>(T(0), T(0), T(1));
        default: throw std::out_of_range("Invalid direction for unit vector");
    }
}

// Specific utils
template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& other) const {
    return Vector3<T>(
        this->data[1] * other.data[2] - this->data[2] * other.data[1],
        this->data[2] * other.data[0] - this->data[0] * other.data[2],
        this->data[0] * other.data[1] - this->data[1] * other.data[0]
    );
}

template<typename T>
RowVector3<T> Vector3<T>::transpose() const {
    return RowVector3<T>(this->data[0], this->data[1], this->data[2]);
}