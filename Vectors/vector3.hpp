#include "vector.hpp"

template<typename T>
class Vector3 : public VectorX<T> {
    public:
        // Constructor
        Vector3();
        
        Vector3(const T& x, const T& y, const T& z);

        // Access x, y, z directly
        T& x() { return this->data[0]; }
        const T& x() const { return this->data[0]; }

        T& y() { return this->data[1]; }
        const T& y() const { return this->data[1]; }

        T& z() { return this->data[2]; }
        const T& z() const { return this->data[2]; }

        // Specific utils
        T dot(const Vector3<T>& other) const;

        Vector3<T> cross(const Vector3<T>& other) const;
};

class Vector3d : public Vector3<double> {
    public:
    // Constructors
    Vector3d() : Vector3<double>() {}
};

class Vector3f : public Vector3<float> {
    public:
    // Constructors
    Vector3f() : Vector3<float>() {}
};

class Vector3i : public Vector3<int> {
    public:
    // Constructors
    Vector3i() : Vector3<int>() {}
};