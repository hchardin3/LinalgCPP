#include "../LinalgCPP.hpp"
#include <iostream>
#include <cassert>

void run_tests() {
    std::cout << "Running tests..." << std::endl;

    // Test Matrix2 Identity
    {
        Matrix2d mat = Matrix2d::Identity();
        assert(mat(0, 0) == 1.0);
        assert(mat(0, 1) == 0.0);
        assert(mat(1, 0) == 0.0);
        assert(mat(1, 1) == 1.0);
        std::cout << "Matrix2 Identity test passed." << std::endl;
    }

    // Test Matrix2 Rotation
    {
        double angle = 3.14159 / 4; // 45 degrees in radians
        Matrix2d rotation_matrix = Matrix2d::Rotation(angle);
        double sqrt2_over_2 = std::sqrt(2) / 2.0;
        assert(std::abs(rotation_matrix(0, 0) - sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(0, 1) + sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(1, 0) - sqrt2_over_2) < 1e-5);
        assert(std::abs(rotation_matrix(1, 1) - sqrt2_over_2) < 1e-5);
        std::cout << "Matrix2 Rotation test passed." << std::endl;
    }

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
        std::cout << "Matrix3 Identity test passed." << std::endl;
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
        std::cout << "Matrix3 RotationZ test passed." << std::endl;
    }

    // Test Vector and RowVector transpose
    {
        Vector<double, 3> vec;
        vec(0) = 1.0;
        vec(1) = 2.0;
        vec(2) = 3.0;

        RowVector<double, 3> row_vec = vec.transpose();
        assert(row_vec(0) == 1.0);
        assert(row_vec(1) == 2.0);
        assert(row_vec(2) == 3.0);
        
        Vector<double, 3> vec_again = row_vec.transpose();
        assert(vec_again(0) == 1.0);
        assert(vec_again(1) == 2.0);
        assert(vec_again(2) == 3.0);

        std::cout << "Vector transpose tests passed." << std::endl;
    }

    // Test Vector and RowVector addition
    {
        Vector<double, 3> vec1;
        vec1(0) = 1.0;
        vec1(1) = 2.0;
        vec1(2) = 3.0;

        Vector<double, 3> vec2;
        vec2(0) = 4.0;
        vec2(1) = 5.0;
        vec2(2) = 6.0;

        Vector<double, 3> vec_sum = vec1 + vec2;
        assert(vec_sum(0) == 5.0);
        assert(vec_sum(1) == 7.0);
        assert(vec_sum(2) == 9.0);

        std::cout << "Vector addition test passed." << std::endl;
    }

    // Test Matrix2 addition
    {
        Matrix2d mat1;
        mat1(0, 0) = 1.0;
        mat1(0, 1) = 2.0;
        mat1(1, 0) = 3.0;
        mat1(1, 1) = 4.0;

        Matrix2d mat2;
        mat2(0, 0) = 5.0;
        mat2(0, 1) = 6.0;
        mat2(1, 0) = 7.0;
        mat2(1, 1) = 8.0;

        Matrix2d mat_sum = mat1 + mat2;
        assert(mat_sum(0, 0) == 6.0);
        assert(mat_sum(0, 1) == 8.0);
        assert(mat_sum(1, 0) == 10.0);
        assert(mat_sum(1, 1) == 12.0);

        std::cout << "Matrix2 addition test passed." << std::endl;
    }

    // Test Matrix3 multiplication by scalar
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

        Matrix3d mat_scaled = mat * 2.0;
        assert(mat_scaled(0, 0) == 2.0);
        assert(mat_scaled(0, 1) == 4.0);
        assert(mat_scaled(0, 2) == 6.0);
        assert(mat_scaled(1, 0) == 8.0);
        assert(mat_scaled(1, 1) == 10.0);
        assert(mat_scaled(1, 2) == 12.0);
        assert(mat_scaled(2, 0) == 14.0);
        assert(mat_scaled(2, 1) == 16.0);
        assert(mat_scaled(2, 2) == 18.0);

        std::cout << "Matrix3 scalar multiplication test passed." << std::endl;
    }

    // Test Matrix2 determinant
    {
        Matrix2d mat;
        mat(0, 0) = 1.0;
        mat(0, 1) = 2.0;
        mat(1, 0) = 3.0;
        mat(1, 1) = 4.0;

        double det = mat.determinant();
        assert(std::abs(det + 2.0) < 1e-5);

        std::cout << "Matrix2 determinant test passed." << std::endl;
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

        std::cout << "Matrix3 determinant test passed." << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    run_tests();
    return 0;
}
