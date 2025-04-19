cmake_minimum_required(VERSION 3.16)
project(prog2hw VERSION 1.0 LANGUAGES CXX)

# Use modern C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compile_commands.json for IDE integration (especially VSCode)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Gather all source files from src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

# Create the main executable
add_executable(prog2hw ${SOURCES})

# Now that the target exists, attach the include directory to it
target_include_directories(prog2hw
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# DELETE:
# Optional: Add sandbox tools (e.g., test scripts, later test drivers)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/sandbox")
    message(STATUS "Sandbox tools available in /sandbox")
endif()

# Prevent warning if tests folder exists but is not used yet
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
    add_subdirectory(tests)
endif()
