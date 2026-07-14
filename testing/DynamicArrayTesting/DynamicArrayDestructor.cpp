#include <gtest/gtest.h>
#include "dynamicArray.h"

// Helper class to track object lifetime
class DestructorTracker
{
public:

    static int aliveObjects;

    DestructorTracker()
    {
        aliveObjects++;
    }

    DestructorTracker(const DestructorTracker&)
    {
        aliveObjects++;
    }

    ~DestructorTracker()
    {
        aliveObjects--;
    }
};

int DestructorTracker::aliveObjects = 0;


// Test 1: Destructor works for empty DynamicArray
TEST(DynamicArrayDestructorTest, EmptyArrayDestructor)
{
    DestructorTracker::aliveObjects = 0;

    {
        DynamicArray<DestructorTracker> arr;
    }

    EXPECT_EQ(DestructorTracker::aliveObjects, 0);
}


// Test 2: Destructor destroys every stored object
TEST(DynamicArrayDestructorTest, CallsDestructorForEveryElement)
{
    DestructorTracker::aliveObjects = 0;

    {
        DynamicArray<DestructorTracker> arr;

        DestructorTracker obj;

        arr.push_back(obj);
        arr.push_back(obj);
        arr.push_back(obj);

        EXPECT_EQ(arr.getSize(), 3);

        // One local object + three objects inside DynamicArray
        EXPECT_EQ(DestructorTracker::aliveObjects, 4);
    }

    // Every constructed object must have been destroyed.
    EXPECT_EQ(DestructorTracker::aliveObjects, 0);
}


// Test 3: Destructor handles large number of elements
TEST(DynamicArrayDestructorTest, HandlesLargeNumberOfElements)
{
    {
        DynamicArray<int> arr;

        for (int i = 0; i < 10000; i++)
        {
            arr.push_back(i);
        }

        EXPECT_EQ(arr.getSize(), 10000);
    }

    SUCCEED();
}


// Test 4: Destructor works correctly after copy constructor
TEST(DynamicArrayDestructorTest, DestructorAfterCopyConstructor)
{
    {
        DynamicArray<int> arr1;

        arr1.push_back(10);
        arr1.push_back(20);

        {
            DynamicArray<int> arr2(arr1);

            EXPECT_EQ(arr2.getSize(), 2);
            EXPECT_EQ(arr2[0], 10);
            EXPECT_EQ(arr2[1], 20);
        }

        EXPECT_EQ(arr1.getSize(), 2);
        EXPECT_EQ(arr1[0], 10);
        EXPECT_EQ(arr1[1], 20);
    }

    SUCCEED();
}


// Test 5: Destructor works correctly after assignment operator
TEST(DynamicArrayDestructorTest, DestructorAfterAssignment)
{
    {
        DynamicArray<int> arr1;

        arr1.push_back(100);

        DynamicArray<int> arr2;

        arr2 = arr1;

        EXPECT_EQ(arr2.getSize(), 1);
        EXPECT_EQ(arr2[0], 100);
    }

    SUCCEED();
}


// Test 6: Multiple DynamicArray objects destroy independently
TEST(DynamicArrayDestructorTest, MultipleObjectsDestroySafely)
{
    {
        DynamicArray<int> arr1;
        DynamicArray<int> arr2;
        DynamicArray<int> arr3;

        arr1.push_back(1);
        arr2.push_back(2);
        arr3.push_back(3);

        EXPECT_EQ(arr1[0], 1);
        EXPECT_EQ(arr2[0], 2);
        EXPECT_EQ(arr3[0], 3);
    }

    SUCCEED();
}