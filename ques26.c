#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

// value passed to main function via command line argument
int main(int arc, char** args)
{
        char buffer[1000],buffer2[1000];
        int fd[2]; // file descripter for the pipe
        // condition to check of more than 2 arguments are passed
        if (arc>3)
        {
                printf("Invalid input! More than two arguments!");
        }
        else
        {
                int x=pipe(fd);  // pipe creation
                //if pipe creation fails
                if (x==-1)
                {
                        printf("Pipe failed!");
                        return(1);
                }
                
                pid_t pid=fork(); // child process created
                if(pid<0)
                {
                        printf("Error!");
                }
                else if(pid>0)
                {   
                        //reading data from the other end of pipe by the child process
                        close(fd[0]);
                        int fd1=open(args[1],O_RDONLY);
                        int n= read(fd1,buffer,1000); // reading data from pipe
                        printf("file opened and read \nfile name : %s",args[1]); 
                        write(fd[1],buffer,n); // writing to the file
                        close(fd[1]);
                        wait(NULL);
                }
                else
                {
                        //writing to one end of pipe in the parent process
                        close(fd[1]);
                        int n=read(fd[0],buffer2,1000); // reading data from file
                        close(fd[0]);
                        int fd2=open(args[2],O_CREAT|O_RDWR,0777);
                        printf("file opened and written \n file name : %s",args[2]);
                        write(fd2,buffer2,n); // writing it to the pipe
                }
        }
}
