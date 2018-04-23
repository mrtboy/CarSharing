# CMakeList.txt : CMake project for Client, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /std:c++latest")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if(WIN32)
	set(BOOST_ROOT C:/boost_1_66_0)
	set(Header C:/boost_1_66_0/boost_1_66_0)

	if(NOT EXISTS BOOST_ROOT AND NOT EXISTS Header)
		set(BOOST_ROOT E:/boost_1_66_0)
		set(Header E:/boost_1_66_0/boost_1_66_0)
	endif()

	set(BOOST_USE_STATIC_LIBS OFF)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME OFF)

	include_directories(${Header})
	include_directories(${BOOST_ROOT})
    link_directories(${BOOST_ROOT}/stage/lib) # add this before add_executable()
endif()

#target_link_libraries(User MenuGenerator)
#add_library(CarController "CarController.h" "CarController.cpp")
	
# Add source to this project's executable.
add_executable (Client "main/Client.cpp" "main/Client.h")


#target_link_libraries(Client CarController)

if(NOT MSVC)
    find_package(Boost REQUIRED COMPONENTS date_time filesystem wserialization system serialization thread regex)

    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        target_link_libraries(your_exec ${Boost_LIBRARIES})
    endif()
endif()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Server)
# TODO: Add tests and install targets if needed.
