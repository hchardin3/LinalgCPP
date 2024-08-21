TEST(Matrix3, Constructor_AllElementsEqualToOne) {
    T values[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    Matrix3<T> matrix(values);

    for (int i = 0; i < 9; ++i) {
        EXPECT_EQ(matrix.data[i], 1);
    }
    EXPECT_EQ(matrix.det, 0);
}