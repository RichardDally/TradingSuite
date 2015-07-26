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

if(WIN32)
	# GTest is static compiled by default
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

# Include Boost headers
include_directories(${Boost_INCLUDE_DIR})

# Include Google's Protocol Buffer headers
include_directories(${PROTOBUF_INCLUDE_DIRS})

# Include FinancialMarketLibrary headers
include_directories(${FinancialMarketLibrary_SOURCE_DIR}/headers)

# Include FinancialMarketUnitTests headers
include_directories(headers)

# FinancialMarketUnitTests files
file(GLOB_RECURSE FINANCIAL_MARKET_UNIT_TESTS_FILES headers/* src/*)

add_executable(FinancialMarketUnitTests ${FINANCIAL_MARKET_UNIT_TESTS_FILES})

include_directories(${FinancialMarketLibrary_BINARY_DIR})
target_link_libraries(FinancialMarketUnitTests ${GTEST_BOTH_LIBRARIES} FinancialMarketLibrary)

enable_testing()
add_test(NAME FinancialMarketUnitTests COMMAND FinancialMarketUnitTests)