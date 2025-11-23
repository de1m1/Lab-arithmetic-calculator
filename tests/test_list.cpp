#include <gtest/gtest.h>
#include "List.h" 

TEST(ListTest, CreateEmptyList) {
    List<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(ListTest, PushBack) {
    List<int> list;
    list.push_back(10);

    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);

    list.push_back(20);
    EXPECT_EQ(list.size(), 2);

    list.push_back(30);
    EXPECT_EQ(list.size(), 3);
}

TEST(ListTest, PushFront) {
    List<int> list;
    list.push_front(10);
    list.push_front(5);

    EXPECT_EQ(list.size(), 2);

    auto it = list.begin();
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(*it, 10);
}

TEST(ListTest, PopBack) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_back();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(*list.begin(), 10);

    list.pop_back();
    EXPECT_EQ(list.size(), 1);

    list.pop_back();
    EXPECT_EQ(list.size(), 0);
    EXPECT_TRUE(list.empty());
}

TEST(ListTest, PopFront) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_front();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(*list.begin(), 20);

    list.pop_front();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(*list.begin(), 30);

    list.pop_front();
    EXPECT_EQ(list.size(), 0);
    EXPECT_TRUE(list.empty());
}

TEST(ListTest, FrontAndBack) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);

    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);

    list.front() = 5;
    list.back() = 25;

    EXPECT_EQ(list.front(), 5);
    EXPECT_EQ(list.back(), 25);
}

TEST(ListTest, CopyConstructor) {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    List<int> list2 = list1; // Копирование

    EXPECT_EQ(list2.size(), 3);
    EXPECT_EQ(list2.front(), 1);
    EXPECT_EQ(list2.back(), 3);

    // Проверяем что это разные списки
    list1.front() = 100;
    EXPECT_EQ(list2.front(), 1); // list2 не изменился
}

TEST(ListTest, InsertAndErase) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);

    // Вставляем 2 между 1 и 3
    auto it = list.begin();
    ++it; // теперь указывает на 3
    list.insert(it, 2);

    EXPECT_EQ(list.size(), 3);

    auto it2 = list.begin();
    EXPECT_EQ(*it2, 1);
    ++it2;
    EXPECT_EQ(*it2, 2);
    ++it2;
    EXPECT_EQ(*it2, 3);

    // Удаляем средний элемент
    it2 = list.begin();
    ++it2;
    list.erase(it2);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 3);
}
