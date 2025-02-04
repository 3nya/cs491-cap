cmake_minimum_required(VERSION 3.30)
project(cs491)

set(CMAKE_CXX_STANDARD 20)

add_executable(cs491
        "1-27 stl hw/stl_hw1.cpp"
        "1-27 stl hw/stl_hw2.cpp"
        "1-27 stl hw/stl_hw3.cpp"
        classwork/cw129A.cpp
        "1-29 complete search hw/a.cpp"
        "1-29 complete search hw/b.cpp"
        classwork/cw131A.cpp
        "1-31 divide and conquer/a.cpp"
        "1-31 divide and conquer/b.cpp"
        classwork/cw203A.cpp)
