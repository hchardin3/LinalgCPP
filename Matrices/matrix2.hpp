#include "matrix.hpp"

template <typename T>
class Matrix2 : public MatrixX<T> {
    public:
        // Construct
        Matrix2() : MatrixX<T>(2, 2) {}

        static Matrix2 Zero() {
            Matrix2 mat;
            mat = MatrixX<T>::Zero(2, 2);
            return mat;
        }

        static Matrix2 One() {
            Matrix2 mat;
            mat = MatrixX<T>::One(2, 2);
            return mat;
        }

        // Utils
};