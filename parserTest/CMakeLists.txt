    cmake_minimum_required(VERSION 3.14) # Or your project's minimum CMake version
    project(parserTest)

    # Link against your DLL project and GTest
    add_executable(${PROJECT_NAME} parserApiTest.cpp)
    target_link_libraries(${PROJECT_NAME} PRIVATE
        parserInterface ${CMAKE_SOURCE_DIR} # Replace with the actual target name of your DLL
        gtest_main # Provides the main function for GTest
    )

    # Add include directories for your DLL's headers if needed
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/parserInterface
    )

    # Add the test to CTest
    add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})