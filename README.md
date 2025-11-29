# CVector

A simple dynamic array library in C. Works as both a **static** and **shared** library.

## Features

* Dynamic array for arbitrary data types
* Functions: `vec_init`, `vec_push_back`, `vec_get`, `vec_pop_copy`, `vec_reserve`, `vec_shrink_to_fit`, `vec_deinit`
* Easy to integrate into your C projects

## Build Instructions

**Clone the project and create a build directory:**

```bash
git clone <repo-url>
cd project
mkdir build
cd build
```

**Build (static library by default):**

```bash
cmake ..
cmake --build .
```

**Build as shared library:**

```bash
cmake -DBUILD_SHARED_LIBS=ON ..
cmake --build .
```

**Run the test executable:**

```bash
./bin/test
```

* Static library: `libcvector.a` in `lib/`
* Shared library: `libcvector.so` (Linux) or `cvector.dll` (Windows) in `lib/`

## Usage

Include the header and link the library in your own projects:

```c
#include "cvector.h"

Vec v;
vec_init(&v, sizeof(int));
```

Link with CMake or manually with `-Llib -lcvector`.
