#include <gtest/gtest.h>
#include <string>
#include "linkedList.h"

using namespace std;

/*------------------------------------------------------------
    Empty List
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, EmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.getSize(), 0);
}

/*------------------------------------------------------------
    Size After Push Front
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, SizeAfterPushFront)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
    {
        list.push_front(i);
        EXPECT_EQ(list.getSize(), i);
    }
}

/*------------------------------------------------------------
    Size After Push Back
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, SizeAfterPushBack)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
    {
        list.push_back(i);
        EXPECT_EQ(list.getSize(), i);
    }
}

/*------------------------------------------------------------
    Size After Pop Front
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, SizeAfterPopFront)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    for (int i = 4; i >= 0; i--)
    {
        list.pop_front();
        EXPECT_EQ(list.getSize(), i);
    }
}

/*------------------------------------------------------------
    Size After Pop Back
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, SizeAfterPopBack)
{
    LinkedList<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i);

    for (int i = 4; i >= 0; i--)
    {
        list.pop_back();
        EXPECT_EQ(list.getSize(), i);
    }
}

/*------------------------------------------------------------
    Size After Insert And Delete
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, SizeAfterInsertAndDelete)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);

    EXPECT_EQ(list.getSize(), 2);

    list.insertAtIndex(1, 15);
    EXPECT_EQ(list.getSize(), 3);

    list.deleteAtIndex(1);
    EXPECT_EQ(list.getSize(), 2);

    list.insertAtIndex(0, 5);
    EXPECT_EQ(list.getSize(), 3);

    list.deleteAtIndex(2);
    EXPECT_EQ(list.getSize(), 2);
}

/*------------------------------------------------------------
    Size After Remove
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, SizeAfterRemove)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.getSize(), 3);

    int value = 20;
    list.remove(value);

    EXPECT_EQ(list.getSize(), 2);

    value = 10;
    list.remove(value);

    EXPECT_EQ(list.getSize(), 1);

    value = 30;
    list.remove(value);

    EXPECT_EQ(list.getSize(), 0);
}

/*------------------------------------------------------------
    Size After Mixed Operations
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, SizeAfterMixedOperations)
{
    LinkedList<int> list;

    list.push_front(10);
    list.push_back(20);
    list.push_front(5);
    list.insertAtIndex(2, 15);

    EXPECT_EQ(list.getSize(), 4);

    list.pop_front();
    EXPECT_EQ(list.getSize(), 3);

    list.pop_back();
    EXPECT_EQ(list.getSize(), 2);

    list.deleteAtIndex(0);
    EXPECT_EQ(list.getSize(), 1);

    int value = 15;
    list.remove(value);

    EXPECT_EQ(list.getSize(), 0);
}

/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListGetSizeTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");

    EXPECT_EQ(list.getSize(), 2);

    list.pop_front();

    EXPECT_EQ(list.getSize(), 1);
}