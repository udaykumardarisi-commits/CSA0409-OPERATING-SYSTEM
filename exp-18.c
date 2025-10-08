#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, head, total = 0, disk_size, move;
    int request[50];

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &disk_size);

    printf("Enter head movement direction (1 for high/right, 0 for low/left): ");
    scanf("%d", &move);

    // Sort requests
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (request[i] > request[j]) {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    int pos;
    for (i = 0; i < n; i++) {
        if (head < request[i]) {
            pos = i;
            break;
        }
    }

    printf("\nHead Movement Sequence: ");

    if (move == 1) { // Moving towards higher end
        for (i = pos; i < n; i++) {
            printf("%d -> ", request[i]);
            total += abs(request[i] - head);
            head = request[i];
        }
        total += abs(disk_size - 1 - head);
        head = disk_size - 1;
        for (i = pos - 1; i >= 0; i--) {
            printf("%d -> ", request[i]);
            total += abs(request[i] - head);
            head = request[i];
        }
    } else { // Moving towards lower end
        for (i = pos - 1; i >= 0; i--) {
            printf("%d -> ", request[i]);
            total += abs(request[i] - head);
            head = request[i];
        }
        total += abs(head - 0);
        head = 0;
        for (i = pos; i < n; i++) {
            printf("%d -> ", request[i]);
            total += abs(request[i] - head);
            head = request[i];
        }
    }

    printf("\n\nTotal Head Movement: %d", total);
    printf("\nAverage Head Movement: %.2f\n", (float)total / n);

    return 0;
}
