#include <stdio.h>
int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int aT[n], bT[n], cT[n], tT[n], wT[n];
    float total_taT = 0, total_wT = 0;

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &aT[i], &bT[i]);
    }

    // Initialize completion time for the first process
    cT[0] = aT[0] + bT[0];
    tT[0] = cT[0] - aT[0];
    wT[0] = tT[0] - bT[0];

    // Calculate completion time, turnaround time, and waiting time
    for (i = 1; i < n; i++) {
        if (cT[i - 1] < aT[i]) {
            cT[i] = aT[i] + bT[i];
        } else {
            cT[i] = cT[i - 1] + bT[i];
        }
        tT[i] = cT[i] - aT[i];
        wT[i] = tT[i] - bT[i];
    }

    // Calculate total turnaround and waiting time
    for (i = 0; i < n; i++) {
        total_taT += tT[i];
        total_wT += wT[i];
    }

    // Print the table
    printf("\n+--------+--------------+------------+-----------------+-----------------+-----------------+\n");
    printf("| Process| Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time    |\n");
    printf("+--------+--------------+------------+-----------------+-----------------+-----------------+\n");
    for (i = 0; i < n; i++) {
        printf("|   P%d   |      %2d      |     %2d     |        %2d       |        %2d       |        %2d       |\n",
               i + 1, aT[i], bT[i], cT[i], tT[i], wT[i]);
    }
    printf("+--------+--------------+------------+-----------------+-----------------+-----------------+\n");

    // Print average turnaround and waiting time
    printf("\nAverage Turnaround Time: %.2f\n", total_taT / n);
    printf("Average Waiting Time: %.2f\n", total_wT / n);

    return 0;
}

