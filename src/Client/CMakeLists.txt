include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(Client Client.cpp Client.h)

#every library should linked to Cleint 
target_link_libraries(Client PUBLIC CarLibrary)