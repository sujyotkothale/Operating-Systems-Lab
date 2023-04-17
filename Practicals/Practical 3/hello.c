# include <stdio.h>
#include <fcntl.h>     /* defines options flags */
#include <sys/types.h> /* defines types used by
sys/stat.h */
#include <sys/stat.h>  /* defines S_IREAD & S_IWRITE*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main () {
char name[100];
            printf("\nEnter a name: ");
            scanf("%s",name);
            int fd;
            fd = creat("datafile.txt",S_IREAD | S_IWRITE);
            close(fd);
            printf("\nFile created");
}
