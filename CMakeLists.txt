cmake_minimum_required(VERSION 3.9.0)
message(STATUS "CMake version: ${CMAKE_VERSION}")

project(ARAD)

set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)

option(USE_CUDA "Use CUDA" ON)

file(GLOB cpu_source_files 
	"${CMAKE_SOURCE_DIR}/src/*.cpp"
	"${CMAKE_SOURCE_DIR}/src/ports/*.h"
)

file(GLOB gpu_source_files "${CMAKE_SOURCE_DIR}/src/*.cu")

# Modern CMake
enable_language("CUDA")
add_executable(ARAD ${cpu_source_files} ${gpu_source_files})

message(STATUS "USE_CUDA: ${USE_CUDA}")
if(USE_CUDA)
    add_definitions(-DUSE_CUDA)
endif()
