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
    Delete At Different Positions
-------------------------------------------------------------*/

TEST(LinkedListDeleteAtIndexTest, DeleteAtDifferentPositions)
{
    // Delete first
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        list.deleteAtIndex(0);

        EXPECT_EQ(list.getSize(), 2);
        EXPECT_EQ(list.get(0), 20);
        EXPECT_EQ(list.get(1), 30);
    }

    // Delete middle
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.push_back(40);

        list.deleteAtIndex(2);

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 20);
        EXPECT_EQ(list.get(2), 40);
    }

    // Delete last
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        list.deleteAtIndex(2);

        EXPECT_EQ(list.getSize(), 2);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 20);
    }
}

/*------------------------------------------------------------
    Delete Until Empty
-------------------------------------------------------------*/

TEST(LinkedListDeleteAtIndexTest, DeleteUntilEmpty)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    while (list.getSize() > 0)
        list.deleteAtIndex(0);

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
}


/*------------------------------------------------------------
    Invalid Indices
-------------------------------------------------------------*/

TEST(LinkedListDeleteAtIndexTest, InvalidIndicesThrowExceptions)
{
    LinkedList<int> list;

    EXPECT_THROW(list.deleteAtIndex(0), underflow_error);

    list.push_back(10);
    list.push_back(20);

    EXPECT_THROW(list.deleteAtIndex(-1), out_of_range);
    EXPECT_THROW(list.deleteAtIndex(2), out_of_range);
    EXPECT_THROW(list.deleteAtIndex(100), out_of_range);
}


/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListDeleteAtIndexTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    list.deleteAtIndex(1);

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0), "Apple");
    EXPECT_EQ(list.get(1), "Cherry");
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListDeleteAtIndexTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    list.deleteAtIndex(1);

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0).value, 10);
    EXPECT_EQ(list.get(1).value, 30);
}

/*------------------------------------------------------------
    Consecutive Deletions Maintain Integrity
-------------------------------------------------------------*/

TEST(LinkedListDeleteAtIndexTest, ConsecutiveDeletionsMaintainIntegrity)
{
    LinkedList<int> list;

    for (int i = 1; i <= 8; i++)
        list.push_back(i);

    list.deleteAtIndex(2); // remove 3
    list.deleteAtIndex(2); // remove 4
    list.deleteAtIndex(4); // remove 7

    EXPECT_EQ(list.getSize(), 5);

    int expected[] = {1, 2, 5, 6, 8};

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), expected[i]);
}