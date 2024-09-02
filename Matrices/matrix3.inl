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

template<typename T>
Matrix3<T> Matrix3<T>::inverse() const {
    T det = (*this).determinant();
    if (std::abs(det) < std::numeric_limits<T>::epsilon()) {
        throw std::runtime_error("Matrix is singular, cannot calculate its inverse");
    }
    Matrix3<T> inverse_matrix;
    inverse_matrix(0, 0) = ((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) / det;
    inverse_matrix(0, 1) = -((*this)(0, 1) * (*this)(2, 2) - (*this)(0, 2) * (*this)(2, 1)) / det;
    inverse_matrix(0, 2) = ((*this)(0, 1) * (*this)(1, 2) - (*this)(0, 2) * (*this)(1, 1)) / det;
    inverse_matrix(1, 0) = -((*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0)) / det;
    inverse_matrix(1, 1) = ((*this)(0, 0) * (*this)(2, 2) - (*this)(0, 2) * (*this)(2, 0)) / det;
    inverse_matrix(1, 2) = -((*this)(0, 0) * (*this)(1, 2) - (*this)(0, 2) * (*this)(1, 0)) / det;
    inverse_matrix(2, 0) = ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0)) / det;
    inverse_matrix(2, 1) = -((*this)(0, 0) * (*this)(1, 2) - (*this)(0, 2) * (*this)(1, 1)) / det;
    inverse_matrix(2, 2) = ((*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0)) / det;

    return inverse_matrix;
}
