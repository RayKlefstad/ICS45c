# ICS 45C: Homework 0.2

Welcome to ICS 45C Homework 0.2! In this assignment, you will be modifying:

```bash
main.cpp
```

## Getting Started

To get started with this homework, you need to ensure that you have followed all of the
instructions in the `main` branch, and have cloned your repository to your local machine.
Once you have the folder on your local machine, you can run the following commands in your
`shell`:

```bash
# Move into the project folder:
cd <ProjectFolder>

# Change to the current homework branch:
git checkout hw0
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw0` with the following structure:

```bash
├── CMakeLists.txt
├── CMakePresets.txt
├── gtest
│   ├── gtestmain.cpp
│   └── hw_gtests.cpp
└── src
    └── main.cpp
```

You should copy everything from the CMakeLists.txt and CMakePresets files into your own, as well as
the files `gtestmain.cpp` and `hw_gtests.cpp`. This process will allow you to build and run the tests for this
assignment. If you do not follow this structure, you will not be able to use the `CMakeLists.txt`
file as provided!

## Coding

We will run the text editor `vim` (or `neovim` if you prefer) on the file `src/main.cpp`:

```bash
# To use vim, type this command:
vim src/main.cpp

# To use neovim, type this command:
nvim src/main.cpp
```

Once you are in `vim`/`nvim`, you will enter `insert` mode by pressing `i`. Then type the following program
and press `Esc` when you are done.

```cpp
#include <iostream>
using namespace std;
int main() {
  cout << "Hello World!" << endl;
  return 0;
}
```

Ensure that you have left `insert` mode by pressing `Esc`, then `write` and `quit` `vim` by typing either
`:wq` or `:x`. This should close `vim`/`nvim` with your changes made. Now, you can move on to
[Build Instructions](#build_instructions)!

## Build Instructions

If you are not already in a terminal (or SSH with OpenLab) from the above instructions, you will need
to open a terminal and move into your project folder as show below:

```bash
cd <YourProjectPath>    # So if we had the project in a folder named Projects: cd Projects/CS46-Template
```

Once you are in the project folder, use the following commands to build your project:

```bash
cmake --preset default  # Create a folder named `build` and run `CMake` to produce build files there
cmake --build build     # Will build all of the `targets` described in the `CMake` file
```

This will produce a folder named `build`, which will have two new executables you can run! First, we will
run your code you just wrote:

```bash
./build/hw              # Runs the `main` function from src/main.cpp
```

This should output the following message to your terminal:

```bash
Hello World!
```

Next, we will run `GTest`. This will run tests on your code and is also how we will be grading your assignments.
If you are not on OpenLab or have not installed `GTest` on your computer you are testing on, then skip this step
and move on to [Submission](#submission).

```bash
./build/hw_gtests      # Runs the tests you wrote in `gtest/hw_gtests.cpp`
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

All submissions will be done through [Gradescope](https://www.gradescope.com/). Open the Gradescope page
and select `Homework 0.2 Github`.

First, we need to make sure that we `commit` all of our changes we made! In a terminal inside your project folder,
run the following command:

```bash
git commit -a -m "Submission commit of HW0."
```

Now that we have committed out changes, we need to push them to `GitHub` so that `Gradescope` can see them. Your
local repository should have two remotes: `origin` which represents the repository at `RayKlefstad/ICS45c` and `my_repo`
which represents your own private repository. In order to push to your repository, use the command:

```bash
git push -u my_repo
```

This will set the default remote for this branch to `my_repo`. In particular, if you make any future changes and
want to resubmit them, you can create another `commit` with `git commit -a -m "Fixed bug XZY"` followed by `git push`.

Now on GradeScope, go to your Account Settings and link your GitHub account to GradeScope.

Then on Gradescope, go to the Homework 0.2 Github assignment, press the submit button, choose the `GitHub` option, 
and select your project and branch as shown below:

![](docs/submit_github.png)

Now the autograder will run and give you a score!
