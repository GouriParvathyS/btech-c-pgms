#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int absoluteValue(int x) {
    return x > 0 ? x : -x;
}

void sortArray(int *arr, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int queue[MAX_REQUESTS], numRequests, headPosition, maxRange;
    int seek = 0, temp;
    int queue1[MAX_REQUESTS], queue2[MAX_REQUESTS], temp1 = 0, temp2 = 0;
    float averageSeekTime;

    printf("Enter the maximum range of Disk: ");
    scanf("%d", &maxRange);
    printf("Enter the number of queue requests: ");
    scanf("%d", &numRequests);
    printf("Enter the initial head position: ");
    scanf("%d", &headPosition);

    printf("Enter the disk positions to be read (queue): ");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &temp);
        if (temp >= headPosition) {
            queue1[temp1] = temp;
            temp1++;
        } else {
            queue2[temp2] = temp;
            temp2++;
        }
    }

    sortArray(queue1, temp1);
    sortArray(queue2, temp2);

    int currentTrack = headPosition;

    // Moving towards the end
    for (int i = 0; i < temp1; i++) {
        seek += absoluteValue(currentTrack - queue1[i]);
        printf("Disk head moves from position %d to %d with Seek %d\n", currentTrack, queue1[i], absoluteValue(currentTrack - queue1[i]));
        currentTrack = queue1[i];
    }

    // Move to the end of the disk
    if (currentTrack != maxRange - 1) {
        seek += absoluteValue(currentTrack - (maxRange - 1));
        printf("Disk head moves from position %d to %d with Seek %d\n", currentTrack, maxRange - 1, absoluteValue(currentTrack - (maxRange - 1)));
        currentTrack = maxRange - 1;
    }

    // Moving towards the beginning
    for (int i = temp2 - 1; i >= 0; i--) {
        seek += absoluteValue(currentTrack - queue2[i]);
        printf("Disk head moves from position %d to %d with Seek %d\n", currentTrack, queue2[i], absoluteValue(currentTrack - queue2[i]));
        currentTrack = queue2[i];
    }

    averageSeekTime = (float)seek / numRequests;
    printf("Total Seek Time: %d\n", seek);
    printf("Average Seek Time: %.2f\n", averageSeekTime);

    return 0;
}