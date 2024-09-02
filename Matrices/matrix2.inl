#include "matrix2.hpp"

// Constructor implementations
template<typename T>
Matrix2<T>::Matrix2() : MatrixS<T, 2>() {}

template<typename T>
Matrix2<T>::Matrix2(const Matrix<T, 2, 2>& m) : MatrixS<T, 2>(m) {}

template<typename T>
Matrix2<T>::Matrix2(const MatrixS<T, 2>& m) : MatrixS<T, 2>(m) {}

template<typename T>
Matrix2<T> Matrix2<T>::Zero()  {
    return Matrix2<T>(MatrixS<T, 2>::Zero(2));
}

template<typename T>
Matrix2<T> Matrix2<T>::One() {
    return Matrix2<T>(MatrixS<T, 2>::One(2));
}

template<typename T>
Matrix2<T> Matrix2<T>::Identity()  {
    return Matrix2<T>(MatrixS<T, 2>::Identity(2));
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

template<typename T>
Matrix2<T> Matrix2<T>::inverse() const {
    T det = (*this).determinant();
    if (std::abs(det) < std::numeric_limits<T>::epsilon()) {
        throw std::runtime_error("Matrix is singular");
    }

    T inv_determinant = 1.0 / det;

    Matrix2<T> inverse_matrix;
    inverse_matrix(0, 0) = (*this)(1, 1) * inv_determinant;
    inverse_matrix(0, 1) = -(*this)(0, 1) * inv_determinant;
    inverse_matrix(1, 0) = -(*this)(1, 0) * inv_determinant;
    inverse_matrix(1, 1) = (*this)(0, 0) * inv_determinant;
    return inverse_matrix;
}
