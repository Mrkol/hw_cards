cmake_minimum_required(VERSION 3.5)

project(cards CXX)

option(DEBUG "Build with debug flags" OFF)
option(WITH_TESTS "Build with tests and run them" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(DEBUG)
	set(CMAKE_BUILD_TYPE Debug)
else(DEBUG)
	set(CMAKE_BUILD_TYPE Release)
endif(DEBUG)
