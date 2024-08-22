#include "LinalgCPP.hpp"
#include <iostream>

int main() {
    // Test VectorXd class (a VectorX<double> specialization)
    std::cout << "Testing VectorXd...\n";

    // Creating vectors
    VectorXd v1 = VectorXd::Zero(5);    // Create a vector of zeros
    VectorXd v2 = VectorXd::One(5);     // Create a vector of ones

    std::cout << "Vector v1 (Zero vector): ";
    v1.display();

    std::cout << "Vector v2 (One vector): ";
    v2.display();

    // Performing arithmetic operations
    VectorXd v3 = v1 + 3 * v2;  // v3 should be [3, 3, 3, 3, 3]

    std::cout << "Vector v3 (v1 + 3 * v2): ";
    v3.display();

    // Additional tests can include dot product, normalization, etc.
    std::cout << "Dot product of v2 and v3: " << v2.dot(v3) << "\n";

    std::cout << "Norm of v3: " << v3.norm() << "\n";

    // Matrix and Vector multiplication test
    std::cout << "Testing MatrixXd...\n";
    
    MatrixXd m1(5, 5); // Assuming there's a way to initialize or set matrix values
    // Set some values in m1 for a meaningful test, e.g., an identity matrix or any predefined matrix.
    
    VectorXd v4 = m1 * v2; // This operation depends on your MatrixX implementation
    
    std::cout << "Vector v4 (m1 * v2): ";
    v4.display();

    return 0;
}
