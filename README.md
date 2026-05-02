# Binary Star Simulation

A real-time simulation of binary star systems using C++ and OpenGL.

## Building

### Dependencies
* **C++ Compiler**: GCC 15.2.0 or higher (via MSYS2 MinGW-w64).
* **Build System**: CMake 3.20+.
* **GLFW 3.4**: Window management and input.
* **GLAD**: OpenGL loader (included in `/include`).
* **OpenGL**: Minimum version 3.3.

### Toolchain Note
This project is developed using a **MinGW-w64** (GCC) toolchain rather than the standard Microsoft Visual Studio (MSVC) environment.

### Windows
Ensure your MSYS2 `bin` folder is in your system **PATH**. Use the following commands in your terminal:
```
mkdir build
cd build
# Point glfw3_DIR to your local GLFW config folder
cmake -G "MinGW Makefiles" -Dglfw3_DIR="C:/Path/To/GLFW/lib/cmake/glfw3" ..
mingw32-make
```

#### Linux

```
mkdir build
cd build
cmake ..
cmake --build .
```