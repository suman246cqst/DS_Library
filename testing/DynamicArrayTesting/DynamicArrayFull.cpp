#include <gtest/gtest.h>
#include "dynamicArray.h"

using namespace std;

/*------------------------------------------------------------
    Initial State
-------------------------------------------------------------*/

TEST(DynamicArrayIsFullTest, InitialState)
{
    DynamicArray<int> arr;

    EXPECT_FALSE(arr.isFull());
    EXPECT_TRUE(arr.isEmpty());
}

/*------------------------------------------------------------
    Full State After Insertions
-------------------------------------------------------------*/

TEST(DynamicArrayIsFullTest, FullStateChangesCorrectly)
{
    DynamicArray<int> arr;

    // Capacity = 1
    arr.push_back(10);

    EXPECT_TRUE(arr.isFull());

    // Resize to capacity = 2
    arr.push_back(20);

    EXPECT_TRUE(arr.isFull());

    // Resize to capacity = 4
    arr.push_back(30);

    EXPECT_FALSE(arr.isFull());

    arr.push_back(40);

    EXPECT_TRUE(arr.isFull());
}

/*------------------------------------------------------------
    State After Pop And Delete
-------------------------------------------------------------*/

TEST(DynamicArrayIsFullTest, StateAfterRemovingElements)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 4; i++)
        arr.push_back(i);

    EXPECT_TRUE(arr.isFull());

    arr.pop_back();
    EXPECT_FALSE(arr.isFull());

    arr.deleteAtIndex(0);
    EXPECT_FALSE(arr.isFull());
}

/*------------------------------------------------------------
    Large Number Of Operations
-------------------------------------------------------------*/

TEST(DynamicArrayIsFullTest, LargeNumberOfOperations)
{
    DynamicArray<int> arr;

    while (!arr.isFull())
    {
        arr.push_back(0);
    }

    EXPECT_TRUE(arr.isFull());

    arr.pop_back();

    EXPECT_FALSE(arr.isFull());

    arr.push_back(1);

    EXPECT_TRUE(arr.isFull());
}