#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>;
#include <sys/stat.h>;
#include <fcntl.h>     /* defines options flags */
#include <sys/types.h> /* defines types used by
sys/stat.h */

int main()
{
    int inp = 0;
    do
    {
        printf("\n 0 for exit:");
        printf("\n1 for creating a file:");
        printf("\n2 for reading contents of a file:");
        printf("\n3 Write to a file:");
        printf("\n4 Read contents  in reverse file:");
        printf("\n5 Find String in file:");
        printf("\nEnter option: ");
        scanf("%d", &inp);
        char ch[1];
        int n;
        switch (inp)
        {
        case 0:
            return 0;

        case 1:
            char name[100];
            printf("\nEnter a name: ");
            scanf("%s", name);
            int fd;
            fd = creat(name, S_IREAD | S_IWRITE);
            char str[200];
            close(fd);
            printf("\nFile created");
            break;

        case 2:
            printf("\nEnter file name: ");
            scanf("%s", name);
            fd = open(name, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
            read(fd, str, sizeof(str) - 1);
            printf("\n%s", str);
            break;

        case 3:

            printf("\nEnter file name: ");
            scanf("%s", name);
            fd = open(name, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
            printf("Enter a String to enter : ");
            scanf("%s", str);
            write(fd, str, sizeof(str));
            close(fd);
            printf("\nFile Written");
            break;

        case 4:
            printf("\nEnter file name: ");
            scanf("%s", name);
            fd = open(name, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
            n = lseek(fd, 0, 2);
            lseek(fd, -1, 2);
            printf("%d n ", n);
            while (n != 0)
            {
                read(fd, ch, sizeof(char));
                printf("%s", ch);
                lseek(fd, -2, 1);
                n--;
            }
            break;

        case 5:
            printf("\nEnter file name: ");
            scanf("%s", name);
            fd = open(name, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
            printf("Enter a String to compare : ");
            scanf("%s", str);
            n = lseek(fd, 0, 2);
            int len = strlen(str);
            lseek(fd, 0, 0);
            int ptr = 1;
            while (n - len > 0)
            {
                char temp[len + 1];
                read(fd, temp, sizeof(temp));
                str[len] = temp[len];
                if (strstr(temp, str) != 0)
                {
                    printf("Match Found");
                }
                lseek(fd, ptr, 0);
                ptr++;
                n--;
            }
            break;

        case 6:
            printf("\nEnter file name: ");
            scanf("%s", name);
            if (remove(name) == 0)
                printf("Deleted successfully");
            else
                printf("Unable to delete the file");

            return 0;

        default:
            printf("*****Invalid option*****");
        }
    } while (inp != 0);
}