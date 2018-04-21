# build using:
#   BOOST_ROOT=../boost_1_55_0 cmake .
# later verbose output from make:
#   make VERBOSE=1
# /usr/bin/c++ -I.../boost_1_55_0 -std=gnu++11 -o CMakeFiles/udpechoserver.dir/udpechoserver.cpp.o -c udpechoserver.cpp
# /usr/bin/c++ CMakeFiles/udpechoserver.dir/udpechoserver.cpp.o -o udpechoserver -rdynamic .../boost_1_55_0/stage/lib/libboost_system.so -Wl,-rpath,.../boost_1_55_0/stage/lib

# the property CXX_STANDARD is first mentioned in cmake 3.1.3
cmake_minimum_required (VERSION 3.1.3)

project (asio)

# executable name
set(EXEC_NAME "udpchatserver")

if(WIN32)
	

	set(BOOST_ROOT C:/boost_1_66_0/boost_1_66_0)

	if(NOT EXISTS BOOST_ROOT AND NOT EXISTS Header)
		
		set(BOOST_ROOT C:/boost_1_66_0/boost_1_66_0)
	endif()

	set(BOOST_USE_STATIC_LIBS OFF)
	set(Boost_USE_MULTITHREADED ON)
	set(Boost_USE_STATIC_RUNTIME OFF)

	
	include_directories(${BOOST_ROOT})
    link_directories(${BOOST_ROOT}/stage/lib) # add this before add_executable()
endif()


add_executable(${EXEC_NAME} main.cpp chatserver.cpp)
set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${EXEC_NAME} PROPERTY CXX_STANDARD_REQUIRED true)

# internal list of mandatory boost components
SET(BOOST_MANDATORY_COMPONENTS system)

if( "$ENV{BOOST_ROOT}" STREQUAL "" )
  set( BOOST_ROOT ${CMAKE_HOME_DIRECTORY}/../boost_1_61_0 )
endif()



# add include path for boost to the compiler
include_directories(${Boost_INCLUDE_DIRS})

# now link against the boost library system
target_link_libraries(${EXEC_NAME} ${Boost_SYSTEM_LIBRARY})


