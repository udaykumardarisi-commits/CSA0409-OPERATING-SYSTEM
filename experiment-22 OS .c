#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    int fd;
    struct stat fileStat;
    struct dirent *de;
    DIR *dr;

    fd = open("sample.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl failed");
        close(fd);
        return 1;
    }
    printf("File Flags: %d\n", flags);

    off_t size = lseek(fd, 0, SEEK_END);
    printf("File Size using lseek: %ld bytes\n", (long)size);

    if (stat("sample.txt", &fileStat) == -1) {
        perror("stat failed");
        close(fd);
        return 1;
    }

    printf("File Size using stat: %ld bytes\n", fileStat.st_size);
    printf("File Permissions: %o\n", fileStat.st_mode & 0777);

    close(fd);

    dr = opendir(".");
    if (dr == NULL) {
        perror("Could not open current directory");
        return 1;
    }

    printf("\nFiles in current directory:\n");
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
}
