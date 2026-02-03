#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {
    // basic safety check
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // check every pair
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                *out_i = i;
                *out_j = j;
                return 1;   // found a solution
            }
        }
    }

    return 0; // no solution
}
