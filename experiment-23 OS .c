#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        printf("Directory contents:\n");
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    } else {
        perror("Unable to open directory");
    }
    return 0;
}
