cmake_minimum_required(VERSION 3.9.0)
message(STATUS "CMake version: ${CMAKE_VERSION}")

project(ARAD)

# Location of compiler on VM
set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)


# Add list of CPU source files (cpp and h files)
file(GLOB cpu_source_files 
	"${CMAKE_SOURCE_DIR}/src/*.cpp"
	"${CMAKE_SOURCE_DIR}/src/*.h"
)

# Add list of GPU source files (cu files)
file(GLOB gpu_source_files 
	"${CMAKE_SOURCE_DIR}/src/*.cu"
)

# Build executable
enable_language("CUDA")
add_executable(ARAD ${cpu_source_files} ${gpu_source_files})
add_definitions(-DUSE_CUDA)
