#ifndef LINALGCPP_HPP
#define LINALGCPP_HPP

// Include utilities and common types
#include "Utils/types.hpp"
#include "Utils/range.hpp"

// Include all vector classes
#include "Vectors/row_vector.hpp"
#include "Vectors/row_vector2.hpp"
#include "Vectors/row_vector3.hpp"
#include "Vectors/vector.hpp"
#include "Vectors/vector2.hpp"
#include "Vectors/vector3.hpp"

// Include all matrix classes
#include "Matrices/matrix.hpp"
#include "Matrices/matrix2.hpp"
#include "Matrices/matrix3.hpp"
#include "Matrices/square_matrix.hpp"

namespace LinalgCPP {
    // Vector classes
    class RowVector;
    class RowVectorXd;
    class RowVectorXi;
    class RowVectorXf;

    class RowVector2;
    class RowVector2d;
    class RowVector2i;
    class RowVector2f;

    class RowVector3;
    class RowVector3d;
    class RowVector3i;
    class RowVector3f;

    class VectorX;
    class VectorXd;
    class VectorXi;
    class VectorXf;

    class Vector2;
    class Vector2d;
    class Vector2i;
    class Vector2f;

    class Vector3;
    class Vector3d;
    class Vector3i;
    class Vector3f;

    // Matrix classes
    class MatrixX;
    class MatrixXd;
    class MatrixXi;
    class MatrixXf;

    class MatrixS;
    class MatrixSd;
    class MatrixSi;
    class MatrixSf;

    class Matrix2;
    class Matrix2d;
    class Matrix2i;
    class Matrix2f;

    class Matrix3;
    class Matrix3d;
    class Matrix3i;
    class Matrix3f;
}

#endif // LINALGCPP_HPP
