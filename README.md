# ICS 45C: Homework 2 

Welcome to ICS 45C Homework 2! Instructions from this point on will assume the use of `GitHub`.

## Getting Started

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Fetch the most recent status from our repo
git fetch --all

# Checkout hw2 from the public branch:
git checkout hw2
```

It is also advisable to delete the build folder from your previous homework when you checkout a new
homework:

```bash
rm -R build
```

## Directory Structure

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── coins_gtests.cpp
│   ├── gtestmain.cpp
│   └── word_count_gtests.cpp
└── src
    ├── coins.cpp
    ├── coins.hpp
    ├── coins_menu.cpp
    ├── coins_simple.cpp
    ├── coins_transfer.cpp
    ├── student_gtests.cpp
    ├── word_count.cpp
    ├── word_count.hpp
    └── word_count_main.cpp
```

## Build Instructions

```bash
# Produce the `build` folder with the presets provided for the homework:
cmake --preset default

# Build all targets at once:
cmake --build build

# Build only coins_simple.cpp:
cmake --build build --target coins_simple

# Build only coins_menu.cpp:
cmake --build build --target coins_menu

# Build only coins_transfer.cpp:
cmake --build build --target coins_transfer

# Build only coins gtests:
cmake --build build --target coins_gtests

# Build student gtests
cmake --build build --target student_gtests

# Build only word_count_main.cpp:
cmake --build build --target word_count

# Build only word_count gtests:
cmake --build build --target word_count_gtests
```

To run the above targets after compiling them:

```bash
./build/coins_simple        # Runs the 'main' function from src/coins_simple.cpp
./build/coins_menu          # Runs the 'main' function from src/coins_menu.cpp
./build/coins_transfer      # Runs the 'main' function from src/coins_transfer.cpp
./build/word_count          # Runs the 'main' function from src/word_count_main.cpp
./build/student_gtests      # Runs the 'word_count' gtests that will be graded
./build/coins_gtests        # Runs the 'coins' gtest set of tests
./build/word_count_gtests   # Runs the 'word_count' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you can submit via `GitHub` by `git commit` and `git push` your
changes to your private repository, and then submitting the `hw2` branch to `Gradescope`.
