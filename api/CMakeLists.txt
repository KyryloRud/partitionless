set(TARGET proto-api)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS partitionless.proto)
add_library(${TARGET} STATIC ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${Protobuf_INCLUDE_DIRS})
target_link_libraries(${TARGET} PUBLIC protobuf::libprotobuf)
