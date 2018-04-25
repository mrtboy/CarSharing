link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
include_directories(${CMAKE_SOURCE_DIR}/../include)

file(GLOB headers *.h)
add_library(User SHARED User.cpp ${headers})
add_library(Car SHARED Car.cpp ${headers})
add_library(ManageUser SHARED ManageUser.cpp ${headers})
add_library(ManageCar SHARED ManageCar.cpp ${headers})

add_definitions(-DEXPMODULE)

# Add source to this project's executable.
target_link_libraries(ManageCar debug Car.lib)
target_link_libraries(ManageCar optimized Car.lib)

target_link_libraries(ManageUser debug User.lib)
target_link_libraries(ManageUser optimized User.lib)

# Add source to this project's executable.
