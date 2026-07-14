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
    Copy Constructor : Empty Array
-------------------------------------------------------------*/

TEST(DynamicArrayCopyConstructorTest, CopyEmptyArray)
{
    DynamicArray<int> original;

    DynamicArray<int> copy(original);

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.getSize(), 0);
    EXPECT_EQ(copy.getCapacity(), original.getCapacity());
}

/*------------------------------------------------------------
    Copy Constructor : Deep Copy
-------------------------------------------------------------*/

TEST(DynamicArrayCopyConstructorTest, CreatesDeepCopy)
{
    DynamicArray<int> original;

    for (int i = 1; i <= 5; i++)
        original.push_back(i);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.getSize(), original.getSize());
    EXPECT_EQ(copy.getCapacity(), original.getCapacity());

    for (int i = 0; i < original.getSize(); i++)
        EXPECT_EQ(copy[i], original[i]);

    // Modify copied object
    copy[0] = 100;

    EXPECT_EQ(original[0], 1);
    EXPECT_EQ(copy[0], 100);
}

/*------------------------------------------------------------
    Copy Constructor : After Resize
-------------------------------------------------------------*/

TEST(DynamicArrayCopyConstructorTest, CopyAfterMultipleResizes)
{
    DynamicArray<int> original;

    for (int i = 0; i < 100; i++)
        original.push_back(i);

    DynamicArray<int> copy(original);

    EXPECT_EQ(copy.getSize(), original.getSize());
    EXPECT_EQ(copy.getCapacity(), original.getCapacity());

    for (int i = 0; i < 100; i++)
        EXPECT_EQ(copy[i], original[i]);
}

/*------------------------------------------------------------
    Copy Constructor : String and Custom Object
-------------------------------------------------------------*/

TEST(DynamicArrayCopyConstructorTest, WorksWithStringAndCustomObject)
{
    // String
    DynamicArray<string> strOriginal;

    strOriginal.push_back("Apple");
    strOriginal.push_back("Banana");

    DynamicArray<string> strCopy(strOriginal);

    EXPECT_EQ(strCopy[0], "Apple");
    EXPECT_EQ(strCopy[1], "Banana");

    strCopy[0] = "Orange";

    EXPECT_EQ(strOriginal[0], "Apple");
    EXPECT_EQ(strCopy[0], "Orange");

    // Custom Object
    DynamicArray<TestObject> objOriginal;

    objOriginal.push_back(TestObject(10));
    objOriginal.push_back(TestObject(20));

    DynamicArray<TestObject> objCopy(objOriginal);

    EXPECT_EQ(objCopy[0].value, 10);
    EXPECT_EQ(objCopy[1].value, 20);

    objCopy[1].value = 99;

    EXPECT_EQ(objOriginal[1].value, 20);
    EXPECT_EQ(objCopy[1].value, 99);
}