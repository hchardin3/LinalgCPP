#include <iostream>
#include "vector3.cpp"
#include "matrix.hpp"

template <typename T>
class Matrix3 : public MatrixX<T> {
    private:
        Vector3<T> col1;
        Vector3<T> col2;
        Vector3<T> col3;
    
    public:
    // Constructors
    Matrix3(Vector3<T> col1, Vector3<T> col2, Vector3<T> col3) : col1(col1), col2(col2), col3(col3) {}

    Matrix3<T> Zero() {
        return Matrix3<T>(Vector3<T>::Zero(), Vector3<T>::Zero(), Vector3<T>::Zero());
    }

    Matrix3<T> Identity() {
        return Matrix3<T>(Vector3<T>::Unit(0), Vector3<T>::Unit(1), Vector3<T>::Unit(2));
    }

    Matrix3<T> One() {
        return Matrix3<T>(Vector3<T>::One(), Vector3<T>::One(), Vector3<T>::One());
    }

    // Destructor
    ~Matrix3() {}

    // Operators
    Matrix3<T> operator+(const Matrix3<T>& other) {
        return Matrix3<T>(col1 + other.col1, col2 + other.col2, col3 + other.col3);
    }

    Matrix3<T> operator-(const Matrix3<T>& other) {
        return Matrix3<T>(col1 - other.col1, col2 - other.col2, col3 - other.col3);
    }

    Matrix3<T> operator*(const Matrix3<T>& other) {
        return Matrix3<T>(col1 * other.col1.x + col2 * other.col1.y + col3 * other.col1.z,
                        col1 * other.col2.x + col2 * other.col2.y + col3 * other.col2.z,
                        col1 * other.col3.x + col2 * other.col3.y + col3 * other.col3.z);
    }

    Matrix3<T> operator*(const T& scalar) {
        return Matrix3<T>(col1 * scalar, col2 * scalar, col3 * scalar);
    }

    Matrix3<T> operator/(const T& scalar) {
        return Matrix3<T>(col1 / scalar, col2 / scalar, col3 / scalar);
    }

    Vector3<T> operator*(const Vector3<T>& vector) {
        if (vector.isTransposed()) {
            Vector3<T> result = Vector3<T>::Zero();
        }
    }

    // Utils
    Matrix3<T> transpose() {
        return Matrix3<T>(Vector3<T>(col1.x, col2.x, col3.x),
                        Vector3<T>(col1.y, col2.y, col3.y),
                        Vector3<T>(col1.z, col2.z, col3.z));
    }

    T determinant() {
        return col1.x * (col2.y * col3.z - col2.z * col3.y) -
               col1.y * (col2.x * col3.z - col2.z * col3.x) +
               col1.z * (col2.x * col3.y - col2.y * col3.x);
    }

    Matrix3<T> inverse() {
        T det = determinant();
        if (det == 0) {
            std::cout << "Error: Matrix is singular!" << std::endl;
            return Matrix3<T>::Zero();
        }

        Matrix3<T> adjugate = Matrix3<T>(Vector3<T>(col2.y * col3.z - col2.z * col3.y,
                                                        -col1.y * col3.z + col1.z * col3.y,
                                                         col1.y * col2.z - col1.z * col2.y),
                                                Vector3<T>(-col2.x * col3.z + col2.z * col3.x,
                                                         col1.x * col3.z - col1.z * col3.x,
                                                        -col1.x * col2.z + col1.z * col2.x),
                                                Vector3<T>( col2.x * col3.y - col2.y * col3.x,
                                                        -col1.x * col3.y + col1.y * col3.x,
                                                         col1.x * col2.y - col1.y * col2.x));

        return adjugate * (1.0 / det);
    }

    // Eigenvalues and eigenvectors

    T[3] eigenvalues() {
        T a = col1.x;
        T b = col1.y;
        T c = col1.z;
        T d = col2.x;
        T e = col2.y;
        T f = col2.z;
        T g = col3.x;
        T h = col3.y;
        T i = col3.z;

        T discriminant = a * (e * i - f * h) + b * (f * g - d * i) + c * (d * h - e * g);

        T eig[3];
        eig[0] = ((b * i - c * h) + discriminant) / (2 * a);
        eig[1] = ((c * f - a * i) + discriminant) / (2 * b);
        eig[2] = ((a * e - b * d) + discriminant) / (2 * c);

        return eig;
    }

    Vector3<T>[3] eigenvectors() {
    
    }

    // Other methods
};