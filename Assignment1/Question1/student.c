#include "Student.h"

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    (void)nums1Size;  // not needed for the algorithm, but kept to avoid warnings
    (void)nums2Size;  // not needed for the algorithm, but kept to avoid warnings

    int i = m - 1;          // last real element in nums1
    int j = n - 1;          // last element in nums2
    int k = m + n - 1;      // last index in nums1

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
}