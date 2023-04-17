
#include <fcntl.h>     /* defines options flags */
#include <sys/types.h> /* defines types used by
sys/stat.h */
#include <sys/stat.h>  /* defines S_IREAD & S_IWRITE*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
static char message[] = "Hello, world";
int main()
{
    int fd;
    char buffer[80];
    char buffer2[20];
    fd = open("datafile4.txt", O_RDWR | O_CREAT | O_EXCL, S_IREAD | S_IWRITE);
    if (fd != -1)
    {
        printf("datafile4.txt opened for read/write access\n");
        write(fd, message, sizeof(message)-1);
        close(fd);
        fd = open("datafile.txt", O_RDWR, S_IREAD|S_IWRITE);
        if (read(fd, buffer, sizeof(message)-1) == sizeof(message)-1)
            printf("\"%s\" was written to datafile.dat\n", buffer);
        else
            printf("*** error reading datafile.dat ***\n");
        lseek(fd,0,0);    
        if (read(fd, buffer2, sizeof(message)-8) == sizeof(message)-8)
            printf("\"%s\" was written to datafile.txt\n", buffer2);
        else
            printf("*** error reading datafile.txt ***\n");    
        close(fd);
    }
    else
        printf("*** datafile.txt already exists ***\n");
    exit(0);
}
