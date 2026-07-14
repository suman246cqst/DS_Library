#include <gtest/gtest.h>
#include "linkedList.h"

using namespace std;


/*------------------------------------------------------------
    Default Constructor
-------------------------------------------------------------*/

TEST(LinkedListConstructorTest, DefaultConstructorInitialState)
{
    LinkedList<int> list;

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);
}


/*------------------------------------------------------------
    Can Insert After Construction
-------------------------------------------------------------*/

TEST(LinkedListConstructorTest, CanInsertAfterConstruction)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);

    EXPECT_EQ(list.getSize(), 2);

    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 20);
}


/*------------------------------------------------------------
    Multiple Empty Lists Are Independent
-------------------------------------------------------------*/

TEST(LinkedListConstructorTest, MultipleObjectsMaintainIndependentState)
{
    LinkedList<int> first;
    LinkedList<int> second;

    first.push_back(10);

    EXPECT_EQ(first.getSize(), 1);
    EXPECT_EQ(second.getSize(), 0);

    EXPECT_NE(first.getHead(), second.getHead());
}


/*------------------------------------------------------------
    Supports Different Data Types
-------------------------------------------------------------*/

TEST(LinkedListConstructorTest, SupportsStringType)
{
    LinkedList<string> list;

    EXPECT_EQ(list.getSize(), 0);
    EXPECT_EQ(list.getHead(), nullptr);

    list.push_back("Hello");

    EXPECT_EQ(list.get(0), "Hello");
}