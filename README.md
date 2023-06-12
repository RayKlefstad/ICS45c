# ICS 45C: Homework 9

Welcome to ICS 45C Homework 9! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw9`, then push the `hw9` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Fetch updates:
git fetch public

# Checkout hw9 from the public branch:
git checkout hw9

# Push the newly checked out branch to your private repository:
git push -u origin hw9
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw9` with the following structure:

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   ├── map_array_gtests.cpp
│   └── set_list_gtests.cpp
└── src
    ├── map_array.hpp
    ├── mapset_main.cpp
    └── set_list.hpp
```

You should copy everything from the `CMakeLists.txt` and `CMakePresets.json` files into your own,
as well as the files `gtestmain.cpp` and the individual `gtests`.

## Build Instructions

```bash
# Produce the `build` folder with the presets provided for the homework:
cmake --preset default

# Build all targets at once:
cmake --build build

# Build only mapset_main.cpp:
cmake --build build --target mapset

# Build map_array gtests:
cmake --build build --target map_array_gtests

# Build set_list gtests:
cmake --build build --target set_list_gtests
```

To run the above targets after compiling them:

```bash
./build/mapset                  # Runs the 'main' function from src/mapset_main.cpp
./build/map_array_gtests        # Runs the 'map_array' gtests
./build/set_list_gtests         # Runs the 'set_list' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push` your
changes to your private repository, and then submitting the `hw9` branch to `Gradescope`. Or, you can
upload files directly, everything listed in the `src` folder above.
