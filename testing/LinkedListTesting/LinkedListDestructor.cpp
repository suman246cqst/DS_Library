#include <gtest/gtest.h>
#include <string>
#include "linkedList.h"

using namespace std;

/*------------------------------------------------------------
    Destructor On Empty List
-------------------------------------------------------------*/

TEST(LinkedListDestructorTest, DestroyEmptyList)
{
    LinkedList<int> list;

    EXPECT_EQ(list.getSize(), 0);
}

/*------------------------------------------------------------
    Destructor After Single Node
-------------------------------------------------------------*/

TEST(LinkedListDestructorTest, DestroySingleNodeList)
{
    {
        LinkedList<int> list;

        list.push_back(10);

        EXPECT_EQ(list.getSize(), 1);
        EXPECT_EQ(list.get(0), 10);
    }

    SUCCEED();
}

/*------------------------------------------------------------
    Destructor After Multiple Nodes
-------------------------------------------------------------*/

TEST(LinkedListDestructorTest, DestroyMultipleNodeList)
{
    {
        LinkedList<int> list;

        for (int i = 1; i <= 100; i++)
            list.push_back(i);

        EXPECT_EQ(list.getSize(), 100);

        EXPECT_EQ(list.get(0), 1);
        EXPECT_EQ(list.get(99), 100);
    }

    SUCCEED();
}

/*------------------------------------------------------------
    Destructor After Mixed Operations
-------------------------------------------------------------*/

TEST(LinkedListDestructorTest, DestroyListAfterMixedOperations)
{
    {
        LinkedList<int> list;

        list.push_back(10);
        list.push_back(20);
        list.push_front(5);
        list.insertAtIndex(2, 15);

        list.pop_front();
        list.pop_back();
        list.deleteAtIndex(1);

        EXPECT_EQ(list.getSize(), 1);
        EXPECT_EQ(list.get(0), 10);
    }

    SUCCEED();
}

/*------------------------------------------------------------
    Destructor On Large List
-------------------------------------------------------------*/

TEST(LinkedListDestructorTest, DestroyLargeList)
{
    {
        LinkedList<int> list;

        const int totalElements = 10000;

        for (int i = 0; i < totalElements; i++)
            list.push_back(i);

        EXPECT_EQ(list.getSize(), totalElements);

        EXPECT_EQ(list.get(0), 0);
        EXPECT_EQ(list.get(totalElements - 1), totalElements - 1);
    }

    SUCCEED();
}

/*------------------------------------------------------------
    Destructor Supports String Type
-------------------------------------------------------------*/

TEST(LinkedListDestructorTest, DestroyStringList)
{
    {
        LinkedList<string> list;

        list.push_back("Apple");
        list.push_back("Banana");
        list.push_back("Cherry");

        EXPECT_EQ(list.getSize(), 3);

        EXPECT_EQ(list.get(0), "Apple");
        EXPECT_EQ(list.get(1), "Banana");
        EXPECT_EQ(list.get(2), "Cherry");
    }

    SUCCEED();
}