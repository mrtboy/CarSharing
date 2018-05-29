# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CarSharing")

message(STATUS "Setting MSVC flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../bin")

if(WIN32)
	set(BOOST_ROOT C:/boost_1_66_0)
	set(Header C:/boost_1_66_0/stage/lib)

	if(NOT EXISTS BOOST_ROOT AND NOT EXISTS Header)
		set(BOOST_ROOT E:/boost_1_66_0)
		set(Header E:/boost_1_66_0/stage/lib)
	endif()

	include_directories(${Header})
	include_directories(${BOOST_ROOT})
    link_directories(${BOOST_ROOT}/stage/lib) # add this before add_executable()

	set(BOOST_USE_STATIC_LIBS OFF)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME OFF)
endif()

if(NOT MSVC)
    find_package(Boost REQUIRED COMPONENTS date_time filesystem wserialization system serialization thread regex)

    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        target_link_libraries(your_exec ${Boost_LIBRARIES})
    endif()
endif()

# Include sub-projects.
add_subdirectory (lib)
add_subdirectory (Server)
add_subdirectory (Client)

#Class Dependencies 

add_dependencies(ManageCar Car)
add_dependencies(ManageUser User)
add_dependencies(Server ManageUser)
add_dependencies(Client MainMenu)