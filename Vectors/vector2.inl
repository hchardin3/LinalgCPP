#include "vector2.hpp"

template <typename T>
Vector2<T>::Vector2() : Vector<T, 2>() {}

template <typename T>
Vector2<T>::Vector2(const T& x, const T& y) : Vector<T, 2>() {
    this->data[0] = x;
    this->data[1] = y;
}

template <typename T>
Vector2<T>::Vector2(const Vector<T, 2>& vector) : Vector<T, 2>(vector) {}

template <typename T>
Vector2<T>::Vector2(const Matrix<T, 2, 1>& matrix) : Vector<T, 2>(matrix) {
}

template <typename T>
Vector2<T> Vector2<T>::Zero() {
    return Vector2(T(0), T(0));
}

template <typename T>
Vector2<T> Vector2<T>::One() {
    return Vector2(T(1), T(1));
}

template <typename T>
Vector2<T> Vector2<T>::Unit(int direction) {
    switch (direction) {
        case 0:
            return Vector2(T(1), T(0));
        
        case 1:
            return Vector2(T(0), T(1));
        
        default:
            throw std::out_of_range("Invalid direction for unit vector");
    }
}

// Functions
template <typename T>
T Vector2<T>::angle(const Vector2<T>& other) const {
    T dot_product = this->dot(other);
    T mags = this->magnitude() * other.magnitude();
    if(mags == 0) {
        throw std::runtime_error("Cannot calculate angle with zero magnitude vectors");
    }
    return std::acos(dot_product / mags);
}

template <typename T>
Vector2<T> Vector2<T>::rotate(T angle) const {
    T cos_angle = std::cos(angle);
    T sin_angle = std::sin(angle);
    return Vector2(cos_angle * this->x() - sin_angle * this->y(), sin_angle * this->x() + cos_angle * this->y());
}

template<typename T>
RowVector2<T> Vector2<T>::transpose() const {
    return RowVector2(this->x(), this->y());
}