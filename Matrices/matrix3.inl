#include "matrix3.hpp"

// Constructor implementations
template<typename T>
Matrix3<T>::Matrix3() : MatrixS<T, 3>() {}

template<typename T>
Matrix3<T>::Matrix3(const Matrix<T, 3, 3>& m) : MatrixS<T, 3>(m) {}

template<typename T>
Matrix3<T>::Matrix3(const MatrixS<T, 3>& m) : MatrixS<T, 3>(m) {}

// Generation methods
template<typename T>
Matrix3<T> Matrix3<T>::Zero() {
    return Matrix3<T>(Matrix<T, 3, 3>::Zero(3));
}

template<typename T>
Matrix3<T> Matrix3<T>::One() {
    return Matrix3<T>(Matrix<T, 3, 3>::One(3));
}

template<typename T>
Matrix3<T> Matrix3<T>::Identity() {
    return Matrix3<T>(MatrixS<T, 3>::Identity(3));
}

// Operators
template<typename T>
Matrix3<T> Matrix3<T>::operator+(const Matrix3<T>& other) const {
    return Matrix3<T>((*this) + other);

}

template<typename T>
Matrix3<T> Matrix3<T>::operator-(const Matrix3<T>& other) const {
    return Matrix3<T>((*this) - other);
}

template<typename T>
Matrix3<T> Matrix3<T>::operator*(const Matrix3<T>& other) const {
    return Matrix3<T>((*this) * other);
}

template<typename T>
Matrix3<T> Matrix3<T>::operator*(T scalar) const {
    return Matrix3<T>((*this) * scalar);
}

template<typename T>
Matrix3<T> Matrix3<T>::operator/(T scalar) const {
    return Matrix3<T>((*this) / scalar);
}

template<typename T>
Vector3<T> Matrix3<T>::operator*(const Vector3<T>& vector) const {
    return Vector3<T>((*this) * vector);
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator+=(const Matrix3<T>& other) {
    (*this) = (*this) + other;
    return *this;
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator-=(const Matrix3<T>& other) {
    (*this) = (*this) - other;
    return *this;
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator*=(const Matrix3<T>& other) {
    (*this) = (*this) * other;
    return *this;
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator*=(T scalar) {
    (*this) = (*this) * scalar;
    return *this;
}

template<typename T>
Matrix3<T>& Matrix3<T>::operator/=(T scalar) {
    (*this) = (*this) / scalar;
    return *this;
}

// Method to create a 3x3 rotation matrix around the X-axis
template<typename T>
Matrix3<T> Matrix3<T>::RotationX(T angle_in_radians) {
    Matrix3<T> rotation_matrix;
    T cos_theta = std::cos(angle_in_radians);
    T sin_theta = std::sin(angle_in_radians);

    rotation_matrix(0, 0) = static_cast<T>(1);
    rotation_matrix(0, 1) = static_cast<T>(0);
    rotation_matrix(0, 2) = static_cast<T>(0);

    rotation_matrix(1, 0) = static_cast<T>(0);
    rotation_matrix(1, 1) = cos_theta;
    rotation_matrix(1, 2) = -sin_theta;

    rotation_matrix(2, 0) = static_cast<T>(0);
    rotation_matrix(2, 1) = sin_theta;
    rotation_matrix(2, 2) = cos_theta;

    return rotation_matrix;
}

// Method to create a 3x3 rotation matrix around the Y-axis
template<typename T>
Matrix3<T> Matrix3<T>::RotationY(T angle_in_radians) {
    Matrix3<T> rotation_matrix;
    T cos_theta = std::cos(angle_in_radians);
    T sin_theta = std::sin(angle_in_radians);

    rotation_matrix(0, 0) = cos_theta;
    rotation_matrix(0, 1) = static_cast<T>(0);
    rotation_matrix(0, 2) = sin_theta;

    rotation_matrix(1, 0) = static_cast<T>(0);
    rotation_matrix(1, 1) = static_cast<T>(1);
    rotation_matrix(1, 2) = static_cast<T>(0);

    rotation_matrix(2, 0) = -sin_theta;
    rotation_matrix(2, 1) = static_cast<T>(0);
    rotation_matrix(2, 2) = cos_theta;

    return rotation_matrix;
}

// Method to create a 3x3 rotation matrix around the Z-axis
template<typename T>
Matrix3<T> Matrix3<T>::RotationZ(T angle_in_radians) {
    Matrix3<T> rotation_matrix;
    T cos_theta = std::cos(angle_in_radians);
    T sin_theta = std::sin(angle_in_radians);

    rotation_matrix(0, 0) = cos_theta;
    rotation_matrix(0, 1) = -sin_theta;
    rotation_matrix(0, 2) = static_cast<T>(0);

    rotation_matrix(1, 0) = sin_theta;
    rotation_matrix(1, 1) = cos_theta;
    rotation_matrix(1, 2) = static_cast<T>(0);

    rotation_matrix(2, 0) = static_cast<T>(0);
    rotation_matrix(2, 1) = static_cast<T>(0);
    rotation_matrix(2, 2) = static_cast<T>(1);

    return rotation_matrix;
}

// Explicit template instantiation for commonly used types
template class Matrix3<double>;
template class Matrix3<int>;
template class Matrix3<float>;
