﻿include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(Server Server.cpp Server.h)

target_link_libraries(Server PUBLIC CarLibrary)