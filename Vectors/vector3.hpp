#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <type_traits>
#include "vector.hpp"
#include "row_vector3.hpp"

template<typename T>
class RowVector3; 

template <typename T>
class Vector3 : public Vector<T, 3> {
    public:
    // Constructor
    Vector3();
    
    Vector3(const T& x, const T& y, const T& z);

    Vector3(const Vector<T, 3>& vector);

    Vector3(const Matrix<T, 3, 1>& matrix);

    /**
     * @brief Creates a new Vector3 instance with all components set to zero.
     *
     * @return A new Vector3 instance with all components set to zero.
     */
    static Vector3 Zero();

    /**
     * @brief Creates a new Vector3 instance with all components set to one.
     *
     * @return A new Vector3 instance with all components set to one.
     */
    static Vector3 One();

    /**
     * @brief Creates a new Vector3 instance with a specific component set to one and the rest set to zero.
     *
     * @param direction The index of the component to set to one. The valid range is 0 (for x), 1 (for y), and 2 (for z).
     *
     * @return A new Vector3 instance with the specified component set to one and the rest set to zero.
     *
     * @throws std::out_of_range If the provided direction is not within the valid range.
    */
    static Vector3 Unit(int direction);

    // Access x, y, z directly
    T& x() { return this->data[0]; }
    const T& x() const { return this->data[0]; }

    T& y() { return this->data[1]; }
    const T& y() const { return this->data[1]; }

    T& z() { return this->data[2]; }
    const T& z() const { return this->data[2]; }

    // Specific utils
    /**
    * @brief Calculates the cross product of this Vector3 instance with another Vector3 instance.
    *
    * The cross product is a vector that is perpendicular to both input vectors.
    * It is only defined for 3D vectors.
    *
    * @param other The other Vector3 instance to calculate the cross product with.
    *
    * @return A new Vector3 instance representing the cross product of this instance with the other Vector3 instance.
    *
    * @note The cross product is not commutative, i.e., cross(a, b) != cross(b, a).
    * @note The magnitude of the resulting vector is equal to the product of the magnitudes of the input vectors and the sine of the angle between them.
    * @note The direction of the resulting vector is determined by the right-hand rule.
    * @note The cross product of two parallel vectors is a zero vector.
    * @note The cross product of a vector with itself is a zero vector.
    * @note The cross product of a zero vector with any other vector is a zero vector.
    */
    Vector3<T> cross(const Vector3<T>& other) const;

    // Rewrite transpose
    /**
     * @brief Calculates the transpose of this Vector3 instance.
     *
     * The transpose of a vector is a matrix obtained by changing the rows to columns and vice versa.
     * In the context of 3D vectors, the transpose operation essentially swaps the x and y components,
     * and leaves the z component unchanged.
     *
     * @return A new RowVector3 instance representing the transpose of this Vector3 instance.
     *
     * @note The transpose operation is not applicable to 1D vectors.
     * @note The transpose of a row vector is a column vector, and vice versa.
     * @note The transpose of a transpose is the original vector.
     * @note The transpose operation is commutative, i.e., transpose(transpose(v)) == v.
     * @note The transpose operation does not change the magnitude of the vector.
     * @note The transpose operation does not change the direction of the vector.
     */
    RowVector3<T> transpose() const;
};

#include "vector3.inl" // Include implementation here, at the end of the header

// Custom vector types
using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;
using Vector3i = Vector3<int>;