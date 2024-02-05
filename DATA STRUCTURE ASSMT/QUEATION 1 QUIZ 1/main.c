#include <stdio.h>

int removeDuplicates(int nums[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    int index = 0; // index to store the position of unique elements

    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[index]) {
            index++;
            nums[index] = nums[i];
        }
    }

    return index + 1; // length of the array without duplicates
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Remove duplicates in-place
    int newLength = removeDuplicates(nums, n);

    printf("Array without duplicates: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
