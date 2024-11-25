FROM debian:bookworm-slim

RUN apt update && \
    apt install -y git \
                   clang \
                   cmake \
                   libgtest-dev && \
    apt autoremove --purge
