cmake_minimum_required(VERSION 3.20)
project(mlx_playground CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(MLX REQUIRED)
find_package(benchmark REQUIRED)

# MLX headers available as <mlx/...>, src/ headers available as <experiment/...>
include_directories(${MLX_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/src)

add_compile_options(${MLX_CXX_FLAGS})

add_subdirectory(src)
