#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

struct stat s_stat;

int main(int argc,char *argv[])
{
  	int pfd,opt,lines = 0, words = 0, character =0;
	int filecount=0;
	char *file_path;
	int n;
        char str[50];
	char buf[BUFFER_SIZE];
        int a=0,i=0,cc=0,wc=0,lc=0,tlc=0,twc=0,tcc=0,m;

	if(argc == 1)
	{
	    scanf("%[^\n]",str);
            while(str[i]!='\0')
	    {
	        if(str[i]==' ')
	        {
	            wc++;
	        }
                cc++;
		i++;
	    }
	    lc++;
            wc++;
	    cc++;

	    printf("%d %d %d lines words characters\n",lc,wc,cc);
	    return 1;
	}

	else
	{
	    for(int k=1;k<argc;k++)
	    {
		
		file_path=argv[k];
	    	pfd = open(file_path, O_RDONLY);
		
	    	while ((opt = getopt(argc, argv, "lwc"))!= -1)
	    	{
                   
		    a++;
	            switch (opt) 
		    {
          	         case 'l':
               		      lines = 1;
                	      break;
                         case 'w':
                	      words = 1;
                              break;
                         case 'c':
                             character = 1;
                             break;
                    }
		}
	        while((n=read(pfd,buf,BUFFER_SIZE))>0)
		{
		
		    filecount++;
		    lc=0,wc=0,cc=0;
		    for (int l = 0; l < n; l++) 
		    {
			if(buf[l]=='\n')
			{
			    lc++;
			    wc++;
			    cc++;
			}
		        else if(buf[l] ==' ' ||buf[l] == '\t')
			{
			    wc++;
			    cc++;
		        }
			else
			{
			    cc++;
			}
		    }
		    if(lines==1 || a==0)
		    {
                    	printf("%d ",lc);
		    }

		    if(words==1 || a==0)
		    {
                    	printf("%d ",wc);
		    }

		    if(character==1 || a==0)
		    {
                    	printf("%d ",cc);
		    }
		    printf("%s\n",file_path);
		    tlc+=lc;
		    twc+=wc;
		    tcc+=cc;
		   
	        }
		    if(filecount > 1)
		    {
		
		    if(lines==1 || a==0)
		    {
                    	printf("%d ",tlc);
		    }

		    if(words==1||a==0)
		    {
                    	printf("%d ",twc);
		    }

		    if(character==1||a==0)
		    {
                    	printf("%d ",tcc);
		    }
		    printf("total\n");
		    }
		}	    

		
	    }
	

	return 0 ;
}

