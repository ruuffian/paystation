cmake_minimum_required(VERSION 3.20)
project(paystation)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory( lib/paystation )

set( 
  SOURCES 
  src/main.cpp 
)

set( 
  INCLUDES 
)

add_executable( main.exe ${SOURCES} ${INCLUDES} )

target_link_libraries( main.exe PRIVATE paystation )
