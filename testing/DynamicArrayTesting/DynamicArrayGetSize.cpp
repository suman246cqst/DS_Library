#include <gtest/gtest.h>
#include <string>
#include "dynamicArray.h"

using namespace std;

/*------------------------------------------------------------
    Initial Size
-------------------------------------------------------------*/

TEST(DynamicArrayGetSizeTest, InitialSizeIsZero)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

/*------------------------------------------------------------
    Size Updates After Operations
-------------------------------------------------------------*/

TEST(DynamicArrayGetSizeTest, SizeUpdatesCorrectly)
{
    DynamicArray<int> arr;

    // Push
    arr.push_back(10);
    EXPECT_EQ(arr.getSize(), 1);

    arr.push_back(20);
    EXPECT_EQ(arr.getSize(), 2);

    // Insert
    arr.insertAtIndex(1, 15);
    EXPECT_EQ(arr.getSize(), 3);

    // Delete
    arr.deleteAtIndex(0);
    EXPECT_EQ(arr.getSize(), 2);

    // Pop
    arr.pop_back();
    EXPECT_EQ(arr.getSize(), 1);

    arr.pop_back();
    EXPECT_EQ(arr.getSize(), 0);
}

/*------------------------------------------------------------
    Large Number Of Operations
-------------------------------------------------------------*/

TEST(DynamicArrayGetSizeTest, LargeNumberOfOperations)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 100; i++)
        arr.push_back(i);

    EXPECT_EQ(arr.getSize(), 100);

    for (int i = 0; i < 50; i++)
        arr.pop_back();

    EXPECT_EQ(arr.getSize(), 50);

    for (int i = 0; i < 25; i++)
        arr.deleteAtIndex(0);

    EXPECT_EQ(arr.getSize(), 25);
}