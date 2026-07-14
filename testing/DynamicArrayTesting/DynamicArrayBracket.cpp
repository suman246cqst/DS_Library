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

TEST(DynamicArrayOperatorBracketTest, AccessValidIndices)
{
    DynamicArray<int> arr;

    for (int i = 1; i <= 5; i++)
        arr.push_back(i * 10);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[2], 30);
    EXPECT_EQ(arr[4], 50);
}

/*------------------------------------------------------------
    Invalid Index Access
-------------------------------------------------------------*/

TEST(DynamicArrayOperatorBracketTest, InvalidIndicesThrowExceptions)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    EXPECT_THROW(arr[-1], out_of_range);
    EXPECT_THROW(arr[2], out_of_range);
    EXPECT_THROW(arr[100], out_of_range);

    DynamicArray<int> empty;

    EXPECT_THROW(empty[0], out_of_range);
}

/*------------------------------------------------------------
    Returned Reference Allows Modification
-------------------------------------------------------------*/

TEST(DynamicArrayOperatorBracketTest, ReturnedReferenceAllowsModification)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    arr[1] = 100;

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 100);
}

/*------------------------------------------------------------
    Const Operator[]
-------------------------------------------------------------*/

TEST(DynamicArrayOperatorBracketTest, ConstOperatorAccess)
{
    DynamicArray<int> temp;

    temp.push_back(5);
    temp.push_back(15);
    temp.push_back(25);

    const DynamicArray<int>& arr = temp;

    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 15);
    EXPECT_EQ(arr[2], 25);
}

/*------------------------------------------------------------
    Works With String And Custom Object
-------------------------------------------------------------*/

TEST(DynamicArrayOperatorBracketTest, WorksWithStringAndCustomObject)
{
    // String
    DynamicArray<string> strArr;

    strArr.push_back("Apple");
    strArr.push_back("Banana");

    EXPECT_EQ(strArr[0], "Apple");
    EXPECT_EQ(strArr[1], "Banana");

    strArr[1] = "Cherry";

    EXPECT_EQ(strArr[1], "Cherry");

    // Custom Object
    DynamicArray<TestObject> objArr;

    objArr.push_back(TestObject(10));
    objArr.push_back(TestObject(20));

    EXPECT_EQ(objArr[0].value, 10);
    EXPECT_EQ(objArr[1].value, 20);

    objArr[1].value = 99;

    EXPECT_EQ(objArr[1].value, 99);
}