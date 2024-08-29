#include "row_vector2.hpp"

template <typename T>
RowVector2<T>::RowVector2() : RowVector<T, 2>() {}

template <typename T>
RowVector2<T>::RowVector2(const RowVector<T, 2>& other) : RowVector<T, 2>(other) {}

template <typename T>
RowVector2<T>::RowVector2(const T& x, const T& y) : RowVector<T, 2>() {
        this->data[0] = x;
        this->data[1] = y;
    }

// Special constructors
template <typename T>
RowVector2<T> RowVector2<T>::Zero() {
    return RowVector2(T(0), T(0));
}

template <typename T>
RowVector2<T> RowVector2<T>::One() {
    return RowVector2(T(1), T(1));
}

template <typename T>
RowVector2<T> RowVector2<T>::Unit(int direction) {
    switch(direction) {
        case 0:
            return RowVector2(T(1), T(0));
        case 1:
            return RowVector2(T(0), T(1));
        default:
            throw std::out_of_range("Invalid direction for unit vector");
    }
}

// Operators
template<typename T>
RowVector2<T> RowVector2<T>::operator+(const RowVector2<T>& other) const {
    return RowVector2((*this) + other);
}

template<typename T>
RowVector2<T> RowVector2<T>::operator-(const RowVector2<T>& other) const {
    return RowVector2((*this) - other);
}

template <typename T>
RowVector2<T> RowVector2<T>::operator*(const T& scalar) const {
    return RowVector2((*this) * scalar);
}

template <typename T>
RowVector2<T> RowVector2<T>::operator/(const T& scalar) const {
    return RowVector2((*this) / scalar);
}

template <typename T>
RowVector2<T>& RowVector2<T>::operator+=(const RowVector2<T>& other) {
    (*this) = (*this) + other;
    return true;
}

template <typename T>
RowVector2<T>& RowVector2<T>::operator-=(const RowVector2<T>& other) {
    (*this) = (*this) - other;
    return true;
}

// Functions
template <typename T>
T RowVector2<T>::angle(const RowVector2<T>& other) const {
    T dot_product = this->dot(other);
    T mags = this->magnitude() * other.magnitude();
    if(mags == 0) {
        throw std::runtime_error("Cannot calculate angle with zero magnitude vectors");
    }
    return std::acos(dot_product / mags);
}

template <typename T>
RowVector2<T> RowVector2<T>::rotate(T angle) const {
    T cos_angle = std::cos(angle);
    T sin_angle = std::sin(angle);
    return RowVector2(cos_angle * this->x() - sin_angle * this->y(), sin_angle * this->x() + cos_angle * this->y());
}

template<typename T>
Vector2<T> RowVector2<T>::transpose() const {
    Vector2<T> result(this->x(), this->y());
    return result;
}