cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O3 -Wall")
project(main VERSION 1.0)

#specify the non-header source files to be compiled
file(GLOB CPP_SOURCE
"${PROJECT_SOURCE_DIR}/src/*.cpp"
"${PROJECT_SOURCE_DIR}/src/*/*.cpp"
)

add_executable(main ${CPP_SOURCE})

#where to find header files
include_directories(${PROJECT_SOURCE_DIR}/lib)

target_include_directories(main PUBLIC /usr/include/SFML)

target_link_libraries(main sfml-system sfml-window sfml-graphics)
