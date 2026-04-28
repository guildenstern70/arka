# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

**Arka** is a C++20 Arkanoid clone built with CMake and [Raylib](https://www.raylib.com/) (fetched automatically via `FetchContent` at configure time — no manual install needed).

## Build

```bash
# Configure (from repo root)
cmake -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build cmake-build-debug

# Run
./cmake-build-debug/Arka
```

The project uses CMake 4.2+ and the C++20 standard.
