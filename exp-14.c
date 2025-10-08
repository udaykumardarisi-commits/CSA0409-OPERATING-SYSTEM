#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

void displayFrames(int frames[], int f) {
    printf("[");
    for (int i = 0; i < f; i++) {
        if (frames[i] == -1)
            printf(" -1 ");
        else
            printf(" %d ", frames[i]);
    }
    printf("]\n");
}

int main() {
    int frames[10], pages[30], time[10];
    int n, f, count = 0, pageFaults = 0, pageHits = 0;
    int i, j, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    if (n <= 0 || n > 30) {
        printf("Error: Invalid number of pages.\n");
        return 1;
    }

    printf("Enter the page reference string: ");
    for (i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    if (f <= 0 || f > 10) {
        printf("Error: Invalid number of frames.\n");
        return 1;
    }

    for (i = 0; i < f; ++i) {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < n; ++i) {
        int flag1 = 0, flag2 = 0;

        // Check if HIT
        for (j = 0; j < f; ++j) {
            if (frames[j] == pages[i]) {
                count++;
                time[j] = count;
                flag1 = flag2 = 1;
                pageHits++;
                printf("Page %d already in frame: ", pages[i]);
                displayFrames(frames, f);
                break;
            }
        }

        // Empty frame case
        if (flag1 == 0) {
            for (j = 0; j < f; ++j) {
                if (frames[j] == -1) {
                    count++;
                    pageFaults++;
                    frames[j] = pages[i];
                    time[j] = count;
                    flag2 = 1;
                    printf("Page %d loaded into empty frame %d: ", pages[i], j);
                    displayFrames(frames, f);
                    break;
                }
            }
        }

        // Replacement case
        if (flag2 == 0) {
            pos = findLRU(time, f);
            count++;
            pageFaults++;
            printf("Page %d replaces least recently used page %d: ", pages[i], frames[pos]);
            frames[pos] = pages[i];
            time[pos] = count;
            displayFrames(frames, f);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);

    return 0;
}
