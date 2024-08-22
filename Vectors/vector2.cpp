#include "vector2.hpp"

template<typename T>
Vector2<T> Vector2<T>::operator*(const Matrix2<T>& mat) const {
    if (!isTransposed()) {
        throw std::runtime_error("Vector must be transposed for line multiplication with Matrix");
    }
    return Vector2(
        mat(0, 0) * this->x() + mat(1, 0) * this->y(),
        mat(0, 1) * this->x() + mat(1, 1) * this->y()
    );
    
}

template <typename T>
T Vector2<T>::angle(const Vector2& other) const {
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