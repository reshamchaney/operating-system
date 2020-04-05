#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
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
int main(int arc, char** args)
{
        if(arc>2)
        {
                printf("Invalid arguments! There should be only one argument!\n");
        }
        else
        {
                if(checkdigit(args[1])==1)
                {
                int start=atoi(args[1]);
                if(start<=0)
                {
                        printf("Invalid input! negative value or 0 passed!\n");
                }
                else
                {
 			pid_t p;
                        p=fork();
                        int x=start;
                        if(p==0)
                        {
                                while(x>0)
                                {
                                        printf("%d ",x);
                                        x=x/2;
                                }
                                printf("\n");
                        }
                        else if(p>0)
                        {
                                wait(NULL);
                        }
                        else
                        {
                                printf("Error!");                                                                                                                                               }
			}
                }
                }
                else                                                                                                                                                                    {                                                                                                                                                                               printf("Invalid input! Please enter digit!\n ");
                }
        }
}