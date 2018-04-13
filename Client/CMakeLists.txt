# CMakeList.txt : CMake project for Client, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# TODO: Add tests and install targets if needed.

if(WIN32)
	set(BOOST_ROOT E:/boost_1_66_0)
	set(BOOST_USE_STATIC_LIBS OFF)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME OFF)

	include_directories(${BOOST_ROOT})
    link_directories(${BOOST_ROOT}/stage/lib) # add this before add_executable()
endif()

# Add source to this project's executable.
add_executable (Client "main/Client.cpp")


if(NOT MSVC)
    find_package(Boost REQUIRED COMPONENTS date_time filesystem wserialization system serialization thread regex)

    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        target_link_libraries(your_exec ${Boost_LIBRARIES})
    endif()
endif()