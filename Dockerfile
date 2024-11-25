FROM debian:bookworm-slim

RUN apt update && \
    apt install -y git \
                   clang \
                   cmake && \
    apt autoremove --purge
