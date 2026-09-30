#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20], response[20];
    
    int queue[1000];
    int front = 0, rear = 0;
    
    int time = 0;
    int completed = 0;
    int quantum;
    
    float avg_tat = 0;
    float avg_wt = 0;
    float avg_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20) {
        printf("Invalid number of processes.\n");
        return 1;
    }

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

        if (bt[i] <= 0) {
            printf("Burst time must be greater than 0.\n");
            return 1;
        }

        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);

    if (quantum <= 0) {
        printf("Time quantum must be greater than 0.\n");
        return 1;
    }

  
    int first = 0;

    for (i = 1; i < n; i++) {
        if (at[i] < at[first]) {
            first = i;
        }
    }

    time = at[first];


    for (i = 0; i < n; i++) {
        if (at[i] <= time) {
            queue[rear++] = i;
        }
    }

    while (completed < n) {

        if (front == rear) {

            int next = -1;

            for (i = 0; i < n; i++) {
                if (rt[i] > 0 && at[i] > time) {
                    if (next == -1 || at[i] < at[next]) {
                        next = i;
                    }
                }
            }

            if (next != -1) {
                time = at[next];


                for (i = 0; i < n; i++) {
                    if (rt[i] > 0 && at[i] <= time) {
                        int already_in_queue = 0;


                        if (!already_in_queue) {
                            queue[rear++] = i;
                        }
                    }
                }
            }
        }

        int p = queue[front++];

    
        if (response[p] == -1) {
            response[p] = time - at[p];
        }

        int execution_time;

        if (rt[p] > quantum) {
            execution_time = quantum;
        } else {
            execution_time = rt[p];
        }

        time += execution_time;
        rt[p] -= execution_time;

        for (i = 0; i < n; i++) {
            if (i != p && rt[i] > 0 &&
                at[i] <= time) {

            
                int already_in_queue = 0;
                int j;

                for (j = front; j < rear; j++) {
                    if (queue[j] == i) {
                        already_in_queue = 1;
                        break;
                    }
                }

                if (!already_in_queue) {
                    queue[rear++] = i;
                }
            }
        }

        if (rt[p] > 0) {
            queue[rear++] = p;
        }
        else {
            completed++;

            ct[p] = time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];

            avg_tat += tat[p];
            avg_wt += wt[p];
            avg_rt += response[p];
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i],
               response[i]);
    }

    printf("\nAverage TAT = %.2f", avg_tat / n);
    printf("\nAverage WT  = %.2f", avg_wt / n);
    printf("\nAverage RT  = %.2f\n", avg_rt / n);

    return 0;
}

