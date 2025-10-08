#include <stdio.h>
#include <string.h>

struct {
    char dname[20];
    char fname[10][20];
    int fcount;
} dir[10];

int main() {
    int i, ch, dcount = 0;
    char d[20], f[20];

    printf("\n*** Two-Level Directory Simulation ***\n");

    while (1) {
        printf("\n1. Create User Directory");
        printf("\n2. Create File");
        printf("\n3. Search File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (dcount >= 10) {
                    printf("\nDirectory list is full!\n");
                    break;
                }
                printf("\nEnter Directory (User) Name: ");
                scanf("%s", d);

                int exists = 0;
                for (i = 0; i < dcount; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        printf("\nUser Directory already exists!\n");
                        exists = 1;
                        break;
                    }
                }

                if (!exists) {
                    strcpy(dir[dcount].dname, d);
                    dir[dcount].fcount = 0;
                    dcount++;
                    printf("\nUser Directory created successfully!\n");
                }
                break;

            case 2:
                printf("\nEnter User Directory Name: ");
                scanf("%s", d);

                int found = 0;
                for (i = 0; i < dcount; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        found = 1;
                        if (dir[i].fcount >= 10) {
                            printf("\nFile list is full for this user!\n");
                            break;
                        }
                        printf("Enter File Name: ");
                        scanf("%s", f);

                        int fexists = 0;
                        for (int j = 0; j < dir[i].fcount; j++) {
                            if (strcmp(f, dir[i].fname[j]) == 0) {
                                printf("\nFile already exists!\n");
                                fexists = 1;
                                break;
                            }
                        }

                        if (!fexists) {
                            strcpy(dir[i].fname[dir[i].fcount], f);
                            dir[i].fcount++;
                            printf("\nFile created successfully!\n");
                        }
                        break;
                    }
                }
                if (!found)
                    printf("\nUser Directory not found!\n");
                break;

            case 3:
                printf("\nEnter User Directory Name: ");
                scanf("%s", d);
                printf("Enter File Name to Search: ");
                scanf("%s", f);
                found = 0;

                for (i = 0; i < dcount; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        for (int j = 0; j < dir[i].fcount; j++) {
                            if (strcmp(f, dir[i].fname[j]) == 0) {
                                printf("\nFile found in user directory '%s'.\n", d);
                                found = 1;
                                break;
                            }
                        }
                    }
                }
                if (!found)
                    printf("\nFile not found!\n");
                break;

            case 4:
                printf("\nEnter User Directory Name: ");
                scanf("%s", d);
                found = 0;
                for (i = 0; i < dcount; i++) {
                    if (strcmp(d, dir[i].dname) == 0) {
                        found = 1;
                        if (dir[i].fcount == 0)
                            printf("\nNo files in this directory.\n");
                        else {
                            printf("\nFiles in directory '%s':\n", d);
                            for (int j = 0; j < dir[i].fcount; j++)
                                printf("%s\n", dir[i].fname[j]);
                        }
                    }
                }
                if (!found)
                    printf("\nUser Directory not found!\n");
                break;

            case 5:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}
