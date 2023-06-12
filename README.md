# ICS 45C: Homework 1

Welcome to ICS 45C Homework 1! Instructions from this point on will assume the use
of `GitHub`. If you are working without `github`, then copy the
[Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, you will need to `checkout` this homework branch.

```bash
# Checkout hw1
git checkout hw1
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw1` with the following structure:

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
    ├── convert_knots.h
    ├── letter_count.cpp
    ├── letter_count.h
    ├── stack.cpp
    └── stack.h
```

You should copy everything from the `CMakeLists.txt` and `CMakePresets.json` files into your own,
as well as the files `gtestmain.cpp` and the individual `gtests`. This will allow you to build and run the
tests for this assignment. If you do not follow this structure, you will not be able to use the
`CMakeLists.txt` file as provided!

## Build Instructions

If you are not already in a terminal (or ssh with OpenLab) from the above instructions, you will need
to open a terminal and move into your project folder as show below:

```bash
cd <YourProjectPath>    # So if we had the project in a folder named Projects: cd Projects/CS45C-Template
```

This time, we are going to go into a little more detail on how `CMake` works. The `CMake` process is
basically comprised of two steps: producing project build files and actually building the executable for
the project. To produce the build files for our project we run the first command:

```bash
# Build Generator Command
cmake --preset deafult # Create a folder named `build` and run `CMake` to produce build files there
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
`knot` (which is the `convert_knots.cpp` file), `knot_gtests` (`knot_gtests.cpp`), `stack` (`stack.cpp`)
`stack_gtests` (`stack_gtests.cpp`), `count` (`letter_count.cpp`), and `count_gtests` (`letter_count.cpp`).
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
(`cmake --build build <--target target>`) every time you make changes to your `*.cpp` or `*.h`
files. For example, if you build `knot_gtests.cpp`, and find out that your conversion does
not work for numbers above `10`, you will need to change `convert_knots.h`. Once you have
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

All submissions will be done through [Gradescope](https://www.gradescope.com/). Open the Gradescope page
and select `HW1`. Now if you are using a `GitHub` account, follow the [GitHub Submission](#github-submission)
instructions, otherwise follow the [File Submission](#file-submission) instructions.

### GitHub Submission

First, we need to make sure that we commit all of our changes we made! In a terminal inside your project folder,
run the following command:

```bash
git commit -a -m "Submission commit of HW1."
```

Now that we have committed out changes, we need to push them to `GitHub` so that `Gradescope` can see them.

```bash
git push
```

Now on Gradescope, press the submit button, choose the `GitHub` option, and select your project and branch
as shown below:

![](docs/cs45c_hw1_github.png)

Now the autograder will run and give you a score!

### File Submission

On `Gradescope`, press the `submit` button and it will bring up the following window:

![](docs/submit_files.png)

Then you will drag and drop the `convert_knots.h`, `convert_knots.cpp`, `letter_count.h`,
`letter_count.cpp`, `stack.h`, and `stack.cpp` files from your `src` folder
(or wherever you have made this file) and press upload. As these are the only files we are changing (for the homework,
not for testing), they should be the only files that you upload!
