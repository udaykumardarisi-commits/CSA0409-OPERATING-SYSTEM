#include <stdio.h>

int main() {
    int n, i, qt;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n], done = 0;
    float avg_wt = 0, avg_tat = 0;

    for(i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];  
        wt[i] = 0;  
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &qt);

    int t = 0; 

    while(done < n) {
        done = 0;
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] > qt) {
                    t += qt;
                    rt[i] -= qt;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                }
            }
            if(rt[i] == 0) done++;
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
