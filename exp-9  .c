#include <stdio.h>

int main() {
    int n, m; 
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int max[n][m], alloc[n][m], need[n][m], avail[m];

    printf("Enter Max matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Allocation matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Available resources:\n");
    for(int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int finish[n];
    for(int i = 0; i < n; i++) finish[i] = 0;

    int safe[n], count = 0;

    while(count < n) {
        int found = 0;
        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                int can = 1;
                for(int j = 0; j < m; j++)
                    if(need[i][j] > avail[j])
                        can = 0;

                if(can) {
                    for(int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(!found) break;
    }

    if(count == n) {
        printf("System is in a safe state.\nSafe sequence: ");
        for(int i = 0; i < n; i++)
            printf("P%d ", safe[i]);
        printf("\n");
    } else {
        printf("System is NOT in a safe state.\n");
    }

    return 0;
}
