# ICS 45C: Homework 5 

Welcome to ICS 45C Homework 5!

## Getting Started

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Get the newest version from our repository
git fetch --all

# Checkout hw5 from the public branch:
git checkout hw5
```

## Directory Structure

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   ├── string_gtests.cpp
│   └── student_gtests.cpp
└── src
    ├── alloc.cpp
    ├── alloc.hpp
    ├── list.cpp
    ├── list.hpp
    ├── standard_main.cpp
    ├── string.cpp
    └── string.hpp
```

## Build Instructions

```bash
# Produce the `build` folder with the presets provided for the homework:
cmake --preset default

# Build all targets at once:
cmake --build build

# Build only standard_main.cpp:
cmake --build build --target standard_main

# Build string gtests:
cmake --build build --target string_gtests

# Build student gtests:
cmake --build build --target student_gtests
```

To run the above targets after compiling them:

```bash
./build/standard_main        # Runs the 'main' function from src/standard_main.cpp
./build/string_gtests        # Runs the 'string' gtests
./build/student_gtests       # Runs the 'student' gtests
```

NOTE : If you want to also use valgrind to check your code, use these instructions:

```bash
# Produce the `build_valgrind` folder with the presets provided for the homework:
cmake --preset valgrind

# Build all targets at once:
cmake --build build_valgrind

# Build only standard_main.cpp:
cmake --build build_valgrind --target standard_main

# Build string gtests:
cmake --build build_valgrind --target string_gtests

# Build student gtests:
cmake --build build_valgrind --target student_gtests
```

Then run the above targets with:

```bash
./build_valgrind/standard_main        # Runs the 'main' function from src/standard_main.cpp
./build_valgrind/string_gtests        # Runs the 'string' gtests
./build_valgrind/student_gtests       # Runs the 'student' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you can either via `GitHub` by `git commit` and `git push -u my_repo`
your changes to your private repository, and then submitting the `hw5` branch to `Gradescope`.
