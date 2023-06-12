# ICS 45C: Homework 2 

Welcome to ICS 45C Homework 2! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw2`, then push the `hw2` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Fetch updates:
git fetch public

# Checkout hw2 from the public branch:
git checkout hw2

# Push the newly checked out branch to your private repository:
git push -u origin hw2
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw2` with the following structure:

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
    ├── coins.h
    ├── coins_menu.cpp
    ├── coins_simple.cpp
    ├── coins_transfer.cpp
    ├── word_count.cpp
    ├── word_count.h
    └── word_count_main.cpp
```

You should copy everything from the `CMakeLists.txt` and `CMakePresets.json` files into your own,
as well as the files `gtestmain.cpp` and the individual `gtests`.

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
./build/coins_gtests        # Runs the 'coins' gtest set of tests
./build/word_count_gtests   # Runs the 'word_count' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push` your
changes to your private repository, and then submitting the `hw2` branch to `Gradescope`. Or, you can
upload files directly, namely: `coins.cpp`, `coins.h`, `coins_menu.cpp`, `coins_simple.cpp`, `coins_transfer.cpp`,
`word_count.cpp`, `word_count.h`, and `word_count_main.cpp`.
