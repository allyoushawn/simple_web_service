#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


#define MAXBUFSIZE  1024


char filename[MAXBUFSIZE];
char buf[MAXBUFSIZE];

int main( int argc, char** argv )
{

	int file_fd;	
	int ret;
	memset(filename,'\0',sizeof(filename));
	memset(buf,'\0',sizeof(buf));
	
	sleep(30);

	read(STDIN_FILENO,buf, sizeof(buf));
	sprintf(filename , "%s",buf);


	

	//Read File
	
	file_fd = open(filename,O_RDONLY,0);
	if(file_fd < 0)
		{
		  fprintf(stderr, "filename is %s\n",filename );	
		  fprintf(stderr, "Wrong in open file! The file not exist! \n");
          return 0 ;  
		}
 
 
 	fprintf(stderr, "In CGI , filename is %s\n",filename );
 	// Output file content to stdout
 	while(1){

 	ret = read(file_fd, buf, sizeof(buf));
 	if (ret < 0){
       fprintf(stderr, "Error when reading file %s\n", filename);break;}
 
    if(ret == 0)
      { close(file_fd);
      	fprintf(stderr, "CGI Done reading file [%s]\n",  filename);
      	break;
      }

     if(ret>0)
         write(STDOUT_FILENO, buf, ret); 
        
    }
	


	return 0 ;

}