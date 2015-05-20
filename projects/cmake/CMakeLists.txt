cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(TradingSimulator)

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})

#message("CMAKE_BINARY_DIR:" ${CMAKE_BINARY_DIR})
#message("CMAKE_CURRENT_BINARY_DIR:" ${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRC PROTO_HEADERS ../../thirdparty/protobuf/InstrumentMessage.proto)

#message("lol" ${PROTO_SRC} ${PROTO_HEADERS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin/)

include_directories(../../headers)
file(GLOB_RECURSE source_files ../../src/* ../../headers/*)

add_executable(TradingSimulator ${source_files} ${PROTO_SRC} ${PROTO_HEADERS})
target_link_libraries(TradingSimulator ${PROTOBUF_LIBRARIES})
