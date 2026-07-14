#include <gtest/gtest.h>
#include "dynamicArray.h"

using namespace std;

/*------------------------------------------------------------
    Empty And Non-Empty States
-------------------------------------------------------------*/

TEST(DynamicArrayIsEmptyTest, EmptyAndNonEmptyStates)
{
    DynamicArray<int> arr;

    EXPECT_TRUE(arr.isEmpty());

    arr.push_back(10);
    EXPECT_FALSE(arr.isEmpty());

    arr.pop_back();
    EXPECT_TRUE(arr.isEmpty());
}

/*------------------------------------------------------------
    State After Different Operations
-------------------------------------------------------------*/

TEST(DynamicArrayIsEmptyTest, StateAfterOperations)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    EXPECT_FALSE(arr.isEmpty());

    arr.deleteAtIndex(1);
    EXPECT_FALSE(arr.isEmpty());

    arr.insertAtIndex(1, 40);
    EXPECT_FALSE(arr.isEmpty());

    arr.pop_back();
    arr.pop_back();
    arr.pop_back();

    EXPECT_TRUE(arr.isEmpty());
}

/*------------------------------------------------------------
    Large Number Of Operations
-------------------------------------------------------------*/

TEST(DynamicArrayIsEmptyTest, LargeNumberOfOperations)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 100; i++)
        arr.push_back(i);

    EXPECT_FALSE(arr.isEmpty());

    while (!arr.isEmpty())
    {
        arr.pop_back();
    }

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.getSize(), 0);
}