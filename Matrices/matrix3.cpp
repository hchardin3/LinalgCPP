#include "matrix3.hpp"

// Constructors
template <typename T>
Matrix3<T>::Matrix3() : MatrixX<T>(3, 3) {}

template <typename T>
Matrix3<T>::Matrix3(const MatrixX<T>& mat) : MatrixX<T>(mat) {
    if (mat.num_rows != 3 || mat.num_cols != 3) {
        throw std::invalid_argument("Matrix must be 3x3 to convert to Matrix3");
    }
}

template <typename T>
Matrix3<T>::Matrix3(const MatrixS<T>& mat) : MatrixX<T>(mat) {
    if (mat.num_rows != 3 || mat.num_cols != 3) {
        throw std::invalid_argument("Matrix must be 3x3 to convert to Matrix3");
    }
}

// Operators
template <typename T>
Vector3<T> Matrix3<T>::operator*(const Vector3<T>& vec) const {
    T x = (*this)(0, 0) * vec.x() + (*this)(0, 1) * vec.y() + (*this)(0, 2) * vec.z();
    T y = (*this)(1, 0) * vec.x() + (*this)(1, 1) * vec.y() + (*this)(1, 2) * vec.z();
    T z = (*this)(2, 0) * vec.x() + (*this)(2, 1) * vec.y() + (*this)(2, 2) * vec.z();
    return Vector3<T>(x, y, z);
}

// Static methods
template <typename T>
Matrix3<T> Matrix3<T>::Zero() {
    return Matrix3(MatrixX<T>::Zero(3, 3));
}

template <typename T>
Matrix3<T> Matrix3<T>::One() {
    return Matrix3(MatrixX<T>::One(3, 3));
}

template <typename T>
Matrix3<T> Matrix3<T>::Identity() {
    return Matrix3(MatrixX<T>::Identity(3));
}

template <typename T>
Matrix3<T> Matrix3<T>::RotationX(T angle) {
    Matrix3 rot;
    T cos_theta = std::cos(angle);
    T sin_theta = std::sin(angle);

    rot(0, 0) = 1;
    rot(0, 1) = 0;
    rot(0, 2) = 0;

    rot(1, 0) = 0;
    rot(1, 1) = cos_theta;
    rot(1, 2) = -sin_theta;

    rot(2, 0) = 0;
    rot(2, 1) = sin_theta;
    rot(2, 2) = cos_theta;

    return rot;
}

template <typename T>
Matrix3<T> Matrix3<T>::RotationY(T angle) {
    Matrix3 rot;
    T cos_theta = std::cos(angle);
    T sin_theta = std::sin(angle);

    rot(0, 0) = cos_theta;
    rot(0, 1) = 0;
    rot(0, 2) = sin_theta;

    rot(1, 0) = 0;
    rot(1, 1) = 1;
    rot(1, 2) = 0;

    rot(2, 0) = -sin_theta;
    rot(2, 1) = 0;
    rot(2, 2) = cos_theta;

    return rot;
}

template <typename T>
Matrix3<T> Matrix3<T>::RotationZ(T angle) {
    Matrix3 rot;
    T cos_theta = std::cos(angle);
    T sin_theta = std::sin(angle);

    rot(0, 0) = cos_theta;
    rot(0, 1) = -sin_theta;
    rot(0, 2) = 0;

    rot(1, 0) = sin_theta;
    rot(1, 1) = cos_theta;
    rot(1, 2) = 0;

    rot(2, 0) = 0;
    rot(2, 1) = 0;
    rot(2, 2) = 1;

    return rot;
}

template <typename T>
Matrix3<T> Matrix3<T>::Scaling(T scale) {
    Matrix3 scaling;
    scaling(0, 0) = scale;
    scaling(1, 1) = scale;
    scaling(2, 2) = scale;
    return scaling;
}

// Determinant
template <typename T>
T Matrix3<T>::determinant() const {
    return (*this)(0, 0) * ((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) -
           (*this)(0, 1) * ((*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0)) +
           (*this)(0, 2) * ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0));
}

// Inverse
template <typename T>
Matrix3<T> Matrix3<T>::inverse() const {
    T det = determinant();
    if (det == 0) {
        throw std::runtime_error("Cannot invert a singular matrix");
    }

    Matrix3 inv;
    inv(0, 0) = ((*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1)) / det;
    inv(0, 1) = ((*this)(0, 2) * (*this)(2, 1) - (*this)(0, 1) * (*this)(2, 2)) / det;
    inv(0, 2) = ((*this)(0, 1) * (*this)(1, 2) - (*this)(0, 2) * (*this)(1, 1)) / det;

    inv(1, 0) = ((*this)(1, 2) * (*this)(2, 0) - (*this)(1, 0) * (*this)(2, 2)) / det;
    inv(1, 1) = ((*this)(0, 0) * (*this)(2, 2) - (*this)(0, 2) * (*this)(2, 0)) / det;
    inv(1, 2) = ((*this)(0, 2) * (*this)(1, 0) - (*this)(0, 0) * (*this)(1, 2)) / det;

    inv(2, 0) = ((*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0)) / det;
    inv(2, 1) = ((*this)(0, 1) * (*this)(2, 0) - (*this)(0, 0) * (*this)(2, 1)) / det;
    inv(2, 2) = ((*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0)) / det;

    return inv;
}

// Eigenvalues
template <typename T>
std::list<T> Matrix3<T>::eigenvalues() const {
    // This method for calculating eigenvalues of a 3x3 matrix is a simplified approach
    // using the characteristic polynomial. More advanced numerical methods may be needed
    // for precision or performance in real-world applications.
    T p1 = (*this)(0, 1) * (*this)(0, 1) + (*this)(0, 2) * (*this)(0, 2) + (*this)(1, 2) * (*this)(1, 2);
    if (p1 == 0) {
        // The matrix is diagonal.
        std::list<T> eigenvalues = {(*this)(0, 0), (*this)(1, 1), (*this)(2, 2)};
        return eigenvalues;
    }

    T q = (trace() / 3);
    T p2 = ((*this)(0, 0) - q) * ((*this)(0, 0) - q) + ((*this)(1, 1) - q) * ((*this)(1, 1) - q) + ((*this)(2, 2) - q) * ((*this)(2, 2) - q) + 2 * p1;
    T p = std::sqrt(p2 / 6);
    Matrix3 B = (1 / p) * ((*this) - q * Matrix3::Identity());
    T r = B.determinant() / 2;

    T phi;
    if (r <= -1) {
        phi = M_PI / 3;
    } else if (r >= 1) {
        phi = 0;
    } else {
        phi = std::acos(r) / 3;
    }

    std::list<T> eigenvalues;
    eigenvalues.push_back(q + 2 * p * std::cos(phi));
    eigenvalues.push_back(q + 2 * p * std::cos(phi + (2 * M_PI / 3)));
    eigenvalues.push_back(q + 2 * p * std::cos(phi + (4 * M_PI / 3)));

    return eigenvalues;
}

// Positive definiteness
template <typename T>
bool Matrix3<T>::isPositiveDefinite() const {
    T a = (*this)(0, 0);
    T b = (*this)(0, 1);
    T c = (*this)(0, 2);
    T d = (*this)(1, 0);
    T e = (*this)(1, 1);
    T f = (*this)(1, 2);
    T g = (*this)(2, 0);
    T h = (*this)(2, 1);
    T i = (*this)(2, 2);

    T det1 = a;
    T det2 = a * e - b * d;
    T det3 = determinant();

    return det1 > 0 && det2 > 0 && det3 > 0;
}
