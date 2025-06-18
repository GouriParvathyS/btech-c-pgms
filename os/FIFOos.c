/*#include <stdio.h>
#include <stdlib.h>
 
#define MAX_FRAMES 3
#define MAX_PAGES 20
 
int frames[MAX_FRAMES];
int rear = -1;
 
void initialize() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
}
 
void displayFrames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}
 
void FIFO(int pages[], int n) {
    int page_faults = 0;
    int front = 0;
 
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
 
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }
 
        if (!found) {
            page_faults++;
           
            if (rear < MAX_FRAMES - 1) {
                rear++;
            } else {
                rear = 0;
            }
            frames[rear] = page;
        }
 
        displayFrames();
    }
 
    printf("Total Page Faults: %d\n", page_faults);
}
 
int main() {
    int pages[MAX_PAGES];
    int n;
 
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
 
    initialize();
    FIFO(pages, n);
}
Enter number of pages: 8
Enter the page reference sequence: 1 3 0 3 5 6 3 0
1 - - 
1 3 - 
1 3 0 
1 3 0 
5 3 0 
5 6 0 
5 6 3 
Total Page Faults: 5
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int frames[MAX_FRAMES];

void initialize() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
}

void displayFrames() {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}

void FIFO(int pages[], int n) {
    int page_faults = 0;
    int front = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        // If the page is not found in frames, it is a page fault
        if (!found) {
            page_faults++;

            // Use the front pointer for the FIFO replacement
            frames[front] = page;
            front = (front + 1) % MAX_FRAMES;  // Move the front pointer circularly
        }

        displayFrames();
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES];
    int n;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    initialize();
    FIFO(pages, n);

    return 0;
}
