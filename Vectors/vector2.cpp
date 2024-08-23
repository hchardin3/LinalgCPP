#include "vector2.hpp"

template <typename T>
Vector2<T>::Vector2() : VectorX<T, 2>() {}

template <typename T>
Vector2<T>::Vector2(const T& x, const T& y) : VectorX<T, 2>() {
        this->data[0] = x;
        this->data[1] = y;
    }

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