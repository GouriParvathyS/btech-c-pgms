#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int calculateTotalSeekTime(int *requests, int numRequests, int initialPosition) {
    int totalSeekTime = 0;
    int currentTrack = initialPosition;
    int direction = 1; // 1 for upward, -1 for downward

    // Sort the requests array
    qsort(requests, numRequests, sizeof(int), compare);

    // Find the first request greater than or equal to initialPosition
    int startIndex = 0;
    while (startIndex < numRequests && requests[startIndex] < initialPosition) {
        startIndex++;
    }

    // First go to the end in the current direction (upward)
    for (int i = startIndex; i < numRequests; i++) {
        totalSeekTime += abs(currentTrack - requests[i]);
        currentTrack = requests[i];
    }

    // Change direction to downward
    totalSeekTime += abs(currentTrack - 199); // Go to the end of the disk
    currentTrack = 199;
    direction = -1;

    // Now go to the start in the opposite direction (downward)
    for (int i = startIndex - 1; i >= 0; i--) {
        totalSeekTime += abs(currentTrack - requests[i]);
        currentTrack = requests[i];
    }

    return totalSeekTime;
}

int main() {
    int requests[MAX_REQUESTS];
    int numRequests;
    int initialPosition;

    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);
    if (numRequests <= 0 || numRequests > MAX_REQUESTS) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &initialPosition);

    printf("Enter the disk requests (track numbers):\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    int totalSeekTime = calculateTotalSeekTime(requests, numRequests, initialPosition);
    printf("Total seek time using SCAN: %d\n", totalSeekTime);

    return 0;
}