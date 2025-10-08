#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], remaining[10];
    int m, n, i, j, allocation[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter size of each block: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        remaining[i] = blockSize[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter size of each process: ");
    for (i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (remaining[j] >= processSize[i]) {
                allocation[i] = j;
                remaining[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    printf("\nBlock No.\tBlock Size\tRemaining Space\n");
    for (i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t%d\n", i + 1, blockSize[i], remaining[i]);
    }

    return 0;
}
