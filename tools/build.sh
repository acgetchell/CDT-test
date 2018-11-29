#!/usr/bin/env bash
cd ..
rm -rf build/
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/Users/adam/vcpkg/scripts/buildsystems/vcpkg.cmake ..
cmake --build .