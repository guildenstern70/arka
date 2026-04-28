# Arka

A C++20 clone of the classic Arkanoid arcade game, built with [Raylib](https://www.raylib.com/).

## Requirements

- CMake 4.2+
- A C++20-capable compiler (GCC 10+, Clang 12+, MSVC 2019+)

Raylib is fetched automatically at configure time — no manual installation needed.

## Build

```bash
# Configure
cmake -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build cmake-build-debug

# Run
./cmake-build-debug/Arka
```
