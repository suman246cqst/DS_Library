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
    Search Existing Elements
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, SearchExistingElements)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    EXPECT_EQ(list.search(10), 0);
    EXPECT_EQ(list.search(30), 2);
    EXPECT_EQ(list.search(50), 4);
}

/*------------------------------------------------------------
    Search Missing Elements
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, SearchMissingElements)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.search(5), -1);
    EXPECT_EQ(list.search(100), -1);
    EXPECT_EQ(list.search(-20), -1);
}

/*------------------------------------------------------------
    Empty List Throws Exception
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, EmptyListThrowsException)
{
    LinkedList<int> list;

    EXPECT_THROW(list.search(10), underflow_error);
}

/*------------------------------------------------------------
    Duplicate Values
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, ReturnsFirstOccurrenceForDuplicateValues)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(20);
    list.push_back(30);
    list.push_back(20);

    EXPECT_EQ(list.search(20), 1);
}


/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    EXPECT_EQ(list.search("Apple"), 0);
    EXPECT_EQ(list.search("Banana"), 1);
    EXPECT_EQ(list.search("Cherry"), 2);
    EXPECT_EQ(list.search("Orange"), -1);
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    EXPECT_EQ(list.search(TestObject(10)), 0);
    EXPECT_EQ(list.search(TestObject(20)), 1);
    EXPECT_EQ(list.search(TestObject(30)), 2);
    EXPECT_EQ(list.search(TestObject(100)), -1);
}

/*------------------------------------------------------------
    Large Number Of Elements
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, HandlesLargeNumberOfElements)
{
    LinkedList<int> list;

    const int totalElements = 1000;

    for (int i = 0; i < totalElements; i++)
        list.push_back(i);

    EXPECT_EQ(list.search(0), 0);
    EXPECT_EQ(list.search(500), 500);
    EXPECT_EQ(list.search(999), 999);
    EXPECT_EQ(list.search(1000), -1);
}

/*------------------------------------------------------------
    Search Does Not Modify List
-------------------------------------------------------------*/

TEST(LinkedListSearchTest, SearchDoesNotModifyList)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    list.search(3);
    list.search(5);
    list.search(100);

    EXPECT_EQ(list.getSize(), 5);

    int expected[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), expected[i]);
}