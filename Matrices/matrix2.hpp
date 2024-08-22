#include "matrix.hpp"
#include "vector2.hpp"
#include <list>

template <typename T>
class Matrix2 : public MatrixS<T> {
public:
    // Constructors
    Matrix2();
    Matrix2(const MatrixX<T>& mat);
    Matrix2(const MatrixS<T>& mat);

    // Operators
    Vector2<T> operator*(const Vector2<T>& vec) const;

    // Static methods
    static Matrix2 Zero();

    static Matrix2 One();

    static Matrix2 Identity();

    static Matrix2 Rotation(T angle);

    static Matrix2 Scaling(T scale);

    // Determinant
    T determinant() const;

    // Inverse
    Matrix2 inverse() const;

    // Eigenvalues
    std::list<T> eigenvalues() const;

    // Positive definiteness
    bool isPositiveDefinite() const;
};

class Matrix2d : public Matrix2<double> {
    public:
    Matrix2d(int rows, int cols) : Matrix2<double>() {}
};

class Matrix2i : public Matrix2<int> {
    public:
    Matrix2i(int rows, int cols) : Matrix2<int>() {}
};

class Matrix2f : public Matrix2<float> {
    public:
    Matrix2f(int rows, int cols) : Matrix2<float>() {}
};