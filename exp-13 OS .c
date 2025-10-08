#include <stdio.h>

int main() {
    int n, frame_size;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string: ");
    for(int i=0; i<n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frame_size);

    int frames[frame_size], time[frame_size];
    for(int i=0; i<frame_size; i++) {
        frames[i] = -1; 
        time[i] = 0;
    }

    int page_faults = 0, current_time = 0;

    printf("\nLRU Page Replacement Steps:\n");
    for(int i=0; i<n; i++) {
        current_time++;
        int found = -1;
        for(int j=0; j<frame_size; j++) {
            if(frames[j] == pages[i]) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            time[found] = current_time;
            printf("Page %d already in frame: [", pages[i]);
        } else {
            int empty_index = -1;
            for(int j=0; j<frame_size; j++) {
                if(frames[j] == -1) {
                    empty_index = j;
                    break;
                }
            }

            if(empty_index != -1) {
                frames[empty_index] = pages[i];
                time[empty_index] = current_time;
                page_faults++;
                printf("Page %d loaded into empty frame %d: [", pages[i], empty_index);
            } else {
                int lru_index = 0;
                for(int j=1; j<frame_size; j++) {
                    if(time[j] < time[lru_index])
                        lru_index = j;
                }
                printf("Page %d replaces least recently used page %d: [", pages[i], frames[lru_index]);
                frames[lru_index] = pages[i];
                time[lru_index] = current_time;
                page_faults++;
            }
        }

        for(int j=0; j<frame_size; j++)
            printf("%d ", frames[j]);
        printf("]\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
