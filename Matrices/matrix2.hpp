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
