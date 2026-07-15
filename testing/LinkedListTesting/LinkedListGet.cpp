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
    Access Elements At Different Positions
-------------------------------------------------------------*/

TEST(LinkedListGetTest, AccessElementsAtDifferentPositions)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(2), 30);
    EXPECT_EQ(list.get(4), 50);
}

/*------------------------------------------------------------
    Access Every Element
-------------------------------------------------------------*/

TEST(LinkedListGetTest, AccessEveryElement)
{
    LinkedList<int> list;

    for (int i = 1; i <= 10; i++)
        list.push_back(i);

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), i + 1);
}

/*------------------------------------------------------------
    Empty List Throws Exception
-------------------------------------------------------------*/

TEST(LinkedListGetTest, EmptyListThrowsException)
{
    LinkedList<int> list;

    EXPECT_THROW(list.get(0), underflow_error);
}

/*------------------------------------------------------------
    Invalid Indices Throw Exceptions
-------------------------------------------------------------*/

TEST(LinkedListGetTest, InvalidIndicesThrowExceptions)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);

    EXPECT_THROW(list.get(-1), out_of_range);
    EXPECT_THROW(list.get(2), out_of_range);
    EXPECT_THROW(list.get(100), out_of_range);
}


/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListGetTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    EXPECT_EQ(list.get(0), "Apple");
    EXPECT_EQ(list.get(1), "Banana");
    EXPECT_EQ(list.get(2), "Cherry");
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListGetTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    EXPECT_EQ(list.get(0).value, 10);
    EXPECT_EQ(list.get(1).value, 20);
    EXPECT_EQ(list.get(2).value, 30);
}

/*------------------------------------------------------------
    Large Number Of Elements
-------------------------------------------------------------*/

TEST(LinkedListGetTest, HandlesLargeNumberOfElements)
{
    LinkedList<int> list;

    const int totalElements = 1000;

    for (int i = 0; i < totalElements; i++)
        list.push_back(i);

    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(499), 499);
    EXPECT_EQ(list.get(999), 999);
}

/*------------------------------------------------------------
    List Remains Unchanged After Access
-------------------------------------------------------------*/

TEST(LinkedListGetTest, AccessDoesNotModifyList)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    list.get(2);
    list.get(4);
    list.get(0);

    EXPECT_EQ(list.getSize(), 5);

    int expected[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), expected[i]);
}