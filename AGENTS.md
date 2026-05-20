# AGENTS.md

Guidance for AI coding agents working on the **Arka** C++20 Arkanoid codebase.

## Project Overview

**Arka** is a minimal Raylib-based Arkanoid clone demonstrating a simple game loop architecture. It's designed for progressive feature expansion (paddle, bricks, collision detection, scoring) while maintaining a clean component-based structure.

- **Language**: C++20
- **Build System**: CMake 4.2+
- **Graphics**: Raylib 5.5 (auto-fetched via FetchContent)
- **Structure**: Single executable with modular, header-based components

## Architecture Pattern

The project follows a **component-based game object pattern**:

1. **Game Objects** (`Ball` class exemplifies this):
   - Header file (`.h`): Class declaration with member variables and public interface
   - Implementation (`.cpp`): Physics, collision, rendering logic
   - Constructor: Takes initial state (position, velocity, dimensions)
   - Public methods: `Update(float dt)` for game logic, `Draw()` for rendering

2. **Main Loop** (`main.cpp`):
   - Initializes Raylib once at startup
   - Sets target FPS (currently 60)
   - Loop: Update all objects with delta time → Clear screen → Draw all objects
   - Clean shutdown with `CloseWindow()`

**When adding new components** (Paddle, Brick, etc.), follow this pattern:
- Create `src/component_name.h` with class declaration
- Create `src/component_name.cpp` with implementation
- Add to `CMakeLists.txt` source list and include in `main.cpp`

## Build & Development Workflow

```bash
# Configure (creates build directory)
cmake -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug

# Build (incremental compilation)
cmake --build cmake-build-debug

# Run executable
./cmake-build-debug/Arka
```

**Recommended for iteration:**
- Edit source files
- Run `cmake --build cmake-build-debug` (CMake rebuilds only changed files)
- Raylib is auto-fetched in `_deps/` (first configure only)

## Conventions & Patterns

### Member Variable Initialization
- Use C++20 member initializer lists in constructors
- Example: `Ball::Ball(float x, y, r, vx, vy) : position{x, y}, velocity{vx, vy}, radius(r) {}`

### Headers

- When creating a new source file, be sure to include headers with license (Project Arka etc.) like the one in `main.cpp`

### Physics Simulation
- Delta time (`dt`) is passed to `Update()` methods (from `GetFrameTime()`)
- Position updates: `position.x += velocity.x * dt`
- Raylib types used directly: `Vector2`, `Color` constants (`BLACK`, `WHITE`)

### Boundary Conditions (Ball Pattern)
```cpp
// Radius-based collision with screen bounds
if (position.x - radius <= 0.0f) {
    position.x = radius;  // Clamp position
    velocity.x = -velocity.x;  // Reverse direction
}
```

### Drawing
- Always use Raylib drawing functions within `BeginDrawing()` / `EndDrawing()` (handled in main loop)
- Objects implement their own `Draw()` method (e.g., `DrawCircleV(position, radius, WHITE)`)

### Headers vs Implementation
- Use `#pragma once` for include guards (modern C++ convention)
- Include only necessary headers in `.h` files (Raylib types only as needed)
- Implementation-specific includes go in `.cpp`

## Raylib Integration Points

- **Input**: Use Raylib functions directly in Update methods (e.g., `IsKeyPressed()`, `GetMousePosition()`)
- **Screen dimensions**: Query at runtime with `GetScreenWidth()`, `GetScreenHeight()` (not hardcoded)
- **Rendering**: All Raylib calls must occur between `BeginDrawing()` and `EndDrawing()`
- **Frame timing**: `GetFrameTime()` provides `dt` for physics; `SetTargetFPS()` locks frame rate

## Key Files & Their Roles

| File | Purpose |
|------|---------|
| `CMakeLists.txt` | Build configuration; add new `.cpp` files to `add_executable()` |
| `src/main.cpp` | Game loop; instantiate and update/draw all components |
| `src/ball.h` / `src/ball.cpp` | Reference implementation of game object pattern |
| `CLAUDE.md` | General build documentation (imported from this file) |

## Rapid Development Tips

1. **Testing changes**: After editing `.cpp`, run `cmake --build cmake-build-debug` — incremental rebuild is fast
2. **Adding a component**: Copy `ball.h` and `ball.cpp`, rename, modify; add filename to `CMakeLists.txt`
3. **Debug physics**: Print values in `Update()` using standard C++ (not Raylib-dependent)
4. **Screen dimensions**: Always use `GetScreenWidth()`/`GetScreenHeight()` to support resizing

## External Dependency: Raylib

Raylib is C-language library with simple C++ bindings. Key implications:
- Types are structs (e.g., `Vector2 = {x, y}`)
- No exceptions; functions return status or void
- All graphics/input/audio via global-like Raylib functions (not OOP-wrapped)
- Documentation: https://www.raylib.com/cheatsheet/cheatsheet.html

