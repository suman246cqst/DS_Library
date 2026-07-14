#include <gtest/gtest.h>
#include <string>
#include "dynamicArray.h"

using namespace std;

/*------------------------------------------------------------
    Helper Class
-------------------------------------------------------------*/

class TestObject
{
public:
    int value;

    TestObject(int val = 0) : value(val) {}

    TestObject(const TestObject& other)
    {
        value = other.value;
    }

    TestObject& operator=(const TestObject& other)
    {
        if (this != &other)
            value = other.value;
        return *this;
    }

    bool operator==(const TestObject& other) const
    {
        return value == other.value;
    }
};

/*------------------------------------------------------------
    Delete At Different Positions
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, DeleteAtDifferentPositions)
{
    // Delete First
    {
        DynamicArray<int> arr;

        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);

        arr.deleteAtIndex(0);

        EXPECT_EQ(arr.getSize(), 2);
        EXPECT_EQ(arr[0], 20);
        EXPECT_EQ(arr[1], 30);
    }

    // Delete Middle
    {
        DynamicArray<int> arr;

        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);
        arr.push_back(40);

        arr.deleteAtIndex(2);

        EXPECT_EQ(arr.getSize(), 3);
        EXPECT_EQ(arr[0], 10);
        EXPECT_EQ(arr[1], 20);
        EXPECT_EQ(arr[2], 40);
    }

    // Delete Last
    {
        DynamicArray<int> arr;

        arr.push_back(10);
        arr.push_back(20);
        arr.push_back(30);

        arr.deleteAtIndex(2);

        EXPECT_EQ(arr.getSize(), 2);
        EXPECT_EQ(arr[0], 10);
        EXPECT_EQ(arr[1], 20);
    }
}

/*------------------------------------------------------------
    Delete Until Empty
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, DeleteUntilEmpty)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 5; i++)
        arr.push_back(i);

    while (!arr.isEmpty())
    {
        arr.deleteAtIndex(0);
    }

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.getSize(), 0);
}

/*------------------------------------------------------------
    Delete After Resize
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, DeleteAfterResize)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 20; i++)
        arr.push_back(i);

    int capacity = arr.getCapacity();

    arr.deleteAtIndex(10);

    EXPECT_EQ(arr.getSize(), 19);
    EXPECT_EQ(arr.getCapacity(), capacity);

    for (int i = 0; i < 10; i++)
        EXPECT_EQ(arr[i], i);

    for (int i = 10; i < 19; i++)
        EXPECT_EQ(arr[i], i + 1);
}

/*------------------------------------------------------------
    Invalid Index Tests
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, InvalidIndicesThrowExceptions)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    EXPECT_THROW(arr.deleteAtIndex(-1), out_of_range);
    EXPECT_THROW(arr.deleteAtIndex(2), out_of_range);
    EXPECT_THROW(arr.deleteAtIndex(100), out_of_range);

    DynamicArray<int> empty;

    EXPECT_THROW(empty.deleteAtIndex(0), underflow_error);
}

/*------------------------------------------------------------
    Duplicate And Negative Values
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, DeleteDuplicateAndNegativeValues)
{
    DynamicArray<int> arr;

    arr.push_back(-10);
    arr.push_back(-20);
    arr.push_back(-20);
    arr.push_back(-30);

    arr.deleteAtIndex(1);

    EXPECT_EQ(arr.getSize(), 3);

    EXPECT_EQ(arr[0], -10);
    EXPECT_EQ(arr[1], -20);
    EXPECT_EQ(arr[2], -30);
}

/*------------------------------------------------------------
    String Type
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, WorksWithString)
{
    DynamicArray<string> arr;

    arr.push_back("Apple");
    arr.push_back("Banana");
    arr.push_back("Cherry");

    arr.deleteAtIndex(1);

    EXPECT_EQ(arr.getSize(), 2);

    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Cherry");
}

/*------------------------------------------------------------
    Custom Object
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, WorksWithCustomObject)
{
    DynamicArray<TestObject> arr;

    arr.push_back(TestObject(10));
    arr.push_back(TestObject(20));
    arr.push_back(TestObject(30));

    arr.deleteAtIndex(1);

    EXPECT_EQ(arr.getSize(), 2);

    EXPECT_EQ(arr[0].value, 10);
    EXPECT_EQ(arr[1].value, 30);
}

/*------------------------------------------------------------
    Consecutive Deletions
-------------------------------------------------------------*/

TEST(DynamicArrayDeleteAtIndexTest, ConsecutiveDeletionsMaintainIntegrity)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 8; i++)
        arr.push_back(i);

    arr.deleteAtIndex(2); // remove 3
    arr.deleteAtIndex(2); // remove 4
    arr.deleteAtIndex(4); // remove 7

    EXPECT_EQ(arr.getSize(), 5);

    int expected[] = {1, 2, 5, 6, 8};

    for (int i = 0; i < arr.getSize(); i++)
        EXPECT_EQ(arr[i], expected[i]);
}