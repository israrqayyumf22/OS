#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pID[n], aT[n], bT[n], cT[n], tT[n], wT[n];
    int isCompleted[n];

    for (int i = 0; i < n; i++) {
        pID[i] = i + 1;
        isCompleted[i] = 0;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &aT[i], &bT[i]);
    }

    int currentTime = 0, completed = 0;

    while (completed != n) {
        int shortestJob = -1;
        int minBurstTime = 1e9; // Initialize to a large number

        // Find the shortest job that has arrived and is not completed
        for (int i = 0; i < n; i++) {
            if (aT[i] <= currentTime && !isCompleted[i] && bT[i] < minBurstTime) {
                minBurstTime = bT[i];
                shortestJob = i;
            }
        }

        // If no job can be executed, increment currentTime (no job ready to execute)
        if (shortestJob == -1) {
            currentTime++;
            continue;
        }

        // Process the selected shortest job
        currentTime += bT[shortestJob];
        cT[shortestJob] = currentTime;
        tT[shortestJob] = cT[shortestJob] - aT[shortestJob];
        wT[shortestJob] = tT[shortestJob] - bT[shortestJob];
        isCompleted[shortestJob] = 1;
        completed++;
    }

    // Print the results
    printf("\n+--------+--------------+------------+-----------------+-----------------+-----------------+\n");
    printf("| Process| Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time    |\n");
    printf("+--------+--------------+------------+-----------------+-----------------+-----------------+\n");
    for (int i = 0; i < n; i++) {
        printf("|   P%d   |      %2d      |     %2d     |        %2d       |        %2d       |        %2d       |\n",
               pID[i], aT[i], bT[i], cT[i], tT[i], wT[i]);
    }
    printf("+--------+--------------+------------+-----------------+-----------------+-----------------+\n");

    // Print average Turnaround and Waiting Times
    float total_taT = 0, total_wT = 0;
    for (int i = 0; i < n; i++) {
        total_taT += tT[i];
        total_wT += wT[i];
    }
    printf("\nAverage Turnaround Time: %.2f\n", total_taT / n);
    printf("Average Waiting Time: %.2f\n", total_wT / n);

    return 0;
}

