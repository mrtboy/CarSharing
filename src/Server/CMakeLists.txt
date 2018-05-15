include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_library(MenuGenerator MenuGenerator.cpp MenuGenerator.h)

add_executable(Server Server.cpp)


#every library should linked to Server 
target_link_libraries(Server debug Car.dll User.dll ManageUser.dll ManageCar.dll Connection.dll Stock.dll)
target_link_libraries(Server optimized Car.dll User.dll ManageUser.dll ManageCar.dll Connection.dll Stock.dll)
