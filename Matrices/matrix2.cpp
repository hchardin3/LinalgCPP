#include "matrix2.hpp"

// Constructors
template <typename T>
Matrix2<T>::Matrix2() : MatrixS<T>(2) {}

template <typename T>
Matrix2<T>::Matrix2(const MatrixX<T>& mat) : MatrixX<T>(mat) {
    if (mat.num_rows != 2 || mat.num_cols != 2) {
        throw std::invalid_argument("Matrix must be 2x2 to convert to Matrix2");
    }
}

template <typename T>
Matrix2<T>::Matrix2(const MatrixS<T>& mat) : MatrixS<T>(mat) {
    if (mat.num_rows != 2 || mat.num_cols != 2) {
        throw std::invalid_argument("Matrix must be 2x2 to convert to Matrix2");
    }
}

// Operators
template <typename T>
Vector2<T> Matrix2<T>::operator*(const Vector2<T>& vec) const {
    T x = (*this)(0, 0) * vec.x() + (*this)(0, 1) * vec.y();
    T y = (*this)(1, 0) * vec.x() + (*this)(1, 1) * vec.y();
    return Vector2<T>(x, y);
}

// Static methods
template <typename T>
Matrix2<T> Matrix2<T>::Zero() {
    return Matrix2(MatrixX<T>::Zero(2, 2));
}

template <typename T>
Matrix2<T> Matrix2<T>::One() {
    return Matrix2(MatrixX<T>::One(2, 2));
}

template <typename T>
Matrix2<T> Matrix2<T>::Identity() {
    return Matrix2(MatrixX<T>::Identity(2));
}

template <typename T>
Matrix2<T> Matrix2<T>::Rotation(T angle) {
    Matrix2 rot;
    T cos_theta = std::cos(angle);
    T sin_theta = std::sin(angle);
    rot(0, 0) = cos_theta;
    rot(0, 1) = -sin_theta;
    rot(1, 0) = sin_theta;
    rot(1, 1) = cos_theta;
    return rot;
}

template <typename T>
Matrix2<T> Matrix2<T>::Scaling(T scale) {
    return scale * Matrix2::Identity();
}

// Determinant
template <typename T>
T Matrix2<T>::determinant() const {
    return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
}

// Inverse
template <typename T>
Matrix2<T> Matrix2<T>::inverse() const {
    T det = determinant();
    if (det == 0) {
        throw std::runtime_error("Cannot invert a singular matrix");
    }

    Matrix2 result;
    result(0, 0) = (*this)(1, 1) / det;
    result(0, 1) = -(*this)(0, 1) / det;
    result(1, 0) = -(*this)(1, 0) / det;
    result(1, 1) = (*this)(0, 0) / det;
    return result;
}

// Eigenvalues
template <typename T>
std::list<T> Matrix2<T>::eigenvalues() const {
    T a = (*this)(0, 0);
    T b = (*this)(0, 1);
    T c = (*this)(1, 0);
    T d = (*this)(1, 1);

    T trace = a + d;
    T determinant = this->determinant();
    T discriminant = trace * trace - 4 * determinant;

    T sqrt_discriminant = std::sqrt(std::abs(discriminant));

    std::list<T> eigenvalues;
    eigenvalues.push_back((trace + sqrt_discriminant) / 2);
    eigenvalues.push_back((trace - sqrt_discriminant) / 2);
    return eigenvalues;
}

// Positive definiteness
template <typename T>
bool Matrix2<T>::isPositiveDefinite() const {
    T a = (*this)(0, 0);
    T b = (*this)(0, 1);
    T c = (*this)(1, 0);
    T d = (*this)(1, 1);

    T det = determinant();
    return a > 0 && det > 0;
}