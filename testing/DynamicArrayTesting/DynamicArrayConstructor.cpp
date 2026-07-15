#include <gtest/gtest.h>
#include <string>
#include "dynamicArray.h"


// Test 1: Verify initial state after default construction
TEST(DynamicArrayConstructorTest, DefaultConstructorInitialState)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 1);

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_FALSE(arr.isFull());
}


// Test 2: First insertion after construction
TEST(DynamicArrayConstructorTest, CanInsertAfterConstruction)
{
    DynamicArray<int> arr;

    arr.push_back(10);

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr.getCapacity(), 1);

    EXPECT_FALSE(arr.isEmpty());
    EXPECT_TRUE(arr.isFull());

    EXPECT_EQ(arr[0], 10);
}


// Test 3: Capacity grows correctly after first reallocation
TEST(DynamicArrayConstructorTest, CapacityGrowthAfterConstruction)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr.getCapacity(), 2);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}


// Test 4: Constructor works for std::string
TEST(DynamicArrayConstructorTest, WorksWithStringType)
{
    DynamicArray<std::string> arr;

    EXPECT_TRUE(arr.isEmpty());

    arr.push_back("OpenAI");

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr[0], "OpenAI");
}


// Test 5: Constructor works for user-defined type
class Student
{
public:

    int id;

    Student(int value = 0)
    {
        id = value;
    }
};

TEST(DynamicArrayConstructorTest, WorksWithUserDefinedType)
{
    DynamicArray<Student> arr;

    Student s(101);

    arr.push_back(s);

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr[0].id, 101);
}

