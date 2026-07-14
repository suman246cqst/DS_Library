#include <gtest/gtest.h>
#include <string>
#include <climits>
#include "dynamicArray.h"

using namespace std;

/*------------------------------------------------------------
    push_back() : Basic Insertion
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, InsertSingleElement)
{
    DynamicArray<int> arr;

    arr.push_back(10);

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr.getCapacity(), 1);
    EXPECT_EQ(arr[0], 10);
}

TEST(DynamicArrayPushBackTest, InsertMultipleElements)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    EXPECT_EQ(arr.getSize(), 4);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
    EXPECT_EQ(arr[3], 40);
}

/*------------------------------------------------------------
    Capacity Expansion
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, CapacityRemainsSameWhenNotFull)
{
    DynamicArray<int> arr;

    arr.push_back(1);

    EXPECT_EQ(arr.getCapacity(), 1);

    arr.push_back(2);

    EXPECT_EQ(arr.getCapacity(), 2);
}

TEST(DynamicArrayPushBackTest, CapacityDoublesFromOneToTwo)
{
    DynamicArray<int> arr;

    arr.push_back(1);
    arr.push_back(2);

    EXPECT_EQ(arr.getCapacity(), 2);
}

TEST(DynamicArrayPushBackTest, CapacityDoublesFromTwoToFour)
{
    DynamicArray<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    EXPECT_EQ(arr.getCapacity(), 4);
}

TEST(DynamicArrayPushBackTest, CapacityDoublesFromFourToEight)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 5; i++)
        arr.push_back(i);

    EXPECT_EQ(arr.getCapacity(), 8);
}

TEST(DynamicArrayPushBackTest, CapacityGrowsCorrectlyForManyInsertions)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 100; i++)
        arr.push_back(i);

    EXPECT_EQ(arr.getSize(), 100);

    for (int i = 0; i < 100; i++)
        EXPECT_EQ(arr[i], i);
}

/*------------------------------------------------------------
    Element Order
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, ElementsRemainInInsertionOrder)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 20; i++)
        arr.push_back(i);

    for (int i = 0; i < 20; i++)
        EXPECT_EQ(arr[i], i + 1);
}

/*------------------------------------------------------------
    Resize Integrity
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, ExistingElementsRemainAfterResize)
{
    DynamicArray<int> arr;

    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(15);
    arr.push_back(20);
    arr.push_back(25);

    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 10);
    EXPECT_EQ(arr[2], 15);
    EXPECT_EQ(arr[3], 20);
    EXPECT_EQ(arr[4], 25);
}

TEST(DynamicArrayPushBackTest, MultipleResizesPreserveData)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 1000; i++)
        arr.push_back(i);

    EXPECT_EQ(arr.getSize(), 1000);

    for (int i = 0; i < 1000; i++)
        EXPECT_EQ(arr[i], i);
}

/*------------------------------------------------------------
    Different Data Types
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, PushBackString)
{
    DynamicArray<string> arr;

    arr.push_back("Apple");
    arr.push_back("Banana");
    arr.push_back("Cherry");

    EXPECT_EQ(arr.getSize(), 3);

    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
    EXPECT_EQ(arr[2], "Cherry");
}

TEST(DynamicArrayPushBackTest, PushBackCharacter)
{
    DynamicArray<char> arr;

    arr.push_back('A');
    arr.push_back('B');
    arr.push_back('C');

    EXPECT_EQ(arr[0], 'A');
    EXPECT_EQ(arr[1], 'B');
    EXPECT_EQ(arr[2], 'C');
}

TEST(DynamicArrayPushBackTest, PushBackDouble)
{
    DynamicArray<double> arr;

    arr.push_back(1.5);
    arr.push_back(2.5);

    EXPECT_DOUBLE_EQ(arr[0], 1.5);
    EXPECT_DOUBLE_EQ(arr[1], 2.5);
}

/*------------------------------------------------------------
    Empty State
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, ArrayIsNotEmptyAfterInsertion)
{
    DynamicArray<int> arr;

    EXPECT_TRUE(arr.isEmpty());

    arr.push_back(100);

    EXPECT_FALSE(arr.isEmpty());
}

/*------------------------------------------------------------
    Full State
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, ArrayBecomesFullAfterFirstInsertion)
{
    DynamicArray<int> arr;

    arr.push_back(1);

    EXPECT_TRUE(arr.isFull());
}

TEST(DynamicArrayPushBackTest, ArrayRemainsFullAfterAutomaticResize)
{
    DynamicArray<int> arr;

    arr.push_back(1);
    arr.push_back(2);

    EXPECT_TRUE(arr.isFull());

    arr.push_back(3);

    EXPECT_FALSE(arr.isFull());

    arr.push_back(4);

    EXPECT_TRUE(arr.isFull());
}

/*------------------------------------------------------------
    Boundary Values
-------------------------------------------------------------*/

TEST(DynamicArrayPushBackTest, PushBackIntegerLimits)
{
    DynamicArray<int> arr;

    arr.push_back(INT_MIN);
    arr.push_back(INT_MAX);

    EXPECT_EQ(arr[0], INT_MIN);
    EXPECT_EQ(arr[1], INT_MAX);
}

TEST(DynamicArrayPushBackTest, PushBackDuplicateValues)
{
    DynamicArray<int> arr;

    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(5);

    EXPECT_EQ(arr.getSize(), 3);

    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);
    EXPECT_EQ(arr[2], 5);
}

TEST(DynamicArrayPushBackTest, PushBackNegativeValues)
{
    DynamicArray<int> arr;

    arr.push_back(-10);
    arr.push_back(-20);

    EXPECT_EQ(arr[0], -10);
    EXPECT_EQ(arr[1], -20);
}