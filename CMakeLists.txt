cmake_minimum_required(VERSION 3.16)

project(DS_Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(include)
include_directories(src)
add_executable(main
    main.cpp
)

# Google Test Setup

enable_testing()

find_package(GTest REQUIRED)


add_executable(DynamicArrayTesting

    testing/DynamicArrayTesting/DynamicArrayInsert.cpp
    testing/DynamicArrayTesting/DynamicArrayConstructor.cpp
    testing/DynamicArrayTesting/DynamicArrayDestructor.cpp
    testing/DynamicArrayTesting/DynamicArrayPushBack.cpp
    testing/DynamicArrayTesting/DynamicArrayPopBack.cpp
    testing/DynamicArrayTesting/DynamicArrayDelete.cpp
    testing/DynamicArrayTesting/DynamicArrayGet.cpp
    testing/DynamicArrayTesting/DynamicArrayBracket.cpp
    testing/DynamicArrayTesting/DynamicArrayCopy.cpp
    testing/DynamicArrayTesting/DynamicArrayCopyAssignment.cpp
    testing/DynamicArrayTesting/DynamicArrayGetSize.cpp
    testing/DynamicArrayTesting/DynamicArrayGetCapacity.cpp
    testing/DynamicArrayTesting/DynamicArrayEmpty.cpp
    testing/DynamicArrayTesting/DynamicArrayFull.cpp
    testing/DynamicArrayTesting/DynamicArrayPrint.cpp
)


target_link_libraries(DynamicArrayTesting

    GTest::gtest
    GTest::gtest_main

)


include(GoogleTest)

gtest_discover_tests(DynamicArrayTesting)