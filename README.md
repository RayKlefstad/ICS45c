# ICS 45C: Homework 8

Welcome to ICS 45C Homework 8! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw8`, then push the `hw8` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Fetch updates:
git fetch public

# Checkout hw8 from the public branch:
git checkout hw8

# Push the newly checked out branch to your private repository:
git push -u origin hw8
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw8` with the following structure:

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── compute_grades_gtests.cpp
│   ├── gtestmain.cpp
│   ├── mapset_gtests.cpp
│   └── process_numbers_gtests.cpp
└── src
    ├── compute_grades.cpp
    ├── compute_grades.hpp
    ├── compute_grades_main.cpp
    ├── gradebook.txt
    ├── mapset.cpp
    ├── mapset.hpp
    ├── mapset_main.cpp
    ├── process_numbers.cpp
    ├── process_numbers.hpp
    ├── process_numbers_main.cpp
    ├── rand_numbers.txt
    ├── sample_doc.txt
    └── stopwords.txt
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

# Build only process_numbers_main.cpp:
cmake --build build --target process_numbers

# Build only compute_grades_main.cpp:
cmake --build build --target compute_grades

# Build mapset gtests:
cmake --build build --target mapset_gtests

# Build process_numbers gtests:
cmake --build build --target process_numbers_gtests

# Build compute_grades gtests:
cmake --build build --target compute_grades_gtests
```

To run the above targets after compiling them:

```bash
./build/mapset                  # Runs the 'main' function from src/mapset_main.cpp
./build/process_numbers         # Runs the 'main' function from src/process_numbers_main.cpp
./build/compute_grades          # Runs the 'main' function from src/compute_grades_main.cpp
./build/mapset_gtests           # Runs the 'mapset' gtests
./build/process_numbers_gtests  # Runs the 'process_numbers' gtests
./build/compute_grades_gtests   # Runs the 'compute_grades' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push` your
changes to your private repository, and then submitting the `hw8` branch to `Gradescope`. Or, you can
upload files directly, everything listed in the `src` folder above.
