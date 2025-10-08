#include <stdio.h>

int main() {
    int disk[50], start, length, i, j, n;
    char ch;

    for (i = 0; i < 50; i++) {
        disk[i] = 0;  // initialize all blocks as free
    }

    printf("Enter total number of disk blocks (<= 50): ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Error: Invalid number of disk blocks.\n");
        return 1;
    }

    do {
        printf("\nEnter starting block and length of file: ");
        scanf("%d%d", &start, &length);

        if (start < 0 || start + length > n) {
            printf("Error: Requested blocks are out of disk range.\n");
        } else {
            int flag = 0;
            for (i = start; i < start + length; i++) {
                if (disk[i] == 1) {
                    flag = 1; // block already allocated
                    break;
                }
            }

            if (flag == 0) {
                for (i = start; i < start + length; i++) {
                    disk[i] = 1;
                }
                printf("File allocated at blocks: ");
                for (i = start; i < start + length; i++) {
                    printf("%d ", i);
                }
                printf("\n");
            } else {
                printf("Error: Some blocks already allocated, cannot allocate file.\n");
            }
        }

        printf("\nDo you want to allocate another file? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    printf("\nFinal Disk Status:\n");
    for (i = 0; i < n; i++) {
        printf("Block %d: %s\n", i, (disk[i] == 1) ? "Allocated" : "Free");
    }

    return 0;
}
