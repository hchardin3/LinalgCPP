#include "vector3.hpp"

template<typename T>
Vector3<T>::Vector3() : VectorX<T>(3) {}

template<typename T>
Vector3<T>::Vector3(const T& x, const T& y, const T& z) : VectorX<T>(3) {
    this->data[0] = x;
    this->data[1] = y;
    this->data[2] = z;
}

// Specific utils
template<typename T>
T Vector3<T>::dot(const Vector3<T>& other) const {
    return this->data[0] * other.data[0] +
            this->data[1] * other.data[1] +
            this->data[2] * other.data[2];
}

template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& other) const {
    return Vector3<T>({
        this->data[1] * other.data[2] - this->data[2] * other.data[1],
        this->data[2] * other.data[0] - this->data[0] * other.data[2],
        this->data[0] * other.data[1] - this->data[1] * other.data[0]
    });
}
