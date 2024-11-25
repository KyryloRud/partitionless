cmake_minimum_required(VERSION 3.23)

project(Partitionless VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -pedantic)

include_directories(${CMAKE_SOURCE_DIR}/include/partitionless)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/partitionless TYPE INCLUDE
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        DIRECTORY_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

add_subdirectory(src/lib)
add_subdirectory(src/cli)
add_subdirectory(src/daemon)
