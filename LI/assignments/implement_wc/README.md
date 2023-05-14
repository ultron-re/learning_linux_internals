# Implement a wc(word count) command with –l –w -c options
## Pre-requisites:

* Knowledge about system calls, How to read and understand ‘man pages’.
* Command line arguments, File operation system calls (open, read, write, close ..etc)
* Working of wc command

## Objective:
To understand and implement using basic system calls

## Requirements:
* Count the number of words, lines and characters(bytes) from files passed through command line. If more than one files passed, print individual count values and file name + calculate the total of all values and print at the end.
* If no file are passed wc will read from std input till end of file(Ctrl + D) then count lines, words and characters(bytes).
* Implement a word_count() function where you have to pass fd and 3 integer addresses(pass by refference). Int word_count (int fd, int *lines, int *words, int *bytes);
* Word_count function will read from the fd and calculates lines, words and bytes, then stores into respective addresses passed (don’t print values inside function).
* Main function will open the files in a loop and call word_count function depends upon number of files passed. Print values after calling functions in main.
      
      Eg: - ./word_count file1.txt file2.txt  
      for(I = 0; I < 2; i++)
      {
      	. . fd = open(…);
        word_count(fd, &lines, &words, &bytes);
      	print_values(…);
      . . }
      Print_total(…);

* If options passed [ -l –w –c ] print only respective values.
* Program should able to handle all possible error conditions.

## Sample execution:
1. When no arguments or file is  passed 
	./word_count
	Hai hello world
	1 3 16 lines words characters
    Reads from stdin till EOF (ctrl + d) and count lines words and bytes.
2. When one file passed
	./word_count file.txt
 	10 20 45
     Reads from file till EOF (ctrl + d) and count lines words and bytes.
3. When Mutilple files are passed
	./word_count f1.txt f2.txt
	5 7 40 f1.txt
	3 4 10 f2.txt
	8 11 50 total
4. When options passed (-l, -w, -c).
	./word_count file.txt –l –w
	10 20
     Prints according to given option. Option combination also should work.(Use getopt function )

