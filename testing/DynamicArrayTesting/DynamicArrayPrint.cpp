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

    friend ostream& operator<<(ostream& os, const TestObject& obj)
    {
        os << obj.value;
        return os;
    }
};

/*------------------------------------------------------------
    Print Empty Array
-------------------------------------------------------------*/

TEST(DynamicArrayPrintTest, PrintEmptyArray)
{
    DynamicArray<int> arr;

    testing::internal::CaptureStdout();

    arr.print();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "\n");
}

/*------------------------------------------------------------
    Print Integer Array
-------------------------------------------------------------*/

TEST(DynamicArrayPrintTest, PrintIntegerArray)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    testing::internal::CaptureStdout();

    arr.print();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 20 30 \n");
}

/*------------------------------------------------------------
    Print String Array
-------------------------------------------------------------*/

TEST(DynamicArrayPrintTest, PrintStringArray)
{
    DynamicArray<string> arr;

    arr.push_back("Apple");
    arr.push_back("Banana");
    arr.push_back("Cherry");

    testing::internal::CaptureStdout();

    arr.print();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Apple Banana Cherry \n");
}

/*------------------------------------------------------------
    Print Custom Object
-------------------------------------------------------------*/

TEST(DynamicArrayPrintTest, PrintCustomObjectArray)
{
    DynamicArray<TestObject> arr;

    arr.push_back(TestObject(5));
    arr.push_back(TestObject(10));
    arr.push_back(TestObject(15));

    testing::internal::CaptureStdout();

    arr.print();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "5 10 15 \n");
}