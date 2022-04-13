# Set library name
project(toml++)

set(TOML_EXCEPTIONS 0)

# Generate headers only library
add_library(${PROJECT_NAME} INTERFACE)

# Files to include in the library
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR}/include/)