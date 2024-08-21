#include <iostream>
#include <list>
#include "vector.hpp"

template <typename T>
class MatrixX {
    private:
        int num_rows;
        int num_cols;
        VectorX<T> data;

    public:
        // Constructor
        MatrixX(int rows, int cols);

        MatrixX Zero(int rows, int cols);

        MatrixX One(int rows, int cols);

        // Operators
        MatrixX operator+(const MatrixX& other) const;

        MatrixX operator-(const MatrixX& other) const;

        MatrixX operator*(const MatrixX& other) const;

        MatrixX operator*(const T& scalar) const;

        MatrixX operator/(const T& scalar) const;

        // Utils
        std::list<int> shape() const;

        VectorX<T> flatten() const;

        MatrixX transpose() const;

        // Display
        void display() const;
};

class MatrixXd : public MatrixX<double> {
    public:
    MatrixXd(int rows, int cols) : MatrixX<double>(rows, cols) {}
};

class MatrixXi : public MatrixX<int> {
    public:
    MatrixXi(int rows, int cols) : MatrixX<int>(rows, cols) {}
};

class MatrixXf : public MatrixX<float> {
    public:
    MatrixXf(int rows, int cols) : MatrixX<float>(rows, cols) {}
};

template <typename T>
class MatrixS : public MatrixX<T> {
    public:
    MatrixS(int size) : MatrixX<T>(size, size) {}

    // Utils
    T determinant() const {
        // Implementation of determinant calculation
        //...
    }

};