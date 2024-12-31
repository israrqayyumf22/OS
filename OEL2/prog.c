#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int alloc[MAX_PROCESSES][MAX_RESOURCES]) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

int isProcessSafe(int process, int avail[MAX_RESOURCES], int need[MAX_PROCESSES][MAX_RESOURCES]) {
    for (int j = 0; j < MAX_RESOURCES; j++) {
        if (need[process][j] > avail[j]) {
            return 0;  // Unsafe
        }
    }
    return 1;  // Safe
}

int main() {
    int n = MAX_PROCESSES;
    int m = MAX_RESOURCES;

    int alloc[MAX_PROCESSES][MAX_RESOURCES] = {
        {0, 1, 0},
        {2, 0, 0}, // 3,0,2
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[MAX_PROCESSES][MAX_RESOURCES] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int avail[MAX_RESOURCES] = {3, 3, 2};//2, 3, 0

    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeed(need, max, alloc);

    int f[MAX_PROCESSES] = {0};  // Flag to mark finished processes
    int ans[MAX_PROCESSES];      // Array to store the safe sequence
    int ind = 0;

    for (int k = 0; k < n; k++) {
	    for (int i = 0; i < n; i++) {
            if (!f[i] && isProcessSafe(i, avail, need)) {
                f[i] = 1;  // Mark process as finished
                ans[ind++] = i;  // Add to safe sequence

                // Update available resources
                for (int j = 0; j < m; j++) {
                    avail[j] += alloc[i][j];
                }
            }
        }
    }

    int safe = 1;
    for (int i = 0; i < n; i++) {
        if (!f[i]) {
            safe = 0;
            break;
        }
    }
    if (safe) {
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d\n", ans[n - 1]);
    } else {
        printf("The system is not safe.\n");
   }
    return 0;
}
