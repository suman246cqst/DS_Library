#include <gtest/gtest.h>
#include <string>
#include "linkedList.h"

using namespace std;

/*------------------------------------------------------------
    Pop From Different Sized Lists
-------------------------------------------------------------*/

TEST(LinkedListPopFrontTest, PopFromDifferentSizedLists)
{
    // Single element
    {
        LinkedList<int> list;

        list.push_back(10);

        list.pop_front();

        EXPECT_EQ(list.getSize(), 0);
        EXPECT_EQ(list.getHead(), nullptr);
    }

    // Two elements
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);

        list.pop_front();

        EXPECT_EQ(list.getSize(), 1);
        EXPECT_EQ(list.get(0), 20);
    }

    // Multiple elements
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.push_back(40);

        list.pop_front();

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), 20);
        EXPECT_EQ(list.get(1), 30);
        EXPECT_EQ(list.get(2), 40);
    }
}

/*------------------------------------------------------------
    Pop Until Empty
-------------------------------------------------------------*/

TEST(LinkedListPopFrontTest, PopUntilEmpty)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    while (list.getSize() > 0)
        list.pop_front();

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
}

/*------------------------------------------------------------
    Underflow
-------------------------------------------------------------*/

TEST(LinkedListPopFrontTest, EmptyListThrowsException)
{
    LinkedList<int> list;

    EXPECT_THROW(list.pop_front(), underflow_error);
}



/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListPopFrontTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    list.pop_front();

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0), "Banana");
    EXPECT_EQ(list.get(1), "Cherry");
}

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
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListPopFrontTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    list.pop_front();

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0).value, 20);
    EXPECT_EQ(list.get(1).value, 30);
}

/*------------------------------------------------------------
    Large Number Of Elements
-------------------------------------------------------------*/

TEST(LinkedListPopFrontTest, HandlesLargeNumberOfElements)
{
    LinkedList<int> list;

    const int totalElements = 1000;

    for (int i = 0; i < totalElements; i++)
        list.push_back(i);

    for (int i = 0; i < totalElements; i++)
    {
        EXPECT_EQ(list.get(0), i);
        list.pop_front();
    }

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
}

/*------------------------------------------------------------
    Consecutive Pop Operations
-------------------------------------------------------------*/

TEST(LinkedListPopFrontTest, ConsecutivePopOperationsMaintainIntegrity)
{
    LinkedList<int> list;

    for (int i = 1; i <= 8; i++)
        list.push_back(i);

    list.pop_front(); // remove 1
    list.pop_front(); // remove 2
    list.pop_front(); // remove 3

    EXPECT_EQ(list.getSize(), 5);

    int expected[] = {4, 5, 6, 7, 8};

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), expected[i]);
}