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
    Copy Empty List
-------------------------------------------------------------*/

TEST(LinkedListCopyConstructorTest, CopyEmptyList)
{
    LinkedList<int> original;

    LinkedList<int> copy(original);

    EXPECT_EQ(copy.getSize(), 0);
    EXPECT_EQ(copy.getHead(), nullptr);
}

/*------------------------------------------------------------
    Copy Single Element List
-------------------------------------------------------------*/

TEST(LinkedListCopyConstructorTest, CopySingleElementList)
{
    LinkedList<int> original;

    original.push_back(10);

    LinkedList<int> copy(original);

    EXPECT_EQ(copy.getSize(), 1);
    EXPECT_EQ(copy.get(0), 10);
}

/*------------------------------------------------------------
    Copy Multiple Elements
-------------------------------------------------------------*/

TEST(LinkedListCopyConstructorTest, CopyMultipleElements)
{
    LinkedList<int> original;

    for (int i = 1; i <= 10; i++)
        original.push_back(i);

    LinkedList<int> copy(original);

    EXPECT_EQ(copy.getSize(), original.getSize());

    for (int i = 0; i < original.getSize(); i++)
        EXPECT_EQ(copy.get(i), original.get(i));
}

/*------------------------------------------------------------
    Deep Copy Independence
-------------------------------------------------------------*/

TEST(LinkedListCopyConstructorTest, DeepCopyCreatesIndependentList)
{
    LinkedList<int> original;

    original.push_back(10);
    original.push_back(20);
    original.push_back(30);

    LinkedList<int> copy(original);

    original.pop_back();
    original.push_back(40);

    EXPECT_EQ(original.getSize(), 3);
    EXPECT_EQ(copy.getSize(), 3);

    EXPECT_EQ(copy.get(0), 10);
    EXPECT_EQ(copy.get(1), 20);
    EXPECT_EQ(copy.get(2), 30);

    EXPECT_EQ(original.get(2), 40);
}

/*------------------------------------------------------------
    Copy Survives Source Destruction
-------------------------------------------------------------*/

TEST(LinkedListCopyConstructorTest, CopyRemainsValidAfterSourceIsDestroyed)
{
    LinkedList<int> copy;

    {
        LinkedList<int> original;

        original.push_back(1);
        original.push_back(2);
        original.push_back(3);

        copy = original;
    }

    EXPECT_EQ(copy.getSize(), 3);

    EXPECT_EQ(copy.get(0), 1);
    EXPECT_EQ(copy.get(1), 2);
    EXPECT_EQ(copy.get(2), 3);
}

/*------------------------------------------------------------
    Supports String Type
-------------------------------------------------------------*/

TEST(LinkedListCopyConstructorTest, WorksWithString)
{
    LinkedList<string> original;

    original.push_back("Apple");
    original.push_back("Banana");
    original.push_back("Cherry");

    LinkedList<string> copy(original);

    EXPECT_EQ(copy.getSize(), 3);

    EXPECT_EQ(copy.get(0), "Apple");
    EXPECT_EQ(copy.get(1), "Banana");
    EXPECT_EQ(copy.get(2), "Cherry");
}

/*------------------------------------------------------------
    Supports Custom Object
-------------------------------------------------------------*/

TEST(LinkedListCopyConstructorTest, WorksWithCustomObject)
{
    LinkedList<TestObject> original;

    original.push_back(TestObject(10));
    original.push_back(TestObject(20));
    original.push_back(TestObject(30));

    LinkedList<TestObject> copy(original);

    EXPECT_EQ(copy.getSize(), 3);

    EXPECT_EQ(copy.get(0).value, 10);
    EXPECT_EQ(copy.get(1).value, 20);
    EXPECT_EQ(copy.get(2).value, 30);
}