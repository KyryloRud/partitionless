# Partitionless

© 2024 Kyrylo Rud. All rights reserved.

## Description

Partitionless is a dynamic filesystem service that manages virtual storage without traditional partitions.

It provides:
 - Enforced quotas;
 - Per-client access permissions;
 - Storage sharing between different clients;
 - Temporary filesystems with expiration mechanism.

## License

This software is licensed under a custom non-profit use license.

It is source-available and provided under specific conditions:
- **Educational and Research Purposes**: The software can be used freely for non-commercial educational or research activities.
- **Commercial Use**: Any use of this software for profit or commercial purposes is strictly prohibited without explicit permission from the copyright holder.
- **Private/POC Use**: Internal proof-of-concept or private non-commercial usage is allowed without restrictions.

For more information, refer to the [LICENSE](./LICENSE) file.

## Build

### Visual Studio Code

Project root directory contains `.devcontainer` folder which fully configures developing environment.

Open project directory in VS Code and run following commands:

- Dev Containers: Reopen in Container
- CMake: Configure
- CMake: Build

### Command Line

It is recommended to use provided `Dockerfile` from the root of the repository.
Otherwise, ensure all dependencies specified in the [DEPENDENCIES](./DEPENDENCIES.md) file are installed on the system.

Execute following console commands (in the root of the project) to build the project:

```sh
mkdir build && cd build
cmake -S . -B build/
cmake --build build/ --parallel $(nproc)
```

## Testing

Project is covered with unit tests. To build them, the `BUILD_UNIT_TESTS` option should be set to `ON`.
After project build, they could be run with `ctest` tool.

```sh
...
cmake -DBUILD_UNIT_TESTS=ON -S . -B build/
cmake --build build/ --parallel $(nproc)
ctest build/
```

## Contact
For inquiries about licensing, collaboration, or other questions, contact:
Kyrylo Rud <krud.official@gmail.com>
