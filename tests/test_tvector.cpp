#include "TVector.h"
#include <gtest/gtest.h>

TEST(TVectorTest, BasicOperations) {
    TVector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);

    vec.pop_back();
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec.back(), 2);
}

TEST(TVectorTest, AtAndBounds) {
    TVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec.at(0), 10);
    EXPECT_THROW(vec.at(2), std::out_of_range);
}