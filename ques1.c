#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>

//function to check whether a digit is passed through the command line argument
int checkdigit(char *s)
{
int i,c=0;
for(i=0;i<strlen(s);i++)
{
if (isdigit(s[i])|| s[i]=='-' )
 {
  c++;
 }
}
if(c==strlen(s))
return 1;
else
return 0;
}

//start of main function
int main(int arc, char** args)
{
	//condition to check if more than 1 agument is passed
        if(arc>2)
        {
                printf("Invalid arguments! There should be only one argument!\n");
        }
        else
        {
                if(checkdigit(args[1])==1)
                {
                int start=atoi(args[1]);  // convert string to integer
                if(start<=0)  //to check if the no. passed is positive
                {
                        printf("Invalid input! negative value or 0 passed!\n");
                }
                else
                {
 			pid_t p;
                        p=fork();  // child process created
                        int x=start;
                        if(p==0)
                        {
				// child process generating the sequence
                                while(x>0)
                                {
                                        printf("%d ",x);
                                        x=x/2;
                                }
                                printf("\n");
                        }
                        else if(p>0)
                        {
                                wait(NULL);  // wait system call is invoked to let child process execute first
                        }
                        else
                        {
				//if an error occurs or the child process is note created
                                printf("Error!");                                                                                                                                               }
			}
                }
                }
                else                                                                                                                                                                    {                                                                                                                                                                               printf("Invalid input! Please enter digit!\n ");
                }
        }
}//end of main
