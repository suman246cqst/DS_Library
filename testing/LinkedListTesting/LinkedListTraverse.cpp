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

    friend ostream& operator<<(ostream& os, const TestObject& obj)
    {
        os << obj.value;
        return os;
    }
};

/*------------------------------------------------------------
    Empty List
-------------------------------------------------------------*/

TEST(LinkedListTraverseTest, EmptyList)
{
    LinkedList<int> list;

    testing::internal::CaptureStdout();

    list.traverse();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "\n");
}

/*------------------------------------------------------------
    Single Element
-------------------------------------------------------------*/

TEST(LinkedListTraverseTest, SingleElement)
{
    LinkedList<int> list;

    list.push_back(10);

    testing::internal::CaptureStdout();

    list.traverse();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 \n");
}



/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListTraverseTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Cherry");

    testing::internal::CaptureStdout();

    list.traverse();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Apple Banana Cherry \n");
}

/*------------------------------------------------------------
    Works With Custom Object
-------------------------------------------------------------*/

TEST(LinkedListTraverseTest, WorksWithCustomObject)
{
    LinkedList<TestObject> list;

    list.push_back(TestObject(10));
    list.push_back(TestObject(20));
    list.push_back(TestObject(30));

    testing::internal::CaptureStdout();

    list.traverse();

    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 20 30 \n");
}

/*------------------------------------------------------------
    Large Number Of Elements
-------------------------------------------------------------*/

TEST(LinkedListTraverseTest, HandlesLargeNumberOfElements)
{
    LinkedList<int> list;

    for (int i = 1; i <= 100; i++)
        list.push_back(i);

    testing::internal::CaptureStdout();

    list.traverse();

    string output = testing::internal::GetCapturedStdout();

    string expected;

    for (int i = 1; i <= 100; i++)
        expected += to_string(i) + " ";

    expected += "\n";

    EXPECT_EQ(output, expected);
}

/*------------------------------------------------------------
    Traverse Does Not Modify List
-------------------------------------------------------------*/

TEST(LinkedListTraverseTest, TraverseDoesNotModifyList)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    testing::internal::CaptureStdout();

    list.traverse();

    testing::internal::GetCapturedStdout();

    EXPECT_EQ(list.getSize(), 5);

    int expected[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < list.getSize(); i++)
        EXPECT_EQ(list.get(i), expected[i]);
}