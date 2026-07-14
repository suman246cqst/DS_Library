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
    Remove From Different Positions
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, RemoveFromDifferentPositions)
{
    // Remove first node
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        int value = 10;
        list.remove(value);

        EXPECT_EQ(list.getSize(), 2);
        EXPECT_EQ(list.get(0), 20);
        EXPECT_EQ(list.get(1), 30);
    }

    // Remove middle node
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.push_back(40);

        int value = 20;
        list.remove(value);

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 30);
        EXPECT_EQ(list.get(2), 40);
    }

    // Remove last node
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        int value = 30;
        list.remove(value);

        EXPECT_EQ(list.getSize(), 2);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 20);
    }
}

/*------------------------------------------------------------
    Remove Until Empty
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, RemoveUntilEmpty)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    for (int i = 1; i <= 5; i++)
        list.remove(i);

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
}

/*------------------------------------------------------------
    Empty List Throws Exception
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, EmptyListThrowsException)
{
    LinkedList<int> list;

    int value = 10;

    EXPECT_THROW(list.remove(value), underflow_error);
}

/*------------------------------------------------------------
    Value Not Present
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, RemovingAbsentValueThrowsException)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    int value = 100;

    EXPECT_THROW(list.remove(value), runtime_error);

    EXPECT_EQ(list.getSize(), 3);
}

/*------------------------------------------------------------
    Duplicate Values
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, RemovesOnlyFirstOccurrence)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(20);
    list.push_back(30);

    int value = 20;

    list.remove(value);

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 30);
}

/*------------------------------------------------------------
    Negative Values
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, HandlesNegativeValues)
{
    LinkedList<int> list;

    list.push_back(-10);
    list.push_back(-20);
    list.push_back(-30);

    int value = -20;

    list.remove(value);

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0), -10);
    EXPECT_EQ(list.get(1), -30);
}

/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    string value = "Banana";

    list.remove(value);

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0), "Apple");
    EXPECT_EQ(list.get(1), "Cherry");
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    TestObject value(20);

    list.remove(value);

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0).value, 10);
    EXPECT_EQ(list.get(1).value, 30);
}

/*------------------------------------------------------------
    Large Number Of Elements
-------------------------------------------------------------*/

TEST(LinkedListRemoveTest, HandlesLargeNumberOfElements)
{
    LinkedList<int> list;

    for (int i = 0; i < 1000; i++)
        list.push_back(i);

    int value = 500;

    list.remove(value);

    EXPECT_EQ(list.getSize(), 999);

    EXPECT_EQ(list.search(500), -1);
    EXPECT_EQ(list.get(500), 501);
}