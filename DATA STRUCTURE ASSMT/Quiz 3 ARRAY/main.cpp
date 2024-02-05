#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int nums[], int n) {
    // Create a hash set to store unique elements
    int hashSet[100000] = {0}; // Assuming the range of integers is within [-50000, 50000]

    for (int i = 0; i < n; i++) {
        // Check if the current element is already in the hash set
        if (hashSet[nums[i] + 50000] == 1) {
            return true; // Duplicate found
        } else {
            // Mark the current element as seen
            hashSet[nums[i] + 50000] = 1;
        }
    }

    return false; // No duplicates found
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    // Check if the array contains any duplicates
    bool result = containsDuplicate(nums, n);

    if (result) {
        printf("The array contains duplicates.\n");
    } else {
        printf("The array does not contain duplicates.\n");
    }

    return 0;
}
