project(ProtobufMessages CXX)

# Google's Protocol Buffer
# See https://github.com/google/protobuf
find_package(Protobuf REQUIRED)

# Windows (x86 and x64) specific instructions for GTest
if (WIN32)
	# GTest is static compiled by default
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

# Protobuf headers
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE PROTOBUF_SOURCE_FILES headers/* src/*)

# Generate Protobuf header and source files
protobuf_generate_cpp(PROTO_SRC PROTO_HEADERS messages/Referential.proto)

add_library(ProtobufMessages STATIC ${PROTO_SRC} ${PROTO_HEADERS} ${PROTOBUF_SOURCE_FILES})