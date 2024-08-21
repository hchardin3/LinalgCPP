#include <iostream>

template <typename T>
class Vector3 {
    private:
    T x;
    T y;
    T z;
    bool isTransposed = false; // Is a column vector by default, is considered as a row vector if transposed

    public:

    // Constructors
    Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

    Vector3<T> Zero() {
        return Vector3(0, 0, 0);
    }

    Vector3<T> One() {
        return Vector3(1, 1, 1);
    }

    Vector3<T> Unit(int i) {
        switch (i)
        {
        case 0:
            return Vector3(1, 0, 0);
        
        case 1:
            return Vector3(0, 1, 0);

        case 2:
            return Vector3(0, 0, 1);
        
        default:
            std::cerr << "Invalid index for vector component" << std::endl;
            exit(EXIT_FAILURE);
            break;
        }
    }

    // Destructor
    ~Vector3() {}

    // Operators
    Vector3<T> operator+(const Vector3<T>& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3<T> operator-(const Vector3<T>& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3<T> operator*(T scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3<T> operator/(T scalar) const {
        if (scalar == 0) {
            std::cerr << "Division by zero" << std::endl;
            exit(EXIT_FAILURE);
        }
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    // Utils
    void transpose() {
        isTransposed = !isTransposed;
    }

    bool isTransposed() const { return isTransposed;}

    T norm() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3<T> normalize() const {
        T magnitude = norm();
        return Vector3(x / magnitude, y / magnitude, z / magnitude);
    }
    
    // Custom operators
    T dot(const Vector3<T>& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3<T> cross(const Vector3<T>& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
    
    // Display vector
    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }    
};