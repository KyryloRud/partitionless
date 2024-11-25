set(TARGET partitionless-dev)

add_library(${TARGET} SHARED partitionless.cpp)
install(TARGETS ${TARGET})

if(BUILD_TESTING)
add_subdirectory(tests)
endif()
