include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(Tests main.cpp main.h)

target_link_libraries(Tests PUBLIC CarLibrary)

enable_testing()
add_test(Tests ${CMAKE_CURRENT_BINARY_DIR}/${Tests})