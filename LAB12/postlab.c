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

    return 0;
}

void allocateMemory(int numFiles, int lengths[]) {
    int allocated[MAX_BLOCKS] = {0}; // Initialize all blocks as free

    printf("\nAllocating memory...\n");
    for (int i = 0; i < numFiles; i++) {
        printf("For File %d:\n", i + 1);
        printf("Allocated Blocks: ");

        for (int j = 0; j < lengths[i]; j++) {
            int block;
            do {
                block = rand() % MAX_BLOCKS;
           } while (allocated[block] == 1);

            printf("%d ", block);
            allocated[block] = 1; // Set flag to indicate allocation
        }
        printf("\n");
    }
}
