#include <stdio.h>
#include <string.h>

struct {
    char fname[20];
} dir[10];

int main() {
    int i, ch, n = 0;
    char f[20];

    printf("\n*** Single Level Directory Simulation ***\n");

    while (1) {
        printf("\n1. Create File");
        printf("\n2. Search File");
        printf("\n3. Display Files");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (n >= 10) {
                    printf("\nDirectory is Full!\n");
                    break;
                }
                printf("\nEnter File name: ");
                scanf("%s", f);

                int exists = 0;
                for (i = 0; i < n; i++) {
                    if (strcmp(f, dir[i].fname) == 0) {
                        printf("\nFile already exists!\n");
                        exists = 1;
                        break;
                    }
                }

                if (!exists) {
                    strcpy(dir[n].fname, f);
                    n++;
                    printf("\nFile created successfully!\n");
                }
                break;

            case 2:
                printf("\nEnter File name to search: ");
                scanf("%s", f);
                int found = 0;
                for (i = 0; i < n; i++) {
                    if (strcmp(f, dir[i].fname) == 0) {
                        printf("\nFile found: %s\n", f);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                    printf("\nFile not found!\n");
                break;

            case 3:
                if (n == 0)
                    printf("\nDirectory is Empty!\n");
                else {
                    printf("\nFiles in Directory:\n");
                    for (i = 0; i < n; i++)
                        printf("%s\n", dir[i].fname);
                }
                break;

            case 4:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}
