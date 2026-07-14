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
    Pop From Different Sized Lists
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, PopFromDifferentSizedLists)
{
    // Single element
    {
        LinkedList<int> list;

        list.push_back(10);

        list.pop_back();

        EXPECT_EQ(list.getSize(), 0);
        EXPECT_EQ(list.getHead(), nullptr);
    }

    // Two elements
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);

        list.pop_back();

        EXPECT_EQ(list.getSize(), 1);
        EXPECT_EQ(list.get(0), 10);
    }

    // Multiple elements
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.push_back(40);

        list.pop_back();

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 20);
        EXPECT_EQ(list.get(2), 30);
    }
}

/*------------------------------------------------------------
    Pop Until Empty
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, PopUntilEmpty)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    while (list.getSize() > 0)
        list.pop_back();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
}

/*------------------------------------------------------------
    Empty List Throws Exception
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, EmptyListThrowsException)
{
    LinkedList<int> list;

    EXPECT_THROW(list.pop_back(), underflow_error);
}

/*------------------------------------------------------------
    Duplicate And Negative Values
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, HandlesDuplicateAndNegativeValues)
{
    LinkedList<int> list;

    list.push_back(-10);
    list.push_back(-20);
    list.push_back(-20);
    list.push_back(-30);

    list.pop_back();

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0), -10);
    EXPECT_EQ(list.get(1), -20);
    EXPECT_EQ(list.get(2), -20);
}

/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    list.pop_back();

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0), "Apple");
    EXPECT_EQ(list.get(1), "Banana");
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    list.pop_back();

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0).value, 10);
    EXPECT_EQ(list.get(1).value, 20);
}

/*------------------------------------------------------------
    Handles Large Number Of Elements
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, HandlesLargeNumberOfElements)
{
    LinkedList<int> list;

    const int totalElements = 1000;

    for (int i = 0; i < totalElements; i++)
        list.push_back(i);

    for (int i = totalElements - 1; i >= 0; i--)
    {
        EXPECT_EQ(list.get(list.getSize() - 1), i);
        list.pop_back();
    }

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
}

/*------------------------------------------------------------
    Consecutive Pop Operations Maintain Integrity
-------------------------------------------------------------*/

TEST(LinkedListPopBackTest, ConsecutivePopOperationsMaintainIntegrity)
{
    LinkedList<int> list;

    for (int i = 1; i <= 8; i++)
        list.push_back(i);

    list.pop_back(); // remove 8
    list.pop_back(); // remove 7
    list.pop_back(); // remove 6

    EXPECT_EQ(list.getSize(), 5);

    int expected[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), expected[i]);
}