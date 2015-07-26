# Boost framework
# http://www.boost.org
find_package(Boost REQUIRED)

# Google's Protocol Buffer
# See https://github.com/google/protobuf
find_package(Protobuf REQUIRED)

# Setting output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Library)
add_subdirectory(Server)
add_subdirectory(UnitTests)