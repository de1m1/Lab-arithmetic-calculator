#include "Stack.h"
#include <gtest/gtest.h>


TEST(StackTest, BasicOperations) {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.top(), 3);
    EXPECT_EQ(stack.size(), 3);

    stack.pop();
    EXPECT_EQ(stack.top(), 2);

    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.empty());
}