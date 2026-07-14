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
    Assignment Operator : Empty Arrays
-------------------------------------------------------------*/

TEST(DynamicArrayAssignmentOperatorTest, AssignEmptyArrays)
{
    DynamicArray<int> arr1;
    DynamicArray<int> arr2;

    arr2 = arr1;

    EXPECT_TRUE(arr2.isEmpty());
    EXPECT_EQ(arr2.getSize(), 0);
    EXPECT_EQ(arr2.getCapacity(), arr1.getCapacity());
}

/*------------------------------------------------------------
    Assignment Operator : Deep Copy
-------------------------------------------------------------*/

TEST(DynamicArrayAssignmentOperatorTest, CreatesDeepCopy)
{
    DynamicArray<int> arr1;

    for (int i = 1; i <= 5; i++)
        arr1.push_back(i);

    DynamicArray<int> arr2;
    arr2 = arr1;

    EXPECT_EQ(arr2.getSize(), arr1.getSize());
    EXPECT_EQ(arr2.getCapacity(), arr1.getCapacity());

    for (int i = 0; i < arr1.getSize(); i++)
        EXPECT_EQ(arr2[i], arr1[i]);

    arr2[0] = 100;

    EXPECT_EQ(arr1[0], 1);
    EXPECT_EQ(arr2[0], 100);
}

/*------------------------------------------------------------
    Assignment Operator : Copy From Empty Array
-------------------------------------------------------------*/

TEST(DynamicArrayAssignmentOperatorTest, AssignFromEmptyArray)
{
    DynamicArray<int> arr1;

    DynamicArray<int> arr2;

    arr2.push_back(10);
    arr2.push_back(20);

    arr2 = arr1;

    EXPECT_TRUE(arr2.isEmpty());
    EXPECT_EQ(arr2.getSize(), 0);
}

/*------------------------------------------------------------
    Assignment Operator : Self Assignment
-------------------------------------------------------------*/

TEST(DynamicArrayAssignmentOperatorTest, SelfAssignment)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    arr = arr;

    EXPECT_EQ(arr.getSize(), 3);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}

/*------------------------------------------------------------
    Assignment Operator : After Resize
-------------------------------------------------------------*/

TEST(DynamicArrayAssignmentOperatorTest, AssignmentAfterResize)
{
    DynamicArray<int> arr1;

    for (int i = 0; i < 100; i++)
        arr1.push_back(i);

    DynamicArray<int> arr2;

    arr2 = arr1;

    EXPECT_EQ(arr2.getSize(), arr1.getSize());
    EXPECT_EQ(arr2.getCapacity(), arr1.getCapacity());

    for (int i = 0; i < 100; i++)
        EXPECT_EQ(arr2[i], arr1[i]);
}

/*------------------------------------------------------------
    Assignment Operator : String And Custom Object
-------------------------------------------------------------*/

TEST(DynamicArrayAssignmentOperatorTest, WorksWithStringAndCustomObject)
{
    // String
    DynamicArray<string> str1;
    str1.push_back("Apple");
    str1.push_back("Banana");

    DynamicArray<string> str2;
    str2 = str1;

    EXPECT_EQ(str2[0], "Apple");
    EXPECT_EQ(str2[1], "Banana");

    str2[0] = "Orange";

    EXPECT_EQ(str1[0], "Apple");
    EXPECT_EQ(str2[0], "Orange");

    // Custom Object
    DynamicArray<TestObject> obj1;

    obj1.push_back(TestObject(10));
    obj1.push_back(TestObject(20));

    DynamicArray<TestObject> obj2;
    obj2 = obj1;

    EXPECT_EQ(obj2[0].value, 10);
    EXPECT_EQ(obj2[1].value, 20);

    obj2[1].value = 99;

    EXPECT_EQ(obj1[1].value, 20);
    EXPECT_EQ(obj2[1].value, 99);
}