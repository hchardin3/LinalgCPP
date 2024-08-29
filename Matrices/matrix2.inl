#include "matrix2.hpp"

// Constructor implementations
template<typename T>
Matrix2<T>::Matrix2() : MatrixS<T, 2>() {}

template<typename T>
Matrix2<T>::Matrix2(const Matrix<T, 2, 2>& m) : MatrixS<T, 2>(m) {}

template<typename T>
Matrix2<T> Matrix2<T>::Zero() const  {
    return Matrix2<T>(MatrixS<T, 2>::Zero(2));
}

template<typename T>
Matrix2<T> Matrix2<T>::One() const {
    return Matrix2<T>(MatrixS<T, 2>::One(2));
}

template<typename T>
Matrix2<T> Matrix2<T>::Identity() const  {
    return Matrix2<T>(MatrixS<T, 2>::Identity(2));
}

// Operators
template<typename T>
Matrix2<T> Matrix2<T>::operator+(const Matrix2<T>& other) const {
    return Matrix2<T>((*this) + other);
}

template<typename T>
Matrix2<T> Matrix2<T>::operator-(const Matrix2<T>& other) const {
    return Matrix2<T>((*this) - other);;
}

template<typename T>
Matrix2<T> Matrix2<T>::operator*(const Matrix2<T>& other) const {
    return Matrix2<T>((*this) * other);
}

template<typename T>
Matrix2<T> Matrix2<T>::operator*(T scalar) const {
    return Matrix2<T>((*this) * scalar);
}

template<typename T>
Matrix2<T> Matrix2<T>::operator/(T scalar) const {
    return Matrix2<T>((*this) / scalar);
}

template<typename T>
Matrix2<T>& Matrix2<T>::operator+=(const Matrix2<T>& other) {
    (*this) = (*this) + other;
    return *this;
}

template<typename T>
Matrix2<T>& Matrix2<T>::operator-=(const Matrix2<T>& other) {
    (*this) = (*this) - other;
    return *this;
}

template<typename T>
Matrix2<T>& Matrix2<T>::operator*=(const Matrix2<T>& other) {
    (*this) = (*this) * other;
    return *this;
}

template<typename T>
Matrix2<T>& Matrix2<T>::operator*=(T scalar) {
    (*this) = (*this) * scalar;
    return *this;
}

template<typename T>
Matrix2<T>& Matrix2<T>::operator/=(T scalar) {
    (*this) = (*this) / scalar;
    return *this;
}

// Vector operations
template<typename T>
Vector2<T> Matrix2<T>::operator*(const Vector2<T>& other) const {
    return Vector2<T>((*this) * other);
}

// Method to create a 2x2 rotation matrix
template<typename T>
Matrix2<T> Matrix2<T>::Rotation(T angle_in_radians) {
    Matrix2<T> rotation_matrix;
    T cos_theta = std::cos(angle_in_radians);
    T sin_theta = std::sin(angle_in_radians);

    rotation_matrix(0, 0) = cos_theta;
    rotation_matrix(0, 1) = -sin_theta;
    rotation_matrix(1, 0) = sin_theta;
    rotation_matrix(1, 1) = cos_theta;

    return rotation_matrix;
}

// Explicit template instantiation for commonly used types
template class Matrix2<double>;
template class Matrix2<int>;
template class Matrix2<float>;
