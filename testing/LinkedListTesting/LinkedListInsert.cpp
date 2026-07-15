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
    Insert At Different Positions
-------------------------------------------------------------*/

TEST(LinkedListInsertAtIndexTest, InsertAtDifferentPositions)
{
    // Insert into empty list
    {
        LinkedList<int> list;

        list.insertAtIndex(0, 10);

        EXPECT_EQ(list.getSize(), 1);
        EXPECT_EQ(list.get(0), 10);
    }

    // Insert at beginning
    {
        LinkedList<int> list;

        list.push_back(20);
        list.push_back(30);

        list.insertAtIndex(0, 10);

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 20);
        EXPECT_EQ(list.get(2), 30);
    }

    // Insert in middle
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(30);

        list.insertAtIndex(1, 20);

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 20);
        EXPECT_EQ(list.get(2), 30);
    }

    // Insert at end
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);

        list.insertAtIndex(2, 30);

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), 10);
        EXPECT_EQ(list.get(1), 20);
        EXPECT_EQ(list.get(2), 30);
    }
}



/*------------------------------------------------------------
    Invalid Indices
-------------------------------------------------------------*/

TEST(LinkedListInsertAtIndexTest, InvalidIndicesThrowExceptions)
{
    LinkedList<int> list;

    EXPECT_THROW(list.insertAtIndex(-1, 10), out_of_range);
    EXPECT_THROW(list.insertAtIndex(1, 10), out_of_range);

    list.push_back(10);
    list.push_back(20);

    EXPECT_THROW(list.insertAtIndex(-5, 100), out_of_range);
    EXPECT_THROW(list.insertAtIndex(3, 100), out_of_range);
    EXPECT_THROW(list.insertAtIndex(100, 100), out_of_range);
}



/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListInsertAtIndexTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Cherry");

    list.insertAtIndex(1, "Banana");

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0), "Apple");
    EXPECT_EQ(list.get(1), "Banana");
    EXPECT_EQ(list.get(2), "Cherry");
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListInsertAtIndexTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(30));

    list.insertAtIndex(1, TestObject(20));

    EXPECT_EQ(list.getSize(), 3);

    EXPECT_EQ(list.get(0).value, 10);
    EXPECT_EQ(list.get(1).value, 20);
    EXPECT_EQ(list.get(2).value, 30);
}

/*------------------------------------------------------------
    Large Number Of Insertions
-------------------------------------------------------------*/

TEST(LinkedListInsertAtIndexTest, HandlesLargeNumberOfInsertions)
{
    LinkedList<int> list;

    for (int i = 0; i < 1000; i++)
        list.insertAtIndex(i, i);

    EXPECT_EQ(list.getSize(), 1000);

    for (int i = 0; i < 1000; i++)
        EXPECT_EQ(list.get(i), i);
}