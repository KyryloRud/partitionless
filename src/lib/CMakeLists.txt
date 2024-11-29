set(TARGET partitionless)

add_library(${TARGET} SHARED partitionless.cpp client.cpp)
target_link_libraries(${TARGET} PUBLIC partitionless-dev partitionless-rpc)
install(TARGETS ${TARGET})

if(BUILD_TESTING)
add_subdirectory(tests)
endif()
