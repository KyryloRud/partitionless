set(TARGET partitionless-dev)

add_library(${TARGET} SHARED partitionless.cpp)
install(TARGETS ${TARGET})
