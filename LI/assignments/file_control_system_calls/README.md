## Pre-requisites:

* Knowledge about system calls, How to read and understand ‘man pages’.
* Command line arguments, File operation system calls (open, read, write, close ...etc)
* Working of fcntl system calls.
## Objective:

* To understand and implement using advanced system calls.
* Understand the need of file synchronization between processes.
## Requirements:

* Using fcntl system call synchronize a file between two processes (parent and child process).
* Pass the file name using command-line arguments.
* Before writing to file check file is locked, in case it is locked must wait the process until its unlocked.
* If its unlocked, lock file and continue with writing.
* Both process will do the same procedure.
## Sample Execution:
1.When no arguments are passed

./a.out

Insufficient arguments

Usage:- ./a.out filename
2. ./a.out f1.txt
PARENT PROCESS: locked file

PARENT PROCESS: writing to file f1.txt

PARENT PROCESS: unlocked file

CHILD PROCESS: locked file

CHILD PROCESS: writing to file f1.txt

CHILD PROCESS: unlocked file
