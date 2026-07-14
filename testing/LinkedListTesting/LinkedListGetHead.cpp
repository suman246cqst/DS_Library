#include <gtest/gtest.h>
#include <string>
#include "linkedList.h"

using namespace std;

/*------------------------------------------------------------
    Empty List
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, EmptyListReturnsNullptr)
{
    LinkedList<int> list;

    EXPECT_EQ(list.getHead(), nullptr);
}

/*------------------------------------------------------------
    Single Element List
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, SingleElementList)
{
    LinkedList<int> list;

    list.push_back(10);

    ASSERT_NE(list.getHead(), nullptr);

    EXPECT_EQ(list.getHead()->data, 10);
    EXPECT_EQ(list.getHead()->next, nullptr);
}

/*------------------------------------------------------------
    Push Front Updates Head
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, PushFrontUpdatesHead)
{
    LinkedList<int> list;

    list.push_front(10);
    EXPECT_EQ(list.getHead()->data, 10);

    list.push_front(20);
    EXPECT_EQ(list.getHead()->data, 20);

    list.push_front(30);
    EXPECT_EQ(list.getHead()->data, 30);
}

/*------------------------------------------------------------
    Push Back Does Not Change Head
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, PushBackDoesNotChangeHead)
{
    LinkedList<int> list;

    list.push_back(10);
    Node<int>* head = list.getHead();

    list.push_back(20);
    list.push_back(30);

    EXPECT_EQ(list.getHead(), head);
    EXPECT_EQ(list.getHead()->data, 10);
}

/*------------------------------------------------------------
    Pop Front Updates Head
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, PopFrontUpdatesHead)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.pop_front();

    ASSERT_NE(list.getHead(), nullptr);
    EXPECT_EQ(list.getHead()->data, 20);

    list.pop_front();

    ASSERT_NE(list.getHead(), nullptr);
    EXPECT_EQ(list.getHead()->data, 30);

    list.pop_front();

    EXPECT_EQ(list.getHead(), nullptr);
}

/*------------------------------------------------------------
    Delete First Node Updates Head
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, DeleteFirstNodeUpdatesHead)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.deleteAtIndex(0);

    ASSERT_NE(list.getHead(), nullptr);
    EXPECT_EQ(list.getHead()->data, 20);
}

/*------------------------------------------------------------
    Remove First Element Updates Head
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, RemoveFirstElementUpdatesHead)
{
    LinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    int value = 10;
    list.remove(value);

    ASSERT_NE(list.getHead(), nullptr);
    EXPECT_EQ(list.getHead()->data, 20);
}

/*------------------------------------------------------------
    Copy Constructor Creates Independent Head
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, CopyConstructorCreatesIndependentHead)
{
    LinkedList<int> original;

    original.push_back(10);
    original.push_back(20);

    LinkedList<int> copy(original);

    EXPECT_NE(copy.getHead(), original.getHead());

    EXPECT_EQ(copy.getHead()->data, 10);
    EXPECT_EQ(copy.getHead()->next->data, 20);
}

/*------------------------------------------------------------
    Copy Assignment Creates Independent Head
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, CopyAssignmentCreatesIndependentHead)
{
    LinkedList<int> original;

    original.push_back(10);
    original.push_back(20);
    original.push_back(30);

    LinkedList<int> copy;

    copy = original;

    EXPECT_NE(copy.getHead(), original.getHead());

    EXPECT_EQ(copy.getHead()->data, 10);
    EXPECT_EQ(copy.getHead()->next->data, 20);
    EXPECT_EQ(copy.getHead()->next->next->data, 30);
}

/*------------------------------------------------------------
    Works With String
-------------------------------------------------------------*/

TEST(LinkedListHeadTest, WorksWithString)
{
    LinkedList<string> list;

    list.push_back("Apple");
    list.push_back("Banana");

    ASSERT_NE(list.getHead(), nullptr);

    EXPECT_EQ(list.getHead()->data, "Apple");
}