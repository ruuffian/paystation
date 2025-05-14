cmake_minimum_required(VERSION 3.10)
project(paystation)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

# Set flag if available on compiler
include(CheckCXXCompilerFlag)
function(enable_cxx_flag flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()

enable_cxx_flag("-Wall")
enable_cxx_flag("-Wextra")
enable_cxx_flag("-Werror")
enable_cxx_flag("-pedantic")

add_subdirectory( lib/paystation )

set( 
  SOURCES 
  src/main.cpp 
  src/Menu/Menu.cpp
  src/Menu/MenuOption.cpp
  src/MenuOptions/EchoMenuOption.h
  src/MenuOptions/EchoMenuOption.cpp
  src/MenuOptions/SubMenuOption.h
  src/MenuOptions/SubMenuOption.cpp
  src/MenuOptions/ExitMenuOption.h
  src/MenuOptions/ExitMenuOption.cpp
)

set(
  INCLUDES
  include/Menu/Menu.h
  include/Menu/MenuOption.h
)

add_executable( main.exe ${SOURCES} ${INCLUDES} )

target_include_directories(main.exe PRIVATE include include/Menu)

target_link_libraries( main.exe PRIVATE paystation )
