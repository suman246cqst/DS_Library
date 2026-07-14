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
    Valid Index Access
-------------------------------------------------------------*/

TEST(DynamicArrayGetTest, AccessValidIndices)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 5; i++)
        arr.push_back(i * 10);

    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(2), 30);
    EXPECT_EQ(arr.get(4), 50);
}

/*------------------------------------------------------------
    Invalid Index Access
-------------------------------------------------------------*/

TEST(DynamicArrayGetTest, InvalidIndicesThrowExceptions)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    EXPECT_THROW(arr.get(-1), out_of_range);
    EXPECT_THROW(arr.get(2), out_of_range);
    EXPECT_THROW(arr.get(100), out_of_range);

    DynamicArray<int> empty;

    EXPECT_THROW(empty.get(0), out_of_range);
}

/*------------------------------------------------------------
    Returned Reference Can Modify Element
-------------------------------------------------------------*/

TEST(DynamicArrayGetTest, ReturnedReferenceAllowsModification)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    arr.get(1) = 100;

    EXPECT_EQ(arr.get(0), 10);
    EXPECT_EQ(arr.get(1), 100);
}

/*------------------------------------------------------------
    Works With Different Data Types
-------------------------------------------------------------*/

TEST(DynamicArrayGetTest, WorksWithStringAndCustomObject)
{
    // String
    DynamicArray<string> strArr;

    strArr.push_back("Apple");
    strArr.push_back("Banana");

    EXPECT_EQ(strArr.get(0), "Apple");
    EXPECT_EQ(strArr.get(1), "Banana");

    // Custom Object
    DynamicArray<TestObject> objArr;

    objArr.push_back(TestObject(10));
    objArr.push_back(TestObject(20));

    EXPECT_EQ(objArr.get(0).value, 10);
    EXPECT_EQ(objArr.get(1).value, 20);

    objArr.get(0).value = 99;

    EXPECT_EQ(objArr.get(0).value, 99);
}