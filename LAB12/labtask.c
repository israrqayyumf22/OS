#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

void allocateMemory(int numFiles, int lengths[]);

int main() {
    srand(time(NULL)); // Seed for random number generation

    int numFiles;
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    if (numFiles <= 0 || numFiles > MAX_FILES) {
        printf("Invalid number of files. Exiting program.\n");
        return 1;
   }

    int lengths[MAX_FILES];

    printf("Enter the memory requirement of each file:\n");
    for (int i = 0; i < numFiles; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &lengths[i]);
    }

    allocateMemory(numFiles, lengths);

    printf("\nResults:\n");
    printf("File No\tLength\tBlocks Allocated\n");
    for (int i = 0; i < numFiles; i++) {
        printf("%d\t%d\t", i + 1, lengths[i]);
        for (int j = 0; j < lengths[i]; j++) {
            printf("%d ", rand() % MAX_BLOCKS + 1);
        }
        printf("\n");
    }

    return 0;
}

void allocateMemory(int numFiles, int lengths[]) {
    printf("\nAllocating memory...\n");
    for (int i = 0; i < numFiles; i++) {
        printf("For File %d:\n", i + 1);
       for (int j = 0; j < lengths[i]; j++) {
            printf("%d ", rand() % MAX_BLOCKS + 1);
        }
        printf("\n");
    }
}
