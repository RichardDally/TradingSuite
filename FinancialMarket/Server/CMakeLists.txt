project(FinancialMarketServer CXX)

# Use static libraries for Boost
if (WIN32)
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

########################################################

# Boost framework
# http://www.boost.org
find_package(Boost 1.40.0 REQUIRED COMPONENTS system date_time regex)

# Include Boost headers
include_directories(${Boost_INCLUDE_DIR})

########################################################

# Google's Protocol Buffer
# See https://github.com/google/protobuf
find_package(Protobuf REQUIRED)

# Include Google's Protocol Buffer headers
include_directories(${PROTOBUF_INCLUDE_DIRS})

# Include ProtobufMessages template serialization helpers
include_directories(${ProtobufMessages_SOURCE_DIR}/headers)

# Include generated protobuf message headers
include_directories(${ProtobufMessages_BINARY_DIR})

########################################################

# Include FinancialMarketServer headers
include_directories(headers)

# Include FinancialMarketLibrary headers
include_directories(${FinancialMarketCore_SOURCE_DIR}/headers)

# FinancialMarketServer files
file(GLOB_RECURSE FINANCIAL_MARKET_SERVER_FILES headers/* src/*)

add_executable(FinancialMarketServer ${FINANCIAL_MARKET_SERVER_FILES})

# Adding FinancialMarketCore headers
include_directories(${FinancialMarketCore_BINARY_DIR})
target_link_libraries(FinancialMarketServer FinancialMarketCore ProtobufMessages ${Boost_LIBRARIES} ${PROTOBUF_LIBRARIES})