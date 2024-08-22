#include "matrix.hpp"
#include "vector3.hpp"
#include <list>

template <typename T>
class Matrix3 : public MatrixS<T> {
public:
    // Constructors
    Matrix3();
    Matrix3(const MatrixX<T>& mat);
    Matrix3(const MatrixS<T>& mat);

    // Operators
    Vector3<T> operator*(const Vector3<T>& vec) const;

    // Static methods
    static Matrix3 Zero();

    static Matrix3 One();

    static Matrix3 Identity();

    static Matrix3 RotationX(T angle);

    static Matrix3 RotationY(T angle);

    static Matrix3 RotationZ(T angle);

    static Matrix3 Scaling(T scale);

    // Determinant
    T determinant() const;

    // Inverse
    Matrix3 inverse() const;

    // Eigenvalues
    std::list<T> eigenvalues() const;

    // Positive definiteness
    bool isPositiveDefinite() const;
};

class Matrix3d : public Matrix3<double> {
    public:
    Matrix3d(int rows, int cols) : Matrix3<double>() {}
};

class Matrix3i : public Matrix3<int> {
    public:
    Matrix3i(int rows, int cols) : Matrix3<int>() {}
};

class Matrix3f : public Matrix3<float> {
    public:
    Matrix3f(int rows, int cols) : Matrix3<float>() {}
};