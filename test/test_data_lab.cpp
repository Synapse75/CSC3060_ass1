#include "data_lab.hpp"
#include <gtest/gtest.h>
#include <cstdint>

// Add function tests (12 tests)
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(data_lab::add(5, 3), 8);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(data_lab::add(-5, -3), -8);
}

TEST(AddTest, MixedSigns) {
    EXPECT_EQ(data_lab::add(10, -3), 7);
}

TEST(AddTest, WithZero) {
    EXPECT_EQ(data_lab::add(0, 5), 5);
}

TEST(AddTest, BothZero) {
    EXPECT_EQ(data_lab::add(0, 0), 0);
}

TEST(AddTest, LargePositive) {
    EXPECT_EQ(data_lab::add(1000000, 2000000), 3000000);
}

TEST(AddTest, LargeNegative) {
    EXPECT_EQ(data_lab::add(-1000000, -2000000), -3000000);
}

TEST(AddTest, NegativeResult) {
    EXPECT_EQ(data_lab::add(-10, 3), -7);
}

TEST(AddTest, PositiveResult) {
    EXPECT_EQ(data_lab::add(-3, 10), 7);
}

TEST(AddTest, MaxInt32) {
    EXPECT_EQ(data_lab::add(INT32_MAX, 0), INT32_MAX);
}

TEST(AddTest, MinInt32) {
    EXPECT_EQ(data_lab::add(INT32_MIN, 0), INT32_MIN);
}

TEST(AddTest, CommutativeProperty) {
    EXPECT_EQ(data_lab::add(7, 13), data_lab::add(13, 7));
}

// Subtract function tests (12 tests)
TEST(SubtractTest, PositiveNumbers) {
    EXPECT_EQ(data_lab::subtract(10, 3), 7);
}

TEST(SubtractTest, NegativeNumbers) {
    EXPECT_EQ(data_lab::subtract(-10, -3), -7);
}

TEST(SubtractTest, MixedSigns) {
    EXPECT_EQ(data_lab::subtract(10, -3), 13);
}

TEST(SubtractTest, WithZero) {
    EXPECT_EQ(data_lab::subtract(5, 0), 5);
}

TEST(SubtractTest, FromZero) {
    EXPECT_EQ(data_lab::subtract(0, 5), -5);
}

TEST(SubtractTest, BothZero) {
    EXPECT_EQ(data_lab::subtract(0, 0), 0);
}

TEST(SubtractTest, LargeNumbers) {
    EXPECT_EQ(data_lab::subtract(5000000, 2000000), 3000000);
}

TEST(SubtractTest, NegativeResult) {
    EXPECT_EQ(data_lab::subtract(3, 10), -7);
}

TEST(SubtractTest, SubtractNegative) {
    EXPECT_EQ(data_lab::subtract(-3, -10), 7);
}

TEST(SubtractTest, SameNumbers) {
    EXPECT_EQ(data_lab::subtract(42, 42), 0);
}

TEST(SubtractTest, MaxInt32) {
    EXPECT_EQ(data_lab::subtract(INT32_MAX, 0), INT32_MAX);
}

TEST(SubtractTest, MinInt32) {
    EXPECT_EQ(data_lab::subtract(INT32_MIN, 0), INT32_MIN);
}

// Multiply function tests (12 tests)
TEST(MultiplyTest, PositiveNumbers) {
    EXPECT_EQ(data_lab::multiply(5, 3), 15);
}

TEST(MultiplyTest, NegativeNumbers) {
    EXPECT_EQ(data_lab::multiply(-5, -3), 15);
}

TEST(MultiplyTest, MixedSigns) {
    EXPECT_EQ(data_lab::multiply(5, -3), -15);
}

TEST(MultiplyTest, WithZero) {
    EXPECT_EQ(data_lab::multiply(5, 0), 0);
}

TEST(MultiplyTest, ZeroWithNegative) {
    EXPECT_EQ(data_lab::multiply(0, -5), 0);
}

TEST(MultiplyTest, WithOne) {
    EXPECT_EQ(data_lab::multiply(7, 1), 7);
}

