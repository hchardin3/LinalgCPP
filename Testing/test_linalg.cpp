#include "../LinalgCPP.hpp"
#include <iostream>
#include <typeinfo>
#include <cassert>

void run_matrix2_tests() {
    std::cout << "Running Matrix2 tests..." << std::endl;

    // Test Matrix2 Identity
    {
        std::cout << "Test Matrix2 Identity..." << std::endl;
        Matrix2d mat = Matrix2d::Identity();
        assert(mat(0, 0) == 1.0);
        assert(mat(0, 1) == 0.0);
        assert(mat(1, 0) == 0.0);
        assert(mat(1, 1) == 1.0);
    }

    // Test Matrix2 Rotation
    {
        std::cout << "Test Matrix2 Rotation..." << std::endl;
        double angle = 3.14159 / 4; // 45 degrees in radians
        Matrix2d rotation_matrix = Matrix2d::Rotation(angle);
        double sqrt2_over_2 = std::sqrt(2) / 2.0;
        assert(std::abs(rotation_matrix(0, 0) - sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(0, 1) + sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(1, 0) - sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(1, 1) - sqrt2_over_2) < 1e-5);
    }

    // Test Matrix2 addition
    {
        std::cout << "Test Matrix2 addition..." << std::endl;
        Matrix2d mat1 = Matrix2d::One();
        Matrix2d mat2 = Matrix2d::One();
        Matrix2d mat_sum = mat1 + mat2;
        assert(mat_sum(0, 0) == 2.0);
        assert(mat_sum(1, 1) == 2.0);
        std::cout << "mat_sum is of type " << typeid(mat_sum).name() << std::endl;
    }

    // Test Matrix2 determinant
    {
        std::cout << "Test Matrix2 determinant..." << std::endl;
        Matrix2d mat;
        mat(0, 0) = 1.0;
        mat(0, 1) = 2.0;
        mat(1, 0) = 3.0;
        mat(1, 1) = 4.0;
        double det = mat.determinant();
        assert(std::abs(det + 2.0) < 1e-5);
    }

    // Test Matrix2 inverse
    {
        std::cout << "Test Matrix2 inverse..." << std::endl;
        Matrix2d mat;
        mat(0, 0) = 4.0;
        mat(0, 1) = 7.0;
        mat(1, 0) = 2.0;
        mat(1, 1) = 6.0;
        Matrix2d inv_mat = mat.inverse();
        Matrix2d identity = mat * inv_mat;
        assert(std::abs(identity(0, 0) - 1.0) < 1e-5);
        assert(std::abs(identity(1, 1) - 1.0) < 1e-5);
    }

    std::cout << "Matrix2 tests passed." << std::endl;
}

void run_matrix3_tests() {
    std::cout << "Running Matrix3 tests..." << std::endl;

    // Test Matrix3 Identity
    {
        Matrix3d mat = Matrix3d::Identity();
        assert(mat(0, 0) == 1.0);
        assert(mat(0, 1) == 0.0);
        assert(mat(0, 2) == 0.0);
        assert(mat(1, 0) == 0.0);
        assert(mat(1, 1) == 1.0);
        assert(mat(1, 2) == 0.0);
        assert(mat(2, 0) == 0.0);
        assert(mat(2, 1) == 0.0);
        assert(mat(2, 2) == 1.0);
    }

    // Test Matrix3 RotationZ
    {
        double angle = 3.14159 / 4; // 45 degrees in radians
        Matrix3d rotation_matrix = Matrix3d::RotationZ(angle);
        double sqrt2_over_2 = std::sqrt(2) / 2.0;
        assert(std::abs(rotation_matrix(0, 0) - sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(0, 1) + sqrt2_over_2) < 1e-5);
        assert(rotation_matrix(0, 2) == 0.0);
        assert(std::abs(rotation_matrix(1, 0) - sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(1, 1) - sqrt2_over_2) < 1e-5);
        assert(rotation_matrix(1, 2) == 0.0);
        assert(rotation_matrix(2, 0) == 0.0);
        assert(rotation_matrix(2, 1) == 0.0);
        assert(rotation_matrix(2, 2) == 1.0);
    }

    // Test Matrix3 determinant
    {
        Matrix3d mat;
        mat(0, 0) = 1.0;
        mat(0, 1) = 2.0;
        mat(0, 2) = 3.0;
        mat(1, 0) = 4.0;
        mat(1, 1) = 5.0;
        mat(1, 2) = 6.0;
        mat(2, 0) = 7.0;
        mat(2, 1) = 8.0;
        mat(2, 2) = 9.0;
        double det = mat.determinant();
        assert(std::abs(det) < 1e-5);  // Determinant of this matrix should be 0
    }

    // Test Matrix3 inverse (should fail for a singular matrix)
    {
        Matrix3d mat;
        mat(0, 0) = 1.0;
        mat(0, 1) = 2.0;
        mat(0, 2) = 3.0;
        mat(1, 0) = 4.0;
        mat(1, 1) = 5.0;
        mat(1, 2) = 6.0;
        mat(2, 0) = 7.0;
        mat(2, 1) = 8.0;
        mat(2, 2) = 9.0;
        bool caught_exception = false;
        try {
            Matrix3d inv_mat = mat.inverse();
        } catch (const std::runtime_error&) {
            caught_exception = true;
        }
        assert(caught_exception);
    }

    std::cout << "Matrix3 tests passed." << std::endl;
}

