set(TARGET partitionlessd)

add_executable(${TARGET} main.cpp server.cpp)
target_link_libraries(${TARGET} PUBLIC partitionless-rpc Boost::boost)
install(TARGETS ${TARGET} PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE DESTINATION sbin)
