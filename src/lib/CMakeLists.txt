project(CarLibrary)

add_library(CarLibrary SHARED
    MainMenu.cpp
    User.cpp
    Car.cpp
    ManageUser.cpp
    ManageCar.cpp
    Connection.cpp)

add_definitions(-DEXPMODULE)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
include_directories(${CMAKE_SOURCE_DIR}/../include)
