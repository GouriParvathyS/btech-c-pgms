#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 10000  // Assuming the maximum value in the arrays is less than 10000

int* missingNumbers(int arr_count, int* arr, int brr_count, int* brr, int* result_count) {
    int freq_brr[MAX_VAL] = {0};
    int freq_arr[MAX_VAL] = {0};
    int *result = (int*)malloc(brr_count * sizeof(int)); // Maximum possible size of the result
    int l = 0;

    // Counting the frequency of each element in brr
    for (int i = 0; i < brr_count; i++) {
        freq_brr[brr[i]]++;
    }

    // Counting the frequency of each element in arr
    for (int i = 0; i < arr_count; i++) {
        freq_arr[arr[i]]++;
    }

    // Finding elements that are missing or have a lower frequency in arr
    for (int i = 0; i < MAX_VAL; i++) {
        if (freq_brr[i] > freq_arr[i]) {
            result[l++] = i;
        }
    }

    // Sorting the missing numbers
    for (int i = 0; i < l - 1; i++) {
        for (int j = 0; j < l - 1 - i; j++) {
            if (result[j] > result[j + 1]) {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    *result_count = l;
    return result;
}

int main() {
    int arr[] = {11, 4, 11, 7, 13, 4, 12, 11, 10, 14};
    int brr[] = {11, 4, 11, 7, 3, 7, 10, 13, 4, 8, 12, 11, 10, 14, 12};
    int arr_count = sizeof(arr) / sizeof(arr[0]);
    int brr_count = sizeof(brr) / sizeof(brr[0]);
    int result_count;

    int *missing = missingNumbers(arr_count, arr, brr_count, brr, &result_count);

    printf("Missing numbers:\n");
    for (int i = 0; i < result_count; i++) {
        printf("%d ", missing[i]);
    }
    printf("\n");

    free(missing);
    return 0;
}
