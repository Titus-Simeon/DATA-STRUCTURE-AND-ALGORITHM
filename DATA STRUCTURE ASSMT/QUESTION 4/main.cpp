#include <stdio.h>

int singleNumber(int nums[], int n) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        // XOR each element in the array
        result ^= nums[i];
    }

    return result;
}

int main() {
    int nums[] = {4, 2, 3, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    // Find the single element in the array
    int result = singleNumber(nums, n);

    printf("The single element is: %d\n", result);

    return 0;
}
