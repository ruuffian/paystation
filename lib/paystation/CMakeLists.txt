cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set( 
  SOURCES 
  src/paystation.cpp 
  src/fixed_linear_rate.cpp
)

set( 
  INCLUDES 
  include/paystation.h
  include/paystrategy.h
  include/fixed_linear_rate.h
)

add_library( 
  paystation
  ${SOURCES}
  ${INCLUDES}
)
target_include_directories( paystation PUBLIC include )
