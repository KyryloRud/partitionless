set(TARGET partitionless-cli)
set(TARGET_SHORTNAME pl)
set(TARGET_EXECNAME partitionless)

add_executable(${TARGET} main.cpp)
target_link_libraries(${TARGET} PUBLIC partitionless)
add_custom_command(
    TARGET ${TARGET} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink ./${TARGET_EXECNAME} ${TARGET_SHORTNAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_SHORTNAME} TYPE BIN)
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/${TARGET} RENAME ${TARGET_EXECNAME} TYPE BIN
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)
