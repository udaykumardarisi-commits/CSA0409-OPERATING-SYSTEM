#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50], search[20], line[200];

    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter word to search: ");
    scanf("%s", search);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("\nLines containing '%s':\n", search);
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, search))
            printf("%s", line);
    }

    fclose(fp);
    return 0;
}
