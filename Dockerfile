# Use the official Ubuntu 20.04 image as a base
FROM ubuntu:22.04

# Set environment variables to non-interactive (this prevents some prompts)
ENV DEBIAN_FRONTEND=non-interactive

# Install dependencies
RUN apt-get update && apt-get install -y \
  g++ \
  cmake \
  libboost-filesystem-dev \
  libspdlog-dev \
  git \
  curl \
  unzip \
  tar \
  zip \
  linux-libc-dev \
  pkg-config

# Install vcpkg
RUN git clone https://github.com/microsoft/vcpkg.git && \
  cd vcpkg && \
  ./bootstrap-vcpkg.sh && \
  ./vcpkg integrate install

# Install cpr and nlohmann_json using vcpkg
RUN ./vcpkg/vcpkg install cpr nlohmann-json

# Set the CMake toolchain file to use vcpkg
ENV CMAKE_TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake

# Copy the current directory (your C++ project) into the Docker image
COPY . /app

# Set the working directory
WORKDIR /app

# Fetch GoogleTest
RUN git clone https://github.com/google/googletest.git third_party/googletest

# Build the project
RUN rm -rf build && \
  mkdir -p build && cd build && \
  cmake .. -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE} && \
  make


# Set the default command to run your application
CMD ["./build/console_rpg"]
