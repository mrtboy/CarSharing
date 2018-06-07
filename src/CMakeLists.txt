cmake_minimum_required (VERSION 3.8)

project ("CarSharing")

message(STATUS "Setting MSVC flags")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

if(WIN32)

	set(BOOST_ROOT E:/boost_1_66_0)
	set(Boost_INCLUDE_DIRS E:/boost_1_66_0/stage/lib)

	set(BOOST_USE_STATIC_LIBS OFF)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME OFF)

	include_directories(${Boost_INCLUDE_DIRS})
	include_directories(${BOOST_ROOT})
    link_directories(${BOOST_ROOT}/stage/lib) # add this before add_executable()
endif()

find_package(BOOST REQUIRED COMPONENTS date_time filesystem wserialization system serialization thread regex unit_test_framework)
find_package(Threads REQUIRED)

# Include sub-projects.
add_subdirectory (lib)
add_subdirectory (Server)
add_subdirectory (Client)
add_subdirectory (tests)



