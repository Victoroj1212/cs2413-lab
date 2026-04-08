#include <stdlib.h>

/*
Optional helper structure for a hash table entry.

You may use this structure if you want to build your own hash table.
key   -> the number from the array
value -> the index of that number
*/
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

/*
Optional table size for a simple hash table implementation.
You may change this value if needed.
*/
#define TABLE_SIZE 1009

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static int hash(int key);
static void insert(Node* table[], int key, int value);
static int find(Node* table[], int key, int* value);
static void freeTable(Node* table[]);

/*
Return an array of size 2 containing the indices of the two numbers
whose sum equals target.
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Node* table[TABLE_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        int needed = target - nums[i];
        int foundIndex;

        if (find(table, needed, &foundIndex)) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(table);
            return result;
        }

        insert(table, nums[i], i);
    }

    freeTable(table);
    *returnSize = 0;
    return NULL;
}

/*
Optional helper: compute a hash index for a key.
*/
static int hash(int key) {
    int h = key % TABLE_SIZE;
    if (h < 0) {
        h += TABLE_SIZE;
    }
    return h;
}

/*
Optional helper: insert (key, value) into the hash table.
*/
static void insert(Node* table[], int key, int value) {
    int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

/*
Optional helper: search for key in the hash table.
If found, store the associated value in *value and return 1.
Otherwise return 0.
*/
static int find(Node* table[], int key, int* value) {
    int index = hash(key);
    Node* curr = table[index];

    while (curr != NULL) {
        if (curr->key == key) {
            *value = curr->value;
            return 1;
        }
        curr = curr->next;
    }

    return 0;
}

/*
Optional helper: free all memory used by the hash table.
*/
static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        table[i] = NULL;
    }
}