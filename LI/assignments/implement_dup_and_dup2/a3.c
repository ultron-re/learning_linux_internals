#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    int fd,new_fd,cpy;

    if (argc < 2) 
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
    {
        printf("Error in opening file\n");
        return 1;
    }

    cpy=dup(1);
    
    if(cpy==-1)
    {
	printf("Error\n");
	return 1;
    }
      
    dup2(fd,1);

    printf("This message is printed to the file '%s'\n", argv[1]);
   
  //  close(fd);
    fflush(stdout);
    
    dup2(cpy,1);
    printf("This message is printed to stdout\n");

    
    return 0;
}

