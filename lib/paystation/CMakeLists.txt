cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_cxx_flag("-Wall")
enable_cxx_flag("-Wextra")
enable_cxx_flag("-Werror")
enable_cxx_flag("-pedantic")

set( 
  SOURCES 
  src/Paystation.cpp 
  src/Paystrategies/FixedLinearRate.cpp
)

set( 
  INCLUDES 
  include/Paystation.h
  include/Paystrategy.h
  include/Paystrategies/FixedLinearRate.h
)

add_library( 
  paystation
  SHARED
  ${SOURCES}
  ${INCLUDES}
)
target_include_directories( paystation PUBLIC include )
