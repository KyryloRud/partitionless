set(TARGET partitionless-rpc)

add_library(${TARGET} partitionless.proto)
target_link_libraries(${TARGET} PUBLIC protobuf::libprotobuf gRPC::grpc gRPC::grpc++)
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate(TARGET ${TARGET} LANGUAGE cpp)
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET ${TARGET} LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
