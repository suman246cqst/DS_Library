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
    Assign Non-Empty List To Empty List
-------------------------------------------------------------*/

TEST(LinkedListCopyAssignmentTest, AssignNonEmptyToEmpty)
{
    LinkedList<int> first;

    for (int i = 1; i <= 5; i++)
        first.push_back(i);

    LinkedList<int> second;

    second = first;

    EXPECT_EQ(second.getSize(), first.getSize());

    for (int i = 0; i < first.getSize(); i++)
        EXPECT_EQ(second.get(i), first.get(i));
}

/*------------------------------------------------------------
    Assign Empty List To Non-Empty List
-------------------------------------------------------------*/

TEST(LinkedListCopyAssignmentTest, AssignEmptyToNonEmpty)
{
    LinkedList<int> first;

    LinkedList<int> second;

    second.push_back(10);
    second.push_back(20);
    second.push_back(30);

    second = first;

    EXPECT_EQ(second.getSize(), 0);
    EXPECT_EQ(second.getHead(), nullptr);
}



/*------------------------------------------------------------
    Deep Copy After Assignment
-------------------------------------------------------------*/

TEST(LinkedListCopyAssignmentTest, PerformsDeepCopy)
{
    LinkedList<int> first;

    first.push_back(10);
    first.push_back(20);
    first.push_back(30);

    LinkedList<int> second;

    second = first;

    first.pop_back();
    first.push_back(40);

    EXPECT_EQ(second.getSize(), 3);

    EXPECT_EQ(second.get(0), 10);
    EXPECT_EQ(second.get(1), 20);
    EXPECT_EQ(second.get(2), 30);

    EXPECT_EQ(first.get(2), 40);
}

/*------------------------------------------------------------
    Self Assignment
-------------------------------------------------------------*/

TEST(LinkedListCopyAssignmentTest, SelfAssignment)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    list = list;

    EXPECT_EQ(list.getSize(), 5);

    for (int i = 0; i < 5; i++)
        EXPECT_EQ(list.get(i), i + 1);
}

/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListCopyAssignmentTest, WorksWithString)
{
    LinkedList<string> first;

    first.push_back("Apple");
    first.push_back("Banana");
    first.push_back("Cherry");

    LinkedList<string> second;

    second = first;

    EXPECT_EQ(second.getSize(), 3);

    EXPECT_EQ(second.get(0), "Apple");
    EXPECT_EQ(second.get(1), "Banana");
    EXPECT_EQ(second.get(2), "Cherry");
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListCopyAssignmentTest, WorksWithCustomObject)
{
    LinkedList<TestObject> first;

    first.push_back(TestObject(10));
    first.push_back(TestObject(20));
    first.push_back(TestObject(30));

    LinkedList<TestObject> second;

    second = first;

    EXPECT_EQ(second.getSize(), 3);

    EXPECT_EQ(second.get(0).value, 10);
    EXPECT_EQ(second.get(1).value, 20);
    EXPECT_EQ(second.get(2).value, 30);
}