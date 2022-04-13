cmake_minimum_required(VERSION 3.10)

# Set the project name (and its version)
project(i3svz VERSION 0.0.0)

configure_file("${PROJECT_SOURCE_DIR}/config/config.h.in" "${PROJECT_SOURCE_DIR}/src/config.h")

# Set C++ standard
set(CXX_STANDARD 17)
# Enforce C++ standard
set(CXX_STANDARD_REQUIRED True)
# Generate compile commands for vim (consumed by YouCompleteMe)
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

add_subdirectory(
    # Include toml++ library
    "${PROJECT_SOURCE_DIR}/external/toml++"
)

# Generate executable from source files
add_executable(
    ${PROJECT_NAME}
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/utils/ArgParser.cpp"
    "${PROJECT_SOURCE_DIR}/src/utils/version.cpp"
    "${PROJECT_SOURCE_DIR}/src/Engine.cpp"
)

target_link_libraries(
    ${PROJECT_NAME}
    # Link toml++ library
    PUBLIC toml++
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES 
        # Set the build output path
        RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)
