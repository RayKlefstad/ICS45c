# ICS 45C: Homework 1

Welcome to ICS 45C Homework 1! These instructions will continue to help you use
`GitHub` and the GTest files provided here in the following
[Directory Structure](#directory-structure).

## Getting Started

To get started with Homework 1, you will need to `checkout` this Homework 1 branch. First,
make sure you're up to date with our repository by running:

```bash
git fetch --all
```

Then you can check out the homework 1 branch with:

```bash
# Checkout hw1
git checkout hw1
```

If you accidentally (or intentionally) checked out this branch before the official release of the homework,
you may have an old version. In that case, you can pull the most recent version with:

```bash
git pull
```

## Directory Structure

```bash
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   ├── count_gtests.cpp
│   ├── knot_gtests.cpp
│   └── stack_gtests.cpp
└── src
    ├── convert_knots.cpp
    ├── convert_knots.hpp
    ├── letter_count.cpp
    ├── letter_count.hpp
    ├── stack.cpp
    └── stack.hpp
```

## Build Instructions

If you are not already in a terminal (i.e., SSH with OpenLab), you will need
to open a terminal and move into your project folder as show below:

```bash
cd <YourProjectPath>    # Most likely, this would be: cd ~/ICS45c
```

This time, we are going to go into a little more detail on how `CMake` works. The `CMake` process is
basically comprised of two steps: producing project build files, and actually building the executable for
the project. To produce the build files for our project we run the first command:

```bash
# Build Generator Command
cmake --preset default # Create a folder named `build` and run `CMake` to produce build files there
```

This command should only need to be run once! If you change `CMakeLists.txt` or add new files, you will need to run
this command again to update the build instructions.
Once you have the `build` folder and files, you will want to build the actual program. This can be done two ways.
You can either build everything at once:

```bash
# Target Build Command
cmake --build build   # Will build all of the `targets` described in the `CMake` file
```

Or you can pick a specific target to build. For this homework, there are 6 possible `targets`:
* `knot` (which is the `convert_knots.cpp` file),
*  `knot_gtests` (`knot_gtests.cpp`),
*  `stack` (`stack.cpp`)
* `stack_gtests` (`stack_gtests.cpp`),
* `count` (`letter_count.cpp`), and
* `count_gtests` (`letter_count.cpp`).
  
These `targets` are defined in the `CMakeLists.txt` file as `project(<name> CXX)`, so if you want to find
the `targets` yourself, you can always check that file. We will also always give you the available `targets`
in this class. Below are the individual `target` commands you can run:

```bash
# Build only convert_knots.cpp:
cmake --build build --target knot

# Build only Knot tests:
cmake --build build --target knot_gtests

# Build only stack.cpp:
cmake --build build --target stack

# Build only Stack tests:
cmake --build build --target stack_gtests

# Build only letter_count.cpp:
cmake --build build --target count

# Build only the Letter Count tests:
cmake --build build --target count_gtests
```

NOTE: If you build all targets with the `cmake --build build` command, you DO NOT need to
run the individual commands. The advantage of running the individual build commands is
being able to build only the parts you want to test. Also, unlike the Build Generator 
Command (`cmake --preset default`), you will need to run the Target Build Command 
(`cmake --build build <--target target>`) every time you make changes to your `*.cpp` or `*.hpp`
files. For example, if you build `knot_gtests.cpp`, and find out that your conversion does
not work for numbers above `10`, you will need to change `convert_knots.hpp`. Once you have
changed it, when you want to test it again, you can run:

```bash
cmake --build build --target knot_gtests
```

And it will build just that code with your updated changes! Very handy for testing one task
at a time.

After you have built your intended target, you will have three new executables you can run!
You will have `hw` which will be the code from `main.cpp`, `knot_gtests`, and `stack_gtests`.
You can run each one with the commands shown below:

```bash
./build/knot          # Runs the 'main' function from src/convert_knots.cpp
./build/stack         # Runs the 'main' function from src/stack.cpp
./build/count         # Runs the 'main' function from src/letter_count.cpp
./build/knot_gtests   # Runs the 'knot' gtest set of tests
./build/stack_gtests  # Runs the 'Stack' gtests
./build/count_gtests  # Runs the 'Letter Count' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

All submissions will be done through [GradeScope](https://www.gradescope.com/). Open the GradeScope page
and select `HW1`.

First, we need to make sure that we commit all of our changes we made! In a terminal inside your project folder,
run the following command:

```bash
git commit -a -m "Submission commit of HW1."
```

Now that we have committed out changes, we need to push them to `GitHub` so that `Gradescope` can see them.

```bash
git push -u my_repo
```

Now on GradeScope, press the submit button, choose the `GitHub` option, and select your project and branch
as shown below:

![](docs/cs45c_hw1_github.png)

Now the autograder will run and give you a score!

