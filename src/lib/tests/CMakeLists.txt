set(TARGET ut_partitionless)

add_executable(${TARGET} ut_partitionless.cpp)
target_link_libraries(${TARGET} PUBLIC GTest::GTest GTest::Main partitionless)
add_test(NAME ${TARGET} COMMAND ${TARGET})
