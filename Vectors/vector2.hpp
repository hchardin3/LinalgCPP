#include "vector.hpp"
#include "matrix2.hpp"

template<typename T>
class Vector2 : public VectorX<T> {
public:
    // Constructor that initializes the base class with size 2
    Vector2() : VectorX<T>(2) {}

    // Access x, y directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    // Operators
    Vector2<T> operator*(const Matrix2<T>& mat) const;

    // Functions
    T angle(const Vector2& other) const;

    Vector2<T> rotate(T angle) const;
};
