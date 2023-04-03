# ICS 45C: Homework 0

Welcome to ICS 45C Homework 0! For more general instructions, please reference the `main` branch.
This repository will focus on instructions relevant to HW0.

## Getting Started

If you are using `GitHub`, then getting started is easy! You will clone this repository, then
checkout the `hw0` branch! If you have already `cloned` this project, then you can skip to
the [Checkout](#checkout) instructions.

### Clone

On `Linux` and `Mac`, you can open a new terminal. On Windows you will open `Git BASH` which
should have been installed following the instructions under the `main` branch. On OpenLab,
you are already in a terminal! Next, you will want to copy the repository link as shown in
the image below:

![](docs/clone_link.png)

And then in the terminal, type:

```bash
git clone <LinkCopiedAbove>  # For example: git clone git@github.com:klefstad/CS45C-Template.git 
```

There should now be a folder named `CS45C-Template`. We will move into that directory using the
command:

```bash
cd CS45C-Template
```

Once inside the directory, we will `checkout` the `hw0` branch!

### Checkout

In the same terminal as before, you will type:

```bash
git checkout hw0
```

You are now in the `hw0` branch! You can now make changes to your code as shown in the [Coding](#coding)
section below!

## Directory Structure

If you are not using `GitHub`, you will need to make a folder named `hw0` with the following structure:

```bash
├── CMakeLists.txt
├── gtest
│   ├── gtestmain.cpp
│   └── tests.cpp
└── src
    └── main.cpp
```

You should copy everything from the CMakeLists.txt file into your own, as well as the files `gtestmain.cpp`
and `tests.cpp`. This will allow you to build and run the tests for this assignment. If you do not
follow this structure, it is HIGHLY LIKELY your code will not work on Gradescope and you will receive a
0 for the assignment!

## Coding



## Build Instructions

If you are not already in a terminal (or ssh with OpenLab) from the above instructions, you will need
to open a terminal and move into your project folder as show below:

```bash
cd <YourProjectPath>    # So if we had the project in a folder named Projects: cd Projects/CS45C-Template
```

Once you are in the project folder, use the following commands to build your project:

```bash
cmake -B build        # Create a folder named `build` and run `CMake` to produce build files there
cmake --build build   # Will build all of the `targets` described in the `CMake` file
```

This will produce a folder named `build`, which will have two new executables you can run! First, we will
run your code you just wrote:

```bash
./build/hw            # Runs the `main` function from src/main.cpp
```

This should output the following message to your terminal:

```bash
Hello World!
```

Next, we will run `GTest`. This will run tests on your code and is also how we will be grading your assignments:

```bash
./build/gtest         # Runs the tests you wrote in `gtest/tests.cpp`
```

This should output:

```bash
[==========] Running 1 tests from 1 test suites.
[----------] Global test environment set-up.
[----------] 1 test from Hello
[ RUN      ] Hello.World
[       OK ] Hello.World (0 ms)
[----------] 1 test from Hello (0 ms total)

[----------] Global test environment tear-down
[==========] 1 tests from 1 test suites ran. (0 ms total)
[  PASSED  ] 1 tests.
```

Congratulations! You are now ready to [submit](#submission) your homework!

## Submission


