# operating-system

Question 1:

Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the user. For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive integer is passed on the command line.

Description:

Fork system call is used to create a child process of the current running process and it runs concurrently with the parent process. The program takes a number from the command line argument and that becomes the starting number of the sequence.
The function call fork () can return 3 values:
Positive – It is when the parent process is running. So in the program we require that the child process is not orphaned. To insure that we invoke the wait () system call.  It blocks the parent process until the child process has completed execution. 
Zero – It is when the child process is executing. Here we perform the task that is to be executed by the child process, i.e., the sequence will be generated.
Negative – It is returned when an error has occurred and the child process is not created successfully.

Test cases:

1.	Case 1:
Input:  8
Expected Output: 8 4 2 1
2.	Case 2:
Input:  -10
Expected Output: Error message
3.	Case 3:
Input: abc
Expected Output: Error message

Question 26:

Design a file-copying program named filecopy using ordinary pipes. This program will be passed two parameters: the name of the file to be copied and the name of the copied file. The program will then create an ordinary pipe and write the contents of the file to be copied to the pipe. The child process will read this file from the pipe and write it to the destination file. For example, if we invoke the program as follows:
filecopy input.txt copy.txt
The file input.txt will be written to the pipe. The child process will read the contents of this file and write it to the destination file copy.txt.

Description:

Pipes are used for inter-process communication. It is a connection between two processes. The output from one process becomes the input to the other process. In the given question the two processes that communicate through pipe are the parent process and the child process. The contents of a source file are read from the parent process and written into the pipe and that is read by the child process from the other end and written into the destination file.
We pass the file descriptors as the parameter of this function.
fd [0] – file descriptor for read end of the file.
fd [1] – file descriptor for the write end of the file.
It returns 2 values:
0 – when it is successful.
1 – when there is an error.

Test cases:

1.	Case 1:
Input:  input.txt copy.txt
Expected Output: File successfully copied!
2.	Case 2:
Input: input.txt copy.txt wrong.txt
Expected Output: Error message
