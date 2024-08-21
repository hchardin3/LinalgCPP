#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

template<typename T>
class VectorX {
    private:
        int size;
        T* data;
        bool is_transposed = false; // True if the VectorX is transposed (row VectorX), false by default (column VectorX)
    
    public:
    // Constructor
    VectorX(int size = 10);

    VectorX<T> Zero(int size);

    VectorX<T> One(int size);

    VectorX<T> Unit(int size, int direction);

    // Random

    VectorX<T> Random(int size, T min, T max);

    // Destructor
    ~VectorX() { delete[] data; }

    // Operators
    VectorX<T> operator+(const VectorX<T>& other) const;

    VectorX<T> operator-(const VectorX<T>& other) const;

    VectorX<T> operator*(const T& value) const;

    VectorX<T> operator/(const T& value) const;

    // Utils
    bool isTransposed() const;

    void transpose();

    T norm() const;

    VectorX<T> normalize() const;

    // Display

    void display() const;

};

class VectorXd : public VectorX<double> {
    public:
        // Constructor
        VectorXd(int size) : VectorX<double>(size) {}
};

class VectorXi : public VectorX<int> {
    public:
    // Constructor
    VectorXi(int size) : VectorX<int>(size) {}
};