// practice03_test.cpp (Unit Tests using Google Test)
#include "../practice/practice03/practice03.cpp"
#include <gtest/gtest.h>

// Tests for sumRange()
TEST(MathUtilsTest, SumRange_NormalCase) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15);
}

TEST(MathUtilsTest, SumRange_SingleValue) {
    EXPECT_EQ(MathUtils::sumRange(5, 5), 5);
}

TEST(MathUtilsTest, SumRange_NegativeValues) {
    EXPECT_EQ(MathUtils::sumRange(-3, 3), 0);
}

// Tests for containsNegative()
TEST(MathUtilsTest, ContainsNegative_HasNegative) {
    std::vector<int> values = {1, -2, 3};
    EXPECT_TRUE(MathUtils::containsNegative(values));
}

TEST(MathUtilsTest, ContainsNegative_AllPositive) {
    std::vector<int> values = {1, 2, 3};
    EXPECT_FALSE(MathUtils::containsNegative(values));
}

TEST(MathUtilsTest, ContainsNegative_EmptyList) {
    std::vector<int> values = {};
    EXPECT_FALSE(MathUtils::containsNegative(values));
}

// Tests for findMax()
TEST(MathUtilsTest, FindMax_NormalCase) {
    std::vector<int> values = {1, 5, 3, 9, 2};
    EXPECT_EQ(MathUtils::findMax(values), 9);
}

TEST(MathUtilsTest, FindMax_AllEqual) {
    std::vector<int> values = {4, 4, 4, 4};
    EXPECT_EQ(MathUtils::findMax(values), 4);
}

TEST(MathUtilsTest, FindMax_EmptyList) {
    std::vector<int> values = {};
    EXPECT_THROW(MathUtils::findMax(values), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
