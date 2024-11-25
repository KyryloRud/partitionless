# Dependencies for Partitionless

This document lists the dependencies required to build and use the Partitionless project.

> **Note**: Version information provided on this page is not final. The project build was tested with these components; however, it could be compatible with older versions of these dependencies.

> **Note**: You can use a preconfigured development environment from the Docker image directly or with the development container functionality in Visual Studio Code.

## Operating System

Project development is currently based on the [Debian Bookworm](https://www.debian.org/releases/bookworm/) release.

## Build Tools

|Name|Version|Comments|URL|
|:-|:-:|:-|:-:|
|Docker|27.2|-|[link](https://docs.docker.com/engine/)|
|CMake|3.23|-|[link](https://cmake.org)|
|Clang|14.0|Or other compatible feature set compiler supporting C++23|[link](https://clang.llvm.org)|
