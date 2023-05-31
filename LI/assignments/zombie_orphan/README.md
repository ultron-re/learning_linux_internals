## Description :

Create a scenario to make zombie process become orphan, print status of each state.

## Pre-requisites:

* Knowledge about system calls, How to read and understand ‘man pages’.
* Good knowledge about processes, zombie and orphan.
* Working of fork system call.
## Objective:

* To understand different states of a process.

## Requirements: 

1. Create a child process and print status that process is running
2. After some time print status that process is zombie state
3. After some time print zombie process cleared by init.
4. To print status use help of /proc//status file.
	For eg: if child pid is 1234, open file /proc/1234/status and print first 3 lines
5. If that file is not available means that process is cleared.

## Sample execution:

1. ./zomb_orph

A child created with pid 1234

Name:  ./zomb_orph

State: S (sleeping)

Name:  /zomb_orph   (After some time)

State: Z (zombie)

Process 1234 cleared by init 
