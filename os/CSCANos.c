/*#include <stdio.h>
int absoluteValue(int x)
{
    if (x > 0)
    {
        return x;
    }
    else
    {
        return x * -1;
    }
}

void main()
{
    int queue[25], n, headposition, i, j, k, seek = 0, maxrange, difference, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;
    printf("Enter the maximum range of Disk : ");
    scanf("%d", &maxrange);
    printf("Enter the number of queue requests : ");
    scanf("% d", &n);
    printf("Enter the initial head position: \n");
    scanf("%d", &headposition);
    printf("Enter the disk positions to be read(queue): ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        if (temp > headposition)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    for (i = 1, j = 0; j < temp1; i++, j++)
    {
        queue[i] = queue1[j];
    }
    queue[i] = maxrange;
    queue[i + 1] = 0;
    for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
    {
        queue[i] = queue2[j];
    }
    queue[0] = headposition;
    for (j = 0; j <= n + 1; j++)
    {
        difference = absoluteValue(queue[j + 1] - queue[j]);
        seek = seek + difference;
        printf("Disk head moves from position %d to %d with Seek %d \n", queue[j], queue[j + 1], difference);
    }
    averageSeekTime = seek / (float)n;
    printf("Total Seek Time= %d\n", seek);
    printf("Average Seek Time= %f\n", averageSeekTime);
}
*/
/*#include <stdio.h>
#include <stdlib.h>

int absoluteValue(int x) {
    return x > 0 ? x : -x;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int queue[25], n, headposition, i, j, seek = 0, maxrange, difference, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;

    printf("Enter the maximum range of Disk : ");
    scanf("%d", &maxrange);
    printf("Enter the number of queue requests : ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &headposition);
    printf("Enter the disk positions to be read(queue): ");
    
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp >= headposition) {
            queue1[temp1++] = temp;
        } else {
            queue2[temp2++] = temp;
        }
    }

    sortArray(queue1, temp1);
    sortArray(queue2, temp2);

    int idx = 0;
    queue[idx++] = headposition;
    
    for (i = 0; i < temp1; i++) {
        queue[idx++] = queue1[i];
    }
    
    queue[idx++] = maxrange; // Assuming the disk head moves to the end of the disk
    queue[idx++] = 0;        // Assuming the disk head reverses and moves to the start of the disk
    
    for (i = 0; i < temp2; i++) {
        queue[idx++] = queue2[i];
    }

    for (j = 0; j < idx - 1; j++) {
        difference = absoluteValue(queue[j + 1] - queue[j]);
        seek += difference;
        printf("Disk head moves from position %d to %d with Seek %d\n", queue[j], queue[j + 1], difference);
    }

    averageSeekTime = (float)seek / n;
    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", averageSeekTime);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

int absoluteValue(int x) {
    return x > 0 ? x : -x;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int queue[25], n, headposition, i, seek = 0, maxrange, difference, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    float averageSeekTime;
    char direction;

    printf("Enter the maximum range of Disk: ");
    scanf("%d", &maxrange);
    printf("Enter the number of queue requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &headposition);
    printf("Enter the direction (l for left, r for right): ");
    scanf(" %c", &direction);  // Note the space before %c to capture newline from previous input

    printf("Enter the disk positions to be read (queue): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp >= headposition) {
            queue1[temp1++] = temp;  // Requests greater than or equal to head position
        } else {
            queue2[temp2++] = temp;  // Requests less than head position
        }
    }

    // Sort both queues
    sortArray(queue1, temp1);
    sortArray(queue2, temp2);

    int idx = 0;
    queue[idx++] = headposition;

    if (direction == 'r') {
        // Moving towards right (end of disk)
        for (i = 0; i < temp1; i++) {
            queue[idx++] = queue1[i];
        }
        queue[idx++] = maxrange; // Move to the end of disk
        queue[idx++] = 0;        // Move back to the start of disk
        for (i = 0; i < temp2; i++) {
            queue[idx++] = queue2[i];
        }
    } else if (direction == 'l') {
        // Moving towards left (start of disk)
        for (i = temp2 - 1; i >= 0; i--) {
            queue[idx++] = queue2[i];
        }
        queue[idx++] = 0;        // Move to the start of disk
        queue[idx++] = maxrange; // Move to the end of disk
        for (i = temp1 - 1; i >= 0; i--) {
            queue[idx++] = queue1[i];
        }
    } else {
        printf("Invalid direction. Please enter 'l' or 'r'.\n");
        return 1;
    }

    // Calculate total seek time
    for (i = 0; i < idx - 1; i++) {
        difference = abs(queue[i + 1] - queue[i]);
        seek += difference;
        printf("Disk head moves from position %d to %d with Seek %d\n", queue[i], queue[i + 1], difference);
    }

    averageSeekTime = (float)seek / n;
    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", averageSeekTime);

    return 0;
}
