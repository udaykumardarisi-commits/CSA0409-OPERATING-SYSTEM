#include <stdio.h>

int main() {
    int n, frame_size, page;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page reference string: ");
    for(int i=0;i<n;i++) scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&frame_size);
    int frames[frame_size];
    for(int i=0;i<frame_size;i++) frames[i] = -1; 

    int page_faults=0, index=0;

    printf("\nFIFO Page Replacement Steps:\n");
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<frame_size;j++){
            if(frames[j]==pages[i]){
                found=1;
                break;
            }
        }

        if(found){
            printf("Page %d already in frame: [", pages[i]);
            for(int k=0;k<frame_size;k++)
                printf("%d ", frames[k]);
            printf("]\n");
        } else {
            if(frames[index]==-1)
                printf("Page %d loaded into empty frame %d. Frame content: [", pages[i], index);
            else
                printf("Page %d replaces page %d at frame %d. Frame content: [", pages[i], frames[index], index);

            frames[index] = pages[i];
            index = (index+1)%frame_size;
            page_faults++;

            for(int k=0;k<frame_size;k++)
                printf("%d ", frames[k]);
            printf("]\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
