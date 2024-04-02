# ICS 45C: Homework 0.2

Welcome to ICS 45C Homework 0.2! In this assignment, you will be modifying and submitting

```bash
main.cpp
```
by following all the steps below. 

## Getting Started

To get started with this Homework 0.2, be sure that you have followed all of the instructions in the `main` branch README, and have cloned the public course repository to your own private one on Openlab (and pushed to your own private GitHub repository).

Now, log in to Openlab, and move into the directory you created for this course:

```bash
# Move into the course directory, i.e., your ICS45c directory on Openlab
cd ICS45c

# Change to the current homework branch:
git checkout hw0
```

## Directory Structure

Our testing framework has the following structure in `hw0`:

```bash
├── CMakeLists.txt
├── CMakePresets.txt
├── gtest
│   ├── gtestmain.cpp
│   └── hw_gtests.cpp
└── src
    └── main.cpp
```
Note that the files with your code are in the subdirectory `src`, and the files with your tests are in the subdirectory `gtest`. To edit the files, you **must specify their path**, e.g. 
```
vim src/main.cpp
vim src/hw_gtests.cpp
```
If you move into `src` before editing `main.cpp`, you must remember to move back up into `ICS45c` before using the `git` commands. We recommend and give examples below of typing the subdirectory paths instead. 

*TIP: Use tab completion of directory and filenames to reduce typing.*

## Coding

We will now run the text editor `vim` (or `neovim` if you prefer) to modify the file `src/main.cpp`:

```bash
# To use vim, type this command:
vim src/main.cpp

# To use neovim, type this command:
nvim src/main.cpp
```

Once you are in `vim`/`nvim`, enter `insert` mode by pressing `i`. Then type the following program, and press `Esc` when you are done.

```cpp
#include <iostream>
using namespace std;
int main() {
  cout << "Hello World!" << endl;
  return 0;
}
```

Ensure that you have left `insert` mode by pressing `Esc`, then `write` and `quit` `vim` by typing either `:wq` or `:x` to close `vim`/`nvim` with your changes made. Now, you can move on to [Build Instructions](#build-instructions)!

## Build Instructions

When logged in to Openlab, and in your course directory (e.g., `ICS45c`)  use the following commands to build your project:

```bash
cmake --preset default  # Create a folder named `build` and run `CMake` to produce build files there
cmake --build build     # Will build all of the `targets` described in the `CMake` file
```

These commands will produce a folder named `build`, which will have two new executables you can run! 

First, we will run your code you just wrote:

```bash
./build/hw    # Runs the `main` function from src/main.cpp
```

This command should output the following message to your terminal:

```bash
Hello World!
```

Next, we will run `GTest`. This procedure will run tests on your code and is the same way we will grade your homework assignments.

```bash
./build/hw_gtests    # Runs the tests in `gtest/hw_gtests.cpp`
```

This command should output:

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

## Commit and push to your GitHub

Next, we need to make sure that we `commit` all of our changes we made! In your course directory on Openlab, run the following command:

```bash
git commit -a -m "Submission commit of HW0."
```

Now that we have committed our changes, we need to `push` them to `GitHub` so that `GradeScope` can upload them. Your Openlab repository should have two remotes: `origin` which represents the public GitHub repository at `RayKlefstad/ICS45c` and `my_repo` which represents your own private GitHub repository for your own code. To push to *your* GitHub repository, use the command:

```bash
git push -u my_repo
```

This command will set the default remote for this branch to `my_repo`. If you make any future changes and want to resubmit them, you can create another `commit` with `git commit -a -m "Fixed bug XZY"` followed by `git push`.

Congratulations! You are now ready to [submit](#submission) your homework!

## Submission

All submissions are done on [GradeScope](https://www.gradescope.com/). 

On GradeScope, go into your **Account Settings** and **link your GitHub account to GradeScope**.

Then on the course GradeScope, go to the `Homework 0.2 Github` assignment, press the `Submit` button, choose the `GitHub` option,  and select your project and branch as shown below:

![](docs/submit_github.png)

Now the autograder will run and give you a score!
