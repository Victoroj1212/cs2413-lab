#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    int* heap = (int*)malloc(sizeof(int) * (size_t)k);
    int heapSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (heapSize < k) {
            heap[heapSize] = nums[i];
            heapifyUp(heap, heapSize);
            heapSize++;
        } else if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapifyDown(heap, heapSize, 0);
        }
    }

    int result = heap[0];
    free(heap);
    return result;
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
static void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index]) {
            break;
        }

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest == index) {
            break;
        }

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}