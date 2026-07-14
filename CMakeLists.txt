cmake_minimum_required(VERSION 3.16)

project(DS_Library)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
include_directories(src)
add_executable(main
    main.cpp
)