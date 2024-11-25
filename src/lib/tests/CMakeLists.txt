set(TARGET ut_partitionless)

add_executable(${TARGET} ut_partitionless.cpp)
target_link_libraries(${TARGET} GTest::GTest GTest::Main partitionless-dev)
add_test(NAME ${TARGET} COMMAND ${TARGET})
