#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20], response[20];
    int time = 0, completed = 0;
    int min, pos;
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &at[i]);
        response[i] = -1;
    }

    printf("\nEnter Burst Times:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
  while (completed < n) {
        min = 9999;
        pos = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                pos = i;
            }
        }
        if (pos == -1) {
            time++;
        }
        else {

            if (response[pos] == -1) {
                response[pos] = time - at[pos];
                avg_rt += response[pos];
            }
            rt[pos]--;
            time++;
            if (rt[pos] == 0) {
                completed++;

                ct[pos] = time;
                tat[pos] = ct[pos] - at[pos];
                wt[pos] = tat[pos] - bt[pos];

                avg_tat += tat[pos];
                avg_wt += wt[pos];
            }
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i],
               ct[i], tat[i], wt[i], response[i]);
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f", avg_wt / n);
    printf("\nAverage RT  = %.2f\n", avg_rt / n);

    return 0;
}

  
            

        
