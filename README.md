# ICS 45C: Homework 3 

## Getting Started

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Get the most recent state of our code
git fetch --all

# Checkout hw3 from the public branch:
git checkout hw3
```

## Directory Structure

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   ├── string_gtests.cpp
│   ├── standard_main_gtests.cpp
│   └── student_gtests.cpp
├── README.md
└── src
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

# Build only string_main gtests:
cmake --build build --target standard_main_gtests

# Build string and student gtests:
cmake --build build --target string_gtests

# Build student gtests:
cmake --build build --target student_gtests
```

To run the above targets after compiling them:

```bash
./build/standard_main        # Runs the 'main' function from src/standard_main.cpp
./build/standard_main_gtests # Runs the 'standard_main' gtest set of tests
./build/string_gtests        # Runs the 'string' and 'student' gtest sets
./build/student_gtests       # Runs the 'student' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you should submit via `GitHub` by `git commit` and `git push` your
changes to your private repository, and then submitting the `hw3` branch to `Gradescope`.
