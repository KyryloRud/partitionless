# Dependencies for Partitionless

This document lists the dependencies required to build and use the Partitionless project.
Refer to the [NOTICE](./NOTICE) file for additional license details.

> **Note**: Version information provided on this page is not final. The project build was tested with these components; however, it could be compatible with older versions of these dependencies.

> **Note**: You can use a preconfigured development environment from the Docker image directly or with the development container functionality in Visual Studio Code.

## OS

Project development is currently based on the [Debian Bookworm](https://www.debian.org/releases/bookworm/) release.

## Build Tools

|Name|Version|Comment|URL|
|:-|:-:|:-|:-:|
|Docker|27.2|-|[link](https://docs.docker.com/engine/)|
|CMake|3.23|-|[link](https://cmake.org)|
|Clang|14.0|Or other compatible feature set compiler supporting C++23|[link](https://clang.llvm.org)|
|Clang-Format|14.0|-|[link](https://releases.llvm.org/14.0.0/tools/clang/docs/ClangFormat.html)|
|Protobuf-Compiler|3.21|-|[link](https://protobuf.dev)|

## Libraries

|Name|Version|Comment|URL|
|:-|:-:|:-|:-:|
|libgtest-dev|1.12|-|[link](https://google.github.io/googletest/)|
|libprotobuf-dev|3.21|-|[link](https://protobuf.dev)|
