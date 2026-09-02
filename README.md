## COMP 211: Lab 00

## Abstract

This lab is intended to give you practice working in a command-line interface shell. In the process of completing this lab, you will be using the `gcc` compiler to compile your programs into executable binaries. Additionally, you will use `git` to form commits, push your changes to GitHub, and submit for autograding on Gradescope.

## Setup
Before beginning each part, read the entire section and complete its Guided Reading questions on [Gradescope](https://www.gradescope.com/courses/1349648/assignments/8541234/). Only then should you proceed with the setup steps and implementation.

### Cloning Your Repository

1. **Open your repository on GitHub**: If you are reading this document, you are already on the correct page.

2. **Copy the repository URL**: Click the green Code button near the top right of the page. In the dropdown menu, make sure the HTTPS option is selected (switch to it if necessary), then copy the URL.

3. **Clone the repository**: In your Docker container, navigate to the `workdir` directory. Run the following command, replacing with the URL you just copied:

```
learncli$ git clone <url>
```

This will clone the repository into the `workdir` directory within your Docker container.

### Configure username and email
When you use Git to track changes to your code or collaborate on a project, it keeps a history of who made each change. This history is stored in the form of commits, which are like snapshots of your work at specific points in time. Each commit includes information about the person who made the change. To configure the username and email that will be attached to your commits, run the following two commands.

```
learncli$ git config --global user.email "you@example.com"
learncli$ git config --global user.name "Your Name"
```

### Configure Default Branch Name

Next, we will configure the default branch name to `main`. Run the following command.

```
learncli$ git config --global init.defaultBranch main
```


## Part 0. Hello, world!
**Before carrying out the steps below, read through the section and complete its guided reading questions on [Gradescope](https://www.gradescope.com/courses/1349648/assignments/8541234/) first!**

In the terminal window, navigate to your `Lab00` directory using the following command:

```
learncli$ cd <lab00-yourgithubusername>
```

Use the `tree` command to view your current file tree.

```
learncli$ tree
.
├── 1-bash-comments
│   ├── 00-verbatim.sh
│   ├── 01-comments.sh
│   ├── 02-strings.sh
│   └── strip-comments.c
└── README.md
```

Inside your `lab00` directory, make a new directory named exactly `0-hello-world`. Now your tree should look like this:

```
learncli$ tree
.
├── 0-hello-world
├── 1-bash-comments
│   ├── 00-verbatim.sh
│   ├── 01-comments.sh
│   ├── 02-strings.sh
│   └── strip-comments.c
└── README.md
```

Change your working directory to be this new subdirectory. 

Next, create a new file named `hello.c` using the following command:

```
learncli$ touch hello.c
```

Once the file is created, open it in VS Code to start editing.

Each source file in COMP211 will begin with the standard header comment below. Note this header is checked by the autograder for an exact match. Please be sure to format your PID as a single 9-digit number with no spaces nor dashes. Additionally, be sure your capitalization and punctuation of the honor code pledge are correct. Since we do grade manually for style we do not include names on code listings to avoid biasing the grading.

~~~c
// PID: 9DigitPidNoSpacesOrDashes
// I pledge the COMP211 honor code.
~~~

### `hello.c` Requirements

Your `hello.c` program should meet the following requirements:

1. Print two lines of output.
- The first line should print `hello, world`.
- The second line should print `welcome to c!`.
2. Define `main` with a return type of `int`.
- In COMP 211, all functions should have an explicitly defined return type.
Since `main` returns an integer exit status, its return type should be `int`.
3. Have `main` return `EXIT_SUCCESS`.
- Add `#include <stdlib.h>` at the top of your program so that you can use the `EXIT_SUCCESS` constant.
- At the end of `main`, return `EXIT_SUCCESS` to indicate that the program completed successfully.
- We will explore exit statuses in more detail later this semester.

### Compiling and Executing

You can compile your program with the following shell command:

~~~bash
learncli$ gcc -Wall -Wextra -Wpedantic hello.c
~~~

Here is a breakdown of the above command:

**gcc**: This is the GNU Compiler Collection, a tool that compiles your C code into an executable program.

**-Wall**: This option turns on all **common** warning messages during the compilation process. If you **do not** include this option, the compiler will only show critical errors that prevent your program from compiling (like syntax errors). 

**-Wextra:** Enables additional warnings not included with `-Wall`. These tend to be more situational, such as:
- Detecting unused function parameters
- Pointing out suspicious pointer comparisons
- Warning about missing initializers in structs

They’re not always errors, but they often catch subtle bugs or sloppy code.

**-Wpedantic:** Enforces strict ISO C standard compliance. It warns about:
- Use of compiler extensions beyond the standard
- Implicit type conversions that could be unsafe
- Extra commas, non-standard keywords, or language constructs gcc normally accepts quietly

This is especially useful if you want your code to be maximally portable and standards-conforming.

**hello.c**: This is the name of the source file you’re compiling. 

If there are no errors, the above command will generate an executable file, named `a.out` by default. If warnings are present, the executable will still be created. Only critical errors will stop the compilation process and prevent the executable from being generated. Even though the executable is generated when warnings exist, you should always resolve warnings before running your program. Warnings often highlight issues that are likely to cause bugs, so fixing them will save you time debugging in the future!

To execute your program, run the following command:

```
learncli$ ./a.out
```

Once your program compiles without warnings and meets the `hello.c` requirements, you can continue on.

### Make a Commit
Follow these steps to form a commit with your `hello.c` file and push it to your GitHub repository. Remember, you should not include `a.out` in your commit, as it's bad practice to store compiled files in source code repositories.

1. Stage your file.

```
learncli$ git add hello.c
```

2. Verify that it is staged. 

```
learncli$ git status
```

3. Form your commit with a clear and descriptive message.

```
learncli$ git commit -m "Your commit message."
```

4. Push your commit to GitHub.

```
learncli$ git push
```

5. Open your GitHub repository in a web browser and confirm you see the `0-hello-world/hello.c` file in your repository.

### Submitting the Project

You will submit to autograding on Gradescope via a GitHub integration. You must make a commit and push your commit to GitHub in order to submit on Gradescope (instructions for doing this are above).

Navigate to the lab assignment on Gradescope. Choose `GitHub` as your submission method. Then, select your respository from the repository selector and `main` from the branch selector. Once uploaded, the autograder should run with feedback shortly.

Make sure you earn full autograding credit on the `0 - hello.c` tests before continuing to Part 1.  

### Common Errors
If the autograder is failing at this step, it is most likely because your PID and honor code pledge are not formatted correctly. Please see directions above on how to format.

## Part 1 - Stripping `bash` Comment

**Before carrying out the steps below, read through the section and complete its guided reading questions on [Gradescope](https://www.gradescope.com/courses/1349648/assignments/8541234/) first!**

In the next part of this lab, you will write a program that reads from standard input and strips out `bash`-style comments. In the `bash` scripting language, comments begin with a `#` symbol and continue to the end of a line.

Your program should read input character-by-character. It should print out all characters verbatim until a comment is encountered and suppress further output until the end of a line is reached. If the comment character (a hash symbol `#`), is found inside of a double quoted string literal, then the comment character should be ignored.

**Example 1:**

Input:
```
echo this is code # this is a comment
# this entire line is commented out
echo another command # another comment
```

Expected Output:
```
echo this is code 

echo another command 
```

**Example 2:**

Input:
```
echo "this is a string"
echo "so is # this one"
echo "##s in strings are ok" # but this is commented out
```

Expected Output:
```
echo "this is a string"
echo "so is # this one"
echo "##s in strings are ok" 
```

Start by navigating back to the base directory of `Lab 00`, which is the parent directory of `0-hello-world`. Use the `cd` command to move to the appropriate directory.

Next, change your working directory to `1-bash-comments` (this directory already exists).
Run the `ls` command in this directory to list the files. You'll notice several sample script files for testing, which will be explained shortly.

Currently, the program reads input one character at a time using `getchar` and immediately prints each character using `putchar`. Your task is to modify this behavior so that the program removes Bash comments from the input while preserving all other characters, as described above. It is recommended that you use a state variable (as seen in HW1 to complete this task).

### Resources to Reference
Lectures
- CL02
- CL03

Homework
- HW1 (especially the questions on state variables)

Readings
- RD01
- RD02

### Testing

There are three test inputs provided for you: `00-verbatim.sh`, `01-comments.sh`, and `02-strings.sh`. These test scripts are written in order of difficulty. You are encouraged to get your program to match the first file's expected results before moving to the next.

#### Viewing the Test Files
To view the contents of each file, you can use the `cat` command. For example, to view `00-verbatim.sh`, run the following command:

```
learncli$ cat 00-verbatim.sh
```

This command will display the contents of `00-verbatim.sh` in your terminal, as shown below:
 

```
echo demo script has no comments
echo nor string literals
```

#### Testing your program
To test your program with `00-verbatim.sh`, use the following command:

```
learncli$ ./a.out < 00-verbatim.sh
```

Your program is expected to produce the following output for the input `00-verbatim.sh`:

```
echo demo script has no comments
echo nor string literals
```

#### Proceeding to Other Tests

Follow the same steps to test `01-comments.sh` and `02-strings.sh`.

### Debugging

To debug your program in VSCode, two configuration files have been provided for you: `launch.json` and `tasks.json`. When you launch the debugger in VSCode, `tasks.json` will compile your program, and `launch.json` will start the debugger. 

#### Understanding `tasks.json`
The `tasks.json` file in Visual Studio Code defines custom tasks that automate repetitive processes, such as building a C program. In this case, we will use it to configure a build task for compiling files using `gcc`.

Let’s examine two key parts of this configuration file:

**command:**

Here, `gcc` refers to the GNU Compiler Collection (GCC), the compiler that translates your C source code into an executable program.

**args**

These are the arguments given to `gcc` that tell it how to compile your file:

```
"args": [
     "-g",
    "-Wall",
    "-Wextra",
    "-Wpedantic",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}"
],
```

If you are debugging a file named `strip-comments.c`, the equivalent `gcc` command executed by this configuration would be:

```
learncli$ gcc -g -Wall -Wextra -Wpedantic strip-comments.c -o strip-comments
```

**Explanation of Each Argument:**

- `-g`: Includes debugging information in the compiled output, allowing compatibility with debuggers like GDB.
- `-Wall`: Enables a broad set of common warnings that help catch likely mistakes (e.g., unused variables, uninitialized values).
- `-Wextra`: Turns on additional warnings not covered by `-Wall`, such as unused parameters or suspicious comparisons.
- `-Wpedantic`: Issues warnings for code that does not strictly conform to the C standard, helping improve portability and correctness.

- `${file}`: Refers to the file you have open in VS Code; this file will be compiled.

- `-o`: Specifies the name of the output file.

- `${fileDirname}/${fileBasenameNoExtension}`
    - `${fileDirname}` refers to the folder containing the current file.
    - `${fileBasenameNoExtension}` is the file name without its extension.
    - Together, they ensure the compiled executable has the same name as the source file and is placed in the same folder.

#### launch.json

The `launch.json` file in Visual Studio Code defines how the debugger should run and interact with your code. 

Let’s examine two key parts of this configuration file:

**"program" Field:** 

```
"program": "${fileDirname}/${fileBasenameNoExtension}"
```

This dynamically points to the executable of the file you’re working on.

- `${fileDirname}` refers to the directory containing the file you’re editing.
- `${fileBasenameNoExtension}` refers to the file name without its extension.

**"args" Field:**

```
"args": [
    "-lc",
    "\"${fileDirname}/${fileBasenameNoExtension}\" < \"${fileDirname}/test\""
],
```

This specifies arguments passed to the program when debugging.

In this case, the debugger will redirect the contents of the file `test` into the program’s standard input. If you want to redirect the contents of `00-verbatim.sh`, then change the word `test` to `00-verbatim.sh`.

#### Steps to Debug
**Debugging**

When you would like to debug other inputs, edit `launch.json` and replace `00-verbatim.sh` with the desired file.

### Submitting to Gradecope

Once you are ready to submit to autograding, add `strip-comments.c` to stage and make a commit. Push to GitHub and resubmit to Gradescope.

Remember to include your PID and honor code at the top of the file! **Make sure they are formatted correctly!!!**

## Part 2 - Character Counting

**Before carrying out the steps below, read through the section and complete its guided reading questions on [Gradescope](https://www.gradescope.com/courses/1349648/assignments/8541234/) first!**

For the final part of this lab, you will write a program that keeps counts of alphabetical characters from standard input and, after `EOF` is detected, displays a summary of the number of occurrences, percentage, and a vertically-oriented histogram of relative frequencies.

Here is an example of a simple input and your expected output:

~~~
learncli$ echo "Hello, World!" | ./a.out
Counts:
d: 1
e: 1
h: 1
l: 3
o: 2
r: 1
w: 1

Percents:
d: 10.0%
e: 10.0%
h: 10.0%
l: 30.0%
o: 20.0%
r: 10.0%
w: 10.0%

Chart:
           |              
           |              
           |              
           |              
           |  |           
           |  |           
           |  |           
   ||  |   |  |  |    |   
   ||  |   |  |  |    |   
   ||  |   |  |  |    |   
abcdefghijklmnopqrstuvwxyz
~~~

The formatting of each area is expected to match exactly.

To begin, change your working directory to be back at Lab 00's base. Then, make a new directory named `2-char-count`, and in that directory create a file named `char-count.c`

### 2.1 - Counts

Your program should count occurrences of alphabetical, English letters `a` through `z`, case insensitive. Ignore all non-alphabetical input characters. Continue processing input until EOF is detected. When the `EOF` character is encountered, your program should display the counts of _only_ the alphabetical characters with at least one occurrence. The expected format of this output is, for each character and count on its own line: `<char>: <count>`.

Your code should be modular, with each task handled by a specific function. For example:
1. A function to process the input character-by-character.
2. A function to count occurrences of alphabetical characters.
3. A function to display the results in the specified format.

Writing modular code is an important skill you need to develop as a programmer because it’s the foundation of writing clean, maintainable, and professional-quality code. By practicing modular design now, you’ll become better at tackling complex problems, collaborating on larger projects, and writing code that others (and future you!) can easily understand and work with.


#### Testing
You can begin testing your code with the example below:

```
learncli$ echo "Hello, World!" | ./a.out
Counts:
d: 1
e: 1
h: 1
l: 3
o: 2
r: 1
w: 1
```
Next, think of different input strings that cover the various edge cases and ensure that your program handles them properly. For example, try a string with a combination of letters from the English alphabet and special characters, then try a string with only special characters, etc. You can manually verify that your program produces the correct output.

**You must fully implement 2.1 before moving on to 2.2.**

### 2.2 - Percents

After outputting character counts, your program should output each character's percentage of the alphabetical characters encountered. For example, in the example input "Hello, World!" there were 10 alphabetical characters and 3 of them were the letter `l`, so `l`'s percentage was `30.0%`. The expected format of this output is, for each character and percentage on its own line, each percentage should have _one digit after the decimal point_ and be followed by the `%` symbol: `<char>: <percent>%`.

Your code should be modular, with each task handled by a specific function. In the previous part, a suggested breakdown of functions was provided, but for this part, it’s up to you to determine how to divide the problem into manageable pieces. Think critically about the tasks your program needs to perform and create functions that encapsulate each one clearly and effectively.


#### Testing
To test your program, you can use the same test cases that you came up with for Part 2.1.

**You must fully implement 2.2 before moving on to 2.3.**

### 2.3 - Frequency Bar Chart

The final challenge of this lab is to produce a _vertical_ bar chart of relative frequencies, as shown in the prior example output. **It should be _scaled_ such that the tallest bar in your chart is _always_ 10 lines tall.** 

- Use the vertical bar character `|` when drawing the bars. 
- When the height of a bar has a decimal component, you should always _truncate_ it (always round down). 
- Unlike the previous two parts, there should be an entry for every alphabetical character to form the x-axis of the chart as shown in the previous example, even if it has no bar.

For example, in the example input "Hello, World!", `l` is the most frequently occurring character, so `l`'s bar will be 10 lines tall. `o` appears twice, while `l` appears 3 times, so `o`'s bar will be 2 / 3 * 10 = 6.67 -> 6 lines tall. Refer back to the example at the top of this section to see the full chart.

#### Testing
To test your program, you can use the same test cases that you came up with for the previous parts.

### Submitting to Gradescope
Once you are ready to submit to autograding, add `char-count.c` to stage and make a commit. Push to GitHub and resubmit to Gradescope.

Remember to include your PID and honor code at the top of the file!

### Resources to Reference
Lectures
- CL02
- CL03

Homework
- HW1 (especially the questions on printing)

Readings
- RD01
- RD02

## Grading (25 points)

(20 Points) Autograded Functionality: feedback on this is provided as soon as Gradescope grading completes. You are encouraged to continue improving your code resubmitting until achieving full credit.

(5 points) Lab guided reading questions (posted on Gradescope).

(5 points) Style: manually graded by course staff, after the late deadline, on the following criteria:

 - All magic numbers are defined as constants (0, 1, and 100.0 are acceptable number literals to use in code)
 - Part 2 must keep character counts using arrays, not individual variables per letter _and_ be organized into simpler functions, not entirely written in the `main` function
 - Meaningful names of variables and functions are chosen
 - No global variables
 - Do not commit unnecessary files, such as system files (`.DS_Store`) or build artifacts (`a.out`).
- Your commit messages must provide clear and meaningful descriptions of the work being added or changed. A good commit message helps others (and your future self) quickly understand the purpose of a change without needing to dig into the code.
    - Examples of good commit messages:
        - Add function to count occurrences of alphabetical characters
        - Fix bug in EOF handling when reading input
    - Examples of bad commit messages:
        - Update code
        - Checkpoint
        - Added function
        - Fixed bug

## Honor Code and Collaboration

No collaboration is permitted on this assignment beyond the undergraduate teaching assistants working for the course. No external resources should be used beyond the course textbook. The use of ChatGPT is not allowed.
