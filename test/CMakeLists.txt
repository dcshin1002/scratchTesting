set(MY_SRCS_MINUS_MAIN ${MY_SRCS})
list(REMOVE_ITEM MY_SRCS_MINUS_MAIN ${PROJECT_SOURCE_DIR}/src/Main.cpp)

file(GLOB MY_TEST_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/testMain.cpp)
file(GLOB MY_TEST_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
set(MY_BINARY_NAME "TestExecutor")

add_executable(${MY_BINARY_NAME} ${MY_TEST_SRCS} ${MY_SRCS_MINUS_MAIN})

target_include_directories(${MY_BINARY_NAME} PUBLIC ${MY_INCLUDES}
                                                    ${MY_TEST_INCLUDES})

target_link_libraries(${MY_BINARY_NAME} gtest)
add_test(NAME gtest_${MY_BINARY_NAME} COMMAND ${MY_BINARY_NAME})
add_custom_target(check
        COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND}
        DEPENDS ${MY_BINARY_NAME})