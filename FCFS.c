#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20];
    int st[20], ct[20], tat[20], wt[20], rt[20];
    int time = 0;
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Times:\n");
    for (i = 0; i < n; i++) {
        printf("AT of P%d: ", i + 1);
        scanf("%d", &at[i]);
    }

    printf("\nEnter Burst Times:\n");
    for (i = 0; i < n; i++) {
        printf("BT of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }


    for (i = 0; i < n; i++) {

        if (time < at[i]) {
            time = at[i];
        }

        st[i] = time;

        rt[i] = st[i] - at[i];

        time = time + bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
        avg_rt += rt[i];
    }

    printf("\nProcess\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               st[i],
               ct[i],
               tat[i],
               wt[i],
               rt[i]);
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f", avg_wt / n);
    printf("\nAverage RT  = %.2f\n", avg_rt / n);

    return 0;
}

