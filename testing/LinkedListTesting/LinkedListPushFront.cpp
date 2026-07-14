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

TEST(LinkedListPushFrontTest, InsertIntoEmptyAndNonEmptyList)
{
    LinkedList<int> list;

    // Insert into an empty list
    list.push_front(10);

    EXPECT_EQ(list.getSize(), 1);
    EXPECT_EQ(list.get(0), 10);

    // Insert into a non-empty list
    list.push_front(20);
    list.push_front(30);

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0), 30);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 10);
}


/*------------------------------------------------------------
    Preserve List Order After Multiple Insertions
-------------------------------------------------------------*/

TEST(LinkedListPushFrontTest, PreserveListOrderAfterMultipleInsertions)
{
    LinkedList<int> list;

    for (int i = 1; i <= 10; i++)
        list.push_front(i);

    EXPECT_EQ(list.getSize(), 10);

    int expected[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), expected[i]);
}


/*------------------------------------------------------------
    Supports Duplicate And Negative Values
-------------------------------------------------------------*/

TEST(LinkedListPushFrontTest, SupportsDuplicateAndNegativeValues)
{
    LinkedList<int> list;

    list.push_front(-10);
    list.push_front(-20);
    list.push_front(-20);
    list.push_front(-30);
    list.push_front(0);

    EXPECT_EQ(list.getSize(), 5);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), -30);
    EXPECT_EQ(list.get(2), -20);
    EXPECT_EQ(list.get(3), -20);
    EXPECT_EQ(list.get(4), -10);
}


/*------------------------------------------------------------
    Supports String Type
-------------------------------------------------------------*/

TEST(LinkedListPushFrontTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_front("Apple");
    list.push_front("Banana");
    list.push_front("Cherry");

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0), "Cherry");
    EXPECT_EQ(list.get(1), "Banana");
    EXPECT_EQ(list.get(2), "Apple");
}


/*------------------------------------------------------------
    Supports Custom Object Type
-------------------------------------------------------------*/

TEST(LinkedListPushFrontTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_front(TestObject(10));
    list.push_front(TestObject(20));
    list.push_front(TestObject(30));

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0).value, 30);
    EXPECT_EQ(list.get(1).value, 20);
    EXPECT_EQ(list.get(2).value, 10);
}


/*------------------------------------------------------------
    Handles Large Number Of Insertions
-------------------------------------------------------------*/

TEST(LinkedListPushFrontTest, HandlesLargeNumberOfInsertions)
{
    LinkedList<int> list;

    const int totalElements = 1000;

    for (int i = 1; i <= totalElements; i++)
        list.push_front(i);

    EXPECT_EQ(list.getSize(), totalElements);

    EXPECT_EQ(list.get(0), totalElements);
    EXPECT_EQ(list.get(totalElements - 1), 1);

    for (int i = 0; i < totalElements; i++)
        EXPECT_EQ(list.get(i), totalElements - i);
}