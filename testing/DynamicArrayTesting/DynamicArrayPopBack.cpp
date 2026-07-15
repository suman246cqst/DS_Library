#include <gtest/gtest.h>
#include <string>
#include "dynamicArray.h"

using namespace std;

/*------------------------------------------------------------
    pop_back() : Remove Single Element
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, PopSingleElement)
{
    DynamicArray<int> arr;

    arr.push_back(10);

    arr.pop_back();

    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.getCapacity(), 1);
}

/*------------------------------------------------------------
    pop_back() : Remove Last Element
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, PopLastElementFromMultipleElements)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);

    arr.pop_back();

    EXPECT_EQ(arr.getSize(), 2);

    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}


/*------------------------------------------------------------
    pop_back() : Pop Until Empty
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, PopUntilEmpty)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 10; i++)
        arr.push_back(i);

    while (!arr.isEmpty())
    {
        arr.pop_back();
    }

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.getSize(), 0);
}

/*------------------------------------------------------------
    pop_back() : Empty Array
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, PopFromEmptyArrayThrows)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.pop_back(), underflow_error);
}



/*------------------------------------------------------------
    pop_back() : After Resize
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, PopAfterMultipleResizes)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 100; i++)
        arr.push_back(i);

    for (int i = 0; i < 50; i++)
        arr.pop_back();

    EXPECT_EQ(arr.getSize(), 50);

    for (int i = 0; i < 50; i++)
        EXPECT_EQ(arr[i], i);
}

/*------------------------------------------------------------
    pop_back() : String Type
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, WorksWithString)
{
    DynamicArray<string> arr;

    arr.push_back("Apple");
    arr.push_back("Banana");
    arr.push_back("Cherry");

    arr.pop_back();

    EXPECT_EQ(arr.getSize(), 2);

    EXPECT_EQ(arr[0], "Apple");
    EXPECT_EQ(arr[1], "Banana");
}

/*------------------------------------------------------------
    pop_back() : Character Type
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, WorksWithCharacter)
{
    DynamicArray<char> arr;

    arr.push_back('A');
    arr.push_back('B');
    arr.push_back('C');

    arr.pop_back();

    EXPECT_EQ(arr.getSize(), 2);

    EXPECT_EQ(arr[0], 'A');
    EXPECT_EQ(arr[1], 'B');
}

/*------------------------------------------------------------
    pop_back() : Pop Everything
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, PopAllElementsAfterLargeInsertion)
{
    DynamicArray<int> arr;

    for (int i = 0; i < 200; i++)
        arr.push_back(i);

    int capacity = arr.getCapacity();

    while (!arr.isEmpty())
        arr.pop_back();

    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());

    // Capacity should not shrink
    EXPECT_EQ(arr.getCapacity(), capacity);
}

/*------------------------------------------------------------
    pop_back() : Alternate Push And Pop
-------------------------------------------------------------*/

TEST(DynamicArrayPopBackTest, AlternatePushAndPop)
{
    DynamicArray<int> arr;

    arr.push_back(10);
    arr.pop_back();

    EXPECT_TRUE(arr.isEmpty());

    arr.push_back(20);

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr[0], 20);

    arr.pop_back();

    EXPECT_TRUE(arr.isEmpty());
}

