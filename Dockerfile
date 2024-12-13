FROM debian:bookworm-slim

RUN apt update && \
    apt install -y git \
                   clang \
                   cmake \
                   protobuf-compiler \
                   protobuf-compiler-grpc \
                   libgrpc++-dev \
                   libgtest-dev \
                   clang-format \
                   libboost-dev && \
    apt autoremove --purge
