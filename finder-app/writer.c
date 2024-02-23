#include <stdio.h>
#include <syslog.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
        openlog(NULL,0,LOG_USER);
        if(argc != 3 )
        {
                syslog(LOG_ERR,"Need to pass 2 arguments path and the content");
		exit(1);
	}else{
		char writefile[10000];
                strcpy(writefile,argv[1]);
                char writestr[1000];
                strcpy(writestr,argv[2]);

		//Creating the File
                int fd;
                fd = open(writefile, O_WRONLY | O_CREAT | O_EXCL | O_TRUNC | O_CLOEXEC, S_IRWXU | S_IRWXG | S_IRWXO);
                if(fd == -1)
                {
                        syslog(LOG_ERR,"Failed to create a file");
                }
		
		//Writing the file
                ssize_t str;
                str = write(fd, writestr, strlen(writestr));
                if (str == -1)
                {
                        syslog(LOG_ERR,"Failed to write in a file");
                }
                syslog(LOG_DEBUG,"Writing %s to %s", writestr, writefile);

		//Closing the file
                if(close(fd) == -1)
                {
                        syslog(LOG_ERR,"Failed to close the file");
                }
	}
	closelog();
}
