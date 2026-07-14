#include <gtest/gtest.h>
#include "dynamicArray.h"

using namespace std;

/*------------------------------------------------------------
    Initial Capacity
-------------------------------------------------------------*/

TEST(DynamicArrayGetCapacityTest, InitialCapacity)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.getCapacity(), 1);
    EXPECT_EQ(arr.getSize(), 0);
}

/*------------------------------------------------------------
    Capacity Growth
-------------------------------------------------------------*/

TEST(DynamicArrayGetCapacityTest, CapacityGrowsCorrectly)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.getCapacity(), 1);

    arr.push_back(10);
    EXPECT_EQ(arr.getCapacity(), 1);

    arr.push_back(20);
    EXPECT_EQ(arr.getCapacity(), 2);

    arr.push_back(30);
    EXPECT_EQ(arr.getCapacity(), 4);

    arr.push_back(40);
    EXPECT_EQ(arr.getCapacity(), 4);

    arr.push_back(50);
    EXPECT_EQ(arr.getCapacity(), 8);
}

/*------------------------------------------------------------
    Capacity Does Not Shrink
-------------------------------------------------------------*/

TEST(DynamicArrayGetCapacityTest, CapacityDoesNotShrink)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 20; i++)
        arr.push_back(i);

    int capacity = arr.getCapacity();

    arr.pop_back();
    arr.deleteAtIndex(0);
    arr.pop_back();

    EXPECT_EQ(arr.getCapacity(), capacity);
}

/*------------------------------------------------------------
    Capacity After Insertions
-------------------------------------------------------------*/

TEST(DynamicArrayGetCapacityTest, CapacityAfterInsertAtIndex)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);      // Capacity = 2

    EXPECT_EQ(arr.getCapacity(), 2);

    arr.insertAtIndex(1, 15);

    EXPECT_EQ(arr.getCapacity(), 4);
    EXPECT_EQ(arr.getSize(), 3);
}