# CMakeList.txt : CMake project for parsingFramework, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

#fetch googlet test framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Add source to this project's executable.
add_library  (parserInterface SHARED "parser.cpp" "parser.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET parserInterface PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