TEST(MultiplyTest, WithNegativeOne) {
    EXPECT_EQ(data_lab::multiply(7, -1), -7);
}

TEST(MultiplyTest, LargeNumbers) {
    EXPECT_EQ(data_lab::multiply(1000, 1000), 1000000);
}

TEST(MultiplyTest, NegativeByPositive) {
    EXPECT_EQ(data_lab::multiply(-10, 5), -50);
}

TEST(MultiplyTest, TwoNegatives) {
    EXPECT_EQ(data_lab::multiply(-8, -7), 56);
}

TEST(MultiplyTest, CommutativeProperty) {
    EXPECT_EQ(data_lab::multiply(6, 9), data_lab::multiply(9, 6));
}

TEST(MultiplyTest, PowersOfTwo) {
    EXPECT_EQ(data_lab::multiply(16, 8), 128);
}

// Divide function tests (12 tests)
TEST(DivideTest, PositiveNumbers) {
    EXPECT_EQ(data_lab::divide(10, 2), 5);
}

TEST(DivideTest, NegativeNumbers) {
    EXPECT_EQ(data_lab::divide(-10, -2), 5);
}

TEST(DivideTest, NegativeByPositive) {
    EXPECT_EQ(data_lab::divide(-10, 3), -3);
}

TEST(DivideTest, PositiveByNegative) {
    EXPECT_EQ(data_lab::divide(10, -3), -3);
}

TEST(DivideTest, ZeroDividend) {
    EXPECT_EQ(data_lab::divide(0, 5), 0);
}

TEST(DivideTest, DivideByOne) {
    EXPECT_EQ(data_lab::divide(42, 1), 42);
}

TEST(DivideTest, DivideByNegativeOne) {
    EXPECT_EQ(data_lab::divide(42, -1), -42);
}

TEST(DivideTest, SameNumbers) {
    EXPECT_EQ(data_lab::divide(7, 7), 1);
}

TEST(DivideTest, LargeNumbers) {
    EXPECT_EQ(data_lab::divide(1000000, 1000), 1000);
}

TEST(DivideTest, IntegerDivision) {
    EXPECT_EQ(data_lab::divide(7, 2), 3);
}

TEST(DivideTest, NegativeIntegerDivision) {
    EXPECT_EQ(data_lab::divide(-7, 2), -3);
}

TEST(DivideTest, MaxByItself) {
    EXPECT_EQ(data_lab::divide(INT32_MAX, INT32_MAX), 1);
}

// Modulo function tests (12 tests)
TEST(ModuloTest, PositiveNumbers) {
    EXPECT_EQ(data_lab::modulo(10, 3), 1);
}

TEST(ModuloTest, NegativeByPositive) {
    EXPECT_EQ(data_lab::modulo(-10, 3), -1);
}

TEST(ModuloTest, PositiveByNegative) {
    EXPECT_EQ(data_lab::modulo(10, -3), 1);
}

TEST(ModuloTest, NegativeNumbers) {
    EXPECT_EQ(data_lab::modulo(-10, -3), -1);
}

TEST(ModuloTest, ZeroDividend) {
    EXPECT_EQ(data_lab::modulo(0, 5), 0);
}

TEST(ModuloTest, NoRemainder) {
    EXPECT_EQ(data_lab::modulo(10, 5), 0);
}

TEST(ModuloTest, DividendSmallerThanDivisor) {
    EXPECT_EQ(data_lab::modulo(3, 10), 3);
}

TEST(ModuloTest, SameNumbers) {
    EXPECT_EQ(data_lab::modulo(7, 7), 0);
}

TEST(ModuloTest, ModuloByOne) {
    EXPECT_EQ(data_lab::modulo(42, 1), 0);
}

TEST(ModuloTest, LargeNumbers) {
    EXPECT_EQ(data_lab::modulo(1000007, 1000), 7);
}

TEST(ModuloTest, NegativeLargeNumber) {
    EXPECT_EQ(data_lab::modulo(-1000007, 1000), -7);
}

TEST(ModuloTest, PowersOfTwo) {
    EXPECT_EQ(data_lab::modulo(17, 4), 1);
}
