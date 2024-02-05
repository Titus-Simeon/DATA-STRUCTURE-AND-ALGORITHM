#include <stdio.h>

// Function to calculate the sum of integers in an array
int summation(int nums[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    return sum;
}

// Function to find the maximum integer in an array
int maximum(int nums[], int n) {
    if (n <= 0) {
        // Handle the case of an empty array
        return 0;
    }

    int max = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    return max;
}

int main() {
    int n;

    // Get the length of the array from the user
    printf("Enter the length of the array (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array length. Exiting.\n");
        return 1;
    }

    int nums[n];

    // Allow the user to enter n integers and store them in the array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter integer #%d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    // Call the summation function and display the result
    int sum = summation(nums, n);
    printf("Sum of the integers: %d\n", sum);

    // Call the maximum function and display the result
    int max = maximum(nums, n);
    printf("Maximum integer: %d\n", max);

    return 0;
}
