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

find_package(Doxygen REQUIRED)


file(GLOB_RECURSE SOURCES . sources/*.cpp)


add_library(cards STATIC ${SOURCES})
target_include_directories(cards PUBLIC "./include")

add_custom_target(documentation
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/cards.conf
	)


add_dependencies(cards documentation)

if(WITH_TESTS)
	enable_testing()
	find_package(GTest REQUIRED)

	file(GLOB_RECURSE TESTS . tests/*.cpp)

	add_executable(tests ${TESTS}) 

	target_include_directories(tests PUBLIC "./include")

	target_link_libraries(tests PUBLIC cards GTest::GTest)

	add_test(AllTests tests)
endif(WITH_TESTS)