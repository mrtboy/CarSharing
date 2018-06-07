include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

enable_testing()

add_test(ManageUser-test ManageUser-test.cpp)

add_executable(ManageUserTest main.cpp ManageUser-test)

target_link_libraries(ManageUserTest PUBLIC CarLibrary)

