cmake_minimum_required(VERSION 3.10)
project(paystation)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory( lib/paystation )

set( 
  SOURCES 
  src/main.cpp 
  src/tui.cpp
  src/Menu/Menu.cpp
  src/Menu/Headers/PaystationBalance.h
  src/Menu/Headers/PaystationBalance.cpp
  src/Menu/Options/AdminMenu.h
  src/Menu/Options/AdminMenu.cpp
  src/Menu/Options/ChangeAdminPin.h
  src/Menu/Options/ChangeAdminPin.cpp
  src/Menu/Options/InsertCoin.h
  src/Menu/Options/InsertCoin.cpp
  src/Menu/Options/ReadMeter.h
  src/Menu/Options/ReadMeter.cpp
  src/Menu/Options/BuyParking.h
  src/Menu/Options/BuyParking.cpp
  src/Menu/Options/Exit.h
  src/Menu/Options/Exit.cpp
)

set(
  INCLUDES
  include/tui.h
  include/Menu/Menu.h
  include/Menu/Header.h
  include/Menu/Option.h
)

add_executable( main.exe ${SOURCES} ${INCLUDES} )

target_include_directories(main.exe PRIVATE include include/Menu)

target_link_libraries( main.exe PRIVATE paystation )

if(UNIX)
  target_compile_options(main.exe PRIVATE -Wall -Wextra -Wpedantic -Werror)
else()
  target_compile_options(main.exe PRIVATE /W4 /WX)
endif()
