cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

include(CTest)
add_subdirectory(
  external
)

add_library( 
  paystation
  STATIC 
  ${SOURCES}
  ${INCLUDES}
)
target_include_directories( paystation PUBLIC include )
target_compile_options(paystation PRIVATE -Wall -Wextra -Wpedantic -Werror)

if(BUILD_TESTING)
  set(
    UNIT_TESTS
    src/Paystation.test.cpp
    src/Paystrategies/FixedLinearRate.test.cpp
  )
  add_executable( unit_tests ${UNIT_TESTS} ${SOURCES} ${INCLUDES} )
  target_link_libraries( unit_tests PRIVATE GTest::gtest_main )
  target_include_directories( unit_tests PUBLIC include )
  
  include(GoogleTest)
  gtest_discover_tests(unit_tests)
endif()
