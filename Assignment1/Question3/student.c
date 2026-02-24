#include "Student.h"
#include <stdlib.h>

// digits: array of length digitsSize
// returns new array, sets *returnSize
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // work from the end like normal addition
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i] += 1;

            int* out = (int*)malloc(sizeof(int) * (size_t)digitsSize);
            for (int k = 0; k < digitsSize; k++) out[k] = digits[k];

            *returnSize = digitsSize;
            return out;
        }
        digits[i] = 0;
    }

    // if we got here, it was all 9s -> need one extra digit
    int* out = (int*)malloc(sizeof(int) * (size_t)(digitsSize + 1));
    out[0] = 1;
    for (int i = 1; i <= digitsSize; i++) out[i] = 0;

    *returnSize = digitsSize + 1;
    return out;
}