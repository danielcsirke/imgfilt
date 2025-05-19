cmake_minimum_required(VERSION 3.16)
project(imgfilt VERSION 1.0 LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compile_commands.json for IDE integration (especially VSCode)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Set output directories for binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Gather all source files from src/ recursively
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Create the main executable
add_executable(imgfilt ${SOURCES})

# Include all relevant header directories
target_include_directories(imgfilt
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/filters
        ${CMAKE_CURRENT_SOURCE_DIR}/include/filt_op
        ${CMAKE_CURRENT_SOURCE_DIR}/include/io
        ${CMAKE_CURRENT_SOURCE_DIR}/include/types
)

# Optional: treat warnings as errors
# target_compile_options(imgfilt PRIVATE -Wall -Wextra -Werror)

# Optional: group sources by folders in IDEs
# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src PREFIX "Source Files" FILES ${SOURCES})
