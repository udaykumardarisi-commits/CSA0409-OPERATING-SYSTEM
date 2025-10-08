#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;
    char filename[50];

    printf("Enter file name: ");
    scanf("%s", filename);

    if (stat(filename, &fileStat) < 0) {
        perror("Error getting file info");
        return 1;
    }

    printf("File Permissions for %s:\n", filename);
    printf("Owner: %c%c%c\n",
           (fileStat.st_mode & S_IRUSR) ? 'r' : '-',
           (fileStat.st_mode & S_IWUSR) ? 'w' : '-',
           (fileStat.st_mode & S_IXUSR) ? 'x' : '-');
    printf("Group: %c%c%c\n",
           (fileStat.st_mode & S_IRGRP) ? 'r' : '-',
           (fileStat.st_mode & S_IWGRP) ? 'w' : '-',
           (fileStat.st_mode & S_IXGRP) ? 'x' : '-');
    printf("Others: %c%c%c\n",
           (fileStat.st_mode & S_IROTH) ? 'r' : '-',
           (fileStat.st_mode & S_IWOTH) ? 'w' : '-',
           (fileStat.st_mode & S_IXOTH) ? 'x' : '-');

    return 0;
}
