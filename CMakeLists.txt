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
  src/MenuOptions/AdminMenu.h
  src/MenuOptions/AdminMenu.cpp
  src/MenuOptions/ChangeAdminPin.h
  src/MenuOptions/ChangeAdminPin.cpp
  src/MenuOptions/InsertCoin.h
  src/MenuOptions/InsertCoin.cpp
  src/MenuOptions/ReadMeter.h
  src/MenuOptions/ReadMeter.cpp
  src/MenuOptions/BuyParking.h
  src/MenuOptions/BuyParking.cpp
  src/MenuOptions/Exit.h
  src/MenuOptions/Exit.cpp
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
