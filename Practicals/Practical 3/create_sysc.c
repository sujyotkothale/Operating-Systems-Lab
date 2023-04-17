#include <stdio.h>
#include <sys/types.h> /* defines types */
#include <sys/stat.h>  /* defines S_IREAD & S_IWRITE */
#include <stdlib.h>
#include <fcntl.h> // file control header file
#include <unistd.h>
int main()
{
    int fd;
    fd = creat("datafile.txt",S_IREAD | S_IWRITE);
    close(fd);
    int fd2;
    fd2 = creat("datafile2.txt",S_IREAD | S_IWRITE);
    if (fd == -1)
        printf("Error in opening datafile.dat\n");
    else
    {
        printf("datafile.txt opened for read/write access\n");
        printf("datafile.txt is currently empty\n");
    }
    printf("FD = %d\n",fd);
    printf("FD2 = %d",fd2);
    
    close(fd2);
    exit(0);
}