void run_vector_tests() {
    std::cout << "Running Vector tests..." << std::endl;

    // Test Vector transpose
    {
        Vector3d vec(1.0, 2.0, 3.0);
        RowVector3d row_vec = vec.transpose();
        assert(row_vec(0) == 1.0);
        assert(row_vec(1) == 2.0);
        assert(row_vec(2) == 3.0);
    }

    // Test Vector dot product
    {
        Vector3d vec1(1.0, 2.0, 3.0);
        Vector3d vec2(4.0, 5.0, 6.0);
        double dot_product = vec1.dot(vec2);
        assert(dot_product == 32.0);
    }

    // Test Vector cross product
    {
        Vector3d vec1(1.0, 0.0, 0.0);
        Vector3d vec2(0.0, 1.0, 0.0);
        Vector3d cross_product = vec1.cross(vec2);
        assert(cross_product(0) == 0.0);
        assert(cross_product(1) == 0.0);
        assert(cross_product(2) == 1.0);
    }

    // Test Vector addition
    {
        Vector3d vec1(1.0, 2.0, 3.0);
        Vector3d vec2(4.0, 5.0, 6.0);
        Vector3d vec_sum = vec1 + vec2;
        assert(vec_sum(0) == 5.0);
        assert(vec_sum(1) == 7.0);
        assert(vec_sum(2) == 9.0);
    }

    // Test Vector scalar multiplication
    {
        Vector3d vec(1.0, 2.0, 3.0);
        Vector3d vec_scaled = vec * 2.0;
        assert(vec_scaled(0) == 2.0);
        assert(vec_scaled(1) == 4.0);
        assert(vec_scaled(2) == 6.0);
    }

    std::cout << "Vector tests passed." << std::endl;
}

void run_rowvector_tests() {
    std::cout << "Running RowVector tests..." << std::endl;

    // Test RowVector transpose
    {
        RowVector3d row_vec(1.0, 2.0, 3.0);
        Vector3d vec = row_vec.transpose();
        assert(vec(0) == 1.0);
        assert(vec(1) == 2.0);
        assert(vec(2) == 3.0);
    }

    // Test RowVector dot product
    {
        RowVector3d row_vec1(1.0, 2.0, 3.0);
        Vector3d vec2(4.0, 5.0, 6.0);
        double dot_product = row_vec1 * vec2;
        assert(dot_product == 32.0);
    }

    // Test RowVector addition
    {
        RowVector3d row_vec1(1.0, 2.0, 3.0);
        RowVector3d row_vec2(4.0, 5.0, 6.0);
        RowVector3d row_vec_sum = row_vec1 + row_vec2;
        assert(row_vec_sum(0) == 5.0);
        assert(row_vec_sum(1) == 7.0);
        assert(row_vec_sum(2) == 9.0);
    }

    // Test RowVector scalar multiplication
    {
        RowVector3d row_vec(1.0, 2.0, 3.0);
        RowVector3d row_vec_scaled = row_vec * 2.0;
        assert(row_vec_scaled(0) == 2.0);
        assert(row_vec_scaled(1) == 4.0);
        assert(row_vec_scaled(2) == 6.0);
    }

    std::cout << "RowVector tests passed." << std::endl;
}

void run_matrix_vector_interaction_tests() {
    std::cout << "Running Matrix-Vector interaction tests..." << std::endl;

    // Test Matrix2 * Vector2
    {
        Matrix2d mat = Matrix2d::Identity();
        Vector2d vec(1.0, 2.0);
        Vector2d result = mat * vec;
        assert(result(0) == 1.0);
        assert(result(1) == 2.0);
    }

    // Test Matrix3 * Vector3
    {
        Matrix3d mat = Matrix3d::Identity();
        Vector3d vec(1.0, 2.0, 3.0);
        Vector3d result = mat * vec;
        assert(result(0) == 1.0);
        assert(result(1) == 2.0);
        assert(result(2) == 3.0);
    }

    // Test Matrix3 * RowVector3 transpose
    {
        Matrix3d mat = Matrix3d::Identity();
        RowVector3d row_vec(1.0, 2.0, 3.0);
        Vector3d vec = row_vec.transpose();
        Vector3d result = mat * vec;
        assert(result(0) == 1.0);
        assert(result(1) == 2.0);
        assert(result(2) == 3.0);
    }

    std::cout << "Matrix-Vector interaction tests passed." << std::endl;
}

int main() {
    run_matrix2_tests();
    run_matrix3_tests();
    run_vector_tests();
    run_rowvector_tests();
    run_matrix_vector_interaction_tests();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
