#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

struct stat s_stat;

int my_copy(int sfd, int dfd,int per)
{
        char buffer[BUFFER_SIZE];
        int bytes_read, bytes_write;
	struct stat d_stat;

	while ((bytes_read = read(sfd, buffer, BUFFER_SIZE)) > 0)          {
            bytes_write = write(dfd, buffer, bytes_read);
            if (bytes_write < 0) 
	    {
                perror("write");
                return 1;
            }
        }

	return 0 ;
}
int main(int argc,char *argv[])
{
  	int sfd,dfd,per=0;
	char *source_path, *dest_path;
	char res;
    
	if(argc < 3 || argc > 4)
	{
	    printf("Usage: ./my_copy [-p] source_file dest_file\n");
	    return 1;
	}
 

	if (argc == 4 && strcmp(argv[1], "-p") == 0) 
	{
            per = 1;
            source_path = argv[2];
            dest_path = argv[3];
  	}
	else if (argc == 3)
       	{
            source_path = argv[1];
       	    dest_path = argv[2];
        }
       	else 
	{
            printf("Usage: ./my_copy [-p] source_file dest_file\n");
	    return 1;
        }

	sfd = open(source_path, O_RDONLY);
	dfd = open(dest_path, O_WRONLY );
	if(sfd == -1)
	{
	    printf("Source file does not exist\n");
	    return 1;
	}

	if(dfd != -1)
	{
	    printf("File \"%s\" already exists. Do you want to overwrite? (Y/n) ", dest_path);
            scanf("%c", &res);
            if (res != 'Y' && res != 'y')
	    {
            	printf("Copying cancelled.\n");
		return 1;
            }
	    else
	    {
               dfd = open(dest_path, O_CREAT | O_WRONLY | O_TRUNC);
	    }
	}
	else
	{
             dfd = open(dest_path, O_CREAT | O_EXCL | O_WRONLY );
	}
  
	my_copy(sfd,dfd,per);

	if (per) 
	{
            if (stat(source_path, &s_stat) < 0) 
	    {
                perror("stat");
                return 1;
            }
        }
	if (per)
       	{
       	    if (chmod(dest_path, s_stat.st_mode) < 0) 
	    {
                perror("chmod");
                return 1;
            }
        }
	return 0 ;
}
