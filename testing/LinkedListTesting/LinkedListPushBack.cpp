#include <gtest/gtest.h>
#include <string>
#include "linkedList.h"

using namespace std;


/*------------------------------------------------------------
    Helper Class
-------------------------------------------------------------*/

class TestObject
{
public:

    int value;

    TestObject(int val = 0)
        : value(val)
    {
    }

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
    Insert Into Empty And Non-Empty List
-------------------------------------------------------------*/

TEST(LinkedListPushBackTest, InsertIntoEmptyAndNonEmptyList)
{
    LinkedList<int> list;

    // Insert into empty list
    list.push_back(10);

    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.get(0), 10);

    // Insert into non-empty list
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}


/*------------------------------------------------------------
    Preserve Insertion Order
-------------------------------------------------------------*/

TEST(LinkedListPushBackTest, PreserveInsertionOrderAfterMultipleInsertions)
{
    LinkedList<int> list;

    for (int i = 1; i <= 10; i++)
        list.push_back(i);

    EXPECT_EQ(list.getSize(), 10);

    for (int i = 0; i < 10; i++)
        EXPECT_EQ(list.get(i), i + 1);
}


/*------------------------------------------------------------
    Supports Duplicate And Negative Values
-------------------------------------------------------------*/

TEST(LinkedListPushBackTest, SupportsDuplicateAndNegativeValues)
{
    LinkedList<int> list;

    list.push_back(-10);
    list.push_back(-20);
    list.push_back(-20);
    list.push_back(0);

    EXPECT_EQ(list.getSize(), 4);

    EXPECT_EQ(list.get(0), -10);
    EXPECT_EQ(list.get(1), -20);
    EXPECT_EQ(list.get(2), -20);
    EXPECT_EQ(list.get(3), 0);
}


/*------------------------------------------------------------
    Supports String Type
-------------------------------------------------------------*/

TEST(LinkedListPushBackTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0), "Apple");
    EXPECT_EQ(list.get(1), "Banana");
    EXPECT_EQ(list.get(2), "Cherry");
}


/*------------------------------------------------------------
    Supports Custom Object Type
-------------------------------------------------------------*/

TEST(LinkedListPushBackTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0).value, 10);
    EXPECT_EQ(list.get(1).value, 20);
    EXPECT_EQ(list.get(2).value, 30);
}


/*------------------------------------------------------------
    Handles Large Number Of Insertions
-------------------------------------------------------------*/

TEST(LinkedListPushBackTest, HandlesLargeNumberOfInsertions)
{
    LinkedList<int> list;

    const int totalElements = 1000;

    for (int i = 1; i <= totalElements; i++)
        list.push_back(i);

    EXPECT_EQ(list.getSize(), totalElements);

    EXPECT_EQ(list.get(0), 1);
    EXPECT_EQ(list.get(totalElements - 1), totalElements);

    for (int i = 0; i < totalElements; i++)
        EXPECT_EQ(list.get(i), i + 1);
}