cmake_minimum_required(VERSION 3.25)
project(object_list_processing_application)

set(CMAKE_CXX_STANDARD 17)

add_executable(object_list_processing_application
        readData.h
        groupBy.h
        groupByType.h
        groupByDistance.h
        groupByName.h
        groupByTime.h
        writeData.h
        groupByType.cpp
        groupByDistance.cpp
        groupByName.cpp
        groupByTime.cpp
        writeData.cpp
        readData.cpp
        main.cpp)
