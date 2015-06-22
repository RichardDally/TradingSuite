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

set(FINANCIAL_MARKET_UNIT_TESTS_BINARY FinancialMarketUnitTests)
include_directories(${FINANCIAL_MARKET_UNIT_TESTS_PATH}/headers)
file(GLOB_RECURSE FINANCIAL_MARKET_UNIT_TESTS_FILES ${FINANCIAL_MARKET_UNIT_TESTS_PATH}/headers/* ${FINANCIAL_MARKET_UNIT_TESTS_PATH}/src/*)

enable_testing()
add_executable(${FINANCIAL_MARKET_UNIT_TESTS_BINARY} ${FINANCIAL_MARKET_UNIT_TESTS_FILES})
target_link_libraries(${FINANCIAL_MARKET_UNIT_TESTS_BINARY} ${GTEST_BOTH_LIBRARIES})

add_test(NAME ${FINANCIAL_MARKET_UNIT_TESTS_BINARY} COMMAND ${FINANCIAL_MARKET_UNIT_TESTS_BINARY})