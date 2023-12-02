cmake_minimum_required (VERSION 3.22)

project ("adventofcode-2023"
  VERSION 0.0.1
  DESCRIPTION ""
  HOMEPAGE_URL "https://github.com/AntonSamojlow/adventofcode-2023"
  LANGUAGES CXX
)

# set global c++ standard to c++20
set(CMAKE_CXX_STANDARD 23)

# log base compiler info
if(CMAKE_CXX_COMPILER_LOADED)
  message(STATUS "CMAKE_CXX_COMPILER='${CMAKE_CXX_COMPILER}'")
  message(STATUS "CMAKE_CXX_COMPILER_ID='${CMAKE_CXX_COMPILER_ID}'")
  message(STATUS "CMAKE_CXX_COMPILER_VERSION='${CMAKE_CXX_COMPILER_VERSION}'")
  message(STATUS "CMAKE_COMPILER_IS_GNUCXX='${CMAKE_COMPILER_IS_GNUCXX}'")
endif()

include("${CMAKE_CURRENT_LIST_DIR}/cmake/StaticAnalysis.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/Warnings.cmake")

if(ENABLE_CLANG_TIDY)
  enable_clang_tidy_globally()
endif()

add_executable(main main.cpp src/day1.h src/day1.cpp)

