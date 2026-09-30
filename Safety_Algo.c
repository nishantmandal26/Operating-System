#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[n][m];
    int max[n][m];
    int need[n][m];
    int available[m];
    int work[m];
    int finish[n];
    int safeSequence[n];


    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }


    printf("\nEnter Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }


    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }


    for (int i = 0; i < n; i++) {
        finish[i] = 0;

        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i);

        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }


    for (int j = 0; j < m; j++) {
        work[j] = available[j];
    }

  
    int count = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {

            if (finish[i] == 0) {
                int canExecute = 1;


                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute) {


                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            break;
        }
    }


    if (count == n) {

        printf("\nSystem is in a SAFE state.\n");


        printf("Safe Sequence: ");

        for (int i = 0; i < n; i++) {
            printf("P%d", safeSequence[i]);

            if (i != n - 1) {
                printf(" -> ");
            }
        }

        printf("\n");


        printf("Final Available: ");

        for (int j = 0; j < m; j++) {
            printf("%d ", work[j]);
        }

        printf("\n");

    } else {

        printf("\nSystem is in an UNSAFE state.\n");
        printf("Deadlock may occur.\n");
        printf("Available at stop: ");

        for (int j = 0; j < m; j++) {
            printf("%d ", work[j]);
        }

        printf("\n");
    }

    return 0;
}

