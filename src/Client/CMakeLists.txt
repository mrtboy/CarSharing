include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_library(MainMenu MainMenu.cpp MainMenu.h)

add_library(Connection Connection.cpp Connection.h)


add_executable(Client Client.cpp Client.h)


#every library should linked to Cleint 
target_link_libraries(Client debug Car.dll User.dll ManageUser.dll)
target_link_libraries(Client optimized Car.dll User.dll ManageUser.dll)