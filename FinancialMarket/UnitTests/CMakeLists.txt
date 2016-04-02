project(FinancialMarketUnitTests CXX)

# Boost
# http://www.boost.org
#find_package(Boost COMPONENTS unit_test_framework REQUIRED)
#include_directories(${Boost_INCLUDE_DIR})
#target_link_libraries(${FINANCIAL_MARKET_UNIT_TESTS_BINARY} ${Boost_LIBRARIES})

# CppUnit
# https://github.com/cpputest/cpputest
#find_package(CPPUNIT REQUIRED)
#include_directories(${CPPUNIT_INCLUDE_DIRS})
#target_link_libraries(${FINANCIAL_MARKET_UNIT_TESTS_BINARY} ${CPPUNIT_LIBRARIES})

# Google C++ Testing Framework
# https://code.google.com/p/googletest/
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Windows (x86 and x64) specific instructions for GTest
if (WIN32)
	# GTest is static compiled by default
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

# Google's Protocol Buffer
# See https://github.com/google/protobuf
find_package(Protobuf REQUIRED)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIR})

# Include Google's Protocol Buffer headers
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Include generated protobuf message headers
include_directories(${ProtobufMessages_BINARY_DIR})

# Include FinancialMarketCore headers
include_directories(${FinancialMarketCore_SOURCE_DIR}/headers)

# Include FinancialMarketServer headers
include_directories(${FinancialMarketServer_SOURCE_DIR}/headers)

# Include ProtobufMessages template serialization helpers
include_directories(${ProtobufMessages_SOURCE_DIR}/headers)

# Include FinancialMarketUnitTests headers
include_directories(headers)

# FinancialMarketUnitTests files
file(GLOB_RECURSE FINANCIAL_MARKET_UNIT_TESTS_FILES headers/* src/*)

add_executable(FinancialMarketUnitTests ${FINANCIAL_MARKET_UNIT_TESTS_FILES})

target_link_libraries(FinancialMarketUnitTests FinancialMarketCore ProtobufMessages ${GTEST_BOTH_LIBRARIES} ${PROTOBUF_LIBRARIES})

enable_testing()
add_test(NAME FinancialMarketUnitTests COMMAND FinancialMarketUnitTests)