#include <iostream>
#include "vector3.cpp"



template <typename T>
class Matrix3 {
    private:
    T data[9];

    public:
    Matrix3(T[9] val) {
        for (int i = 0; i < 9; ++i) {
            data[i] = val[i];
        }
    }

    Matrix3<T> Zero() const {
        Matrix3<T> result;
        for (int i = 0; i < 9; ++i) {
            result.data[i] = 0;
        }
        return result;
    }

    Matrix3<T> Identity() const {
        Matrix3<T> result;
        for (int i = 0; i < 9; ++i) {
            result.data[i] = (i % 4 == 0) * 1 + (i % 4 == 1) * 0 + (i % 4 == 2) * 0 + (i % 4 == 3) * 0;
        }
        return result;
    }

    Matrix3<T> operator+(const Matrix3<T>& other) const {
        Matrix3<T> result;
        for (int i = 0; i < 9; ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Matrix3 operator-(const Matrix3<T>& other) const {
        Matrix3<T> result;
        for (int i = 0; i < 9; ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    Matrix3 operator*(const Matrix3<T>& other) const {
        Matrix3<T> result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[3 * i + j] = data[3 * i] * other.data[j] + data[3 * i + 1] * other.data[j + 3] + data[3 * i + 2] * other.data[j + 6];
            }
        }
        return result;
    }

    Matrix3<T> operator*(const T& scalar) const {
        Matrix3<T> result;
        for (int i = 0; i < 9; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    Matrix3 transpose() const {
        Matrix3<T> result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[3 * j + i] = data[3 * i + j];
            }
        }
        return result;
    }

    T determinant() {
        T submatrix[9];
        T det = 0;
        int sign = 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int k = 0;
                for (int l = 0; l < 3; ++l) {
                    if (l!= i) {
                        submatrix[k++] = data[3 * l + j];
                    }
                }
            }
            det += sign * data[i] * Matrix3(submatrix).determinant();
            sign = -sign;
        }
        return det;
    }

    Matrix3<T> inverse() const {
        T det = determinant();
        if (det == 0) {
            std::cerr << "Error: Determinant is zero, cannot compute inverse." << std::endl;
            return Zero();
        } 
        T submatrix[9];
        int sign = 1;
        Matrix3<T> result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int k = 0;
                for (int l = 0; l < 3; ++l) {
                    if (l!= i) {
                        submatrix[k++] = data[3 * l + j];
                    }
                }
                result.data[3 * j + i] = sign * Matrix3(submatrix).determinant();
                sign = -sign;
            }
        }
        return result;
    }

    Vector3<T> operator*(const Vector3<T>& vec) const {
        Vector3<T> result;
        for (int i = 0; i < 3; ++i) {
            result.data[i] = data[3 * i] * vec.data[0] + data[3 * i + 1] * vec.data[1] + data[3 * i + 2] * vec.data[2];
        }
        return result;
    }

    T[3] eigenvalues() const {
        T eigenvalues[3];
        T a = data[0];
        T b = data[1];
        T c = data[2];
        T d = data[3];
        T e = data[4];
        T f = data[5];
        T g = data[6];
        T h = data[7];
        T i = data[8];

        T det = determinant();

        T lambda1 = (d * f - e * c) / det + 0.5;
        T lambda2 = (-b * f + c * e) / det + 0.5;
        T lambda3 = (b * d - c * a) / det + 0.5;

        eigenvalues[0] = lambda1;
        eigenvalues[1] = lambda2;
        eigenvalues[2] = lambda3;

        return eigenvalues;
    }

    void display() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << data[3 * i + j] << " ";
            }
            std::cout << std::endl;
        }
    }

};