#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF_SIZE 1024

int main(int argc,char *argv[])
{
    int fd;
    char buf[MAX_BUF_SIZE];
    struct flock fl;

    if(argc!=2)
    {
	printf("Insufficient arguments\n");
	printf("Usage: ./a.out <filename>\n");
	return 1;
    }

    fd = open(argv[1],O_RDWR);

    int count,l=0;
    char c[10];
    pid_t pid;

    // Create a child process using fork()
    pid = fork();


    if(pid > 0) // parent, pid -> child pid
    {
	memset(&fl, 0, sizeof(fl));
        fl.l_type = F_WRLCK;
     
        while (fcntl(fd, F_SETLKW, &fl) == -1);

        printf("PARENT PROCESS: locked file\n");
	
	printf("PARENT PROCESS: prime numbers up to 15: \n");
//      write(fd, buf, strlen(buf));
//	buf[0] = '\0';

	for(int i=2;i<=15;i++)
	{
	    count =0;
	    for(int k=2;k<=i/2;k++)
	    {
		if(i%k==0)
		{
		    count=1;
		    break;
		}
	    }
    
	    if(count == 0)
	    {
	        sprintf(buf, "%d, ", i);
                write(fd,buf,strlen(buf));
		buf[0] = '\0';
	    }

	}
	sprintf(buf, "\n");
        write(fd, buf, strlen(buf));
	buf[0] = '\0';

	fl.l_type = F_UNLCK;
        if (fcntl(fd, F_SETLK, &fl) == -1) {
            perror("fcntl");
            return 1;
        }

        printf("PARENT PROCESS: unlocked file\n");
    }
    //child, fork returns 0
    else if(pid == 0)
    {
	memset(&fl, 0, sizeof(fl));
        fl.l_type = F_WRLCK;

	
	while (fcntl(fd, F_SETLKW, &fl) == -1);

	printf("CHILD PROCESS: locked file\n");

	int a = 0, b = 1, c, i;
        printf("CHILD PROCESS: Fibonacci series up to 10:\n");
//        write(fd, buf, strlen(buf));
//	buf[0] = '\0';

  //      sprintf(buf, "CHILD PROCESS: %d, %d, ", a, b);
//	write(fd, buf, strlen(buf));
//	buf[0] = '\0';

        for (i = 2; i < 10; i++) 
	{
            c = a + b;
            sprintf(buf, "%d, ", c);
            write(fd, buf, strlen(buf));
	    buf[0] = '\0';

            a = b;
            b = c;
        }

        sprintf(buf, "\n");
        write(fd, buf, strlen(buf));
	buf[0] = '\0';

	fl.l_type = F_UNLCK;
        if (fcntl(fd, F_SETLK, &fl) == -1) 
	{
            perror("fcntl");
            return 1;
        }

        printf("CHILD PROCESS: unlocked file\n");
    }
    else // fork returned -1 (failed)
    {
	perror("fork");
	return 1;
    }

        if (close(fd) == -1) 
	{
        perror("close");
	}
    return 0;
}

