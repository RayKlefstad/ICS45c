# ICS 45C: Homework 7

Welcome to ICS 45C Homework 7! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw7`, then push the `hw7` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Fetch updates:
git fetch public

# Checkout hw7 from the public branch:
git checkout hw7

# Push the newly checked out branch to your private repository:
git push -u origin hw7
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw7` with the following structure:

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── array_gtests.cpp
│   ├── int_array_gtests.cpp
│   ├── gtestmain.cpp
│   └── matrix_gtests.cpp
└── src
    ├── alloc.cpp
    ├── alloc.hpp
    ├── array.hpp
    ├── int_array.hpp
    ├── matrix.hpp
    └── standard_main.cpp
```

You should copy everything from the `CMakeLists.txt` and `CMakePresets.json` files into your own,
as well as the files `gtestmain.cpp` and the individual `gtests`.

## Build Instructions

```bash
# Produce the `build` folder with the presets provided for the homework:
cmake --preset default

# Build all targets at once:
cmake --build build

# Build only standard_main.cpp:
cmake --build build --target standard_main

# Build int_array gtests:
cmake --build build --target int_array_gtests

# Build array gtests:
cmake --build build --target array_gtests

# Build matrix gtests:
cmake --build build --target matrix_gtests
```

To run the above targets after compiling them:

```bash
./build/standard_main       # Runs the 'main' function from src/standard_main.cpp
./build/int_array_gtests    # Runs the 'int_array' gtests
./build/array_gtests        # Runs the 'array' gtests
./build/matrix_gtests       # Runs the 'matrix' gtests
```

NOTE : If you want to also use valgrind to check your code, use these instructions:

```bash
# Produce the `build_valgrind` folder with the presets provided for the homework:
cmake --preset valgrind

# Build all targets at once:
cmake --build build_valgrind

# Build only standard_main.cpp:
cmake --build build_valgrind --target standard_main

# Build array gtests:
cmake --build build_valgrind --target array_gtests

# Build matrix gtests:
cmake --build build_valgrind --target matrix_gtests
```

Then run the above targets with:

```bash
./build_valgrind/standard_main        # Runs the 'main' function from src/standard_main.cpp
./build_valgrind/array_gtests         # Runs the 'array' gtests
./build_valgrind/matrix_gtests       # Runs the 'matrix' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push` your
changes to your private repository, and then submitting the `hw7` branch to `Gradescope`. Or, you can
upload files directly, namely: `alloc<.hpp/.cpp>`, `array.hpp`, `int_array.hpp`,
`matrix.hpp`, and `standard_main.cpp`.
