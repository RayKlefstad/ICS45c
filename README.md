# ICS 45C: Homework 6 

Welcome to ICS 45C Homework 6!

## Getting Started

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Fetch the most recent changes
git fetch --all

# Checkout hw6 from the public branch:
git checkout hw6
```

## Directory Structure

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   ├── picture_gtests.cpp
│   ├── shape_gtests.cpp
└── src
    ├── alloc.cpp
    ├── alloc.hpp
    ├── circle.cpp
    ├── circle.hpp
    ├── picture.cpp
    ├── picture.hpp
    ├── rectangle.cpp
    ├── rectangle.hpp
    ├── shape.cpp
    ├── shape.hpp
    ├── square.cpp
    ├── square.hpp
    ├── standard_main.cpp
    ├── triangle.cpp
    └── triangle.hpp
```

## Build Instructions

```bash
# Produce the `build` folder with the presets provided for the homework:
cmake --preset default

# Build all targets at once:
cmake --build build

# Build only standard_main.cpp:
cmake --build build --target picture_main

# Build shape gtests:
cmake --build build --target shape_gtests

# Build picture gtests:
cmake --build build --target picture_gtests
```

To run the above targets after compiling them:

```bash
./build/picture_main         # Runs the 'main' function from src/standard_main.cpp
./build/shape_gtests         # Runs the 'shape' gtests
./build/picture_gtests       # Runs the 'picture' gtests
```

NOTE : If you want to also use valgrind to check your code, use these instructions:

```bash
# Produce the `build_valgrind` folder with the presets provided for the homework:
cmake --preset valgrind

# Build all targets at once:
cmake --build build_valgrind

# Build only picture_main.cpp:
cmake --build build_valgrind --target picture_main

# Build shape gtests:
cmake --build build_valgrind --target shape_gtests

# Build picture gtests:
cmake --build build_valgrind --target picture_gtests

```

Then run the above targets with:

```bash
./build_valgrind/picture_main         # Runs the 'main' function from src/standard_main.cpp
./build_valgrind/shape_gtests         # Runs the 'shape' gtests
./build_valgrind/picture_gtests       # Runs the 'picture' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you can submit via `GitHub` by `git commit` and `git push -u my_repo` your
changes to your private repository, and then submitting the `hw6` branch to `Gradescope`.
