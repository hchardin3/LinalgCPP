# Linear Algebra library on C++

LinalgCPP is a personnal project that I used primarly to learn complex OOP and project management on C++ for myself.

It consists in a tentative Linear Algebra library for C++.

## Objects

### Matrix

Matrix is the base object of this library. It contains three different hyperparameters:

- T (typename): the object type of the matrix elements.
- Rows (integer): the number of rows of the matrix.
- Cols (integer): the number of columns of the matrix.

This class contains a number of methods including, but not limited to:

- Constructing methods, such as Zero and One.
- Operators, such as Add, Sub, Multiply and Divide by scalars.
- Diverse methods, such as Normalize, Norm, Transpose, Display....

All the following classes are derived from this one.

### Square matrix (MatrixS)

The class MatrixS implements square matrix in LinalgCPP. As their name implies, these matrices are defined to have the same number of rows and columns, defined under one hyperparameter called Size (integer). 

This class contains several specific methods:

- determinant, to get the determinant of the matrix.
- power, to raise the matrix to a power n (positive for now).
- inverse, to compute the inverse of a square matrix if it exists.

#### Matrix2 and Matrix3

The subclasses Matrix2 and Matrix3 are specifically defined to handle the algebra of square matrices of size respectively 2 and 3.

### Vector and RowVector

These two classes are used to represent column vectors (thereafter simply referred to as "vectors") and row vectors. They are treated as subclasses of Matrix, with respectively Cols and Rows set to 1, the other parameter being called Size.

These classes can handle classical vector operations, such as addition, subtraction, multiplication to a matrix of compatible dimensions, transposition and so on.

#### Vector2, Vector3, RowVector2 and RowVector3

These subclasses are used to represent vectors of size 2 and 3.

They are designed to be computationally efficient when used alongside the classes Matrix2 and Matrix3 respectively.
