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