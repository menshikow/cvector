# CVector

A simple dynamic array library in C. Works as both a **static** and **shared** library.

## Features

* Dynamic array for arbitrary data types
* Functions: `vec_init`, `vec_push_back`, `vec_get`, `vec_pop_copy`, `vec_reserve`, `vec_shrink_to_fit`, `vec_deinit`
* Easy to integrate into your C projects

## Build Instructions

### Configure separate build types

CMake supports multiple build types. Use a dedicated directory for each.

**Debug build (with `-g` for debugging):**

```bash
git clone <repo-url>
cd project
mkdir build-debug
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
```

**Release build (optimized):**

```bash
mkdir build-release
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release
```

### Build the library

Both builds will produce either static or shared libraries depending on your flag.

**Static library (default):**

```bash
cmake ..
cmake --build .
```

**Shared library:**

```bash
cmake -DBUILD_SHARED_LIBS=ON ..
cmake --build .
```

### Running the test executable

From a build directory:

```bash
./bin/test
```

Artifacts:

* Static: `libcvector.a` in `lib/`
* Shared: `libcvector.so` (Linux) or `cvector.dll` (Windows) in `lib/`

## Debugging

To debug the test program or your own code using this library:

```bash
gdb ./bin/test
```

Or use a GUI such as **gdbgui**:

```bash
gdbgui ./bin/test
```

Breakpoints, stepping, memory inspection, and other gdb features work normally, since the Debug build includes symbols.

## Usage

Include the header and link the library:

```c
#include "cvector.h"

Vec v;
vec_init(&v, sizeof(int));
```

Link manually:

```bash
-Llib -lcvector
```

Or via CMake:

```cmake
target_link_libraries(your_target PRIVATE cvector)
```
