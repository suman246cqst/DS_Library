#include <gtest/gtest.h>
#include "dynamicArray.h"


TEST(DynamicArrayInsertTest, InsertElementAtMiddle)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    arr.insertAtIndex(1, 15);

    EXPECT_EQ(arr.getSize(), 4);

    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 15);
    EXPECT_EQ(arr.get(2), 20);
    EXPECT_EQ(arr.get(3), 30);
}


TEST(DynamicArrayInsertTest, InsertElementAtBeginning)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    arr.insertAtIndex(0, 5);

    EXPECT_EQ(arr.getSize(), 3);

    EXPECT_EQ(arr.get(0), 5);
    EXPECT_EQ(arr.get(1), 10);
    EXPECT_EQ(arr.get(2), 20);
}


TEST(DynamicArrayInsertTest, InsertElementAtEnd)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    arr.insertAtIndex(2, 30);

    EXPECT_EQ(arr.getSize(), 3);

    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
    EXPECT_EQ(arr.get(2), 30);
}


TEST(DynamicArrayInsertTest, InsertMultipleElements)
{
    DynamicArray<int> arr;

    for(int i = 1; i <= 5; i++)
    {
        arr.push_back(i * 10);
    }

    arr.insertAtIndex(3, 35);

    EXPECT_EQ(arr.getSize(), 6);

    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 20);
    EXPECT_EQ(arr.get(2), 30);
    EXPECT_EQ(arr.get(3), 35);
    EXPECT_EQ(arr.get(4), 40);
    EXPECT_EQ(arr.get(5), 50);
}