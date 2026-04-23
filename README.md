# 🐚 Simple Shell

## 📌 Description

**Simple Shell** is a minimalist UNIX command line interpreter written in C.
It replicates the basic behavior of `/bin/sh`, focusing on understanding how a shell works internally.

The program reads user input, parses commands, resolves executable paths, creates child processes, and executes programs using system calls.

---

## ⚙️ Features

### Task 0.1
- Displays a prompt and waits for user input
- Executes simple commands (no arguments initially)
- Handles `Ctrl + D` (EOF) to exit the shell
- Prints error messages when commands are not found

### Task 0.2
- Supports commands with arguments
- Implements PATH resolution to locate executables
- Prevents unnecessary `fork()` if command does not exist

### Task 0.3
- Built-in command:
  - `exit` → exits the shell cleanly

### Task 0.4
- Built-in command:
  - `env` → prints the current environment variables

---

## 🧠 Learning Objectives

This project is designed to help understand:

- How a shell works internally
- Process creation using `fork()`
- Executing programs with `execve()`
- Waiting for processes using `wait()` / `waitpid()`
- What PID and PPID are
- How environment variables are handled
- How the PATH variable is used to locate executables
- Difference between system calls and library functions
- The concept of EOF (End Of File)
- Basic UNIX process lifecycle

---

## ⚙️ Requirements

- Ubuntu 20.04 LTS
- gcc compiler with flags:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
- Code must follow Betty style
- No memory leaks allowed
- Maximum 5 functions per file
- Include guards for all header files

🚀 Usage

Compilation: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Run in interactive mode
./hsh
($) /bin/ls
($) env
($) exit

Run in non-interactive mode
echo "/bin/ls" | ./hsh
cat file.txt | ./hsh


🧾 Built-in Commands
Command	Description
exit	Exit the shell
env	Print environment variables

⚠️ Limitations

This shell does NOT support:

Pipes (|)
Redirections (>, <, >>)
Command chaining (;)
Background execution (&)
Quoting (", ')
Wildcards (*)
Shell scripting features

This is a learning shell, not a production shell.

🧪 Behavior
The shell behaves like /bin/sh in terms of execution flow
Works in both interactive and non-interactive modes
Error messages mimic /bin/sh format, using argv[0]

Example:

./hsh: 1: qwerty: not found


🔄 Execution Flow
[User Input]
      ↓
[Read line (getline)]
      ↓
[Parse command]
      ↓
[Check PATH]
      ↓
[If valid → fork()]
      ↓
[Child → execve()]
      ↓
[Parent → wait()]
      ↓
[Return to prompt]

📊 Flowchart

🧩 Insert your flowchart here

[ PLACE YOUR FLOWCHART IMAGE OR ASCII DIAGRAM HERE ]


💻 Authors

This project is developed for educational purposes to understand UNIX shell internals and system programming concepts.

📜 License

This project is for academic use only by holberton school
